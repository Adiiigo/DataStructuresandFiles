/*
 * operatorstack.cpp
 *
 *  Created on: 14-Jan-2017
 *      Author: acer
 */



//INCLUDING .h FILE
#include </home/acer/eclipse/Sem3Workspace/conversions/operatorstack.h>

//FOR RUNTIME MEMORY ALLOCATION
#include<stdlib.h>

//FOR DEFINING NULL
#include<stddef.h>

//FOR STREAM RELATED OPERATIONS
#include<iostream>

using namespace std;

void op_pushprint( int i);
void op_popprint( int i);

//CONTRUCTOR
operator_stack::operator_stack()
{
	// TODO Auto-generated constructor stub
	top = NULL ;

}

//DESTRUCTOR
operator_stack::~operator_stack()
{
	// TODO Auto-generated destructor stub
	struct opstack *a = NULL ;				//STRUCT TYPE VARIABLE POINTER

	while(top !=NULL)
	{
		if(top->prev != NULL)
		{
			a = top ;
			top = top->prev ;
			a->prev = NULL ;
			top->next = NULL ;
			free(a) ;
			a = NULL ;
		}
		else
		{
			top->prev = NULL ;
			free(top) ;
			top = NULL ;
		}
	}
}


int operator_stack::stackfull(int fsize)
{
	int flag=-1 ;							//SUCCESS FLAG
	if(fsize == (SIZE-1))
	{
		flag = 1 ;
	}
	else
	{
		flag = 0 ;
	}
	return flag ;
}

int operator_stack::push(int &fsize, char fidata)
{
	struct opstack *newnode = NULL;		//POINTER WHICH STORES 'idata' VALUE
	int flag = -2 ;						//SUCCESS FLAG

	if(stackfull(fsize) == 1)
	{
		op_pushprint( 1 ) ;
		flag = 0 ;
	}
	else
	{
		op_pushprint( 2 ) ;

		newnode = (struct opstack*)calloc(1,sizeof(struct opstack)) ;
		if(newnode == NULL)
		{
			op_pushprint( 3 ) ;

			flag = -1 ;
		}
		else
		{
			op_pushprint( 4 ) ;

			newnode->data = fidata ;
			if(top == NULL)
			{
				top = newnode ;
			}
			else
			{
				top->next= newnode;
				newnode->prev = top ;
				top = newnode ;
			}
			fsize++ ;
			cout << "\n\n\t\tfsize=" << fsize ;
			flag = 1 ;
		}
	}

	return flag;
}

int operator_stack::stackempty(int fsize)
{
	int flag = -1 ;						//SUCCESS FLAG
	if(fsize == -1)
	{
		flag = 0 ;
	}
	else
	{
		flag = 1 ;
	}
	return flag ;
}

int operator_stack::pop(int &fsize,char &fddata)
{
	struct opstack *a = NULL;			//STRUCT TYPE VARIABLE POINTER
	int flag = -1 ;					    //SUCCESS FLAG


	if(stackempty(fsize) == 0)
	{
		op_popprint( 1 ) ;
		flag = 0 ;
	}
	else
	{
		op_popprint( 2 ) ;

		if(top == NULL)
		{
			op_popprint( 1 ) ;
			flag = 0;
		}
		else
		{
			op_popprint( 3 ) ;

			fddata = top->data ;
			if(top->prev != NULL)
			{
				a = top ;
				top = top->prev ;
				a->prev = NULL ;
				top->next = NULL ;
				free(a) ;
				a  = NULL ;
			}
			else
			{
				top->prev = NULL ;
				free(top) ;
				top = NULL ;
			}
			fsize-- ;
			flag = 1 ;
		}
	}
	return flag ;
}

char operator_stack::getdata()
{
	char fdata = '\0';					//VARIABLE WHICH STORES THE VALUE OF THE TOPPEST CHAR
	if(top != NULL)
	{
		fdata = top->data;
	}
	else
	{
		fdata = -1 ;
	}

	return fdata;
}

void op_pushprint( int i )
{
	switch( i )
	{
		case 1 :	cout << "\n\n\t\tStack Is Full!!!" ;
					cout << "\n\t\tCannot Enter Data." ;
					break;

		case 2 :	cout << "\n\n\t\tYou Can Continue!!!" ;
					cout << "\n\t\tStack Is Not Full." ;
					break;

		case 3 :	cout << "\n\n\t\tHeap Is Full!!!" ;
					cout << "\n\t\tCannot Allocate New Memory." ;
					break;

		case 4 :	cout << "\n\n\t\tYou Can Continue!!!" ;
					cout << "\n\t\tHeap Is Not Full." ;
					break;
	}
}

void op_popprint( int i )
{
	switch( i )
	{
		case 1 :	cout << "\n\n\t\tStack Is Empty" ;
					cout << "\n\t\tCannot Remove Data" ;
					break;

		case 2 :	cout << "\n\n\t\tYou Can Continue!!!" ;
					cout << "\n\t\tStack Is Full." ;
					break;

		case 3 :	cout << "\n\n\t\tYou Can Continue!!!" ;
					cout << "\n\t\tTop is Not NULL." ;
					break;
	}
}
