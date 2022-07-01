# Signed Multiplication (2's Complement Multiplication)
# Booth Algorithm

from binary_subtraction import binary_adder, twos_complement


def booth(M, Q):
    count = max(len(M), len(Q))
    M = M.zfill(count)
    Q = Q.zfill(count)

    M_comp = twos_complement(M)                                                                                            
    Q_1 = "0"
    # initialize accumulator with zero
    A = "0" * count

    for i in range(count):
        deciding_bits = Q[-1] + Q_1
        if deciding_bits == "10":
            A = binary_adder(A, M_comp)
        elif deciding_bits == "01":
            A = binary_adder(A, M)
        # Arithmentic Shift Right (ASR A, Q, Q_-1)
        Q_1 = Q[-1]
        Q = A[-1] + Q[:-1]
        A = A[0] + A[:-1]

    return A + Q


if __name__ == "__main__":
    M = input("Enter multiplicand: ")
    Q = input("Enter multiplier: ")
    product = booth(M, Q)
    print(f"Product = {product}")

# Note: In case of Booth's algorithm, an extra bit is always added to the binary numbers while giving input. 
# eg: 12 = (01100)