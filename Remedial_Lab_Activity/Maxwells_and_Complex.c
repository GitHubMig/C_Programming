#include<stdio.h>
#include<math.h>

// Function prototypes
double maxwells_equation(double, double);
double complex_number(double, double, double, double);

int main() {
    int formula_choice, variable_choice;
    double variable1, variable2, variable3, variable4, result;

    do {
        printf("Select a formula:\n1. Maxwell's Equation\n2. Complex Number\n3. Quit\n");
        scanf("%d", &formula_choice);

        switch(formula_choice) {
            case 1:
                do {
                    printf("Select a variable to compute:\n1. Charge\n2. Permittivity\n3. Go back\n");
                    scanf("%d", &variable_choice);
                    switch(variable_choice) {
                        case 1:
                            printf("Enter permittivity: ");
                            scanf("%lf", &variable2);
                            result = maxwells_equation(1, variable2);
                            printf("Charge: %lf\n", result);
                            break;
                        case 2:
                            printf("Enter charge: ");
                            scanf("%lf", &variable1);
                            result = maxwells_equation(variable1, 1);
                            printf("Permittivity: %lf\n", result);
                            break;
                    }
                } while(variable_choice != 3);
                break;
            case 2:
                do {
                    printf("Select a variable to compute:\n1. Real Sum\n2. Imaginary Sum\n3. Real Product\n4. Imaginary Product\n5. Magnitude\n6. Go back\n");
                    scanf("%d", &variable_choice);
                    switch(variable_choice) {
                        case 1:
                            printf("Enter b, c, d: ");
                            scanf("%lf %lf %lf", &variable2, &variable3, &variable4);
                            result = complex_number(1, variable2, variable3, variable4);
                            printf("Real Sum: %lf\n", result);
                            break;
                        case 2:
                            printf("Enter a, c, d: ");
                            scanf("%lf %lf %lf", &variable1, &variable3, &variable4);
                            result = complex_number(variable1, 1, variable3, variable4);
                            printf("Imaginary Sum: %lf\n", result);
                            break;
                        case 3:
                            printf("Enter b, c, d: ");
                            scanf("%lf %lf %lf", &variable2, &variable3, &variable4);
                            result = complex_number(1, variable2, variable3, variable4);
                            printf("Real Product: %lf\n", result);
                            break;
                        case 4:
                            printf("Enter a, c, d: ");
                            scanf("%lf %lf %lf", &variable1, &variable3, &variable4);
                            result = complex_number(variable1, 1, variable3, variable4);
                            printf("Imaginary Product: %lf\n", result);
                            break;
                        case 5:
                            printf("Enter a, b, c, d: ");
                            scanf("%lf %lf %lf %lf", &variable1, &variable2, &variable3, &variable4);
                            result = complex_number(variable1, variable2, variable3, variable4);
                            printf("Magnitude: %lf\n", result);
                            break;
                    }
                } while(variable_choice != 6);
                break;
            case 3:
                printf("Quitting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(formula_choice != 3);

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
