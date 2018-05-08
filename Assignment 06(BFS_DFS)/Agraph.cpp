/*
 * Agraph.cpp
 *
 *  Created on: 16-Mar-2017
 *      Author: acer
 */

#include<iostream>
#include</home/acer/eclipse/Sem3Workspace/Facebook_assig/Agraph.h>
#include </home/acer/eclipse/Sem3Workspace/Facebook_assig/gqueue.h>
#include </home/acer/eclipse/Sem3Workspace/Facebook_assig/stack.h>
#include<stddef.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

Agraph::Agraph()
{
	// TODO Auto-generated constructor stub
	int i = 0 ;			//COUNTER VARIABLE

	//INITIALIZING ADJACENTCY LIST
	for(i = 0 ; i < SIZE ; i++)
	{
		d[i].index = -1 ;
		d[i].month = 0 ;
		d[i].noc = -1 ;
		d[i].head = NULL ;
		d[i].last = NULL ;
	}

	//INITIALIZING ADJACENTCY MATRIX
	/*for(i = 0 ; i < SIZE ; i++)
	{
		for(j = 0 ; j < SIZE ; j++)
		{
			if(i == j)
			{
				m[i][j] = 0 ;
			}
			else
			{
				m[i][j] =- 1 ;
			}
		}
	}*/

	//INITIALIZING VISITED ARRAY
	for(i = 0 ; i < SIZE ; i++)
	{
		v[i].vname = '\0';
		v[i].vindex = 0;
	}
}

Agraph::~Agraph()
{
	// TODO Auto-generated destructor stub
}

/*void Agraph::createAdjMatrix(int fvertices)
{
	int i = 0 ;			//COUNTER VARIABLE
	int j = 0 ;			//COUNTER VARIABLE
	char ans  = '\0' ;

	for(i = 0 ; i < fvertices ; i++)
	{
		cout << "\n*******************************************************";
		cout<<"\n\t\tFOR VERTEX "<<i+1;
		cout << "\n\nEnter Name of Vertex " << i+1<<" : " ;
		cin >> 	v[i].vname;

		for(j = i+1 ; j < fvertices ; j++)		{

			cout << "\n-------------------------------------";
			cout << "\n\nIs There Exists An Edge Between Vertex "<<i+1<<" and Vertex "<<j+1<< " ?(y/n) :";
			cin >> ans ;
			if(ans == 'Y' || ans == 'y')
			{
				m[i][j] = 1 ;
				m[j][i] = 1 ;
			}
			else
			{
				m[i][j] = 0 ;
				m[j][i] = 0 ;
			}
		}
	}
	cout << "\n*******************************************************";
}*/

void Agraph::createAdjList(int fvertices)
{
	struct node *newnode = NULL ;
	struct node *snewnode = NULL ;

	int i = 0 ;			//COUNTER VARIABLE
	int j = 0 ;			//COUNTER VARIABLE
	char ans = '\0' ;

	for(i = 0 ; i < fvertices ; i++ )
	{
		d[i].index = i+1;
	}

	i = 0 ;
	while(i < fvertices)
	{
		cout << "\n-------------------------------------";

		cout << "\n\nEnter Name of Vertex " << i+1<<" : " ;
		cin >> d[i].name ;
		v[i].vname = d[i].name ;

		cout << "\n\nEnter Date Of Month No.:" ;
		cin >> d[i].month ;

		cout << "\n\nEnter No. Of Comments :" ;
		cin >> d[i].noc ;

		j = i+1 ;
		while( j < fvertices )
		{
			cout << "\n\nIs There A Link Between Vertex "<< i+1 << " and Vertex " << j+1 << " ?(y/n) :" ;
			cin>> ans ;

			if(ans == 'Y' || ans == 'y')
			{
				newnode = (struct node*)calloc(1,sizeof(struct node));
				snewnode = (struct node*)calloc(1,sizeof(struct node));

				if(newnode == NULL && snewnode == NULL)
				{
					cout << "\n\n\t\tMemory Allocation Unsuccessful" ;
				}
				else
				{
					cout << "\n\n\t\tMemory Allocation Successful" ;
					cout << "\n\t\tNode "<< j+1<<" Linked" ;

					//LINKING I->J
					newnode->cindex = j+1 ;

					if(d[i].head == NULL)
					{
						d[i].head = newnode ;
						d[i].last = newnode ;
					}
					else
					{
						d[i].last->cnext=newnode;
						d[i].last = newnode;
					}

					//LINKING J->I
					snewnode->cindex = i+1 ;

					if(d[j].head == NULL)
					{
						d[j].head = snewnode ;
						d[j].last = snewnode ;
					}
					else
					{
						d[j].last->cnext = snewnode ;
						d[j].last = snewnode ;
					}
				}
			}
			else
			{
				//DO NOTHING
			}
			j++;
		}
		i++;
	}
}

