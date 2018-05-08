/*
 * main.cpp
 *
 *  Created on: 14-Jan-2017
 *      Author: acer
 */

//FOR STREAM RELATED OPERATIONS
#include<iostream>

//INCLUDING .h FILE
#include</home/acer/eclipse/Sem3Workspace/conversions/eval.h>
#include</home/acer/eclipse/Sem3Workspace/conversions/operand.h>
#include</home/acer/eclipse/Sem3Workspace/conversions/operatorstack.h>

//FOR STRING RELATED FUNCTIONS
#include<string.h>

//FOR ARITHMETIC RELATED FUNCTIONS
#include<math.h>
using namespace std;

//STRUCT
struct number
{
	char variable ;
	int value ;
};

//FUNCTIONS PERFORMED USING 3 DIFFERENT CLASSES
int linearSearch(char f , struct number fn[10] , int structlen) ;
int string_check(char fstring[10]);
int intopost(char fistring[10],char fpstring[10]) ;
int operator_priority(int fsym) ;
int intopre(char fistring[10],char fpstring[10]) ;
int posttoin(char fpstring[10],char fistring[10]) ;
int pretoin(char fpstring[10],char fistring[10]) ;
int posteval(char fpstring[10],struct number fn[10],int &ffinalvalue , int structlen) ;
int pre_eval(char fpstring[10],struct number fn[10],int &ffinalvalue, int structlen) ;
int intopostbracket(char fistring[10],char fpstring[10]) ;

