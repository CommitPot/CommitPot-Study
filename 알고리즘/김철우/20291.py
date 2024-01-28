from collections import  defaultdict
A = int(input())
dic = defaultdict(int)
for i in range(A):
    a,b = map(str,input().split('.'))
    dic[b] += 1
sorted_dic = sorted(dic)
for i in sorted_dic:
    print(i,dic[i])
