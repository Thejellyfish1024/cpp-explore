#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void addition();
void subtraction();
void multiplication();
void division();
void modulus();
void factorial();
void power();
void square();
void cube();
void squareroot();
void SIN();
void COS();
void TAN();
void SIN_INVERSE();
void COS_INVERSE();
void TAN_INVERSE();
void twoRootsLinearEquations();
void threeRootsLinearEquations();

int main()
{

    printf("\t !! Introducing Scientific Calculator !!\n\n");
    int choice;

    printf(" 0 : Exit \n");
    printf(" 1 : Addition \n");
    printf(" 2 : Subtraction \n");
    printf(" 3 : Multiplication \n");
    printf(" 4 : Division \n");
    printf(" 5 : Modulus\n");
    printf(" 6 : Power \n");
    printf(" 7 : Factorial \n");
    printf(" 8 : Square \n");
    printf(" 9 : Cube \n");
    printf(" 10 : Squareroot\n");
    printf(" 11 : Sin()\n");
    printf(" 12 : Cos()\n");
    printf(" 13 : Tan()\n");
    printf(" 14 : Arc_Sin()\n");
    printf(" 15 : Arc_Cos()\n");
    printf(" 16 : Arc_Tan()\n");
    printf(" 17 : Two Roots Linear Equations\n");
    printf(" 18 : Three Roots Linear Equations\n");

    while (1)
    {
        printf("\n Choose operator: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a valid integer.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice)
        {
        case 1:
            addition();
            break;

        case 2:
            subtraction();
            break;

        case 3:
            multiplication();
            break;

        case 4:
            division();
            break;

        case 5:
            modulus();
            break;

        case 6:
            power();
            break;

        case 7:
            factorial();
            break;

        case 8:
            square();
            break;

        case 9:
            cube();
            break;

        case 10:
            squareroot();
            break;

        case 11:
            SIN();
            break;

        case 12:
            COS();
            break;

        case 13:
            TAN();
            break;
        case 14:
            SIN_INVERSE();
            break;

        case 15:
            COS_INVERSE();
            break;

        case 16:
            TAN_INVERSE();
            break;
        case 17:
            twoRootsLinearEquations();
            break;
        case 18:
            threeRootsLinearEquations();
            break;

        case 0:
            exit(0);

        default:
            printf("!! please enter valid operation");
        }
    }
    return 0;
}

void addition()
{
    printf("Enter the numbers you want to add: ");
    float a, b;
    scanf("%f%f", &a, &b);
    printf(" Sum = %0.04f\n", a + b);
}

void subtraction()
{
    printf("Enter the numbers you want to subtract: ");
    int a, b;
    scanf("%lf%lf", &a, &b);
    printf(" Subtraction = %0.04lf\n", a - b);
}

void multiplication()
{
    printf("Enter the numbers you want to multiply: ");
    int a, b;
    scanf("%lf%lf", &a, &b);
    printf(" Multiplication = %0.04f\n", a * b);
}

void division()
{
    printf("Enter the numbers you want to divide: ");
    int a, b;
    scanf("%lf%lf", &a, &b);
    printf(" Division %0.04f\n", a / b);
}

void modulus()
{
    printf("Enter the numbers you want to find modulus of: ");
    int a, b;
    scanf("%lf%lf", &a, &b);
    printf("The modulus of a and b is %0.04f\n", a % b);
}

void factorial()
{
    int n, factorial;
    printf("Enter the number you want the factorial of: ");
    scanf("%d", &n);
    factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial = factorial * i;
    }
    printf("\nFactorial of %d is %d", n, factorial);
}

void power()
{
    double b;
    double p;
    printf("Enter the base and the power: ");
    scanf("%lf%lf", &b, &p);
    double e = pow(b, p);
    printf("The power is %0.4lf", e);
}

void square()
{
    double b;
    printf("Enter the number you want the square of: ");
    scanf("%lf", &b);
    double p = pow(b, 2);
    printf("The square of %lf is %0.4lf", b, p);
}

void cube()
{
    double b;
    printf("Enter the number you want the cube of: ");
    scanf("%lf", &b);

    double p = pow(b, 3);
    printf("The cube of %lf is %0.4lf", b, p);
}

void squareroot()
{
    double b;
    printf("Enter the number you want the square root of : ");
    scanf("%lf", &b);
    double s = sqrt(b);
    printf("The square root of %lf is %0.4lf", b, s);
}

