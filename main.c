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
contact* scrollContacts(contact **headPtr, contact **prevPtr, char trigger[3]); 
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

contact* scrollContacts(contact **headPtr, contact **prevPtr, char trigger[3]){
    char userDirection[3];
    char dummy[100];

    contact *indexPtr = *headPtr;

    while(strcmp(userDirection, trigger) != 0){ // Cycle through the contacts until we hit our trigger
        printf("%s", indexPtr->name);
        fgets(userDirection, sizeof(userDirection), stdin);
        userDirection[strcspn(userDirection, "\n")] = '\0';

        if(strcmp(userDirection, "n") == 0){
            *prevPtr = indexPtr;
            if(indexPtr->next != NULL){
                indexPtr = indexPtr->next;
            } else {
                indexPtr = *headPtr;
            }
        }
        else if (strcmp(userDirection, trigger) == 0){
            return indexPtr;
        } 
        else if (strcmp(userDirection, "q") == 0) {
            return 0;
        } 
        else {
            printf("Command not Recognized");
        }
    }

    return NULL;
}

// Implemented
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

// Implemented
int removeContact(contact *headPtr){
    if (headPtr == NULL){
        printf("No Contacts to remove\n");
        return 1;
    } 
    char userDirection[3];
    char dummy[100];
    contact *prevPtr = NULL;
    contact *removePtr = scrollContacts(&headPtr, &prevPtr, "rm");

    if(removePtr == 0){
        return 0;
    } else {
        if(removePtr->isHead == 1){
            removePtr = removePtr->next;
            removePtr->isHead = true;
            *headPtr = *removePtr;
        } else {
            prevPtr->next = removePtr->next;
            free(removePtr);
        }
        fgets(dummy, sizeof(dummy), stdin);    // Clears \n from stream so it's not 
    }
    return 1;
}


int editContact(contact *headPtr){
    printf("Edit Contact");
    return 0;
    //
}


int searchContacts(contact *headPtr){
    printf("Search Contact");
    return 0; 
}