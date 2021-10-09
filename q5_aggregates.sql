SELECT CategoryName,number,averagePrice,miniPrice,maxiPrice,
(
    CASE WHEN number>10 THEN totalUnits
    ELSE '' END
) as TotalUnitsOnOrder
FROM (
    SELECT CategoryId,count(*) as number,round(avg(UnitPrice),2) as averagePrice,
    min(UnitPrice) as miniPrice, max(UnitPrice) as maxiPrice,sum(UnitsOnOrder) 
    as totalUnits
FROM 'Product'GROUP BY CategoryId),'Category'
WHERE Id=CategoryId
ORDER BY Id;