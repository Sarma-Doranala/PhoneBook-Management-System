#include<stdio.h>
#include<string.h>
#include "contact.h"
#include<stdlib.h>

node *head = NULL;
int main()
{
    load_contacts();
    printf("--------------------------------------------------\n");
    printf("SNO  option     action\n");
    printf("--------------------------------------------------\n");
    printf("1     C         create a new contact\n");
    printf("2     P         print the contact database\n");
    printf("3     D         delete the particular contact\n");
    printf("4     F         find the particular contact\n");
    printf("5     E         edit the contaact\n");
    printf("6     S         save the contact in database\n");
    printf("7     Q         Quit the APP\n");
    printf("--------------------------------------------------\n");
    char choice;
    //printf("Select the action : ");
    //scanf(" %c",&choice);
    //load_contacts();
    while(1)
    {
        printf("select the action : ");
        scanf(" %c",&choice);
        switch(choice)
        {
            case 'C':
            case 'c':
                 create_contact();
                 //printf("-----------------------------------------------------");
                 break;

            case 'P':
            case 'p':
                 print_contact();
                 //printf("-----------------------------------------------------");
                 break;

            case 'D':
            case 'd':
                 delete_contact();
                 //printf("-----------------------------------------------------");
                 break;

            case 'F':
            case 'f':
                 find_contact();
                 //printf("-----------------------------------------------------");
                 break;

            case 'E':
            case 'e':
                 edit_contact();
                 //printf("-----------------------------------------------------");
                 break;

            case 'S':
            case 's':
                 save_contact();
                 //printf("-----------------------------------------------------");
                 break;

            case 'Q':
            case 'q':
                 printf("saving and quiting the app\n");
                 //save_contact();
                 //printf("-----------------------------------------------------");
                 exit(0);

            default:
                 printf("Invalid option entered please tyr again\n");
                 while (getchar() != '\n' && getchar() != EOF);
                 //printf("-----------------------------------------------------");
                 break;
        }
    }
}


