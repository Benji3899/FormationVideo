#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int **matrix = NULL;
	int rows;
	int columns;
	int i, j;

	printf("Taille de la matrice (format : <rows> <columns>) ? ");
	scanf("%1d %1d", &rows, &columns);

	//Création
	matrix = malloc(rows * sizeof(int*));

	if(matrix == NULL)
		exit(1);

	for(i = 0 ; i < rows ; i++)
	{
		matrix[i] = malloc(columns * sizeof(int));

		if(matrix[i] == NULL)
			exit(1);
	}

	//Remplissage
	for(i = 0 ; i < rows ; i++)
		for(j = 0 ; j < columns ; j++)
		{
			printf("Valeur pour [%d][%d] ? ", i, j);
			scanf("%2d", &matrix[i][j]);
		}

	//Affichage
	for(i = 0 ; i < rows ; i++)
		for(j = 0 ; j < columns ; j++)
			printf("[%d][%d] = %d\n", i, j, matrix[i][j]);

	//Destruction
	for(i = 0 ; i < rows ; i++)
	{
		free(matrix[i]);
		matrix[i] = NULL;
	}
	free(matrix);
	matrix = NULL;

	return 0;
}
