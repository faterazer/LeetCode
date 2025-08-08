-- Write your PostgreSQL query statement below
WITH ranked_reviews AS (
    SELECT  employee_id,
            review_date,
            rating,
            ROW_NUMBER() OVER (PARTITION BY employee_id ORDER BY review_date DESC) AS rn
    FROM    performance_reviews AS pr
),
last_three_reviews AS (
    SELECT  employee_id,
            MAX(rating) FILTER (WHERE rn = 1) AS latest_rating,
            MAX(rating) FILTER (WHERE rn = 2) AS second_latest_rating,
            MAX(rating) FILTER (WHERE rn = 3) AS third_latest_rating
    FROM    ranked_reviews
    GROUP BY    employee_id
    HAVING  COUNT(*) >= 3
)
SELECT  last_three_reviews.employee_id,
        name,
        latest_rating - third_latest_rating AS improvement_score
FROM    last_three_reviews
LEFT JOIN   employees
ON  last_three_reviews.employee_id = employees.employee_id
WHERE   latest_rating > second_latest_rating AND second_latest_rating > third_latest_rating
ORDER BY    improvement_score DESC, name;
