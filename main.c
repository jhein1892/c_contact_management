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
    bool addContact = true; 
    contact* currptr; // Start with a first pointer.

    while(addContact == true){
        currptr = (contact*) malloc((sizeof(contact))); // Allocate memory for a new contact
        if (currptr == NULL){
            printf("Cannot allocate memory!");
            exit(0);
        }
        strcpy(currptr->name, "Jake Hein");
        strcpy(currptr->email, "email@email.com");
        strcpy(currptr->phone, "100-xxx-xxxx");
        currptr->next = NULL;


        printf("Name: %s\nEmail: %s\nPhone: %s\n", currptr->name, currptr->email, currptr->phone);
        addContact = false;
    } 


    printf("Thank you for adding contacts!");
    return 0; 
}