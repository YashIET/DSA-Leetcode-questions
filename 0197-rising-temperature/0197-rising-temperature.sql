# Write your MySQL query statement below
select w.id as Id
from weather w join weather t on DATEDIFF(w.recordDate,t.recordDate)=1 and w.temperature>t.temperature