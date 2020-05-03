def main():
    number = input("Number: ")
    num_digits = len(number)
    check_sum = get_sum(number)
    starting_digits = int(number[:2])
    if not check_sum:
        print("INVALID")
    card_type = check_card(num_digits, starting_digits)
    print(card_type)

def get_sum(number):
    number = int(number)
    count = 0
    sum1 = 0
    sum2 = 0
    while number > 0:
        r = number % 10
        number = number // 10
        if count % 2 == 0:
            sum1 += r
        else:
            r *= 2
            while r > 0:
                digit = r % 10
                r = r // 10
                sum2 += digit
        count += 1
    return True if (sum1 + sum2) % 10 == 0 else False

def checkVisa(n, s):
    if n == 13 or n == 16 and s > 39 and s < 50:
        return True
    return False

def checkAmex( n,  s):
    if n == 15 and s == 34 or s == 37:
        return True
    return False

def checkMaster(n, s):
    if n == 16 and s > 50 and s < 56:
        return True
    return False



def check_card(length, start):
    if checkVisa(length,start):
        return "VISA"
    elif checkAmex(length,start):
        return "AMEX"
    elif checkMaster(length,start):
        return "MASTERCARD"
    else:
        return "INVALID"

main()