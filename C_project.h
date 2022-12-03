#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>/*Include this Library to use bool function*/
typedef unsigned int u8;/*using typedef to change unsigned int data type to new data type called u8*/
//---------------------------------------------structure definition--------------------
typedef struct data
{
u8 id;//store id of the student
u8 year;//store year of the student
u8 subjects[3];/*store subject ids of the student*/
u8 grades[3];/*store subject grades of the student*/
struct data* link;/*pointer of type data points to the next student*/
}student;/*using typedef to change data to new data type called student*/
extern student* head;/*to be used in this file and another files*/
//---------------------------------------------prototypes-------------------------------
void interface();/*Function to print a message in a friendly way,it doesn't take arguments and return void*/
void list_view();/*Function to print a list of choices to the user in a friendly way,it doesn't take arguments and return void*/
student* CreateList(student*);/*Function to create the database at the beginning of the program,it takes pointer of type student as argument and return a pointer of the same type*/
student* InsertInBeginning(student*);/*Function to add a student at the beginning of the database"used inside CreateList function",it takes pointer of type student as argument and return a pointer of the same type*/
void InsertAtEnd(student*);/*Function to add a student at the end of the database"used inside CreateList function",it takes pointer of type student as argument and return void*/
void DisplayList(student*);/*Function to display the students inside the database ,it takes pointer of type student as argument and return void*/
bool SDB_IsFull(void);/*Function to know if the database is full or not ,it does not take arguments and return bool*/
u8 SDB_GetUsedSize(void);/*Function to get the size of the database,it does not take arguments and return u8*/
bool SDB_AddEntery(u8,u8,u8*,u8*);/*Function to add anew student to the database,it takes id and year of type u8 and subjects,grades of type pointer to u8 as argument and return bool*/
void SDB_DeleteEntry(u8);/*Function to delete a student from the database,it takes id of the student as argument and return void*/
bool SDB_IsIdExist(u8);/*Function to know if the student exist or not,id of the student as argument and return bool*/
bool SDB_ReadEntry(u8,u8*,u8*,u8*);/*Function to know if the student exist or not and matching his id with his information,it takes pointer of type u8 to year, subject and grades and u8 id of the student as argument and return bool*/
void SDB_GetIdList(u8*,u8*);/*Function to get the number of students and their ids,2 pointer to u8 as argument and return void*/
//-------------------------------------------------------------------------------------
