/*
 * hashing.cpp
 *
 *  Created on: 20-Feb-2017
 *      Author: acer
 */

#include</home/acer/eclipse/Sem3Workspace/Hashing/hashing.h>
#include<iostream>
#include<stddef.h>
#include<stdlib.h>
using namespace std;


//DONE
hashing::hashing()
{
	// TODO Auto-generated constructor stub
	int i = 0 ;
	for(i = 0 ; i < SIZE ; i++ )
	{
		arr[i] = -1;
	}

	for(i = 0 ; i < SIZE ; i++ )
	{
		chain[i] = -1;
	}
}

//DONE
hashing::~hashing()
{
	// TODO Auto-generated destructor stub
	int i = 0 ;
	for(i = 0 ; i < SIZE ; i++ )
	{
		arr[i] = -1;
	}

	for(i = 0 ; i < SIZE ; i++ )
	{
		chain[i] = -1;
	}
}

//DONE
void hashing::clean()
{
	int i = 0 ;
	for(i = 0 ; i < SIZE ; i++ )
	{
		arr[i] = -1;
	}

	for(i = 0 ; i < SIZE ; i++ )
	{
		chain[i] = -1;
	}
}

//DONE
int hashing::insertDataWorWoc(int farray[SIZE])
{
	int rval = -1 ;
	int first = 0 ;
	int pos = -1 ;
	int flag = 0 ;
	int i = 0 ;
	int j = 0 ;
	int k = 0 ;

	while(i < SIZE)
	{
		//SUBSTITUTING VALUE AT iTH POSITION IN FIRST
		first = farray[i];
		pos = first % 10;
		//IF EMPTY
		if(arr[pos] == -1)
		{
			arr[pos] = first ;
			rval++;
		}
		//NOT EMPTY
		else
		{
			//RUNNING TH ELOOP UNTIL WE WILL GET THE DESIRED LOCATION
			do
			{
				pos = ( pos + 1 ) % 10;
				if(arr[pos] == -1)
				{
					arr[pos] = first ;
					rval++;
					flag = 1 ;
				}
				else
				{
					flag = 0 ;
 				}
			}while( flag == 0 );
		}

		cout<<"\n\nElement Added:"<<farray[i];

		cout<<"\nIndex\t\t";
		for(j = 0 ; j < SIZE ; j++)
		{
			cout<<j<<"\t";
		}

		cout<<"\nElements\t";
		for (k = 0 ; k < SIZE ; k++ )
		{
			cout<<arr[k]<<"\t";
		}

		i++;
	}
	return rval ;
}

//DONE
int hashing::searchDataWorWoc(int farray[SIZE])
{
	int rval = -1 ;
	int pos = -1 ;
	int count = 0 ;
	int flag = -1 ;
	int fdata = 0 ;
	int i= 0 ;

	cout<<"\n\n\tHashing Without Replacement Without Chaining";
	cout<<"\nIndex\t\t";

	for(i = 0 ; i < SIZE ; i++)
	{
		cout<<i<<"\t";
	}

	cout<<"\n\nElements\t";
	for (i = 0 ; i < SIZE ; i++ )
	{
		cout<<farray[i]<<"\t";
	}

	i = 0 ;
	cout<<"\n\nComp.\t\t";
	while(i < SIZE)
	{
		fdata = farray[i];
		pos = fdata % 10;
		//CHECKING IF THE DATA IS IN THAT ADDRESS
		if(arr[pos] == fdata)
		{
			count++ ;
		}
		//THIS PART IF THE ELEMENT IS NOT THERE AT THAT POSTION
		else
		{
			count++;
			do
			{
				//KEEP ON INCREASING 'pos' TO GET DESIRED VALUE
				pos = ( pos + 1 ) % 10;
				if(arr[pos] == fdata)
				{
					flag = 1 ;
				}
				else
				{
					flag = 0 ;
				}
				count++;
			}while( flag == 0 );
		}
		cout<<count<<"\t";
		count = 0 ;
		i++;
	}
	return rval ;
}