int main()
{

	int choice = 0;					//STORES MENU OPTION CHOOSEN BY THE USER

	char temp[10] = {'\0'} ;		//STORES STRING WITH NO DATA
	char istring[10] = {'\0'} ;		//STORES INFIX STRING
	char poststring[10] = {'\0'} ;	//STORES POSTFIX STRING
	char prestring[10] = {'\0'} ;	//STORES PREFIX STRING

	struct number n[SIZE] = {0};		//ARRAY OF STRUCTURE 'number'

	char sym = '\0';				//STORES THE CURRENT SYMBOL OF ANY STRING
	int i = 0; 						//COUNTER VARIABLE
	int k = 0; 						//COUNTER VARIABLE
	int count = 0;					//COUNTER VARIABLE
	int finalvalue = -1;			//STORES THE TOPPEST VALUE OF 'eval' STACK
	char rstring[10] = {'\0'};		//VARIABLE TO STORE REVERSE OF PREFIX STRING
	int m = 0;						//COUNTER VARIABLE
	int len = 0;					//COUNTER VARIABLE
	int l = 0;						//COUNTER VARIABLE
	int flag = -1 ;					//SUCCESS FLAG
	int sflag = -1 ;

	do
	{
		do
		{
			cout << "\n\n\t\t----Menu----" ;
			cout << "\n\t\t1.Insert Infix String" ;
			cout << "\n\t\t2.Display Infix to Postfix String" ;
			cout << "\n\t\t3.Display Infix to Prefix String" ;
			cout << "\n\n\t\t4.Insert Prefix String" ;
			cout << "\n\t\t5.Display Prefix to Infix" ;
			cout << "\n\n\t\t6.Insert Postfix String" ;
			cout << "\n\t\t7.Display Postfix to Infix String" ;
			cout << "\n\n\t\t8.Evaluation of Prefix String" ;
			cout << "\n\t\t9.Evaluation of Postfix String" ;
			cout << "\n\n\t\t0.Exit";

			cout <<" \n\nEnter Your Choice:" ;
			cin >> choice ;
		}while(choice < 0 || choice > 9 ) ;

		switch( choice )
		{

		case 1:	do
				{
					cout << "\n\nEnter Infix String:" ;
					cin >> istring ;

					sflag = string_check(istring) ;

					if(sflag == 0)
					{
						cout << "\n\n\t\tYou Can Contine!!!" ;
						cout << "\n\t\tString Is Valid" ;
					}
					else
					{
						cout << "String Is Invalid" ;
					}
				}while(sflag == 1);

				break ;

		case 2: if( istring[0] != '\0' )
				{
					flag=intopostbracket( istring,poststring ) ;
					if(flag == 0)
					{
						cout << "\n\n\t\tPostfix String=" << poststring ;
					}
					else
					{
						cout << "\n\n\t\tError Occured!!!" ;
					}
				}
				else
				{
					cout << "\n\n\t\tSorry Cannot Continue" ;
					cout << "\n\t\tNo Infix String Is Present" ;
					cout << "\n\t\tGo To '1' Option" ;
				}

				break ;

		case 3: if( istring[0] != '\0' )
				{
					flag = intopre(istring,prestring);
					if(flag == 0)
					{
						cout << "\n\n\t\tPrefix String=" << prestring ;
					}
					else
					{
						cout <<"\n\n\t\tError Occured!!!" ;
					}
				}
				else
				{
					cout << "\n\n\t\tSorry Cannot Continue" ;
					cout<<"\n\t\tNo Infix String Is Present" ;
					cout << "\n\t\tGo To '1' Option" ;
				}

;				break ;

		case 4: strcpy(prestring,temp);
				sflag = -1;
				do
				{
					cout << "\n\nEnter Prefix String:" ;
					cin >> prestring ;

					sflag = string_check(prestring) ;

					if(sflag == 0)
					{
						cout << "\n\n\t\tYou Can Contine!!!" ;
						cout << "\n\t\tString Is Valid" ;
					}
					else
					{
						cout << "String Is Invalid" ;
					}
				}while(sflag == 1);

				break ;

		case 5: if(prestring[0] != '\0')
				{
					flag = pretoin(prestring,istring) ;
					if(flag == 0)
					{
						cout << "\n\n\t\tInfix String=" << istring ;
					}
					else
					{
						cout << "\n\n\t\tError Occured!!!" ;
					}
				}
				else
				{
					cout << "\n\n\t\tSorry Cannot Continue" ;
					cout << "\n\t\tNo Prefix String Is Present" ;
					cout << "\n\t\tGo To '4' Option" ;
				}

				break ;

		case 6:	strcpy(poststring,temp);
				sflag = -1;
				do
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
						cout << "String Is Invalid" ;
					}
				}while(sflag == 1);

				break ;

		case 7: if( poststring[0] != '\0' )
				{
					flag = posttoin( poststring,istring ) ;
					if(flag == 0)
					{
						cout << "\n\n\t\tInfix String=" << istring;
					}
					else
					{
						cout << "\n\n\t\tError Occured!!!" ;
					}
				}
				else
				{
					cout << "\n\n\t\tSorry Cannot Continue" ;
					cout << "\n\t\tNo Postfix String Is Present" ;
					cout << "\n\t\tGo To '6' Option";
				}

				break ;

		case 8: i = 0 ;
				k = 0 ;
				count = 0 ;
				finalvalue = 0 ;
				strcpy(prestring,temp);
				flag = -1 ;
				sflag = -1;
				do
				{
					cout << "\n\nEnter Prefix String:" ;
					cin >> prestring ;

					sflag = string_check(prestring) ;

					if(sflag == 0)
					{
						cout << "\n\n\t\tYou Can Contine!!!" ;
						cout << "\n\t\tString Is Valid" ;
					}
					else
					{
						cout << "String Is Invalid" ;
					}
				}while(sflag == 1);

				len = strlen(prestring) ;
				for(m = len-1 ; m >= 0  ; m--)
				{
					rstring[l] = prestring[m] ;
					l++ ;
				}

				strcpy (prestring,rstring ) ;

				while(prestring[i] != '\0')
				{
					sym = prestring[i] ;
					if((sym >= 'a' && sym <= 'z') || (sym >= 'A' && sym <= 'Z'))
					{
						flag = linearSearch(sym , n , k) ;
						if(flag == -1)
						{
							cout << "\nEnter Value of " << sym << " :" ;

							n[k].variable = sym ;
							cin >> n[k].value ;
							count++ ;
							k++ ;
						}
						else
						{
							cout << "\n\t\tValue of variable " << sym << " is already entered";
						}
					}
					i++  ;
				}

				//cout << "\nNo. of Varibale in Prefix String :" << count;

				if( prestring[0] != '\0' )
				{
					try
					{
						flag = pre_eval(prestring,n,finalvalue , count ) ;
					}
					catch(const char *msg)
					{
						cout << "\n\n\t\t" << msg ;
						flag=1;
					}
					if(flag == 0)
					{
						cout << "\n\n\t\tAfter Evaluation." ;
						cout << "\n\t\tValue=" << finalvalue ;
					}
					else
					{
						cout << "\n\t\tError Occured!!!" ;
					}
				}
				else
				{
					cout << "\n\n\t\tSorry Cannot Continue" ;
					cout << "\n\t\tNo Prefix String Is Present" ;
					cout << "\n\t\tGo To '4' Option" ;
				}

				break ;

		case 9: i = 0 ;
				k = 0 ;
				count = 0 ;
				finalvalue = 0 ;
				strcpy(poststring,temp);
				flag = -1 ;
				sflag = -1;
				do
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
						cout << "String Is Invalid" ;
					}
				}while(sflag == 1);

				while( poststring[i] != '\0' )
				{
					sym = poststring[i] ;
					if((sym >= 'a'&& sym <= 'z') || (sym >= 'A' && sym <= 'Z'))
					{
						flag = linearSearch(sym , n , k) ;
						if(flag == -1)
						{
							cout << "\nEnter Value of " << sym << " :" ;

							n[k].variable = sym ;
							cin >> n[k].value ;
							count++ ;
							k++ ;
						}
						else
						{
							cout << "\n\t\tValue of variable " << sym << " is already entered";
						}
					}
					i++ ;
				}

				//cout << "\nNo. of Varibale in Postfix String :" << count ;

				if( poststring[0] != '\0' )
				{
					try
					{
						flag = posteval( poststring,n,finalvalue, count  ) ;
					}
					catch(const char *msg)
					{
						cout << "\n\n\t\t" <<  msg ;
						flag=1;
					}
					if(flag == 0)
					{
						cout << "\n\n\t\tAfter Evaluation." ;
						cout << "\n\t\tValue=" << finalvalue ;
					}
					else
					{
						cout << "\n\t\tError Occured!!!" ;
					}
				}
				else
				{
					cout << "\n\n\t\tSorry Cannot Continue" ;
					cout << "\n\t\tNo Postfix String Is Present" ;
					cout << "\n\t\tGo To '6' Option" ;
				}

				break ;

		case 0: cout << "\n\n\t\tExited From The Menu" ;
				 break ;

		}
	}while(choice > 0 && choice <= 9 && choice != 0 ) ;
	return 0 ;
}

int linearSearch(char f , struct number fn[10], int structlen)
{

	int i = 0 ;
	int flag =  -1 ;

	while(i < structlen )
	{
		if(fn[i].variable == f)
		{
			flag = i ;
			i = structlen  ;
		}
		else
		{
			flag = -1 ;
		}
		i++ ;
	}

	return flag ;
}

