K = int(input())
S = input()

i = 0
res = ""
while i < len(S):
	res += S[i]
	i += K
print(res)