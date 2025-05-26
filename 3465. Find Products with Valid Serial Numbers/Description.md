# 3465. Find Products with Valid Serial Numbers

SQL Schema:

```sql
CREATE TABLE If not exists products (
    product_id INT,
    product_name VARCHAR(255),
    description VARCHAR(255)
)

Truncate table products
insert into products (product_id, product_name, description) values ('1', 'Widget A', 'This is a sample product with SN1234-5678')
insert into products (product_id, product_name, description) values ('2', 'Widget B', 'A product with serial SN9876-1234 in the description')
insert into products (product_id, product_name, description) values ('3', 'Widget C', 'Product SN1234-56789 is available now')
insert into products (product_id, product_name, description) values ('4', 'Widget D', 'No serial number here')
insert into products (product_id, product_name, description) values ('5', 'Widget E', 'Check out SN4321-8765 in this description')
```

Pandas Schema:

```python
data = [[1, 'Widget A', 'This is a sample product with SN1234-5678'], [2, 'Widget B', 'A product with serial SN9876-1234 in the description'], [3, 'Widget C', 'Product SN1234-56789 is available now'], [4, 'Widget D', 'No serial number here'], [5, 'Widget E', 'Check out SN4321-8765 in this description']]
products = pd.DataFrame(columns=['product_id', 'product_name', 'description']).astype({'product_id': 'int32', 'product_name': 'string', 'description': 'string'})
```

---

Table: `products`

```()
+--------------+------------+
| Column Name  | Type       |
+--------------+------------+
| product_id   | int        |
| product_name | varchar    |
| description  | varchar    |
+--------------+------------+
(product_id) is the unique key for this table.
Each row in the table represents a product with its unique ID, name, and description.
```

Write a solution to find all products whose description **contains a valid serial number** pattern. A valid serial number follows these rules:

- It starts with the letters **SN** (case-sensitive).
- Followed by exactly `4` digits.
- It must have a hyphen (-) **followed by exactly** `4` digits.
- The serial number must be within the description (it may not necessarily start at the beginning).

Return *the result table ordered by* `product_id` *in **ascending** order*.

The result format is in the following example.

**Example :**

```()
Input:

products table:

+------------+--------------+------------------------------------------------------+
| product_id | product_name | description                                          |
+------------+--------------+------------------------------------------------------+
| 1          | Widget A     | This is a sample product with SN1234-5678            |
| 2          | Widget B     | A product with serial SN9876-1234 in the description |
| 3          | Widget C     | Product SN1234-56789 is available now                |
| 4          | Widget D     | No serial number here                                |
| 5          | Widget E     | Check out SN4321-8765 in this description            |
+------------+--------------+------------------------------------------------------+
    

Output:

+------------+--------------+------------------------------------------------------+
| product_id | product_name | description                                          |
+------------+--------------+------------------------------------------------------+
| 1          | Widget A     | This is a sample product with SN1234-5678            |
| 2          | Widget B     | A product with serial SN9876-1234 in the description |
| 5          | Widget E     | Check out SN4321-8765 in this description            |
+------------+--------------+------------------------------------------------------+
    

Explanation:

- Product 1: Valid serial number SN1234-5678
- Product 2: Valid serial number SN9876-1234
- Product 3: Invalid serial number SN1234-56789 (contains 5 digits after the hyphen)
- Product 4: No serial number in the description
- Product 5: Valid serial number SN4321-8765

The result table is ordered by product_id in ascending order.
```
