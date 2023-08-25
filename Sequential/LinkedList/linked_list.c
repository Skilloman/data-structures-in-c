#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

LinkedList create_linked_list()
{
	return NULL;
}

LinkedList push_head(LinkedList lc, DataType valeur)
{
	// Dans tous les cas on créer notre pt sur nouvel élément.
	Cell *pt_cell = calloc(1, sizeof(Cell*));
	if(pt_cell == NULL)
	{
		fprintf(stderr, "[!] Dynamic allocation error.\n");
		exit(EXIT_FAILURE);
	}

	// Et on lui assigne la valeur demandé
	pt_cell->valeur = valeur;

	// Si la liste est vide,
	if(is_empty(lc))
	{
		// Alors il suffit de retourner un pt sur une nouvelle Cell pointant sur NULL.
		pt_cell->Cell_suivante = NULL;
		return pt_cell;
	}

	// Sinon on fait pointer cette nouvelle Cell sur la tete de l'ancienne liste.
	pt_cell->Cell_suivante = lc;
	return pt_cell;
}

LinkedList pop_head(LinkedList lc)
{
	if(is_empty(lc))
	{
		printf("(i) List is empty, nothing to remove.\n");
		return lc;
	}

	int valeur_supprimee = lc->valeur;
	Cell *cell = lc;
	lc = lc->Cell_suivante;


	free(cell);
	printf("(i) I have dequeued the element : %d\n", valeur_supprimee);
	return lc;

}

LinkedList push_tail(LinkedList lc, DataType valeur)
{
	Cell *pt_cell = calloc(1, sizeof(Cell*)); 
	if(pt_cell == NULL)
	{
		fprintf(stderr, "[!] Dynamic allocation error.\n");
		exit(EXIT_FAILURE);
	}
	
	pt_cell->valeur = valeur;
	pt_cell->Cell_suivante = NULL;

	if(is_empty(lc))
		return pt_cell;

	Cell *cell_temp = lc;
	while(cell_temp->Cell_suivante != NULL)
		cell_temp = cell_temp->Cell_suivante;

	cell_temp->Cell_suivante = pt_cell;

	return lc;
}

LinkedList pop_tail(LinkedList lc)
{
	// Soit la liste est vide ...
	if(is_empty(lc))
	{
		fprintf(stderr, "[!] List is empty, nothing to remove.\n");
		return lc;
	}
	// Soit la liste a 1 élément ...
	int valeur_supprimee = 0;
	if(length(lc) == 1)
	{
		valeur_supprimee = lc->valeur;
		free(lc);
		lc = NULL;
		printf("(i) I have successfully removed the last element : %d\n", valeur_supprimee);
		return create_linked_list();	
	}

	// Soit elle en a > 1 ...
	Cell *derniere_cell = lc->Cell_suivante;
	Cell *av_derniere_cell = lc;

	while(derniere_cell->Cell_suivante != NULL)
	{
		derniere_cell = derniere_cell->Cell_suivante;
		av_derniere_cell = av_derniere_cell->Cell_suivante;
	}

	valeur_supprimee = derniere_cell->valeur;
	free(derniere_cell);
	derniere_cell = NULL;
	av_derniere_cell->Cell_suivante = NULL;
	printf("(i) I have successfully removed the last element : %d\n", valeur_supprimee);

	return lc;
}

void print_list(LinkedList lc)
{
	if(is_empty(lc))
	{
		fprintf(stderr, "[!] Empty list, nothing to print.\n");
		return;
	}
	
	printf("*** List values : ***\n");
	while(!is_empty(lc))
	{
		lc->Cell_suivante == NULL ? printf("%d\n", lc->valeur) : printf("%d -> ", lc->valeur);
		lc = lc->Cell_suivante;
	}

	return;
}

int length(LinkedList lc)
{
	int taille = 0;

	if(is_empty(lc))
		return taille;

	while(lc != NULL)
	{
		taille++;
		lc = lc->Cell_suivante;
	}

	return taille;
}

int is_empty(LinkedList lc)
{
	return lc == NULL ? 1 : 0;
}

LinkedList destroy_list(LinkedList lc)
{
	if(is_empty(lc))
	{
		free(lc);
		lc = NULL;
		printf("(i) List has been destroyed.\n");
		return NULL;
	}	

	while(lc != NULL)
		lc = pop_head(lc);	

	printf("(i) List has been destroyed.\n");
	return NULL;
}