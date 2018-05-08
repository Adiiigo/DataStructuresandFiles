/*
 * main.cpp
 *
 *  Created on: 16-Jan-2017
 *      Author: acer
 */

#include<iostream>
#include </home/acer/eclipse/Sem3Workspace/priority_queue/pqueue.h>
//#include </home/acer/workspace/priority_queue/pqueue.cpp>
using namespace std ;

int main()
{
	int choice = 0 ;				//STORES MENU OPTION CHOOSEN BY THE USER//

	pqueue high ;					//'high' PRIORITY OBJECT
	int hcount = -1 ;				//COUNTER VARIABLE OF 'high' QUEUE

	pqueue medium ;					//'medium' PRIORITY OBJECT
	int mcount = -1 ;				//COUNTER VARIABLE OF 'medium' QUEUE

	pqueue low ;					//'low' PRIORITY OBJECT
	int lcount = -1 ;				//COUNTER VARIABLE OF 'low' QUEUE

	char idata[20] = {'\0'} ;		//VALUE INSERTED INTO THE QUEUE
	char ddata[20] = {'\0'} ;		//VALUE DELETED FROM THE QUEUE
	int priority = 0 ;				//PRIORITY ENTERED BY THE USER
	int flag = -1 ;					//SUCCESS FLAG

	do
	{
		do
		{
			cout << "\n\n\t\t----Menu----" ;
			cout << "\n\t\t1.Insert Patients" ;
			cout << "\n\t\t2.Extract Patients" ;
			cout << "\n\t\t0.Exit";

			cout << "\n\nEnter Your Choice: " ;
			cin >> choice;
		}while(choice < 0 || choice > 2);

		switch(choice)
		{
			case 1:	cout << "\nEnter Patient Name:" ;
					cin >> idata;

					cout << "\nEnter Priority of Patient(1=High,2=Medium,3=Low):" ;
					cin >> priority;

					switch(priority)
					{
					case 1: flag = high.insertpq(hcount,idata) ;
							switch(flag)
							{
								case -1: cout << "\n\n\t\tDidnt Enter Function" ;
									   	 break ;

								case 2:	cout << "\n\t\tSuccessful Addition of Patient In High Priority" ;
									   	break ;
							}

							break ;

					case 2:	flag = medium.insertpq(mcount,idata) ;
							switch(flag)
							{
								case -1: cout << "\n\n\t\tDidnt Enter Function" ;
										break;

								case 2:	cout << "\n\t\tSuccessful Addition of Patient In Medium Priority" ;
										break ;
							}

							break ;

					case 3:	flag = low.insertpq(lcount,idata) ;
							switch(flag)
							{
								case -1: cout << "\n\n\t\tDidnt Enter Function" ;
										break;

								case 2:	cout << "\n\t\tSuccessful Addition of Patient  In Low Priority" ;
										break ;
							}

							break ;
					}
					break ;

			case 2:	flag = -1 ;
					if(hcount != -1)
					{
						flag = high.deletepq(hcount,ddata) ;
						switch(flag)
						{
							case -1: cout << "\n\n\t\tDidnt Enter Function" ;
									 break;

							case 2: cout << "\n\n\t\tExtraction Successful From High Priority" ;
									cout << "\n\t\tPatient Name:" << ddata ;
									break ;

						}
					}
					else
					{
						flag = -1 ;
						if(mcount != -1 )
						{
							flag = medium.deletepq(mcount,ddata) ;
							switch(flag)
							{
								case -1: cout << "\n\n\t\tDidnt Enter Function From Medium Priority" ;
										 break;

								case 2: cout << "\n\n\t\tExtraction Successful" ;
										cout << "\n\t\tPatient Name:" << ddata ;
										break;
							}
						}
						else
						{
							flag = -1 ;
							if(lcount != -1)
							{
								flag = low.deletepq(lcount,ddata) ;
								switch(flag)
								{
									case -1: cout << "\n\n\t\tDidnt Enter Function" ;
											 break ;

									case 2: cout << "\n\n\t\tExtraction Successful From Low Priority" ;
											cout << "\n\t\tPatient Name:" << ddata ;
											break ;
								}
							}
							else
							{
								cout << "\n\n\t\tQueue Is Completely Empty" ;
								cout << "\n\t\tInsert Element First In The Queue" ;
							}
						}
					}

					break ;

			case 0: cout << "\n\n\t\tExited From The Menu" ;
					break ;
		}
	}while(choice > 0 && choice <= 2 && choice != 0);

	return 0 ;
}
