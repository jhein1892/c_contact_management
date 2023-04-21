// Build a simple text-based contact management system that allows users to add, edit, delete, and search for contacts using a linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    char name[50];
    char phone[20];
    char email[40];
    struct node * next; // creating a pointer called next
} contact;

int main(void){
    bool newContact = true; 
    contact* currptr; // Start with a first pointer.

    while(newContact == true){
        currptr = (contact*) malloc((sizeof(contact))); // Allocate memory for a new contact
        if (currptr == NULL){
            printf("Cannot allocate memory!");
            exit(0);
        }
        
        
        











        // contact first_contact;
        // char name[50];
        // char addMore[1];
        // printf("Please Enter your first contact's name: ");
        // fgets(name, sizeof(name), stdin);
        // strcpy(first_contact.name, name);
        // printf("Name: %s\n", first_contact.name);
        // printf("Would you like to add another contact?(y/n) ");
        // scanf("%c", addMore);

        // if (strcmp(addMore, "n\n") == 0){
        //     newContact = false;
        // } else {

        // }
    } 


    printf("Thank you for adding contacts!");
    return 0; 
}