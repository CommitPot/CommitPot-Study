a,b,c = map(int, input().split(' '))

if(a==b==c): print(10000 + 1000*a)
elif(a == b): print(1000 + 100*a)
elif(c == b): print(1000 + 100*b)
elif(a == c): print(1000 + 100*a)
else: print(100 * ((a if a>c else c) if a>b else (b if b>c else c)))