/*
 * ExpTree.cpp
 *
 *  Created on: 25-Jan-2017
 *      Author: acer
 */

#include </home/acer/workspace/Expression_Tree/ExpTree.h>
#include </home/acer/workspace/Expression_Tree/estack.h>

#include <stddef.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void deletenode(struct ExpTreeNode **node);

ExpTree::ExpTree(void)
{
	// TODO Auto-generated constructor stub
	root = NULL;
}

ExpTree::~ExpTree(void)
{
	// TODO Auto-generated destructor stub
	deletenode(&root);
}

int ExpTree::constructTree(char fpostfix[])
{

	estack e;

	struct ExpTreeNode *newnode = NULL ;
	struct ExpTreeNode *ddata = NULL ;

	int rval = -1 ;
	int i = 0 ;
	char sym = '\0';

	int ecount = -1 ;
	int eflag = -1 ;

	while(fpostfix[i] != '\0')
	{
		sym=fpostfix[i];
		if((sym >= 'a' && sym <= 'z') || (sym >= 'a' && sym <= 'Z'))
		{
			newnode = (struct ExpTreeNode*)calloc(1,sizeof(struct ExpTreeNode));
			if( newnode == NULL)
			{
				cout << "\n\n\t\tMemory Allocation Failed";
				rval = 0 ;
			}
			else
			{
				newnode->data = sym ;

				eflag=e.push(ecount,newnode) ;
				if(eflag == 1)
				{
					cout<<"\n\n\t\tInsertion Successfully Happened" ;
				}
				else if(eflag == 0)
				{
					cout<<"\n\n\t\tInsertion Failed" ;
				}
				else if(eflag == -1)
				{
					cout << "\n\n\t\tMemory Full Failure " ;
				}
				else
				{
					cout << "\n\n\t\tFunction Failure" ;
				}
				rval = 1 ;
			}
		}
		else
		{
			newnode = (struct ExpTreeNode*)calloc(1,sizeof(struct ExpTreeNode));
			if( newnode == NULL)
			{
				cout << "\n\n\t\tMemory Allocation Failed" ;
				rval = 0 ;
			}
			else
			{
				//INSERTING SYM INTO THE NEWNODE
				newnode->data = sym ;

				//POPPING FIRST ELEMENT IN THE STACK
				eflag = e.pop(ecount,&ddata) ;
				if(eflag == 1)
				{
					cout << "\n\n\t\tDeletion Successful" ;
				}
				else if(eflag == 0)
				{
					cout << "\n\n\t\tDeletion Failed" ;
				}
				else
				{
					cout << "\n\n\t\tFunction Failure" ;
				}
				newnode->rchild = ddata;

				//POPPING SECOND ELEMENT IN THE STACK
				eflag = e.pop(ecount,&ddata) ;
				if(eflag == 1)
				{
					cout << "\n\n\t\tDeletion Successful" ;
				}
				else if(eflag == 0)
				{
					cout << "\n\n\t\tDeletion Failed" ;
				}
				else
				{
					cout << "\n\n\t\tFunction Failure" ;
				}
				newnode->lchild = ddata ;

				//PUSHING THE NODE IN THE STACK
				eflag = e.push(ecount,newnode);
				if(eflag == 1)
				{
					cout<<"\n\n\t\tInsertion Successfully Happened" ;
				}
				else if(eflag == 0)
				{
					cout<<"\n\n\t\tInsertion Failed" ;
				}
				else if(eflag == -1)
				{
					cout << "\n\n\t\tMemory Full Failure " ;
				}
				else
				{
					cout << "\n\n\t\tFunction Failure" ;
				}
				rval = 1 ;
			}
		}
		i++;
	}

	//POPPING THE FINAL ELEMENT
	eflag = e.pop(ecount,&ddata);
	if(eflag == 1)
	{
		cout << "\n\n\t\tDeletion Successful" ;
	}
	else if(eflag == 0)
	{
		cout << "\n\n\t\tDeletion Failed" ;
	}
	else
	{
		cout << "\n\n\t\tFunction Failure" ;
	}
	root = ddata ;

	return rval ;
}
void ExpTree::preorder (struct ExpTreeNode *node)
{
	if(node != NULL)
	{
		cout << node->data;
		preorder(node->lchild) ;
		preorder(node->rchild) ;
	}

}
void ExpTree::postorder (struct ExpTreeNode *node)
{
	if(node != NULL)
	{
		postorder(node->lchild) ;
		postorder(node->rchild) ;
		cout << node->data;
	}
}
void ExpTree::inorder (struct ExpTreeNode *node)
{
	if(node != NULL)
	{
		inorder(node->lchild) ;
		cout << node->data;
		inorder(node->rchild) ;
	}
}

void ExpTree::getroot(struct ExpTreeNode **node)
{
	if(root != NULL)
	{
		*node = root ;
	}
}

void deletenode(struct ExpTreeNode **node)
{
	struct ExpTreeNode *a = NULL ;
	struct ExpTreeNode *b = NULL ;
	struct ExpTreeNode *c = NULL ;

	a = *node ;

	b = a->lchild ;

	c = a->rchild ;

	while( a->lchild != NULL && a->rchild != NULL)
	{
		a->lchild = NULL ;
		a->rchild = NULL ;
		free(a);

		a = NULL;

		if( b != NULL )
		{
			deletenode(&b);
		}

		if( c != NULL )
		{
			deletenode(&c);
		}
	}

	*node = a ;

}
