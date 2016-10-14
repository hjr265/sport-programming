# In the name of Allah, Most Gracious, Most Merciful

# Codeforces/Codeforces Round #126 (Div. 2)/C
# Football Championship
# implementation
# http://codeforces.com/contest/200/problem/C
# 
# AC (01:18:46)

games = []
teams = []
points = {}
diffs = {}
goals = {}
vsberland = []

def order(a, b):
	if points[a] > points[b]:
		return -1
	elif points[a] < points[b]:
		return 1
	if diffs[a] > diffs[b]:
		return -1
	elif diffs[a] < diffs[b]:
		return 1
	if goals[a] > goals[b]:
		return -1
	elif goals[a] < goals[b]:
		return 1
	return cmp(a, b)

for i in range(5):
	tokens = raw_input().split()
	team1 = tokens[0]
	team2 = tokens[1]
	goals1, goals2 = map(int, tokens[2].split(':'))
	games.append([(team1, goals1), (team2, goals2)])
	if team1 not in teams:
		teams.append(team1)
		points[team1] = 0
		diffs[team1] = 0
		goals[team1] = 0
	if team2 not in teams:
		teams.append(team2)
		points[team2] = 0
		diffs[team2] = 0
		goals[team2] = 0
	if goals1 > goals2:
		points[team1] += 3
	elif goals1 < goals2:
		points[team2] += 3
	else:
		points[team1] += 1
		points[team2] += 1
	diffs[team1] += goals1
	diffs[team2] -= goals1
	diffs[team1] -= goals2
	diffs[team2] += goals2
	goals[team1] += goals1
	goals[team2] += goals2
	if team1 == 'BERLAND':
		vsberland.append(team2)
	elif team2 == 'BERLAND':
		vsberland.append(team1)

teams.sort(cmp=order)

result = (10000, 0, 10000)

team1 = 'BERLAND'
for team2 in teams:
	if team2 != team1 and team2 not in vsberland:
		points[team1] += 3
		
		for goals1 in range(0, 201):
			for goals2 in range(0, goals1):
				diffs[team1] += goals1
				diffs[team2] -= goals1
				diffs[team1] -= goals2
				diffs[team2] += goals2
				goals[team1] += goals1
				goals[team2] += goals2
				
				teams.sort(cmp=order)
				if teams[0] == team1 or teams[1] == team1:
					if goals1-goals2 < result[0] or goals1-goals2 == result[0] and goals2 < result[2]:
						result = (goals1-goals2, goals1, goals2)
				
				diffs[team1] -= goals1
				diffs[team2] += goals1
				diffs[team1] += goals2
				diffs[team2] -= goals2
				goals[team1] -= goals1
				goals[team2] -= goals2
		
		break

if result[0] == 10000:
	print 'IMPOSSIBLE'
else:
	print '%d:%d'%(result[1], result[2])
