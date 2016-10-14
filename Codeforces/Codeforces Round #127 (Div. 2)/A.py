# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Round #127 (Div. 2)/A
# LLPS
# brute force, greedy, strings
# http://codeforces.com/contest/202/problem/A
# 
# AC (00:07:58)

def is_palindrome(S):
	for i in range(len(S)):
		if S[i] != S[len(S)-1-i]:
			return False
	return True

S = raw_input()

R = []
for i in range(1, 1<<len(S)):
	R.append("")
	for j in range(len(S)):
		if i&(1<<j):
			R[-1] += S[j]
	if not is_palindrome(R[-1]):
		R.pop()
R.sort()
print R[-1]
