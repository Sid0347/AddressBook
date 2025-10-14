#include <stdio.h>
#include <stdlib.h>
#define size 20
#define count 100
struct contact
{
    char name[size];
    char mobile[14];
    char email[20];
};

struct addressBook
{
    struct contact *Book;
    int Contact_count;
};

void Create_Contact(struct addressBook *Details);
void Display_Contact(struct addressBook *Details);