# In the name of Allah, Most Gracious, Most Merciful

# /
# 
# 
# 
# 
# ??

n, m, k = map(int, raw_input().split())

R = list(range(1000))
C = list(range(1000))
G = []

for i in range(n):
	G.append(map(int, raw_input().split()))

while k > 0:
	s, x, y = raw_input().split()
	x = int(x)-1
	y = int(y)-1
	
	if s == 'g':
		print G[R[x]][C[y]]
	elif s == 'c':
		C[x], C[y] = C[y], C[x]
	elif s == 'r':
		R[x], R[y] = R[y], R[x]
	
	k -= 1
