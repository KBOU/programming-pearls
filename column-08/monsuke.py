# -*- coding: utf-8 -*-


def solve_slow(ns):
	max_ = []
	for i in xrange(len(ns)):
		for j in xrange(i, len(ns)):
			if sum(max_) < sum(ns[i:j + 1]):
				max_ = ns[i:j + 1]
			elif sum(max_) == sum(ns[i: j + 1]) and len(max_) < j - i + 1:
				max_ = ns[i:j + 1]
	return max_


def solve1(ns):
	"""
		>>> solve1([31, -41, 59, 26, -53, 58, 97, -93, -23, 84])
		[59, 26, -53, 58, 97]
		>>> solve1([436, -768, 753])
		[753]
		>>> solve1([476, -767])
		[476]
		>>> solve1([60])
   		[60]
		>>> solve1([-10, 0, 60, 0, -10])
		[0, 60, 0]
	"""

	assert 0 < len(ns)

	max_ = (-1, None, None)

	start = end = None
	total = 0
	for i, n in enumerate(ns):	# O(n)
		if 0 <= n:
			if start is None:
				assert end is None
				start = end = i
				total = 0
			else:
				end = i
		else:
			if start is not None:
				assert end is not None
				if max_[0] < sum(ns[start:end + 1]):
					max_ = (total, start, end)
			if total + n < 0:
				start = end = None
				total = 0
			else:
				end = i
		total += n
	if start is not None:
		assert end is not None
		if max_[0] < sum(ns[start:end + 1]):
			max_ = (total, start, end)

	if max_[1] is None:
		return []
	return ns[max_[1]:max_[2] + 1]


def solve2(ns):
	"""
		>>> solve2([31, -41, 59, 26, -53, 58, 97, -93, -23, 84])
		[59, 26, -53, 58, 97]
		>>> solve2([436, -768, 753])
		[753]
		>>> solve2([476, -767])
		[476]
		>>> solve2([60])
		[60]
		>>> solve2([-10, 0, 60, 0, -10])
		[0, 60, 0]
		>>> solve2([-5, -20])
		[]
	"""

	assert 0 < len(ns)

	candidates = []
	low = up = total = 0
	low_id = up_id = 0
	i = 0
	while i < len(ns):
		n = ns[i]
		if n < 0:
			if total + n < low:
				# 最低記録更新
				candidates.append(((low_id, up_id), (low, up)))
				while i < len(ns) and ns[i] < 0:
					i += 1
					total += n
				if len(ns) <= i:
					break
				low_id = up_id = i
				low = up = total
				continue
		else:
			if up <= total + n:
				up = total + n
				up_id = i
		i += 1
		total += n
	candidates.append(((low_id, up_id), (low, up)))

	max_ = None # (value, start_index, end_index)
	for (low_id, up_id), (low, up) in candidates:
		if max_ is None or max_[0] < up - low:
			max_ = (up - low, low_id, up_id)
	if max_[0] <= 0:
		return []
	return ns[max_[1]:max_[2] + 1]

if __name__ == '__main__':
	import doctest
	doctest.testmod()

	import random
	import time
	for i in xrange(1000):
		a = [
			random.randint(-1000, 1000)
			for j in xrange(random.randint(1, 100))
		]
		if solve_slow(a) != solve2(a):
			print a, solve_slow(a), solve2(a)

	a = [random.randint(-1000, 1000) for j in xrange(10000)]
	TC = 1000
	for N in (10, 20, 30, 100, 200, 300, 1000):
		ttt = 0
		for i in xrange(TC):
			_S = time.time()
			solve2(a[:N])
			_E = time.time()
			ttt += _E - _S
		print '{} => {:.3f} [sec]'.format(N, ttt)

"""
solve_slow TC=1000
10 => 0.067 [sec]
20 => 0.275 [sec]
30 => 0.631 [sec]
100 => 10.011 [sec]

solve1 TC=1000
10 => 0.008 [sec]
20 => 0.016 [sec]
30 => 0.025 [sec]
100 => 0.070 [sec]
200 => 0.146 [sec]
300 => 0.251 [sec]
1000 => 1.328 [sec]

solve2 TC=1000
10 => 0.008 [sec]
20 => 0.011 [sec]
30 => 0.014 [sec]
100 => 0.040 [sec]
200 => 0.071 [sec]
300 => 0.111 [sec]
1000 => 0.355 [sec]
"""
