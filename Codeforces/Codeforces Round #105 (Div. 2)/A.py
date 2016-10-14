# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Round #105 (Div. 2)/A
# Insomnia cure
# implementation, math
# http://codeforces.com/problemset/problem/148/A
# 
# AC (Sep 3, 2012 12:14:19 PM)

import itertools

def gcd(a, b):
	return a if b == 0 else gcd(b, a%b)

def lcm(a, b):
	return a/gcd(a,b)*b

k = input()
l = input()
m = input()
n = input()
d = input()

z = 0

x = [k, l, m, n]
for i in range(1, 5):
	for y in itertools.combinations(x, i):
		z -= d/reduce(lambda a, b: lcm(a, b), y)*((-1)**len(y))

print z
