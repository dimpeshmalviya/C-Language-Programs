/*
bmi_calculator.c
Calculate BMI from weight (kg) and height (m) and print category.
Compile:
  gcc -o bmi_calculator bmi_calculator.c
Usage:
  ./bmi_calculator 70 1.75
  Output:
  BMI = 22.86 (Normal weight)
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <weight_kg> <height_m>\n", argv[0]);
        return 1;
    }
    double weight = atof(argv[1]);
    double height = atof(argv[2]);
    if (weight <= 0 || height <= 0) {
        fprintf(stderr, "Weight and height must be positive numbers.\n");
        return 1;
    }
    double bmi = weight / (height * height);
    printf("BMI = %.2f ", bmi);
    if (bmi < 18.5) printf("(Underweight)\n");
    else if (bmi < 25.0) printf("(Normal weight)\n");
    else if (bmi < 30.0) printf("(Overweight)\n");
    else printf("(Obesity)\n");
    return 0;
}
