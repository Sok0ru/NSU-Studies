

def bank_check(income, delays, sum_delays):
    if income <= 30000:
        return False
    elif delays == 0:
        if sum_delays > 10000:
            return False
    return True
pass

income = int(input())
delays = int(input())
sum_delays = int(input())

if bank_check(income, delays, sum_delays):
    print("Дать кредит")
else: print("Отказано")
