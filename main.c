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

void add(contact *prevPtr, contact **headPtr);
int removeContact(contact *headPtr);

int main(void){
    contact* prevPtr = NULL; // Start with a first pointer.
    contact* headPtr = NULL; // The Start of our list
    char userDirection[3];
    while(strcmp(userDirection, "q") != 0){
        printf("What would you like to do:\n'a': add Contact\t'r': remove Contact\n");
        fgets(userDirection, sizeof(userDirection), stdin);
        userDirection[strcspn(userDirection, "\n")] = '\0';
        if(strcmp(userDirection, "a") == 0){
            add(prevPtr, &headPtr);    
        } 
        if(strcmp(userDirection, "r") == 0){
            removeContact(headPtr);
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
    
    contact *indexPtr = headPtr;
    while(indexPtr != NULL){
        printf("%s", indexPtr->name);
        indexPtr = indexPtr->next;
    }


    return 0;
    
    // When user clicks on remove we should start circling through the contacts
    // If user hits down arrow, then we should go to next, up arrow goes back
    // If user hits next and we have next == NULL, then we go back to head.
    // If user hits 'q' then we quit and go back to main
    // if user types 'rm' then we delete that contact
        // We need to store the prevPtr so that when we delete, we are able to reference it and set its next value to the deleted contact's next value.

}