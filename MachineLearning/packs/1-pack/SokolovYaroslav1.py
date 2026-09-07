ticket = input()
first_num = ticket[0:3]
second_num = ticket[3:6]

first_num_sum = sum(map(int, first_num))
second_num_sum = sum(map(int, second_num))
check_sum = first_num_sum == second_num_sum
if check_sum:
    print("Счастливый")
else:
    print("Обычный")