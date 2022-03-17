#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PhoneBook.h"


char temp=0;

void options(void)
{
    char choice=0;
    system("cls");
    printf("\n\t\t **** PHONEBOOK DATABASE SYSTEM ****");
    printf("\n\nOPTIONS:\n");
    printf("--------------------------------------------------------\n");
    printf("1.View All My contacts\t|\t5.Search By Phone Number \n\t\t\t|\n");
    printf("2.Add New Contact\t|\t6.Search By Name \n\t\t\t|\n");
    printf("3.Edit Contact   \t|\t7.Delete All Contacts \n\t\t\t|\n");
    printf("4.Delete Contact\t|\t8.Exit \n");
    printf("--------------------------------------------------------\n\n");
    printf("\nPlease Choose An Option ");

    fflush(stdin);
    scanf("%c",&choice);

    if((char)choice == '1')
    {
        view_my_contacts();
    }
    else if ((char)choice == '2')
    {
        add_contact();
    }
    else if ((char)choice == '3')
    {
       modify_contact();
    }
    else if ((char)choice == '4')
    {
        remove_contact();
    }
    else if ((char)choice == '5')
    {
        phone_search();
    }
    else if ((char)choice == '6')
    {
        name_search();
    }
    else if ((char)choice == '7')
    {
        delete_all();
    }
    else if ((char)choice == '8')
    {
        system("cls");
        printf("\n\t\t**** Student's Information ****\n\n");
        printf("\nStudent Name: Mohamed Yasser Mohamed");
        printf("\n\nSection: 2");
        printf("\n\nB.N.: 24");
        printf("\n\nThank You! (^_^)\n\n\n");
        exit(0);
    }
    else
    {
        system("cls");
        printf("\n\t**** ERROR: Please Choose An Option From 1 To 7 Only!! ****\n\n");
        printf("Press Any Key To Try Again: ");
        scanf("%c",&temp);
        options();
    }

}


void add_contact(void)
{
    /* clear screen */
    system("cls");
    /* create new variable name (nc) of type (newContact) struct */
    newContact nc;
    nc.name[0]='0';
    /* create pointer, which points to FILE */
    FILE *file_ptr;
    file_ptr = fopen("phonebook.text","ab+");
    /* if (file_ptr == NULL). It means no phonebook.text file. And we create it: */
    if(file_ptr == NULL)
    {
        system("cls");
        printf("\n\t\t\t**** ERORR:can't find phonebook.text file ****\n\n");
        printf("\nDo You Want To Create A New One? [Yes,No] ");
        char decision=0;
        scanf("%c",&decision);
        if( ((char)decision=='Y') || ((char)decision=='y'))
        {
            file_ptr = fopen("phonebook.text","wb+");
            add_contact();
        }
        else
        {
            exit(0);
        }
    }

    printf("\nEnter The Name: ");
    fflush(stdin);
    gets(nc.name);

    printf("\nEnter an Email: ");
    fflush(stdin);
    gets(nc.email);

    printf("\nEnter The Phone Number: ");
    fflush(stdin);
    scanf("%u",&(nc.phone));

    printf("\n\n");

    fwrite(&nc,(size_t)sizeof(nc),(size_t)1,file_ptr);
    fflush(stdin);
    fclose(file_ptr);       /* close the file. */
    system("cls");
    printf("\n\n\t\t**** New Contact Is Saved! ****");
    printf("\n\nName: \" %s \"\n\nEmail: \" %s \"\n\nPhone number: %u\n\n",nc.name,nc.email,nc.phone);
    printf("\nEnter Any Key To Return Main Menu ");
    scanf("%c",&temp);
    system("cls");
    options();
}


