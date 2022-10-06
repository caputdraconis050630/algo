class Solution:
	def reverseString(self, s: List[str]) -> None:
		j = len(s) - 1
		i = 0
		while i < j:
			c = s[i]
			s[i] = s[j]
			s[j] = c
			i += 1
			j -= 1
			
        