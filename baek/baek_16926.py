def rotate(N, M, arr):
	

N, M, R = map(int, input().split())

arr = []

# Input Array
for i in range(N):
	tmp = list(map(int, input().split()))
	arr.append(tmp)

# Rotate
for i in range(R):
	rotate(N, M, arr)

# Print Result
for i in range(N):
	print(*arr[i])

