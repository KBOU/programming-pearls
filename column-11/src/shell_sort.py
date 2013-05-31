def shell_sort(x):
	# 8 3 1 2 7 5 6 4
	n = len(x)
	h = 1
	while h < n:
		# 1 4 13 40 121 ...
		h = 3*h + 1

	while True:
		h /= 3
		if h < 1:
			break
		for i in xrange(h, n):
			for j in xrange(i, h-1, h):
				if x[j-h] < x[j]:
					break
				swap(j-h, j)
