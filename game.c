//by FONGOH MARTIN, UNIVERSITY OF BUEA
//Please ensure to read the readme.info to understand how the program works. it takes no arguements at the command line and no variables needs to be given by the user.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"header_life_death.h"
int main(int argc, char **argv)
{
	srand(time(NULL));
	status *cell[MAX_ROW_COL];
	int i, j;
	for(i=0; i<MAX_ROW_COL; ++i)
	{
		cell[i]= (status *) malloc (MAX_ROW_COL *sizeof(status));
	}
	//printf("1    good\n");
/*---------------------------------------------------------------------------*/
	for(i=0; i<MAX_ROW_COL; i++)											//
	{																		// Initialising all the cells to 0
		for(j=0; j<MAX_ROW_COL; j++)										//
			*(*(cell +i ) + j ) = 0;											//
	}																		//
/*--------------------------------------------------------------------------*/
printf("2    good\n");
	printf("Welcome to the game of life_sustainance \n");
	puts("Initially, we have the status of the cells as below");
	cell_status_print ( cell );
	initial_living( cell );//give half of the population a living status
	cell_status_print ( cell );
	
	while(1)
	{
		i=rand()% MAX_ROW_COL;
		j=rand()% MAX_ROW_COL;
		
		tester ( cell, i, j );
		//free the memory as was allocated above
		for(i=0; i<MAX_ROW_COL; ++i)
				free( cell[i] );
	}
	return 0;
}
