SELECT CompanyName,round(countlate*100*1./countall,2) as rate
FROM
(SELECT ShipVia,count(*) as countall
FROM 'Order'
GROUP BY ShipVia) A ,
(SELECT ShipVia,count(*) as countlate
FROM (SELECT * FROM 'Order' WHERE ShippedDate>RequiredDate)
GROUP BY ShipVia) B,
'Shipper' C
WHERE A.ShipVia=B.ShipVia and A.ShipVia=C.Id
ORDER BY rate DESC;