def main():
    change = float(get_change()) * 100
    coins = make_change(change)
    print(coins)

def get_change():
    while True:
        change = input("How much?")
        if is_float(change) and float(change) > 0:
            return change


def make_change(change):
    count = 0
    while change > 0:
        if change >= 25:
            count += 1
            change -= 25
        elif change >= 10:
            count += 1
            change -= 10
        elif change >= 5:
            count += 1
            change -= 5
        else:
            change -= 1
            count += 1
    return count 

def is_float(value):
    try:
        float(value)
        return True
    except ValueError:
        return False

main()