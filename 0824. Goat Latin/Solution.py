class Solution:
    def toGoatLatin(self, S: str) -> str:
        vowels = set('aeiouAEIOU')
        wordList = S.split()
        for i in range(len(wordList)):
            if wordList[i][0] not in vowels:
                wordList[i] = wordList[i][1:] + wordList[i][0]
            wordList[i] += 'ma' + 'a' * (i + 1)
        return ' '.join(wordList)
