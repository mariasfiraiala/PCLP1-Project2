//Copyright 2021 Maria Sfiraiala (maria.sfiraiala@stud.acs.upb.ro)

#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "strassen.h"
#include "tasks.h"

int main(void)
{
	char command;//the character that shows which command should be implemented
	int ***array3d = NULL;//the collection/array of matrices
	int count = 0;//index of current matrix
	indexes *x = NULL;//array of dimensions for every matrix in the collection

	//initializing the arrays
	x = (indexes *)malloc(sizeof(indexes));
	array3d = (int ***)malloc(sizeof(int **));

	//reading and carrying out commands
	do {
		command = fgetc(stdin);
		if (command != ' ' && command != '\n') {
			switch (command) {
			case 'L':
				array3d = load(&count, array3d, &x);
				break;
			case 'D':
				dimension(count, x);
				break;
			case 'P':
				print(count, array3d, x);
				break;
			case 'C':
				crop(count, array3d, x);
				break;
			case 'M':
				array3d = multiply_matrix(&count, array3d, &x);
				break;
			case 'O':
				sort(count, array3d, x);
				break;
			case 'T':
				transpose(count, array3d, x);
				break;
			case 'F':
				array3d = free_data(&count, array3d, &x);
				break;
			case 'S':
				array3d = task_strassen(&count, array3d, &x);
				break;
			case 'Q':
				quit(count, array3d, x);
				break;
			default:
				printf("Unrecognized command\n");
				break;
			}
		}
	} while (command != 'Q');
	return 0;
}
