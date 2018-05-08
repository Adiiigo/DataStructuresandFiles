/*
 * btree.cpp
 *
 *  Created on: 05-Feb-2017
 *      Author: administrator
 */

#include </home/acer/eclipse/test/PBT/btree.h>
#include<stddef.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

btree::btree()
{
	// TODO Auto-generated constructor stub
	root=NULL;
}

btree::~btree() {
	// TODO Auto-generated destructor stub

		deletenode(&root);
		free(root);
		root=NULL;

}
void btree::deletenode(struct dll **dnode)
{
	if((*dnode)->lchild==NULL && (*dnode)->rchild==NULL )
	{
		free(*dnode);
		(*dnode)=NULL;

	}
	else
	{
		deletenode(&((*dnode)->lchild));
		deletenode(&((*dnode)->rchild));
	}


}

int btree::insertnode(struct dll **node,int child,int ndata)
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

			if(child==1)//left child
			{
				ret=insertnode(&((*node)->lchild),child,ndata);
			}
			else if(child==3)		//right child
			{
				ret=insertnode(&((*node)->rchild),child,ndata);
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


void btree::search(struct dll **node,struct dll **snode,int parent)
{
	if((*snode)!=NULL)
	{
		if((*snode)->data==parent)
		{
			*node=(*snode);
		}
		else
		{
			search(&(*node),&((*snode)->lchild),parent);
			search(&(*node),&((*snode)->rchild),parent);
		}

	}
}


void btree::getroot(struct dll **node)
{
	*node=root;
}


void btree::display(struct dll *node)
{
	if(node!=NULL)
	{
		display(node->lchild);
		cout<<"\t"<<node->data;
		display(node->rchild);
	}
}



int btree::theight(struct dll *node)
{
	int hl=0;
	int hr=0;
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		if(node->lchild==NULL && node->rchild==NULL)
		{
			return 0;
		}
		else
		{
			if(node->lchild!=NULL)
			{
				hl=theight(node->lchild);
			}
			if(node->rchild!=NULL)
			{
				hr=theight(node->rchild);
			}
		}
		if(hl>hr)
		{
			return (hl+1);
		}
		else
		{
			return (hr+1);
		}
	}

}


void btree::tleaf(struct dll *node)
{
	if(root==NULL)
	{
		cout<<"\n NO leaf node as tree is empty";
	}
	else
	{
		if(root->lchild==NULL && root->rchild==NULL)
		{
			cout<<"\n NO leaf node as tree has only root node";
		}
		else
		{

			if(node->lchild==NULL && node->rchild==NULL && node!=root)
			{
				cout<<"\n\t"<<node->data;
			}
			else
			{
				if(node->lchild!=NULL)
				{
					tleaf(node->lchild);
				}
				if(node->rchild!=NULL)
				{
					tleaf(node->rchild);
				}
			}
		}
	}

}



void btree::tcopy(struct dll *node,struct dll **snode)
{
	if(node!=NULL)
	{
		*snode=(struct dll *)calloc(1,sizeof (struct dll));
		(*snode)->data=node->data;
		if(node->lchild!=NULL)
		{
			tcopy(node->lchild,&((*snode)->lchild));
		}
		if(node->rchild!=NULL)
		{
			tcopy(node->rchild,&((*snode)->rchild));
		}

	}
}
