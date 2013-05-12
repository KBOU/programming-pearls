# coding: utf-8

import random

def create_array(num):
	arr = []
	for i in range(0, num):
		arr.append(i)
	return arr

if __name__ == "__main__":
	arr = create_array(10000000)

	random.shuffle(arr)

	for e in arr:
		print e