void modify_contact(void)
{
    newContact nc1,nc2;
    nc1.name[0]='0';
    nc2.name[0]='0';
    int8 flag=0;
	char name[50]={'0'};
    FILE *file_ptr;
	file_ptr = fopen("phonebook.text","rb+");
	if(file_ptr == NULL)
		{
			system("cls");
            printf("\n\n\t**** ERROR: CANNOT OPEN YOUR PHONE DATABASE .TEXT FILE ****\n\n");
            exit(0);
		}
    else
    {
        system("cls");
        printf("\n\nEnter Contact's Name To Edit: ");
        fflush(stdin);
        gets(name);

        while(  (int32)(fread(&nc1,(size_t)sizeof(nc1),(size_t)1,file_ptr)) == 1 )
            {
                if(strcmp(name,nc1.name)==0)
                {
                    system("cls");
                    printf("\n\nEnter The New Name: ");
                    fflush(stdin);
                    gets(nc2.name);
                    printf("\nEnter The New Email: ");
                    fflush(stdin);
                    gets(nc2.email);
                    printf("\nEnter The New Number: ");
                    fflush(stdin);
                    scanf("%u",&nc2.phone);
                    fseek(file_ptr,(int32)-sizeof(nc1),(int32)SEEK_CUR);
                    fwrite(&nc2,(size_t)sizeof(nc2),(size_t)1,file_ptr);
                    flag=1;
                    break;
                }
            }

            if(flag==1)
            {
                system("cls");
                printf("\n\t\t**** Your Contact Is Edited! ****\n\n");
                printf("----------------------------------");
                printf("\nName: \" %s \"\n\nEmail: \" %s \"\n\nPhone number: %u\n",nc2.name,nc2.email,nc2.phone);
                printf("----------------------------------\n");

            }
            else
            {
                system("cls");
                printf("\n\t\t**** Contact Not Found! ****\n\n");

            }
            fclose(file_ptr);
        }
        printf("\n\nEnter Any Key To Return Main Menu ");
        scanf("%c",&temp);
        options();
}



void view_my_contacts(void)
{
        newContact nc;
        nc.name[0]='0';
        FILE *file_ptr;
        file_ptr = fopen("phonebook.text","rb");
        if(file_ptr==NULL)
        {
            system("cls");
            printf("\n\n\t**** ERROR: CANNOT OPEN YOUR PHONE DATABASE .TEXT FILE ****\n\n");
            exit(0);
        }
        system("cls");
        if((int32) fread(&nc,(size_t)sizeof(nc),(size_t)1,file_ptr) == 1)
        {
            printf("\n\n\t\t**** Your Contact List Is ****\n\n\n");
            fseek(file_ptr,(int32)-sizeof(nc),(int32)SEEK_CUR);
        }
        else
        {
            printf("\n\n\t\t**** Your Contact List Is Empty.. ****\n\n\n");
            fseek(file_ptr,(int32)-sizeof(nc),(int32)SEEK_CUR);
        }
        while((int32)fread(&nc,(size_t)sizeof(nc),(size_t)1,file_ptr) == 1)
        {
            printf("----------------------------------");
            printf("\nName=%s\nEmail=%s\nMobile no=%u\n\n",nc.name,nc.email,nc.phone);
        }
        printf("----------------------------------");
        fclose(file_ptr);
        printf("\n\nEnter Any Key To Return Main Menu ");
        scanf("%c",&temp);
        system("cls");
        options();

}


void remove_contact(void)
{
    system("cls");
    newContact nc;
    nc.name[0]='0';
    FILE *file_ptr1,*file_ptr2;
	int8 flag=0;
	char name[50]={'0'};
	file_ptr1 = fopen("phonebook.text","rb");
	if(file_ptr1 == NULL)
    {
        printf("\n\n\t\t**** ERORR:CAN NOT OPEN DATABASE .TEXT FILE ****\n\n");
    }
    else
    {
        file_ptr2 = fopen("temp.text","wb+");
		if(file_ptr2 == NULL)
        {
            printf("\n\n\t\t**** ERROR: CAN NOT CREATE TEMP.TEXT FILE ****\n\n");
        }
		else
        {
            printf("\nEnter Contact Name: ");
            fflush(stdin);
            gets(name);
            while((int32)fread(&nc,(size_t)sizeof(nc),(size_t)1,file_ptr1) == 1 )
            {
                if(strcmp(nc.name,name)!=0)
                {
                    fwrite(&nc,(size_t)sizeof(nc),(size_t)1,file_ptr2);
                }
                if(strcmp(nc.name,name)==0)
                {
                    flag=1;
                }
            }
            fclose(file_ptr1);
            fclose(file_ptr2);
            if(flag!=1)
            {
                system("cls");
                printf("\n\n\t**** No Contact With This Name \" %s \" To Delete ****\n\n",name);
                remove("temp.text");
            }
            else
            {
                system("cls");
                remove("phonebook.text");
                rename("temp.text","phonebook.text");
                printf("\n\n\t**** You Contact \" %s \" Is Deleted Successfully ^_^ ****\n\n",name);
            }
        }
    }
    printf("\n\nEnter Any Key To Return Main Menu");
    scanf("%c",&temp);
    system("cls");
    options();
}

