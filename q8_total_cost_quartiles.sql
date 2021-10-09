SELECT CompanyName,CustomerId,TotalExpenditures
FROM
(SELECT NTILE(4) OVER (ORDER BY TotalExpenditures) num,*
FROM
(SELECT CustomerId,ifNULL(CompanyName,'MISSNG_NAME') as CompanyName,TotalExpenditures
FROM
(SELECT CustomerId,round(sum(Expenditures),2) as TotalExpenditures
FROM
(SELECT A.CustomerId,B.UnitPrice*B.Quantity as Expenditures
FROM 'Order' A, OrderDetail B
WHERE A.Id=B.OrderId)
GROUP BY CustomerId)
natural left outer join
(   SELECT Id as CustomerId,CompanyName
    FROM Customer
    GROUP BY CustomerId)
)
)
WHERE num=1;