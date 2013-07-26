#include "PathUtil.h"
#include <stdio.h>
#include <stdlib.h>

int PATHUTIL_i4_huge = 2147483647;

namespace PathUtil {

	void find_nearest ( int num_edge, int *mind, int *connected, int *d, int *v );
	void update_mind ( int mv, int *connected, int num_edge, int **ohd, int **result );

	int **GetPath ( int num_edge, int **ohd, int start_edge )
	{
	  int *connected;
	  int **result;  
	  int i;
	  int md;  
	  int mv;
	  int step; 

	  connected = ( int * ) malloc ( num_edge * sizeof ( int ) );
  
	  for ( i = 0; i < num_edge; i++ )
	  {		
		  connected[i] = 0;
	  }  

	  connected[start_edge] = 1;

	  result = (int**) malloc( 2 * sizeof( int* ) );  
	  result[PATHUTIL_MIND] = (int*) malloc( num_edge * sizeof( int ) );
	  result[PATHUTIL_PATH] = (int*) malloc( num_edge * sizeof( int ) );

	  for ( i = 0; i < num_edge; i++ )
	  {
		  result[PATHUTIL_MIND][i] = ohd[start_edge][i];
		  result[PATHUTIL_PATH][i] = start_edge;
	  }

	  for ( step = 1; step < num_edge; step++ )
	  {
		find_nearest ( num_edge, result[PATHUTIL_MIND], connected, &md, &mv );

		if ( mv == - 1 )
		{
		  //fprintf ( stdout, "\n" );
		  //fprintf ( stdout, "DIJKSTRA_DISTANCE - Warning!\n" );
		  //fprintf ( stdout, "  Search terminated early.\n" );
		  //fprintf ( stdout, "  Graph might not be connected.\n" );
		  break;
		}

		connected[mv] = 1;
		update_mind ( mv, connected, num_edge, ohd, result );
	  }

	  free ( connected );

	  return result;
	}

	void find_nearest ( int num_edge, int *mind, int *connected, int *d, int *v )
	{
	  int i;
  
	  *d = PATHUTIL_i4_huge;
	  *v = -1;

	  for ( i = 0; i < num_edge; i++ )
	  {
		if ( !connected[i] && mind[i] < *d )
		{
		  *d = mind[i];
		  *v = i;
		}
	  }

	  return;
	}

	void update_mind ( int mv, int *connected, int num_edge, int **ohd, int **result )
	{
	  int i;  

	  for ( i = 0; i < num_edge; i++ )
	  {
		if ( !connected[i] )
		{
		  if ( ohd[mv][i] < PATHUTIL_i4_huge )
		  {
			  if ( result[PATHUTIL_MIND][mv] + ohd[mv][i] < result[PATHUTIL_MIND][i] )  
			{
			  result[PATHUTIL_MIND][i] = result[PATHUTIL_MIND][mv] + ohd[mv][i];
			  result[PATHUTIL_PATH][i] = mv;
			}
		  }
		}
	  }

	  return;
	}


}
