#ifndef __PATHUTIL__
#define __PATHUTIL__

#define PATHUTIL_MIND	0
#define PATHUTIL_PATH	1

extern int PATHUTIL_i4_huge;

namespace PathUtil {

	//num_edge: number of edges
	//ohd: matrix contain the tree
	//start_edge: edge to find shortest path to other edge
	//return a two dimention array that contain the result
	int **GetPath ( int num_edge, int **ohd, int start_edge );	

}

#endif