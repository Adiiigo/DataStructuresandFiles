/*
 * Kgraph.cpp
 *
 *  Created on: 18-Mar-2017
 *      Author: acer
 */

#include</home/acer/eclipse/Sem3Workspace/KruskalCode/Kgraph.h>
#include<stddef.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

Kgraph::Kgraph()
{
	// TODO Auto-generated constructor stub
	int i = 0 ;			//COUNTER VARIABLE
	int j = 0 ;			//COUNTER VARIABLE

	//INITIALIZING ADJACENTCY LIST
	for(i = 0 ; i < SIZE ; i++)
	{
		v[i].vindex = -1 ;
		v[i].vname = '\0' ;
		v[i].vhead = NULL ;
		v[i].vlast = NULL ;
	}

	//INITIALIZING ADJACENTCY MATRIX
	for(i = 0 ; i < SIZE ; i++)
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
	}

	//INITIALIZING VISITED ARRAY
	for(i = 0 ; i < SIZE ; i++)
	{
		varray[i].name = '\0';
		varray[i].flag = 0;
	}

	//INITIALIZING Edge ARRAY
	for(i = 0 ; i < SIZ ; i++)
	{
		e[i].sindex = -1;
		e[i].eindex = -1;
		e[i].weight = -1;
	}
}

Kgraph::~Kgraph()
{
	// TODO Auto-generated destructor stub
}

void Kgraph::createAdjMatrix(int fvertices, int &fedges)
{
	int i = 0 ;			//COUNTER VARIABLE
	int j = 0 ;			//COUNTER VARIABLE
	char ans  = '\0' ;
	int weight = 0 ;

	for(i = 0 ; i < fvertices ; i++)
	{
		cout << "\n*******************************************************";
		cout<<"\n\t\tFOR VERTEX "<<i+1;
		cout << "\n\nEnter Name of Vertex " << i+1<<" : " ;
		cin >> 	varray[i].name;

		for(j = i+1 ; j < fvertices ; j++)		{

			cout << "\n-------------------------------------";
			cout << "\n\nIs There Exists An Edge Between Vertex "<<i+1<<" and Vertex "<<j+1<< " ?(y/n) :";
			cin >> ans ;
			if(ans == 'Y' || ans == 'y')
			{
				cout << "\nEnter weight Between Them:" ;
				cin >> weight ;
				m[i][j] = weight ;
				m[j][i] = weight ;
				e[fedges].sindex = i ;
				e[fedges].eindex = j ;
				e[fedges].weight = weight ;
				fedges++;
			}
			else
			{
				m[i][j] = 0 ;
				m[j][i] = 0 ;
			}
		}
	}
	cout << "\n*******************************************************";
}

