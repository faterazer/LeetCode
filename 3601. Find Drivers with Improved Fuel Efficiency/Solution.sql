-- Write your PostgreSQL query statement below
SELECT  *
FROM    (
    SELECT  t1.driver_id,
            d.driver_name,
            ROUND(AVG(t1.distance_km / t1.fuel_consumed), 2) AS first_half_avg,
            ROUND(AVG(t2.distance_km / t2.fuel_consumed), 2) AS second_half_avg,
            ROUND(AVG(t2.distance_km / t2.fuel_consumed) - AVG(t1.distance_km / t1.fuel_consumed), 2) AS efficiency_improvement
    FROM    trips AS t1
    JOIN    trips AS t2
    ON      t1.driver_id = t2.driver_id AND EXTRACT(MONTH FROM t1.trip_date) BETWEEN 1 AND 6 AND EXTRACT(MONTH FROM t2.trip_date) BETWEEN 7 AND 12
    JOIN    drivers AS d
    ON      t1.driver_id = d.driver_id
    GROUP BY    t1.driver_id, d.driver_name
    ORDER BY    efficiency_improvement DESC, d.driver_name
)
WHERE   efficiency_improvement > 0;