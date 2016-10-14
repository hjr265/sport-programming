# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Round #111 (Div. 2)/A
# Twins
# greedy, sortings
# http://codeforces.com/problemset/problem/160/A
# 
# AC (Sep 4, 2012 4:35:23 PM)

n = input()
a = map(int, raw_input().split())

s0 = 0
s1 = sum(a)

a = sorted(a)

i = n-1
while i >= 0 and s0 <= s1:
	s0 += a[i]
	s1 -= a[i]
	i -= 1

print n-i-1
