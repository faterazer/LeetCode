-- Write your MySQL query statement below
SELECT  Students.student_id,
        Students.student_name,
        Subjects.subject_name,
        IFNULL(grouped.attended_exams, 0) AS attended_exams
FROM    Students 
CROSS JOIN  Subjects
LEFT JOIN   (
    SELECT  student_id,
            subject_name ,
            COUNT(*) AS attended_exams
    FROM    Examinations
    GROUP BY    student_id, subject_name
) AS grouped
ON  Students.student_id = grouped.student_id AND Subjects.subject_name = grouped.subject_name
ORDER BY Students.student_id, Subjects.subject_name
