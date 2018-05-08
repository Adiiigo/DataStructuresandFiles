/*
 * main.cpp
 *
 *  Created on: 20-Feb-2017
 *      Author: acer
 */

#include</home/acer/eclipse/Sem3Workspace/Hashing/hashing.h>
#include<iostream>
using namespace std;

int main(void)
{
	hashing a;
	struct datanode s[10] = {0};

	int choice = 0 ;
	int flag  = -1 ;
	int rval = 0 ;
	int i = 0 ;
	int array[SIZE] = {0} ;
	int sdata = 0 ;
	int count = -1 ;
	int sflag = -1 ;

	int check = 0 ;

	char ans = '\0' ;
	int subchoice = 0 ;
	do
	{
		do
		{
			cout<<"\n\n\t\t---Menu---" ;
			cout<<"\n\t\t1.Insert Data" ;
			cout<<"\n\t\t2.Display Array" ;
			cout<<"\n\t\t0. Exit" ;

			cout<<"\nEnter Your Choice:";
			cin>>choice ;
		}while(choice < 0 || choice > 2) ;


		switch(choice)
		{
		flag  = -1 ;
		case 1:	//IF USER WANT TO CONTINUE WITH SAMR ARRAY OR NOT
				if( check != 0 )
				{
					cout<<"\nDo You  Want To Continue With Same Array ? (y/n) : " ;
					cin>>ans;
					if(ans == 'Y' || ans == 'y')
					{
						cout<<"\n\n\t\tYour Array Elements are ";
						for(i = 0 ; i < SIZE ; i++)
						{
							cout<<"\n\t\tElement "<<i+1<<" : "<<array[i];
						}
					}
					else
					{
						cout<<"\nEnter Array Elements:";
						for(i = 0 ; i < SIZE ; i++ )
						{
							cout<<"\nElement "<<i+1<<" : ";
							cin>>array[i];
						}
					}
				}
				else
				{
					cout<<"\nEnter Array Elements:";
					for(i = 0 ; i < SIZE ; i++ )
					{
						cout<<"\nElement "<<i+1<<" : ";
						cin>>array[i];
					}
				}

				do
				{
					cout<<"\n\n\t\t\t---SubMenu---";
					cout<<"\n\n\t\t\t1.Without Replacement Without Chaining";
					cout<<"\n\t\t\t2.Without Replacement With Chaining";
					cout<<"\n\t\t\t3.With Replacement Without Chaining";
					cout<<"\n\t\t\t4.With Replacement With Chaining";
					cout<<"\n\t\t\t5.Using Linked List";

					cout<<"\nEnter Your Choice : ";
					cin>>subchoice;

				}while(subchoice < 0 || subchoice > 5);

				switch(subchoice)
				{
				case 1:	a.clean();
						check = 1 ;
						rval = a.insertDataWorWoc(array);
						if(rval == (SIZE-1) )
						{
							cout<<"\n\n\t\tSuccessFul Insertion Of Data";
							flag = 1;
						}
						else
						{
							cout<<"\n\n\t\tError Occurred In the Insertion Of Data";
						}
						break;

				case 2:	a.clean();
						check = 1 ;
						rval = a.insertDataWorWc(array);
						if(rval == (SIZE-1) )
						{
							cout<<"\n\n\t\tSuccessFul Insertion Of Data";
							flag = 2;
						}
						else
						{
							cout<<"\n\n\t\tError Occurred In the Insertion Of Data";
						}
						break;

				case 3:	a.clean();
						check = 1 ;
						rval = a.insertDataWrWoc(array);
						if(rval == (SIZE-1) )
						{
							cout<<"\n\n\t\tSuccessFul Insertion Of Data";
							flag = 3;
						}
						else
						{
							cout<<"\n\n\t\tError Occurred In the Insertion Of Data";
						}
						break;

				case 4:	a.clean();
						check = 1 ;
						rval = a.insertDataWrWc(array);
						if(rval == (SIZE-1) )
						{
							cout<<"\n\n\t\tSuccessFul Insertion Of Data";
							flag = 4;
						}
						else
						{
							cout<<"\n\n\t\tError Occurred In the Insertion Of Data";
						}
						break;

				case 5:	a.clean();
						check = 1 ;
						rval = a.insertDatall(s,array);
						if(rval == (SIZE-1) )
						{
							cout<<"\n\n\t\tSuccessFul Insertion Of Data";
							flag = 4;
						}
						else
						{
							cout<<"\n\n\t\tError Occurred In the Insertion Of Data";
						}
						break;

				}
				break;

		case 2:	if(flag == 1)
				{
					sflag = a.searchDataWorWoc(array);
					if( sflag != -1)
					{
						cout<<"\n\n\t\tExecution Successful!!!";
					}
					else
					{
						cout<<"\n\n\t\tExecution Unsuccessful!!!";
					}
				}
				else if(flag == 2)
				{
					sflag = a.searchDataWorWc(array);
					if( sflag != -1)
					{
						cout<<"\n\n\t\tExecution Successful!!!";
					}
					else
					{
						cout<<"\n\n\t\tExecution Unsuccessful!!!";
					}
				}
				else if(flag == 3)
				{
					sflag = a.searchDataWrWoc(array);
					if( sflag != -1)
					{
						cout<<"\n\n\t\tExecution Successful!!!";
					}
					else
					{
						cout<<"\n\n\t\tExecution Successful!!!";
					}
				}
				else if(flag == 4)
				{

					sflag = a.searchDataWrWc(array);
					if( sflag != -1)
					{
						cout<<"\n\n\t\tElement Found !!!";
						cout<<"\n\t\tNo. of Comparisons : "<<count;
					}
					else
					{
						cout<<"\n\n\t\tElement Not Found !!!";
					}
				}
				else if(flag == 5)
				{
					cout<<"\nEnter Data To Be Searched:";
					cin>>sdata;

					a.searchDatall(s,array);
				}
				else
				{
					cout<<"\n\n\t\tPlease Enter Data First!!!";
					cout<<"\n\t\t	Go to Option '1'";
				}
				break;

		case 0:	cout<<"\n\n\t\tExited From The Menu";
				break;
		}

	}while(choice > 0 && choice <= 2 && choice !=0);
	return 0 ;
}
