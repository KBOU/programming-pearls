# coding: utf8

def nearzero(arr, m):
	sum0 = 0
	for i in xrange(m):
		sum0 += arr[i]

	near0 = sum0
	for i in xrange(1, len(arr)-m):
		sum0 += (arr[i-1+m] - arr[i-1])
		if abs(near0) > abs(sum0):
			near0 = sum0
	return near0

if __name__ == "__main__":
	casenum = int(raw_input())

	for case in xrange(1, casenum+1):
		inp = raw_input().split()
		m = int(inp.pop(0))
		arr = map(float, inp)
		near0 = nearzero(arr, m)
		print "Case #%d: %lf" % (case, near0)
