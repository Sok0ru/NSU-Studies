def leap_year(year):
    return year % 4 == 0 and year % 100 != 0 or year % 400 == 0

year = int(input())
if not leap_year(year):
    print("Обычный")
else: print("Високосный")