//DONE
int hashing::insertDataWorWc(int farray[SIZE])
{
	int rval = -1 ;
	int i = 0 ;
	int j = 0 ;
	int first = 0 ;
	int pos = -1 ;
	int flag = -1 ;
	int pos1 = -1 ;
	int chainflag = -1 ;

	//'while' LOOP FOR INSERTING DATA IN THE ARRAY
	while(i < SIZE)
	{
		first = farray[i];
		pos = first % 10;
		//INSERTING ELEMENT IN THE ARRAY IF NO DATA IS PRESENT AT THAT POSITON
		if(arr[pos] == -1)
		{
			arr[pos] = first ;
			rval++;
		}
		else
		{
			do
			{
				//SEARCHING THE POSTION FOR THE ELEMENT USING 'pos' VARIABLE.
				pos1 = first % 10 ;
				pos = ( pos + 1 ) % 10;
				//IF BASE ADDRESSES ARE SAME LINK USING CHAINING.
				if(pos1 == ( arr[pos1] % 10) )
				{
					//IF THAT PSOTION IS NULL.
					if(arr[pos] == -1)
					{
						arr[pos] = first ;

						//CHECKING IF THE CHAINING OR LINKING IS THERE OR NOT.
						//IF CHAINING IS THERE UPDATE 'pos1'.
						do
						{
							if(chain[pos1] != -1)
							{
								pos1=chain[pos1];
								chainflag = 1 ;
							}
							else
							{
								chainflag = 0 ;
							}
						}while(chainflag == 1);

						chain[pos1] = pos ;
						rval++;
						flag = 1 ;
					}
					else
					{
						flag = 0 ;
	 				}
				}
				//IF THE BASE ADDRESSES ARE NOT SAME.
				else
				{
					//IF THAT POSITION IS NULL.
					if(arr[pos] == -1)
					{
						arr[pos] = first ;
						rval++;
						flag = 1 ;
					}
					else
					{
						flag = 0 ;
	 				}
				}
			}while( flag == 0 );
		}

		cout<<"\n\nElement Added:"<<farray[i];

		cout<<"\nIndex\t\t";
		for(j = 0 ; j < SIZE ; j++)
		{
			cout<<j<<"\t";
		}

		cout<<"\nElements\t";
		for (j = 0 ; j < SIZE ; j++ )
		{
			cout<<arr[j]<<"\t";
		}

		cout<<"\nChain\t\t";
		for (j = 0 ; j < SIZE ; j++ )
		{
			cout<<chain[j]<<"\t";
		}

		i++;
	}
	return rval ;
}

//DONE
int hashing::searchDataWorWc(int farray[SIZE])
{
	int rval = 0 ;
	int pos = -1 ;
	int pos1 = -1 ;
	int count = 0 ;
	int flag = -1 ;
	int i = 0 ;
	int fdata = 0 ;

	cout<<"\n\n\tHashing Without Replacement With Chaining";
	cout<<"\nIndex\t\t";

	for(i = 0 ; i < SIZE ; i++)
	{
		cout<<i<<"\t";
	}

	cout<<"\n\nElements\t";
	for (i = 0 ; i < SIZE ; i++ )
	{
		cout<<farray[i]<<"\t";
	}

	i = 0 ;
	cout<<"\n\nComp.\t\t";
	while(i < SIZE)
	{
		fdata = farray[i];
		pos = fdata % 10;
		//CHECKING IF THE ELEMENT IS THERE AT THE DESIRED POSTION
		if(arr[pos] == fdata)
		{
			count ++ ;
		}
		//THIS PART IMPLIES IT IS NOT THERE
		else
		{
			count++;
			pos1 = chain[pos];

			//THERE IS NO CHAIN
			if(pos1 == -1)
			{
				do
				{
					//KEEP ON INCREASING TO GET DESIRED ADDRESS
					pos = ( pos + 1 ) % 10;
					if(arr[pos] == fdata)
					{
						flag = 1 ;
					}
					else
					{
						flag = 0 ;
					}
					count++ ;
				}while(flag == 0 && count < SIZE );
			}
			else
			{
				do
				{
					//TO FIND DESIRED ADDRESS USING CHAIN
					if(arr[pos1] == fdata)
					{
						flag = 1 ;
					}
					else
					{
						flag = 0 ;
						pos1 = chain[pos1] ;
					}
					count++ ;
				}while( flag == 0 && count < SIZE );
			}
		}
		cout<<count<<"\t";
		count = 0 ;
		i++;
	}
	return rval ;
}