/*void Agraph::displayAdjMatrix(int fvertices)
{
	int i = 0 ;			//COUNTER VARIABLE
	int j = 0 ;			//COUNTER VARIABLE

	cout << "\n";
	for(i = 0 ; i < fvertices ; i++)
	{
		for(j = 0 ; j < fvertices ; j++)
		{
			cout << "\t" << m[i][j] ;
		}
		cout << "\n";
	}
}*/

void Agraph::displayAdjList(int fvertices)
{
	int i = 0 ;			//COUNTER VARIABLE
	struct node *j = NULL ;

	cout << "\n\nIndex\tVertex 1\tConnected Vertices";
	for(i = 0 ; i < fvertices ; i++)
	{
		cout << "\n" << i+1;
		cout << "\t" << d[i].name << "-->\t" ;
		for( j = d[i].head ; j != NULL  ; j = j->cnext )
		{
			cout << "\t" << j->cindex ;
		}
	}
}

void Agraph::depthFirstSearch(int fvertices)
{
	int i = 0 ;			//COUNTER VARIABLE FOR 'while' LOOP
	int j = 0 ;			//COUNTER VARIABLE FOR 'do-while' LOOP
	struct node *k = 0 ;		//COUNTER VARIABLE FOR PUSHING LINKED VALUES

	stack s;
	int sflag = -2 ;
	int ssize = -1 ;
	char ddata = '\0';		//STORE THE EXTRACTED CHAR FROM THE STACK
	int maxComment = -1 ;
	char maxCommentEle = '\0' ;
	int pos = -1 ;
	int visitedCount =0 ;

	//ASSUMING FIRST PERSON HAS MAXIMUM COMMENTS
	maxComment = d[i].noc ;
	maxCommentEle = d[i].name ;
	v[i].vindex = 1 ;

	//PUSHING ALL LINKED VERTICES OF THE FIRST PERSON TO THE STACK
	for( k = d[i].head ; k != NULL ; k = k->cnext)
	{
		pos = k->cindex ;
		pos--;
		if(v[pos].vindex != 1 )
		{
			sflag = s.push(ssize ,d[pos].name);
			if(sflag == 1)
			{
				cout << "\n\n\t\tInsertion Successfully Happened" ;
			}
			else if(sflag == 0)
			{
				cout << "\n\n\t\tInsertion Failed" ;
			}
			else if(sflag == -1)
			{
				cout << "\n\n\t\tMemory Full Failure ";
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}
		}
	}

	do
	{
		visitedCount = 0 ;
		//POP A PERSON
		sflag = s.pop( ssize,ddata ) ;
		if(sflag == 1)
		{
			cout << "\n\n\t\tDeletion Successful" ;
			cout << "\n\t\tToppest Value: " << ddata ;
		}
		else if(sflag == 0)
		{
			cout << "\n\n\t\tDeletion Failed" ;
		}
		else
		{
			cout << "\n\n\t\tFunction Failure" ;
		}

		//TO FIND WHICH PERSON IS POPPED OUT

		for(j = 0 ; j < fvertices ; j++)
		{
			if(d[j].name == ddata)
			{
				pos = j ;
				if(maxComment < d[j].noc && v[j].vindex != 1)
				{
					maxComment = d[j].noc ;
					maxCommentEle = d[j].name ;
				}
				v[j].vindex = 1;
				j = fvertices ;			//FOR COMING OUT OF THE 'for' LOOP
			}
		}

		//PUSHING ALL LINKED VERTICES OF THAT PERSON TO THE STACK
		for( k = d[pos].head ; k != NULL ; k = k->cnext)
		{
			pos = k->cindex ;
			pos--;
			if(v[pos].vindex != 1)
			{
				sflag = s.push(ssize ,d[pos].name);
				if(sflag == 1)
				{
					cout << "\n\n\t\tInsertion Successfully Happened" ;
				}
				else if(sflag == 0)
				{
					cout << "\n\n\t\tInsertion Failed" ;
				}
				else if(sflag == -1)
				{
					cout << "\n\n\t\tMemory Full Failure ";
				}
				else
				{
					cout << "\n\n\t\tFunction Failure" ;
				}
			}
		}

		for(i = 0 ; i < fvertices ; i++ )
		{
			if(v[i].vindex == 1)
			{
				visitedCount++ ;
			}
		}
	}while( visitedCount != fvertices);

	cout<<"\n\tMax no. of Comments is " << maxComment << " by Element " << maxCommentEle ;

}
/*void Agraph::breadthFirstsearch(int fvertices)
{
	int i = 0 ;			//COUNTER VARIABLE FOR 'while' LOOP
	int j = 0 ;			//COUNTER VARIABLE FOR 'do-while' LOOP

	gqueue g;

	int qflag = -1 ;
	int qsize = -1 ;

	char ddata = '\0';		//STORE THE EXTRACTED CHAR FROM THE STACK
	int maxComment = -1 ;
	char maxCommentEle = '\0' ;
	int pos = -1 ;
	int visitedCount = 0 ;

	struct node *k = 0 ;		//COUNTER VARIABLE FOR PUSHING LINKED VALUES

	//ASSUMING FIRST PERSON HAS MAXIMUM COMMENTS
	maxComment = d[i].noc ;
	maxCommentEle = d[i].name ;
	v[i].vindex = 1 ;

	//PUSHING ALL LINKED VERTICES OF THE FIRST PERSON TO THE STACK
	for( k = d[i].head ; k != NULL ; k = k->cnext)
	{
		pos = k->cindex ;
		pos--;
		if(v[pos].vindex != 1 )
		{
			qflag = g.insertgq(qsize ,d[pos].name);
			switch(qflag)
			{
				case -1: cout << "\n\n\t\tDidnt Enter Function" ;
					   	 break ;

				case 2:	cout << "\n\t\tSuccessful Addition" ;
					   	break ;
			}
		}
	}

	do
	{
		visitedCount = 0 ;
		qflag = g.deletegq(qsize,ddata) ;
		switch(qflag)
		{
			case -1: cout << "\n\n\t\tDidnt Enter Function" ;
					 break;

			case 2: cout << "\n\n\t\tExtraction Successful" ;
					cout << "\n\t\tDeleted Data:" << ddata ;
					break ;

		}

		//TO FIND WHICH DATA IS POPPED OUT
		j = 0 ;
		do
		{
			if(d[j].name == ddata)
			{
				pos = j ;

				if(maxComment < d[j].noc  && v[j].vindex != 1)
				{
					maxComment = d[j].noc ;
					maxCommentEle = d[j].name ;

				}
				else
				{
					//DO NOTHING
				}
				v[j].vindex = 1;
				j = fvertices ;			//FOR COMING OUT OF THE 'do-while' LOOP
			}
			else
			{
				j++ ;
			}
		}while( j < fvertices );

		//PUSHING ALL LINKED VERTICES OF THAT PERSON TO THE STACK
		for( k = d[pos].head ; k != NULL ; k = k->cnext)
		{
			pos = k->cindex ;
			pos--;
			if(v[pos].vindex != 1 )
			{
				qflag = g.insertgq(qsize ,d[pos].name);
				switch(qflag)
				{
					case -1: cout << "\n\n\t\tDidnt Enter Function" ;
						   	 break ;

					case 2:	cout << "\n\t\tSuccessful Addition" ;
						   	break ;
				}
			}
		}

		for(i = 0 ; i < fvertices ; i++)
		{
			if(v[i].vindex == 1)
			{
				visitedCount++;
			}
		}
	}while(visitedCount != fvertices);

	cout<<"\n\tMax no. of Comments is " << maxComment << " by Element " << maxCommentEle ;
}*/

