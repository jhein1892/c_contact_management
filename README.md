
# Contact Management Program
This program is a simple command-line interface for managing a list of contacts. It allows you to add, remove, edit, and search for contacts using a linked list.

## How to Use
To use the program, simply compile and run the source code using a C compiler such as GCC. Upon running, you will be presented with a menu of options:

- a: add a new contact
- r: remove a contact
- e: edit a contact
- s: search for a contact
- q: quit the program
To select an option, enter the corresponding letter and press Enter. Follow the prompts to perform the desired action.

## Data Structure
The program uses a linked list data structure to store the contacts. Each contact is represented by a contact struct, which contains fields for the contact's name, phone number, email address, and a pointer to the next contact in the list.

When a new contact is added, the program allocates memory for a new contact struct and adds it to the end of the list. When a contact is removed, the program frees the memory used by the corresponding contact struct and updates the next pointer of the previous contact struct to point to the next contact struct in the list.

## Functions
The program contains several functions to perform the various actions on the linked list:

- add: adds a new contact to the list
- scrollContacts: scrolls through the list of contacts until a specified trigger is hit
- removeContact: removes a contact from the list
- editContact: allows the user to edit the details of a contact
- searchContacts: searches for a contact by name
Each function is implemented using standard C library functions and basic string manipulation.

## Limitations
The program has several limitations that should be addressed in a more robust contact management system:

The program does not provide any validation of input data
The program does not persist the contact list between runs
The program does not provide any sorting or filtering of the contact list

Despite these limitations, the program serves as a simple example of how linked lists can be used to manage data in a program.