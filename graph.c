/*graph.c has three functions - printVertices(int N, int G[][N]), printEdges(int N, int G[][N]), isThereAPath(int N, int G[][N], int v1, int v2). The main() function runs these three functions
with certain given inputs*/
/* These functions, respectively, print the vertices of a given graph G with N vertices, the edges of a given graph G with N vertices, and whether a path exists between two vertices v1 and v2 in
graph G */
#include <stdio.h>

void printVertices(int N, int G[][N]) {			
	printf ("\nThe graph has vertices: ");		
	int vertex = 0;					/* starting with vertex 0 */			
	while (vertex < N){				/* as long as the current vertex # is less than the total number of vertices given */
		printf("Vertex %d\n", vertex);		/* print the current vertex # */
		vertex +=1;				/* and increase vertex # for next iteration */
	}
	return;
}

void printEdges(int N, int G[][N]) {
	printf("\nThe graph has edges: ");						
        int row = 0;							/* starting with row 0 */			
        int column = 0;							/* and starting with column 0*/
        while (row < N){						/* while our current row is within bounds of the matrix... */
                column = 0;						/* reset the to column 0 for iterations of the above while loop */
                while (column < N){					/* while our current column is within bounds of the matrix... */
                        if (G[row][column] == 1){			/* if there is an edge at the current coordinate (combination of current column # and row #)... */
				printf("[%d, %d]\n", row, column);	/* print the coordinates */
                                column +=1;				/* and increase column # for next iteration */
                        }	
                        else{						/* if there is no edge... */
                                column += 1;				/* just increase column # for next iteration */
                        }
                }
                row += 1;			/* after all coordinates between all columns and this current row have been examined, increase row # to examine the next row for next iteration */
        }
        return;	
}


void isThereAPath(int N, int G[][N], int v1, int v2) {									
	int flag = 0;			/* set flag as 0 (if unchanged from 0, signals that there is no edge - if changed from 0, signals that there is some edge, between vertices v1 and v2) */
	if (G[v1][v2] == 1){											/* if there is a 1 at row v1 and column, v2 signifying an edge */
		flag +=1;											/* add 1 to the flag  */
	}
	if( G[v2][v1] == 1){											/* if there is a 1 at row v2 and column, v1 signifying an edge  */
		flag +=1;											/* add 1 to the flag  */
	}
	if (flag == 0){												/* if the flag is 0, unchanged, then...  */
		printf("\nNo, there is no path between Vertex %d and Vertex %d.\n", v1, v2);			/* state that there is no path between the given vertices  */
	}
	else {													/* otherwise... */
		printf("\nYes, there is a path between Vertex %d and Vertex %d.\n", v1, v2);			/* state that there is a path between the given vertices  */
	}
	return;
}

#define N 5

int main() {						
	
	int Graph[N][N] = { 	{0,1,0,0,1},			/* graph is filled as shown */
				{1,0,0,0,1},
				{0,0,0,1,0},
				{0,0,1,0,0},
				{1,1,0,0,0}
			};

	printVertices(N, Graph);				/* calls the above functions with given values */
	printEdges(N, Graph);
	isThereAPath(N, Graph, 0, 1);
	isThereAPath(N, Graph, 0, 3);

	return 0;

}

