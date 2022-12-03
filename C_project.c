#include "C_project.h"/*Including header file which contain prototypes of functions and preprocessor*/

void interface()/*Definition of the function to print a message in a friendly way*/
{
    printf("\t\t\t\t          --------------------------- \n");
    printf("\t\t\t\t          | Welcome to Our Database  |\n");
    printf("\t\t\t\t          --------------------------- \n\n ");
}

void list_view()/*Definition of the function to list of choices to let the user choose*/
{
    printf("\n\n\n1- Is the database full or not.\n");
    printf("2- What is the size of the database.\n");
    printf("3- Add new student to the database.\n");
    printf("4- Delete a student from the database.\n");
    printf("5- Information of a student.\n");
    printf("6- Number of students and their ids.\n");
    printf("7- Is this student exist or not.\n");
    printf("8- Display the database.\n");
    printf("9- Exit.\n");
}

bool SDB_IsFull(void)/*Definition of the function to know if the database is full or not*/
{
    if(head==NULL)/*If head does not point to any thing then there is no database*/
    {
        printf("The database is empty\n");
        return false;
    }
    u8 x=1;/*counter*/
    student* temp;/*pointer of type student to moving in the database through the students*/
    temp=head;/*it point to the same location pointed by the head*/
    while(temp->link!=NULL)/*Loop to move through database*/
    {
        temp=temp->link;/*update*/
        x++;/*increment the counter*/
    }
    if(x==10)/*Knowing if the database is full or not*/
    {
        return true;/*Full*/
    }
    else
    {
      return false;/*Not full*/
    }
}

u8 SDB_GetUsedSize(void)/*Definition of the function to know number of students in the database*/
{
if(head==NULL)/*If head does not point to any thing then there is no database*/
    {
        return 0;
    }
    u8 x=1;/*counter of students*/
    student* temp;/*pointer of type student to moving in the database through the students*/
    temp=head;/*it point to the same location pointed by the head*/
    while(temp->link!=NULL)/*Loop to move through database*/
    {
        temp=temp->link;/*update*/
        x++;/*increment the counter*/
    }
    return x;/*Size*/
}

student* InsertInBeginning(student* head)/*Definition of the function to insert the first student in the database*/
{
	student* temp =(student*) malloc(sizeof(student));/*variable of type student to contain data*/
/*Deceleration of variables*/
	u8 id;
    u8 year;
    u8 subjects[3];
    u8 grades[3];
/*Taking values from the user*/
    printf("Please Enter the id of first the student to be inserted : ");
    scanf("%u",&id);

    printf("Please Enter the year of first the student to be inserted : ");
    scanf("%u",&year);
for(u8 i=0;i<3;i++)
{
        printf("Please Enter %uth course id of first the student to be inserted : ",(i+1));
        scanf("%u",&subjects[i]);
}
for(u8 i=0 ; i < 3 ; i++ )
{
        printf("Please Enter %uth course grade of first the student to be inserted : ",(i+1));
        scanf("%u",&grades[i]);
        if( (grades[i] > 100 ) || ( grades[i] < 0 ) )/*Allowed range of the grades from 0 to 100*/
        {
            while(grades[i]>100)
            {
                printf("Please Enter %uth course right grade: ",(i+1));
                scanf("%u",&grades[i]);
            }
        }
}
/*Store values from the user*/
	if(temp != NULL)
	{
		temp -> id = id;
		temp -> year= year;

		for(u8 i=0 ; i<3 ; i++ )
        {
            temp ->subjects[i] = subjects[i];
        }

        for(u8 i=0 ; i<3 ; i++ )
        {
            temp ->grades[i] = grades[i];
        }

		temp -> link = head;
		head = temp;
	}
	return head;
}

