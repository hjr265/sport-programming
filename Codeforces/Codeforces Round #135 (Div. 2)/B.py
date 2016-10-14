# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Round #135 (Div. 2)/B
# Special Offer! Super Price 999 Bourles!
# implementation
# http://codeforces.com/contest/219/problem/B
# 
# AC (00:20:29)

def count9(p):
	p = str(p)[::-1]
	r = 0
	for c in p:
		if c == '9':
			r += 1
		else:
			break
	return r

p, d = map(int, raw_input().split())

t = [1]
for i in range(20):
	t.append(t[i]*10)

r = p

for i in range(20):
	while t[i] <= p and t[i] <= d and (p/t[i])%10 != 9:
		p -= t[i]
		d -= t[i]
	if count9(r) < count9(p):
		r = p
print r
