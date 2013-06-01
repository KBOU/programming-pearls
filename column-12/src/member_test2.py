def member_test2(m, n):
    total = 0
    for i in xrange(1, n):
        total += i * (float(m)/n) ** i
    print total

if __name__ == "__main__":
    member_test2(15, 20)
