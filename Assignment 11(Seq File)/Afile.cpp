/*
 * Afile.cp p
 *
 *  Created on: 26-Mar-2017
 *      Author: acer
 */

#include </home/acer/eclipse/Sem3Workspace/dsf_sequential_file/Afile.h>
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<string.h>
using namespace std ;


Afile::Afile()
{
	// TODO Auto-generated constructor stub

}

Afile::~Afile()
{
	// TODO Auto-generated destructor stub
}

void Afile::getRecordCount(int &count)
{
	ifstream fin ;

	fin.open("student.txt" , ios::in) ;
	if(fin.is_open() == true)
	{
		do
		{
			fin.read((char*)&s ,sizeof(s)) ;
			if(!fin.eof() == true)
			{
				if(fin.good() == true)
				{
					count++ ;
				}
			}
		}while(!fin.eof() == true);
	}
}

int Afile::createDatabase(int &numRecord)
{
	int flag = -3 ;
	int subflag = -3 ;
	int rval  = -1 ;

	cout << "\n---Enter details of the student---" ;
	do
	{
		cout << "\nEnter Roll no. " ;
		cin >> s.roll;

		subflag = searchRecord(s.roll) ;
		if(subflag == -1 || subflag == 0)
		{
			//RECORD NOT FOUND
			cout << "\nEnter Name :" ;
			cin >> s.name ;

			cout << "\nEnter Division :" ;
			cin >> s.div ;

			cout << "\nEnter Address :" ;
			cin >> s.address ;

			flag = addRecord(s);
			if(flag == 0)
			{
				cout << "SUCCESSFULL ADDITION OF RECORD!!!" ;
				rval = 1 ;
				numRecord++;
			}
			else
			{
				cout << "UNSUCCESSFULL ADDITION OF RECORD!!!" ;
			}
		}
		else if(subflag == 1)
		{
			//RECORD ALREADY EXISTS
			cout << "\nRECORD ALREADY EXISTS!!!" ;
		}
		else if(subflag == -2 || subflag == -1)
		{
			//FUNCTION ERROR
			cout << "\nFUNCTION ERROR!!!" ;
		}
	}while(subflag != -1 && subflag != 0);
	return rval ;
}

int Afile::addRecord(struct details fs)
{
	ifstream fin ;
	ofstream fout ;
	int flag = -1 ;

	fin.open("student.txt" , ios::binary  | ios::in ) ;
	if(fin.is_open() == true)
	{
		fout.open("student.txt" , ios::binary  | ios::app  | ios::out ) ;
		fin.close();
		//fin = NULL ;
	}
	else
	{
		fout.open("student.txt" , ios::binary  | ios::out ) ;
		fin.close();
		//fin = NULL ;
	}

	if(fout.is_open() == true)
	{
		fout.write((char*)&fs,sizeof(fs));
		fout.close();
		//fout = NULL ;
		flag = 0 ;
	}
	else
	{
		cout << "\n\t\tFile Opening Error" ;
		flag = 1 ;
	}
	return flag ;
}

void Afile::displayARecord(int froll)
{
	ifstream fin ;
	details s;

	fin.open("student.txt" , ios::binary  | ios::in ) ;
	if(fin.is_open() == true)
	{
		do
		{
			fin.read((char*)&s ,sizeof(s)) ;
			if(s.roll == froll)
			{
				cout << "\nRoll no. :" << s.roll ;
				cout << "\nName :" << s.name ;
				cout << "\nDivision:" << s.div ;
				cout << "\nAddress:" << s.address ;

				break ;
			}
		}while(!fin.eof() == true) ;
		fin.close() ;
		//fin = NULL ;
	}
	else
	{
		cout << "\n\t\tFile Existing Error" ;
	}

}

