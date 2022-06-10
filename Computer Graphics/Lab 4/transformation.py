# 2D Transformation
# Scale triangle by double with its centroid fixed
# Rotate triangle by angle with its first vertex fixed
from matplotlib import pyplot as plt
from math import sin, cos, radians

# Draw polygon
def draw(x, y):
    plt.plot(x + [x[0]], y + [y[0]])


def matrix_multiply(a, b):
    product = [[0 for i in range(len(b[0]))] for j in range(len(a))]
    for i in range(len(a)):
        for j in range(len(b[0])):
            for k in range(len(b)):
                product[i][j] += a[i][k] * b[k][j]
    return product


# Transform Co-ordinates
def transform(x, y, matrix):
    for i in range(len(x)):
        point = [[x[i]], [y[i]], [1]]
        new_point = matrix_multiply(matrix, point)
        x[i], y[i] = new_point[0][0], new_point[1][0]


def scale(x, y, sx, sy):
    # Fixed point for transformation
    xf, yf = 0, 0
    # Taking centroid as fixed point
    for i in range(len(x)):
        xf += x[i]
        yf += y[i]
    xf = int(xf / 3)
    yf = int(yf / 3)

    # Composite Transformation Matrix
    a = [[1, 0, xf], [0, 1, yf], [0, 0, 1]]
    b = [[sx, 0, 0], [0, sy, 0], [0, 0, 1]]
    c = [[1, 0, -xf], [0, 1, -yf], [0, 0, 1]]
    matrix = matrix_multiply(a, b)
    matrix = matrix_multiply(matrix, c)

    # Transform co-ordinates
    transform(x, y, matrix)


def rotate(x, y, angle):
    # Fixed point for transformation
    xr, yr = x[0], y[0]  # one of the vertices

    # Composite Transformation Matrix
    a = [[1, 0, xr], [0, 1, yr], [0, 0, 1]]
    b = [[cos(angle), -sin(angle), 0], [sin(angle), cos(angle), 0], [0, 0, 1]]
    c = [[1, 0, -xr], [0, 1, -yr], [0, 0, 1]]
    matrix = matrix_multiply(a, b)
    matrix = matrix_multiply(matrix, c)

    # Transform co-ordinates
    transform(x, y, matrix)


if __name__ == "__main__":
    x = [2, 10, 21]
    y = [4, 11, 6]
    draw(x, y)
    # Scale triangle by double with its centroid fixed
    scale(x, y, 2, 2)
    draw(x, y)
    # Rotate triangle by angle with its first vertex fixed
    rotate(x, y, radians(60))
    draw(x, y)
    plt.show()
