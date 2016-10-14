# In the name of Allah, Most Gracious, Most Merciful

# /
# 
# 
# 
# 
# ??

def T(n):
	r = 10**n
	t = n-2
	while t >= 0:
		r += (10**t)
		t -= 2
	return r
	

print T(1)
print T(2)
print T(3)
print T(4)
print T(5)
print T(6)
