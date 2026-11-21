#include <stdio.h>
#include <string.h>
#include "contact.h"

extern node *head;

int check_duplicate(char *name, char new_phone[][20], int new_count)
{
    node *temp = head;
    while(temp != NULL)
    {
        // 1. Check if the name matches
        if(strcmp(temp->data.name, name) == 0)
        {
            return 1; // Duplicate name found
        }

        // 2. Check if any phone number matches existing contacts
        for(int i = 0; i < temp->data.count; i++)
        {
            for(int j = 0; j < new_count; j++)
            {
                if(strcmp(temp->data.phone_number[i], new_phone[j]) == 0)
                {
                    return 2; // Duplicate phone number found
                }
            }
        }

        temp = temp->next;
    }
    return 0; // No duplicates found
}

