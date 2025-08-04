import pandas as pd


def find_books_with_no_available_copies(library_books: pd.DataFrame, borrowing_records: pd.DataFrame) -> pd.DataFrame:
    borrowing_counts = borrowing_records[borrowing_records["return_date"].isnull()].groupby("book_id").size().rename("current_borrowers")
    merged = library_books.merge(borrowing_counts, on="book_id")
    no_available_copies = merged[merged["total_copies"] == merged["current_borrowers"]]
    return no_available_copies[["book_id", "title", "author", "genre", "publication_year", "current_borrowers"]].sort_values(
        by=["current_borrowers", "title"], ascending=[False, True]
    )
