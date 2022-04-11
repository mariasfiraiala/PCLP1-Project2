//Copyright 2021 Maria Sfiraiala (maria.sfiraiala@stud.acs.upb.ro)

#ifndef __HELPERS__
#define __HELPERS__
#define MOD 10007

typedef struct {
		int row, column;
	} indexes;

// dynamically allocates memory for a matrix (int **)
//in other words we allocate memory for n pointers (arrays)
int **alloc_data(int row, int column)
{
	int **matrix = (int **)malloc(row * sizeof(int *));

	//defensive programming
	if (!matrix) {
		fprintf(stderr, "malloc() failed\n");
		return NULL;
	}
	//row allocation
	for (int i = 0; i < row; ++i) {
		//for each row we allocate column * sizeof(int)
		matrix[i] = (int *)malloc(column * sizeof(int));

		if (!matrix[i]) {
			fprintf(stderr, "malloc() failed\n");

			//for each row previously allocated, we deallocate since
			//the malloc() function failed
			while (--i >= 0)
				free(matrix[i]);

			free(matrix);
			return NULL;
		}
	}

	return matrix;
}

//function that reads every matrix
void read(int m, int n, int **matrix)
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &matrix[i][j]);
}

int *sum(int count, int ***p, indexes *x)
{
	//we create an array of sums % MOD by dynamically
	//allocating memory
	int *sum_array;
	sum_array = (int *)malloc(count * sizeof(int));

	for (int k = 0; k < count; ++k) {
		//for each matrix the sum starts at 0
		int s = 0;
		for (int i = 0; i < x[k].row; ++i)
			for (int j = 0; j < x[k].column; ++j) {
				s += p[k][i][j];
				if (s < 0)
					s += MOD;
				s %= (MOD);//to avoid the overflow we calculate the sum % MOD
			}
		sum_array[k] = s;//the sum is now part of the array
	}
	return sum_array;
}

void swap_matrix(int ***p, indexes *x, int *s, int i, int j)
{
	//the function swaps three entities:
	//1. two matrices
	//2. two indexes
	//3. two sums
	int **auxp = p[i];
	p[i] = p[j];
	p[j] = auxp;

	int aux = x[i].row;
	x[i].row = x[j].row;
	x[j].row = aux;

	aux = x[i].column;
	x[i].column = x[j].column;
	x[j].column = aux;

	aux = s[i];
	s[i] = s[j];
	s[j] = aux;
}

void free_matrix(int row, int **matrix)
{
	for (int i = 0; i < row; ++i)
		free(matrix[i]);
	free(matrix);
}

#endif
