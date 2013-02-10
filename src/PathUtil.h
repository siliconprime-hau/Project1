#ifndef __PATHUTIL__
#define __PATHUTIL__

#define PATHUTIL_MIND	0
#define PATHUTIL_PATH	1

extern int i4_huge;

namespace PathUtil {

int **GetPath ( int num_edge, int **ohd, int start_edge );
void find_nearest ( int num_edge, int *mind, int *connected, int *d, int *v );
void update_mind ( int mv, int *connected, int num_edge, int **ohd, int **result );

}

#endif