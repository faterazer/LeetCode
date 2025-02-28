import heapq
from collections import defaultdict


class FoodRatings:

    def __init__(self, foods: list[str], cuisines: list[str], ratings: list[int]) -> None:
        self.food_map = {}
        self.cuisine_map = defaultdict(list)
        for food, cuisine, rating in zip(foods, cuisines, ratings):
            self.food_map[food] = [cuisine, rating]
            self.cuisine_map[cuisine].append((-rating, food))
        for v in self.cuisine_map.values():
            heapq.heapify(v)

    def changeRating(self, food: str, newRating: int) -> None:
        p = self.food_map[food]
        p[1] = newRating
        heapq.heappush(self.cuisine_map[p[0]], (-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        v = self.cuisine_map[cuisine]
        while v[0][0] != -self.food_map[v[0][1]][1]:
            heapq.heappop(v)
        return v[0][1]


# Your FoodRatings object will be instantiated and called as such:
# obj = FoodRatings(foods, cuisines, ratings)
# obj.changeRating(food,newRating)
# param_2 = obj.highestRated(cuisine)
