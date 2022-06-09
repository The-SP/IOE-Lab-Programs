# Mid-Point Ellipse Algorithm
from matplotlib import pyplot as plt


def ellipse(a, b, rx, ry):
    x, y = 0, ry

    x_coordinates = [x + a, -x + a, x + a, -x + a]
    y_coordinates = [y + b, y + b, -y + b, -y + b]

    # Initial decision parameter in region 1
    p = ry**2 - rx**2 * ry + 1 / 4 * rx**2

    while (2 * ry**2 * x) < (2 * rx**2 * y):
        x = x + 1
        if p < 0:
            p += 2 * ry**2 * x + ry**2
        else:
            p += 2 * ry**2 * x - 2 * rx**2 * y + ry**2
            y = y - 1

        x_coordinates += [x + a, -x + a, x + a, -x + a]
        y_coordinates += [y + b, y + b, -y + b, -y + b]

    # Initial decision parameter in region 2
    p = ry**2 * (x + 1 / 2) ** 2 + rx**2 * (y - 1) ** 2 - (rx * ry) ** 2

    while y >= 0:
        y = y - 1
        if p > 0:
            p += -2 * rx**2 * y + rx**2
        else:
            p += 2 * ry**2 * x - 2 * rx**2 * y + rx**2
            x = x + 1

        x_coordinates += [x + a, -x + a, x + a, -x + a]
        y_coordinates += [y + b, y + b, -y + b, -y + b]

    # Print coordinate values
    for i in range(len(x_coordinates)):
        if i % 4 == 0:
            print()
        print(f"({x_coordinates[i]}, \t{y_coordinates[i]})")

    # Plot the line with coordinates list
    plt.plot(
        x_coordinates,
        y_coordinates,
        marker="o",
        linestyle="none",
        markersize=1,
        markerfacecolor="red",
    )
    plt.show()


if __name__ == "__main__":
    ellipse(0, 0, 100, 80)