void SIN()
{
    double b;
    printf("Enter the value in degrees: ");
    scanf("%lf", &b);
    double radians = b * (M_PI / 180.0);
    double si = sin(radians);
    printf("Sin(%lf degrees) = %0.4lf\n", b, si);
}

void COS()
{
    double b;
    printf("Enter the value in degrees: ");
    scanf("%lf", &b);
    double radians = b * (M_PI / 180.0);
    double co = cos(radians);
    printf(" Cos(%lf) = %0.4lf", b, co);
}

void TAN()
{
    double b;
    printf("Enter the value in degrees: ");
    scanf("%lf", &b);
    double radians = b * (M_PI / 180.0);
    double ta = tan(radians);
    printf("Tan(%lf) = %0.4lf", b, ta);
}

void SIN_INVERSE()
{
    double b;
    printf("Enter the value (-1 <= x <= 1): ");
    scanf("%lf", &b);

    if (b >= -1 && b <= 1)
    {
        double result = asin(b);
        double degrees = result * (180.0 / M_PI);
        printf("Arc_Sin(%lf) = %0.4lf degrees\n", b, degrees);
    }
    else
    {
        printf("Invalid input. arc_sin is only defined for values between -1 and 1.\n");
    }
}

void COS_INVERSE()
{
    double b;
    printf("Enter the value (-1 <= x <= 1): ");
    scanf("%lf", &b);

    if (b >= -1 && b <= 1)
    {
        double result = acos(b);
        double degrees = result * (180.0 / M_PI);
        printf("Arc_Cos(%lf) = %0.4lf degrees\n", b, degrees);
    }
    else
    {
        printf("Invalid input. arc_cos is only defined for values between -1 and 1.\n");
    }
}

void TAN_INVERSE()
{
    double b;
    printf("Enter the value: ");
    scanf("%lf", &b);

    double result = atan(b);
    double degrees = result * (180.0 / M_PI);
    printf("Arc_Tan(%lf) = %0.4lf degrees\n", b, degrees);
}

void twoRootsLinearEquations()
{
    double a1, b1, c1, a2, b2, c2, x, y;

    printf("Enter coefficients a1, b1, c1 for the first equation (a1x + b1y + c1 = 0): ");
    scanf("%lf %lf %lf", &a1, &b1, &c1);

    printf("Enter coefficients a2, b2, c2 for the second equation (a2x + b2y + c2 = 0): ");
    scanf("%lf %lf %lf", &a2, &b2, &c2);

    double determinant = a1 * b2 - a2 * b1;
    if (determinant == 0)
    {
        printf("The equations have no unique solution (they may be parallel or coincident).\n");
        return;
    }

    x = (b1 * c2 - b2 * c1) / determinant;
    y = (a2 * c1 - a1 * c2) / determinant;

    printf("The solutions are:\n");
    printf("x = %0.4lf\n", x);
    printf("y = %0.4lf\n", y);
}


void threeRootsLinearEquations() {
    double a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
    double x, y, z;

    printf("Enter coefficients a1, b1, c1, d1 for the first equation (a1x + b1y + c1z + d1 = 0): ");
    scanf("%lf %lf %lf %lf", &a1, &b1, &c1, &d1);

    printf("Enter coefficients a2, b2, c2, d2 for the second equation (a2x + b2y + c2z + d2 = 0): ");
    scanf("%lf %lf %lf %lf", &a2, &b2, &c2, &d2);

    printf("Enter coefficients a3, b3, c3, d3 for the third equation (a3x + b3y + c3z + d3 = 0): ");
    scanf("%lf %lf %lf %lf", &a3, &b3, &c3, &d3);

    double determinant = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + d1 * (a2 * b3 - a3 * b2);
    
    if (determinant == 0) {
        printf("The equations have no unique solution (they may be parallel or coincident).\n");
        return;
    }

    x = (d1 * (b2 * c3 - b3 * c2) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2)) / determinant;
    y = (a1 * (d2 * c3 - d3 * c2) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2)) / determinant;
    z = (a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2)) / determinant;

    printf("The solutions are:\n");
    printf("x = %0.4lf\n", x);
    printf("y = %0.4lf\n", y);
    printf("z = %0.4lf\n", z);
}
