-- Write your PostgreSQL query statement below
SELECT  c1.patient_id, 
        p.patient_name, 
        p.age, 
        MIN(c2.test_date) - MIN(c1.test_date) AS recovery_time
FROM    covid_tests AS c1
JOIN    covid_tests AS c2
ON  c1.patient_id = c2.patient_id AND c1.result = 'Positive' AND c2.result = 'Negative' AND c1.test_date < c2.test_date
JOIN    patients AS p
ON  c1.patient_id = p.patient_id
GROUP BY c1.patient_id, p.patient_name, p.age
ORDER BY recovery_time, p.patient_name;