/*int Afile::searchRecord(int froll , int &fpos)
{
	details s ;
	ifstream fin ;
	int flag  = -2;

	int cnt = 0 ;

	fin.open("student.txt" , ios::binary | ios::in ) ;
	if(fin.is_open() == true)
	{
		do
		{
			fin.read((char*)&s ,sizeof(s)) ;
			if(s.roll == froll)
			{
				flag = 1 ;
				fpos = cnt ;
				break ;
			}
			else
			{
				flag = 0 ;
			}
			cnt++;
		}while(! fin.eof()) ;
	}
	else
	{
		flag = -1 ;
	}

	fin.close();
	fin = NULL ;
	return flag ;
}*/

int Afile::searchRecord(int froll)
{
	details s ;
	ifstream fin ;
	int flag  = -2;

	int cnt = 0 ;

	fin.open("student.txt" , ios::binary | ios::in ) ;
	if(fin.is_open() == true)
	{
		do
		{
			fin.read((char*)&s ,sizeof(s)) ;
			if(s.roll == froll)
			{
				flag = 1 ;
				break ;
			}
			else
			{
				flag = 0 ;
			}
			cnt++;
		}while(!fin.eof() == true ) ;
	}
	else
	{
		flag = -1 ;
	}

	fin.close();
	//fin = NULL ;
	return flag ;
}

void Afile::displayRecord()
{
	details s ;
	ifstream fin ;

	fin.open("student.txt" , ios::binary | ios::in ) ;

	cout << "\nRoll No.\tName\tDiv\tAddress" ;
	if(fin.is_open() == true)
	{
		do
		{
			fin.read((char*)&s ,sizeof(s)) ;
			if(!fin.eof() == true)
			{
				cout << "\n" <<s.roll ;
				cout << "\t\t" << s.name ;
				cout << "\t" << s.div ;
				cout << "\t" << s.address ;
			}

		}while(!fin.eof() == true) ;

		fin.close() ;
		//fin = NULL ;
	}
	else
	{
		cout << "\n\t\tFile Existing Error" ;
	}
}

int Afile::modifyNRecord(int froll , char fname[20])
{
	ofstream fout ;
	ifstream fin ;

	int flag = -1 ;
	fin.open("student.txt" , ios::binary | ios::in ) ;
	if(fin.is_open() == true)
	{
		fout.open("temp.txt" , ios::binary | ios::out | ios::app ) ;
		if(fout.is_open() == true)
		{
			do
			{
				fin.read((char*)&s ,sizeof(s)) ;
				if(!fin.eof() == true && fin.good() == true )
				{
					if(s.roll == froll)
					{
						strcpy(s.name , fname) ;
						fout.write((char*)&s ,sizeof(s)) ;
						flag = 1 ;
					}
					else
					{
						fout.write((char*)&s ,sizeof(s)) ;
					}
				}
			}while(!fin.eof() == true) ;
			fout.close() ;
			//fout = NULL ;
		}
		else
		{
			cout << "\n\t\tRecord Not Modified . Temporary File Opening Error" ;
		}
		fin.close() ;
		//fin = NULL ;
	}
	else
	{
		cout << "\n\t\tRecord Not Modified . Original File Exisitng Error" ;
	}
	remove("student.txt");
	rename("temp.txt" , "student.txt") ;

	return flag ;
}

int Afile::modifyRecord(int froll , char fdiv)
{
	ofstream fout ;
	ifstream fin ;

	int flag = -1 ;
	fin.open("student.txt" , ios::binary | ios::in ) ;
	if(fin.is_open() == true)
	{
		fout.open("temp.txt" , ios::binary | ios::out | ios::app ) ;
		if(fout.is_open() == true)
		{
			do
			{
				fin.read((char*)&s ,sizeof(s)) ;
				if(!fin.eof() == true && fin.good() == true )
				{
					if(s.roll == froll)
					{
						s.div = fdiv ;
						fout.write((char*)&s ,sizeof(s)) ;
						flag = 1 ;
					}
					else
					{
						fout.write((char*)&s ,sizeof(s)) ;
					}
				}
			}while(!fin.eof() == true) ;
			fout.close() ;
			//fout = NULL ;
		}
		else
		{
			cout << "\n\t\tRecord Not Modified . Temporary File Opening Error" ;
		}
		fin.close() ;
		//fin = NULL ;
	}
	else
	{
		cout << "\n\t\tRecord Not Modified . Original File Exisitng Error" ;
	}
	remove("student.txt");
	rename("temp.txt" , "student.txt") ;

	return flag ;
}

