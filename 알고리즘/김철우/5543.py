burger = []
for _ in range(3):
    burger.append(int(input()))
    
drink = []
for _ in range(2):
    drink.append(int(input()))

min_set = min(burger) + min(drink) - 50
print(min_set)
