/*
 * Dgraph.cpp
 *
 *  Created on: 24-Mar-2017
 *      Author: acer
 */

#include "Dgraph.h"
//#include </home/acer/eclipse/Sem3Workspace/FDijkstraCode/Dgraph.h>
#include<iostream>
#include<stdlib.h>
#include<stddef.h>

using namespace std;

Dgraph::Dgraph()
{
	// TODO Auto-generated constructor stub
	int i = 0 ;			//COUNTER VARIABLE
	int j = 0 ;			//COUNTER VARIABLE

	//INITILAZING ADJACENCY LIST
	for(i = 0 ; i < SIZE ; i++)
	{
		n[i].index = i+1 ;
		n[i].head = NULL ;
		n[i].last = NULL ;
	}

	//INITIALAZING ADJACENCY MATRIX
	for(i = 0 ; i < SIZE ; i++)
	{
		for(j = 0 ; j < SIZE ; j++)
		{
			mat[i][j] = 0 ;
		}
	}

	//INITIALIZING PATH ARRAY
	for(i = 0 ; i < SIZE ; i++)
	{
		cost[i] = 0 ;
	}

	//INITIALIZING VISITED ARRAY
	for(i = 0 ; i < SIZE ; i++)
	{
		visited[i] = 0 ;
	}
}

Dgraph::~Dgraph()
{
	// TODO Auto-generated constructor stub
	int i = 0 ;			//COUNTER VARIABLE
	int j = 0 ;			//COUNTER VARIABLE

	//INITILAZING ADJACENCY LIST
	for(i = 0 ; i < SIZE ; i++)
	{
		n[i].index = i+1 ;
		n[i].head = NULL ;
		n[i].last = NULL ;
	}

	//INITIALAZING ADJACENCY MATRIX
	for(i = 0 ; i < SIZE ; i++)
	{
		for(j = 0 ; j < SIZE ; j++)
		{
			mat[i][j] = 0 ;
		}
	}

	//INITIALIZING PATH ARRAY
	for(i = 0 ; i < SIZE ; i++)
	{
		cost[i] = 0 ;
	}

	//INITIALIZING VISITED ARRAY
	for(i = 0 ; i < SIZE ; i++)
	{
		visited[i] = 0 ;
	}
}

void Dgraph::createAdjMat(int fvertices)
{
	int i = 0 ;			//COUNTER VARIABLE
	int j = 0 ;			//COUNTER VARIABLE
	char ans = '\0' ;
	int weight = 0 ;

	for( i = 0 ; i < fvertices  ; i++)
	{
		cout << "\n----Vertex " << i+1 << "----" ;

		for(j = i ; j < fvertices ; j++)
		{
			if(i == j)
			{
				mat[i][j] = INF ;
				mat[j][i] = INF ;
			}
			else
			{

				cout << "\nIs there a Link Between edge " << i+1 << " and edge " << j+1 << " ?(y/n):" ;
				cin >> ans ;
				if(ans == 'Y' || ans == 'y')
				{
					cout << "\nEnter Weight Between them: " ;
					cin >> weight ;
					mat[i][j] = weight ;
					mat[j][i] = weight ;
				}
				else
				{
					mat[i][j] = INF ;
					mat[j][i] = INF ;
				}
			}
		}

	}
}

void Dgraph::displayAdjMat(int fvertices)
{
	int i = 0 ;			//COUNTER VARIABLE
	int j = 0 ;			//COUNTER VARIABLE

	cout << "\n\t";
	for(i = 0 ; i < fvertices ; i++)
	{
		cout << n[i].index ;
		cout << "\t" ;

	}

	for(i = 0 ; i < fvertices ; i++)
	{
		cout << "\n" << n[i].index << "\t";
		for(j = 0 ; j < fvertices ; j++)
		{
			cout << mat[i][j] ;
			cout << "\t" ;
		}
	}
}

