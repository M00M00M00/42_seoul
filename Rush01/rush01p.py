import sys
n = int(input())

def cnt(table, x, y, try_i):

	table[x][y] = try_i
	

	temp = 0
	cnt = 0
	for i in table[x][1:y+1]:
		if temp < i:
			cnt += 1
			temp = i
	if cnt > table[x][0]:
		table[x][y] = 0
		return False
	if temp == n:
		if cnt != table[x][0]:
			table[x][y] = 0
			return False

	if y == n:
		temp = 0
		cnt = 0
		for i in range(n,0,-1):
			if temp < table[x][i]:
				cnt += 1
				temp = table[x][i]

		if cnt != table[x][n+1]:
			table[x][y] = 0
			return False
		
	temp = 0
	cnt = 0
	for i in range(1,x+1):
		if temp < table[i][y]:
			cnt += 1
			temp = table[i][y]
	if cnt > table[0][y]:
		table[x][y] = 0
		return False		
	if temp == n:
		if cnt != table[0][y]:
			table[x][y] = 0
			return False

	if x == n:
		temp = 0
		cnt = 0
		for i in range(n,0,-1):
			if temp < table[i][y]:
				cnt += 1
				temp = table[i][y]
		if cnt != table[n+1][y]:
			table[x][y] = 0
			return False

	table[x][y] = 0
	return True

def isCorrect(table, x, y, try_i):
	if (bit_hori[x] & (1<<try_i)):
		return False
	
	if (bit_verti[y] & (1<<try_i)):
		return False

	if not(cnt(table, x , y, try_i)):
		return False

	return True

sw_hori = [1 for _ in range(n)]
sw_verti = [1 for _ in range(n)]
bit_hori = [0 for _ in range(n+1)]
bit_verti = [0 for _ in range(n+1)]
table=[]
for _ in range(n+2):
	table.append(list(map(int,sys.stdin.readline().rstrip().split())))

def dfs(x, y):
	if x == n+1 and y == 1:
		print("\n")
		for i in table:
			print(" ".join(list(map(str,i))))
		exit()


	for i in range(1,n+1):
		if isCorrect(table, x, y, i):
			table[x][y] = i
			bit_hori[x] |= (1 << i)
			bit_verti[y] |= (1 << i)
			if y == n:
				dfs(x+1, 1)
			else:
				dfs(x, y+1)
			table[x][y] = 0
			bit_hori[x] &= ~(1 << i)
			bit_verti[y] &= ~(1 << i)

dfs(1, 1)
print("error")
