-- Write your PostgreSQL query statement below
WITH start_t AS (
    SELECT  machine_id,
            process_id,
            timestamp AS start_timestamp
    FROM    Activity
    WHERE   activity_type = 'start'
),
end_t AS (
    SELECT  machine_id AS machine_id,
            process_id,
            timestamp AS end_timestamp
    FROM    Activity
    WHERE   activity_type = 'end'
)
SELECT  start_t.machine_id,
        ROUND(AVG(end_timestamp - start_timestamp)::numeric, 3) AS processing_time
FROM    start_t
JOIN    end_t
ON  start_t.machine_id = end_t.machine_id and start_t.process_id = end_t.process_id
GROUP BY    start_t.machine_id
