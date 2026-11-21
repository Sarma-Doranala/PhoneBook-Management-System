#ifndef CONTACT_H
#define CONTACT_H

typedef struct
{
    char name[100];
    char phone_number[5][20];
    int count;
    char email[100];
    char address[200];
} contact;

typedef struct Node
{
    contact data;
    struct Node *next;
} node;

void create_contact(void);
void print_contact(void);
void load_contacts(void);
int check_duplicate(char *, char [][20], int);
void delete_contact(void);
void find_contact(void);
void edit_contact(void);
void save_contact(void);
void save_contact_to_file(void);

#endif

