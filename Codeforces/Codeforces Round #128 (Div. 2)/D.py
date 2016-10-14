# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Round #128 (Div. 2)/D
# Hit Ball
# geometry, implementation, math
# http://www.codeforces.com/contest/203/problem/D
# 
# AC (00:18)

import math

def repl(x, m):
	x -= math.floor(x/(2*m))*2*m
	while x > 2*m:
		x -= 2*m
	while x < 0:
		x += 2*m
	if x > m:
		x = 2*m-x
	return x

a, b, m = map(float, raw_input().split())
vx, vy, vz = map(float, raw_input().split())
t = -m/vy
x = repl(a/2+vx*t, a)
z = repl(vz*t, b)
print x, z
