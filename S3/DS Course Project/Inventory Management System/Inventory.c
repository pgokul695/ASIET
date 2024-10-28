#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct Product {
    int id;
    char name[50];
    char category[30];
    float price;
    int quantity;
    struct Product *next;
} Product;

Product* head = NULL;
Product* productArray[MAX_PRODUCTS];
int productCount = 0;
int autosort = 0;
int isSorted = 0;

void addProduct();
void updateProduct(int id);
void deleteProduct(int id);
void displayProducts();
void saveData();
void loadData();
void sortInventory();
int linearSearch(int id);
int binarySearch(int id);
void mergeSort(Product* array[], int left, int right);
void merge(Product* array[], int left, int mid, int right);
void toggleAutoSort();
void searchProduct(int id);
void sellProduct(int id, int quantity);
void restockInventory(int id);

void addProduct() {
    Product *newProduct = (Product *)malloc(sizeof(Product));
    Product *temp;

    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full!\n");
        return;
    }

    printf("Enter Product ID: ");
    scanf("%d", &newProduct->id);
    printf("Enter Product Name: ");
    scanf("%s", newProduct->name);
    printf("Enter Product Category: ");
    scanf("%s", newProduct->category);
    printf("Enter Product Price: ");
    scanf("%f", &newProduct->price);
    printf("Enter Product Quantity: ");
    scanf("%d", &newProduct->quantity);
    
    newProduct->next = head;
    head = newProduct;
    
    productArray[productCount] = newProduct;
    productCount++;

    if (autosort) {
        int i = productCount - 1;
        while (i > 0 && productArray[i]->id < productArray[i - 1]->id) {
            temp = productArray[i];
            productArray[i] = productArray[i - 1];
            productArray[i - 1] = temp;
            i--;
        }
        isSorted = 1;
    } else {
        isSorted = 0;
    }

    printf("Product Added Successfully!\n");
}

void updateProduct(int id) {
    int index = (isSorted) ? binarySearch(id) : linearSearch(id);
    if (index == -1) {
        printf("Product not found.\n");
        return;
    }

    Product *current = productArray[index];
    char name[50];
    char category[30];
    float price;
    int quantity;
    char input[50];

    printf("Current Name (%s), enter new name (leave blank to skip): ", current->name);
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        sscanf(input, "%49[^\n]", name);
        strcpy(current->name, name);
    }

    printf("Current Category (%s), enter new category (leave blank to skip): ", current->category);
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        sscanf(input, "%29[^\n]", category);
        strcpy(current->category, category);
    }

    printf("Current Price (%.2f), enter new price (leave blank to skip): ", current->price);
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        sscanf(input, "%f", &price);
        current->price = price;
    }

    printf("Current Quantity (%d), enter new quantity (leave blank to skip): ", current->quantity);
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        sscanf(input, "%d", &quantity);
        current->quantity = quantity;
    }

    if (autosort) {
        sortInventory();
    } else {
        isSorted = 0;
    }

    printf("Product Updated Successfully!\n");
}


void deleteProduct(int id) {
    int index = (isSorted) ? binarySearch(id) : linearSearch(id);
    if (index == -1) {
        printf("Product not found.\n");
        return;
    }

    for (int i = index; i < productCount - 1; i++) {
        productArray[i] = productArray[i + 1];
    }
    productCount--;

    if (!autosort) {
        isSorted = 0;
    }

    printf("Product Deleted Successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        Product *temp = productArray[i];
        if (temp) {
            printf("ID: %d, Name: %s, Category: %s, Price: %.2f, Quantity: %d\n",
               temp->id, temp->name, temp->category, temp->price, temp->quantity);
        } else {
            printf("Error: Invalid product pointer at index %d\n", i);
        }
    }
}

void saveData() {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < productCount; i++) {
        Product *current = productArray[i];
        fprintf(file, "%d %s %s %.2f %d\n", current->id, current->name, current->category, current->price, current->quantity);
    }
    fclose(file);
    printf("Data saved successfully!\n");
}

