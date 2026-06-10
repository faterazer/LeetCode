class Solution:
    def earliestFinishTime(
        self, landStartTime: list[int], landDuration: list[int], waterStartTime: list[int], waterDuration: list[int]
    ) -> int:
        def solve(start_time1: list[int], duration1: list[int], start_time2: list[int], duration2: list[int]) -> int:
            min_finish = min(t + d for t, d in zip(start_time1, duration1))
            return min(max(min_finish, t) + d for t, d in zip(start_time2, duration2))

        land_water = solve(landStartTime, landDuration, waterStartTime, waterDuration)
        water_land = solve(waterStartTime, waterDuration, landStartTime, landDuration)
        return min(land_water, water_land)
