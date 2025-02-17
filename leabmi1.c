#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define FILENAME "bmi_records.txt"

// Function Prototypes
void calculateBMI();
void displayRecords();
void searchRecord();
float calculateBMIValue(float weight, float height);

int main() {
    int choice;

    while (1) {
        printf("\n===== BMI Calculator =====\n");
        printf("1. Calculate BMI\n");
        printf("2. View BMI Records\n");
        printf("3. Search Record by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear input buffer

        switch (choice) {
            case 1:
                calculateBMI();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                printf("Exiting... Stay Healthy!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void calculateBMI() {
    char name[MAX_NAME_LEN];
    float weight, height_cm, height_m, bmi;

    printf("\nEnter your name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove newline character

    printf("Enter your weight (in kg): ");
    while (scanf("%f", &weight) != 1 || weight <= 0) {
        printf("Invalid input. Please enter a valid positive weight: ");
        while (getchar() != '\n');
    }

    printf("Enter your height (in cm): ");
    while (scanf("%f", &height_cm) != 1 || height_cm <= 0) {
        printf("Invalid input. Please enter a valid positive height in cm: ");
        while (getchar() != '\n');
    }

    height_m = height_cm / 100.0;
    bmi = calculateBMIValue(weight, height_m);

    printf("\n==== BMI Results for %s ====\n", name);
    printf("Your BMI: %.2f\n", bmi);
    if (bmi < 18.5) {
        printf("Category: Underweight\nRecommendation: Eat more nutritious food.\n");
    } else if (bmi >= 18.5 && bmi < 24.9) {
        printf("Category: Normal weight\nRecommendation: Keep up your healthy lifestyle!\n");
    } else if (bmi >= 25 && bmi < 29.9) {
        printf("Category: Overweight\nRecommendation: Exercise and balanced diet.\n");
    } else {
        printf("Category: Obese\nRecommendation: Consult a healthcare provider.\n");
    }

    FILE *file = fopen(FILENAME, "a");  // Append mode
    if (file == NULL) {
        printf("Error: Could not open file for saving records.\n");
        return;
    }
    fprintf(file, "%s %.2f %.2f %.2f\n", name, weight, height_m, bmi);
    fclose(file);
    printf("BMI record saved successfully!\n");
}

void displayRecords() {
    char name[MAX_NAME_LEN];
    float weight, height, bmi;

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\n==== BMI Records ====\n");
    int recordCount = 0;
    while (fscanf(file, "%s %f %f %f", name, &weight, &height, &bmi) == 4) {
        printf("Name: %s | Weight: %.2f kg | Height: %.2f m | BMI: %.2f\n", name, weight, height, bmi);
        recordCount++;
    }

    if (recordCount == 0) {
        printf("No records to display.\n");
    }
    fclose(file);
}

void searchRecord() {
    char searchName[MAX_NAME_LEN];
    char name[MAX_NAME_LEN];
    float weight, height, bmi;
    int found = 0;

    printf("\nEnter the name to search for: ");
    fgets(searchName, MAX_NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  // Remove newline character

    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\n==== Search Results for %s ====\n", searchName);
    while (fscanf(file, "%s %f %f %f", name, &weight, &height, &bmi) == 4) {
        if (strcmp(name, searchName) == 0) {
            printf("Name: %s | Weight: %.2f kg | Height: %.2f m | BMI: %.2f\n", name, weight, height, bmi);
            found = 1;
        }
    }

    if (!found) {
        printf("No records found for %s.\n", searchName);
    }
    fclose(file);
}

float calculateBMIValue(float weight, float height) {
    return weight / (height * height);
}

