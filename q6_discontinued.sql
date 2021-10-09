SELECT E.ProductName,CompanyName,ContactName
FROM
(SELECT Id,C.ProductId,OrderDate,CustomerId,min(OrderDate),C.ProductName
FROM
(SELECT OrderId,B.ProductId,A.ProductName
FROM 
(SELECT Id,ProductName FROM Product WHERE Discontinued=1) A, OrderDetail B
WHERE A.Id=B.ProductId) C,'Order' D
WHERE C.OrderID=D.Id
GROUP BY C.ProductId) E, 'Customer' F
WHERE E.CustomerId=F.Id
ORDER BY E.ProductName;