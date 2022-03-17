#ifndef PhoneBook_H
#define PhoneBook_H


/*
Type name: int8
Type Description: signed char type
Type Range: 0 .. 255
*/
typedef signed char int8;

/*
Type name: int16
Type Description: signed short type
Type Range: 0 .. 65535
*/
typedef signed short int16;
/*
Type name: int32
Type Description: signed int type
Type Range: 0 .. 4294967295
*/
typedef signed int int32;
/*
Type name: uint8
Type Description: unsigned char type
Type Range: -125 ... 127
*/
typedef unsigned char uint8;
/*
Type name: uint16
Type Description: unsigned short type
Type Range: -32768 ... 32767
*/
typedef unsigned short uint16;
/*
Type name: uint32
Type Description: unsigned short type
Type Range: -2147483648 ... 2147483647
*/
typedef unsigned int uint32;



typedef struct personn
{
    char name[50];
    char email[50];
    uint32 phone;

}newContact;

void options (void);
void view_my_contacts(void);
void add_contact(void);
void modify_contact(void);
void remove_contact(void);
void phone_search(void);
void name_search(void);
void delete_all(void);
#endif



