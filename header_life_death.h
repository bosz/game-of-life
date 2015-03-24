//The status: 0 for a dead cell and 1 for a living cell.
typedef short int status;
#define MAX_ROW_COL 10
//The maximum number of rows and columns are the same as the macro specifies

void initial_living(status *cell[MAX_ROW_COL] );

void tester(status *cell[MAX_ROW_COL], int row, int col);

void cell_status_print(status *cell[MAX_ROW_COL]);

void life_tester(status *cell[MAX_ROW_COL], int row, int col );

int test_edges(status *cell[MAX_ROW_COL], int row, int col);
