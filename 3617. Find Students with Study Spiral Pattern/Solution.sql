-- Write your PostgreSQL query statement below
WITH data_with_index AS (
    SELECT  student_id,
            subject,
            session_date,
            hours_studied,
            ROW_NUMBER() OVER(PARTITION BY student_id ORDER BY session_date) AS rn,
            LEAD(session_date) OVER(PARTITION BY student_id ORDER BY session_date) AS next_session_date
    FROM    study_sessions
),
student_stats AS (
    SELECT  student_id,
            COUNT(DISTINCT subject) AS cycle_length,
            COUNT(*) AS total_sessions,
            SUM(hours_studied) AS total_study_hours
    FROM    study_sessions
    GROUP BY    student_id
),
validated_students AS (
    SELECT  s.student_id,
            s.cycle_length,
            s.total_study_hours
    FROM    student_stats AS s
    JOIN    data_with_index AS d1
    ON  s.student_id = d1.student_id
    LEFT JOIN   data_with_index AS d2
    ON  d1.student_id = d2.student_id AND d2.rn = d1.rn + s.cycle_length
    WHERE   s.cycle_length >= 3 AND s.total_sessions >= 2 * s.cycle_length
    GROUP BY    s.student_id, s.cycle_length, s.total_study_hours
    HAVING  MAX(COALESCE(d1.next_session_date - d1.session_date, 0)) <= 2
            AND SUM(CASE WHEN d2.student_id IS NOT NULL AND d1.subject != d2.subject THEN 1 ELSE 0 END) = 0
)
SELECT  v.student_id,
        stu.student_name,
        stu.major,
        v.cycle_length,
        v.total_study_hours
FROM    validated_students AS v
JOIN    students AS stu
ON  v.student_id = stu.student_id
ORDER BY v.cycle_length DESC, total_study_hours DESC
