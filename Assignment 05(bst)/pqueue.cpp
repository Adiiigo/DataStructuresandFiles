/*
 * pqueue.cpp
 *
 *  Created on: 23-Apr-2017
 *      Author: acer
 */

#include "pqueue.h"
#include<iostream>
using namespace std;
#include<stddef.h>
#include<stdlib.h>
#include<string.h>
pqueue::pqueue() {
	// TODO Auto-generated constructor stub
rear=NULL;
front=NULL;
count=-1;
}

pqueue::~pqueue() {
	// TODO Auto-generated destructor stub
	struct dllnode *dnode=NULL;
	while(front!=NULL)
	{
		dnode=front;
		front=front->next;
		dnode->pre=NULL;
		free(dnode);
		dnode=NULL;
	}

}

int pqueue::insert_ele(struct dll *node)
{

	int flag=0;
	struct dllnode *newnode=NULL;

	if(queuefull()==1)
	{
		flag=1;
	}
	else
	{
		if(queueempty()==1)
		{
			newnode=(struct dllnode*)calloc(1,sizeof(struct dllnode));
			if(newnode==NULL)
			{
				flag=2;  //memory allocation failed
			}
			else
			{
				newnode->data=node;
				rear=newnode;
				front=newnode;
				count++;
			}

		}
		else
		{
			newnode=(struct dllnode*)calloc(1,sizeof(struct dllnode));
			if(newnode==NULL)
			{
				flag=2;  //memory allocation failed
			}
			else
			{
				newnode->data=node;
				rear->next=newnode;
				newnode->pre=rear;
				rear=newnode;
				count++;
			}
		}
	}

	return flag;

}



int pqueue::delete_ele(struct dll **node)
{
	struct dllnode *dnode=NULL;
	char flag=0;
	if(queueempty()==1)
	{
		flag=1;  //can't delete
	}
	else
	{
		*node=front->data;
		dnode=front;
		front=front->next;
		free(dnode);
		dnode=NULL;
		count--;
		flag=0;
	}
	return flag;
}


int pqueue::queuefull()
{
	int flag=0;

	if(count==SIZE-1)
	{
		flag=1;  //queue full
	}
	else
	{
		flag=2;
	}
	return flag;
}


int pqueue::queueempty()
{
	int flag=0;
	if(count==-1)
	{
		flag=1;  //queue empty
	}
	else
	{
		flag=2;
	}
	return flag;
}

