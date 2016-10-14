# In the name of Allah, Most Gracious, Most Merciful

# /
# 
# 
# 
# 
# ??

class ORSolitaireDiv2:
	def getMinimum(self, numbers, goal):
		numbers = filter(lambda number: (number|goal) == goal, numbers)
	
		for i in range(1<<len(numbers)):
			test = 0
			for j in range(len(numbers)):
				if (i&(1<<j)) > 0:
					test |= numbers[j]
			if test == goal:
				break
		else:
			return 0
	
		best = 22
		for i in range(32):
			matches = 0
			for number in numbers:
				if (number&(1<<i)) > 0 and (number|goal) == goal:
					matches += 1
			if matches == 0:
				continue
			print i, matches
			best = min(best, matches)
		
		if best == 22:
			best = 0
		return best

