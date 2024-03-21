#include<stdio.h>
#include<math.h>

// Function prototypes
double maxwells_equation(double, double);
double complex_number(double, double, double, double);

int main() {
    int choice;
    double variable1, variable2, variable3, variable4, result;

    do {
        printf("Select a formula:\n1. Maxwell's Equation\n2. Complex Number\n3. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter two variables for Maxwell's Equation: ");
                scanf("%lf %lf", &variable1, &variable2);
                result = maxwells_equation(variable1, variable2);
                printf("Result: %lf\n", result);
                break;
            case 2:
                printf("Enter four variables for Complex Number: ");
                scanf("%lf %lf %lf %lf", &variable1, &variable2, &variable3, &variable4);
                result = complex_number(variable1, variable2, variable3, variable4);
                printf("Result: %lf\n", result);
                break;
            case 3:
                printf("Quitting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}

// Function definitions
double maxwells_equation(double charge, double permittivity) {
    // Implement Maxwell's equation here
    return charge / permittivity;  // Gauss's law for electricity
}

double complex_number(double a, double b, double c, double d) {
    double real_sum = a + c;
    double imag_sum = b + d;

    double real_product = a * c - b * d;
    double imag_product = a * d + b * c;

    double magnitude = sqrt(real_sum * real_sum + imag_sum * imag_sum);

    return magnitude;
}
