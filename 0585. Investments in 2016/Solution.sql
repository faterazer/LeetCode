-- Write your PostgreSQL query statement below
WITH tiv_counts AS (
    SELECT tiv_2015, COUNT(*) AS count_tiv
    FROM Insurance
    GROUP BY tiv_2015
),
location_counts AS (
    SELECT lat, lon, COUNT(*) AS count_loc
    FROM Insurance
    GROUP BY lat, lon
)
SELECT ROUND(SUM(tiv_2016)::numeric, 2) AS tiv_2016
FROM Insurance i
JOIN tiv_counts tc ON i.tiv_2015 = tc.tiv_2015
JOIN location_counts lc ON i.lat = lc.lat AND i.lon = lc.lon
WHERE tc.count_tiv >= 2 AND lc.count_loc = 1;
