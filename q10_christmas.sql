SELECT group_concat(ProductName)
FROM
(SELECT ProductName,C.OrderDate
FROM 'Product' A,'OrderDetail' B,'Order' C,'Customer' D
WHERE A.Id=B.ProductId and B.OrderId=C.Id and C.CustomerId=D.Id
and D.CompanyName='Queen Cozinha' and C.OrderDate>'2014-12-24' and C.OrderDate<'2014-12-26'
ORDER BY A.Id
);