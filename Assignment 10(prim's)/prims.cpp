/*
 * prims.cpp
 *
 *  Created on: 19-Apr-2017
 *      Author: acer
 */

#include "prims.h"

#include "prims.h"
#include<iostream>
#include<stdio_ext.h>
using namespace std ;

prims::prims()
{
	// TODO Auto-generated constructor stub

}

prims::~prims()
{
	// TODO Auto-generated destructor stub
}

void prims::init( void )
{
	int i = 0 ;

	for( i = 0 ; i < SIZE ; i++ )
	{
		vertex[i] = 0 ;
		dist[i] = 0 ;
		path[i] = 0 ;
		visited[i] = 0 ;
	}
}

int prims::menu( void )
{
	int ch = 0 ;

	do
	{
		cout << "\n\n\t.......MAIN MENU......." ;
		cout << "\n\t 1. Create network " ;
		cout << "\n\t 2. Find minimum cost to connect all offices using phone lines " ;
		cout << "\n\t 0. Exit " ;
		cout << "\n\t Enter your choice : " ;
		cin >> ch ;

	}while( ch < 0 || ch > 2 ) ;

	return ch ;
}

void prims::create( int num )
{
	int i = 0 ;
	int j = 0 ;
	char ans = '\0' ;

	init() ;

	for( i = 0 ; i < num ; i++ )
	{
		for( j = 0 ; j < num ; j++ )
		{
			if( i == j )
			{
				cost[i][j] = 0 ;
			}
			else
			{
				cost[i][j] = INF ;
			}
		}
	}

	for( i = 0 ; i < num ; i++ )
	{
		for( j = i+1 ; j < num ; j++ )
		{
			cout << "\n\n Do you want to connect " << i << " office and " << j << " office : " ;
			__fpurge(stdin) ;
			cin >> ans ;

			if( ans == 'y' || ans == 'Y' )
			{
				cout << "\n Enter the cost of the phone line to be laid between " << i << " and " << j << " office : " ;
				cin >> cost[i][j] ;

				cost[j][i] = cost[i][j] ;
			}
			else
			{
				//do nothing edge does not exists
			}
		}
	}
}


int prims::mstprims( int num )
{
	int i = 0 ;
	int j = 0 ;
	int k = 0 ;
	int n = 0 ;
	int v = 0 ;
	int l = 0 ;
	int min = INF ;
	int flag = 0 ;
	int weight = 0 ;

	for( i = 0 ; i < SIZE ; i++ )
	{
		vertex[i] = 0 ;
		dist[i] = 0 ;
		path[i] = 0 ;
		visited[i] = 0 ;
	}

	cout << "\n Enter starting vertex : " ;
	cin >> v ;

	visited[v] = 1 ;

	do
	{
		path[k] = v ;		//including the selected vertex in the path array

		min = INF ;		//initializing min to infinity for each loop to compare the min correctly
		n = 0 ;			//for each loop new set of vertices will be selected in vertex array

		for( l = 0 ; l <= k ; l++ )		//checking for each vertex in the path array
		{
			for( i = 0 ; i < num ; i++ )	//for start vertex
			{
				for( j = 0 ; j < num ; j++ )	//for end vertex
				{
					if( i == path[l] )			//checking for starting vertex
					{
						if( visited[j] != 1 )		//checking for end vertex whose visited is != 1
						{
							vertex[n] = j ;		//if end vertex's visited is not one store it in vertex array
							dist[n] = cost[i][j] ;		//storing its cost in dist array
							n++ ;
						}
					}
				}
			}
		}

		for( i = 0 ; i < n ; i++ )		//checking for which vertex has min dist
		{
			if( min > dist[i] )
			{
				min = dist[i] ;
				v = vertex[i] ;			//storing the vertex with min dist for next loop
			}
		}

		cout << "\n\n OFFICE SELECTED = " << v ;
		visited[v] = 1 ;	//mark the visited of the selected vertex to 1

		k++ ;

		cout << "\n MIN = " << min ;

		for( i = 0 ; i < num ; i++ )	//for stopping the algo when the visited of all vertices is 1
		{
			if( visited[i] == 1 )
			{
				flag = 1 ;
			}
			else
			{
				flag = 0 ;
				i = num ;
			}
		}

		weight = weight + min ;		//total final cost

		if( flag == 1 )
		{
			path[k] = v ;		//adding last vertex to th path array
			k++ ;
		}

	}while( flag != 1 ) ;

	cout << "\n\n Path to connect the offices is : " ;

	for( i = 0 ; i < num ; i++ )
	{
		cout << "\t" << path[i] ;
	}

	return weight ;
}

int prims::mst(int fvertices)
{
	int i = 0 ;
	int fstart = 0 ;
	int visitedCount = 0 ;
	int k = 0 ;
	int l = 0 ;
	int j = 0 ;
	int n = 0 ;
	int min = 0 ;
	int minWeight = 0 ;

	for(i = 0 ; i < fvertices ; i++)
	{
		visited[i] = 0  ;
		path[i] = 0 ;
		vertex[i] = 0 ;
		dist[i] = 0 ;
	}

	cout << "\nEnter Start Vertex" ;
	cin >> fstart ;

	visited[fstart] = 1 ;

	do
	{
		path[k] = fstart ;
		visitedCount = 0 ;
		int n = 0 ;
		min = 99999;

		for(l = 0 ; l <= k ; l++)
		{
			for(i = 0 ; i < fvertices ; i++)
			{
				if(path[l] == i)
				{
					for(j = 0 ; j < fvertices ; j++)
					{
						if(visited[j] != 1)
						{
							dist[n] = cost[i][j] ;
							vertex[n] = j ;
							n++;
						}
					}
				}
			}
		}

		for(i = 0 ; i < n ; i++)
		{
			if(min > dist[i])
			{
				min = dist[i] ;
				fstart = vertex[i] ;
			}
		}
		visited[fstart] = 1 ;
		minWeight = minWeight + min ;
		k++ ;

		for(i = 0 ; i <fvertices ; i++)
		{
			if(visited[i] == 1)
			{
				visitedCount++ ;
			}
		}

		if(visitedCount == fvertices)
		{
			path[k] = fstart;
			k++;
		}
	}while(visitedCount != fvertices);

	cout << "\n\n Path to connect the offices is : " ;

	for( i = 0 ; i < fvertices ; i++ )
	{
		cout << "\t" << path[i] ;
	}

	return minWeight ;

}




