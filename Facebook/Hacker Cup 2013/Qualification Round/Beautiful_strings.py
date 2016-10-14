import string

m = input()

for i in range(m):
	line = raw_input()
	line = line.lower()

	freqs = {}
	for char in line:
		if char in string.ascii_lowercase:
			freqs[char] = freqs.get(char, 0)+1

	freqs = freqs.items()
	freqs.sort(lambda a, b: cmp(a[1], b[1]), reverse=True)

	score = 0
	value = 26
	for char, freq in freqs:
		score += freq*value
		value -= 1

	print 'Case #%d: %d' % (i+1, score)