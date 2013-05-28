def swap(x, i, j):
	t = x[i]
	x[i] = x[j]
	x[j] = t

def isort(x):
	n = len(x)
	for i in xrange(1, n):
		t = x[i]
		for j in xrange(i, 0):
			if x[j-1] > t:
				x[j] = x[j-1]
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

def qsort3(x, l, u):
	if l >= u:
		return
	t = x[l]
	i = l
	j = u+1
	while True:
		i += 1
		while i <= u and x[i] < t:
			i += 1
		j -= 1
		while j >= l and x[j] > t:
			j -= 1
		if i > j:
			break
		swap(x, i, j)
	swap(x, l, j)
	qsort3(l, j-1)
	qsort3(j+1, u)

def qsort4(x, l, u):
	if u -l < cutoff:
		return
	swap(l, random.randint(l, u))
	t = x[l]
	i = l
	j = u + 1
	while True:
		i += 1
		while i <= u and x[i] < t:
			i += 1
		j -= 1
		while j >= l and x[j] > t:
			j -= 1
		if i > j:
			break
		swap(x, i, j)
	swap(x, l, j)
	qsort4(l, j-1)
	qsort4(j+1, u)
		
