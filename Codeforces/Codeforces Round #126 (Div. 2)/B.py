# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Round #126 (Div. 2)/B
# Drinks
# implementation, math
# http://codeforces.com/contest/200/problem/B
# 
# AC (00:04:25)

n = input()
p = map(float, raw_input().split())

r = 0.

for i in range(len(p)):
	r += p[i]/100;

print r*100/len(p)
