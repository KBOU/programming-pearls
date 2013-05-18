def mk_testcase():
	import random
	t = random.randint(1, 1024)
	lng = random.choice(range(t, 1024))

	print t
	print lng,

	for i in xrange(0, lng):
		print i+1,
	print
		



def main():
	testcase_num = 100

	print testcase_num
	for i in xrange(0, testcase_num):
		mk_testcase()


if __name__ == "__main__":
	main()
