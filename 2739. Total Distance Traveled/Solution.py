class Solution:
    def distanceTraveled(self, mainTank: int, additionalTank: int) -> int:
        return (mainTank + min((mainTank - 1) // 4, additionalTank)) * 10