void delete_all(void)
{
    system("cls");
    char sure=0;
    printf("\n\n**** WARNING: all your contacts will be deleted and can't be restored!! ****\a");
    printf("\n\n\nARE YOU SURE YOU WANT TO DELETE ALL YOUR CONTACTS?\a [Yes,No]: ");
    fflush(stdin);
    scanf("%c",&sure);
    if(  ((char)sure=='Y') || ((char)sure=='y'))
    {
        remove("phonebook.text");
        FILE *file_ptr;
        file_ptr = fopen("phonebook.text","wb+");
        if(file_ptr != NULL)
        {
            fclose(file_ptr);
            printf("\n\n\t**** All Your Contacts Are Deleted Successfully *_* ****\n\n");
        }
        else
        {
            printf("\n\n\t\t**** ERORR:CAN NOT CREATE PHONEBOOK.TEXT FILE ****\n\n");
        }
    }
    printf("\n\nEnter Any Key To Return Main Menu ");
    scanf("%c",&temp);
    system("cls");
    options();
}


void phone_search(void)
{
    system("cls");
    newContact nc;
    nc.name[0]='0';
    FILE *file_ptr;
    uint32 pn=0;

    file_ptr = fopen("phonebook.text","rb");

    if(file_ptr==NULL)
    {
        printf("\n\t\t**** ERROR: CAN NOT OPEN YOUR PHONE DATABASE .TEXT FILE ****\n\n");
        exit(0);
    }

    printf("\nEnter The Contact's Number To Search: ");
    scanf("%u",&pn);
    system("cls");

    while((int32)fread(&nc,(size_t)sizeof(nc),(size_t)1,file_ptr)==1)
    {
        if(nc.phone==pn)
        {
            printf("\n\n\t\t**** Your Contact PhoneNumber's \" %u \" Is Found ****\n\n",pn);
            printf("----------------------------------");
            printf("\nName: \" %s \"\nEmail: \" %s \"\nPhoneNumber: ( %u )\n\n",nc.name,nc.email,nc.phone);
            printf("----------------------------------");
        }
        else
        {
            printf("\n\t\t**** Contact PhoneNumber's ( %u ) Not Found****\n\n",pn);
        }
    }

    fclose(file_ptr);
    printf("\n\nEnter Any Key To Return Main Menu ");
    scanf("%c",&temp);
    system("cls");
    options();

}



void name_search(void)
{
    system("cls");
    newContact nc;
    nc.name[0]='0';
    FILE *file_ptr;
    char name[50]={'0'};

    file_ptr =fopen("phonebook.text","rb");

    if(file_ptr == NULL)
    {
        printf("\n\t\t**** ERROR: CAN NOT OPEN YOUR PHONE DATABASE .TEXT FILE ****\n\n");
        exit(1);
    }

    printf("\nEnter The Contact's Name To Search: ");
    fflush(stdin);
    gets(name);
    system("cls");

    while((int32)fread(&nc,(size_t)sizeof(nc),(size_t)1,file_ptr)==1)
    {
        if(strcmp(nc.name,name)==0)
        {
            printf("\n\t\t**** Your Contact Name's \" %s \" Is Found:\n\n",name);
            printf("----------------------------------");
            printf("\nName: \" %s \"\n\nEmail: \" %s \"\n\nNumber: %u\n\n",nc.name,nc.email,nc.phone);
            printf("----------------------------------");
        }
        else
        {
            printf("\n\t\t**** Contact Name's \" %s \" Not Found:\n",name);
        }
    }
    fclose(file_ptr);
    printf("\n\nEnter Any Key To Return Main Menu ");
    scanf("%c",&temp);
    system("cls");
    options();
}


