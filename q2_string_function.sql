SELECT distinct ShipName,SUBSTR(ShipName,1,INSTR(ShipName,'-')-1) from 'Order'
where ShipName like '%-%'
order by ShipName;