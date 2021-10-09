SELECT RegionDescription,D.FirstName,D.LastName,max(D.BirthDate)
FROM 'Region' A, 'Territory' B, 'EmployeeTerritory' C,'Employee' D
WHERE A.Id=B.RegionId and B.Id=C.TerritoryId and C.EmployeeId=D.Id
GROUP BY RegionDescription
ORDER BY RegionId;