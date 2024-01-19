SELECT  activity_date AS day,
        count(DISTINCT user_id) AS active_users
FROM    Activity
WHERE   activity_date > '2019-07-27'::Date - 30 AND activity_date <= '2019-07-27'::Date
GROUP BY   activity_date 
