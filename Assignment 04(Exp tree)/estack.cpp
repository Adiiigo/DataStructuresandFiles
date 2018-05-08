/*
 * estack.cpp
 *
 *  Created on: 25-Jan-2017
 *      Author: acer
 */

#include </home/acer/workspace/Expression_Tree/estack.h>
#include <stddef.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void op_popprint( int i ) ;
void op_pushprint( int i ) ;

estack::estack(void)
{
	// TODO Auto-generated constructor stub
	top = NULL ;
}

estack::~estack(void)
{
	// TODO Auto-generated destructor stub
	struct stacknode *a = NULL ;

	while(top != NULL)
	{
		if( top->next != NULL)
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
			top->next = NULL ;
			free (top) ;

			top = NULL ;
		}
	}
}

int estack::stackfull(int fcount)
{
	int rval = 0 ;

	if(fcount == (SIZE-1))
	{
		rval=1;
	}
	else
	{
		rval=0;
	}

	return rval ;
}

int estack::push(int &fcount,struct ExpTreeNode *idata)
{
	int rval = -2 ;

	struct stacknode *newnode = NULL ;

	if(stackfull(fcount) == 1)
	{
		op_pushprint( 1 ) ;
		rval = 0 ;
	}
	else
	{
		op_pushprint( 2 ) ;

		newnode = (struct stacknode*)calloc(1,sizeof(struct stacknode)) ;
		if(newnode == NULL)
		{
			op_pushprint( 3 ) ;

			rval = -1 ;
		}
		else
		{
			op_pushprint( 4 ) ;

			newnode->data=idata;

			if(top == NULL)
			{
				top = newnode ;
			}
			else
			{
				newnode->prev = top ;
				top->next = newnode ;
				top = newnode ;
			}

			rval = 1 ;
			fcount++;
		}
	}

	return rval ;
}

int estack::stackempty(int fcount)
{
	int rval = 0 ;

	if(fcount == -1)
	{
		rval=1;
	}
	else
	{
		rval=0;
	}

	return rval ;
}


int estack::pop(int &fcount,struct ExpTreeNode **ddata)
{
	int rval = -1 ;

	struct stacknode *a = NULL ;


	if(stackempty(fcount) == 1)
	{
		op_popprint( 1 ) ;
		rval = 0 ;
	}
	else
	{
		op_popprint( 2 ) ;

		if(top == NULL)
		{
			op_popprint( 1 ) ;
			rval = 0;
		}
		else
		{
			op_popprint( 3 ) ;

			*ddata=top->data;
			if( top->prev != NULL)
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
				top->next = NULL ;
				free(top) ;

				top = NULL ;
			}

			rval = 1 ;
			fcount-- ;
		}
	}
	return rval ;

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
