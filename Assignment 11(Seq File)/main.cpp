/*
 * main.cpp
 *
 *  Created on: 26-Mar-2017
 *      Author: acer
 */

#include </home/acer/eclipse/Sem3Workspace/dsf_sequential_file/Afile.h>
#include<iostream>
#include <fstream>
using namespace std ;

int main(void)
{
	Afile f;
	int numRecord = 0 ;

	int choice = 0 ;
	int subch = 0 ;
	int flag = -3 ;
	int subflag = -3 ;
	int main = -1 ;
	int roll = -1 ;
	char name[20] = {'\0'};
	char div = '\0' ;
	char address[100] = {'\0'};

	f.getRecordCount(numRecord);


	do
	{
		do
		{
			cout << "\n\n\t\t---Menu---" ;
			cout << "\n\t\t1.Add a Record " ;
			cout << "\n\t\t2.Display a Record "  ;
			cout << "\n\t\t3.Display All Record " ;
			cout << "\n\t\t4.Modify a Record " ;
			cout << "\n\t\t5.Delete A Record " ;
			cout << "\n\t\t0.Exit" ;

			cout << "\nEnter your Choice :" ;
			cin >> choice ;
			}while(choice > 5 || choice < 0);


		switch(choice)
		{
			case 1: f.createDatabase(numRecord);
					main = 1 ;
					break ;

			case 2:	if(main == -1 && numRecord == 0)
					{
						cout << "\n\t\tThere Are no Records." ;
						cout << "\n\t\tPlease Go to Option '1' " ;
					}
					else
					{
						do
						{
							cout << "\nEnter Roll no. of the Record to be Displayed:" ;
							cin >> roll ;

							subflag = f.searchRecord(roll) ;
							if(subflag == -1 || subflag == 0)
							{
								//RECORD NOT FOUND
								cout << "\nRECORD NOT FOUND!!!" ;
							}
							else if(subflag == 1)
							{
								//RECORD ALREADY EXISTS
								f.displayARecord(roll) ;
							}
							else if(subflag == -2 || subflag == -1)
							{
								//FUNCTION ERROR
								cout << "\nFUNCTION ERROR!!!" ;
							}
						}while( subflag != 1 );
					}

					break ;

			case 3:	if(main == -1)
					{
						cout << "\n\t\tThere Are No Records." ;
						cout << "\n\t\tPlease Go to Option '1' " ;
					}
					else
					{
						f.getRecordCount(numRecord);
						if(numRecord == 0)
						{
							cout << "\n\n\t\tList Is Completely Empty" ;
						}
						else
						{
							f.displayRecord() ;
						}

					}

					break ;

			case 4:	if(main == -1 && numRecord == 0)
					{
						cout << "\n\t\tThere Are No Records." ;
						cout << "\n\t\tPlease Go to Option '1' " ;
					}
					else
					{
						do
						{
							cout << "\nEnter Roll no. of the Record to be Modified:" ;
							cin >> roll ;

							subflag = f.searchRecord(roll) ;
							if(subflag == -1 || subflag == 0)
							{
								cout << "\nRECORD NOT FOUND!!!" ;
								//RECORD NOT FOUND
							}
							else if(subflag == 1)
							{
								//RECORD ALREADY EXISTS
								cout << "\n\n\t\t---SubMenu---" ;
								cout << "\n\t\t1.Modify Name";
								cout << "\n\t\t2.Modify Division";
								cout << "\n\t\t3.Modify Address";
								cout << "\n\t\t4.Modify Name and Division ";
								cout << "\n\t\t5.Modify Division and Address ";
								cout << "\n\t\t6.Modify Address and Name ";
								cout << "\n\t\t7.Modify All Three ";
								cout << "\n\t\t0.Exit" ;

								cout << "\nEnter your Choice:";
								cin >> subch;

								switch(subch)
								{
								case 1: cout << "\nEnter Name:" ;
										cin >> name ;
										flag = f.modifyNRecord(roll , name ) ;
										if(flag == 1)
										{
											cout << "\n\t\tRecord Modified";
										}
										else
										{
											cout << "\n\t\tRecord Not Modified";
										}
										break;

								case 2: cout << "\nEnter Division:" ;
										cin >> div ;
										flag = f.modifyRecord(roll , div ) ;
										if(flag == 1)
										{
											cout << "\n\t\tRecord Modified";
										}
										else
										{
											cout << "\n\t\tRecord Not Modified";
										}
										break;

								case 3: cout << "\nEnter Address:" ;
										cin >> address ;
										flag  = f.modifyARecord(roll , address ) ;
										if(flag == 1)
										{
											cout << "\n\t\tRecord Modified";
										}
										else
										{
											cout << "\n\t\tRecord Not Modified";
										}
										break;

								case 4: cout << "\nEnter Name:" ;
										cin >> name ;
										cout << "\nEnter Division:" ;
										cin >> div ;
										flag  = f.modifyRecord(roll , name , div ) ;
										if(flag == 1)
										{
											cout << "\n\t\tRecord Modified";
										}
										else
										{
											cout << "\n\t\tRecord Not Modified";
										}
										break;

								case 5: cout << "\nEnter Division:" ;
										cin >> div ;
										cout << "\nEnter Address:" ;
										cin >> address ;
										flag = f.modifyRecord(roll , div , address ) ;
										if(flag == 1)
										{
											cout << "\n\t\tRecord Modified";
										}
										else
										{
											cout << "\n\t\tRecord Not Modified";
										}
										break;

								case 6: cout << "\nEnter Address:" ;
										cin >> address ;
										cout << "\nEnter Name:" ;
										flag = f.modifyRecord(roll , address , name) ;
										if(flag == 1)
										{
											cout << "\n\t\tRecord Modified";
										}
										else
										{
											cout << "\n\t\tRecord Not Modified";
										}
										cin >> name ;
										break;

								case 7: cout << "\nEnter Name:" ;
										cin >> name ;
										cout << "\nEnter Division:" ;
										cin >> div ;
										cout << "\nEnter Address:" ;
										cin >> address ;
										flag = f.modifyRecord(roll , name ,  div , address ) ;
										if(flag == 1)
										{
											cout << "\n\t\tRecord Modified";
										}
										else
										{
											cout << "\n\t\tRecord Not Modified";
										}
										break;

								case 0 :cout << "\n\t\t!!!Exited From The SubMenu!!!";
										break;
								}
							}
							else if(subflag == -2 || subflag == -1)
							{
								cout << "\nFUNCTION ERROR!!!" ;
								//FUNCTION ERROR
							}
						}while(subflag != 1 );
					}

					break ;

			case 5:	if(main == -1 && numRecord == 0)
					{
						cout << "\n\t\tThere Are No Records." ;
						cout << "\n\t\tPlease Go to Option '1' " ;
					}
					else
					{
						cout << "\nEnter Roll no. of the Record to be Modified:" ;
						cin >> roll ;

						subflag = f.searchRecord(roll) ;
						if(subflag == -1 || subflag == 0)
						{
							//RECORD NOT FOUND
							cout << "\nRECORD NOT FOUND!!!" ;
						}
						else if(subflag == 1)
						{
							//RECORD ALREADY EXISTS
							flag = f.deleteRecord(roll) ;
							if(flag == 1)
							{
								cout << "\n\t\tRecord Deleted";
							}
							else
							{
								cout << "\n\t\tRecord Not Deleted";
							}
						}
						else if(subflag == -2 || subflag == -1)
						{
							//FUNCTION ERROR
							cout << "\nFUNCTION ERROR!!!" ;
						}
					}

					break ;

			case 0 :cout << "\n\t\t!!!Exited From The MainMenu!!!";
					break;
		}

	}while(choice <= 5 && choice > 0 && choice != 0);


	return 0 ;
}

