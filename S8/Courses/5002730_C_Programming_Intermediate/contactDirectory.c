#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 300

// Structure to store contact information
typedef struct {
    char lastName[50];
    char firstName[50];
    char phoneNumber[20];
} Contact;

// Function to display the menu and get the user's choice
int displayMenu() {
    int choice;
    printf("\n--- MENU ---\n");
    printf("1. Display contact list\n");
    printf("2. Add a contact\n");
    printf("3. Delete a contact\n");
    printf("4. Modify a contact\n");
    printf("5. Search for a contact\n");
    printf("6. Quit and Save\n");
    printf("Choice: ");
    scanf("%d", &choice);
    getchar();  // Capture the newline character
    return choice;
}

// Function to add a contact
void addContact(Contact* contacts, int* numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("The directory is full. Cannot add a new contact.\n");
        return;
    }

    Contact newContact;

    printf("Last Name: ");
    fgets(newContact.lastName, sizeof(newContact.lastName), stdin);
    newContact.lastName[strcspn(newContact.lastName, "\n")] = '\0';
    for (int i = 0; newContact.lastName[i] != '\0'; i++) {
        newContact.lastName[i] = toupper(newContact.lastName[i]);
    }

    printf("First Name: ");
    fgets(newContact.firstName, sizeof(newContact.firstName), stdin);
    newContact.firstName[strcspn(newContact.firstName, "\n")] = '\0';

    printf("Phone Number: ");
    fgets(newContact.phoneNumber, sizeof(newContact.phoneNumber), stdin);
    newContact.phoneNumber[strcspn(newContact.phoneNumber, "\n")] = '\0';

    // Check if the contact already exists in the directory (same lastName and firstName)
    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(contacts[i].lastName, newContact.lastName) == 0 && strcmp(contacts[i].firstName, newContact.firstName) == 0) {
            printf("This contact already exists in the directory.\n");
            return;
        }
    }

    // Validate the phone number format
    int validNumber = 1;
    for (int i = 0; newContact.phoneNumber[i] != '\0'; i++) {
        if (!(isdigit(newContact.phoneNumber[i]) || newContact.phoneNumber[i] == '+' || newContact.phoneNumber[i] == '-' || newContact.phoneNumber[i] == ' ')) {
            validNumber = 0;
            break;
        }
    }

    if (!validNumber) {
        printf("Invalid phone number format. The phone number should only contain numbers, ' ', '+' or '-' characters.\n");
        return;
    }

    // Add the new contact to the list
    contacts[*numContacts] = newContact;
    (*numContacts)++;

    printf("Contact added successfully.\n");
}

// Function to delete a contact
void deleteContact(Contact* contacts, int* numContacts) {
    char searchLastName[50];
    printf("Last Name of the contact to delete: ");
    fgets(searchLastName, sizeof(searchLastName), stdin); // Read the last name input from the user
    searchLastName[strcspn(searchLastName, "\n")] = '\0'; // Remove the trailing newline character from the last name
    for (int i = 0; searchLastName[i] != '\0'; i++) {
        searchLastName[i] = toupper(searchLastName[i]);  // Convert the last name to uppercase
    }

    int deleteIndex = -1;
    int numContactsSameLastName = 0;
    int matchingIndices[50];  // Array to store the indices of contacts with the same last name

    // Find the index of the contact to delete and collect the indices of contacts with the same last name
    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(contacts[i].lastName, searchLastName) == 0) {
            matchingIndices[numContactsSameLastName] = i;
            numContactsSameLastName++;
            if (deleteIndex == -1) {
                deleteIndex = i;
            }
        }
    }

    if (deleteIndex == -1) {
        printf("The contact \"%s\" does not exist in the directory.\n", searchLastName);
        return;
    }

    // If there are multiple contacts with the same last name, ask for the first name
    if (numContactsSameLastName > 1) {
        printf("\nThere are multiple contacts with the last name \"%s\".\n", searchLastName);
        printf("Please enter the First Name of the contact to delete: ");
        char searchFirstName[50];
        fgets(searchFirstName, sizeof(searchFirstName), stdin);
        searchFirstName[strcspn(searchFirstName, "\n")] = '\0';
        for (int i = 0; searchFirstName[i] != '\0'; i++) {
            searchFirstName[i] = toupper(searchFirstName[i]);  // Convert the first name to uppercase
        }

        // Find the contact with the matching first name and delete it
        for (int i = 0; i < numContactsSameLastName; i++) {
            int index = matchingIndices[i];
            if (strcmp(toupper(contacts[index].firstName), searchFirstName) == 0) {
                deleteIndex = index;
                break;
            }
        }
    }

    // Delete the contact by shifting the following contacts
    for (int i = deleteIndex; i < (*numContacts) - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    (*numContacts)--;
    printf("Contact deleted successfully.\n");
}


