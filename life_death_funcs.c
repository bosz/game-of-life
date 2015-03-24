#include<stdio.h>
#include<stdlib.h>
#include"header_life_death.h"
int i, j;
void initial_living(status *cell[MAX_ROW_COL] )
{
	int i, r, c;
	int half = (MAX_ROW_COL*MAX_ROW_COL)/2;
	//printf("the size is %d\n", half);
	while(i!=half)
	{
		r=rand() % MAX_ROW_COL;
		c=rand() % MAX_ROW_COL;
		
		//printf(" %d %d  -- \n", r, c  );
		
		if( *(*(cell + r ) + c ) == 1 )
			continue;
		else
		{
			*(*(cell + r ) + c ) = 1; 
			i++;
		}
	}

}

void tester(status *cell[MAX_ROW_COL], int row, int col )
{
	//printf("SELECTED %d %d", row, col);
	cell_status_print( cell );
	if ( *(*(cell + row ) + col ) == 0 )
	{
		*(*(cell + row ) + col ) = 1;
		cell_status_print(cell);
		life_tester(cell, row, col);
		cell_status_print(cell);
	}
	else
	{
		*(*(cell + row ) + col ) = 1;	
		life_tester(cell, row, col);
		cell_status_print( cell );
	}

}
/*======================================================================================*/
/*======================================================================================*/
/*======================================================================================*/
	
void life_tester(status *cell[MAX_ROW_COL], int row, int col )
{
int pop=0;
	
	if( row == MAX_ROW_COL-1 || col == MAX_ROW_COL-1 || col == 0 || row == 0 )  
		pop=test_edges( cell, row, col );
	else
	{
		for(i=(row-1); i<=(row+1); i++)
		{
			for(i= (col-1); j<=(col+1); j++)
			{
				if ( *(*(cell + i) + j ) == *(*(cell + row ) + col ) )
					continue;
				else
				{
					//if( *(*(cell + i ) + j ) == 1 )
						pop+=*(*(cell + i ) + j );
	}	}	}	}
	//printf("population is %d\n\n", pop);
	/*Now we have the number of living cell around cell[row][col], we need to test if it needs 
	to die or continue living*/
	if ( pop >=5 || pop <=2 )
		*(*(cell + row ) + col ) = 0; //cell dies due to sofucation or lonelyness
	else
		*(*(cell + row ) + col ) = 1; //population around the cell is just good for living
}	


/*======================================================================================*/
/*======================================================================================*/
/*======================================================================================*/

int test_edges(status *cell[MAX_ROW_COL], int row, int col)
{
	//printf(" In the edges function\n\n");
	int pop=0;
		if ( row == MAX_ROW_COL-1 && col == MAX_ROW_COL-1 )
		{
			pop+= *(*(cell + MAX_ROW_COL-2 ) + MAX_ROW_COL-2 );
			pop+= *(*(cell + MAX_ROW_COL-2 ) + MAX_ROW_COL-1 );
			pop+= *(*(cell + MAX_ROW_COL-1 ) + MAX_ROW_COL-2 );
		}
		
		
		if ( row == 0 && col == 0 )
		{
			pop+=*(*(cell + 1 ) + 1 );
			pop+=*(*(cell + 1 ) + 0 );
			pop+=*(*(cell + 0 ) + 1 );
		}
		
		
		if (row == 0 && col == MAX_ROW_COL-1 )
		{
			pop+=*(*(cell + 1 ) + MAX_ROW_COL-1 );
			pop+=*(*(cell + 0 ) + MAX_ROW_COL-2 );
			pop+=*(*(cell + 1 ) + MAX_ROW_COL-2 );
		}
		
		
		if (row == MAX_ROW_COL-1 && col == 0 )
		{
			pop+=*(*(cell + MAX_ROW_COL-1 ) + 1 );
			pop+=*(*(cell + MAX_ROW_COL-2 ) + 1 );
			pop+=*(*(cell + MAX_ROW_COL-2 ) + 0 );
		}
	
	//now getting to the other points which lie against the wall.
	//The array is not so inginite as such
	
		if (row == MAX_ROW_COL-1 && col != 0 && col != MAX_ROW_COL-1)
		{
			pop+=*(*(cell + row ) + col-1 );
			pop+=*(*(cell + row-1) + col-1 );
			pop+=*(*(cell + row-1 ) + col );
			pop+=*(*(cell + row-1 ) +  col+1);
			pop+=*(*(cell + row ) + col+1 );
		}
		
		if (col == MAX_ROW_COL-1 &&  row!= 0 && row != MAX_ROW_COL-1)
		{
			pop+=*(*(cell + row-1 ) + col );
			pop+=*(*(cell + row-1 ) + col-1 );
			pop+=*(*(cell + row ) + col-1 );
			pop+=*(*(cell +  row+1 ) + col-1);
			pop+=*(*(cell + row+1 ) + col );
		}
		
		if (row == 0 && col != MAX_ROW_COL-1 &&  col != 0)
		{
			pop+=*(*(cell + row ) + col-1 );
			pop+=*(*(cell + row+1 ) + col-1 );
			pop+=*(*(cell + row+1) + col );
			pop+=*(*(cell +  row+1 ) + col+1);
			pop+=*(*(cell + row ) + col+1 );
		}
		
		if (col == 0 && row != MAX_ROW_COL-1 &&  row != 0)
		{
			pop+=*(*(cell + row-1 ) + col );
			pop+=*(*(cell + row-1 ) + col+1 );
			pop+=*(*(cell + row) + col+1 );
			pop+=*(*(cell +  row+1 ) + col+1);
			pop+=*(*(cell + row+1 ) + col );
		}
		
		return pop;
}

void cell_status_print(status *cell[MAX_ROW_COL] )
{
	int i, j;
	for(i=0; i<MAX_ROW_COL; i++)											
		{											
			printf("\n");						
			for(j=0; j<MAX_ROW_COL; j++)										
				printf("%d ", *(*(cell + i ) + j ));											
		}		
		system("sleep 1");
		system("clear");
		
		//printf("\n\n");
	return ;
}
