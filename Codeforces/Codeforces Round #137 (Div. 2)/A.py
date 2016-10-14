# In the name of Allah, Most Gracious, Most Merciful

# /
# 
# 
# 
# 
# ??

n, k = map(int, raw_input().split())
a = map(int, raw_input().split())

for i in range(k-1, n):
	if a[i] != a[k-1]:
		print -1
		break
else:
	l = 0
	for i in range(0, k-1):
		if a[i] != a[i+1]:
			l = i+1
	print l
