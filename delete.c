#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

extern node *head;

void delete_contact(void)
{
    if (head == NULL)
    {
        printf("the database is empty, nothing to delete\n");
        return;
    }

    char target[100];
    printf("enter the name of the contact to delete: ");
    scanf(" %[^\n]", target);

    node *temp = head;
    node *prev = NULL;

    //1.Search for the node by name
    while (temp != NULL && strcmp(temp->data.name, target) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("contact not found!\n");
        return;
    }
    
    //2. if found then 
    // Unlink node from the linked list
    if (prev == NULL)
    {
        head = temp->next; //deleting the head node
    }
    else
    {
        prev->next = temp->next; // Deleting a middle or tail node
    }

    free(temp);
    printf("contact deleted from memory successfully\n");

    //3. Automatically make the changes to database.txt file
    save_contact_to_file();
}

