#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contact.h"

extern node *head;

void create_contact(void)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("memory allocation failed\n");
        return;
    }
    newnode->next = NULL;
    newnode->data.count = 0;

    // Clear buffers
    memset(newnode->data.name, 0, sizeof(newnode->data.name));
    memset(newnode->data.email, 0, sizeof(newnode->data.email));
    memset(newnode->data.address, 0, sizeof(newnode->data.address));
    for (int i = 0; i < 5; i++)
    {
        memset(newnode->data.phone_number[i], 0, sizeof(newnode->data.phone_number[i]));
    }

    // 1. Collect Name
    printf("enter the name : ");
    scanf(" %[^\n]", newnode->data.name);

    // 2. Collect First Phone Number
    printf("enter the phone number : ");
    scanf(" %[^\n]", newnode->data.phone_number[0]);
    newnode->data.count = 1;

    // Collect additional phone numbers (up to 5)
    char choice;
    while (newnode->data.count < 5)
    {
        printf("do you want to add another number to the same contact :(Y/N) : ");
        scanf(" %c", &choice);
        if (choice == 'Y' || choice == 'y')
        {
            printf("enter the %d phone number : ", newnode->data.count + 1);
            scanf(" %[^\n]", newnode->data.phone_number[newnode->data.count]);
            newnode->data.count++;
        }
        else
        {
            break;
        }
    }

    // 3. Verify Duplicates (Name & Phone Numbers) BEFORE saving or finalizing
    int dup_result = check_duplicate(newnode->data.name, newnode->data.phone_number, newnode->data.count);
    if (dup_result == 1)
    {
        printf("error: contact with this name already exists\n");
        free(newnode);
        return;
    }
    else if (dup_result == 2)
    {
        printf("error: one of these phone numbers already belongs to another contact\n");
        free(newnode);
        return;
    }

    // 4. Optional Email Address
    printf("do you want to enter the email address :(Y/N): ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y')
    {
        printf("enter the email address : ");
        scanf(" %[^\n]", newnode->data.email);
    }

    // 5. Optional Address
    printf("do you want to enter the address :(Y/N): ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y')
    {
        printf("enter the address : ");
        scanf(" %[^\n]", newnode->data.address);
    }

    // 6. add the new entered contact in to the file
    // and the '-' indicate no data or information entered
    FILE *fp = fopen("database.txt", "a");
    if (fp == NULL)
    {
        printf("error opening database file\n");
        free(newnode);
        return;
    }

    fprintf(fp, "%s ", newnode->data.name);
    
    for (int i = 0; i < newnode->data.count; i++)
    {
        fprintf(fp, "%s ", newnode->data.phone_number[i]);
    }

    if (strlen(newnode->data.email) > 0)
    {
        fprintf(fp, "%s ", newnode->data.email);
    }
    else
    {
        fprintf(fp, "- "); 
    }

    if (strlen(newnode->data.address) > 0)
    {
        fprintf(fp, "%s", newnode->data.address);
    }
    else
    {
        fprintf(fp, "-"); 
    }

    fprintf(fp, "\n");
    fclose(fp);

    // 7. Attach to the Linked List in memory
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    printf("creation of the contact is completed\n");
}

