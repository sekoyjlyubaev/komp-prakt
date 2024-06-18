#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Function to solve the system of linear equations using the matrix method
vector<double> solveMatrixMethod(const vector<vector<double>>& A, const vector<double>& b) {
    int n = A.size();
    vector<double> x(n);

    // Check if the matrix is singular
    if (det(A) == 0) {
        cout << "The matrix is singular, cannot solve." << endl;
        return x;
    }

    // Forward substitution
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < i; ++j) {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }

    // Back substitution
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0;
        for (int j = i + 1; j < n; ++j) {
            sum += A[i][j] * x[j];
        }
        x[i] = (x[i] - sum) / A[i][i];
    }

    return x;
}

// Function to calculate the determinant of a matrix
double det(const vector<vector<double>>& A) {
    int n = A.size();
    double det = 1;
    for (int i = 0; i < n; ++i) {
        det *= A[i][i];
    }
    return det;
}

int main() {
    // Define the coefficients of the system of linear equations
    vector<vector<double>> A = {{7, -3, 2}, {1, -8, 1}, {6, -6, 2}};
    vector<double> b = {1, 1, -1};

    // Solve the system of linear equations using the matrix method
    vector<double> x = solveMatrixMethod(A, b);

    cout << "Solution: ";
    for (double xi : x) {
        cout << xi << " ";
    }
    cout << endl;

    return 0;
}