// Function to modify a contact
void modifyContact(Contact* contacts, int numContacts) {
    char searchLastName[50];
    printf("Last Name of the contact to modify: ");
    fgets(searchLastName, sizeof(searchLastName), stdin);
    searchLastName[strcspn(searchLastName, "\n")] = '\0';
    for (int i = 0; searchLastName[i] != '\0'; i++) {
        searchLastName[i] = toupper(searchLastName[i]);  // Convert the last name to uppercase
    }

    int modifyIndex = -1;
    int numContactsSameLastName = 0;
    int matchingIndices[50];  // Array to store the indices of contacts with the same last name

    // Find the index of the contact to modify and collect the indices of contacts with the same last name
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].lastName, searchLastName) == 0) {
            matchingIndices[numContactsSameLastName] = i;
            numContactsSameLastName++;
            if (modifyIndex == -1) {
                modifyIndex = i;
            }
        }
    }

    if (modifyIndex == -1) {
        printf("The contact \"%s\" does not exist in the directory.\n", searchLastName);
        return;
    }

    // If there are multiple contacts with the same last name, ask for the first name
    if (numContactsSameLastName > 1) {
        printf("There are multiple contacts with the last name \"%s\".\n", searchLastName);
        printf("Please enter the First Name of the contact to modify: ");
        char searchFirstName[50];
        fgets(searchFirstName, sizeof(searchFirstName), stdin);
        searchFirstName[strcspn(searchFirstName, "\n")] = '\0';
        for (int i = 0; searchFirstName[i] != '\0'; i++) {
            searchFirstName[i] = toupper(searchFirstName[i]);  // Convert the first name to uppercase
        }

        // Find the contact with the matching first name to modify
        for (int i = 0; i < numContactsSameLastName; i++) {
            int index = matchingIndices[i];
            if (strcmp(toupper(contacts[index].firstName), searchFirstName) == 0) {
                modifyIndex = index;
                break;
            }
        }
    }

    Contact* modifiedContact = &contacts[modifyIndex];

    printf("New Last Name (leave blank to not modify): ");
    char newLastName[50];
    fgets(newLastName, sizeof(newLastName), stdin);
    newLastName[strcspn(newLastName, "\n")] = '\0';
    for (int i = 0; newLastName[i] != '\0'; i++) {
        newLastName[i] = toupper(newLastName[i]);  // Convert the last name to uppercase
    }
    if (strlen(newLastName) > 0) {
        strncpy(modifiedContact->lastName, newLastName, sizeof(modifiedContact->lastName));
    }

    printf("New First Name (leave blank to not modify): ");
    char newFirstName[50];
    fgets(newFirstName, sizeof(newFirstName), stdin);
    newFirstName[strcspn(newFirstName, "\n")] = '\0';
    for (int i = 0; newFirstName[i] != '\0'; i++) {
        newFirstName[i] = newFirstName[i];
    }
    if (strlen(newFirstName) > 0) {
        strncpy(modifiedContact->firstName, newFirstName, sizeof(modifiedContact->firstName));
    }

    printf("New Phone Number (leave blank to not modify): ");
    fgets(modifiedContact->phoneNumber, sizeof(modifiedContact->phoneNumber), stdin);
    modifiedContact->phoneNumber[strcspn(modifiedContact->phoneNumber, "\n")] = '\0';

    printf("Contact modified successfully.\n");
}


