class Solution:
    def maximumBinaryString(self, binary: str) -> str:
        i = binary.find("0")
        if i < 0:
            return binary

        cnt = binary.count("1", i)
        return "1" * (len(binary) - 1 - cnt) + "0" + "1" * cnt
