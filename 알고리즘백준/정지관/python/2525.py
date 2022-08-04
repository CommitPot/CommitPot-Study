a, b = map(int, input().split(' '))
c = int(input())
allMinutes = a*60 + b + c
hour = allMinutes // 60
minute = allMinutes % 60

if(hour >= 24): hour -= 24

print(hour, minute)