void InsertAtEnd(student* head)/*Definition of the function to insert student in the database*/
{

	student* temp =(student*) malloc(sizeof(student));/*variable of type student to contain data*/

	if(temp != NULL)
	{
		student* ptr = head;

		while(ptr->link != NULL)/*loop to move through the database*/
		{
			ptr = ptr->link;/*update*/
		}

/*Taking values from the user*/
    printf("Please Enter the id of next the student to be inserted : ");
	scanf("%u",&temp->id);

	printf("Please Enter the year of next the student to be inserted : ");
	scanf("%u",&temp->year);


	for(u8 i=0;i<3;i++)
    {
        printf("Please Enter %uth course id of the student to be inserted : ",(i+1));
        scanf("%u",&(temp->subjects[i]));
	}


	for(u8 i=0 ; i < 3 ; i++ )
    {
        printf("Please Enter %uth course grade of the student to be inserted : ",(i+1));
        scanf("%u",(&temp->grades[i]));

        if( ( temp->grades[i] > 100 ) || ( temp->grades[i] < 0 ) )/*Allowed range 0 to 100*/
        {
            while(temp->grades[i]>100)
            {
                printf("Please Enter %uth course right grade: ",(i+1));
                scanf("%u",&temp->grades[i]);
            }


	}
		ptr->link   = temp;
		temp->link  = NULL;
	}
}
}

student* CreateList(student* head) /*Definition of the function to create the database by using the 2 functions above*/
{
    /*Deceleration of variables*/
    u8 NumberOfStudents;
	u8 counter;


    /*Taking number of students*/
	printf("Enter the number of students:");
	scanf("%u",&NumberOfStudents);

    while(NumberOfStudents>10)/*Wrong entry*/
    {
    printf("Enter the number of students (max. 10 students ) : ");
	scanf("%u",&NumberOfStudents);
    }

	if(0 == NumberOfStudents)/*There is no list*/
	{
		return head;
	}


	head = InsertInBeginning(head);/*calling the function*/

	for(counter = 1; counter <NumberOfStudents; counter++)/*loop to insert the rest of students after the first one*/

	{
    InsertAtEnd(head);/*calling the function*/
	}
	return head;
}

 bool SDB_AddEntery(u8 id,u8 year,u8* subjects,u8* grades) /*Definition of the function to add a student*/
{
    student* temp =(student*) malloc(sizeof(student)); /*variable of type student to contain data*/
	if(head==NULL)/*If the database is empty then the student will be the first one*/
    {
     temp->id=id;
     temp->year=year;

	for(u8 i=0;i<3;i++)
    {

        temp->subjects[i]=*(subjects+i);
	}


	for(u8 i=0 ; i < 3 ; i++ )
    {

        temp->grades[i]=*(grades+i);

        if( ( *(grades+i) > 100 ) || ( *(grades+i) < 0 ) )
        {

           while(*(grades+i)>100)
            {
                temp->grades[i]=*(grades+i);
            }


	    }
    }

    head  = temp;

    temp->link  = NULL;

     return true;

    }



	u8 x=SDB_GetUsedSize();/*initializing variable by the value returned from the function*/


	if(x==10)/*Database is Full or not*/
    {
        return false;
    }

	if(temp != NULL)
	{
		student* ptr = head;

		while(ptr->link != NULL)/*loop to move through the database*/
		{
			ptr = ptr->link;/*update*/
		}
/*Taking values from the user*/
      if(SDB_IsIdExist(id))/*If the id is already exist*/
      {
          printf("Id is already exist\n");
          return false;
      }
      temp->id=id;
      temp->year=year;

	for(u8 i=0;i<3;i++)
    {
        temp->subjects[i]=*(subjects+i);
	}


	for(u8 i=0 ; i < 3 ; i++ )
    {
        temp->grades[i]=*(grades+i);

        if( ( *(grades+i) > 100 ) || ( *(grades+i) < 0 ) )
        {

           while(*(grades+i)>100)
            {
                temp->grades[i]=*(grades+i);
            }


	    }
		ptr->link   = temp;
		temp->link  = NULL;
	}

	if (x<(SDB_GetUsedSize()))/*if the size is incremented so the student is added successfully*/
    {
        return true;
    }
    else
    {
        return false;
    }
	}
}


