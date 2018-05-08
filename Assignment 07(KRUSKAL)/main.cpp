/*
 * main.cpp
 *
 *  Created on: 18-Mar-2017
 *      Author: acer
 */

#include<iostream>
using namespace std;
#include</home/acer/workspace/KruskalCode/Kgraph.h>

int main(void)
{
	Kgraph k;

	int choice = 0 ;
	int vertices = 0 ;  //VARIABLE TO STORE TO STORE NO. OF VERTICES
	int link = 0 ;
	int main = 0 ;
	int subchoice = 0 ;
	int subflag = 0 ;

	do
	{
		do
		{
			cout << "\n\n\t\t----Main Menu----" ;
			cout << "\n\t\t1.Accept Data" ;
			cout << "\n\t\t2.Diplay Data" ;
			cout << "\n\t\t3.Find Minimum spanning Tree" ;
			cout << "\n\t\t0.Exit" ;

			cout << "\nEnter Your Choice:" ;
			cin >> choice ;

		}while(choice > 3 || choice < 0 );

		switch(choice)
		{
		case 1:	cout << "\nEnter Total No.of Vertices :" ;
				cin >> vertices ;

				do
				{
					cout << "\n\n\t\t---SUBMENU---" ;
					cout << "\n\t\t1.Using Adjacency Matrix" ;
					cout << "\n\t\t2.Using Adjacency List " ;
					cout << "\n\t\t0.Exit SubMenu";

					cout << "\n\t\tEnter Your Choice :" ;
					cin >> subchoice ;

				}while(subchoice > 3 || subchoice < 0);

				switch(subchoice)
				{
				case 1:	cout << "\n\t---Using Adjacentcy Matrix--- " ;
						k.createAdjMatrix(vertices,link);
						subflag = 1;
						break ;

				case 2: cout << "\n\t---Using Adjacentcy List--- " ;
						k.createAdjList(vertices,link);
						subflag = 2 ;
						break;

				case 0:	cout << "\n\n\t\tExited From The SubMenu" ;
						break;
				}
				main = 1;
				cout <<"\n\t\tno . of links="<<link ;
				break;

		case 2:	if(subflag == 0 && main == 0)
				{
					cout << "\n\n\t\tPlease Enter Data First ";
					cout << "\n\t\tGo to Option '1'" ;
				}
				else if(subflag == 1 && main == 1)
				{
					cout << "\n\t---Displaying Using Adjacentcy Matrix--- " ;
					k.displayAdjMatrix(vertices);
				}
				else if(subflag == 2 && main == 1)
				{
					cout << "\n\t---Displaying Using Adjacentcy List--- " ;
					k.displayAdjList(vertices);
				}
				//cout << "\n\t---Displaying Visited Array--- " ;
				//k.displayVisitedArray(vertices);

				break;

		case 3:	if(main == 0)
				{
					cout << "\n\n\t\tPlease Enter Data First ";
					cout << "\n\t\tGo to Option '1'" ;
				}
				else
				{
					k.minimumSpanningTree( vertices,link) ;
				}
				break;

		case 0:	cout << "\n\n\t\tExited From The  Main Menu" ;
				break;
		}
	}while(choice <= 3 && choice > 0 && choice !=0 );

	return 0;
}
