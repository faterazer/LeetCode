# Method 1
SELECT a.Name AS Employee
FROM Employee AS a, Employee AS b
WHERE a.ManagerId = b.Id AND a.Salary > b.Salary;

# Method 2
SELECT a.Name AS Employee
FROM Employee AS a JOIN Employee AS b
ON a.ManagerId = b.Id and a.Salary > b.Salary
