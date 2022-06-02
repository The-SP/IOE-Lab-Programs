# Mid-Point Circle Drawing Algorithm
from matplotlib import pyplot as plt


def circle(a, b, r):
    x, y = 0, r

    x_coordinates = [x + a, -x + a, x + a, -x + a, y + a, -y + a, y + a, -y + a]
    y_coordinates = [y + b, y + b, -y + b, -y + b, x + b, x + b, -x + b, -x + b]

    # Initial value of decision parameter
    p = 1 - r

    while x <= y:
        x = x + 1
        if p < 0:
            p += 2 * x + 1
        else:
            p += 2 * (x - y) + 1
            y = y - 1

        x_coordinates += [x + a, -x + a, x + a, -x + a, y + a, -y + a, y + a, -y + a]
        y_coordinates += [y + b, y + b, -y + b, -y + b, x + b, x + b, -x + b, -x + b]

    # Print coordinate values
    for i in range(len(x_coordinates)):
        if i % 8 == 0:
            print("")
        print("(", x_coordinates[i], y_coordinates[i], ")")

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
    fig, ax = plt.subplots()
    ax.xaxis.tick_top()
    ax.invert_yaxis()

    # square plot
    ax.set_aspect("equal", adjustable="box")
    circle(100, 100, 75)
