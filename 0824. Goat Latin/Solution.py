class Solution:
    def toGoatLatin(self, S: str) -> str:
        vowels = set('aeiouAEIOU')
        wordList = S.split()
        ret = []
        index = 1
        for word in wordList:
            ret.append(word if word[0] in vowels else word[1:] + word[0])
            ret[-1] += 'ma' + ('a' * index)
            index += 1
        return ' '.join(ret)
