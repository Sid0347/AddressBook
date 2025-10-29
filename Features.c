#include "Header.h"

/* Function for create new contact.*/
void Create_Contact(struct addressBook *Details)
{
    char Name[50];
    // While loop to get name until it's valid.
    while (1)
    {
        printf("Enter Name : ");
        getchar();
        scanf("%s", Name);
        if (Is_Valid_Name(Name))
        {
            strcpy(Details->Book[Details->Contact_count].name, Name);
            printf("Valid Name\n");
            break;
        }
        else
        {
            printf("Invalid Name.\n");
        }
    }

    // While loop to get mobile number until it's valid.
    char Mobile[14];
    while (1)
    {
        getchar();
        printf("Enter Mobile Number : ");
        scanf("%s", Mobile);
        if (Is_Valid_Mobile_Number(Mobile))
        {
            strcpy(Details->Book[Details->Contact_count].mobile, Mobile);
            printf("Valid Mobile Number.\n");
            break;
        }
        else
        {
            printf("Invalid Mobile Number.\n");
        }
    }

    // While loop to get email address until it's valid.
    char Email[50];
    char str[50];
    while (1)
    {
        printf("Enter email address : ");
        getchar();
        scanf("%s", Email);
        strcpy(str, Email);
        if (Is_Valid_Email(Email))
        {
            strcpy(Details->Book[Details->Contact_count].email, str);
            printf("Valid Email\n");
            break;
        }
        else
        {
            printf("Invalid Email\n");
        }
    }

    Details->Contact_count++;
}
/*................................................................*/
/*  Functiion for search contact.*/
void Search_Contact(struct addressBook *Details)
{
    int i, choice;
    int Found_Flag = 0;
    char Search_Name[20];
    char Search_Number[20];
    char Search_Email[50];

    while (1)
    {
        printf("1. Name\n2. Mobile Number.\n3. Email\n4. Go Back To Main Menu\n");
        printf("Enter mode of search :\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the name to search : ");
            scanf("%s", Search_Name);

            for (i = 0; i < Details->Contact_count; i++)
            {
                if (strcmp(Details->Book[i].name, Search_Name) == 0)
                {
                    printf("=======================================================\n");
                    printf("| %-15s | %-15s | %-15s |\n", "Name", "Mobile number", "Email address");
                    printf("=======================================================\n");
                    printf("| %-15s | %-15s | %-15s |\n", Details->Book[i].name, Details->Book[i].mobile, Details->Book[i].email);
                    printf("-------------------------------------------------------\n");
                    Found_Flag = 1;
                }
            }
            if (!Found_Flag)
                printf("Invalid name search.\n");
            break;

        case 2:
            printf("Enter number to search : ");
            scanf("%s", Search_Number);

            for (i = 0; i, Details->Contact_count; i++)
            {
                if (strcmp(Details->Book[i].mobile, Search_Number) == 0)
                {
                    printf("=======================================================\n");
                    printf("| %-15s | %-15s | %-15s |\n", "Name", "Mobile number", "Email address");
                    printf("=======================================================\n");
                    printf("| %-15s | %-15s | %-15s |\n", Details->Book[i].name, Details->Book[i].mobile, Details->Book[i].email);
                    printf("-------------------------------------------------------\n");
                    Found_Flag = 1;
                }
            }
            if (!Found_Flag)
                printf("Invalid numbr to search.\n");
            break;

        case 3:
            printf("Enter email to search : ");
            scanf("%s", Search_Email);

            for (i = 0; i, Details->Contact_count; i++)
            {
                if (strcmp(Details->Book[i].email, Search_Email) == 0)
                {
                    printf("=======================================================\n");
                    printf("| %-15s | %-15s | %-15s |\n", "Name", "Mobile number", "Email address");
                    printf("=======================================================\n");
                    printf("| %-15s | %-15s | %-15s |\n", Details->Book[i].name, Details->Book[i].mobile, Details->Book[i].email);
                    printf("-------------------------------------------------------\n");
                    Found_Flag = 1;
                }
            }
            if (!Found_Flag)
                printf("Invalid email to search.\n");
            break;
        case 4:
            printf("Returen to main menu.\n");
            return;
        default:
            printf("Invalid Search Mode.\n");
            break;
        }
    }
}
/*................................................................*/
/* Function for edit contact.*/
void Edit_Contact(struct addressBook *Details)
{
    int i, Found_Count = -1;
    char Name[20];
    printf("Enter name to edit contact : ");
    scanf("%s", Name);

    for (i = 0; i < Details->Contact_count; i++)
    {
        if (strcmp(Details->Book[i].name, Name) == 0)
        {
            Found_Count = i;
            break;
        }
    }
    if (Found_Count == -1)
    {
        printf("ERROR : Contact not found.\n");
        return;
    }

    printf("Contact information to edit.\n");
    printf("=======================================================\n");
    printf("| %-15s | %-15s | %-15s |\n", "Name", "Mobile number", "Email address");
    printf("=======================================================\n");
    printf("| %-15s | %-15s | %-15s |\n", Details->Book[Found_Count].name, Details->Book[Found_Count].mobile, Details->Book[Found_Count].email);
    printf("-------------------------------------------------------\n");

    int choice;
    char Edit_Name[20], Edit_Mobile[20], Edit_Email[50];
    printf("Please Enter choice according to what you want to edit.\n");
    printf("1. Name\n2. Mobile\n3. Email\n4. All Details\n");

    printf("Enter choice to edit : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        while (1)
        {
            printf("Enter Name : ");
            getchar();
            scanf("%s", Edit_Name);
            if (Is_Valid_Name(Edit_Name))
            {
                strcpy(Details->Book[Found_Count].name, Edit_Name);
                printf("Name changed\n");
                break;
            }
            else
            {
                printf("Invalid Name.\n");
            }
        }
        break;
    case 2:
        while (1)
        {
            getchar();
            printf("Enter Mobile Number : ");
            scanf("%s", Edit_Mobile);
            if (Is_Valid_Mobile_Number(Edit_Mobile))
            {
                strcpy(Details->Book[Found_Count].mobile, Edit_Mobile);
                printf("Mobile Number Changed.\n");
                break;
            }
            else
            {
                printf("Invalid Mobile Number.\n");
            }
        }
        break;
    case 3:
        while (1)
        {
            char Edit_str[50];
            printf("Enter email address : ");
            getchar();
            scanf("%s", Edit_Email);
            strcpy(Edit_str, Edit_Email);
            if (Is_Valid_Email(Edit_Email))
            {
                strcpy(Details->Book[Found_Count].email, Edit_str);
                printf("Valid Email\n");
                break;
            }
            else
            {
                printf("Invalid Email\n");
            }
        }
        break;
    case 4:
        while (1)
        {
            printf("Enter Name : ");
            getchar();
            scanf("%s", Edit_Name);
            if (Is_Valid_Name(Edit_Name))
            {
                strcpy(Details->Book[Found_Count].name, Edit_Name);
                printf("Name changed\n");
                break;
            }
            else
            {
                printf("Invalid Name.\n");
            }
        }

        while (1)
        {
            getchar();
            printf("Enter Mobile Number : ");
            scanf("%s", Edit_Mobile);
            if (Is_Valid_Mobile_Number(Edit_Mobile))
            {
                strcpy(Details->Book[Found_Count].mobile, Edit_Mobile);
                printf("Mobile Number Changed.\n");
                break;
            }
            else
            {
                printf("Invalid Mobile Number.\n");
            }
        }

        while (1)
        {
            char Edit_str[50];
            printf("Enter email address : ");
            getchar();
            scanf("%s", Edit_Email);
            strcpy(Edit_str, Edit_Email);
            if (Is_Valid_Email(Edit_Email))
            {
                strcpy(Details->Book[Found_Count].email, Edit_str);
                printf("Valid Email\n");
                break;
            }
            else
            {
                printf("Invalid Email\n");
            }
        }
        break;
    default:
        printf("Invalid Choice.\n");
        break;
    }
}
/*................................................................*/
/* Function for save contact.*/
void Save_Contact(struct addressBook *Details)
{
    FILE *file = fopen("Contact_Diary.txt", "w");
    int i;
    if(file == NULL)
    {
        printf("Error File Opening Failed.\n");
        return;
    }

    for (i = 0; i <Details->Contact_count; i++)
    {
        fprintf(file,"%-15s %-15s %-20s\n", Details->Book[i].name, Details->Book[i].mobile, Details->Book[i].email);
    }
    fclose(file);
    printf("Contacts saved in Contact Diary.\n");
}
/*................................................................*/
/* Function for delete contact.*/
void Delete_Contact(struct addressBook *Details)
{
    int i, choice;
    int Search_Flag = 0;
    int Delete_Flag = 0;
    char Delete_Name[20];
    char Delete_Number[20];
    char Delete_Email[50];

    while (1)
    {
        printf("1. Name\n2. Mobile Number.\n3. Email\n4. Go Back To Main Menu\n");
        printf("Enter mode of search to delete contact :\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the name to delete : ");
            scanf("%s", Delete_Name);

            for (i = 0; i < Details->Contact_count; i++)
            {
                if (strcmp(Details->Book[i].name, Delete_Name) == 0)
                {
                    Search_Flag = 1;
                    Delete_Flag = 1;
                }
            }
            if (!Search_Flag)
                printf("Invalid name search.\n");
            break;

        case 2:
            printf("Enter number to delete : ");
            scanf("%s", Delete_Number);

            for (i = 0; i, Details->Contact_count; i++)
            {
                if (strcmp(Details->Book[i].mobile, Delete_Number) == 0)
                {
                    Search_Flag = 1;
                    Delete_Flag = 1;
                }
            }
            if (!Search_Flag)
                printf("Invalid numbr to search.\n");
            break;

        case 3:
            printf("Enter email to delete : ");
            scanf("%s", Delete_Email);

            for (i = 0; i, Details->Contact_count; i++)
            {
                if (strcmp(Details->Book[i].email, Delete_Email) == 0)
                {
                    Search_Flag = 1;
                    Delete_Flag = 1;
                }
            }
            if (!Search_Flag)
                printf("Invalid email to search.\n");
            break;
        case 4:
            printf("Returen to main menu.\n");
            return;
        default:
            printf("Invalid Search Mode.\n");
            break;
        }
        if (Delete_Flag)
        {
            for (int j = i; j < Details->Contact_count - 1; j++)
            {
                Details->Book[j] = Details->Book[j + 1];
            }
            Details->Contact_count--;
            printf("The contact is deleted successfully.\n");
            return;
        }
    }
}
/*................................................................*/
/* Fuction for display contact address book.*/
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
}
/*................................................................*/
/* Function for exit from AddressBook.*/
void Exit_Contact(struct addressBook *Details)
{
    printf("Exit from contacts,\n");
    exit(0);
}