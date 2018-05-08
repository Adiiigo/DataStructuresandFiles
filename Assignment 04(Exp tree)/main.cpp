/*
 * main.cpp
 *
 *  Created on: 25-Jan-2017
 *      Author: acer
 */

#include </home/acer/workspace/Expression_Tree/estack.h>
#include </home/acer/workspace/Expression_Tree/ExpTree.h>
//#include </home/acer/workspace/Expression_Tree/estack.cpp>
//#include </home/acer/workspace/Expression_Tree/ExpTree.cpp>
#include <iostream>
using namespace std;

int string_check(char fstring[10]);

int main(void)
{
	ExpTree e;

	struct ExpTreeNode *node = NULL;
	int choice = 0 ;
	char poststring[20] = {'\0'};
	int flag = 0 ;
	int sflag = -1 ;

 	do
	{
		do
		{
			cout << "\n\n\t\t----MENU----";
			cout << "\n\t\t1.Insert Postfix String";
			cout << "\n\t\t2.Construct Tree";
			cout << "\n\t\t3.Preorder Traversal";
			cout << "\n\t\t4.Postorder Traversal";
			cout << "\n\t\t5.Inorder Traversal";
			cout << "\n\t\t0.Exit";

			cout << "\n\nEnter Your Choice: ";
			cin >> choice;
		}while( choice < 0 || choice >5 );

		switch(choice)
		{

		case 1:	do
				{
					cout << "\n\nEnter Postfix String:" ;
					cin >> poststring ;

					sflag = string_check(poststring) ;

					if(sflag == 0)
					{
						cout << "\n\n\t\tYou Can Contine!!!" ;
						cout << "\n\t\tString Is Valid" ;
					}
					else
					{
						cout << "\n\n\t\tString Is Invalid" ;
					}
				}while(sflag == 1);
				break;

		case 2:	flag = e.constructTree(poststring);
				if(flag == 0)
				{
					cout << "\n\n\t\tUnsuucessful !!" ;
				}
				else
				{
					cout << "\n\n\t\tSuucessful!!" ;
				}
				break;

		case 3:	e.getroot(&node);
				if(node != NULL)
				{
					e.preorder(node);
				}
				else
				{
					cout<<"\n\n\t\tPlease Construct Tree First!";
					cout<<"\n\t\tGo to option '2'";
				}

				break;

		case 4:	e.getroot(&node);
				if(node != NULL)
				{
					e.postorder(node);
				}
				else
				{
					cout<<"\n\n\t\tPlease Construct Tree First!";
					cout<<"\n\t\tGo to option '2'";
				}

				break;

		case 5:	e.getroot(&node);
				if(node != NULL)
				{
					e.inorder(node);
				}
				else
				{
					cout<<"\n\n\t\tPlease Construct Tree First!";
					cout<<"\n\t\tGo to option '2'";
				}

				break;

		case 0:	cout << "\n\n\t\tExited From The Menu" ;
				break;
		}
	}while(choice > 0 && choice <= 5 && choice != 0);

	return 0;
}

int string_check(char fstring[20])
{
	int rval=0;
	int i=0;
	char sym = '\0';				//STORES THE CURRENT SYMBOL OF ANY STRING
	int opnd=0;
	int op=0;

	while(fstring[i] != '\0')
	{
		sym = fstring[i] ;
		if((sym >= 'a'&& sym <= 'z') || (sym >= 'A' && sym <= 'Z'))
		{
			opnd++ ;
		}
		else if( sym == '$' || sym == '^' || sym == '*' || sym == '/' || sym == '%' || sym == '+' || sym == '-')
		{
			op++ ;
		}
		i++;
	}

	if(opnd == (op+1))
	{
		rval = 0 ;
	}
	else
	{
		rval = 1 ;
	}
	return rval;
}