//DONE
int hashing::insertDataWrWoc(int farray[SIZE])
{
	int rval = -1 ;
	int i = 0 ;
	int pos = 0 ;
	int first = 0 ;
	int flag = -1 ;
	int temp = 0 ;
	int pos1 = 0 ;
	int pos1flag = 0 ;
	int j = 0 ;
	int  k = 0 ;
	while(i < SIZE )
	{
		first = farray[i];
		pos = farray[i] % 10 ;
		//IF THAT BASE ADDRESS IS EMPTY
		if(arr[pos] == -1)
		{
			arr[pos] = first ;
			rval++ ;
		}
		else
		{
			//IF ELEMENT IS STORED WITH CORRECT BASE ADDRESS
			if(pos == arr[pos] % 10)
			{
				do
				{
					pos = ( pos + 1 ) % 10 ;
					if(arr[pos] == -1)
					{
						arr[pos] = first ;
						rval++ ;
						flag = 1;
					}
					else
					{
						flag = 0 ;
					}
				}while(flag == 0);
			}
			else
			{
				//IF ELEMENT IS STORED WITH DIFFERENT BASE ADDRESS
				temp = arr[pos] ;
				arr[pos] = first ;
				pos1 = pos ;
				do
				{
					pos1 = ( pos1 + 1 ) % 10 ;
					if(arr[pos1] == -1)
					{
						arr[pos1] = temp ;
						pos1flag = 1 ;
					}
					else
					{
						pos1flag = 0 ;
					}
				}while(pos1flag == 0);
			}
		}

		cout<<"\n\nElement Added:"<<farray[i];

		cout<<"\nIndex\t\t";
		for(j = 0 ; j < SIZE ; j++)
		{
			cout<<j<<"\t";
		}

		cout<<"\nElements\t";
		for (k = 0 ; k < SIZE ; k++ )
		{
			cout<<arr[k]<<"\t";
		}
		i++ ;
	}
	return rval ;
}

//DONE
int hashing::searchDataWrWoc(int farray[SIZE])
{
	int rval = -1 ;
	int pos = -1 ;
	int count = 0 ;
	int flag = -1 ;
	int fdata = 0 ;
	int i= 0 ;

	cout<<"\n\n\tHashing With Replacement Without Chaining";
	cout<<"\nIndex\t\t";

	for(i = 0 ; i < SIZE ; i++)
	{
		cout<<i<<"\t";
	}

	cout<<"\n\nElements\t";
	for (i = 0 ; i < SIZE ; i++ )
	{
		cout<<farray[i]<<"\t";
	}

	i = 0 ;
	cout<<"\n\nComp.\t\t";
	while(i < SIZE)
	{
		fdata = farray[i];
		pos = fdata % 10;
		//CHECKING IF THE DATA IS IN THAT ADDRESS
		if(arr[pos] == fdata)
		{
			count++ ;
		}
		//THIS PART IF THE ELEMENT IS NOT THERE AT THAT POSTION
		else
		{
			count++;
			do
			{
				//KEEP ON INCREASING 'pos' TO GET DESIRED VALUE
				pos = ( pos + 1 ) % 10;
				if(arr[pos] == fdata)
				{
					flag = 1 ;
				}
				else
				{
					flag = 0 ;
				}
				count++;
			}while( flag == 0 );
		}
		cout<<count<<"\t";
		count = 0 ;
		i++;
	}
	return rval ;
}


