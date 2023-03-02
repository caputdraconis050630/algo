def main():
	X = 0
	n = int(input())

	for i in range(n):
		op = input()
		if op.startswith("++") or op.endswith("++"):
			X += 1
		else:
			X -= 1

	print(X)

if __name__ == "__main__":
	main()