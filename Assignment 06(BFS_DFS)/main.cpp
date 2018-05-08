/*
 * main.cpp
 *
 *  Created on: 16-Mar-2017
 *      Author: acer
 */

#include<iostream>
using namespace std;
#include</home/acer/eclipse/Sem3Workspace/Facebook_assig/Agraph.h>
#include </home/acer/eclipse/Sem3Workspace/Facebook_assig/gqueue.h>
#include </home/acer/eclipse/Sem3Workspace/Facebook_assig/stack.h>

int main(void)
{
	Agraph g;

	int main = 0 ;
	int choice = 0 ;
	int subchoice = 0 ;
	int subflag = 0 ;
	int vertices = 0 ;  //VARIABLE TO STORE TO STORE NO. OF VERTICES
	int month = 0 ;
	int flag = -1 ;
	do
	{
		do
		{
			cout << "\n\n\t\t---MENU---" ;
			cout << "\n\t\t1.Accept Data" ;
			cout << "\n\t\t2.Display Graph" ;
			cout << "\n\t\t3.Find Max Comments" ;
			cout << "\n\t\t4.Find Person with Max Friends" ;
			cout << "\n\t\t5.Find People With Specfic BirthMonths" ;
			cout << "\n\t\t0.Exit" ;

			cout << "\n\nEnter Your Choice:" ;
			cin >> choice;

		}while(choice < 0 || choice > 5);

		switch(choice)
		{

		case 1:	do
				{
					cout << "\n\nEnter Total No.of Vertices :" ;
					cin >> vertices ;

					if(vertices > 2)
					{
						cout << "\n\n\t\tNo. Of Vertices Entered Are Valid " ;
						cout << "\n\t\tYou can Continue " ;
						flag = 1 ;
					}
					else
					{
						cout << "\n\n\t\tNo. Of Vertices Entered Are Not Valid " ;
						cout << "\n\t\tPlease Enter Again." ;
						flag = 0 ;
					}

				}while(flag == 0 );

				do
				{
					cout << "\n\n\t\t---SUBMENU---" ;
					cout << "\n\t\t1.Using Adjacency List " ;
					//cout << "\n\t\t2.Using Adjacency Matrix" ;
					cout << "\n\t\t0.Exit SubMenu";

					cout << "\n\t\tEnter Your Choice :" ;
					cin >> subchoice ;

				}while(subchoice > 2 || subchoice < 0);

				switch(subchoice)
				{

				case 1: cout << "\n\t---Using Adjacentcy List--- " ;
						g.createAdjList(vertices);
						subflag = 1 ;
						break;

				/*case 2:	cout << "\n\t---Using Adjacentcy Matrix--- " ;
						g.createAdjMatrix(vertices);
						subflag = 2;
						break ;*/

				case 0:	cout << "\n\n\t\tExited From The SubMenu" ;
						break;
				}
				main = 1;
				break;

		case 2: if(subflag == 0 && main == 0)
				{
					cout << "\n\n\t\tPlease Enter Data First ";
					cout << "\n\t\tGo to Option '1'" ;
				}
				else if(subflag == 1 && main == 1)
				{
					cout << "\n\t---Displaying Using Adjacentcy List--- " ;
					g.displayAdjList(vertices);
				}
				/*else if(subflag == 2 && main == 1)
				{
					cout << "\n\t---Displaying Using Adjacentcy Matrix--- " ;
					g.displayAdjMatrix(vertices);
				}*/

				//cout << "\n\t---Displaying Visted Array--- " ;
				//g.displayVisitedArray(vertices);

				break;

		case 3:	if(main == 1)
				{
					do
					{
						cout << "\n\n\t\t---SUBMENU---" ;
						cout << "\n\t\t1.Using Depth First Search " ;
						//cout << "\n\t\t2.Using Breadth First Search " ;
						cout << "\n\t\t0.Exit SubMenu";

						cout << "\n\t\tEnter Your Choice :" ;
						cin >> subchoice ;

					}while(subchoice > 2 || subchoice < 0);

					switch(subchoice)
					{
					case 1:	cout << "\n\t---Using depthFirstSearch--- " ;
							g.depthFirstSearch(vertices);
							break ;

					/*case 2: cout << "\n\t---Using breadthFirstsearch--- " ;
							g.breadthFirstsearch(vertices);
							break;
					*/

					case 0:	cout << "\n\n\t\tExited From The SubMenu" ;
							break;

					}
				}
				else
				{
					cout << "\n\n\t\tPlease Enter Data First ";
					cout << "\n\t\tGo to Option '1'" ;
				}
				break;

		case 4:	if(main == 0)
				{
					cout << "\n\n\t\tPlease Enter Data First ";
					cout << "\n\t\tGo to Option '1'" ;
				}
				else
				{
					cout << "\n\t---Displaying Person With Max Friends--- " ;
					g.maxFriends(vertices);
				}
				break;

		case 5:	if(main == 0)
				{
					cout << "\n\n\t\tPlease Enter Data First ";
					cout << "\n\t\tGo to Option '1'" ;
				}
				else
				{
					cout << "\nEnter Month No." ;
					cin >> month ;
					g.getUserCount(month,vertices);
				}
				break;

		case 0:	cout << "\n\n\t\tExited From The  Main Menu" ;
				break;
		}
	}while(choice > 0 && choice <= 5 && choice != 0 );
	return 0;
}
