import pandas as pd


def find_improved_efficiency_drivers(drivers: pd.DataFrame, trips: pd.DataFrame) -> pd.DataFrame:
    trips = trips.assign(trip_date=pd.to_datetime(trips["trip_date"]), fuel_efficiency=trips["distance_km"] / trips["fuel_consumed"])
    buff = {}
    for line in trips.itertuples():
        driver_id = line.driver_id
        half_data = buff.setdefault(driver_id, [[], []])
        idx = int(line.trip_date.month >= 7)
        half_data[idx].append(line.fuel_efficiency)

    df = []
    for driver_id, half_data in buff.items():
        if not half_data[0] or not half_data[1]:
            continue
        first_half_avg = sum(half_data[0]) / len(half_data[0])
        second_half_avg = sum(half_data[1]) / len(half_data[1])
        if second_half_avg > first_half_avg:
            df.append(
                {
                    "driver_id": driver_id,
                    "first_half_avg": round(first_half_avg, 2),
                    "second_half_avg": round(second_half_avg, 2),
                    "efficiency_improvement": round(second_half_avg - first_half_avg, 2),
                }
            )
    df = pd.DataFrame(df).merge(drivers, on="driver_id").sort_values(by=["efficiency_improvement", "driver_name"], ascending=[False, True])
    return df[["driver_id", "driver_name", "first_half_avg", "second_half_avg", "efficiency_improvement"]]
