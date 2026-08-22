# Write your MySQL query statement below
SELECT a.id 
FROM Weather AS a 
JOIN Weather AS b 
  -- 1. Self-Join kiya aur check kiya ki table 'a' ka din, 
  -- table 'b' (pichle din) se theek 1 din aage ho.
  ON DATEDIFF(a.recordDate, b.recordDate) = 1 
WHERE 
  -- 2. Filter kiya ki aaj ka temperature pichle din se zyada ho.
  a.temperature > b.temperature;
