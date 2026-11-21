#include <stdio.h>
#include <string.h>
#include "contact.h"

extern node *head;

void find_contact(void)
{
    if (head == NULL)
    {
        printf("the database is empty\n");
        return;
    }

    char query[100];
    printf("enter the name or phone number to search: ");
    scanf(" %[^\n]", query);

    node *temp = head;
    int found = 0;

    while (temp != NULL)
    {
        int match = 0;
        if (strcmp(temp->data.name, query) == 0)
        {
            match = 1;
        }
        else
        {
            for (int i = 0; i < temp->data.count; i++)
            {
                if (strcmp(temp->data.phone_number[i], query) == 0)
                {
                    match = 1;
                    break;
                }
            }
        }

        if (match)
        {
            printf("\n--- Contact Found ---\n");
            printf("the name : %s\n", temp->data.name);
            printf("the phone numbers :\n");
            for (int i = 0; i < temp->data.count; i++)
            {
                printf("  %d - %s\n", i + 1, temp->data.phone_number[i]);
            }
            printf("the email : %s\n", strlen(temp->data.email) > 0 ? temp->data.email : "---no email---");
            printf("the address : %s\n", strlen(temp->data.address) > 0 ? temp->data.address : "---no address---");
            printf("---------------------\n");
            found = 1;
        }
        temp = temp->next;
    }

    if (!found)
    {
        printf("no matching contact found.\n");
    }
}

