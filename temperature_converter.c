/*
temperature_converter.c
Convert temperature between Celsius, Fahrenheit, and Kelvin.
Compile:
  gcc -o temperature_converter temperature_converter.c
Usage:
  ./temperature_converter 100 C F
  (Converts 100 Celsius to Fahrenheit)
Supported units: C, F, K (case-insensitive)
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

double to_celsius(double value, const char *unit) {
    char u = toupper((unsigned char)unit[0]);
    if (u == 'C') return value;
    if (u == 'F') return (value - 32.0) * 5.0 / 9.0;
    if (u == 'K') return value - 273.15;
    fprintf(stderr, "Unknown unit %s\n", unit);
    exit(1);
}

double from_celsius(double c, const char *unit) {
    char u = toupper((unsigned char)unit[0]);
    if (u == 'C') return c;
    if (u == 'F') return c * 9.0 / 5.0 + 32.0;
    if (u == 'K') return c + 273.15;
    fprintf(stderr, "Unknown unit %s\n", unit);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <value> <from> <to>\nUnits: C, F, K\n", argv[0]);
        return 1;
    }
    double val = atof(argv[1]);
    double c = to_celsius(val, argv[2]);
    double out = from_celsius(c, argv[3]);
    printf("%.4g %s = %.4g %s\n", val, argv[2], out, argv[3]);
    return 0;
}