void loadData() {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("No previous data found!\n");
        return;
    }

    productCount = 0;
    Product *newProduct;

    while (productCount < MAX_PRODUCTS) {
        newProduct = (Product *)malloc(sizeof(Product));
        if (fscanf(file, "%d %49s %29s %f %d", &newProduct->id, newProduct->name, newProduct->category, &newProduct->price, &newProduct->quantity) == 5) {
            newProduct->next = head;
            head = newProduct;
            productArray[productCount] = newProduct;
            productCount++;
        } else {
            free(newProduct);
            break;
        }
    }
    fclose(file);
    printf("Data loaded successfully! %d products.\n", productCount);
}

void toggleAutoSort() {
    autosort = !autosort;
    if (autosort) {
        printf("Autosort is now ON.\n");
        sortInventory();
    } else {
        printf("Autosort is now OFF.\n");
    }
}

int linearSearch(int id) {
    for (int i = 0; i < productCount; i++) {
        if (productArray[i]->id == id) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int id) {
    int left = 0, right = productCount - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (productArray[mid]->id == id) {
            return mid;
        }
        if (productArray[mid]->id < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void searchProduct(int id) {
    int index = (isSorted) ? binarySearch(id) : linearSearch(id);
    if (index == -1) {
        printf("Product not found.\n");
    } else {
        Product *product = productArray[index];
        printf("Found Product - ID: %d, Name: %s, Category: %s, Price: %.2f, Quantity: %d\n",
               product->id, product->name, product->category, product->price, product->quantity);
    }
}

void sellProduct(int id, int quantity) {
    int index = (isSorted) ? binarySearch(id) : linearSearch(id);
    if (index == -1) {
        printf("Product not found.\n");
        return;
    }

    Product *product = productArray[index];
    if (quantity > product->quantity) {
        printf("Insufficient stock.\n");
    } else {
        product->quantity -= quantity;
        printf("Product %s sold, remaining stock: %d\n", product->name, product->quantity);
    }
}

void restockInventory(int id) {
    int index = (isSorted) ? binarySearch(id) : linearSearch(id);
    if (index == -1) {
        printf("Product not found.\n");
        return;
    }

    Product *product = productArray[index];
    printf("Enter quantity to add for product %s (ID: %d): ", product->name, product->id);
    int quantity;
    scanf("%d", &quantity);
    product->quantity += quantity;
    printf("Product %s restocked to %d units.\n", product->name, product->quantity);
}

void sortInventory() {
    mergeSort(productArray, 0, productCount - 1);
    isSorted = 1;
}

void mergeSort(Product* array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void merge(Product* array[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Product* L[n1], *R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i]->id <= R[j]->id) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

int main() {
    int choice, id, quantity;
    loadData();

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Product\n2. Update Product\n3. Delete Product\n4. Display Products\n5. Search Product\n");
        printf("6. Sell Product\n7. Restock Product\n8. Toggle Autosort\n9. Save Data\n10. Load Data\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                printf("Enter Product ID to update: ");
                scanf("%d", &id);
                updateProduct(id);
                break;
            case 3:
                printf("Enter Product ID to delete: ");
                scanf("%d", &id);
                deleteProduct(id);
                break;
            case 4:
                displayProducts();
                break;
            case 5:
                printf("Enter Product ID to search: ");
                scanf("%d", &id);
                searchProduct(id);
                break;
            case 6:
                printf("Enter Product ID to sell: ");
                scanf("%d", &id);
                printf("Enter quantity to sell: ");
                scanf("%d", &quantity);
                sellProduct(id, quantity);
                break;
            case 7:
                printf("Enter Product ID to restock: ");
                scanf("%d", &id);
                restockInventory(id);
                break;
            case 8:
                toggleAutoSort();
                break;
            case 9:
                saveData();
                break;
            case 10:
                loadData();
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

