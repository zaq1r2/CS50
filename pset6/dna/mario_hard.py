def main():
    height = int(get_height())
    mario(height,0)

def get_height():
    while True:
        height = input("How high?")
        if height.isdigit() and int(height) > 0 and int(height) < 9:
            return height


def mario(height,spaces):
    if height == 0:
        return
    
    mario(height - 1, spaces + 1)

    print(" " * spaces, end ="")
    print("#" * height, end = "")
    print(" " * 2, end = "")
    print("#" * height)

main()