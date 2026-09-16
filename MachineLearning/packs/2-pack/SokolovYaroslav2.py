nums = list(map(int, input().split()))
shift = input()
count = int(input())
count = -count if shift == "R" else count
result = nums[count:] + nums[:count]
print(result)