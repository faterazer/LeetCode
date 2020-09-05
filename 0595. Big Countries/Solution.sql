# Approach 1.
SELECT name, population, area
FROM World
WHERE population > 25000000 OR area > 3000000

# Approach 2.
SELECT name, population, area
FROM World
WHERE population > 25000000

UNION

SELECT name, population, area
FROM World
WHERE area > 3000000
