/*
 * main.cpp
 *
 *  Created on: 19-Apr-2017
 *      Author: acer
 */

#include "prims.h"
#include<iostream>
using namespace std ;

int main( void )
{
	int ch = 0 ;
	int cnt = 0 ;
	int num = 0 ;
	int flag = 0 ;
	prims p ;

	do
	{
		ch = p.menu() ;
		if( ch == 1 )
		{
			cnt = 1 ;
		}

		switch( ch )
		{
		case 1 :	cout << "\n Enter no. of offices you want to connect in a network  : " ;
					cin >> num ;

					p.create( num ) ;
					break ;

		case 2 :	if( cnt == 1 )
					{
						flag = p.mst( num );

						if( flag > 0 )
						{
							cout << "\n\n\t TOTAL COST OF CONNECTING THE OFFICES IS : " << flag ;
						}
						else
						{
							cout << "\n OPERATION FAILED...." ;
						}
					}
					else
					{
						cout << "\n\n NETWORK NOT DEFINED....PLEASE SELECT OPTION 1.... " ;
					}
					break ;

		case 0 :	cout << "\n\n\t\t.....THANK U....." ;
					break ;
		}

	}while( ch != 0 ) ;

	return 0 ;
}
