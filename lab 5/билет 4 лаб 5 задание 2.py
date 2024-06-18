import numpy as np

def construct_polynomial(nodes):
    n = len(nodes)
    coefficients = []

    for i in range(n):
        x0, y0 = nodes[i]

        # Calculate the coefficients of the Newton polynomial
        coefficient = [y0]

        for j in range(1, i + 1):
            coefficient.append((coefficient[-1] * (x0 - j * np.pi / 4)) / (j * np.pi / 4))

        coefficients.append(coefficient)

    return np.array(coefficients)

def evaluate_polynomial(coefficients, x):
    n = len(coefficients)
    result = coefficients[0][0]

    for i in range(1, n):
        product = 1
        for j in range(i):
            product *= (x - j * np.pi / 4)
        result += product * coefficients[i][i]

    return result

# Define the nodes of interpolation
nodes = [(np.pi / 10, np.cos(np.pi / 10)), (np.pi / 5, np.cos(np.pi / 5)), (3 * np.pi / 10, np.cos(3 * np.pi / 10)), (2 * np.pi / 5, np.cos(2 * np.pi / 5))]

# Construct the Newton polynomial
coefficients = construct_polynomial(nodes)

# Evaluate the Newton polynomial at a given point
x* = np.pi / 4
y* = evaluate_polynomial(coefficients, x*)

print("Value of the Newton polynomial at x*", x*, ":", y*)

# Calculate the error of interpolation
error = abs(y* - np.cos(x*))
print("Error of interpolation: ", error)