# Signed Multiplication (2's Complement Multiplication)
# Booth Algorithm

from binary_addition import binary_adder
from binary_subtraction import twos_complement


def booth(M, Q):
    # Multiplicand M
    M = "0" + M
    M_comp = twos_complement(M)

    # Multiplier Q (signed)
    Q = Q.zfill(len(M))
    Q = twos_complement(Q)
    Q_1 = "0"
    # initialize accumulator with zero
    A = "0" * len(M)

    count = len(M)
    for i in range(count):
        deciding_bits = Q[-1] + Q_1
        if deciding_bits == "10":
            A, carry = binary_adder(A, M_comp)
        elif deciding_bits == "01":
            A, carry = binary_adder(A, M)
        # Arithmentic Shift Right (ASR A, Q, Q_-1)
        Q_1 = Q[-1]
        Q = A[-1] + Q[:-1]
        A = A[0] + A[:-1]

    return A + Q


if __name__ == "__main__":
    M = input("Enter multiplicand: ")
    # Note: this program assumes the multiplier is signed i.e if i/p is "11"(3) it is considered as "11101"(-3)
    Q = input("Enter signed multiplier: ")
    product = booth(M, Q)
    print(f"Product = {product}")
