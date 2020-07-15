SELECT Weather.Id
FROM Weather JOIN Weather w
ON DATEDIFF(Weather.RecordDate, w.RecordDate) = 1 AND Weather.Temperature > w.Temperature
