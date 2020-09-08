class Solution:
    def wordPattern_MK1(self, pattern: str, str: str) -> bool:
        str_list = str.split(' ')
        return len(pattern) == len(str_list) and len(set(zip(pattern, str_list))) == len(set(pattern)) == len(set(str_list))

    def wordPattern_MK2(self, pattern: str, str: str) -> bool:
        str_list = str.split(' ')
        return list(map(pattern.find, pattern)) == list(map(str_list.index, str_list))
