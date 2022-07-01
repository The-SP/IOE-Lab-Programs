# Division of Two Unsigned Integer Binary Numbers
# Restoring Division Algorithm

from binary_subtraction import binary_adder, twos_complement


def restoring_division(Q, M):
    count = len(Q)  # no of bits in dividend Q
    if len(M) <= count:
        M = M.zfill(count + 1)
    M_comp = twos_complement(M)
    # initialize accumulator with zero
    A = "0" * len(M)

    for i in range(count):
        # Left shift A, Q
        A = A[1:] + Q[0]
        Q = Q[1:]  # one bit is less, which is empty

        # A <- A - M
        A = binary_adder(A, M_comp)

        if A[0] == "1":
            # Set Qo to 0
            Q = Q + "0"
            # A <- A + M (restore A)
            A = binary_adder(A, M)
        else:
            # Set Qo to 1
            Q = Q + "1"

    return (Q, A)


if __name__ == "__main__":
    Q = input("Enter dividend: ")
    M = input("Enter divisor: ")
    if int(Q) < int(M):
        quotient, remainder = "0" * len(Q), Q
    else:
        quotient, remainder = restoring_division(Q, M)
    print(f"Quotient = {quotient}, Remainder = {remainder}")