int string_check(char fstring[10])
{
	int rval=0;
	int i=0;
	char sym = '\0';				//STORES THE CURRENT SYMBOL OF ANY STRING
	int sum = 0 ;
	int len = 0 ;

	len = strlen(fstring);
	if(len >=3 )
	{
		while(fstring[i] != '\0')
		{
			sym = fstring[i] ;
			if((sym >= 'a'&& sym <= 'z') || (sym >= 'A' && sym <= 'Z'))
			{
				sum = sum + 1 ;
			}
			else if( sym == '$' || sym == '^' || sym == '*' || sym == '/' || sym == '%' || sym == '+' || sym == '-')
			{
				sum = sum -1 ;
			}
			else if(sym == ')' || sym == '(')
			{
				sum = sum + 0 ;
			}
			i++;
		}

		if(sum == 1)
		{
			rval = 0 ;
		}
		else
		{
			rval = 1 ;
		}

	}
	else
	{
		rval = 1 ;
	}

	return rval;
}

int operator_priority(int fsym)
{
	int flag =-1 ;						//VARIABLE TO STORE PRIORITY VALUE

	switch(fsym)
	{
		case '(': flag = 0 ;
				  break ;

		case '$': flag = 3 ;
				  break ;

		case '^': flag = 3;
				  break ;

		case '*': flag = 2 ;
				  break;

		case '/': flag = 2 ;
				  break ;

		case '%': flag = 2 ;
				  break;

		case '+': flag = 1 ;
				  break  ;

		case '-': flag = 1 ;
				  break ;
	}
	return flag ;
}

int intopost(char fistring[10],char fpstring[10])
{
	operator_stack s;		//OBJECT TO STORE OPERATORES

	int i = 0 ; 			//COUNTER VARIABLE
	int k = 0 ;				//COUNTER VARIABLE
	int size = -1 ;			//GIVES NO. OF NODES
	char sym = '\0';		//STORES THE CURRENT SYMBOL OF INFIX STRING
	int flag = -2 ;			//EXCEPTION HANDLER
	int inop = 0 ;			//OPERATOR PRIORITY OF THE CURRENT SYMBOL
	int stop = 0 ;			//OPERATOR PRIORITY OF THE TOPPEST ELEMENT OF THE STACK
	char data = '\0' ;		//STORES THE CHAR IN THE TOPPEST NODE OF THE STACK
	char ddata = '\0';		//STORE THE EXTRACTED CHAR FROM THE STACK

	while(fistring[i] != '\0')
	{

		sym = fistring[i] ;
		if((sym >= 'a'&& sym <= 'z') || (sym >= 'A' && sym <= 'Z'))
		{
			fpstring[k] = fpstring[k] + sym ;
			k++ ;
		}
		else
		{
			if(s.stackempty(size) == 0)
			{
				flag = s.push( size,sym ) ;
				if(flag == 1)
				{
					cout << "\n\n\t\tInsertion Successfully Happened" ;
				}
				else if(flag == 0)
				{
					cout << "\n\n\t\tInsertion Failed" ;
				}
				else if(flag == -1)
				{
					cout << "\n\n\t\tMemory Full Failure ";
				}
				else
				{
					cout << "\n\n\t\tFunction Failure" ;
				}

			}
			else
			{
				do
				{
					inop = operator_priority( sym ) ;
					data = s.getdata() ;
					stop = operator_priority( data ) ;
					if( inop > stop )
					{
						flag = s.push( size,sym ) ;
						if(flag == 1)
						{
							cout<<"\n\n\t\tInsertion Successfully Happened";
						}
						else if(flag == 0)
						{
							cout<<"\n\n\t\tInsertion Failed";
						}
						else if(flag == -1)
						{
							cout << "\n\n\t\tMemory Full Failure " ;
						}
						else
						{
							cout << "\n\n\t\tFunction Failure" ;
						}
					}
					else
					{
						flag = s.pop( size,ddata ) ;
						if(flag == 1)
						{
							cout << "\n\n\t\tDeletion Successful" ;
							cout << "\n\t\tToppest Value: "<<ddata ;
							fpstring[k] = fpstring[k] + ddata ;
							k++ ;

						}
						else if(flag == 0)
						{
							cout<<"\n\n\t\tDeletion Failed" ;
						}
						else
						{
							cout<<"\n\n\t\tFunction Failure" ;
						}
					}
				}while(inop <= stop) ;
			}
		}
		i++ ;
	}

	while(s.stackempty(size) == 1)
	{
		flag=s.pop( size,ddata ) ;
		if(flag == 1)
		{
			cout << "\n\n\t\tDeletion Successful" ;
			cout << "\n\t\tToppest Value: " << ddata ;
			fpstring[k] = fpstring[k] + ddata ;
			k++ ;
		}
		else if(flag == 0)
		{
			cout << "\n\n\t\tDeletion Failed" ;
		}
		else
		{
			cout << "\n\n\t\tFunction Failure" ;
		}
	}

	fpstring[k] = '\0' ;

	return 0 ;
}

