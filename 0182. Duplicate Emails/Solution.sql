# Approach 1.
SELECT DISTINCT a.Email
FROM Person AS a JOIN Person AS b
ON a.Id != b.Id AND a.Email = b.Email;

# Approach 2.
SELECT Email FROM Person GROUP BY Email HAVING count(Email) > 1;
