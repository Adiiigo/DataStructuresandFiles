/*
 * eval.cpp
 *
 *  Created on: 21-Jan-2017
 *      Author: acer
 */

//INCLUDING .h FILE
#include</home/acer/eclipse/Sem3Workspace/conversions/eval.h>

//FOR DEFINING NULL
#include<stddef.h>

//FOR STREAM RELATED OPERATIONS
#include<iostream>

//FOR RUNTIME MEMORY ALLOCATION
#include<stdlib.h>

using namespace std ;

void pushprint( int i);
void popprint( int i);

//CONTRUCTOR
eval::eval()
{
	// TODO Auto-generated constructor stub
	top = NULL ;

}

//DESTRUCTOR
eval::~eval()
{
	// TODO Auto-generated destructor stub
	struct eval_node *a = NULL ;			//STRUCT TYPE VARIABLE POINTER

	while(top !=NULL)
	{
		if(top->prev != NULL)
		{
			a = top ;
			top = top->prev ;
			a->prev = NULL ;
			top->next = NULL ;
			free(a) ;
			a=NULL ;
		}
		else
		{
			top->prev = NULL ;
			free(top) ;
			top = NULL ;
		}
	}
}

int eval::push(int &fsize, int fidata)
{
	struct eval_node *newnode = NULL ;	//POINTER WHICH STORES 'idata' VALUE
	int flag = -2 ;						//SUCCESS FLAG

	newnode = (struct eval_node*)calloc(1,sizeof(struct eval_node)) ;
	if(newnode == NULL)
	{
		pushprint( 1 ) ;
		flag = -1 ;
	}
	else
	{
		pushprint( 2 ) ;

		newnode->data = fidata ;
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
	return flag ;
}

int eval::stackempty(int fsize)
{
	int flag = -1 ;			//SUCCESS FLAG
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

int eval::pop(int &fsize,int &fddata)
{
	struct eval_node *a = NULL ;			//STRUCT TYPE VARIABLE POINTER
	int flag = -1 ;							//SUCCESS FLAG

	if(stackempty(fsize) == 0)
	{
		popprint( 1 ) ;
		flag = 0 ;
	}
	else
	{
		popprint( 2 ) ;

		if(top == NULL)
		{
			popprint( 1 ) ;

			flag = 0 ;
		}
		else
		{
			popprint( 3 ) ;

			fddata = top->data ;

				if(top->prev != NULL)
				{
					a = top ;
					top = top->prev ;
					a->prev = NULL ;
					top->next = NULL ;
					free(a);
					a = NULL;
				}
				else
				{
					top->prev = NULL ;
					free(top) ;
					top = NULL ;
				}
			}
			fsize-- ;
			flag = 1 ;
		}
	return flag ;
}

void pushprint( int i)
{
	switch( i )
	{
		case 1 :	cout << "\n\n\t\tHeap Is Full!!!" ;
					cout << "\n\t\tCannot Allocate New Memory." ;
					break;

		case 2 :	cout << "\n\n\t\tYou Can Continue!!!" ;
					cout << "\n\t\tHeap Is Not Full." ;
					break;
	}
}

void popprint( int i)
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
