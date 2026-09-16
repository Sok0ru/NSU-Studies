rows = int(input())

matrix = []
nums = []

for row in range(rows):
    column = list(map(int, input().split()))
    matrix.append(column)
    if row < rows / 2:
        nums.extend(column[:row + 1])
        nums.extend(column[-row - 1:])
    else:
        nums.extend(column[:rows - row])
        nums.extend(column[-(rows - row):])
print(max(nums))