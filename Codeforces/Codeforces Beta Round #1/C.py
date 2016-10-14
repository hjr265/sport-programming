# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Beta Round #1/C
# Ancient Berland Circus
# geometry
# http://codeforces.com/contest/1/problem/C
# 
# AC (Sep 9, 2012 8:10:55 PM)

import math

EPS = 1e-4

def gcd(a, b):
	while abs(a) > EPS and abs(b) > EPS:
		if a > b:
			a -= math.floor(a/b)*b
		else:
			b -= math.floor(b/a)*a
	return a+b

def dist(x0, y0, x1, y1):
	return math.sqrt((x0-x1)**2+(y0-y1)**2)

x0, y0 = map(float, raw_input().split())
x1, y1 = map(float, raw_input().split())
x2, y2 = map(float, raw_input().split())

s = abs(x0*y1+x1*y2+x2*y0-y0*x1-y1*x2-y2*x0)/2
a = dist(x0, y0, x1, y1)
b = dist(x0, y0, x2, y2)
c = dist(x1, y1, x2, y2)
r = (a*b*c)/(4*s)

A = math.acos((b**2+c**2-a**2)/(2*b*c))
B = math.acos((a**2+c**2-b**2)/(2*a*c))
C = math.acos((a**2+b**2-c**2)/(2*a*b))

t = gcd(gcd(A, B), C)

n = math.pi/t

print (n/2)*(r**2)*math.sin(2*math.pi/n)