int intopre(char fistring[10],char fpstring[10])
{
	operator_stack opr ; 		//STACK TO STORE OPERATORS
    int oprsize = -1 ;			//GIVES NO. OF NODES OP OPERATOR STACK
    int opndsize = -1 ;			//GIVES NO. OF NODES OP OPERAND STACK

	operand opnd ;				//STACK TO STORE OPERANDS
    int opndflag = 0 ;			//EXCEPTION HANDLER FOR OPERAND STACK
    int oprflag = 0 ;			//EXCEPTION HANDLER FOR OPERATOR STACK

    char sym = '\0';			//STORES THE CURRENT SYMBOL OF INFIX STRING

    char temp[10] = {'\0'} ;	//TEMPORARY VARIABLE TO STORE 'sym'
    char temp1[2]  ={'\0'} ;	//TEMPORARY VARIABLE TO STORE 'sym'

	int inop = 0 ;				//OPERATOR PRIORITY OF THE CURRENT SYMBOL
	int stop = 0 ;				//OPERATOR PRIORITY OF THE TOPPEST ELEMENT OF THE OPERATOR STACK

	char data = '\0' ;			//STORES THE CHAR IN THE TOPPEST NODE OF THE STACK
	char op = '\0';				//VARIABLE TO STORE POPPED CHAR FROM OPERATOR STACK
	char opnd1[10] = {'\0'} ;	//VARIABLE TO STORE POOPED CHAR FROM OPERAND STACK
	char opnd2[10] = {'\0'} ;	//VARIABLE TO STORE POOPED CHAR FROM OPERAND STACK

	int i = 0 ;					//COUNTER VARIABLE OF 'fistring'


	while( fistring[i] != '\0' )
	{
		sym = fistring[i] ;
		if((sym >= 'a'&& sym <= 'z') || (sym >= 'A' && sym <= 'Z'))
		{
			temp[0] = sym ;
			opndflag = opnd.push(opndsize,temp) ;
			if(opndflag == 1)
			{
				cout << "\n\n\t\tInsertion Successfully Happened" ;
			}
			else if(opndflag == 0)
			{
				cout << "\n\n\t\tInsertion Failed" ;
			}
			else if(opndflag==-1)
			{
				cout << " \n\n\t\tMemory Full Failure " ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}
		}
		else
		{
			if(opr.stackempty(oprsize) == 0)
			{
				oprflag = opr.push(oprsize,sym) ;
				if(oprflag == 1)
				{
					cout << "\n\n\t\tInsertion Successfully Happened" ;
				}
				else if(oprflag == 0)
				{
					cout << "\n\n\t\tInsertion Failed" ;
				}
				else if(oprflag == -1)
				{
					cout << "\n\n\t\tMemory Full Failure " ;
				}
				else
				{
					cout << "\n\n\t\tFunction Failure" ;
				}
			}
			else
			{
				do
				{
					inop = operator_priority(sym) ;
					data = opr.getdata() ;
					stop = operator_priority(data) ;
					if(inop > stop)
					{
						oprflag = opr.push(oprsize,sym) ;
						if(oprflag == 1)
						{
							cout << "\n\n\t\tInsertion Successfully Happened" ;
						}
						else if(oprflag == 0)
						{
							cout << "\n\n\t\tInsertion Failed" ;
						}
						else if(oprflag == -1)
						{
							cout << "\n\n\t\tMemory Full Failure " ;
						}
						else
						{
							cout << "\n\n\t\tFunction Failure" ;
						}
					}
					else
					{

						//POPPING CHAR FROM OPRATOR STACK
						oprflag = opr.pop(oprsize,op) ;
						if(oprflag == 1)
						{
							cout << "\n\n\t\tDeletion Successful" ;
							cout << "\n\t\tToppest Value: " << op;
						}
						else if(oprflag == 0)
						{
							cout << "\n\n\t\tDeletion Failed" ;
						}
						else
						{
							cout << "\n\n\t\tFunction Failure" ;
						}

						//POPPING OPND2 FROM OPERAND STACK
						opndflag = opnd.pop(opndsize,temp) ;
						strcpy(opnd2,temp) ;
						if(opndflag == 1)
						{
							cout << "\n\n\t\tDeletion Successful" ;
							cout << "\n\t\tToppest Value: " << opnd2 ;
						}
						else if(opndflag == 0)
						{
							cout << "\n\n\t\tDeletion Failed" ;
						}
						else
						{
							cout << "\n\n\t\tFunction Failure" ;
						}

						//POPPING OPND1 FROM OPERAND STACK
						opndflag = opnd.pop(opndsize,temp) ;
						strcpy(opnd1,temp) ;
						if(opndflag == 1)
						{
							cout << "\n\n\t\tDeletion Successful" ;
							cout << "\n\t\tToppest Value: " << opnd1 ;
						}
						else if(opndflag == 0)
						{
							cout << "\n\n\t\tDeletion Failed" ;
						}
						else
						{
							cout << "\n\n\t\tFunction Failure" ;
						}

						temp1[0] = op;
						strcpy(fpstring,temp1) ;
						strcat(fpstring,opnd1) ;
						strcat(fpstring,opnd2) ;

						opndflag = opnd.push(opndsize,fpstring) ;
						if(opndflag == 1)
						{
							cout << "\n\n\t\tInsertion Successfully Happened" ;
						}
						else if(opndflag == 0)
						{
							cout << "\n\n\t\tInsertion Failed" ;
						}
						else if(opndflag == -1)
						{
							cout << "\n\n\t\tMemory Full Failure " ;
						}
						else
						{
							cout << "\n\n\t\tFunction Failure" ;
						}

					}
				}while(inop <= stop) ;
			}
		}
		i++ ;
	}

	while(opr.stackempty(oprsize) == 1)
	{
		//POPPING CHAR FROM OPRATOR STACK
		oprflag = opr.pop(oprsize,op) ;
		if(oprflag == 1)
		{
			cout << "\n\n\t\tDeletion Successful" ;
			cout << "\n\t\tToppest Value: " << op ;
		}
		else if(oprflag == 0)
		{
			cout << "\n\n\t\tDeletion Failed" ;
		}
		else
		{
			cout << "\n\n\t\tFunction Failure" ;
		}

		//POPPING OPND2 FROM OPERAND STACK
		opndflag = opnd.pop(opndsize,temp) ;
		strcpy(opnd2,temp) ;
		if(opndflag == 1)
		{
			cout << "\n\n\t\tDeletion Successful" ;
			cout << "\n\t\tToppest Value: " << opnd2 ;
		}
		else if(opndflag==0)
		{
			cout << "\n\n\t\tDeletion Failed" ;
		}
		else
		{
			cout << "\n\n\t\tFunction Failure" ;
		}

		//POPPING OPND1 FROM OPERAND STACK
		opndflag=opnd.pop(opndsize,temp);
		strcpy(opnd1,temp);
		if(opndflag==1)
		{
			cout << "\n\n\t\tDeletion Successful";
			cout << "\n\t\tToppest Value: "<< opnd1;
		}
		else if(opndflag == 0)
		{
			cout << "\n\n\t\tDeletion Failed" ;
		}
		else
		{
			cout << "\n\n\t\tFunction Failure" ;
		}

		temp1[0] = op;
		strcpy(fpstring,temp1) ;
		strcat(fpstring,opnd1) ;
		strcat(fpstring,opnd2)  ;

		opndflag = opnd.push(opndsize,fpstring) ;
		if(opndflag == 1)
		{
			cout <<  "\n\n\t\tInsertion Successfully Happened" ;
		}
		else if(opndflag == 0)
		{
			cout << "\n\n\t\tInsertion Failed" ;
		}
		else if(opndflag==-1)
		{
			cout << "\n\n\t\tMemory Full Failure " ;
		}
		else
		{
			cout << "\n\n\t\tFunction Failure" ;
		}
	}
	return 0;
}

