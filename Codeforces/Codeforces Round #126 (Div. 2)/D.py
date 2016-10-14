# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Round #126 (Div. 2)/D
# Programming Language
# parsing
# http://codeforces.com/contest/200/problem/D
# 
# AC (00:25:42)

import re

n = input()

procedures = {}
for i in range(n):
	line = raw_input()
	match = re.match(r'\s*void\s+(\w+)\s*\(([\w\s,]*)\)', line)
	name = match.group(1)
	args = match.group(2).split(',')
	for i in range(len(args)):
		args[i] = args[i].strip()
	if name not in procedures:
		procedures[name] = []
	procedures[name].append(args)

m = input()

variables = {}
for i in range(m):
	line = raw_input()
	match = re.match(r'\s*(\w+)\s*(\w+)\s*', line)
	kind = match.group(1)
	name = match.group(2)
	variables[name] = kind

k = input()

for i in range(k):
	r = 0
	
	line = raw_input()
	match = re.match(r'\s*(\w+)\s*\(([\w\s,]*)\)', line)
	name = match.group(1)
	args = match.group(2).split(',')
	for i in range(len(args)):
		args[i] = variables[args[i].strip()]
	if name in procedures:
		for signature in procedures[name]:
			if len(args) == len(signature):
				for i in range(len(args)):
					if args[i] != signature[i] and signature[i] != 'T':
						break
				else:
					r += 1
	
	print r