void Agraph::maxFriends(int fvertices)
{
	stack s ;
	int sflag = -2 ;
	int ssize = -1 ;

	int i = 0 ;			//COUNTER VARIABLE
	int j = 0 ;			//COUNTER VARIABLE FOR 'do-while' LOOP
	int count = 0 ;
	char ddata = '\0' ;

	int maxFriends = -1 ;
	char maxFriendsEle = '\0' ;

	struct node *k = 0 ;		//COUNTER VARIABLE FOR PUSHING LINKED VALUES
	int pos = -1 ;
	int visitedCount = 0 ;

	//FINDING MAX FRIENDS CONSIDERING FIRST ELEMENT HAS MAXIMUM FRIENDS AND SIMULATANEOUSLY PUSHING THEM ON THE STACK
	maxFriendsEle = d[0].name ;
	v[0].vindex = 1 ;
	for(k = d[0].head ; k != NULL ; k= k->cnext)
	{
		count++;
		pos = k->cindex ;
		pos--;
		if(v[pos].vindex != 1)
		{
			sflag = s.push(ssize , d[pos].name) ;
			if(sflag == 1)
			{
				cout << "\n\n\t\tInsertion Successfully Happened" ;
			}
			else if(sflag == 0)
			{
				cout << "\n\n\t\tInsertion Failed" ;
			}
			else if(sflag == -1)
			{
				cout << "\n\n\t\tMemory Full Failure ";
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}
		}
	}
	maxFriends = count ;

	do
	{
		visitedCount = 0 ;
		//POP A PERSON
		sflag = s. pop(ssize , ddata);
		if(sflag == 1)
		{
			cout << "\n\n\t\tDeletion Successful" ;
			cout << "\n\t\tToppest Value: " << ddata ;
		}
		else if(sflag == 0)
		{
			cout << "\n\n\t\tDeletion Failed" ;
		}
		else
		{
			cout << "\n\n\t\tFunction Failure" ;
		}

		//TO FIND WHICH DATA IS POPPED OUT
		for(j = 0 ; j < fvertices ; j++)
		{
			if(d[j].name == ddata)
			{
				pos = j ;
				j = fvertices ;			//FOR COMING OUT OF THE 'for' LOOP
			}
		}

		//COUNTING AND PUSHING ALL THE FRIENDS OF THAT PERSON
		j = pos ;
		count = 0 ;
		for(k = d[pos].head ; k != NULL ; k= k->cnext)
		{
			count++;
			pos = k->cindex ;
			pos--;
			if(v[pos].vindex != 1)
			{
				sflag = s.push(ssize , d[pos].name) ;
				if(sflag == 1)
				{
					cout << "\n\n\t\tInsertion Successfully Happened" ;
				}
				else if(sflag == 0)
				{
					cout << "\n\n\t\tInsertion Failed" ;
				}
				else if(sflag == -1)
				{
					cout << "\n\n\t\tMemory Full Failure ";
				}
				else
				{
					cout << "\n\n\t\tFunction Failure" ;
				}
			}
		}

		//COMPARING AND STORING MAX NUMBER
		if(maxFriends < count)
		{
			maxFriends = count ;
			maxFriendsEle = ddata ;
		}

		v[j].vindex = 1;
		

		for(i = 0 ; i < fvertices ; i++)
		{
			if(v[i].vindex == 1)
			{
				visitedCount++;
			}
		}
	}while(visitedCount != fvertices );

	cout << "\n\n\t\tPerson "<< (maxFriendsEle) << " has maximum friends with Maximum Friend count " << maxFriends ;
}

