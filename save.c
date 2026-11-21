#include <stdio.h>
#include <string.h>
#include "contact.h"

extern node *head;

// Core function that completely overwrites database.txt with current memory list
void save_contact_to_file(void)
{
    FILE *fp = fopen("database.txt", "w"); // "w" clears the old file and writes fresh
    if (fp == NULL)
    {
        printf("error opening database file for saving\n");
        return;
    }

    node *temp = head;
    while (temp != NULL)
    {
        // 1. Print Name
        fprintf(fp, "%s ", temp->data.name);
        
        // 2. Print Phone Numbers
        for (int i = 0; i < temp->data.count; i++)
        {
            fprintf(fp, "%s ", temp->data.phone_number[i]);
        }

        // 3. Print Email (or dash marker if empty)
        if (strlen(temp->data.email) > 0)
        {
            fprintf(fp, "%s ", temp->data.email);
        }
        else
        {
            fprintf(fp, "- ");
        }

        // 4. Print Address (or dash marker if empty)
        if (strlen(temp->data.address) > 0)
        {
            fprintf(fp, "%s", temp->data.address);
        }
        else
        {
            fprintf(fp, "-");
        }

        fprintf(fp, "\n");
        temp = temp->next;
    }

    fclose(fp);
}

// Menu wrapper function for case 's' / 'S'
void save_contact(void)
{
    save_contact_to_file();
    printf("all contacts saved successfully to database.txt\n");
}
