#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Simple color macros
#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"

#define FILE_NAME "travel_records.csv"
#define TEMP_FILE "temp.csv"

// Structure to hold travel data
typedef struct
{
    int id;
    char customerName[100];
    char destination[100];
    char date[20];
    float distance;
    float farePerKm;
    float gstPercent;
    float totalAmount;
} TravelRecord;

// Function declarations
void displayMenu();
void addRecord();
void viewRecords();
void searchRecords();
void updateRecord();
void deleteRecord();
void showSummary();
void generateInvoice();
void createBackup();
int getNextId();
void getCurrentDate(char* buffer);
void clearInputBuffer();
void pauseScreen();

int main()
{
    int choice;
    
    printf(CYAN "\n=== Simple Travel Billing System ===\n" RESET);
    
    while (1)
    {
        displayMenu();
        printf(YELLOW "Enter your choice: " RESET);
        
        if (scanf("%d", &choice) != 1)
        {
            printf(RED "Invalid input! Please enter a number.\n" RESET);
            clearInputBuffer();
            pauseScreen();
            continue;
        }
        clearInputBuffer();
        
        switch (choice)
        {
            case 1: addRecord(); break;
            case 2: viewRecords(); break;
            case 3: searchRecords(); break;
            case 4: updateRecord(); break;
            case 5: deleteRecord(); break;
            case 6: showSummary(); break;
            case 7: generateInvoice(); break;
            case 8: createBackup(); break;
            case 9:
                printf(GREEN "Thank you for using Travel Billing System!\n" RESET);
                exit(0);
            default:
                printf(RED "Invalid choice! Please try again.\n" RESET);
                pauseScreen();
        }
    }
    return 0;
}

void displayMenu()
{
    printf("\n" CYAN "================================\n");
    printf("   Travel Billing System\n");
    printf("================================\n" RESET);
    printf("1. Add New Record\n");
    printf("2. View All Records\n");
    printf("3. Search Records\n");
    printf("4. Update Record\n");
    printf("5. Delete Record\n");
    printf("6. Show Summary\n");
    printf("7. Generate Invoice\n");
    printf("8. Create Backup\n");
    printf("9. Exit\n");
    printf(CYAN "================================\n" RESET);
}

void addRecord()
{
    TravelRecord record;
    FILE *fp = fopen(FILE_NAME, "a");
    
    if (fp == NULL)
    {
        printf(RED "Error: Cannot open file!\n" RESET);
        pauseScreen();
        return;
    }
    
    printf(CYAN "\n--- Add New Record ---\n" RESET);
    
    record.id = getNextId();
    getCurrentDate(record.date);
    
    printf("Record ID: %d\n", record.id);
    printf("Date: %s\n", record.date);
    
    printf("Enter Customer Name: ");
    fgets(record.customerName, sizeof(record.customerName), stdin);
    record.customerName[strcspn(record.customerName, "\n")] = 0;
    
    printf("Enter Destination: ");
    fgets(record.destination, sizeof(record.destination), stdin);
    record.destination[strcspn(record.destination, "\n")] = 0;
    
    printf("Enter Distance (km): ");
    scanf("%f", &record.distance);
    
    printf("Enter Fare per km (Rs): ");
    scanf("%f", &record.farePerKm);
    
    printf("Enter GST Percentage: ");
    scanf("%f", &record.gstPercent);
    
    // Calculate total amount
    float baseAmount = record.distance * record.farePerKm;
    float gstAmount = baseAmount * (record.gstPercent / 100);
    record.totalAmount = baseAmount + gstAmount;
    
    // Write to file
    fprintf(fp, "%d,%s,%s,%s,%.2f,%.2f,%.2f,%.2f\n",
            record.id, record.customerName, record.destination, record.date,
            record.distance, record.farePerKm, record.gstPercent, record.totalAmount);
    
    fclose(fp);
    
    printf(GREEN "\nRecord added successfully!\n" RESET);
    printf("Total Amount: Rs. %.2f\n", record.totalAmount);
    pauseScreen();
}

