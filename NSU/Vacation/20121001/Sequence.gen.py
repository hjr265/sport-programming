inFile = file('Sequence.in3', 'w')
ansFile = file('Sequence.ans3', 'w')

N = 100
inFile.write('%d\n' % N)
k = 1
for i in range(1, 10000):
	for j in range(i):
		inFile.write('%d\n' % k)
		ansFile.write('%d\n' % i)
		k += 1
		if k > N:
			exit()
exit()

N = 28
inFile.write('%d\n' % N)
for i in range(N):
	inFile.write('%d\n' % (1<<i))
ansFile.write('')