void SDB_DeleteEntry(u8 id) /*Definition of the function to delete a student*/
{
    student * temp;/*pointer of type student*/


	if(head == NULL)/* Database is empty */
	{
		printf("Database is empty \n");
		return;
	}

	/* Delete the first Student at the List*/
	if(head->id == id)
	{
		temp  = head;
		head = head->link;
		free(temp);
		printf("The student has been deleted\n");
		return;
	}

	/* Delete in between Students or at the end */
	student * ptr = head;
	while(ptr->link != NULL)
	{
		if(ptr->link->id == id)
		{
			temp = ptr->link;
			break;
		}
		ptr = ptr->link;
	}

	if(ptr->link == NULL)/*Reaching the end of the database without getting the required id*/
	{
		printf("Student of the id %u is not in the database\n",id);
	}
	else/*delete the student*/
	{
		ptr->link = temp -> link;
		free(temp);
		printf("The student has been deleted\n");
	}
	//return head;

}
bool SDB_IsIdExist(u8 id) /*Definition of the function to know the existence of a student*/
{


	if(head == NULL)/*Database does not exist*/
	{
		printf("Database is empty \n");
		return false;
	}


	if(head->id == id)/*The student is at the start of the database*/
	{
		printf("Student of the id %u exists\n",id);
		return true;
	}

	student * ptr = head;
	while(ptr->link != NULL)/*Loop to find the required id*/
	{
		if(ptr->link->id == id)/*Id is found*/
		{
			break;
		}
		ptr = ptr->link;/*Update*/
	}

	if(ptr->link == NULL)/*Reaching the end of the database and the student does not exist*/
	{
		printf("Student of the id %u is not exist\n",id);
		return false;
	}
	else/*Found*/
	{
	    printf("Student of the id %u exists\n",id);
		return true;
	}
}


void DisplayList(student* head)/*Definition of function to display the students*/
{
	if(head == NULL)/*Database is empty*/
	{
		printf("List is empty\n");
		return;
	}

	student* ptr = head;
	printf("List is : \n");
	while(ptr!=NULL)/*Printing information*/
	{
		printf("id: %u \n",ptr->id);
		printf("Year: %u \n",ptr->year);
		for (u8 i=0;i<3;i++)
        {
            printf("%uth course_id: %u \t",(i+1),ptr->subjects[i]);
            printf("%uth course_grade: %u \n",(i+1),ptr->grades[i]);
        }
        printf("\n");
		ptr = ptr->link;/*Update*/
	}
}

bool SDB_ReadEntry(u8 id ,u8* Year ,u8* subjects ,u8* grades)/*Definition of function to get a student information*/
{
    student * temp;


	if(head == NULL)/*Database is empty*/
	{
		printf("Database is empty \n");
		return false;
	}


	if(head->id == id)/*Id is at the start of the database*/
	{
        *Year=head->year;
		for (u8 i=0;i<3;i++)
        {
            *(subjects+i)=head->subjects[i];
            *(grades+i)=head->grades[i];
        }

        return true;
	}

	student * ptr = head;
	while(ptr->link != NULL)/*Loop*/
	{
		if(ptr->link->id == id)/*Found*/
		{
			temp = ptr->link;
			break;
		}
		ptr = ptr->link;/*Update*/
	}

	if(ptr->link== NULL)/*Reaching the end of the database and the student does not exist*/
	{
		return false;
	}
	else/*assigning information*/
	{

	    *Year=temp->year;
	    for (u8 i=0;i<3;i++)
        {
            *(subjects+i)=temp->subjects[i];
            *(grades+i)=temp->grades[i];
        }
		return true;
	}
}

void SDB_GetIdList(u8* count,u8* List)/*Definition of function to make array of ids and get number of students*/
{
    *count=SDB_GetUsedSize();/*Number of students*/

    if(head == NULL)/*Database is empty*/
	{
		printf("List is empty\n");
		return;
	}

	student* ptr = head;
	int i=0;/*Counter*/
	while(ptr!=NULL)/*Loop*/
	{
		*(List + i ) =ptr->id;/*Storing id*/
		ptr = ptr->link;/*Update*/
        i++;/*Update*/
	}
}
