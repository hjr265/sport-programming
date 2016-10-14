# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Round #135 (Div. 2)/A
# k-String
# implementation, strings
# http://codeforces.com/contest/219/problem/A
# 
# AC (00:8:14)

k = input()
s = raw_input()

m = {}
for c in s:
	m[c] = 1 if c not in m else m[c]+1

for c in 'abcdefghijklmnopqrstuvwxyz':
	if c in m and m[c]%k != 0:
		print -1
		break
else:
	r = ''
	for c in 'abcdefghijklmnopqrstuvwxyz':
		if c in m:
			r += c*(m[c]/k)
	print r*k
