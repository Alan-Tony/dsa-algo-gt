import matplotlib.pyplot as plt

if __name__ == "__main__":

    ifile= open("points.txt", "r")
    lines1 = ifile.readlines()
    ifile.close()

    X_points = []
    Y_points = []
    for line in lines1:

        nums= line.split()
        X_points.append(float(nums[0]))
        Y_points.append(float(nums[1]))

    ifile = open("hull.txt", "r")
    lines2 = ifile.readlines()
    ifile.close()

    X_hull = []
    Y_hull = []
    for line in lines2:

        nums= line.split()
        X_hull.append(float(nums[0]))
        Y_hull.append(float(nums[1]))
    X_hull.append(X_hull[0])
    Y_hull.append(Y_hull[0])

    print(X_points)
    print(Y_points)
    print(X_hull)
    print(Y_hull)

    plt.plot(X_points, Y_points, "bo")
    plt.plot(X_hull, Y_hull, "go")
    plt.plot(X_hull, Y_hull, "r-")
    plt.show()

