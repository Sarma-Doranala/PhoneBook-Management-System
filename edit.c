#include <stdio.h>
#include <string.h>
#include "contact.h"

extern node *head;

void edit_contact(void)
{
    if (head == NULL)
    {
        printf("the database is empty\n");
        return;
    }
    
    //1. enter the name u want to edit
    char target[100];
    printf("enter the name of the contact you want to edit: ");
    scanf(" %[^\n]", target);

    node *temp = head;
    while (temp != NULL && strcmp(temp->data.name, target) != 0)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("contact not found!\n");
        return;
    }
    //2. if contact found then this are this are the options 
    //avaliable you need to select what you wnat to edit
    printf("contact found. what do you want to edit?\n");
    printf("1. Name\n"); //1 means edit name
    printf("2. Phone Number\n"); //2 means edit phone number
    printf("3. Email\n"); //3 means edit email 
    printf("4. Address\n"); //4 means edit address
    printf("enter your choice: ");
    
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("enter new name: ");
        scanf(" %[^\n]", temp->data.name);
    }
    else if (choice == 2)
    {
        //so if the contact has more than 1 number
        printf("this contact has %d phone number(s).\n", temp->data.count);
        for (int i = 0; i < temp->data.count; i++)
        {
            printf("  [%d] %s\n", i, temp->data.phone_number[i]);
        }
        //if will show the index number like (0 to 3) need to select which
        //phone you want to edit
        printf("enter index of phone number to edit (0 to %d): ", temp->data.count - 1);
        
        int idx;
        scanf("%d", &idx);
        if (idx >= 0 && idx < temp->data.count)
        {
            printf("enter new phone number: ");
            scanf(" %[^\n]", temp->data.phone_number[idx]);
        }
        else
        {
            printf("invalid phone index\n");
            return;
        }
    }
    else if (choice == 3)
    {
        printf("enter new email: ");
        scanf(" %[^\n]", temp->data.email);
    }
    else if (choice == 4)
    {
        printf("enter new address: ");
        scanf(" %[^\n]", temp->data.address);
    }
    else
    {
        printf("invalid choice\n");
        return;
    }

    printf("contact updated successfully in memory\n");

    // Automatically make the changes to database.txt file
    save_contact_to_file();
}

