// Build a simple text-based contact management system that allows users to add, edit, delete, and search for contacts using a linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    char name[50];
    char phone[20];
    char email[40];
    bool isHead;
    struct node * next; // creating a pointer called next
} contact;

int main(void){
    bool addContact = true; 
    contact* prevPtr = NULL; // Start with a first pointer.
    contact* headPtr = NULL; // The Start of our list

    while(addContact == true){
        char inputName[50];
        char inputPhone[20];
        char inputEmail[40];

        contact* currptr = (contact*) malloc((sizeof(contact))); // Allocate memory for a new contact and create new struct to use
        if (currptr == NULL){
            printf("Cannot allocate memory!");
            exit(0);
        }
        printf("Please Enter a Name: ");
        fgets(inputName, sizeof(inputName), stdin);
        strcpy(currptr->name, inputName);

        printf("Please Enter a Phone: ");
        fgets(inputPhone, sizeof(inputPhone), stdin);
        strcpy(currptr->phone, inputPhone);

        printf("Please Enter a Email: ");
        fgets(inputEmail, sizeof(inputEmail), stdin);
        strcpy(currptr->email, inputEmail);

        currptr->next = NULL;

        if(prevPtr!= NULL){
            prevPtr->next = currptr;
        }
        if(headPtr == NULL){ // First Contact
            headPtr = currptr;
        } else {
            currptr->isHead = false;
        }
    
        prevPtr = currptr;
        printf("Name: %s\nEmail: %s\nPhone: %s\nPtr: %p\n", currptr->name, currptr->email, currptr->phone, currptr);

        printf("\nWould you lke to add another contact?(y/n): ");
        char addAnother[4];
        fgets(addAnother, sizeof(addAnother), stdin);
        addAnother[strcspn(addAnother, "\n")] = '\0';
        if (strcmp(addAnother, "n") == 0){
            addContact = false;
        }
    } 
    contact* indexPtr = headPtr;
    while(indexPtr != NULL){
        printf("%s\n", indexPtr->name);
        indexPtr = indexPtr->next;
    }

    // printf("PrevPointer: %p\n", prevPtr);
    printf("Thank you for adding contacts!\n");
    return 0; 
}