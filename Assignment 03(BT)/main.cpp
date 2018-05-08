/*
 * main.cpp
 *
 *  Created on: 23-Apr-2017
 *      Author: acer
 */

/*
 * main.cpp
 *
 *  Created on: 05-Feb-2017
 *      Author: administrator
 */

#include </home/acer/eclipse/test/PBT/btree.h>
#include<stddef.h>
#include<iostream>
using namespace std;
int main(void)
{
	int ch=0;
	int child=0;
	int opt=0;
	int parent=0;
	int ndata=0;
	int ret=0;
	int height=0;
	btree b;
	struct dll *node=NULL;
	struct dll *snode=NULL;  //node use for searching
	struct dll *copynode=NULL;
	do
	{
		cout<<"\n\n Menu";
		cout<<"\n1.Insert node";
		cout<<"\n2.Display tree";
		cout<<"\n3.Depth of tree";
		cout<<"\n4.Leaf nodes ";
		cout<<"\n5.Copy tree ";
		cout<<"\n\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\n1.Insert root node of tree";
			cout<<"\n2.Insert left node";
			cout<<"\n3.Insert right node";
			cout<<"\n\nEnter your choice: ";
			cin>>opt;
			switch(opt)
			{
				case 1:child=2;
				if(node==NULL)
				{
					cout<<"\nEnter root node data: ";
					cin>>ndata;
					ret=b.insertnode(&node,child,ndata);
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
				else
				{
					cout<<"\nRoot node already exist";
				}
					break;


				case 2:
				b.getroot(&snode);
				if(snode==NULL)
				{
					cout<<"\nNode insertion failure as no root present";
				}
				else
				{
					child=1;
					cout<<"\nEnter data of node for which you want to insert left child: ";
					cin>>parent;

					b.getroot(&snode);
					b.search(&node,&snode,parent);
					if(node->data==parent && node->lchild==NULL)
					{
						cout<<"\nEnter left node data: ";
						cin>>ndata;
						ret=b.insertnode(&node,child,ndata);
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
					else if(node->data!=parent)
					{
						cout<<"\nNode does not exist";
					}
					else
					{
						cout<<"\nNode already contains data,therefore new node cant be added";
					}
				}

					break;


				case 3:
				b.getroot(&snode);
				if(snode==NULL)
				{
					cout<<"\nNode insertion failure as no root present";
				}
				else
				{
					child=3;
					cout<<"\nEnter data of node for which you want to insert right child:";
					cin>>parent;

					b.getroot(&snode);
					b.search(&node,&snode,parent);
					if(node->data==parent && node->rchild==NULL )
					{
						cout<<"\nEnter right node data: ";
						cin>>ndata;
						ret=b.insertnode(&node,child,ndata);
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
					else if(node->data!=parent)
					{
						cout<<"\nNode does not exist";
					}
					else
					{
						cout<<"\nNode already contains data,therefore new node cant be added";
					}

						break;
				}
			}
			break;
		case 2:
			b.getroot(&node);
			b.display(node);
			break;
		case 3:
			b.getroot(&node);
			height=b.theight(node);
			cout<<"\nHeight of the tree is: "<<height;
			break;
		case 4:
			b.getroot(&node);
			b.tleaf(node);
			break;
		case 5:
			b.getroot(&node);
			cout<<"\nOriginal tree: ";
			b.display(node);
			b.tcopy(node,&copynode);
			cout<<"\n";
			cout<<"\nCopied tree: ";
			b.display(copynode);
			break;
		}

	}while(ch>0 && ch<6);
	return 0;
}



