  A, B = map(int, input().split())
dic = {}
for i in range(A):
    a, b = input().split(' ')
    dic[a] = b
for i in range(B):
    c = input()
    print(dic[c])
