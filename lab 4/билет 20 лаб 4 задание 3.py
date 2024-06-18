import numpy as np

# Define the coefficients of the system of linear equations
A = np.array([[10, -1, -2, 5], [4, 28, 7, 9], [6, 5, -23, 4], [1, 4, 5, -15]])
b = np.array([-99, 0, 67, 58])

# Solve the system of linear equations using the Gauss method
x = np.linalg.solve(A, b)

print("Solution:", x)