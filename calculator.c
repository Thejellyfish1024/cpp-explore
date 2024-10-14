#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Zulkar Nayem
void addition();
void subtraction();
void multiplication();
void division();

// Tanim
void power();
void square();
void cube();
void percentage();

// Suleiman
void modulus();
void factorial();
void squareroot();
void cuberoot();
void nthRootOfX();

// Tanvir
void SIN();
void COS();
void TAN();
void SIN_INVERSE();
void COS_INVERSE();
void TAN_INVERSE();

// Rahim
void LOG();
void LN();
void exponential();
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
    printf(" 5 : Power \n");
    printf(" 6 : Square \n");
    printf(" 7 : Cube \n");
    printf(" 8 : Percentage \n");
    printf(" 9 : Modulus\n");
    printf(" 10 : Factorial \n");
    printf(" 11 : Square-root\n");
    printf(" 12 : Cube-root\n");
    printf(" 13 : n-th Root Of X\n");
    printf(" 14 : Sin()\n");
    printf(" 15 : Cos()\n");
    printf(" 16 : Tan()\n");
    printf(" 17 : Arc_Sin()\n");
    printf(" 18 : Arc_Cos()\n");
    printf(" 19 : Arc_Tan()\n");
    printf(" 20 : log\n");
    printf(" 21 : ln\n");
    printf(" 22 : e^x\n");
    printf(" 23 : Two Roots Linear Equations\n");
    printf(" 24 : Three Roots Linear Equations\n");

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
            power();
            break;

        case 6:
            square();
            break;

        case 7:
            cube();
            break;

        case 8:
            percentage();
            break;

        case 9:
            modulus();
            break;

        case 10:
            factorial();
            break;

        case 11:
            squareroot();
            break;

        case 12:
            cuberoot();
            break;

        case 13:
            nthRootOfX();
            break;

        case 14:
            SIN();
            break;

        case 15:
            COS();
            break;

        case 16:
            TAN();
            break;

        case 17:
            SIN_INVERSE();
            break;

        case 18:
            COS_INVERSE();
            break;

        case 19:
            TAN_INVERSE();
            break;

        case 20:
            LOG();
            break;

        case 21:
            LN();
            break;

        case 22:
            exponential();
            break;

        case 23:
            twoRootsLinearEquations();
            break;

        case 24:
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

