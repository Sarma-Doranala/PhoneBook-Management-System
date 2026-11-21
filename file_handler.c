#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contact.h"

extern node *head;

void load_contacts(void)
{
    FILE *fp = fopen("database.txt", "r");
    if (fp == NULL)
    {
        return; // File doesn't exist yet on first run
    }

    char line[512];
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // Remove trailing newline characters
        line[strcspn(line, "\r\n")] = '\0';
        if (strlen(line) == 0) continue;

        node *newnode = (node *)malloc(sizeof(node));
        if (newnode == NULL) break;

        newnode->next = NULL;
        newnode->data.count = 0;
        memset(&newnode->data, 0, sizeof(contact));

        // Tokenize the line by spaces
        char *tokens[50];
        int token_count = 0;
        char *token = strtok(line, " ");
        while (token != NULL && token_count < 50)
        {
            tokens[token_count++] = token;
            token = strtok(NULL, " ");
        }

        if (token_count < 2)
        {
            free(newnode);
            continue;
        }

        // Find email position (contains '@' or equals '-')
        int email_idx = -1;
        for (int i = 1; i < token_count; i++)
        {
            if (strchr(tokens[i], '@') != NULL || strcmp(tokens[i], "-") == 0)
            {
                email_idx = i;
                break;
            }
        }

        if (email_idx != -1)
        {
            // Find where phone number(s) start (first numeric token before email)
            int phone_start = -1;
            for (int i = 0; i < email_idx; i++)
            {
                int is_num = 1;
                for (int c = 0; tokens[i][c] != '\0'; c++)
                {
                    if (tokens[i][c] < '0' || tokens[i][c] > '9')
                    {
                        is_num = 0;
                        break;
                    }
                }
                if (is_num)
                {
                    phone_start = i;
                    break;
                }
            }

            if (phone_start != -1)
            {
                // 1. Reconstruct Name (everything before the phone number)
                char name_buf[100] = "";
                for (int i = 0; i < phone_start; i++)
                {
                    strcat(name_buf, tokens[i]);
                    if (i < phone_start - 1) strcat(name_buf, " ");
                }
                strcpy(newnode->data.name, name_buf);

                // 2. Load Phone Numbers (from phone_start up to email_idx)
                int p_count = 0;
                for (int i = phone_start; i < email_idx && p_count < 5; i++)
                {
                    strcpy(newnode->data.phone_number[p_count], tokens[i]);
                    p_count++;
                }
                newnode->data.count = p_count;

                // 3. Load Email (if not a dash marker)
                if (strcmp(tokens[email_idx], "-") != 0)
                {
                    strcpy(newnode->data.email, tokens[email_idx]);
                }

                // 4. Load Address (everything after email_idx, if not a dash marker)
                if (token_count > email_idx + 1)
                {
                    if (strcmp(tokens[email_idx + 1], "-") != 0)
                    {
                        char addr_buf[200] = "";
                        for (int i = email_idx + 1; i < token_count; i++)
                        {
                            strcat(addr_buf, tokens[i]);
                            if (i < token_count - 1) strcat(addr_buf, " ");
                        }
                        strcpy(newnode->data.address, addr_buf);
                    }
                }
            }
        }

        // Attach newnode to the end of the linked list in memory
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
    }

    fclose(fp);
}
   

