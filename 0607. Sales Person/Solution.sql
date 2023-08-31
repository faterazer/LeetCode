-- Write your MySQL query statement below
SELECT  name
FROM    SalesPerson
WHERE   SalesPerson.sales_id NOT IN (
  SELECT  sales_id
  FROM    Orders
  JOIN    Company
  ON      Orders.com_id = Company.com_id
  WHERE   name = "RED"
)
