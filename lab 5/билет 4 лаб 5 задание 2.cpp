#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to construct a Newton polynomial
void constructPolynomial(const vector<pair<double, double>>& nodes, vector<vector<double>>& coefficients) {
    int n = nodes.size();
    coefficients.resize(n);

    for (int i = 0; i < n; ++i) {
        double x0 = nodes[i].first;
        double y0 = nodes[i].second;

        // Calculate the coefficients of the Newton polynomial
        coefficients[i].resize(n - i);
        coefficients[i][0] = y0;

        for (int j = 1; j <= i; ++j) {
            coefficients[i][j] = (coefficients[i][j - 1] * (x0 - j * M_PI / 4)) / (j * M_PI / 4);
        }
    }
}

// Function to evaluate the Newton polynomial at a given point
double evaluatePolynomial(const vector<vector<double>>& coefficients, double x) {
    int n = coefficients.size();
    double result = coefficients[0][0];

    for (int i = 1; i < n; ++i) {
        double product = 1;
        for (int j = 0; j < i; ++j) {
            product *= (x - j * M_PI / 4);
        }
        result += product * coefficients[i][i];
    }

    return result;
}

int main() {
    // Define the nodes of interpolation
    vector<pair<double, double>> nodes = {{M_PI / 10, cos(M_PI / 10)}, {M_PI / 5, cos(M_PI / 5)}, {3 * M_PI / 10, cos(3 * M_PI / 10)}, {2 * M_PI / 5, cos(2 * M_PI / 5)}};

    // Construct the Newton polynomial
    vector<vector<double>> coefficients;
    constructPolynomial(nodes, coefficients);

    // Evaluate the Newton polynomial at a given point
    double x* = M_PI / 4;
    double y* = evaluatePolynomial(coefficients, x*);

    cout << "Value of the Newton polynomial at x*" << x* << ": " << y* << endl;

    // Calculate the error of interpolation
    double error = fabs(y* - cos(x*));
    cout << "Error of interpolation: " << error << endl;

    return 0;
}
