# Write your MySQL query statement below
SELECT
    patient_id,
    patient_name,
    conditions
FROM
    Patients
WHERE
    conditions RLIKE " DIAB1" OR conditions REGEXP "^DIAB1"
