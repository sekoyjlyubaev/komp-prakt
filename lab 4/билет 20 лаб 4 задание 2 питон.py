import numpy as np

# Define the coefficients of the system of linear equations
A = np.array([[7, -3, 2], [1, -8, 1], [6, -6, 2]])
b = np.array([1, 1, -1])

# Solve the system of linear equations using the Gauss method
x = np.linalg.solve(A, b)

print("Solution:", x)