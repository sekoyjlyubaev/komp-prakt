import numpy as np

def construct_spline(nodes):
    n = len(nodes)
    coefficients = []

    for i in range(n - 1):
        x0, y0 = nodes[i]
        x1, y1 = nodes[i + 1]

        a = (y1 - y0) / (x1 - x0)
        b = y0
        c = 3 * (y1 - y0) / (x1 - x0)
        d = -2 * (y0 - y1) / (x1 - x0)

        coefficients.append([a, b, c, d])

    return np.array(coefficients)

def evaluate_spline(coefficients, x):
    n = len(coefficients)
    result = 0

    for i in range(n):
        h = x - coefficients[i][0]
        result += coefficients[i][3] * h ** 3 + coefficients[i][2] * h ** 2 + coefficients[i][1] * h + coefficients[i][0]

    return result

# Define the nodes of interpolation
nodes = [(0.0, 0.0), (1.0, 2.0), (3.0, 4.0)]

# Construct the cubic spline
coefficients = construct_spline(nodes)

# Evaluate the cubic spline at a given point
x* = 1.5
y* = evaluate_spline(coefficients, x*)

print("Value of the cubic spline at x*", x*, ":", y*)