def main():
	flag = False
	str1 = input().lower()
	str2 = input().lower()

	strLen = len(str1)
	for i in range(strLen):
		if str1[i] == str2[i]:
			pass
		elif str1[i] < str2[i]:
			print(-1)
			flag = True
			break
		else:
			print(1)
			flag = True
			break
	if not flag:
		print(0)

if __name__ == "__main__":
	main()