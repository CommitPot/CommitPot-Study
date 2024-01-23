array = []
for i in range(1, 6):
    a = input()
    if "FBI" in a:
        array.append(i)
if array:
    print(*array)
else:
    print("HE GOT AWAY!")