int hashing::insertDataWrWc(int farray[SIZE])
{
	int rval = -1 ;
	int i= 0 ;
	int first = 0 ;
	int pos = 0 ;
	int pos1 = 0 ;
	int chainflag = 0 ;
	int flag = 0 ;
	int temp = 0 ;
	int j = 0 ;
	int temppos = 0 ;
	while(i < SIZE)
	{
		first = farray[i];
		pos = first % 10 ;
		if(arr[pos] == -1)
		{
			arr[pos] =first ;
			rval++ ;
		}
		else
		{
			if(pos == arr[pos] % 10)
			{
				//FIND NEXT LOCATION FOR THE ELEMENT WITH SAME BASE ADDRESS
				pos1 = pos ;
				do
				{	/*HERE, pos1 = is the base address of the "first" element
					 and pos is getting updated to find the empty loc.*/

					pos = ( pos + 1 ) % 10 ;
					if(arr[pos] == -1)
					{
						//IF THAT LOCATION IS EMPTY
						arr[pos] = first ;
						//CHECKING IF THE CHAINING OR LINKING IS THERE OR NOT.
						//IF CHAINING IS THERE UPDATE 'pos1'.
						do
						{
							if(chain[pos1] != -1)
							{
								pos1=chain[pos1];
								chainflag = 1 ;
							}
							else
							{
								chainflag = 0 ;
							}
						}while(chainflag == 1);

						chain[pos1] = pos ;
						rval++;
						flag = 1 ;
					}
					else
					{
						flag = 0 ;
					}
				}
				while(flag == 0);
			}
			else
			{
				//FIND NEXT LOCATION FOR THE ELEMENT WHICH WAS IN FAULTY LOC.
				temp = arr[pos] ;
				//temppos =chain[ (temp % 10) ] ;
				for(j = 0 ; j < SIZE ; j++)
				{
					if(chain[j] == pos)
					{
						temppos = j ;
						chain[i] = -1;
					}
				}

				arr[pos] = first ;
				//chain[pos] = -1 ;
				do
				{
					/*HERE, pos1 = is the base address of the "first" element
					         and pos is getting updated to find the empty loc.*/
					//pos1 = temppos ;
					pos = ( pos + 1 ) % 10 ;
					if(arr[pos] == -1)
					{
						//IF THAT LOCATION IS EMPTY
						arr[pos] = temp ;
						//CHECKING IF THE CHAINING OR LINKING IS THERE OR NOT.
						//IF CHAINING IS THERE UPDATE 'pos1'.
						chain[temppos] = pos ;
						rval++;
						flag = 1 ;
					}
					else
					{
						flag = 0 ;
					}
				}while(flag == 0);
			}
		}

		cout<<"\n\nElement Added:"<<farray[i];

		cout<<"\nIndex\t\t";
		for(j = 0 ; j < SIZE ; j++)
		{
			cout<<j<<"\t";
		}

		cout<<"\nElements\t";
		for (j = 0 ; j < SIZE ; j++ )
		{
			cout<<arr[j]<<"\t";
		}

		cout<<"\nChain\t\t";
		for (j = 0 ; j < SIZE ; j++ )
		{
			cout<<chain[j]<<"\t";
		}
		i++;
	}
	return rval ;
}

int hashing::searchDataWrWc(int farray[SIZE])
{
	int rval = 0 ;
	int pos = -1 ;
	int pos1 = -1 ;
	int count = 0 ;
	int flag = -1 ;
	int i = 0 ;
	int fdata = 0 ;

	cout<<"\n\n\tHashing With Replacement With Chaining";
	cout<<"\nIndex\t\t";

	for(i = 0 ; i < SIZE ; i++)
	{
		cout<<i<<"\t";
	}

	cout<<"\n\nElements\t";
	for (i = 0 ; i < SIZE ; i++ )
	{
		cout<<farray[i]<<"\t";
	}

	i = 0 ;
	cout<<"\n\nComp.\t\t";
	while(i < SIZE)
	{
		fdata = farray[i];
		pos = fdata % 10;
		//CHECKING IF THE ELEMENT IS THERE AT THE DESIRED PSOTION
		if(arr[pos] == fdata)
		{
			count ++ ;
		}
		//THIS PART IMPLIES IT IS NOT THERE
		else
		{
			count++;
			pos1 = chain[pos];
			//THERE IS NO CHAIN
			if(pos1 == -1)
			{
				do
				{
					//KEEP ON INCREASING TO GET DESIRED ADDRESS
					pos = ( pos + 1 ) % 10;
					if(arr[pos] == fdata)
					{
						flag = 1 ;
					}
					else
					{
						flag = 0 ;
					}
					count++ ;
				}while(flag == 0 && count < SIZE );
			}
			else
			{
				do
				{
					//TO FIND DESIRED ADDRESS USING CHAIN
					if(arr[pos1] == fdata)
					{
						flag = 1 ;
					}
					else
					{
						flag = 0 ;
						pos1 = chain[pos1] ;
					}
					count++ ;
				}while( flag == 0 && count < SIZE );
			}
		}
		cout<<count<<"\t";
		count = 0 ;
		i++;
	}
	return rval ;
}

