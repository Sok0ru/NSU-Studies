n = int(input())

results = []

for _ in range(n):
    row = list(map(int, input().split()))
    avg = sum(row) / len(row)

    results.append(sum(1 for x in row if x > avg))

for count in results:
    print(count)