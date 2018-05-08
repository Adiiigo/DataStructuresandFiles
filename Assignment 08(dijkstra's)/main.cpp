/*
 * main.cpp
 *
 *  Created on: 24-Mar-2017
 *      Author: acer
 */

#include "Dgraph.h"
//#include </home/acer/eclipse/Sem3Workspace/FDijkstraCode/Dgraph.h>
#include<iostream>
using namespace std ;

int main(void)
{
	Dgraph d;
	int choice = 0 ;
	int subchoice = 0 ;
	int subflag = 0 ;
	int main = 0 ;
	int start = 0 ;
	int vertices = 0 ;
	do
	{
		do
		{
			cout << "\n\n\t\t----Main Menu" ;
			cout << "\n\t\t1.Accept Data" ;
			cout << "\n\t\t2.Display Data" ;
			cout << "\n\t\t3.Minimum Weighted Path" ;
			cout << "\n\t\t0.Exit" ;

			cout << "\nEnter your Choice :" ;
			cin >> choice ;
		}while(choice > 3 || choice < 0);

		switch(choice)
		{
		case 1: cout << "\nEnter Number of Vertices:";
				cin >> vertices ;

				do
				{
					cout << "\n\n\t\t---Sub Menu---";
					cout << "\n\t\t1.Using Adjacency Matrix" ;
					cout << "\n\t\t0.Exit" ;

					cout << "\nEnter your Choice :" ;
					cin >> subchoice ;

				}while(subchoice > 2  || subchoice < 0);

				switch(subchoice)
				{
				case 1 :cout << "\n\n\t\t----Using Adjacency Matrix----" ;
						d.createAdjMat(vertices) ;
						subflag = 1 ;
						break ;

				case 0 :cout << "\n\n\t\tExited From The SubMenu" ;
						break ;
				}

				main = 1 ;
				break;

		case 2 :if(main == 0 && subflag == 0)
				{
					cout << "\n\n\t\tPlease Enter Data First" ;
					cout << "\n\t\tGo to Option '1'!!";
				}
				else if(main == 1 && subflag == 1)
				{
					cout << "\n\n\t\t----Displaying Adjacency Matrix----" ;
					d.displayAdjMat(vertices) ;
				}

				break ;

		case 3 :if(main == 0)
				{
					cout << "\n\n\t\tPlease Enter Data First" ;
					cout << "\n\t\tGo to Option '1'!!";
				}
				else
				{
					cout << "\nEnter Start Vertex(Integer Data) :" ;
					cin >> start ;

					start-- ;
					if(subflag == 1)
					{
						d.shortestPathMat(vertices , start);
					}
				}
				break ;

		case 0 :cout << "\n\n\t\tExited From The Main Menu" ;
				break ;

		}
	}while(choice <= 3 && choice > 0 && choice != 0);
	return 0 ;
}
