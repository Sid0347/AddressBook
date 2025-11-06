#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define size 50
#define count 100
typedef struct contact
{
    char name[size];
    char mobile[size];
    char email[size];
}Contact;

typedef struct addressBook
{
    Contact Book[count];
    int Contact_count;
}AddressBook;

extern AddressBook Details;

// Feature functions of the Address Book.
void Load_Contact(AddressBook *Details);
void Create_Contact(AddressBook *Details);
void Search_Contact(AddressBook *Details);
void Edit_Contact(AddressBook *Details);
void Save_Contact(AddressBook *Details);
void Delete_Contact(AddressBook *Details);
void Display_Contact(AddressBook *Details);
void Exit_Contact(AddressBook *Details);


// Validation Fuctions.
int Is_Valid_Name(char *Name);
int Is_Valid_Mobile_Number(char *Mobile);
int Is_Valid_Email(char *Email);

#endif