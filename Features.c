#include "Header.h"

/* Function for create new contact.*/
void Create_Contact(AddressBook *Details)
{
    char Name[50];
    int conferm;
    // While loop to get name until it's valid.
    while (1)
    {
        printf("Enter Name : ");
        getchar();
        scanf("%[^\n]", Name);
        if (Name[0] == '\0') /* If entered string is blank then go to main menu.*/
            return;
        if (Is_Valid_Name(Name))
        {
            printf("Valid Name\n");
            printf("Conferm to add Name\n1. Save | 2. Cancel\n");
            scanf("%d", &conferm);
            if (conferm == 1) /* Confermation to save or not.*/
            {
                strcpy(Details->Book[Details->Contact_count].name, Name);
                printf("Name is added successfully!\n");
            }
            else
            {
                printf("Name addition canceled!\n");
                continue;
            }
            break;
        }
        else
        {
            printf("Invalid Name please Re-Enter.\n");
        }
    }

    /* Menu for adding further details OR exit to main menu.*/
    while (1)
    {
        printf("|-----Add Contact Menu-----|\n");
        printf("1. Add Details\n2. Exit to main menu\n");
        int Option;
        int exit_flag = 0;
        scanf("%d", &Option);
        if (Option == 1)
        {
            while (1)
            {
                /* Menu for add details.*/
                printf("|-----Add Details Menu-----|\n");
                printf("1. Add Mobile Number\n2. Add Email Address\n3. Exit To 'Add Contact Menu'\n");
                scanf("%d", &Option);
                switch (Option)
                {
                case 1:
                    // While loop to get mobile number until it's valid.
                    char Mobile[40];
                    while (1)
                    {
                        getchar();
                        printf("Enter Mobile Number : ");
                        scanf("%s", Mobile);
                        if (Is_Valid_Mobile_Number(Mobile))
                        {
                            printf("Valid Mobile Number.\n");
                            printf("Conferm to add Number\n1. Save | 2. Cancel\n");
                            scanf("%d", &conferm);
                            if (conferm == 1) /* Confermation to save or not.*/
                            {
                                strcpy(Details->Book[Details->Contact_count].mobile, Mobile);
                                printf("Mobile number is added successfully!\n");
                            }
                            else
                            {
                                printf("Mobile number addition chanceled!\n");
                                continue;
                            }
                            break;
                        }
                        else
                        {
                            printf("Invalid Mobile Number Re-Enter.\n");
                        }
                    }
                    break;
                case 2:
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
                            printf("Valid Email\n");
                            printf("Conferm to add\n1. Save | 2. Chancel\n");
                            scanf("%d", &conferm);
                            if (conferm == 1) /* Confermation to save or not.*/
                            {
                                strcpy(Details->Book[Details->Contact_count].email, str);
                                printf("Email address is added successfully!\n");
                            }
                            else
                            {
                                printf("Email address addition canceled!\n");
                                continue;
                            }
                            break;
                        }
                        else
                        {
                            printf("Invalid Email Re-Enter.\n");
                        }
                    }
                    break;
                default:
                    exit_flag = 1;
                }

                if (exit_flag != 0) /* This flag is for exit from the while loop of 'Add Details Menu' and go to 'Add Contact Menu' */
                {
                    exit_flag = 0;
                    break;
                }
            }
        }
        else
        {
            Details->Contact_count++;
            return;
        }
    }
}
/*................................................................*/
/*  Functiion for search contact.*/
void Search_Contact(AddressBook *Details)
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
                    break;
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
                    break;
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
                    break;
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
void Edit_Contact(AddressBook *Details)
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
void Save_Contact(AddressBook *Details)
{
    FILE *file = fopen("Contact_Book.csv", "w");
    int i;
    if (file == NULL)
    {
        printf("Error File Opening Failed.\n");
        return;
    }

    fprintf(file, "==================================================================\n");
    fprintf(file, "| %-5s | %-15s | %-15s | %-20s |\n", "Sr.No", "Name", "Mobile number", "Email address");
    fprintf(file, "==================================================================\n");
    for (i = 0; i < Details->Contact_count; i++)
    {
        fprintf(file, "| %-5d | %-15s | %-15s | %-20s |\n", i + 1, Details->Book[i].name, Details->Book[i].mobile, Details->Book[i].email);
        fprintf(file, "---------------------------------------------------------------\n");
    }
    fclose(file);
    printf("Contacts saved in Contact Diary.\n");
}
/*................................................................*/
/* Function for save contact.*/
void Load_Contact(AddressBook *Details)
{
    FILE *file = fopen("Contact_Book.csv", "r");
    int i = 0;
    if (file == NULL)
    {
        printf("Error : No existing contact file found.\n");
        return;
    }

    char line[200];
    int Sr_index;
    int Input_Count;
    /* Skip border lines.*/
    fgets(line, sizeof(line), file);
    fgets(line, sizeof(line), file);
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file))
    {
          if (line[0] == '=' || line[0] == '-')
            continue;
        Input_Count = sscanf(line, "| %d | %[^|] | %[^|] | %[^|] |",
                             &Sr_index,
                             Details->Book[i].name,
                             Details->Book[i].mobile,
                             Details->Book[i].email);

        if (Input_Count == 1 || Input_Count == 4)
        {
            i++;
        }
    }

    Details->Contact_count = i;
    fclose(file);
    printf("Contacts Lode successfully.\n");
}
/*................................................................*/
/* Function for delete contact.*/
void Delete_Contact(AddressBook *Details)
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
                    break;
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
                    break;
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
                    break;
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
void Display_Contact(AddressBook *Details)
{
    // int index = Details->Contact_count - 1;

    printf("==================================================================\n");
    printf("| %-5s | %-15s | %-15s | %-20s |\n", "Sr.No", "Name", "Mobile number", "Email address");
    printf("==================================================================\n");
    for (int i = 0; i < Details->Contact_count; i++)
    {
        printf("| %-5d | %-15s | %-15s | %-20s |\n", i + 1, Details->Book[i].name, Details->Book[i].mobile, Details->Book[i].email);
        printf("---------------------------------------------------------------\n");
    }
}
/*................................................................*/
/* Function for exit from AddressBook.*/
void Exit_Contact(AddressBook *Details)
{
    printf("Exit from contacts,\n");
    exit(0);
}