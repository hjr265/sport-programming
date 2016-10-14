# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Round #128 (Div. 2)/C
# Photographer
# greedy
# http://www.codeforces.com/contest/203/problem/C
# 
# AC (00:10)

n, d = map(int, raw_input().split())
a, b = map(int, raw_input().split())
t = []
for i in range(n):
	x, y = map(int, raw_input().split())
	t.append((x*a+y*b, i))
t.sort()
r = []
for i in range(len(t)):
	if d < t[i][0]:
		break
	d -= t[i][0]
	r.append(str(t[i][1]+1))
print len(r)
print ' '.join(r)
