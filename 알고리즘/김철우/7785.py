A = int(input())
dic = {}
fltmxm = []
for i in range(A):
    a, b = input().split(' ')
    if b in 'enter':
        dic[a] = '1'
    elif b in 'leave':
        dic[a] = '0'
for i in dic:
    if dic[i] in '1':
        fltmxm.append(i)
fltmxm.sort(reverse=True)
fltmxm = '\n'.join(fltmxm)
print(fltmxm)
