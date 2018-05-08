/*
 * operand.cpp
 *
 *  Created on: 14-Jan-2017
 *      Author: acer
 */

//INCLUDING .h FILE
#include </home/acer/eclipse/Sem3Workspace/conversions/operand.h>

//FOR RUNTIME MEMORY ALLOCATION
#include<stdlib.h>

//FOR DEFINING NULL
#include<stddef.h>

//FOR STREAM RELATED OPERATIONS
#include<iostream>

//FOR STRING RELATED FUNCTIONS
#include<string.h>

using namespace std;

void opnd_pushprint( int i);
void opnd_popprint( int i);

//CONTRUCTOR
operand::operand()
{
	// TODO Auto-generated constructor stub
	top  = NULL ;
}

//DESTRUCTOR
operand::~operand()
{
	// TODO Auto-generated destructor stub
	struct opnd_stack *a = NULL;			//STRUCT TYPE VARIABLE POINTER

	while(top !=NULL)
	{
		if(top->prev != NULL)
		{
			a = top ;
			top = top->prev ;
			a->prev = NULL;
			top->next = NULL ;
			free(a);
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

int operand::stackfull(int fsize)
{
	int flag =-1 ;					//SUCCESS FLAG
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

int operand::push(int &fsize, char fidata[20])
{
	struct opnd_stack *newnode = NULL ;	//POINTER WHICH STORES 'idata' VALUE
	int flag = -2;						//SUCCESS FLAG

	if(stackfull(fsize) == 1)
	{
		opnd_pushprint( 1 ) ;
		flag = 0 ;
	}
	else
	{
		opnd_pushprint( 2 ) ;

		newnode = (struct opnd_stack*)calloc(1,sizeof(struct opnd_stack)) ;
		if(newnode == NULL)
		{
			opnd_pushprint( 3 ) ;
			flag = -1 ;
		}
		else
		{
			opnd_pushprint( 4 ) ;

			strcpy(newnode->data,fidata) ;
			if(top == NULL)
			{
				top = newnode ;
			}
			else
			{
				top->next = newnode ;
				newnode->prev = top ;
				top = newnode ;
			}
			fsize++ ;
			//cout << "\n\n\t\tfsize=" << fsize ;
			flag = 1 ;
		}
	}
	return flag ;
}

int operand::stackempty(int fsize)
{
	int flag= -1 ;
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

int operand::pop(int &fsize,char fddata[20])
{
	struct opnd_stack *a  =NULL;			//STRUCT TYPE VARIABLE POINTER
	int flag = -1 ;	 						//SUCCESS FLAG


	if(stackempty(fsize) == 0)
	{
		opnd_popprint( 1 ) ;
		flag = 0 ;
	}
	else
	{
		opnd_popprint( 2 ) ;

		if(top==NULL)
		{
			opnd_popprint( 1 ) ;
			flag = 0 ;
		}
		else
		{
			opnd_popprint( 3 ) ;

			strcpy(fddata,top->data) ;

			fddata = top->data ;
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
			fsize-- ;
			flag = 1 ;
		}
	}
	return flag ;
}

void opnd_pushprint( int i )
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

void opnd_popprint( int i )
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


