-- Write your PostgreSQL query statement below
(
    SELECT Users.name AS results
    FROM MovieRating
    JOIN Users ON MovieRating.user_id = Users.user_id
    GROUP BY Users.name
    ORDER BY COUNT(MovieRating.movie_id) DESC, Users.name
    LIMIT 1
)
UNION ALL
(
    SELECT Movies.title AS results
    FROM MovieRating
    JOIN Movies ON MovieRating.movie_id = Movies.movie_id
    WHERE TO_CHAR(MovieRating.created_at, 'YYYY-MM') = '2020-02'
    GROUP BY Movies.title
    ORDER BY AVG(MovieRating.rating) DESC, Movies.title
    LIMIT 1
)