int posttoin(char fpstring[10],char fistring[10])
{
	operand opnd ;						//STACK TO STORE OPERANDS
	int opndsize = -1 ;					//GIVES NO. OF NODES OP OPERAND STACK
    int opndflag = 0 ;					//EXCEPTION HANDLER FOR OPERAND STACK

    char temp[2] = {'\0'} ;				//TEMPORARY VARIABLE TO STORE 'sym'
	char sym = '\0' ;					//STORES THE CURRENT SYMBOL OF INFIX STRING

	char op[2] = {'\0'} ;				//VARIABLE TO STORE POPPED CHAR FROM OPERATOR STACK
	char opnd1[10] = {'\0'} ;			//VARIABLE TO STORE POOPED CHAR FROM OPERAND STACK
	char opnd2[10] = {'\0'} ; 			//VARIABLE TO STORE POOPED CHAR FROM OPERAND STACK

	int i = 0;							//COUNTER VARIABLE OF 'fistring'

	while(fpstring[i] != 0)
	{
		sym = fpstring[i];
		if((sym >= 'a'&& sym <= 'z') || (sym >= 'A' && sym <= 'Z'))
		{
			temp[0] = sym ;
			opndflag = opnd.push(opndsize,temp) ;
			if(opndflag == 1)
			{
				cout << "\n\n\t\tInsertion Successfully Happened" ;
			}
			else if(opndflag == 0)
			{
				cout << "\n\n\t\tInsertion Failed" ;
			}
			else if(opndflag == -1)
			{
				cout << "\n\n\t\tMemory Full Failure " ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}
		}
		else
		{
			op[0] =sym ;

			//POPPING OPND2 FROM OPERAND STACK
			opndflag = opnd.pop(opndsize,opnd2) ;
			if(opndflag == 1)
			{
				cout << "\n\n\t\tDeletion Successful" ;
				cout << "\n\t\tToppest Value: " << opnd2 ;
			}
			else if(opndflag == 0)
			{
				cout << "\n\n\t\tDeletion Failed" ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}

			//POPPING OPND1 FROM OPERAND STACK
			opndflag = opnd.pop(opndsize,opnd1) ;
			if(opndflag==1)
			{
				cout << "\n\n\t\tDeletion Successful" ;
				cout << "\n\t\tToppest Value: " << opnd1 ;
			}
			else if(opndflag == 0)
			{
				cout << "\n\n\t\tDeletion Failed" ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}

			strcpy(fistring,"(") ;
			strcat(fistring,opnd1) ;
			strcat(fistring,op) ;
			strcat(fistring,opnd2) ;
			strcat(fistring,")") ;

			opndflag = opnd.push(opndsize,fistring) ;
			if(opndflag == 1)
			{
				cout << "\n\n\t\tInsertion Successfully Happened" ;
			}
			else if(opndflag == 0)
			{
				cout << "\n\n\t\tInsertion Failed" ;
			}
			else if(opndflag == -1)
			{
				cout << "\n\n\t\tMemory Full Failure " ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}
		}
		i++ ;
	}

	opndflag = opnd.pop(opndsize,opnd1) ;
	if(opndflag == 1)
	{
		cout << "\n\n\t\tDeletion Successful" ;
		cout << "\n\t\tToppest Value: "<<opnd1 ;
	}
	else if(opndflag == 0)
	{
		cout << "\n\n\t\tDeletion Failed";
	}
	else
	{
		cout << "\n\n\t\tFunction Failure" ;
	}

	strcpy(fistring,opnd1) ;

	return 0 ;

}