void Kgraph::createAdjList(int fvertices, int &fedges)
{
	struct hnode *newnode = NULL ;
	struct hnode *snewnode = NULL ;
	int weight = 0 ;

	int i = 0 ;			//COUNTER VARIABLE
	int j = 0 ;			//COUNTER VARIABLE
	char ans = '\0' ;

	for(i = 0 ; i < fvertices ; i++ )
	{
		v[i].vindex = i+1;
	}

	i = 0 ;
	while(i < fvertices)
	{
		cout << "\n-------------------------------------";

		cout << "\n\nEnter Name of Vertex " << i+1<<" : " ;
		cin >> v[i].vname ;
		varray[i].name = v[i].vname ;

		j = i+1 ;
		while( j < fvertices )
		{
			cout << "\nIs There A Link Between Vertex "<< i+1 << " and Vertex " << j+1 << " ?(y/n) :" ;
			cin>> ans ;

			if(ans == 'Y' || ans == 'y')
			{
				newnode = (struct hnode*)calloc(1,sizeof(struct hnode));
				snewnode = (struct hnode*)calloc(1,sizeof(struct hnode));

				if(newnode == NULL && snewnode == NULL)
				{
					cout << "\n\n\t\tMemory Allocation Unsuccessful" ;
				}
				else
				{
					//cout << "\n\n\t\tMemory Allocation Successful" ;
					cout << "\n\t\tNode "<< j+1<<" Linked" ;

					cout << "\nEnter weight Between Them:" ;
					cin >> weight ;

					newnode->hindex = j+1 ;
					newnode->hweight = weight ;

					e[fedges].sindex = i ;
					e[fedges].eindex = j ;
					e[fedges].weight = weight ;
					fedges++;

					if(v[i].vhead == NULL)
					{
						v[i].vhead = newnode ;
						v[i].vlast = newnode ;
					}
					else
					{
						v[i].vlast->hnext=newnode;
						v[i].vlast = newnode;
					}

					snewnode->hindex = i+1 ;
					snewnode->hweight = weight ;

					if(v[j].vhead == NULL)
					{
						v[j].vhead = snewnode ;
						v[j].vlast = snewnode ;
					}
					else
					{
						v[j].vlast->hnext = snewnode ;
						v[j].vlast = snewnode ;
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

void Kgraph::displayAdjMatrix(int fvertices)
{
	int i = 0 ;			//COUNTER VARIABLE
	int j = 0 ;			//COUNTER VARIABLE

	cout << "\n" ;
	for(i = 0 ; i < fvertices ; i++)
	{
		cout << "\t" <<varray[i].name ;
	}

	cout << "\n";
	for(i = 0 ; i < fvertices ; i++)
	{
		cout << varray[i].name ;
		for(j = 0 ; j < fvertices ; j++)
		{
			cout << "\t" << m[i][j] ;
		}
		cout << "\n";
	}
}

void Kgraph::displayVisitedArray(int fvertices)
{
	int i = 0 ;			//COUNTER VARIABLE

	cout << "\nName\t" ;
	for(i = 0 ; i < fvertices ; i++)
	{
		cout << varray[i].name << "\t";
	}

	cout << "\nIndex\t" ;
	for(i = 0 ; i < fvertices ; i++)
	{
		cout << varray[i].flag << "\t";
	}
}
void Kgraph::displayEdgeArray(int fedges)
{
	int i = 0 ;			//COUNTER VARIABLE

	cout << "\n\tStartI\tEndI\tWeight" ;
	for(i = 0 ; i < fedges ; i++)
	{
		cout << "\n\t";
		cout << e[i].sindex;
		cout << "\t" ;
		cout << e[i].eindex;
		cout << "\t" ;
		cout << e[i].weight;
		cout << "\t" ;
	}
}

void Kgraph::displayAdjList(int fvertices)
{
	int i = 0 ;			//COUNTER VARIABLE
	struct hnode *j = NULL ;

	cout << "\n\nIndex\tVertex 1\tConnected Vertices";
	for(i = 0 ; i < fvertices ; i++)
	{
		cout << "\n" << i+1;
		cout << "\t" << v[i].vname << "-->\t" ;
		for( j = v[i].vhead ; j != NULL  ; j = j->hnext )
		{
			cout << "\t" << j->hindex ;
		}
	}
}

void Kgraph::minimumSpanningTree( int fvertices , int fedges )
{
	cout << "\n\n\t---Displaying UNSORETD Edge Array--- " ;
	displayEdgeArray(fedges);
	cout << "\n-------------------------------------";

	int i = 0 ;			//COUNTER VARIABLE
	int j = 0 ;			//COUNTER VARIABLE
	int  smallest = 0 ;

	int v1 = 0 ;
	int v2 = 0 ;
	int weight = 0 ;

	int m = 0 ;
	int n = 0 ;
	int cnt = 0 ;

	for(i = 0 ; i < fedges; i++)
	{
		smallest = i ;

		for(j = i+1 ; j < fedges ; j++)
		{
			if(e[smallest].weight > e[j].weight)
			{
				smallest = j ;
			}
		}

		if(i != smallest)
		{
			v1 = e[i].sindex ;
			v2 = e[i].eindex ;
			weight = e[i].weight ;

			e[i].sindex = e[smallest].sindex ;
			e[i].eindex = e[smallest].eindex ;
			e[i].weight = e[smallest].weight ;

			e[smallest].sindex = v1;
			e[smallest].eindex = v2;
			e[smallest].weight = weight;
		}
	}

	//DISPLAYING SORETED EDGE ARRAY
	cout << "\n\n\t---Displaying SORETD Edge Array--- " ;
	displayEdgeArray(fedges);
	cout << "\n-------------------------------------";

	//Finding MST

	//INITIALIZING VISITED ARRAY
	for(i = 0 ; i < SIZE ; i++)
	{
		varray[i].flag = 0;
	}

	weight = 0 ;
	for(i = 0 ; i < fedges ; i++)
	{
		v1 = e[i].sindex ;
		v2 = e[i].eindex ;

		m = varray[v1].flag ;
		n = varray[v2].flag ;
		if(m == 0)
		{
			if(n == 0)
			{
				//no cycle ==> add edge
				cnt = cnt + 1 ;
				varray[v1].flag = cnt ;
				varray[v2].flag = cnt ;
				weight = weight + e[i].weight ;
			}
			else
			{
				// n != 0
				varray[v1].flag = n ;
				weight = weight + e[i].weight ;
			}
		}
		else
		{
			//m != 0
			if( n == 0)
			{
				varray[v2].flag = m ;
				weight = weight + e[i].weight ;
			}
			else
			{
				//n != 0
				if(m == n)
				{
					//NO ADDITION
					//CYCLE FORMATION
				}
				else
				{
					if(m < n)
					{
						weight = weight + e[i].weight ;
						for(j = 0 ; j <fvertices ; j++ )
						{
							if(varray[j].flag == n)
							{
								varray[j].flag = m ;
							}
						}
					}
					else if(m > n)
					{
						weight = weight + e[i].weight ;
						for(j = 0 ; j <fvertices ; j++ )
						{
							if(varray[j].flag == m)
							{
								varray[j].flag = n ;
							}
						}
					}
				}
			}
		}
		cout << "\n" ;
		displayVisitedArray(fvertices);

	}

	cout << "\n\t\tWeight Of Mst =" << weight ;

}
