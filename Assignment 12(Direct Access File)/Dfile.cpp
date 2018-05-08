/*
 * Dfile.cpp
 *
 *  Created on: 20-Apr-2017
 *      Author: acer
 */

#include "Dfile.h"
#include<iostream>
#include<fstream>

using namespace std;

Dfile::Dfile()
{
	// TODO Auto-generated constructor stub
	ofstream fout;
	int i= 0 ;
	s.roll = -1 ;
	s.name[0] = '-';
	s.name[1] = '\0' ;
	s.chain = -1 ;

	fout.open("master.dat" , ios::binary | ios::out );
	if(fout.is_open() == true)
	{
		if(fout.good() == true)
		{
			for( i = 0 ; i < SIZE ; i++)
			{
				fout.seekp(i*sizeof(s) , ios::beg) ;
				fout.write((char*)&s , sizeof(s)) ;
			}
		}
	}
}

Dfile::~Dfile()
{
	// TODO Auto-generated destructor stub
	ofstream fout;
	int i= 0 ;
	s.roll = -1 ;
	s.name[0] = '\0';
	s.chain = -1 ;

	fout.open("master.dat" , ios::binary | ios::out );
	if(fout.is_open() == true)
	{
		if(fout.good() == true)
		{
			for( i = 0 ; i < SIZE ; i++)
			{
				fout.seekp(i*sizeof(s) , ios::beg) ;
				fout.write((char*)&s , sizeof(s)) ;
			}
		}
	}
}

int Dfile::hash(int froll)
{
	int rval = 0 ;

	rval = froll%SIZE ;

	return rval ;
}
void Dfile::display()
{
	fstream fin ;
	int i = 0 ;
	fin.open("master.dat" , ios::binary | ios::in) ;
	if(fin.is_open() == true)
	{
		if(fin.good() == true)
		{
			cout<<"\nRollno\tname\tchain\n";
			for(i = 0 ; i < SIZE ; i++)
			{
				fin.read((char*)&s , sizeof(s) ) ;
				cout<<"\n"<<s.roll<<"\t"<<s.name<<"\t"<<s.chain;

			}
		}
	}
}

void Dfile::addrecord(struct details r)
{
	fstream fs ;

	int index = -1 ;
	int fpos = 0 ;
	int flag = -1 ;
	int chainflag = -1 ;

	fs.open("master.dat" , ios::binary | ios::in | ios::out);
	if(fs.is_open() == true && fs.good() == true)
	{
		index = hash(r.roll);
		fs.seekg(index*sizeof(s) ,ios::beg ) ;
		fs.read((char*)&s , sizeof(s));
		if(s.roll == 0)
		{
			r.chain = -1 ;
			//SLOT IS EMPTY
			fs.seekp(index*sizeof(r) , ios::beg);
			fs.write((char*)&r , sizeof(r)) ;
		}
		else
		{
			//SLOT IS NOT EMPTY
			fpos = index ;
			do
			{
				//SEARCHING THE POSTION FOR THE ELEMENT USING 'fpos' VARIABLE
				fpos = (fpos + 1 ) % 10 ;

				fs.seekg(index*sizeof(s) , ios::beg);
				fs.read((char*)&s , sizeof(s)) ;
				//IF BASE ADDRESSES ARE SAME LINK USING CHAINING.
				if(s.roll % SIZE == index)
				{
					fs.seekg(fpos*sizeof(s) , ios::beg);
					fs.read((char*)&s , sizeof(s)) ;

					if(s.roll == 0 )
					{
						r.chain = -1 ;
						fs.seekp(fpos*sizeof(r) , ios::beg);
						fs.write((char*)&r , sizeof(r)) ;

						//CHECKING IF THE CHAINING OR LINKING IS THERE OR NOT.
						//IF CHAINING IS THERE UPDATE 'pos1'.
						do
						{
							fs.seekg(index*sizeof(s) , ios::beg);
							fs.read((char*)&s , sizeof(s)) ;
							if(s.chain != -1)
							{
								index = s.chain ;
								chainflag = 1;
							}
							else
							{
								chainflag = 0 ;
							}
						}while(chainflag  == 1) ;

						fs.seekg(index*sizeof(s) , ios::beg);
						fs.read((char*)&s , sizeof(s)) ;

						s.chain = fpos ;

						fs.seekp(index*sizeof(r) , ios::beg);
						fs.write((char*)&s , sizeof(s)) ;
						flag = 1 ;
					}
					else
					{
						flag = 0 ;
					}
				}
				else
				{
					//IF THE BASE ADDRESSES ARE NOT SAME.
					if(s.roll == 0)
					{
						r.chain = -1 ;
						fs.seekp(fpos*sizeof(r) , ios::beg);
						fs.write((char*)&r , sizeof(r)) ;
						flag = 1 ;
					}
					else
					{
						flag = 0 ;
					}
				}
			}while(flag == 0 );
		}

	}
	fs.close() ;
}

