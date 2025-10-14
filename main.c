#include "Header.h"

int main()
{
    int choice;
    struct addressBook Details;
    Details.Book = NULL;
    Details.Contact_count = 0;
    printf("Menu of functions : \n");
    printf("===================\n");
    printf("1. Create Contact\n2. Save Contact\n3. Search Contact\n4. Edit Contact\n5. Delete Contact\n6. Display Contact\n7. Exit\n");
    printf("===================\n");
    while (1)
    {

        printf("Read user choice.\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
    
        switch (choice)
        {
            case 1:
            Create_Contact(&Details);
            // printf("Create Contact\n");
            break;
    
            case 2:
            Display_Contact(&Details);
            // printf("Save Contact\n");
            break;
        }
    }
    return 0;
}