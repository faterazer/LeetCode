class Solution:
	def sortSentence(self, s: str) -> str:
		l = sorted([w for w in s.split()], key=lambda x: int(x[-1]))
		return " ".join(w[:-1] for w in l)
