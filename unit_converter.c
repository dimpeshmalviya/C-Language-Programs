/*
 * Universal Unit Converter - Multi-Category Conversion Tool
 * 
 * Program: Universal Unit Converter
 * Problem: Convert between different units of measurement across multiple categories
 * 
 * Features:
 * - Length conversions (meters, feet, inches, kilometers, miles, etc.)
 * - Weight conversions (kilograms, pounds, ounces, grams, etc.)
 * - Temperature conversions (Celsius, Fahrenheit, Kelvin)
 * - Volume conversions (liters, gallons, milliliters, etc.)
 * - Area conversions (square meters, acres, hectares, etc.)
 * - Time conversions (seconds, minutes, hours, days, etc.)
 * 
 * Input: Category selection, unit types, and value to convert
 * Output: Converted value with appropriate units
 * 
 * Example:
 * Input: Length category, 100 meters to feet
 * Output: 100 meters = 328.084 feet
 * 
 * Compilation: gcc -o unit_converter unit_converter.c
 * Usage: ./unit_converter
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes
void display_main_menu();
void length_converter();
void weight_converter();
void temperature_converter();
void volume_converter();
void area_converter();
void time_converter();
void display_length_units();
void display_weight_units();
void display_temperature_units();
void display_volume_units();
void display_area_units();
void display_time_units();
void clear_screen();
void pause_screen();

int main() {
    int choice;
    
    printf("========================================\n");
    printf("    Universal Unit Converter\n");
    printf("========================================\n");
    printf("Welcome to the most comprehensive unit converter!\n\n");
    
    do {
        display_main_menu();
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                length_converter();
                break;
            case 2:
                weight_converter();
                break;
            case 3:
                temperature_converter();
                break;
            case 4:
                volume_converter();
                break;
            case 5:
                area_converter();
                break;
            case 6:
                time_converter();
                break;
            case 7:
                printf("\nThank you for using Universal Unit Converter!\n");
                printf("Happy converting!\n");
                break;
            default:
                printf("\nInvalid choice! Please select 1-7.\n");
                pause_screen();
        }
    } while (choice != 7);
    
    return 0;
}

void display_main_menu() {
    clear_screen();
    printf("========================================\n");
    printf("      UNIVERSAL UNIT CONVERTER\n");
    printf("========================================\n");
    printf("1. Length Converter\n");
    printf("2. Weight Converter\n");
    printf("3. Temperature Converter\n");
    printf("4. Volume Converter\n");
    printf("5. Area Converter\n");
    printf("6. Time Converter\n");
    printf("7. Exit\n");
    printf("========================================\n\n");
}

void length_converter() {
    clear_screen();
    printf("========================================\n");
    printf("         LENGTH CONVERTER\n");
    printf("========================================\n");
    
    display_length_units();
    
    int from_unit, to_unit;
    double value, result;
    
    printf("Enter source unit (1-8): ");
    scanf("%d", &from_unit);
    printf("Enter target unit (1-8): ");
    scanf("%d", &to_unit);
    printf("Enter value to convert: ");
    scanf("%lf", &value);
    
    // Convert to meters first (base unit)
    double meters;
    switch (from_unit) {
        case 1: meters = value; break;                    // meters
        case 2: meters = value / 100.0; break;           // centimeters
        case 3: meters = value / 1000.0; break;          // millimeters
        case 4: meters = value * 1000.0; break;          // kilometers
        case 5: meters = value * 0.3048; break;          // feet
        case 6: meters = value * 0.0254; break;          // inches
        case 7: meters = value * 1609.34; break;         // miles
        case 8: meters = value * 0.9144; break;          // yards
        default:
            printf("Invalid source unit!\n");
            pause_screen();
            return;
    }
    
    // Convert from meters to target unit
    switch (to_unit) {
        case 1: result = meters; break;                   // meters
        case 2: result = meters * 100.0; break;          // centimeters
        case 3: result = meters * 1000.0; break;         // millimeters
        case 4: result = meters / 1000.0; break;         // kilometers
        case 5: result = meters / 0.3048; break;         // feet
        case 6: result = meters / 0.0254; break;         // inches
        case 7: result = meters / 1609.34; break;        // miles
        case 8: result = meters / 0.9144; break;         // yards
        default:
            printf("Invalid target unit!\n");
            pause_screen();
            return;
    }
    
    char* units[] = {"", "meters", "centimeters", "millimeters", "kilometers", 
                     "feet", "inches", "miles", "yards"};
    
    printf("\nCONVERSION RESULT:\n");
    printf("%.6f %s = %.6f %s\n", value, units[from_unit], result, units[to_unit]);
    
    pause_screen();
}

void weight_converter() {
    clear_screen();
    printf("========================================\n");
    printf("         WEIGHT CONVERTER\n");
    printf("========================================\n");
    
    display_weight_units();
    
    int from_unit, to_unit;
    double value, result;
    
    printf("Enter source unit (1-6): ");
    scanf("%d", &from_unit);
    printf("Enter target unit (1-6): ");
    scanf("%d", &to_unit);
    printf("Enter value to convert: ");
    scanf("%lf", &value);
    
    // Convert to grams first (base unit)
    double grams;
    switch (from_unit) {
        case 1: grams = value; break;                     // grams
        case 2: grams = value * 1000.0; break;           // kilograms
        case 3: grams = value * 453.592; break;          // pounds
        case 4: grams = value * 28.3495; break;          // ounces
        case 5: grams = value * 1000000.0; break;        // tons (metric)
        case 6: grams = value * 907185.0; break;         // tons (US)
        default:
            printf("Invalid source unit!\n");
            pause_screen();
            return;
    }
    
    // Convert from grams to target unit
    switch (to_unit) {
        case 1: result = grams; break;                    // grams
        case 2: result = grams / 1000.0; break;          // kilograms
        case 3: result = grams / 453.592; break;         // pounds
        case 4: result = grams / 28.3495; break;         // ounces
        case 5: result = grams / 1000000.0; break;       // tons (metric)
        case 6: result = grams / 907185.0; break;        // tons (US)
        default:
            printf("Invalid target unit!\n");
            pause_screen();
            return;
    }
    
    char* units[] = {"", "grams", "kilograms", "pounds", "ounces", "metric tons", "US tons"};
    
    printf("\nCONVERSION RESULT:\n");
    printf("%.6f %s = %.6f %s\n", value, units[from_unit], result, units[to_unit]);
    
    pause_screen();
}

void temperature_converter() {
    clear_screen();
    printf("========================================\n");
    printf("        TEMPERATURE CONVERTER\n");
    printf("========================================\n");
    
    display_temperature_units();
    
    int from_unit, to_unit;
    double value, result;
    
    printf("Enter source unit (1-3): ");
    scanf("%d", &from_unit);
    printf("Enter target unit (1-3): ");
    scanf("%d", &to_unit);
    printf("Enter temperature value: ");
    scanf("%lf", &value);
    
    // Convert to Celsius first (base unit)
    double celsius;
    switch (from_unit) {
        case 1: celsius = value; break;                   // Celsius
        case 2: celsius = (value - 32.0) * 5.0/9.0; break; // Fahrenheit
        case 3: celsius = value - 273.15; break;         // Kelvin
        default:
            printf("Invalid source unit!\n");
            pause_screen();
            return;
    }
    
    // Convert from Celsius to target unit
    switch (to_unit) {
        case 1: result = celsius; break;                  // Celsius
        case 2: result = (celsius * 9.0/5.0) + 32.0; break; // Fahrenheit
        case 3: result = celsius + 273.15; break;        // Kelvin
        default:
            printf("Invalid target unit!\n");
            pause_screen();
            return;
    }
    
    char* units[] = {"", "°C", "°F", "K"};
    
    printf("\nCONVERSION RESULT:\n");
    printf("%.2f%s = %.2f%s\n", value, units[from_unit], result, units[to_unit]);
    
    // Display additional info for temperature
    if (to_unit == 1) { // Celsius
        if (result == 0) printf("Water freezing point!\n");
        else if (result == 100) printf("Water boiling point!\n");
        else if (result < 0) printf("Below freezing!\n");
        else if (result > 35) printf("Hot temperature!\n");
    }
    
    pause_screen();
}

void volume_converter() {
    clear_screen();
    printf("========================================\n");
    printf("         VOLUME CONVERTER\n");
    printf("========================================\n");
    
    display_volume_units();
    
    int from_unit, to_unit;
    double value, result;
    
    printf("Enter source unit (1-6): ");
    scanf("%d", &from_unit);
    printf("Enter target unit (1-6): ");
    scanf("%d", &to_unit);
    printf("Enter value to convert: ");
    scanf("%lf", &value);
    
    // Convert to liters first (base unit)
    double liters;
    switch (from_unit) {
        case 1: liters = value; break;                    // liters
        case 2: liters = value / 1000.0; break;          // milliliters
        case 3: liters = value * 3.78541; break;         // gallons (US)
        case 4: liters = value * 0.946353; break;        // quarts (US)
        case 5: liters = value * 0.473176; break;        // pints (US)
        case 6: liters = value * 0.0295735; break;       // fluid ounces (US)
        default:
            printf("Invalid source unit!\n");
            pause_screen();
            return;
    }
    
    // Convert from liters to target unit
    switch (to_unit) {
        case 1: result = liters; break;                   // liters
        case 2: result = liters * 1000.0; break;         // milliliters
        case 3: result = liters / 3.78541; break;        // gallons (US)
        case 4: result = liters / 0.946353; break;       // quarts (US)
        case 5: result = liters / 0.473176; break;       // pints (US)
        case 6: result = liters / 0.0295735; break;      // fluid ounces (US)
        default:
            printf("Invalid target unit!\n");
            pause_screen();
            return;
    }
    
    char* units[] = {"", "liters", "milliliters", "gallons", "quarts", "pints", "fluid ounces"};
    
    printf("\nCONVERSION RESULT:\n");
    printf("%.6f %s = %.6f %s\n", value, units[from_unit], result, units[to_unit]);
    
    pause_screen();
}

void area_converter() {
    clear_screen();
    printf("========================================\n");
    printf("         AREA CONVERTER\n");
    printf("========================================\n");
    
    display_area_units();
    
    int from_unit, to_unit;
    double value, result;
    
    printf("Enter source unit (1-6): ");
    scanf("%d", &from_unit);
    printf("Enter target unit (1-6): ");
    scanf("%d", &to_unit);
    printf("Enter value to convert: ");
    scanf("%lf", &value);
    
    // Convert to square meters first (base unit)
    double sq_meters;
    switch (from_unit) {
        case 1: sq_meters = value; break;                 // square meters
        case 2: sq_meters = value / 10000.0; break;      // square centimeters
        case 3: sq_meters = value * 1000000.0; break;    // square kilometers
        case 4: sq_meters = value * 0.092903; break;     // square feet
        case 5: sq_meters = value * 4047.0; break;       // acres
        case 6: sq_meters = value * 10000.0; break;      // hectares
        default:
            printf("Invalid source unit!\n");
            pause_screen();
            return;
    }
    
    // Convert from square meters to target unit
    switch (to_unit) {
        case 1: result = sq_meters; break;               // square meters
        case 2: result = sq_meters * 10000.0; break;    // square centimeters
        case 3: result = sq_meters / 1000000.0; break;  // square kilometers
        case 4: result = sq_meters / 0.092903; break;   // square feet
        case 5: result = sq_meters / 4047.0; break;     // acres
        case 6: result = sq_meters / 10000.0; break;    // hectares
        default:
            printf("Invalid target unit!\n");
            pause_screen();
            return;
    }
    
    char* units[] = {"", "sq meters", "sq centimeters", "sq kilometers", "sq feet", "acres", "hectares"};
    
    printf("\nCONVERSION RESULT:\n");
    printf("%.6f %s = %.6f %s\n", value, units[from_unit], result, units[to_unit]);
    
    pause_screen();
}

void time_converter() {
    clear_screen();
    printf("========================================\n");
    printf("         TIME CONVERTER\n");
    printf("========================================\n");
    
    display_time_units();
    
    int from_unit, to_unit;
    double value, result;
    
    printf("Enter source unit (1-7): ");
    scanf("%d", &from_unit);
    printf("Enter target unit (1-7): ");
    scanf("%d", &to_unit);
    printf("Enter value to convert: ");
    scanf("%lf", &value);
    
    // Convert to seconds first (base unit)
    double seconds;
    switch (from_unit) {
        case 1: seconds = value; break;                   // seconds
        case 2: seconds = value * 60.0; break;           // minutes
        case 3: seconds = value * 3600.0; break;         // hours
        case 4: seconds = value * 86400.0; break;        // days
        case 5: seconds = value * 604800.0; break;       // weeks
        case 6: seconds = value * 2629746.0; break;      // months (average)
        case 7: seconds = value * 31556952.0; break;     // years (average)
        default:
            printf("Invalid source unit!\n");
            pause_screen();
            return;
    }
    
    // Convert from seconds to target unit
    switch (to_unit) {
        case 1: result = seconds; break;                  // seconds
        case 2: result = seconds / 60.0; break;          // minutes
        case 3: result = seconds / 3600.0; break;        // hours
        case 4: result = seconds / 86400.0; break;       // days
        case 5: result = seconds / 604800.0; break;      // weeks
        case 6: result = seconds / 2629746.0; break;     // months (average)
        case 7: result = seconds / 31556952.0; break;    // years (average)
        default:
            printf("Invalid target unit!\n");
            pause_screen();
            return;
    }
    
    char* units[] = {"", "seconds", "minutes", "hours", "days", "weeks", "months", "years"};
    
    printf("\nCONVERSION RESULT:\n");
    printf("%.6f %s = %.6f %s\n", value, units[from_unit], result, units[to_unit]);
    
    pause_screen();
}

// Display functions for unit options
void display_length_units() {
    printf("Available Length Units:\n");
    printf("1. Meters        2. Centimeters\n");
    printf("3. Millimeters   4. Kilometers\n");
    printf("5. Feet          6. Inches\n");
    printf("7. Miles         8. Yards\n\n");
}

void display_weight_units() {
    printf("Available Weight Units:\n");
    printf("1. Grams         2. Kilograms\n");
    printf("3. Pounds        4. Ounces\n");
    printf("5. Metric Tons   6. US Tons\n\n");
}

void display_temperature_units() {
    printf("Available Temperature Units:\n");
    printf("1. Celsius (°C)  2. Fahrenheit (°F)\n");
    printf("3. Kelvin (K)\n\n");
}

void display_volume_units() {
    printf("Available Volume Units:\n");
    printf("1. Liters        2. Milliliters\n");
    printf("3. Gallons (US)  4. Quarts (US)\n");
    printf("5. Pints (US)    6. Fluid Ounces (US)\n\n");
}

void display_area_units() {
    printf("Available Area Units:\n");
    printf("1. Square Meters      2. Square Centimeters\n");
    printf("3. Square Kilometers  4. Square Feet\n");
    printf("5. Acres             6. Hectares\n\n");
}

void display_time_units() {
    printf("Available Time Units:\n");
    printf("1. Seconds       2. Minutes\n");
    printf("3. Hours         4. Days\n");
    printf("5. Weeks         6. Months\n");
    printf("7. Years\n\n");
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause_screen() {
    printf("\nPress Enter to continue...");
    while (getchar() != '\n'); // Clear input buffer
    getchar(); // Wait for Enter
}
