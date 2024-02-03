A = int(input())
N = []
for i in range(A):
    n = input()
    N.append(n)
sset = set(N)
N = list(sset)
N.sort(key= lambda x: (len(x), x))
print("\n".join(N))
