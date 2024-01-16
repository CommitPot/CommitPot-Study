t=int(input())

if t % 10 !=0:
    print(-1)
else:
    a,b,c=0,0,0
    a=t//300
    b=(t % 300) // 60
    c=(t % 60) // 10
    print(a,b,c)