// Function to search for a contact
void searchContact(Contact* contacts, int numContacts) {
    char searchLastName[50];
    printf("Last Name of the contact to search for: ");
    fgets(searchLastName, sizeof(searchLastName), stdin);
    searchLastName[strcspn(searchLastName, "\n")] = '\0';
    for (int i = 0; searchLastName[i] != '\0'; i++) {
        searchLastName[i] = toupper(searchLastName[i]);  // Convert the last name to uppercase
    }

    int contactFound = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].lastName, searchLastName) == 0) {
            printf("\n---------\n");
            printf("Last Name: %s\n", contacts[i].lastName);
            printf("First Name: %s\n", contacts[i].firstName);
            printf("Phone Number: %s\n", contacts[i].phoneNumber);
            printf("---------\n");
            contactFound = 1;
        }
    }

    if (!contactFound) {
        printf("The contact \"%s\" does not exist in the directory.\n", searchLastName);
    }
}

// Comparison function for alphabetical sorting of contacts by last name and first name
int compareContacts(const void* a, const void* b) {
    const Contact* contactA = (const Contact*)a;
    const Contact* contactB = (const Contact*)b;

    // Compare last names
    int lastNameComparison = strcmp(contactA->lastName, contactB->lastName);
    if (lastNameComparison != 0) {
        return lastNameComparison;
    }

    // If last names are the same, compare first names
    return strcmp(contactA->firstName, contactB->firstName);
}

// Function to display all contacts sorted in alphabetical order
void displayContacts(Contact* contacts, int numContacts) {
    if (numContacts == 0) {
        printf("The directory is empty.\n");
        return;
    }

    // Sort the contacts in alphabetical order
    qsort(contacts, numContacts, sizeof(Contact), compareContacts);

    printf("--- Contacts ---\n");
    for (int i = 0; i < numContacts; i++) {
        printf("\n---------\n");
        printf("Last Name: %s\n", contacts[i].lastName);
        printf("First Name: %s\n", contacts[i].firstName);
        printf("Phone Number: %s\n", contacts[i].phoneNumber);
        printf("---------\n");
    }
}

// Function to check if a string contains only letters
int isOnlyLetters(const char* string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (!isalpha(string[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a phone number is valid
int isValidPhoneNumber(const char* number) {
    if (number[0] != '+') {
        return 0;
    }

    for (int i = 1; number[i] != '\0'; i++) {
        if (!isdigit(number[i]) && number[i] != '-' && number[i] != '+') {
            return 0;
        }
    }
    return 1;
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    // Load contacts from file (if it exists)
    FILE* file = fopen("directory.txt", "r");
    if (file != NULL) {
        while (fread(&contacts[numContacts], sizeof(Contact), 1, file) == 1) {
            numContacts++;
        }
        fclose(file);
    }

    do {
        choice = displayMenu();

        switch (choice) {
            case 1:
                displayContacts(contacts, numContacts);
                break;
            case 2:
                addContact(contacts, &numContacts);
                break;
            case 3:
                deleteContact(contacts, &numContacts);
                break;
            case 4:
                modifyContact(contacts, numContacts);
                break;
            case 5:
                searchContact(contacts, numContacts);
                break;
            case 6:
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    // Save contacts to file
    file = fopen("directory.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < numContacts; i++) {
            fwrite(&contacts[i], sizeof(Contact), 1, file);
        }
        fclose(file);
    }

    printf("Program terminated. Thank you for using the phone directory.\n");

    return 0;
}
