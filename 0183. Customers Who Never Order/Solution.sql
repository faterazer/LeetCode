-- Approach 1.
SELECT Name AS Customers
FROM Customers LEFT JOIN Orders
ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL

-- Approach 2.
SELECT Name AS Customers
FROM Customers
WHERE Customers.Id NOT IN
(
    SELECT CustomerId FROM Orders
);