int hashing::insertDatall(struct datanode s[10] ,int farray[SIZE])
{
	struct datanode *newnode = NULL ;
	struct datanode *a = NULL ;

	int j = 0 ;
	int rval = 0 ;
	int i = 0 ;
	int flag = -1 ;
	int first = 0 ;
	int pos = 0 ;
	while(i < SIZE)
	{
		first = farray[i];
		pos = first % 10 ;
		if(s[pos].data == 0)
		{
			s[pos].index = pos ;
			s[pos].data = first ;
			s[pos].next = NULL ;
			rval++ ;
		}
		else
		{
			newnode = (struct datanode*)calloc(1,sizeof(struct datanode));
			if(newnode == NULL)
			{
				cout<<"\n\n\t\tMemmory Allocation Failed ";
			}
			else
			{
				cout<<"\n\n\t\tMemory Allocation Successful";
				newnode->index = pos ;
				newnode->data = first ;
				newnode->next = NULL ;
				rval++ ;

				a=s[pos].next;
				do
				{
					if(a == NULL)
					{
						a->next=newnode;
					}
					else
					{
						a=a->next;
					}
				}while(a != NULL);
			}
		}

		cout<<"\n\nElement Added:"<<farray[i];

		cout<<"\nIndex\t\t";
		for(j = 0 ; j < SIZE ; j++)
		{
			cout<<j<<"\t";
		}

		a = NULL ;
		cout<<"\nElements\t";
		for (j = 0 ; j < SIZE ; j++ )
		{
			if(s[j].data == 0)
			{
				cout<<"--\t";
			}
			else
			{
				cout<<s[j].data<<"\t";
				do
				{
					a=s[j].next ;
					if(a != NULL)
					{
						cout<<","<<a->data;
						flag = 0 ;
					}
					else
					{
						flag = 1 ;
					}
				}while(flag == 0);
			}
		}
		i++;
	}
	return rval ;
}

int hashing::searchDatall(struct datanode s[10] ,int farray[SIZE])
{
	struct datanode *a = NULL ;

	int rval = 0 ;
	int i = 0 ;
	int fdata = 0 ;
	int pos  = 0 ;
	int count  = 0 ;

	cout<<"\n\n\tHashing Using Linked List";
	cout<<"\nIndex\t\t";

	for(i = 0 ; i < SIZE ; i++)
	{
		cout<<i<<"\t";
	}

	cout<<"\n\nElements\t";
	for (i = 0 ; i < SIZE ; i++ )
	{
		cout<<farray[i]<<"\t";
	}

	i = 0 ;
	cout<<"\n\nComp.\t\t";
	while(i < SIZE)
	{
		fdata = farray[i];
		pos = fdata % 10 ;
		if(s[pos].data == fdata)
		{
			count++ ;
		}
		else
		{
			count++;
			a = s[pos].next;
			do
			{
				if(a != NULL)
				{
					if(a->data == fdata)
					{
						count++;
					}
				}
				else
				{
					//DO NOTHING
				}
			}while(a != NULL);

		}
		cout<<count<<"\t";
		count = 0 ;
		i++;
	}
	return rval ;
}

void hashing::displayData()
{
	int i = 0 ;
	cout<<"\n\n\t\tArray Elements:";
	cout<<"{\t";
	for(i = 0 ; i < SIZE ; i++)
	{
		cout<<arr[i];
		if( i == SIZE-1)
		{
			cout<<"\t";
		}
		else
		{
			cout<<",";
		}
	}
	cout<<"}";
}


