#ifndef __LISTE_H__
#define __LISTE_H__

// Définitions des types
typedef int DataType;
typedef struct Cell Cell;
typedef Cell *LinkedList;

// Définition de la structure de Cell d'une lc
struct Cell {
	DataType valeur;
	Cell *Cell_suivante;
};

// Prototypes principaux
LinkedList create_linked_list();
LinkedList push_head(LinkedList lc, DataType valeur);
LinkedList pop_head(LinkedList lc);
LinkedList push_tail(LinkedList lc, DataType valeur);
LinkedList pop_tail(LinkedList lc);
LinkedList destroy_list(LinkedList lc);

// Prototypes de fonctions secondaires
void print_list(LinkedList lc);
int length(LinkedList lc);
int is_empty(LinkedList lc);

#endif