# coding: utf-8

def get_max(arr):
	maxsofar = 0
	maxendinghere = 0
	for el in arr:
		maxendinghere = max(maxendinghere + el, 0)
		maxsofar = max(maxsofar, maxendinghere)
	return maxsofar

if __name__ == "__main__":
	import random
	casenum = 1000
	sample = 100
	total = 0

	for n in xrange(1, casenum + 1):
		arr = []
		for i in xrange(0, sample):
			elem = random.random() * 2 - 1
			arr.append(elem)
		max_arr = get_max(arr)
		total += max_arr
		print "Case #%d: %lf" % (n, max_arr)
	print "Avg: %lf" % (total / casenum)


