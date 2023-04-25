// edit and search for contacts using a linked list
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

void add(contact *prevPtr, contact **headPtr);
int removeContact(contact *headPtr);
int editContact(contact *headPtr);
int searchContacts(contact *headPtr);

int main(void){
    contact* prevPtr = NULL; // Start with a first pointer.
    contact* headPtr = NULL; // The Start of our list
    char userDirection[3];
    while(strcmp(userDirection, "q") != 0){
        printf("What would you like to do:\n'a': add Contact\t'r': remove Contact\t'e': edit Contact");
        fgets(userDirection, sizeof(userDirection), stdin);
        userDirection[strcspn(userDirection, "\n")] = '\0';
        if(strcmp(userDirection, "a") == 0){
            add(prevPtr, &headPtr);    
        } 
        else if(strcmp(userDirection, "r") == 0){
            removeContact(headPtr);
        }
        else if(strcmp(userDirection, "e") == 0){
            editContact(headPtr);
        }
        else if(strcmp(userDirection, "s") == 0){
            searchContacts(headPtr);
        }
    }

    contact* indexPtr = headPtr;
    while(indexPtr != NULL){
        printf("%s\n", indexPtr->name);
        indexPtr = indexPtr->next;
    }

    printf("Thank you for adding contacts!\n");
    return 0; 
}


void add(contact *prevPtr, contact **headPtr){

    bool addContact = true; 

    while(addContact == true){
        contact* currptr = (contact*) malloc((sizeof(contact))); // Allocate memory for a new contact and create new struct to use
        if (currptr == NULL){
            printf("Cannot allocate memory!");
            exit(0);
        }

        printf("Please Enter a Name: ");
        fgets(currptr->name, sizeof(currptr->name), stdin);

        printf("Please Enter a Phone: ");
        fgets(currptr->phone, sizeof(currptr->phone), stdin);

        printf("Please Enter a Email: ");
        fgets(currptr->email, sizeof(currptr->email), stdin);

        currptr->next = NULL;

        if(prevPtr != NULL){
            prevPtr->next = currptr;
        }
        if(*headPtr == NULL){ // First Contact
            *headPtr = currptr;
            currptr->isHead = true;
        } else {
            currptr->isHead = false;
        }
    
        prevPtr = currptr;
        
        printf("\nWould you lke to add another contact?(y/n): ");
        char addAnother[4];
        fgets(addAnother, sizeof(addAnother), stdin);
        addAnother[strcspn(addAnother, "\n")] = '\0';
        if (strcmp(addAnother, "n") == 0){
            addContact = false;
        }
    } 

    return;
}

int removeContact(contact *headPtr){
    if (headPtr == NULL){
        printf("No Contacts to remove\n");
        return 1;
    } 
    char userDirection[3];
    char dummy[100];
    contact *indexPtr = headPtr;
    contact *prevPtr = NULL;

    while(strcmp(userDirection, "q") != 0){
        printf("%s", indexPtr->name);
        fgets(userDirection, sizeof(userDirection), stdin);
        userDirection[strcspn(userDirection, "\n")] = '\0';
        if(strcmp(userDirection, "n") == 0){
            prevPtr = indexPtr;
            if(indexPtr->next != NULL){
                indexPtr = indexPtr->next;
            } else {
                indexPtr = headPtr;
            }
        } else if(strcmp(userDirection, "q") == 0){ // Maybe remove this if I find there is some code we always want executed at the end of the loop
            return 0;
        } else if(strcmp(userDirection, "rm") == 0){
            if(indexPtr->isHead == 1){
                contact *tempPtr = indexPtr->next; // Set up temp PTR
                indexPtr = tempPtr;
                indexPtr->isHead = true; // Set is Head to True on next Node
                free(headPtr); // Free this space
                *headPtr = *indexPtr; // Set headPtr to new head.
            } else {
                prevPtr->next = indexPtr->next; // Make previous pointer point to next Pointer
                free(indexPtr);
                indexPtr = indexPtr->next; 
            }
            fgets(dummy, sizeof(dummy), stdin);    // Clears \n from stream so it's not 
        } else {
            printf("Not a valid Comand, %s", userDirection);
        }
    }
    return 1;
}

int editContact(contact *headPtr){
    printf("Edit Contact");
    return 0;
}

int searchContacts(contact *headPtr){
    printf("Search Contact");
    return 0; 
}