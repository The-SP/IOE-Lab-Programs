# Multiplication of Two Unsigned Integer Binary Numbers By Patrial-Product Method

from binary_subtraction import binary_adder


def adjust_number(x, y):
    l1, l2 = len(x), len(y)
    # For n-bit multiplication, the result is 2n-bit
    max_bit = max(l1, l2)
    x = x.rjust(2 * max_bit, "0")
    y = y.rjust(2 * max_bit, "0")
    return (x, y)


def binary_multiplication(x, y, count):
    # partial product is initially started with zero
    sum = "0" * len(x)
    for i in range(count):
        # Test Yo, if it is 1 add content of X to the accumulator sum
        if y[-1] == "1":
            sum = binary_adder(sum, x)
        # Left shift X
        x = x[1:] + "0"
        # Right shift Y
        y = "0" + y[:-1]
    return sum


if __name__ == "__main__":
    x = input("Enter multiplicand: ")
    y = input("Enter multiplier: ")
    count = len(y)  # no of bits in y
    x, y = adjust_number(x, y)
    product = binary_multiplication(x, y, count)
    print(f"Product = {product}")
