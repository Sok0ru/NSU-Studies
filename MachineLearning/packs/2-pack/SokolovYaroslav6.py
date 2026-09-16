rows = int(input())

matrix = []

for row in range(rows):
    column = list(map(int, input().split()))
    matrix.append(column)

def check_matrix(matrix):
    for row in range(len(matrix)):
        for column in range(len(matrix)):
            if matrix[row][column] != matrix[column][row]:
                return False
    return True

if check_matrix(matrix):
    print("YES")
else:
    print("NO")
