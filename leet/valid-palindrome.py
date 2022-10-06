class Solution:
	def isNonAlphaNumeric(self, c) -> bool:
			# NonAlphaNumeric -> False
			# AlphaNumeric -> True
			if c.isalnum():
				return False
			return True
		

	def isPalindrome(self, s: str) -> bool:
		s = s.lower()
		len_s = len(s) - 1
		i = 0
		j = len_s
		while i < j:
			while self.isNonAlphaNumeric(s[i]):
				if i < len_s:
					i += 1
				else:
					break
			while self.isNonAlphaNumeric(s[j]):
				if j > 0:
					j -= 1
				else:
					break
			if (i > j):
				return True
			if s[i] != s[j]:
				return False
			else:
				if i < j:
					i += 1
					j -= 1
		return True
