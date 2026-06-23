-- Write your PostgreSQL query statement below
WITH SessionMetrics AS (
    SELECT  session_id,
            MAX(user_id) AS user_id,
            EXTRACT(EPOCH FROM (MAX(event_timestamp) - MIN(event_timestamp))) / 60 AS duration_minutes,
            COUNT(*) FILTER (WHERE event_type = 'scroll') AS scroll_count,
            COUNT(*) FILTER (WHERE event_type = 'click') AS click_count,
            COUNT(*) FILTER (WHERE event_type = 'purchase') AS purchase_count
    FROM    app_events
    GROUP BY    session_id
)
SELECT  session_id,
        user_id,
        duration_minutes AS session_duration_minutes,
        scroll_count
FROM    SessionMetrics
WHERE   duration_minutes > 30
    AND purchase_count = 0
    AND scroll_count >= 5
    AND click_count < scroll_count * 0.2
ORDER BY 
    scroll_count DESC, 
    session_id;
