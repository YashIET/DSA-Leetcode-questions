# Write your MySQL query statement below
# select salary as SecondHighestSalary
# from Employee 
# order by salary desc
# limit 1 offset 1

# above does not deal with null

SELECT max(Salary) as SecondHighestSalary
FROM Employee
WHERE Salary < (SELECT max(Salary) FROM Employee)
# good for 2nd highest

# select max(salary) as SecondHighestSalary from Employee
# where salary not in (
# select salary from (
# select DISTINCT salary from Employee
# order by salary desc )
# where rownum<=1);