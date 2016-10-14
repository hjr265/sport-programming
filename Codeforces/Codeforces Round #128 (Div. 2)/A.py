# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Round #128 (Div. 2)/A
# Two Problems
# brute force, implementation
# http://www.codeforces.com/contest/203/problem/A
# 
# AC (00:03)

x, t, a, b, da, db = map(int, raw_input().split())
for i in range(t):
	for j in range(t):
		if a-i*da+b-j*db == x or a-i*da == x or b-j*db == x or x == 0:
			print 'YES'
			exit()
print 'NO'