void viewRecords()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        printf(RED "No records found!\n" RESET);
        pauseScreen();
        return;
    }
    
    printf(CYAN "\n--- All Records ---\n" RESET);
    printf("%-5s %-20s %-20s %-12s %-8s %-8s %-6s %-10s\n",
           "ID", "Customer", "Destination", "Date", "Distance", "Rate", "GST%", "Total");
    printf("--------------------------------------------------------------------------------\n");
    
    char line[500];
    TravelRecord record;
    int count = 0;
    
    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d,%[^,],%[^,],%[^,],%f,%f,%f,%f",
                   &record.id, record.customerName, record.destination, record.date,
                   &record.distance, &record.farePerKm, &record.gstPercent, &record.totalAmount) == 8)
        {
            printf("%-5d %-20s %-20s %-12s %-8.1f %-8.2f %-6.1f %-10.2f\n",
                   record.id, record.customerName, record.destination, record.date,
                   record.distance, record.farePerKm, record.gstPercent, record.totalAmount);
            count++;
        }
    }
    
    fclose(fp);
    printf("\nTotal Records: %d\n", count);
    pauseScreen();
}

void searchRecords()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        printf(RED "No records found!\n" RESET);
        pauseScreen();
        return;
    }
    
    int searchType;
    char searchTerm[100];
    
    printf(CYAN "\n--- Search Records ---\n" RESET);
    printf("1. Search by Customer Name\n");
    printf("2. Search by Destination\n");
    printf("3. Search by ID\n");
    printf("Enter search type: ");
    scanf("%d", &searchType);
    clearInputBuffer();
    
    printf("Enter search term: ");
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0;
    
    printf("\n--- Search Results ---\n");
    printf("%-5s %-20s %-20s %-12s %-10s\n", "ID", "Customer", "Destination", "Date", "Total");
    printf("---------------------------------------------------------------\n");
    
    char line[500];
    TravelRecord record;
    int found = 0;
    
    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d,%[^,],%[^,],%[^,],%f,%f,%f,%f",
                   &record.id, record.customerName, record.destination, record.date,
                   &record.distance, &record.farePerKm, &record.gstPercent, &record.totalAmount) == 8)
        {
            int match = 0;
            
            switch (searchType)
            {
                case 1:
                    if (strstr(record.customerName, searchTerm) != NULL) match = 1;
                    break;
                case 2:
                    if (strstr(record.destination, searchTerm) != NULL) match = 1;
                    break;
                case 3:
                    if (record.id == atoi(searchTerm)) match = 1;
                    break;
            }
            
            if (match)
            {
                printf("%-5d %-20s %-20s %-12s %-10.2f\n",
                       record.id, record.customerName, record.destination, record.date, record.totalAmount);
                found++;
            }
        }
    }
    
    fclose(fp);
    
    if (found == 0)
        printf("No matching records found.\n");
    else
        printf("\nFound %d record(s).\n", found);
    
    pauseScreen();
}

