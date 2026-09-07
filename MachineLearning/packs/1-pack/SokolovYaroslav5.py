passenger_class = int(input())
gender = input()
age = int(input())


def chance_die(passenger_class, gender, age):
    if passenger_class == 1:
        return True
    elif passenger_class == 2:
        if gender == "м" and  age > 9 :
            return True
    elif passenger_class == 3:
        if gender == "м" or (gender == "ж" and age > 24):
            return True
    return False

print("Не выжил" if chance_die(passenger_class, gender, age) else "Выжил" )
