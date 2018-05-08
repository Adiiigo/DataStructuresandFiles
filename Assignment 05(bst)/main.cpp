/*
 * main.cpp
 *
 *  Created on: 23-Apr-2017
 *      Author: acer
 */

#include "bst.h"
#include "pqueue.h"
#include<stddef.h>
#include<iostream>
using namespace std;
int main(void)
{
	int ch=0;
	int ndata=0;
	int ret=0;
	int flag=0;

	int ddata=0;
	bst b;
	struct dll *p=NULL;
	struct dll *node=NULL;
	struct dll *snode=NULL;  //node use for searching
	struct dll *mnode=NULL;
	do
	{
		cout<<"\n\n Menu";
		cout<<"\n1.Insert node";
		cout<<"\n2.Display tree";
		cout<<"\n3.Delete node";
		cout<<"\n4.Mirror image ";
		cout<<"\n5.Search ";
		cout<<"\n6.Level wise display";
		cout<<"\n\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:

			cout<<"\nEnter node's data: ";
			cin>>ndata;
			b.getroot(&snode);
			b.search(&node,snode,ndata);
			if(node!=NULL && node->data==ndata)
			{
				cout<<"\nNode can't be added as data already exist!!!";
			}
			else
			{
				ret=b.insertnode(&snode,ndata);
				if(ret==0)
				{
					cout<<"\nNode added successfully";
				}
				else if(ret==1)
				{
					cout<<"\nMemory allocation failure";
				}
				else
				{
					cout<<"\nNode insertion failure";
				}
			}

			break;
		case 2:
			b.getroot(&node);
			b.display(node);
			break;
		case 3:
			b.getroot(&node);
			cout<<"\n Enter data to be deleted";
			cin>>ddata;
			p=b.deletenode(node,ddata);
			break;
		case 4:
			b.getroot(&node);
			cout<<"\nOriginal tree: ";
			b.display(node);
			b.mirror(node,&mnode);
			cout<<"\n";
			cout<<"\nMirror image of tree: ";
			b.display(mnode);;
			break;
		case 5:
			flag=0;
			cout<<"\nEnter node's data to be searched: ";
			cin>>ndata;
			b.getroot(&snode);
			if(snode==NULL)
			{
				cout<<"\nNode does not exist, as tree is empty!!";
			}
			else
			{
				b.searchnode(snode,ndata,flag);
				if(flag==1)
				{
					cout<<"\n\tNode found!!";
				}
				else
				{
					cout<<"\n\tNode does not exist!!";
				}
			}

			break;
		case 6:
			b.getroot(&node);
			b.display_level(node);
			break;

		}

	}while(ch>0 && ch<7);
	return 0;
}


