import sys
n = int(input())

def cnt(table, x, y, try_i):

	table[x][y] = try_i
	
	# if sw_hori[x-1]:
	# 	temp = 0
	# 	cnt = 0
	# 	for i in table[x][1:y+1]:
	# 		if temp < i:
	# 			cnt += 1
	# 			temp = i
	# 	if cnt == table[x][0]:
	# 		if temp != n:
	# 			table[x][y] = 0
	# 			return False
	# 		sw_hori[x-1] = 0

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
		
	# if sw_verti[y-1]:
	# 	temp = 0
	# 	cnt = 0
	# 	for i in range(1,x+1):
	# 		if temp < table[i][y]:
	# 			cnt += 1
	# 			temp = table[i][y]
		
		# if cnt == table[0][y]:
		# 	if temp != n:
		# 		table[x][y] = 0
		# 		return False
		# 	sw_verti[y-1] = 0

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

	# if not(cnt(table, x , y, try_i)):
	# 	return False

	if (bit_hori1[x] < (1 << try_i) and sw_hori[x]):
		if cnt_hori[x] == table[x][0]:
			return False
		if try_i == n:
			sw_hori[x] = 0

	if (bit_verti1[y] < (1 << try_i) and sw_verti[y]):
		if cnt_verti[y] == table[0][y]:
			return False
		if try_i == n:
			sw_verti[y] = 0

	if (x == n or y == n):
		if not(cnt(table, x, y, try_i)):
			return False

	return True

cnt_hori = [0 for _ in range(n+1)]
cnt_verti = [0 for _ in range(n+1)]
bit_table = [0 for _ in range(n+1)]
bit_hori = [0 for _ in range(n+1)]
bit_verti = [0 for _ in range(n+1)]
bit_hori1 = [0 for _ in range(n+1)]
bit_verti1 = [0 for _ in range(n+1)]
sw_hori = [1 for _ in range(n+1)]
sw_verti = [1 for _ in range(n+1)]

table=[]
for _ in range(n+2):
	table.append(list(map(int,sys.stdin.readline().rstrip().split())))

def dfs(x, y):
	sw_ho=0
	sw_ver=0
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
			if (bit_hori1[x] < (1 << i)):
				bit_hori1[x] |= (1 << i)
				cnt_hori[x] += 1
				sw_ho = 1
			if (bit_verti1[y] < (1 << i)):
				bit_verti1[y] |= (1 << i)
				cnt_verti[y] += 1
				sw_ver = 1
			if y == n:
				dfs(x+1, 1)
			else:
				dfs(x, y+1)
			table[x][y] = 0
			bit_hori[x] &= ~(1 << i)
			bit_verti[y] &= ~(1 << i)
			bit_hori1[x] &= ~(1 << i)
			bit_verti1[y] &= ~(1 << i)
			if (sw_ho):
				bit_hori1[x] &= ~(1 << i)
				cnt_hori[x] -= 1
				sw_ho = 0
			if (sw_ver):
				bit_verti1[y] &= ~(1 << i)
				cnt_verti[y] -= 1
				sw_ver = 0

dfs(1, 1)
print("error")
