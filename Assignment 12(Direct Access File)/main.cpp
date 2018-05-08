/*
 * main.cpp
 *
 *  Created on: 20-Apr-2017
 *      Author: acer
 */

#include</home/acer/eclipse/Sem3Workspace/Dsf_Direct_Access_File/Dfile.h>
#include<iostream>
#include<fstream>

using namespace std;
int main()
{

	details s ;

	int ch=0;
	int rno=0;
	//char ch;
	Dfile file;
	do
	{
		cout<<"\n\n\t ***MENU***";
		cout<<"\n 1.Add record";
		cout<<"\n 2.Modify";
		cout<<"\n 3.Search";
		cout<<"\n 4.Display Records";
		cout<<"\n 0.exit";
		cout<<"\n\t Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1 :
					do
					{
						cout << "\nEnter Roll no. " ;
						cin >> s.roll;
					}while(s.roll == 0 );


				cout << "\nEnter Name :" ;
				cin >> s.name ;

				file.addrecord1(s);
				break;

			case 2 :
				file.modify();
				break;

			case 3 :
				cout<<"Enter a roll no of a record to be searched : ";
				cin>>rno;
				file.search(rno);
				break;

			case 4 :
				file.display();
				break;

			case 0 :
					cout<<"\n Thank You!";
				break;

			default : cout<<"\n Wrong choice";
		}
	}while(ch!=0);
	return 0;
}
