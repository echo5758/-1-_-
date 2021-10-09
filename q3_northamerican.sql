SELECT Id,ShipCountry,
(CASE WHEN ShipCountry='USA' THEN 'NorthAmerica'
WHEN ShipCountry='Mexico' THEN 'NorthAmerica'
WHEN ShipCountry='Canada' THEN 'NorthAmerica'
ELSE 'OtherPlace' END) as AotherColumn
from 'Order'
where Id>=15445
order by Id
limit 0,20;