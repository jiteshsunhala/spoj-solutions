while 2 > 1:
    string = raw_input()
    n, d = string.split()
    n = int(n)
    d = int(d)
    if(n == 0 and d == 0):
        break
    print(n ** d)
