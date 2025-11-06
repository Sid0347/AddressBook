#include "Header.h"
AddressBook Details;

int main()
{
    Details.Contact_count = 0;
    int choice;

    Load_Contact(&Details);
    while (1)
    {
        printf("|--------- Address Book ---------|\n");
        printf("=================================\n");
        printf("1. Create Contact\n2. Search Contact\n3. Edit Contact\n4. Save Contact\n5. Delete Contact\n6. Display Contact\n7. Exit\n");
        printf("=================================\n");

        printf("Read user choice.\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Create_Contact(&Details);
            break;

        case 2:
            Search_Contact(&Details);
            break;

        case 3:
            Edit_Contact(&Details);
            break;

        case 4:
            Save_Contact(&Details);
            break;

        case 5:
            Delete_Contact(&Details);
            break;

        case 6:
            Display_Contact(&Details);
            break;

        case 7:
            Exit_Contact(&Details);
            break;
        }
    }
    return 0;
}