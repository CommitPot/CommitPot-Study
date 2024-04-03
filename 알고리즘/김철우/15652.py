v = [0 for i in range(8)]
def dfs(index):
    global v
    if index == m:
        for i in range(m):
            print(v[i], end=' ')
        print()
        return
    for i in range(1,n+1):
        v[index] = i
        dfs(index + 1)
        v[index] = 0

n,m = map(int,input().split(' '))
dfs(0)