int Afile::modifyARecord(int froll , char faddress[100])
{
	ofstream fout ;
	ifstream fin ;

	int flag = -1 ;
	fin.open("student.txt" , ios::binary | ios::in ) ;
	if(fin.is_open() == true)
	{
		fout.open("temp.txt" , ios::binary | ios::out | ios::app ) ;
		if(fout.is_open() == true)
		{
			do
			{
				fin.read((char*)&s ,sizeof(s)) ;
				if(!fin.eof() == true && fin.good() == true )
				{
					if(s.roll == froll)
					{
						strcpy(s.address , faddress) ;
						fout.write((char*)&s ,sizeof(s)) ;
						flag = 1 ;
					}
					else
					{
						fout.write((char*)&s ,sizeof(s)) ;
					}
				}

			}while(!fin.eof() == true) ;
			fout.close() ;
			//fout = NULL ;
		}
		else
		{
			cout << "\n\t\tRecord Not Modified . Temporary File Opening Error" ;
		}
		fin.close() ;
		//fin = NULL ;
	}
	else
	{
		cout << "\n\t\tRecord Not Modified . Original File Exisitng Error" ;
	}
	remove("student.txt");
	rename("temp.txt" , "student.txt") ;

	return flag ;

}

int Afile::modifyRecord(int froll , char fname[20] , char fdiv)
{
	ofstream fout ;
	ifstream fin ;

	int flag = -1 ;
	fin.open("student.txt" , ios::binary | ios::in ) ;
	if(fin.is_open() == true)
	{
		fout.open("temp.txt" , ios::binary | ios::out | ios::app ) ;
		if(fout.is_open() == true)
		{
			do
			{
				fin.read((char*)&s ,sizeof(s)) ;
				if(!fin.eof() == true && fin.good() == true )
				{
					if(s.roll == froll)
					{
						strcpy(s.name , fname) ;
						s.div = fdiv ;
						fout.write((char*)&s ,sizeof(s)) ;
						flag = 1 ;
					}
					else
					{
						fout.write((char*)&s ,sizeof(s)) ;
					}
				}
			}while(!fin.eof() == true) ;
			fout.close() ;
			//fout = NULL ;
		}
		else
		{
			cout << "\n\t\tRecord Not Modified . Temporary File Opening Error" ;
		}
		fin.close() ;
		//fin = NULL ;
	}
	else
	{
		cout << "\n\t\tRecord Not Modified . Original File Exisitng Error" ;
	}
	remove("student.txt");
	rename("temp.txt" , "student.txt") ;

	return flag ;
}

int Afile::modifyRecord(int froll , char fdiv , char faddress[100])
{
	ofstream fout ;
	ifstream fin ;

	int flag = -1 ;
	fin.open("student.txt" , ios::binary | ios::in ) ;
	if(fin.is_open() == true)
	{
		fout.open("temp.txt" , ios::binary | ios::out | ios::app ) ;
		if(fout.is_open() == true)
		{
			do
			{
				fin.read((char*)&s ,sizeof(s)) ;
				if(!fin.eof() == true && fin.good() == true )
				{
					if(s.roll == froll)
					{
						s.div = fdiv ;
						strcpy(s.address , faddress) ;
						fout.write((char*)&s ,sizeof(s)) ;
						flag = 1 ;
					}
					else
					{
						fout.write((char*)&s ,sizeof(s)) ;
					}
				}
			}while(!fin.eof() == true) ;
			fout.close() ;
			//fout = NULL ;
		}
		else
		{
			cout << "\n\t\tRecord Not Modified . Temporary File Opening Error" ;
		}
		fin.close() ;
		//fin = NULL ;
	}
	else
	{
		cout << "\n\t\tRecord Not Modified . Original File Exisitng Error" ;
	}
	remove("student.txt");
	rename("temp.txt" , "student.txt") ;

	return flag ;
}

