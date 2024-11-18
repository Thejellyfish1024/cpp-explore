#include <stdio.h>

void dividedDifferenceTable(int n, double x[], double y[][n])
{
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            y[i][j] = (y[i + 1][j - 1] - y[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}
double newtonInterpolation(int n, double x[], double y[][n], double value)
{
    double result = y[0][0];
    double product = 1.0;
    for (int i = 1; i < n; i++)
    {
        product *= (value - x[i - 1]);
        result += product * y[0][i];
    }
    return result;
}

int main()
{

    int n = 17; 
    double x[] = {2, 2.3, 2.4, 2.45, 3, 3.32, 3.81, 4, -1, -4.23, 5.5, 6.1, 7.1, 7.15, 7.88, 9, 9.5};
    double y[17][17] = {
        {788}, {2377.663558}, {3333.907425}, {3927.896301}, {19741}, {44359.05585}, {133319.7762}, {196740}, {5}, {307351.9701}, {2512354.887}, {5751677.352}, {19373325.76}, {20492038.71}, {44600585.79}, {129141625}, {199027848.1}};

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            y[i][j] = 0.0;
        }
    }

    dividedDifferenceTable(n, x, y);

    printf("Divided Difference Table:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nline %d ==> %lf\t", i + 1, x[i]);
        for (int j = 0; j < n - i; j++)
        {
            printf("%lf\t", y[i][j]);
        }
        printf("\n");
    }

    double value = 12;
    double result = newtonInterpolation(n, x, y, value);

    printf("\nThe interpolated value at x = %.2f is %.6lf\n", value, result);

    return 0;
}
