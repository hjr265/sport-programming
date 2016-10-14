# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Round #173 (Div. 2)/A
# Bit++
# implementation
# http://codeforces.com/contest/282/problem/A
# 
# AC (Dec 10, 2013 8:57:19 AM)

n = input()

x = 0
for i in range(n):
  if '+' in raw_input():
    x += 1
  else:
    x -= 1

print x
