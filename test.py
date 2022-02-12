from ssl import _create_default_https_context
import sys

n= int(input())

table=[]
hori=[0 for _ in range(n)]
verti=[0 for _ in range(n)]
cnt_hori=[0 for _ in range(n)]
cnt_verti=[0 for _ in range(n)]

for _ in range(n+2):
	table.append(list(map(int,sys.stdin.readline().rstrip().split())))

def is_correct(x,y,i):
	if (hori[x] & (1 << i)):
		return False
	
	if (verti[y] & (1 << i)):
		return False
	
	if (hori[x] < (1 << i)):
		if cnt_hori[x-1] == table[x][0]:
			return False
	
	if (verti[x] < (1 << i)):
		if cnt_hori[y-1] == table[0][y]:
			return False
	
def dfs(x,y):
	sw_ho=0
	sw_ver=0
	if x == n+1 and y == 1:
		print("\n")
		for i in table:
			print(" ".join(list(map(str,i))))
		exit()
	else:
		if is_correct(x,y,i):
			if (hori[x] < (1 << i)):
				cnt_hori[x-1] += 1
				sw_ho=1
			if (verti[y] < (1 << i)):
				cnt_verti[y-1] += 1
				sw_ver=1
			table[x][y] = i
			hori[x] |= (1 << i)
			verti[y] |= (1 << i)
			if y == n:
				dfs(x+1,1)
			else:
				dfs(x,y+1)
			if (sw_ho):
				cnt_hori[x-1] -= 1
			if (sw_ver):
				cnt_verti[y-1] -= 1
			table[x][y] = 0
			hori[x] & ~(1 << i)
			verti[y] & ~(1 << i)

