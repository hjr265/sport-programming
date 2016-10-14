# In the name of Allah, Most Gracious, Most Merciful

# Recover the Sequence
# implementation
# AC (22:11)

def recover_sort(arr, debug):
	n = len(arr)
	if n <= 1:
		return arr
	mid = n/2
	first_half = recover_sort(arr[:mid], debug)
	second_half = recover_sort(arr[mid:], debug)
	return recover(first_half, second_half, debug)

def recover(arr1, arr2, debug):
	result = []
	while len(arr1) > 0 and len(arr2) > 0:
		if debug[0] == 1:
			result.append(arr1[0])
			arr1.pop(0)
		else:
			result.append(arr2[0])
			arr2.pop(0)
		debug.pop(0)
	result += arr1
	result += arr2
	return result

def checksum(arr):
	result = 1
	for i in range(len(arr)):
		result = (31*result+arr[i])%1000003
	return result

for no in range(1, input()+1):
	N = input()
	debug = [int(x) for x in raw_input()]
	order = recover_sort([i+1 for i in range(N)], debug)
	result = [0]*N
	for i in range(N):
		result[order[i]-1] = i+1
	print 'Case #%d: %d'%(no, checksum(result))
