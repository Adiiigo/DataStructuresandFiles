/*
 * gqueue.cpp
 *
 *  Created on: 16-Jan-2017
 *      Author: acer
 */

//INCLUDING .h FILE
#include </home/acer/eclipse/Sem3Workspace/Facebook_assig/gqueue.h>

//FOR STREAM RELATED OPERATIONS
#include<iostream>

//FOR DEFINING NULL
#include<stddef.h>

//FOR RUNTIME MEMORY ALLOCATION
#include<stdlib.h>

//FOR STRING RELATED FUNCTIONS
#include<string.h>

void insertprint(int i);
void deleteprint(int i);

using namespace std;

//CONTRUCTOR
gqueue::gqueue(void )
{
	// TODO Auto-generated constructor stub
	front = NULL ;
	rear = NULL ;
}

//DESTRUCTOR
gqueue::~gqueue( void )
{
	// TODO Auto-generated destructor stub

	struct gqueuenode *a = NULL ;		//STRUCT TYPE VARIABLE POINTER


	while(front != NULL)
	{
		if(front->next != NULL)
		{
			a = front ;
			front = front->next ;
			a->next = NULL ;
			free(a) ;
			a = NULL ;
		}
		else
		{
			front->prev = NULL ;
			free(front) ;
			front = NULL ;
		}
	}
}

int gqueue::queuefull(int fcount)
{
	int flag = -1 ;							//SUCCESS FLAG
	if(fcount == (SIZE-1))
	{
		flag = 1 ;
	}
	else
	{
		flag = 0 ;
	}
	return flag ;
}

int gqueue::insertgq(int &fcount, char fidata)
{
	struct gqueuenode *newnode = NULL;	//STRUCT TYPE VARIABLE POINTER
	int flag = -1 ;							//SUCCESS FLAG

	if(queuefull(fcount) == 1)
	{
		insertprint(1);

		flag = 1 ;
	}
	else
	{
		newnode = (struct gqueuenode*)calloc(1,sizeof(struct gqueuenode)) ;
		if(newnode == NULL)
		{
			insertprint(2);
		}
		else
		{
			insertprint(3);

			newnode->name = fidata ;
			if(queueempty(fcount) == 0)
			{
				rear = newnode ;
				front = newnode ;
			}
			else
			{
				newnode->prev = rear ;
				rear->next = newnode ;
				rear = newnode ;
			}

				fcount++ ;
				flag = 2 ;
		}
	}
	return flag ;
}

int gqueue::queueempty(int fcount)
{
	int flag = -1 ;							//SUCCESS FLAG
	if(fcount == -1)
	{
		flag = 0 ;
	}
	else
	{
		flag = 1 ;
	}
	return flag ;
}

int gqueue::deletegq(int &fcount, char &fddata)
{
	struct gqueuenode *a = NULL ;		//STRUCT TYPE VARIABLE POINTER
	int flag = -1 ;							//SUCCESS FLAG

	if(queueempty(fcount) == 0)
	{
		deleteprint(1);

		flag = 1 ;
	}
	else
	{

		fddata  = front->name ;

		if(front->next != NULL)
		{
			a = front ;
			front=front->next ;
			a->next = NULL ;
			free(a) ;
			a = NULL ;
		}
		else
		{
			front->prev = NULL ;
			free(front) ;
			front = NULL ;
		}

		fcount-- ;
		flag = 2 ;
	}
	return flag ;
}

void insertprint(int i)
{
	switch ( i )
	{
	   	   case 1 :	cout << "\n\n\t\tQueue Is Full!!!" ;
					cout << "\n\t\tCannot Insert More Elements" ;
					cout << "\n\t\tExtract Elements First" ;
	   		   	   	break ;

	   	   case 2 : cout << "\n\n\t\tMemory Allocation of 'newnode' Failed." ;
	   	   	   	   	break;

	   	   case 3 : cout << "\n\t\tYou Can Continue!!!" ;
	   	   	   	   	break;
	}
}

void deleteprint(int i)
{
	switch ( i )
	{
	   	   case 1 :	cout<<"\n\t\tQueue Is Empty." ;
					cout<<"\n\t\tInsert Elements in The Queue First" ;
	   		   	   	break ;
	}
}
