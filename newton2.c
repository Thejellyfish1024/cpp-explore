#include <stdio.h>

// Function to build the divided difference table
void dividedDifferenceTable(int n, double x[], double y[][n]) {
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = (y[i+1][j-1] - y[i][j-1]) / (x[i+j] - x[i]);
        }
    }
}

// Function to apply Newton's Divided Difference formula
double newtonInterpolation(int n, double x[], double y[][n], double value) {
    double result = y[0][0];
    double product = 1.0;
    for (int i = 1; i < n; i++) {
        product *= (value - x[i-1]);
        result += product * y[0][i];
    }
    return result;
}

int main() {
    // Input values
    int n = 5;  // Number of data points
    double x[] = {1, 2, 5, 6, 7};
    double y[5][5] = {
        {-1, 0, 0, 0, 0},  // Initial y values in the first column
        {11, 0, 0, 0, 0},
        {95, 0, 0, 0, 0},
        {139, 0, 0, 0, 0},
        {191, 0, 0, 0, 0}
    };

    // Fill the divided difference table
    dividedDifferenceTable(n, x, y);

    // Print divided difference table (optional for verification)
    printf("Divided Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%lf\t", x[i]);
        for (int j = 0; j < n - i; j++) {
            printf("%lf\t", y[i][j]);
        }
        printf("\n");
    }

    // Interpolating for x = 3
    double value = 3;
    double result = newtonInterpolation(n, x, y, value);

    printf("\nThe interpolated value at x = %.2f is %.6lf\n", value, result);

    return 0;
}