////////////////////  Zulkar Nayem - Start /////////////////
void addition()
{
    printf("Enter the numbers you want to add: ");
    double a, b;
    if (scanf("%lf%lf", &a, &b) != 2)
    {
        printf("Invalid input. Please enter valid number values.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    printf(" Sum = %0.04lf\n", a + b);
}

void subtraction()
{
    printf("Enter the numbers you want to subtract: ");
    double a, b;
    if (scanf("%lf%lf", &a, &b) != 2)
    {
        printf("Invalid input. Please enter valid number values.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    printf(" Subtraction = %0.04lf\n", a - b);
}

void multiplication()
{
    printf("Enter the numbers you want to multiply: ");
    double a, b;
    if (scanf("%lf%lf", &a, &b) != 2)
    {
        printf("Invalid input. Please enter valid number values.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    printf(" Multiplication = %0.04lf\n", a * b);
}

void division()
{
    printf("Enter the numbers you want to divide: ");
    double a, b;
    if (scanf("%lf%lf", &a, &b) != 2)
    {
        printf("Invalid input. Please enter valid number values.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    printf(" Division %0.04lf\n", a / b);
}
////////////////////  Zulkar Nayem - End /////////////////

////////////////////  Tanim - Start /////////////////
void power()
{
    double base;
    double power;
    printf("Enter the base and the power: ");
    if (scanf("%lf%lf", &base, &power) != 2)
    {
        printf("Invalid input. Please enter valid number value.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    double value = pow(base, power);
    printf("The power is %0.4lf", value);
}

void square()
{
    double number;
    printf("Enter the number you want the square of: ");
    if (scanf("%lf", &number) != 1)
    {
        printf("Invalid input. Please enter valid number value.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    double value = pow(number, 2);
    printf("The square of %lf is %0.4lf", number, value);
}

void cube()
{
    double number;
    printf("Enter the number you want the cube of: ");
    if (scanf("%lf", &number) != 1)
    {
        printf("Invalid input. Please enter valid number value.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    double value = pow(number, 3);
    printf("The cube of %lf is %0.4lf", number, value);
}

void percentage()
{
    double number, percentage;
    printf("Enter the number and the percentage(%%): ");
    if (scanf("%lf%lf", &number, &percentage) != 2)
    {
        printf("Invalid input. Please enter valid number values.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    double value = number * (percentage / 100.0);
    printf("The %lf of %lf is %0.4lf", percentage, number, value);
}
////////////////////  Tanim - End /////////////////

////////////////////  Suleiman - Start /////////////////
void modulus()
{
    printf("Enter the numbers you want to find modulus of: ");
    int a, b;
    if (scanf("%d%d", &a, &b) != 2)
    {
        printf("Invalid input. Please enter valid integer values.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    printf("The modulus of %d and %d is %d\n", a, b, a % b);
}

void factorial()
{
    int n;
    long long int factorial = 1;

    printf("Enter the number you want the factorial of: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Invalid input. Please enter a valid integer.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    if (n < 0)
    {
        printf("Factorial is possible for only positive numbers.\n");
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }

    printf("Factorial of %d is %lld\n", n, factorial);
}

void squareroot()
{
    double number;
    printf("Enter the number you want the square root of : ");
    if (scanf("%lf", &number) != 1)
    {
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    double root = sqrt(number);
    printf("The square root of %lf is %0.4lf", number, root);
}

void cuberoot()
{
    double number;
    printf("Enter the number you want the cube root of : ");
    if (scanf("%lf", &number) != 1)
    {
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    double root = pow(number, 1.0 / 3.0);
    printf("The square root of %lf is %0.4lf", number, root);
}

void nthRootOfX()
{
    double number, r;
    printf("Enter the number and root value : ");
    if (scanf("%lf%lf", &number, &r) != 2)
    {
        printf("Invalid input. Please enter valid number values.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    double root = pow(number, 1.0 / r);
    printf("The value is %0.4lf", root);
}
////////////////////  Suleiman - End /////////////////

////////////////////  Tanvir - Start /////////////////
void SIN()
{
    double b;
    printf("Enter the value in degrees for sin(x): ");

    if (scanf("%lf", &b) != 1)
    {
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    double radians = b * (M_PI / 180.0);
    double si = sin(radians);
    printf("Sin(%lf degrees) = %0.4lf\n", b, si);
}

void COS()
{
    double b;
    printf("Enter the value in degrees for cos(x): ");

    if (scanf("%lf", &b) != 1)
    {
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    double radians = b * (M_PI / 180.0);
    double co = cos(radians);
    printf(" Cos(%lf) = %0.4lf", b, co);
}

void TAN()
{
    double b;
    printf("Enter the value in degrees for tan(x): ");

    if (scanf("%lf", &b) != 1)
    {
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    if (fmod(b, 180.0) == 90.0)
    {
        printf("Tan(%lf) is undefined or infinity.\n", b);
        return;
    }
    double radians = b * (M_PI / 180.0);
    double ta = tan(radians);

    printf("Tan(%lf) = %0.4lf\n", b, ta);
}

void SIN_INVERSE()
{
    double b;
    printf("Enter the value for arc-sin(x) (Range: -1 <= x <= 1): ");
    if (scanf("%lf", &b) != 1)
    {
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n')
            ;
        return;
    }

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
    printf("Enter the value for arc-cos(x) (Range: -1 <= x <= 1): ");

    if (scanf("%lf", &b) != 1)
    {
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n')
            ;
        return;
    }

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
    printf("Enter the value for arc-tan(x): ");

    if (scanf("%lf", &b) != 1)
    {
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    double result = atan(b);
    double degrees = result * (180.0 / M_PI);
    printf("Arc_Tan(%lf) = %0.4lf degrees\n", b, degrees);
}
////////////////////  Tanvir - End /////////////////

////////////////////  Rahim - Start /////////////////
void LOG()
{
    double value;
    printf("Enter a positive value for log(x): ");
    if (scanf("%lf", &value) != 1)
    {
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    if (value > 0)
    {
        double result = log10(value);
        printf("log(%lf) = %0.4lf\n", value, result);
    }
    else
    {
        printf("Invalid input. Log is only defined for positive values.\n");
    }
}

void LN()
{
    double value;
    printf("Enter a positive value for ln(x): ");
    if (scanf("%lf", &value) != 1)
    {
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    if (value > 0)
    {
        double result = log(value);
        printf("ln(%lf) = %0.4lf\n", value, result);
    }
    else
    {
        printf("Invalid input. ln is only defined for positive values.\n");
    }
}

void exponential()
{
    double value;
    printf("Enter a value for e^x: ");
    if (scanf("%lf", &value) != 1)
    {
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    double result = exp(value);
    printf("e^(%lf) = %0.4lf\n", value, result);
}

void twoRootsLinearEquations()
{
    double a1, b1, c1, a2, b2, c2, x, y;
    int result;

    printf("Enter coefficients a1, b1, c1 for the first equation (a1x + b1y + c1 = 0): ");
    result = scanf("%lf %lf %lf", &a1, &b1, &c1);
    if (result != 3)
    {
        printf("Invalid input! Please enter valid number coefficients for the first equation.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    printf("Enter coefficients a2, b2, c2 for the second equation (a2x + b2y + c2 = 0): ");
    result = scanf("%lf %lf %lf", &a2, &b2, &c2);
    if (result != 3)
    {
        printf("Invalid input! Please enter valid number coefficients for the second equation.\n");
        // Clear input buffer
        while (getchar() != '\n')
            ;
        return;
    }

    double determinant = a1 * b2 - a2 * b1;
    if (determinant == 0)
    {
        printf("The equations have no unique solution (they may be parallel).\n");
        return;
    }

    x = (b1 * c2 - b2 * c1) / determinant;
    y = (a2 * c1 - a1 * c2) / determinant;

    printf("The solutions are:\n");
    printf("x = %0.4lf\n", x);
    printf("y = %0.4lf\n", y);
}

void threeRootsLinearEquations()
{
    double a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
    double x, y, z;

    printf("Enter coefficients a1, b1, c1, d1 for the first equation (a1x + b1y + c1z + d1 = 0): ");

    if (scanf("%lf %lf %lf %lf", &a1, &b1, &c1, &d1) != 4)
    {
        printf("Invalid input. Please enter valid numeric values.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    printf("Enter coefficients a2, b2, c2, d2 for the second equation (a2x + b2y + c2z + d2 = 0): ");
    if (scanf("%lf %lf %lf %lf", &a2, &b2, &c2, &d2) != 4)
    {
        printf("Invalid input. Please enter valid numeric values.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    printf("Enter coefficients a3, b3, c3, d3 for the third equation (a3x + b3y + c3z + d3 = 0): ");
    if (scanf("%lf %lf %lf %lf", &a3, &b3, &c3, &d3) != 4)
    {
        printf("Invalid input. Please enter valid numeric values.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    double determinant = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + d1 * (a2 * b3 - a3 * b2);

    if (determinant == 0)
    {
        printf("The equations have no unique solution (they may be parallel).\n");
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
////////////////////  Rahim - End /////////////////
