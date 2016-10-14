n = input()
a = map(int, raw_input().split())

b = sorted(a)

x = 0
for i in range(n):
	if a[i] != b[i]:
		x += 1

print 'YES' if x <= 2 else 'NO'
