#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct() {
    FILE *f = fopen("inventory.dat", "ab");
    if (!f) {
        printf("Unable to open file!\n");
        return;
    }

    Product p;
    printf("Enter Product ID: ");
    scanf("%d", &p.id);
    getchar(); // clear newline
    printf("Enter Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;
    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter Price: ");
    scanf("%f", &p.price);

    fwrite(&p, sizeof(Product), 1, f);
    fclose(f);
    printf("✅ Product added successfully!\n");
}

void displayProducts() {
    FILE *f = fopen("inventory.dat", "rb");
    if (!f) {
        printf("No products found.\n");
        return;
    }

    Product p;
    printf("\n--- Inventory ---\n");
    while (fread(&p, sizeof(Product), 1, f)) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n", p.id, p.name, p.quantity, p.price);
    }
    fclose(f);
}

void searchProduct() {
    FILE *f = fopen("inventory.dat", "rb");
    if (!f) {
        printf("No products found.\n");
        return;
    }

    int id;
    printf("Enter Product ID to search: ");
    scanf("%d", &id);

    Product p;
    int found = 0;
    while (fread(&p, sizeof(Product), 1, f)) {
        if (p.id == id) {
            printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n", p.id, p.name, p.quantity, p.price);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Product not found.\n");

    fclose(f);
}

void updateProduct() {
    FILE *f = fopen("inventory.dat", "rb+");
    if (!f) {
        printf("No products found.\n");
        return;
    }

    int id;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);

    Product p;
    int found = 0;
    while (fread(&p, sizeof(Product), 1, f)) {
        if (p.id == id) {
            found = 1;
            printf("Enter new Name: ");
            getchar();
            fgets(p.name, sizeof(p.name), stdin);
            p.name[strcspn(p.name, "\n")] = 0;
            printf("Enter new Quantity: ");
            scanf("%d", &p.quantity);
            printf("Enter new Price: ");
            scanf("%f", &p.price);

            fseek(f, -sizeof(Product), SEEK_CUR);
            fwrite(&p, sizeof(Product), 1, f);
            printf("✅ Product updated successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Product not found.\n");

    fclose(f);
}

void deleteProduct() {
    FILE *f = fopen("inventory.dat", "rb");
    if (!f) {
        printf("No products found.\n");
        return;
    }

    int id;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);

    FILE *temp = fopen("temp.dat", "wb");
    Product p;
    int found = 0;

    while (fread(&p, sizeof(Product), 1, f)) {
        if (p.id != id) {
            fwrite(&p, sizeof(Product), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(f);
    fclose(temp);

    remove("inventory.dat");
    rename("temp.dat", "inventory.dat");

    if (found)
        printf("✅ Product deleted successfully!\n");
    else
        printf("Product not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n====== Inventory Management System ======\n");
        printf("1. Add Product\n2. Display Products\n3. Search Product\n4. Update Product\n5. Delete Product\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: searchProduct(); break;
            case 4: updateProduct(); break;
            case 5: deleteProduct(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 6);

    return 0;
}