int pretoin(char fpstring[10],char fistring[10])
{
	operand opnd ;					//STACK TO STORE OPERANDS
	int opndsize = -1 ;				//GIVES NO. OF NODES OP OPERAND STACK
    int opndflag = 0 ;				//EXCEPTION HANDLER FOR OPERAND STACK

	char rstring[10] = {'\0'} ;		//VARIABLE TO STORE REVERSE OF PREFIX STRING

	char sym = '\0' ;				//STORES THE CURRENT SYMBOL OF REVERSE OF PREFIX STRING
    char temp[2] = {'\0'} ;			//TEMPORARY VARIABLE TO STORE 'sym'

	char op[2] = {'\0'};			//VARIABLE TO STORE POPPED CHAR FROM OPERATOR STACK
	char opnd1[10] = {'\0'} ;		//VARIABLE TO STORE POOPED CHAR FROM OPERAND STACK
	char opnd2[10] = {'\0'} ;		//VARIABLE TO STORE POOPED CHAR FROM OPERAND STACK

	int k = 0 ;						//COUNTER VARIABLE
	int len = 0 ;					//STORES LENGTH OF THE STRING
	int l = 0 ; 					//COUNTER VARIABLE

	int i = 0 ;						//COUNTER VARIABLE OF 'rstring'

	len = strlen(fpstring);
	for(k = len-1 ; k >= 0 ; k--)
	{
		rstring[l] = fpstring[k] ;
		l++ ;
	}

	cout << "\n\n\t\tReverse String: " << rstring ;

	while(rstring[i] != '\0')
	{
		sym = rstring[i] ;
		if((sym >= 'a' && sym <= 'z') || (sym >= 'A' && sym <= 'Z'))
		{
			temp[0] = sym ;
			opndflag = opnd.push(opndsize,temp) ;
			if(opndflag == 1)
			{
				cout << "\n\n\t\tInsertion Successfully Happened" ;
			}
			else if(opndflag == 0)
			{
				cout << "\n\n\t\tInsertion Failed" ;
			}
			else if(opndflag == -1)
			{
				cout << "\n\n\t\tMemory Full Failure " ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}
		}
		else
		{
			op[0] = sym;

			//POPPING OPND1 FROM OPERAND STACK
			opndflag = opnd.pop(opndsize,opnd1);
			if(opndflag == 1)
			{
				cout << "\n\n\t\tDeletion Successful" ;
				cout << "\n\t\tToppest Value: " << opnd1 ;
			}
			else if(opndflag == 0)
			{
				cout << "\n\n\t\tDeletion Failed" ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}

			//POPPING OPND2 FROM OPERAND STACK
			opndflag = opnd.pop(opndsize,opnd2) ;
			if(opndflag == 1)
			{
				cout << "\n\n\t\tDeletion Successful" ;
				cout << "\n\t\tToppest Value: " << opnd2 ;
			}
			else if(opndflag == 0)
			{
				cout << "\n\n\t\tDeletion Failed" ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}

			strcpy(fistring,"(") ;
			strcat(fistring,opnd1) ;
			strcat(fistring,op) ;
			strcat(fistring,opnd2) ;
			strcat(fistring,")") ;

			opndflag = opnd.push(opndsize,fistring) ;
			if(opndflag== 1)
			{
				cout << "\n\n\t\tInsertion Successfully Happened";
			}
			else if(opndflag==0)
			{
				cout<<"\n\n\t\tInsertion Failed";
			}
			else if(opndflag==-1)
			{
				cout<<"\n\n\t\tMemory Full Failure ";
			}
			else
			{
				cout<<"\n\n\t\tFunction Failure";
			}
		}
		i++;
	}

	opndflag=opnd.pop(opndsize,opnd1);
	if(opndflag==1)
	{
		cout<<"\n\n\t\tDeletion Successful";
		cout<<"\n\t\tToppest Value: "<<opnd1;
	}
	else if(opndflag==0)
	{
		cout<<"\n\n\t\tDeletion Failed";
	}
	else
	{
		cout<<"\n\n\t\tFunction Failure";
	}

	strcpy(fistring,opnd1);

	return 0;
}

int posteval(char fpstring[10],struct number fn[10],int &ffinalvalue , int structlen)
{
	eval e ;
	int esize = -1 ;		//GIVES NO. OF NODES OP Eval STACK
    int eflag = 0 ; 		//EXCEPTION HANDLER FOR Eval STACK


	int value=0 ;			//STORES THE VALUE OF THE VARIABLE

	char sym = '\0' ;		//STORES THE CURRENT SYMBOL OF POSTFIX STRING

	char op = '\0';			//VARIABLE TO STORE OPERATOR
	int opnd1 = 0 ;			//VARIABLE TO STORE POOPED CHAR FROM Eval STACK
	int opnd2 = '\0' ;		//VARIABLE TO STORE POOPED CHAR FROM Eval STACK

	int result=0;			//STORES THE CALCULATED VALUE OF OPND1 AND OPND2

	int i = 0;				//COUNTER VARIABLE OF 'fpstring'

	int flag = 0 ;

	while(fpstring[i] != '\0')
	{
		sym=fpstring[i];
		if((sym >= 'a'&& sym <= 'z') || (sym >= 'A' && sym <= 'Z'))
		{
			flag = linearSearch(sym , fn , structlen) ;
			if(flag != -1 )
			{
				value = fn[flag].value;
			}

			eflag = e.push(esize,value) ;
			if(eflag == 1)
			{
				cout<<"\n\n\t\tInsertion Successfully Happened" ;
			}
			else if(eflag == 0)
			{
				cout<<"\n\n\t\tInsertion Failed" ;
			}
			else if(eflag == -1)
			{
				cout << "\n\n\t\tMemory Full Failure " ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}
		}
		else
		{
			op = sym ;

			//POPPING OPND2 FROM OPERAND STACK
			eflag = e.pop(esize,opnd2) ;
			if(eflag == 1)
			{
				cout << "\n\n\t\tDeletion Successful" ;
				cout << "\n\t\tToppest Value: " << opnd2 ;
			}
			else if(eflag == 0)
			{
				cout << "\n\n\t\tDeletion Failed" ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}

			//POPPING OPND1 FROM OPERAND STACK
			eflag = e.pop(esize,opnd1) ;
			if(eflag == 1)
			{
				cout << "\n\n\t\tDeletion Successful" ;
				cout << "\n\t\tToppest Value: " << opnd1 ;
			}
			else if(eflag==0)
			{
				cout << "\n\n\t\tDeletion Failed" ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}

			switch(op)
			{
			case '$': result=pow(opnd1,opnd2) ;
					  break;

			case '^': result=pow(opnd1,opnd2) ;
					  break;

			case '*': result=opnd1*opnd2 ;
					  break;

			case '/': if(opnd2 != 0)
					  {
						  result = opnd1 / opnd2 ;
					  }
					  else
					  {
						  throw "Divide By Zero Error" ;
					  }

						break ;

			case '%': if(opnd2 != 0)
					  {
						  result = opnd1 / opnd2 ;
					  }
					  else
					  {
						  throw "Divide By Zero Error" ;
					  }

					  break;

			case '+': result=opnd1+opnd2 ;
					  break;

			case '-': result=opnd1-opnd2 ;
					  break;
			}

			eflag = e.push(esize,result) ;
			if(eflag == 1)
			{
				cout << "\n\n\t\tInsertion Successfully Happened" ;
			}
			else if(eflag == 0)
			{
				cout << "\n\n\t\tInsertion Failed" ;
			}
			else if(eflag == -1)
			{
				cout << "\n\n\t\tMemory Full Failure " ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}
		}
		i++;
	}

	//POPPING OPND1 FROM OPERAND STACK
	eflag = e.pop(esize,opnd1) ;
	if(eflag ==1 )
	{
		cout << "\n\n\t\tDeletion Successful" ;
		cout << "\n\t\tToppest Value: " << opnd1 ;
	}
	else if(eflag == 0)
	{
		cout << "\n\n\t\tDeletion Failed" ;
	}
	else
	{
		cout << "\n\n\t\tFunction Failure" ;
	}

	ffinalvalue = result ;
	return 0 ;
}

