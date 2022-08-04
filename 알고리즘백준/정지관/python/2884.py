a, b = map(int, input().split(' '))

if(b - 45 >= 0): print(a, b-45)
else: 
    if(a-1 < 0): print(23, 15 + b)
    else: print(a-1, 15 + b )