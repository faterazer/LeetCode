-- Write your PostgreSQL query statement below
WITH swapped_seat AS (
  SELECT
    id,
    student,
    CASE
      WHEN MOD(id, 2) = 0 THEN id - 1  -- 如果 id 是偶数，返回 id-1
      ELSE id + 1                      -- 如果 id 是奇数，返回 id+1
    END AS swap_id
  FROM seat
)
SELECT
  ROW_NUMBER() OVER (ORDER BY swap_id) AS id,  -- 按 swap_id 排序生成连续 id
  student
FROM swapped_seat
ORDER BY id;
