/****************************************************************************
*                                                                           *
*********************** Date    :  27/8/2022                   **************
*********************** Version :  1.0                         **************
*********************** Name    :  Mostafa Mohamed Abdel-Azeem **************
*********************** SWC     :  Simple database             **************
*                                                                           *
****************************************************************************/
#include "C_project.h"/*Including header file*/
student* head=NULL;/*Global head of the linked list*/
int main()
{
u8 id=0,year=0,choice=0,len=0,i=0,count=0,Year=0;/*initializing variables*/
bool full,add,exist;/*deceleration of variables of type bool to store the value returned from bool functions*/
u8 arr[10],subjects[3],grades[3];/*deceleration of array to store the ids of students returned from the function */
interface();/*calling the function*/
printf("\nCreate the Database:\n\n");
head=CreateList(head);/*calling the function to create the database*/
printf("\n\n-----------------------------------------------------------\n\n");
list_view();/*calling the function*/
printf("\n\n--------------------------------------------\n\n");
printf("\nEnter your choice:");/*let the user to choose which feature to be done or executed*/
scanf("%u",&choice);
while(choice!=9)/*Loop to make the user choose a new feature every loop*/
{
  switch(choice)/*Switch case to make the desired order*/
  {
      case 1:
          full=SDB_IsFull();/*calling the function to know if the database is full or not*/
          printf("The return is %u\n",full);
          if(full==0)
          {
              printf("The database is not full.\n");
          }
          else
          {
              printf("The database is full.\n");
          }
          break;
      case 2:
          len=SDB_GetUsedSize();/*calling the function to know the number of students in the database*/
          printf("The size is %u",len);
          break;
      case 3:
          /*Taking values from the user*/
           printf("Please Enter the id of next the student to be inserted : ");
	       scanf("%u",&id);


	       printf("Please Enter the year of next the student to be inserted : ");
	       scanf("%u",&year);


	      for(u8 i=0;i<3;i++)
          {
            printf("Please Enter %uth course id of the student to be inserted : ",(i+1));
            scanf("%u",&(subjects[i]));
	      }


	      for(u8 i=0 ; i < 3 ; i++ )
          {
            printf("Please Enter %uth course grade of the student to be inserted : ",(i+1));
            scanf("%u",(&grades[i]));

              if( ( grades[i] > 100 ) || ( grades[i] < 0 ) )
              {
                  while(grades[i]>100)
                  {
                   printf("Please Enter %uth course right grade: ",(i+1));
                   scanf("%u",&grades[i]);
                  }
	          }
          }

          add=SDB_AddEntery(id,year,&subjects[0],&grades[0]);/*calling the function add new student in the database*/
          printf("The return is %u\n",add);
          if(add==0)
          {
              printf("The student is not added successfully.\n");
          }

          else
          {
              printf("The student added successfully. \n");
          }

          break;

      case 4:
          printf("Enter the student's id: ");
          scanf("%u",&id);
          SDB_DeleteEntry(id);/*calling the function to delete a student in the database*/
          break;
      case 5:
          printf("Enter the student's id: ");
          scanf("%u",&id);
          exist = SDB_ReadEntry( id ,&Year ,&subjects[0] ,&grades[0] );/*calling the function display the information of a student in the database*/
          printf("The return is %u\n",exist);
          if(exist==0)
          {
            printf("Student is not found.\n");
          }

          else
          {
          printf("Student is found.\n");
          printf("Id: %u\n",id);
          printf("Year: %u\n",Year);
          for( i=0 ; i < 3 ; i++ )/*loop to print the ids from the array*/
          {
            printf("%uth course_id: %u \t",(i+1),subjects[i]);
            printf("%uth course_grade: %u \n",(i+1),grades[i]);
          }
          }

          break;
      case 6:
          SDB_GetIdList(&count,arr);/*calling the function to count the number of students in the database and print their ids*/
          printf("Number of ids is: %u\n",count);
          printf("The list of ids is :\t");
          for( i=0 ; i < count ; i++ )/*loop to print the ids from the array*/
          {
                printf("%u\t\t",arr[i]);
          }
          break;
      case 7:
          printf("Enter the student's id: ");
          scanf("%u",&id);
          exist=SDB_IsIdExist(id);/*calling the function if the student of this id is present in the database or not*/
          printf("The return is %u",exist);
          break;
      case 8:
        DisplayList(head);/*Calling a function to display the information in the database*/
        break;
      default:/*if the user enter a number not in the choices list*/
        printf("\nWrong choice\n");
        break;

  }
   printf("\n\n--------------------------------------------\n\n");
   list_view();/*calling the function to display list of choices*/
   printf("\n\n\nEnter your choice:");
   scanf("%u",&choice);
}
    return 0;
}
//----------------------------------------------
