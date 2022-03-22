class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        Alice_count = Bob_count = 0
        for i in range(1, len(colors) - 1):
            if colors[i - 1] == colors[i] == colors[i + 1]:
                if colors[i] == 'A':
                    Alice_count += 1
                else:
                    Bob_count += 1
        return Alice_count > Bob_count