int pre_eval(char fpstring[10],struct number fn[10],int &ffinalvalue , int structlen)
{
	eval e ;
	int esize = -1 ;				//GIVES NO. OF NODES OP Eval STACK
    int eflag = 0 ; 				//EXCEPTION HANDLER FOR Eval STACK

	char rstring[10] = {'\0'};		//VARIABLE TO STORE REVERSE OF PREFIX STRING

	char sym = '\0';				//STORES THE CURRENT SYMBOL OF REVERSE OF PREFIX STRING
	int value = 0 ;					//STORES THE VALUE OF THE VARIABLE

	char op = '\0' ;				//VARIABLE TO STORE OPERATOR
	int opnd1 = 0  ;				//VARIABLE TO STORE POOPED CHAR FROM Eval STACK
	int opnd2 = '\0' ;				//VARIABLE TO STORE POOPED CHAR FROM Eval STACK

	int result=0 ;					//STORES THE CALCULATED VALUE OF OPND1 AND OPND2

	int i = 0;						//COUNTER VARIABLE OF 'rstring'
	int flag = 0 ;

	strcpy(rstring,fpstring);

	cout << "\n\n\t\tReverse String: " << rstring ;

	while(rstring[i] != '\0')
	{
		sym = rstring[i] ;
		if((sym >= 'a' && sym<='z') || (sym >= 'A' && sym <= 'Z'))
		{
			flag = linearSearch(sym , fn , structlen) ;
			if(flag != -1 )
			{
				value = fn[flag].value;
			}

			eflag = e.push(esize,value) ;
			if(eflag == 1)
			{
				cout << "\n\n\t\tInsertion Successfully Happened " ;
			}
			else if(eflag == 0)
			{
				cout << "\n\n\t\tInsertion Failed " ;
			}
			else if(eflag == -1)
			{
				cout << "\n\n\t\tMemory Full Failure " ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}
		}
		else
		{
			op=sym;

			//POPPING OPND1 FROM OPERAND STACK
			eflag = e.pop(esize,opnd1) ;
			if(eflag == 1)
			{
				cout << "\n\n\t\tDeletion Successful" ;
				cout << "\n\t\tToppest Value: " << opnd1 ;
			}
			else if(eflag == 0)
			{
				cout << "\n\n\t\tDeletion Failed" ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}

			//POPPING OPND2 FROM OPERAND STACK
			eflag = e.pop(esize,opnd2) ;
			if(eflag == 1)
			{
				cout << "\n\n\t\tDeletion Successful" ;
				cout << "\n\t\tToppest Value: " << opnd2 ;
			}
			else if(eflag == 0)
			{
				cout << "\n\n\t\tDeletion Failed" ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}

			switch(op)
			{
			case '$': result=pow(opnd1,opnd2) ;
					break;

			case '^': result=pow(opnd1,opnd2) ;
					break;

			case '*': result=opnd1*opnd2 ;
					break;

			case '/': if(opnd2 != 0)
					  {
						  result = opnd1 / opnd2 ;
					  }
					  else
					  {
						  throw "Divide By Zero Error" ;
					  }

					break;

			case '%': if(opnd2 != 0)
					  {
						  result = opnd1 / opnd2 ;
					  }
					  else
					  {
						  throw "Divide By Zero Error" ;
					  }

					break;

			case '+': result=opnd1+opnd2 ;
					break;

			case '-': result=opnd1-opnd2 ;
					break;
			}

			eflag = e.push(esize,result) ;
			if(eflag == 1)
			{
				cout << "\n\n\t\tInsertion Successfully Happened" ;
			}
			else if(eflag == 0)
			{
				cout << "\n\n\t\tInsertion Failed" ;
			}
			else if(eflag == -1)
			{
				cout << "\n\n\t\tMemory Full Failure " ;
			}
			else
			{
				cout << "\n\n\t\tFunction Failure" ;
			}
		}
		i++ ;
	}

	//POPPING OPND1 FROM OPERAND STACK
	eflag = e.pop(esize,opnd1) ;
	if(eflag == 1)
	{
		cout << "\n\n\t\tDeletion Successful" ;
		cout << "\n\t\tToppest Value: "<<opnd1 ;
	}
	else if(eflag == 0)
	{
		cout << "\n\n\t\tDeletion Failed" ;
	}
	else
	{
		cout << "\n\n\t\tFunction Failure" ;
	}

	ffinalvalue = result ;
	return 0 ;
}

