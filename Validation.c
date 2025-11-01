#include "Header.h"
/*  Function to validate name.*/
int Is_Valid_Name(char *Name)
{

    int Valid = 1;
    int Atleast_one_letter = 0;
    int i;
    for (i = 0; Name[i] != '\0'; i++)
    {
        if (isalpha(Name[i])) // unsigned char because isalpha() expect an argument that fits in an unsigned char i.e.0-255.
        {
            Atleast_one_letter = 1; // Found at least one letter.
        }
        else if (!isspace(Name[i]))
        {
            Valid = 0; // Invalide character found.
            break;
        }
    }
    if (Valid && Atleast_one_letter)
    {
        for (int i = 0; i < Details.Contact_count; i++)
        {
            if (strcmp(Details.Book[i].name, Name) == 0)
            {
                printf("The name is already exist in contact book (Select option to overwrite or cancel!).\n");
                printf("1. Press 1 for (Overwrite)\n2. Press 2 for (Cancel to re-enter name)\n");
                int option;
                scanf("%d", &option);
                if (option == 1)
                {
                    Exist_Index = i;
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

/*  Function to validate mobile number.*/
int Is_Valid_Mobile_Number(char *Mobile)
{
    if (strlen(Mobile) != 10)
        return 0;

    int i;
    for (i = 0; Mobile[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)Mobile[i])) // unsigned char because isdigit() expect an argument that fits in an unsigned char i.e.0-255.
        {
            return 0;
        }
    }
    for (int i = 0; i < Details.Contact_count; i++)
    {
        if (strcmp(Details.Book[i].mobile, Mobile) == 0)
        {
            printf("The mobile is already exist in contact book (Select option to overwrite or cancel!).\n");
            printf("1.  Press 1 for (Overwrite)\n2. Press 2 for (Cancel to re-enter mobile)\n");
            int Option;
            scanf("%d", &Option);
            if (Option == 1)
            {
                Exist_Index = i;
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}

/*  Function to validate email address.*/
int Is_Valid_Email(char *Email)
{
    if (strchr(Email, '@') == NULL || strchr(Email, '.') == NULL)
    {
        return 0;
    }
    char *Token;
    int i, Token_count = 0;
    Token = strtok(Email, "@.");
    if (Token == NULL)
        return 0;
    for (i = 0; Token[i] != '\0'; i++)
    {
        if (!isdigit(Token[i]) && !islower(Token[i]))
        {
            return 0;
        }
    }
    Token = strtok(NULL, "@.");
    while (Token != NULL)
    {
        Token_count++;
        for (i = 0; Token[i] != '\0'; i++)
        {
            if (islower(Token[i]) == 0)
            {
                return 0;
            }
        }
        if (Token_count == 2)
        {
            for (int i = 0; i < Details.Contact_count; i++)
            {
                if (strcmp(Details.Book[i].email, Email) == 0)
                {
                    printf("The email is already exist in contact book (Select option to overwrite or cancel!).\n");
                    printf("1.  Press 1 for (Overwrite)\n2. Press 2 for (Cancel to re-enter email)\n");
                    int Option;
                    scanf("%d", &Option);
                    if (Option == 1)
                    {
                        Exist_Index = i;
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
            return 1;
        }
        Token = strtok(NULL, "@.");
    }
    return 0;
}