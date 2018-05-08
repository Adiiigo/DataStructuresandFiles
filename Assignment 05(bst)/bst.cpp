/*
 * bst.cpp
 *
 *  Created on: 23-Apr-2017
 *      Author: acer
 */

#include "bst.h"
#include "pqueue.h"
#include<stddef.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
bst::bst() {
	// TODO Auto-generated constructor stub
	root=NULL;
}

bst::~bst() {
	// TODO Auto-generated destructor stub
	deletetree(&root);
	free(root);
	root=NULL;
}

void bst::deletetree(struct dll **dnode)
{
	if((*dnode)->lchild==NULL && (*dnode)->rchild==NULL )
	{
		free(*dnode);
		(*dnode)=NULL;

	}
	else
	{
		deletetree(&((*dnode)->lchild));
		deletetree(&((*dnode)->rchild));
	}


}

int bst::insertnode(struct dll **node,int ndata)
{
	int flag=0;
	int ret=0;
	struct dll *newnode=NULL;
	newnode=(struct dll *)calloc(1,sizeof (struct dll));
	if(newnode==NULL)
	{
		flag=1;//memory allocation failed
	}
	else
	{
		newnode->data=ndata;
		if((*node)==NULL)
		{
			if(root==NULL)
			{
				root=newnode;
			}

			(*node)=newnode;
		}
		else
		{

			if(ndata < (*node)->data)//left child
			{
				ret=insertnode(&((*node)->lchild),ndata);
			}
			else		//right child
			{
				ret=insertnode(&((*node)->rchild),ndata);
			}
		}
	}
	if(ret==0)
	{
		flag=0;
	}
	else
	{
		flag=2;
	}
	return (flag);
}



struct dll* bst::deletenode(struct dll *node,int ddata)
{

	struct dll *dnode=NULL;
	if(node==NULL)
	{
		cout<<"tree empty";
		return(node);
	}
	else
	{


		if(ddata < node->data)//left child
		{
			node->lchild=deletenode(node->lchild,ddata);
			return(node);
		}
		else
		{
			if(ddata > node->data)//left child
			{
				node->rchild=deletenode(node->rchild,ddata);
				return(node);
			}
			else
			{
				if(ddata==node->data)
				{
					if(node->lchild==NULL && node->rchild==NULL)
					{
						dnode=node;
						free(dnode);
						dnode=NULL;

					}
					else if(node->lchild==NULL)
					{
						dnode=node;
						node=node->rchild;
						free(dnode);
						(dnode)=NULL;
						return(node);
					}
					else if(node->rchild==NULL)
					{
						dnode=node;
						node=node->lchild;
						free(dnode);
						(dnode)=NULL;
						return(node);
					}
					else
					{
						dnode=node->rchild;   //two child
						while(dnode->lchild!=NULL)
						{
							dnode=dnode->lchild;
						}
						node->data=dnode->data;
						node->rchild=deletenode(node->rchild,dnode->data);
						return(node);
					}
				}
			}
		}

	}
	return(node);
}

void bst::search(struct dll **node,struct dll *snode,int ndata)
{
	if(snode!=NULL)
	{
		if(snode->data==ndata)
		{
			*node=snode;
		}
		else
		{
			search(&(*node),snode->lchild,ndata);
			search(&(*node),snode->rchild,ndata);
		}

	}
}


void bst::searchnode(struct dll *snode,int ndata,int &flag)
{
	if(ndata == snode->data)
	{
		flag=1;
	}
	else
	{
		if(ndata < snode->data)//left child
		{
			if(snode->lchild!=NULL)
			{
				searchnode(snode->lchild,ndata,flag);
			}
		}
		else
		{
			if(ndata > snode->data)		//right child
			{
				if(snode->rchild!=NULL)
				{
					searchnode(snode->rchild,ndata,flag);
				}
			}

		}
	}

}

void bst::getroot(struct dll **node)
{
	*node=root;
}


void bst::display(struct dll *node)
{
	if(node!=NULL)
	{
		display(node->lchild);
		cout<<"\t"<<node->data;
		display(node->rchild);
	}
}





//void bst::display_level(struct dll *node,int nn)
//{
//
//	int i=0;
//	nn=theight(node);
//	for(i=0;i<nn;i++)
//	{
//		printlevel(node,nn);
//	}
//
//}


void bst::display_level(struct dll *node/*,int nn*/)
{

	pqueue q1,q2;
	struct dll *p1=NULL;
	//struct dll *p2=NULL;
	if(node==NULL)
	{
		return;
	}
	else
	{
		q1.insert_ele(node);
		cout<<"\n\t"<<node->data;
		while(q1.queueempty()!=1)
		{
			cout<<"\n";
			while(q1.queueempty()!=1)
			{
				q1.delete_ele(&p1);
				if(p1->lchild!=NULL)
				{
					q2.insert_ele(p1->lchild);
					cout<<"\t"<<p1->lchild->data;
				}
				if(p1->rchild!=NULL)
				{
					q2.insert_ele(p1->rchild);
					cout<<"\t"<<p1->rchild->data;
				}
			}
			q1=q2;
		}
	}
}


//void bst::printlevel(struct dll *node,int d)
//{
//
//	if(node==NULL)
//	{
//		return ;
//	}
//	else
//	{
//		cout<<"\t"<<node->data;
//		printlevel(node->lchild,d-1);
//		printlevel(node->rchild,d-1);
//	}
//}

//int bst::theight(struct dll *node)
//{
//	int hl=0;
//	int hr=0;
//	if(root==NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		if(node->lchild==NULL && node->rchild==NULL)
//		{
//			return 0;
//		}
//		else
//		{
//			if(node->lchild!=NULL)
//			{
//				hl=theight(node->lchild);
//			}
//			if(node->rchild!=NULL)
//			{
//				hr=theight(node->rchild);
//			}
//		}
//		if(hl>hr)
//		{
//			return (hl+1);
//		}
//		else
//		{
//			return (hr+1);
//		}
//	}
//
//}

void bst::mirror(struct dll *node,struct dll **snode)
{
	if(node!=NULL)
	{
		*snode=(struct dll *)calloc(1,sizeof (struct dll));
		(*snode)->data=node->data;
		if(node->lchild!=NULL)
		{
			mirror(node->lchild,&((*snode)->rchild));
		}
		if(node->rchild!=NULL)
		{
			mirror(node->rchild,&((*snode)->lchild));
		}

	}
}

