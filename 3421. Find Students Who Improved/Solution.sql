-- Write your PostgreSQL query statement below
SELECT  DISTINCT
        student_id,
        subject,
        first_score,
        latest_score
FROM    (
    SELECT  student_id,
            subject,
            FIRST_VALUE(score) OVER (PARTiTION BY student_id, subject ORDER BY exam_date) AS first_score,
            FIRST_VALUE(score) OVER (PARTiTION BY student_id, subject ORDER BY exam_date DESC) AS latest_score
    FROM    Scores
)
WHERE first_score < latest_score
ORDER BY student_id, subject
