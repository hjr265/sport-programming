# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Round #127 (Div. 2)/C
# Clear Symmetry
# math
# http://codeforces.com/contest/202/problem/C
# 
# AC (01:22:07)

"""Z = [50]*102

M = []

def magic(i, j, n, s):
	if s > 100:
		return
	Z[s] = min(Z[s], n)
	if j > (n+1)/2:
		return magic(i+1, 1, n, s)
	if i > (n+1)/2:
		return
	if M[i-1][j] == 0 and M[i][j-1] == 0:
		M[i][j] = 1
		t = 4
		if i == (n+1)/2:
			t /= 2
		if j == (n+1)/2:
			t /= 2
		magic(i, j+1, n, s+t)
		M[i][j] = 0
	magic(i, j+1, n, s)

for n in range(1, 14):
	M = [[0]*(n+2) for _ in range(n+2)]
	magic(1, 1, n, 0)
	print n, Z

"""

Z = [1, 1, 3, 5, 3, 3]
n = 8
for i in range(5, 16, 2):
	Z += [i]*n
	n += 4

x = input()
print Z[x]
#"""
