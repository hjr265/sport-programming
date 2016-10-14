# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Round #128 (Div. 2)/B
# Game on Paper
# brute force, implementation
# http://www.codeforces.com/contest/203/problem/B
# 
# AC (00:29)

n, m = map(int, raw_input().split())
g = [[0]*n for _ in range(n)]
for i in range(m):
	x, y = map(int, raw_input().split())
	g[y-1][x-1] = i+1;
z = 1<<28
for i in range(1, n-1):
	for j in range(1, n-1):
		if g[i][j] == 0:
			continue
		r = 0
		for di, dj in [(0, 0), (-1, 0), (-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1)]:
			if g[i+di][j+dj] == 0:
				break
			r = max(r, g[i+di][j+dj])
		else:
			z = min(z, r)
if z == 1<<28:
	z = -1
print z
