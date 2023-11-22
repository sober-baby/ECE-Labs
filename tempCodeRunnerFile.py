def symmetric(st):
    f = st[:len(st)//2]
    s = st[(len(st) - len(st)//2):]
    s = stringwise(list(s).reverse())
    print(st,f,s)
    return f == s

def stringwise(l):
    s = ''
    for i in l:
        s += str(i)
    return s

if __name__ == '__main__':
    digit = 2
    palin = []
    for i in range(10**(digit-1),10**digit-1):
        for j in range(10**(digit-1),10**digit-1):
            if symmetric(str(i*j)):
                palin.append(i*j)
    print(max(palin))
    