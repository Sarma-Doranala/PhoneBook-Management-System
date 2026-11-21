#include<stdio.h>
#include<string.h>
#include"contact.h"
extern node *head;
void print_contact(void)
{
    node *temp = head;
    if(head == NULL)
    {
        printf("the list is empty\n");
        return;
    }
    while(temp != NULL)
    {
        printf("\n----------------------------------------------------------\n");
        printf("the name : %s\n",temp->data.name);
        printf("the phone numbers :\n ");
        for(int i=0;i<(temp->data.count);i++)
        {
            printf(" %d - %s\n",i+1,temp->data.phone_number[i]);
        }
        if(temp->data.email[0] != '\0')
        {
            printf("the email : %s\n",temp->data.email);
        }
        else
        {
            printf("----no email-------\n");
        }
        if(temp->data.address[0] != '\0')
        {
            printf("the address : %s\n",temp->data.address);
        }
        else
        {
            printf("-----no address------\n");
        }
        printf("\n----------------------------------------------------------\n");
        temp = temp->next;
    }
}


            
