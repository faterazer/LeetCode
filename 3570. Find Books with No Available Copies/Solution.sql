-- Write your PostgreSQL query statement below
SELECT  library_books.book_id,
        title,
        author,
        genre,
        publication_year,
        current_borrowers
FROM    library_books
JOIN    (
    SELECT  book_id,
            COUNT(*) AS current_borrowers
    FROM    borrowing_records
    WHERE   return_date IS NULL
    GROUP BY    book_id
) AS borrowing_counts
ON  library_books.book_id = borrowing_counts.book_id
WHERE   total_copies = current_borrowers
ORDER BY    current_borrowers DESC, title;