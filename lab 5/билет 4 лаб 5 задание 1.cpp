#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Function to construct a cubic spline
void constructSpline(const vector<pair<double, double>>& nodes, vector<vector<double>>& coefficients) {
    int n = nodes.size();
    coefficients.resize(n - 1);

    for (int i = 0; i < n - 1; ++i) {
        // Calculate the coefficients of the cubic polynomial for each segment
        double x0 = nodes[i].first;
        double y0 = nodes[i].second;
        double x1 = nodes[i + 1].first;
        double y1 = nodes[i + 1].second;

        // Calculate the coefficients of the cubic polynomial
        double a = (y1 - y0) / (x1 - x0);
        double b = y0;
        double c = 3 * (y1 - y0) / (x1 - x0);
        double d = -2 * (y0 - y1) / (x1 - x0);

        // Store the coefficients in the vector
        coefficients[i].resize(4);
        coefficients[i][0] = a;
        coefficients[i][1] = b;
        coefficients[i][2] = c;
        coefficients[i][3] = d;
    }
}

// Function to evaluate the cubic spline at a given point
double evaluateSpline(const vector<vector<double>>& coefficients, double x) {
    int n = coefficients.size();
    double result = 0;

    for (int i = 0; i < n; ++i) {
        double h = x - coefficients[i][0];
        result += coefficients[i][3] * h * h * h + coefficients[i][2] * h * h + coefficients[i][1] * h + coefficients[i][0];
    }

    return result;
}

int main() {
    // Define the nodes of interpolation
    vector<pair<double, double>> nodes = {{0.0, 0.0}, {1.0, 2.0}, {3.0, 4.0}};

    // Construct the cubic spline
    vector<vector<double>> coefficients;
    constructSpline(nodes, coefficients);

    // Evaluate the cubic spline at a given point
    double x* = 1.5;
    double y* = evaluateSpline(coefficients, x*);

    cout << "Value of the cubic spline at x*" << x* << ": " << y* << endl;

    return 0;
}