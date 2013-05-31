class X(object):
	def __init__(self, bit):
		self.bit = bit
		self.length = len(bit)

def bsort(x, l, u, depth):
	if l >= u:
		# 範囲が0なら終わり
		return
	
	for i in xrange(l, u+1):
		# 範囲内で長さがdepthより短いものは左へ
		if x[i].length < depth:
			swap(i, l)
			l += 1
	m = l
	for i in xrange(l, u+1):
		if x[i].bit[depth] == 0
			# depth bitが0なら左へ。depthがより小さい物に関してはすでに整列されているはず
			swap(i, m)
			m += 1
	bsort(x, l, m-1, depth+1)
	bsort(x, m+1, u, depth+1)