void updateRecord()
{
    int updateId;
    printf(CYAN "\n--- Update Record ---\n" RESET);
    printf("Enter Record ID to update: ");
    scanf("%d", &updateId);
    clearInputBuffer();
    
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen(TEMP_FILE, "w");
    
    if (fp == NULL || temp == NULL)
    {
        printf(RED "Error: Cannot open files!\n" RESET);
        if (fp) fclose(fp);
        if (temp) fclose(temp);
        pauseScreen();
        return;
    }
    
    char line[500];
    TravelRecord record;
    int found = 0;
    
    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d,%[^,],%[^,],%[^,],%f,%f,%f,%f",
                   &record.id, record.customerName, record.destination, record.date,
                   &record.distance, &record.farePerKm, &record.gstPercent, &record.totalAmount) == 8)
        {
            if (record.id == updateId)
            {
                found = 1;
                printf("Current Record:\n");
                printf("Customer: %s\n", record.customerName);
                printf("Destination: %s\n", record.destination);
                printf("Distance: %.2f km\n", record.distance);
                printf("Fare per km: Rs. %.2f\n", record.farePerKm);
                printf("GST: %.1f%%\n", record.gstPercent);
                
                printf("\nEnter new details:\n");
                printf("Customer Name: ");
                fgets(record.customerName, sizeof(record.customerName), stdin);
                record.customerName[strcspn(record.customerName, "\n")] = 0;
                
                printf("Destination: ");
                fgets(record.destination, sizeof(record.destination), stdin);
                record.destination[strcspn(record.destination, "\n")] = 0;
                
                printf("Distance (km): ");
                scanf("%f", &record.distance);
                
                printf("Fare per km (Rs): ");
                scanf("%f", &record.farePerKm);
                
                printf("GST Percentage: ");
                scanf("%f", &record.gstPercent);
                
                // Recalculate total
                float baseAmount = record.distance * record.farePerKm;
                float gstAmount = baseAmount * (record.gstPercent / 100);
                record.totalAmount = baseAmount + gstAmount;
            }
            
            fprintf(temp, "%d,%s,%s,%s,%.2f,%.2f,%.2f,%.2f\n",
                    record.id, record.customerName, record.destination, record.date,
                    record.distance, record.farePerKm, record.gstPercent, record.totalAmount);
        }
    }
    
    fclose(fp);
    fclose(temp);
    
    if (found)
    {
        remove(FILE_NAME);
        rename(TEMP_FILE, FILE_NAME);
        printf(GREEN "Record updated successfully!\n" RESET);
    }
    else
    {
        remove(TEMP_FILE);
        printf(RED "Record with ID %d not found!\n" RESET, updateId);
    }
    
    pauseScreen();
}

void deleteRecord()
{
    int deleteId;
    printf(CYAN "\n--- Delete Record ---\n" RESET);
    printf("Enter Record ID to delete: ");
    scanf("%d", &deleteId);
    
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen(TEMP_FILE, "w");
    
    if (fp == NULL || temp == NULL)
    {
        printf(RED "Error: Cannot open files!\n" RESET);
        if (fp) fclose(fp);
        if (temp) fclose(temp);
        pauseScreen();
        return;
    }
    
    char line[500];
    TravelRecord record;
    int found = 0;
    
    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d,%[^,],%[^,],%[^,],%f,%f,%f,%f",
                   &record.id, record.customerName, record.destination, record.date,
                   &record.distance, &record.farePerKm, &record.gstPercent, &record.totalAmount) == 8)
        {
            if (record.id == deleteId)
            {
                found = 1;
                printf("Deleted Record: %s -> %s (Rs. %.2f)\n",
                       record.customerName, record.destination, record.totalAmount);
            }
            else
            {
                fprintf(temp, "%d,%s,%s,%s,%.2f,%.2f,%.2f,%.2f\n",
                        record.id, record.customerName, record.destination, record.date,
                        record.distance, record.farePerKm, record.gstPercent, record.totalAmount);
            }
        }
    }
    
    fclose(fp);
    fclose(temp);
    
    if (found)
    {
        remove(FILE_NAME);
        rename(TEMP_FILE, FILE_NAME);
        printf(GREEN "Record deleted successfully!\n" RESET);
    }
    else
    {
        remove(TEMP_FILE);
        printf(RED "Record with ID %d not found!\n" RESET, deleteId);
    }
    
    pauseScreen();
}

void showSummary()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        printf(RED "No records found!\n" RESET);
        pauseScreen();
        return;
    }
    
    char line[500];
    TravelRecord record;
    int count = 0;
    float totalRevenue = 0, totalDistance = 0, totalGST = 0;
    
    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d,%[^,],%[^,],%[^,],%f,%f,%f,%f",
                   &record.id, record.customerName, record.destination, record.date,
                   &record.distance, &record.farePerKm, &record.gstPercent, &record.totalAmount) == 8)
        {
            totalRevenue += record.totalAmount;
            totalDistance += record.distance;
            float baseAmount = record.distance * record.farePerKm;
            totalGST += baseAmount * (record.gstPercent / 100);
            count++;
        }
    }
    
    fclose(fp);
    
    printf(CYAN "\n--- Business Summary ---\n" RESET);
    printf("Total Records: %d\n", count);
    printf("Total Revenue: Rs. %.2f\n", totalRevenue);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total GST Collected: Rs. %.2f\n", totalGST);
    printf("Average Revenue per Trip: Rs. %.2f\n", count > 0 ? totalRevenue / count : 0);
    printf("Average Distance per Trip: %.2f km\n", count > 0 ? totalDistance / count : 0);
    
    pauseScreen();
}

