def OOB(y, x):
	if y < 0 or y >= N or x < 0 or x >= N:
		return True
	else:
		return False

def dfs(i, j):
	cnt = 0
	for q in range(8):
		tmp_y = i + dy[q]
		tmp_x = j + dx[q]
		tmp_cnt = 0
		if OOB(tmp_y, tmp_x):
			continue
		while board[tmp_y][tmp_x] == 'W':
			tmp_cnt += 1
			tmp_y += dy[q]
			tmp_x += dx[q]
			if OOB(tmp_y, tmp_x):
				break
		if OOB(tmp_y, tmp_x) == False:
			if board[tmp_y][tmp_x] == 'B':
				cnt += tmp_cnt
	return cnt

N = int(input())
M = 0
x = 0
y = 0
dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, 1, 1, 1, 0, -1, -1, -1]
board = [""] * N

		

for i in range(N):
	board[i] = input()

for i in range(N):
	for j in range(N):
		if board[i][j] != '.':
			continue
		ans = dfs(i, j)
		if M < ans:
			x = j
			y = i
			M = ans



# print result
if M == 0:
	print("PASS")
else:
	print("{0} {1}".format(x, y))
	print(M)