int Afile::modifyRecord(int froll , char faddress[100] , char fname[20] )
{
	ofstream fout ;
	ifstream fin ;

	int flag = -1 ;
	fin.open("student.txt" , ios::binary | ios::in ) ;
	if(fin.is_open() == true)
	{
		fout.open("temp.txt" , ios::binary | ios::out | ios::app ) ;
		if(fout.is_open() == true)
		{
			do
			{
				fin.read((char*)&s ,sizeof(s)) ;
				if(!fin.eof() == true && fin.good() == true )
				{
					if(s.roll == froll)
					{
						strcpy(s.name , fname) ;
						strcpy(s.address , faddress) ;
						fout.write((char*)&s ,sizeof(s)) ;
						flag = 1 ;
					}
					else
					{
						fout.write((char*)&s ,sizeof(s)) ;
					}
				}
			}while(!fin.eof() == true) ;
			fout.close() ;
			//fout = NULL ;
		}
		else
		{
			cout << "\n\t\tRecord Not Modified . Temporary File Opening Error" ;
		}
		fin.close() ;
		//fin = NULL ;
	}
	else
	{
		cout << "\n\t\tRecord Not Modified . Original File Exisitng Error" ;
	}
	remove("student.txt");
	rename("temp.txt" , "student.txt") ;

	return flag ;
}

int Afile::modifyRecord(int froll , char fname[20] , char fdiv , char faddress[100] )
{
	ofstream fout ;
	ifstream fin ;

	int flag = -1 ;
	fin.open("student.txt" , ios::binary | ios::in ) ;
	if(fin.is_open() == true)
	{
		fout.open("temp.txt" , ios::binary | ios::out | ios::app ) ;
		if(fout.is_open() == true)
		{
			do
			{
				fin.read((char*)&s ,sizeof(s)) ;
				if(!fin.eof() == true && fin.good() == true )
				{
					if(s.roll == froll)
					{
						strcpy(s.name , fname) ;
						strcpy(s.address , faddress) ;
						s.div = fdiv ;
						fout.write((char*)&s ,sizeof(s)) ;
						flag = 1 ;
					}
					else
					{
						fout.write((char*)&s ,sizeof(s)) ;
					}
				}
			}while(!fin.eof() == true) ;
			fout.close() ;
			//fout = NULL ;
		}
		else
		{
			cout << "\n\t\tRecord Not Modified . Temporary File Opening Error" ;
		}
		fin.close() ;
		//fin = NULL ;
	}
	else
	{
		cout << "\n\t\tRecord Not Modified . Original File Exisitng Error" ;
	}
	remove("student.txt");
	rename("temp.txt" , "student.txt") ;

	return flag ;
}

int Afile::deleteRecord(int froll)
{
	int rval = -1 ;

	ofstream fout ;
	ifstream fin ;

	fin.open("student.txt" , ios::binary | ios::in ) ;
	if(fin.is_open() == true)
	{
		fout.open("temp.txt" , ios::binary | ios::out | ios::app ) ;
		if(fout.is_open() == true)
		{
			do
			{
				fin.read((char*)&s ,sizeof(s)) ;
				if(!fin.eof() == true && fin.good() == true )
				{
					if(s.roll != froll)
					{
						fout.write((char*)&s ,sizeof(s)) ;
					}
				}
			}while(!fin.eof() == true) ;
			rval = 1 ;
			fout.close() ;
			//fout = NULL ;
		}
		else
		{
			cout << "\n\t\tRecord Not Modified . Temporary File Opening Error" ;
		}
		fin.close() ;
		//fin = NULL ;
	}
	else
	{
		cout << "\n\t\tRecord Not Modified . Original File Exisitng Error" ;
	}
	remove("student.txt");
	rename("temp.txt" , "student.txt") ;

	return rval ;
}

