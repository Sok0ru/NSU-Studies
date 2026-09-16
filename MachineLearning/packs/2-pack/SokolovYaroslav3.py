correct_nums = input().split()
classic_nums = input().split()

count = 0

for (i, num) in enumerate(correct_nums):
    if num == classic_nums[i]: count += 1

print(count / len(correct_nums))
