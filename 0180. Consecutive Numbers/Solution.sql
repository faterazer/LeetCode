-- Write your PostgreSQL query statement below
SELECT  DISTINCT t1.num AS ConsecutiveNums
FROM    Logs AS t1, Logs AS t2, Logs AS t3
WHERE t1.id = t2.id - 1
    AND t1.id = t3.id - 2
    AND t1.num = t2.num 
    AND t1.num = t3.num
