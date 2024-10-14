#include <stdio.h>
#include <math.h>

int main() {
    double x = 27;  // Example number

    // Calculate cube root (3rd root)
    double cube_root = pow(x, 1.0/3.0);

    // Calculate fourth root (4th root)
    double fourth_root = pow(x, 1.0/4.0);

    printf("Cube root of %.2f is %.2f\n", x, cube_root);
    printf("Fourth root of %.2f is %.2f\n", x, fourth_root);

    return 0;
}