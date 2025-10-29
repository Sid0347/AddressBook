#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define size 50
#define count 100
struct contact
{
    char name[size];
    char mobile[size];
    char email[size];
};

struct addressBook
{
    struct contact Book[count];
    int Contact_count;
};

// Feature functions of the Address Book.
void Create_Contact(struct addressBook *Details);
void Search_Contact(struct addressBook *Details);
void Edit_Contact(struct addressBook *Details);
void Save_Contact(struct addressBook *Details);
void Delete_Contact(struct addressBook *Details);
void Display_Contact(struct addressBook *Details);
void Exit_Contact(struct addressBook *Details);

// Validation Fuctions.
int Is_Valid_Name(char *Name);
int Is_Valid_Mobile_Number(char *Mobile);
int Is_Valid_Email(char *Email);