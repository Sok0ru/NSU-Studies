num_1 = float(input())
num_2 = float(input())
operator = input()
if operator == "+":
    print(num_1 + num_2)
elif operator == "-":
    print(num_1 - num_2)
elif operator == "*":
    print(num_1 * num_2)
elif operator == "/":
    if num_2 == 0:
        print("Деление на ноль!")
    else: print(num_1 / num_2)
elif operator == "mod":
    if num_2 == 0:
        print("Деление на ноль!")
    else: print(num_1 % num_2)
elif operator == "pow":
    print(num_1 ** num_2)
elif operator == "div":
    if num_2 == 0:
        print("Деление на ноль!")
    else: print(num_1 // num_2)
