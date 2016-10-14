# In the name of Allah, Most Gracious, Most Merciful

# /
# 
# 
# 
# 
# ??

n = input()

scores = {}
records = {}

for i in range(n):
	name, score = raw_input().split()
	score = int(score)
	if name not in scores:
		scores[name] = 0
		records[name] = []
	scores[name] += score
	records[name].append((scores[name], i))

highest = sorted(scores.values())[-1]

winner = ('', 1<<28)

for name, score in scores.items():
	if score == highest:
		for record, i in records[name]:
			if record >= highest and i < winner[1]:
				winner = (name, i)
				break

print winner[0]
