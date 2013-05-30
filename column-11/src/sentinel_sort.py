def swap(x, i, j):
	t = x[i]
	x[i] = x[j]
	x[j] = t

def qsort1(x, l, u):
	if l >= u:
		return
	m = 1
	for i in xrange(l+1, u+1):
		if x[i] < x[l]:
			swap(x, ++m, i)
	swap(x, l, m)
	qsort1(l, m-1)
	qsort1(m+1, u)

def qsort2(x, l, u):
	if l >= u:
		return
	m = u
	i = u
	while x[i] < t:
		i -= 1
	m -= 1
	while i != 1:
		while x[i] < t:
			i -= 1
		m -= 1
	swap(x, m, i)
	qsort2(l, m-1)
	qsort2(m+1, u)

