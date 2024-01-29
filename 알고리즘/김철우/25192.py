from collections import  defaultdict
A = int(input())
dic = defaultdict(int)
cnt = 0
for i in range(A):
    b = input()
    if b == "ENTER":
        dic = defaultdict(int)
    if b != "ENTER":
        if dic[b] != 1:
            cnt += 1
            dic[b] = 1
print(cnt)