int intopostbracket(char fistring[10],char fpstring[10])
{
	operator_stack s;		//OBJECT TO STORE OPERATORES

	int i = 0 ; 			//COUNTER VARIABLE
	int k = 0 ;				//COUNTER VARIABLE
	int size = -1 ;			//GIVES NO. OF NODES
	char sym = '\0';		//STORES THE CURRENT SYMBOL OF INFIX STRING
	int flag = -2 ;			//EXCEPTION HANDLER
	int inop = 0 ;			//OPERATOR PRIORITY OF THE CURRENT SYMBOL
	int stop = 0 ;			//OPERATOR PRIORITY OF THE TOPPEST ELEMENT OF THE STACK
	char data = '\0' ;		//STORES THE CHAR IN THE TOPPEST NODE OF THE STACK
	char ddata = '\0';		//STORE THE EXTRACTED CHAR FROM THE STACK

	while(fistring[i] != '\0')
	{

		sym = fistring[i] ;
		if((sym >= 'a'&& sym <= 'z') || (sym >= 'A' && sym <= 'Z'))
		{
			//SYMBOL IS AN OPERAND
			fpstring[k] = fpstring[k] + sym ;
			k++ ;
		}
		else
		{
			//SYM IS AN OPERATOR
			//PUSH IF THE STACK IS EMPTY OPERATOR IS OPENING BRACKET
			if(s.stackempty(size) == 0 && sym == '(')
			{
				flag = s.push( size,sym ) ;
				if(flag == 1)
				{
					cout << "\n\n\t\tInsertion Successfully Happened" ;
				}
				else if(flag == 0)
				{
					cout << "\n\n\t\tInsertion Failed" ;
				}
				else if(flag == -1)
				{
					cout << "\n\n\t\tMemory Full Failure ";
				}
				else
				{
					cout << "\n\n\t\tFunction Failure" ;
				}

			}
			else
			{
				//IF SECOND OPENNING BRACKET IS ENCOUNTERED
				if(sym == '(')
				{
					flag = s.push( size,sym ) ;
					if(flag == 1)
					{
						cout << "\n\n\t\tInsertion Successfully Happened" ;
					}
					else if(flag == 0)
					{
						cout << "\n\n\t\tInsertion Failed" ;
					}
					else if(flag == -1)
					{
						cout << "\n\n\t\tMemory Full Failure ";
					}
					else
					{
						cout << "\n\n\t\tFunction Failure" ;
					}
				}
				else
				{
					//IF OPENING BRACKET IS NOT THERE
					if(sym == ')' )
					{
						//TILL CLOSING BRACKET IS ENCOUNTERED KEEP POPPING
						do
						{
							flag = s.pop( size,ddata ) ;
							if(flag == 1)
							{
								cout << "\n\n\t\tDeletion Successful" ;
								cout << "\n\t\tToppest Value: "<<ddata ;
								if(ddata != '(')
								{
									fpstring[k] = fpstring[k] + ddata ;
									k++ ;
								}

							}
							else if(flag == 0)
							{
								cout<<"\n\n\t\tDeletion Failed" ;
							}
							else
							{
								cout<<"\n\n\t\tFunction Failure" ;
							}
						}while(ddata != '(');
					}
					else
					{
						//ELSE PUSH/POP NORMALLY
						do
						{
							inop = operator_priority( sym ) ;
							data = s.getdata() ;
							stop = operator_priority( data ) ;
							if( inop > stop )
							{
								flag = s.push( size,sym ) ;
								if(flag == 1)
								{
									cout<<"\n\n\t\tInsertion Successfully Happened";
								}
								else if(flag == 0)
								{
									cout<<"\n\n\t\tInsertion Failed";
								}
								else if(flag == -1)
								{
									cout << "\n\n\t\tMemory Full Failure " ;
								}
								else
								{
									cout << "\n\n\t\tFunction Failure" ;
								}
							}
							else
							{
								flag = s.pop( size,ddata ) ;
								if(flag == 1)
								{
									cout << "\n\n\t\tDeletion Successful" ;
									cout << "\n\t\tToppest Value: "<<ddata ;
									fpstring[k] = fpstring[k] + ddata ;
									k++ ;

								}
								else if(flag == 0)
								{
									cout<<"\n\n\t\tDeletion Failed" ;
								}
								else
								{
									cout<<"\n\n\t\tFunction Failure" ;
								}
							}
						}while(inop <= stop) ;
					}
				}
			}
		}
		i++ ;
	}

	while(s.stackempty(size) == 1)
	{
		flag=s.pop( size,ddata ) ;
		if(flag == 1)
		{
			cout << "\n\n\t\tDeletion Successful" ;
			cout << "\n\t\tToppest Value: " << ddata ;
			fpstring[k] = fpstring[k] + ddata ;
			k++ ;
		}
		else if(flag == 0)
		{
			cout << "\n\n\t\tDeletion Failed" ;
		}
		else
		{
			cout << "\n\n\t\tFunction Failure" ;
		}
	}

	fpstring[k] = '\0' ;

	return 0 ;
}