void generateInvoice()
{
    int invoiceId;
    printf(CYAN "\n--- Generate Invoice ---\n" RESET);
    printf("Enter Record ID for invoice: ");
    scanf("%d", &invoiceId);
    
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        printf(RED "No records found!\n" RESET);
        pauseScreen();
        return;
    }
    
    char line[500];
    TravelRecord record;
    int found = 0;
    
    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d,%[^,],%[^,],%[^,],%f,%f,%f,%f",
                   &record.id, record.customerName, record.destination, record.date,
                   &record.distance, &record.farePerKm, &record.gstPercent, &record.totalAmount) == 8)
        {
            if (record.id == invoiceId)
            {
                found = 1;
                break;
            }
        }
    }
    
    fclose(fp);
    
    if (!found)
    {
        printf(RED "Record with ID %d not found!\n" RESET, invoiceId);
        pauseScreen();
        return;
    }
    
    // Generate invoice
    printf("\n");
    printf("========================================\n");
    printf("           TRAVEL INVOICE\n");
    printf("========================================\n");
    printf("Invoice ID: INV-%d\n", record.id);
    printf("Date: %s\n", record.date);
    printf("----------------------------------------\n");
    printf("Customer: %s\n", record.customerName);
    printf("Destination: %s\n", record.destination);
    printf("----------------------------------------\n");
    printf("Distance: %.2f km\n", record.distance);
    printf("Rate per km: Rs. %.2f\n", record.farePerKm);
    
    float baseAmount = record.distance * record.farePerKm;
    float gstAmount = baseAmount * (record.gstPercent / 100);
    
    printf("Base Amount: Rs. %.2f\n", baseAmount);
    printf("GST (%.1f%%): Rs. %.2f\n", record.gstPercent, gstAmount);
    printf("----------------------------------------\n");
    printf("TOTAL AMOUNT: Rs. %.2f\n", record.totalAmount);
    printf("========================================\n");
    printf("    Thank you for your business!\n");
    printf("========================================\n");
    
    pauseScreen();
}

void createBackup()
{
    FILE *source = fopen(FILE_NAME, "r");
    if (source == NULL)
    {
        printf(RED "No data to backup!\n" RESET);
        pauseScreen();
        return;
    }
    
    char backupName[100];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    sprintf(backupName, "backup_%04d%02d%02d_%02d%02d%02d.csv",
            tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
            tm->tm_hour, tm->tm_min, tm->tm_sec);
    
    FILE *backup = fopen(backupName, "w");
    if (backup == NULL)
    {
        printf(RED "Error creating backup!\n" RESET);
        fclose(source);
        pauseScreen();
        return;
    }
    
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), source))
    {
        fputs(buffer, backup);
    }
    
    fclose(source);
    fclose(backup);
    
    printf(GREEN "Backup created: %s\n" RESET, backupName);
    pauseScreen();
}

int getNextId()
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) return 1;
    
    char line[500];
    int maxId = 0, id;
    
    while (fgets(line, sizeof(line), fp))
    {
        if (sscanf(line, "%d,", &id) == 1)
        {
            if (id > maxId) maxId = id;
        }
    }
    
    fclose(fp);
    return maxId + 1;
}

void getCurrentDate(char* buffer)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    sprintf(buffer, "%04d-%02d-%02d", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pauseScreen()
{
    printf("\nPress Enter to continue...");
    getchar();
}