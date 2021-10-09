SELECT Id,OrderDate,PDate,round(julianday(OrderDate) - julianday(PDate),2)
FROM
(SELECT Id,OrderDate,OrderDate as PDate
FROM 'Order'
WHERE CustomerId='BLONP'and Id='16766'
UNION
SELECT Id,OrderDate,
LAG(OrderDate,1,0) OVER ( ORDER BY OrderDate ) as PDate
FROM 'Order'
WHERE CustomerId='BLONP'
ORDER BY OrderDate LIMIT 1,10);