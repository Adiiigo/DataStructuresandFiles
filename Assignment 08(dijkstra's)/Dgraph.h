/*
 * Dgraph.h
 *
 *  Created on: 24-Mar-2017
 *      Author: acer
 */

#ifndef DGRAPH_H_
#define DGRAPH_H_

#define SIZE 10
#define INF 99999

struct node
{
	struct node *head ;
	int index ;
	struct node *last ;
};
class Dgraph
{
	struct node n[SIZE] ;
	int mat[SIZE][SIZE] ;
	int cost[SIZE] ;				//WEIGHT ARRAY
	int visited[SIZE] ;				//WEIGHT ARRAY

public:
	Dgraph();
	virtual ~Dgraph();

	void createAdjMat(int fvertices) ;

	void displayAdjMat(int fvertices) ;

	void shortestPathMat(int fvertices , int fstart) ;
};

#endif /* DGRAPH_H_ */
