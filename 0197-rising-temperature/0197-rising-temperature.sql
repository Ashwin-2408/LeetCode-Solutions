# Write your MySQL query statement below

select w1.id from Weather w1 join 
Weather w2 on w1.recordDate-1 = w2.recordDate where w2.temperature < w1.temperature;