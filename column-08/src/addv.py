# coding: utf-8

def addv(arr, luv):
	cum = [0] * len(arr)

	for elem in luv:
		if elem[0] - 1 >= 0:
			cum[elem[0]-1] -= elem[2]
		cum[elem[1]] += elem[2]
	
	for i in xrange(len(arr)-1, -1, -1):
		if i >= len(arr) - 1:
			arr[i] = cum[i]
		else:
			arr[i] = arr[i+1] + cum[i]


if __name__ == "__main__":
	casenum = int(raw_input())

	for num in xrange(1, casenum+1):
		# n l u v l u v l u v
		inp = raw_input().split()
		length = int(inp.pop(0))
		arr = [0] * length
		assert len(inp) % 3 == 0
		assert length == len(inp) / 3
		luv = [(int(inp[i]), int(inp[i+1]), float(inp[i+2])) for i in xrange(0, len(inp), 3)]
		addv(arr, luv)

		print "Case #%d:" % num,
		print arr
