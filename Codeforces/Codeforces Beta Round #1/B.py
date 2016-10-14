# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Beta Round #1/B
# Spreadsheets
# implementation, math
# http://codeforces.com/contest/1/problem/B
# 
# AC (00:17:02)

import re

n = input()

while n > 0:
	s = raw_input()
	
	m = re.match(r'R(\d+)C(\d+)', s)
	if m:
		r = m.group(1)
		c = int(m.group(2))
		
		cc = ''
		while c > 0:
			c -= 1
			cc += 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'[c%26]
			c /= 26
		cc = cc[::-1]
		if cc == '':
			cc = 'A'
		
		print '%s%s' % (cc, r)
		
	else:
		m = re.match(r'([A-Z]+)(\d+)', s)
		
		r = m.group(2)
		c = m.group(1)
		
		cc = 0
		for x in c:
			cc *= 26
			cc += 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'.index(x)+1
		
		print 'R%sC%d' % (r, cc)
		
	
	n -= 1
