# Division of Two Unsigned Integer Binary Numbers
# Non-Restoring Division Algorithm

from binary_subtraction import binary_adder, twos_complement


def non_restoring_division(Q, M):
    count = len(Q)  # no of bits in dividend Q
    M = M.zfill(count + 1)
    M_comp = twos_complement(M)
    # initialize accumulator with zero
    A = "0" * len(M)

    for i in range(count):
        sign_bit = A[0]  # check sign of A
        # Left shift A, Q
        A = A[1:] + Q[0]
        Q = Q[1:]  # one bit is less, which is empty
        if sign_bit == "1":
            # A <- A + M
            A = binary_adder(A, M)
        else:
            # A <- A - M
            A = binary_adder(A, M_comp)

        Q += "0" if A[0] == "1" else "1"

    if A[0] == "1":  # if A is negative
        A = binary_adder(A, M)
    return (Q, A)


if __name__ == "__main__":
    Q = input("Enter dividend: ")
    M = input("Enter divisor: ")
    if int(Q) < int(M):
        quotient, remainder = "0" * len(Q), Q
    else:
        quotient, remainder = non_restoring_division(Q, M)
    print(f"Quotient = {quotient}, Remainder = {remainder}")
