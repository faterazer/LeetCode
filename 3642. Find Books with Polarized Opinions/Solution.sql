-- Write your PostgreSQL query statement below
WITH book_stats AS (
    SELECT  book_id,
            MAX(session_rating) - MIN(session_rating) AS rating_spread,
            ROUND(COUNT(*) FILTER (WHERE session_rating >= 4 OR session_rating <= 2)::NUMERIC / COUNT(*), 2) AS polarization_score
    FROM    reading_sessions
    GROUP BY    book_id
    HAVING  MAX(session_rating) >= 4
        AND MIN(session_rating) <= 2
        AND COUNT(*) >= 5
)
SELECT  book_stats.book_id,
        title,
        author,
        genre,
        pages,
        rating_spread,
        polarization_score
FROM    book_stats
JOIN   books ON book_stats.book_id = books.book_id
WHERE   polarization_score >= 0.6
ORDER BY    polarization_score DESC, title DESC;
