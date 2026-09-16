gen = input()

result = ""
count = 1

for i in range(1, len(gen)):
    if gen[i] == gen[i-1]:
        count += 1
    else:
        result += gen[i-1] + str(count)
        count = 1
result += gen[-1] + str(count)
print(result)