-- Write your PostgreSQL query statement below
SELECT  ip,
        COUNT(ip) AS invalid_count
FROM    (
    SELECT  ip
    FROM    logs
    WHERE   ip !~ '^((25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]|[0-9])\.){3}(25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9][0-9]|[0-9])$'
)
GROUP BY    ip
ORDER BY    invalid_count DESC, ip DESC