void Dgraph::shortestPathMat(int fvertices , int fstart)
{
	int i = 0 ;

	//INITIALIZING PATH ARRAY
	for(i = 0 ; i < SIZE ; i++)
	{
		cost[i] = 0 ;
	}

	//INITIALIZING VISITED ARRAY
	for(i = 0 ; i < SIZE ; i++)
	{
		visited[i] = 0 ;
	}
	int index = 0 ;			//COUNTER VARIABLE
	i = 0 ;
	int j = 0 ;			//COUNTER VARIABLE

	int a[fvertices] = {0} ;
	int minCost = 0 ;
	int weight = 0 ;
	int pos = 0 ;
	int initial = 0 ;

	//STORING FOREMOST ELEMENT IN VARIABLE 'initial'
	initial = fstart ;

	//SINCE THAT ELEMENT IS VISTED SETTING VISITED ARRAY 1
	visited[fstart] = 1 ;

	//STORING ROW OF THAT ELEMENT IN COST ARRAY
	for( j = 0 ; j < fvertices ; j++)
	{
		cost[j] = mat[fstart][j] ;
	}

	//FINDING MINIMUM IN COST ARRAY
	i = 0 ;
	j = 0 ;
	weight = cost[0] ;
	pos = 0 ;
	for( j = i+1 ; j < fvertices ; j++)
	{
		if(weight > cost[j] && visited[j] != 1)
		{
			weight = cost[j] ;
			pos = j ;
		}
	}

	//STORING THE MINIMUM WEIGHT IN 'minCost'
	minCost = weight ;

	//NOW WE HAVE TO START FROM THE VERTEX WE LAST VISITED => STORE IT IN THE POS
	fstart = pos ;

	//SINCE THAT ELEMENT IS VISTED SETTING VISITED ARRAY 1
	visited[fstart] = 1 ;

	//PRINTING THE OUTPUT
	cout << "\n\t\tMinimum Path Between:" ;
	cout << "\n" <<initial+1 << "---->" ;
	cout << "\t" << pos+1 << ":" << minCost ;

	//FROM HERE SECOND VERTEX CALACULATION STARTS

	//STORING AL VALUES OF COST IN A ARRAY 'a'
	for(i = 0 ; i < fvertices ; i ++)
	{
		a[i] = cost[i] ;
	}

	index = 0 ;
	while(index < fvertices-2 )
	{
		//STORING ALL VALUES OF 'j'TH ROW IN COST ARRAY ADDING minCost TO EVERY VALUE
		for( j = 0 ; j < fvertices ; j++)
		{
			cost[j] = mat[fstart][j] + minCost ;
		}

		//FOR COMPARING THE PREVIOUS VALUE OF THAT POSTION WITH NEW VALUE
		//STORING THE MINIMUM VALUE IN THE 'cost'  ARRAY
		for(j = 0 ; j < fvertices ; j++)
		{
			if(a[j] < cost[j] && visited[j] != 1)
			{
				cost[j] = a[j] ;
			}
		}

		i = 0 ;
		j = 0 ;
		weight = cost[0] ;
		pos = 0 ;
		for( j = i+1 ; j < fvertices ; j++)
		{
			if(weight > cost[j] && visited[j] != 1)
			{
				weight = cost[j];
				pos = j ;
			}
		}

		//STORING THE MINIMUM WEIGHT IN 'minCost'
		minCost =  weight ;

		//NOW WE HAVE TO START FROM THE VERTEX WE LAST VISITED => STORE IT IN THE POS
		fstart = pos ;

		//SINCE THAT ELEMENT IS VISTED SETTING VISITED ARRAY 1
		visited[fstart] = 1 ;

		//PRINTING THE OUTPUT
		cout << "\n" <<initial+1 << "---->" ;
		cout << "\t" << pos+1 << ":" << minCost ;

		//STORING AL VALUES OF COST IN A ARRAY 'a'
		for(j = 0 ; j < fvertices ; j ++)
		{
			a[j] = cost[j] ;
		}
		index++ ;
	}
}
