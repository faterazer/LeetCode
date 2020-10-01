# Approach 1
UPDATE salary SET sex = IF(sex='m', 'f', 'm')

# Approach 2
UPDATE salary SET sex = CHAR(ASCII('f') ^ ASCII('m') ^ ASCII(sex))

# Approach 3
UPDATE salary
SET
    sex = CASE sex
        WHEN 'm' THEN 'f'
        ELSE 'm'
    END;
