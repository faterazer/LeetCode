-- Write your PostgreSQL query statement below
SELECT 
    t.request_at AS Day,
    CAST(AVG(CASE WHEN status = 'completed' THEN 0.0 ELSE 1.0 END) AS DECIMAL(10, 2)) AS "Cancellation Rate"
FROM 
    Trips t
LEFT JOIN 
    Users u1 ON t.client_id = u1.users_id AND u1.banned = 'Yes'
LEFT JOIN 
    Users u2 ON t.driver_id = u2.users_id AND u2.banned = 'Yes'
WHERE 
    u1.users_id IS NULL 
    AND u2.users_id IS NULL 
    AND t.request_at::DATE BETWEEN '2013-10-01'::DATE AND '2013-10-03'
GROUP BY 
    t.request_at
