import numpy as np

# Define the coefficients of the system of linear equations
A = np.array([[-6, 6, 0, 0, 0], [2, 10, -7, 0, 0], [0, -8, 18, 9, 0], [0, 0, 6, -17, -6], [0, 0, 0, 14, -14]])
b = np.array([-30, -31, -108, -114, 124])

# Solve the system of linear equations using the Gauss method
x = np.linalg.solve(A, b)

print("Solution:", x)