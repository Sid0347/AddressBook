#include "Header.h"
/* Function for create new contact.*/
void Create_Contact(struct addressBook *Details)
{
    Details->Contact_count++;
    int index = Details->Contact_count - 1;
    Details->Book = realloc(Details->Book, Details->Contact_count * sizeof(struct contact));
    
    if (Details->Book == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter name of student : ");
    scanf("%s", Details->Book[index].name);
    printf("Enter mobile number : ");
    scanf("%s", Details->Book[index].mobile);
    printf("Enter email address : ");
    scanf("%s", Details->Book[index].email);
}

/* Fuction for display contact.*/
void Display_Contact(struct addressBook *Details)
{
    // int index = Details->Contact_count - 1;
    printf("=======================================================\n");
    printf("| %-15s | %-15s | %-15s |\n", "Name", "Mobile number", "Email address");
    printf("=======================================================\n");
    for (int i = 0; i < Details->Contact_count; i++)
    {
        printf("| %-15s | %-15s | %-15s |\n", Details->Book[i].name, Details->Book[i].mobile, Details->Book[i].email);
        printf("-------------------------------------------------------\n");
    }
    // printf("Name : %s\n", Details->Book[index].name);
    // printf("Mobile number : %s\n", Details->Book[index].mobile);
    // printf("Email address : %s\n", Details->Book[index].email);
}