/*
 * Agraph.h
 *
 *  Created on: 16-Mar-2017
 *      Author: acer
 */

#ifndef AGRAPH_H_
#define AGRAPH_H_

#define SIZE 10
struct details
{
	int index ;
	char name ;
	int month ;
	int noc ;
	struct node *head ;
	struct node *last ;
};

struct node
{
	int cindex ;
	struct node  *cnext ;
};

struct varray
{
	char vname ;
	int vindex ;
};

class Agraph
{
	struct varray v[SIZE];			//VISITED ARRAY STRUCTURE
	struct details d[SIZE] ;		//FOR ADJACENTCY LIST
	//int m[SIZE][SIZE];			//FOR ADJACENTCY MATRIX

public:
	Agraph();
	~Agraph();

	//void createAdjMatrix(int fvertices);
	void createAdjList(int fvertices);

	//void displayAdjMatrix(int fvertices);
	void displayAdjList(int fvertices);

	void depthFirstSearch(int fvertices);
	//void breadthFirstsearch(int fvertices);

	void maxFriends(int fvertices);

	void getUserCount(int fmonth , int fvertices);
};

#endif /* AGRAPH_H_ */