int Dfile::search(int roll)
{
	ifstream fin;
	int pos = -1 ;
	int flag = 0 ;
	int pos1 = 0 ;
	int chainflag = 0 ;
	int index = 0 ;
	int break1 = -1 ;

	fin.open("master.dat" , ios::binary | ios::in) ;
	if(fin.is_open() == true && fin.good() == true)
	{
		pos = hash(roll) ;
		fin.seekg(pos*sizeof(s) , ios::beg) ;
		fin.read((char*)&s , sizeof(s));
		if(s.roll == roll)
		{
			//NUMBER IS AT DESIRED POSITION
			flag = 1 ;
			index = pos ;
		}
		else
		{
			//THE NUMBER IS NOT AT DESIRED POSITION
			pos1 = s.chain ;
			do
			{
				if(pos1 == -1)
				{
					//THERE IS NO CHAIN
					//TRAVERSE
					do
					{
						pos = (pos + 1) % 10 ;
						fin.seekg(pos*sizeof(s) , ios::beg) ;
						fin.read((char*)&s , sizeof(s));
						if(s.roll == roll)
						{
							chainflag = 1 ;
							index = pos ;
							flag = 1 ;
						}
						else
						{
							chainflag = 0 ;
							flag = 0 ;
							break1 = 1;
						}
					}while(chainflag != 1 && pos < (SIZE-1) );
				}
				else
				{
					//THERE IS CHAIN
					fin.seekg(pos1*sizeof(s) , ios::beg) ;
					fin.read((char*)&s , sizeof(s));
					if(s.roll == roll)
					{
						chainflag = 1;
						index = pos1 ;
						flag = 1 ;
					}
					else
					{
						pos1 = s.chain ;
						chainflag = 0 ;
						flag = 0 ;
					}
				}
			}while(chainflag != 1 && break1 != 1 );
		}

		if(flag == 0)
		{
			cout<<"\nRecord Not found";
			index=-1;
		}
		else
		{
			cout<<"\nRecord Found at "<<index<<" location";
			fin.seekg((index)*sizeof(s),ios::beg);
			fin.read((char*)&s, sizeof(s));
			cout<<"\n"<<s.roll<<"\t"<<s.name;
		}
	}
	else
	{
		cout<<"\nUnable to open the file for reading";
	}
	fin.close() ;
	return index ;
}


void Dfile::modify()
{
	fstream fs;
	int roll = 0 ;
	int index = 0 ;

	fs.open("master.dat" , ios::binary | ios::in | ios::out) ;
	if(fs.is_open() == true)
	{
		cout<<"\nEnter roll no of a student to be modified : ";
		cin>>roll ;

		index = search(roll);
		if(index == -1)
		{
			cout<<"\nCan't modify";
		}
		else
		{
			 //Go to the index location and check for empty slot
			fs.seekg((index)*sizeof(s),ios::beg);
			fs.read((char*)&s, sizeof(s));
			cout<<"\nEnter modified name of a student";
			cin>>s.name;
			fs.seekp((index)*sizeof(s),ios::beg);
			fs.write((char*)&s, sizeof(s));
		}
	}
	else
	{
		cout<<"\nUnable to open the file for reading";
	}
}

void Dfile::addrecord1(struct details r)
{
	fstream fs;
	int index = 0 ;
	int flag = -1 ;
	int fpos = -1 ;
	int chainflag = 0 ;

	r.chain = -1 ;

	fs.open("master.dat" ,ios::binary | ios::in | ios::out);
	if(fs.is_open() == true && fs.good() == true )
	{
		index = hash(r.roll);
		fs.seekg(index*sizeof(s) , ios::beg) ;
		fs.read((char*)&s , sizeof(s));
		if(s.roll == -1)
		{
			//slot is empty
			fs.seekp(index*sizeof(s) , ios::beg) ;
			fs.write((char*)&r , sizeof(r));
		}
		else
		{
			//slot no empty
			fpos = index ;
			do
			{
				fpos = hash(fpos+1);
				fs.seekg(fpos*sizeof(s) , ios::beg) ;
				fs.read((char*)&s , sizeof(s));
				if(s.roll == -1)
				{
					fs.seekp(fpos*sizeof(s) , ios::beg) ;
					fs.write((char*)&r , sizeof(r));

					fs.seekg(index*sizeof(s) , ios::beg) ;
					fs.read((char*)&s , sizeof(s));
					if(index == hash(s.roll))
					{
						//chaining required
						do
						{
							fs.seekg(index*sizeof(s) , ios::beg) ;
							fs.read((char*)&s , sizeof(s));
							if(s.chain != -1)
							{
								index = s.chain ;
								chainflag = 0;
							}
							else
							{
								chainflag = 1 ;
							}
						}while(chainflag == 0);

						fs.seekg(index*sizeof(s) , ios::beg) ;
						fs.read((char*)&s , sizeof(s));

						s.chain = fpos;

						fs.seekp(index*sizeof(s) , ios::beg) ;
						fs.write((char*)&s , sizeof(s));

					}
					else
					{
						//chaining not reqiured
					}
					flag = 1  ;
				}
				else
				{
					flag = 0 ;
				}
			}while(flag == 0);
		}
	}
	else
	{
		//file opening error
	}
}