void Agraph::getUserCount(int fmonth , int fvertices)
{
	gqueue q ;
	int qflag = -2 ;
	int qsize = -1 ;

	int i = 0 ;			//COUNTER VARIABLE FOR 'while' LOOP
	int j = 0 ;			//COUNTER VARIABLE FOR 'do-while' LOOP
	char ddata = '\0' ;

	struct node *k = 0 ;			//COUNTER VARIABLE FOR PUSHING LINKED VALUES
	int pos = -1 ;
	char name[fvertices] = {'\0'} ;
	int x = 0 ;
	int visitedCount = 0 ;

	//INITIALIZING VISITED ARRAY
	for(i = 0 ; i < fvertices ; i++)
	{
		v[i].vindex = 0;
	}

	//CHECKING IF THE FIRST PERSON IS BORN ON THAT MONTH
	i = 0 ;
	if(d[i].month == fmonth)
	{
		name[x] = d[i].name;
		x++ ;
	}
	v[i].vindex = 1 ;

	//PUSHING ALL LINKED VERTICES OF THE FIRST PERSON TO THE QUEUE
	for( k = d[i].head ; k != NULL ; k = k->cnext)
	{
		pos = k->cindex ;
		pos--;
		if(v[pos].vindex != 1)
		{
			qflag = q.insertgq(qsize ,d[pos].name);
			switch(qflag)
			{
				case -1: cout << "\n\n\t\tDidnt Enter Function" ;
					   	 break ;

				case 2:	cout << "\n\t\tSuccessful Addition" ;
					   	break ;
			}
		}
	}

	do
	{
		visitedCount = 0 ;
		//DELETING THE FRONTMOST PERSON
		qflag = q.deletegq(qsize,ddata) ;
		switch(qflag)
		{
			case -1: cout << "\n\n\t\tDidnt Enter Function" ;
					 break;

			case 2: cout << "\n\n\t\tExtraction Successful" ;
					cout << "\n\t\tDeleted Data:" << ddata ;
					break ;

		}

		//TO FIND WHICH DATA IS POPPED OUT
		j = 0 ;
		for(j = 0 ; j < fvertices ; j++)
		{
			if(d[j].name == ddata)
			{
				pos = j ;
				j = fvertices ;			//FOR COMING OUT OF THE 'for' LOOP
			}
		}

		j = pos ;

		//CHECKING IF THAT PERSON IS BORN IN THAT MONTH
		if(d[pos].month == fmonth)
		{
			name[x] = d[pos].name ;
			x++;
		}

		//PUSHING ALL LINKED VERTICES OF THE THAT PERSON TO THE QUEUE
		for( k = d[pos].head ; k != NULL ; k = k->cnext)
		{
			pos = k->cindex ;
			pos--;
			if(v[pos].vindex != 1)
			{
				qflag = q.insertgq(qsize ,d[pos].name);
				switch(qflag)
				{
					case -1: cout << "\n\n\t\tDidnt Enter Function" ;
						   	 break ;

					case 2:	cout << "\n\t\tSuccessful Addition" ;
						   	break ;
				}
			}
		}

		v[j].vindex = 1 ;
	
		for(i = 0 ; i < fvertices ; i++)
		{
			if(v[i].vindex == 1)
			{
				visitedCount++;
			}
		}

	}while(visitedCount != fvertices) ;

	//DISPLAYING OUTPUT
	if( x != 0 )
	{
		cout << "\n\t\t";
		cout << "People with Birthmonth " << fmonth << " is " ;
		for( i = 0 ; i < x ; i++ )
		{
			cout << name[i] ;
			cout << "\t" ;
		}
	}
	else
	{
		cout << "\n\t\tNO Person is not born in " << fmonth << " month" ;
	}
}
