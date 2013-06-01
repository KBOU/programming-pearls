def member_test(n):
    total = 0
    for i in xrange(1, n):
        total += i * 2 ** -i
    print total

if __name__ == "__main__":
    member_test(2000)
        
