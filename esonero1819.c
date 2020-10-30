/***************************************************
Sia data una lista di stringhe i cui elementi sono definiti tramite
la seguente struttura C:
struct node {
char *word;
struct node *next;
};
e lo scheletro di codice sotto riportato.
Si completi il codice, scrivendo l'implementazione delle funzioni C
insert
print_list
avg_word_length
che appaiono nello scheletro, dove:
1) la funzione insert implementa l'inserimento in lista senza
ripetizione (una stringa viene inserita nella lista solo se la stessa
non è già presente nella lista)
2) la funzione print_list stampa a schermo gli elementi della lista
3) la funzione avg_word_length restituisce la lunghezza media delle
stringhe presenti nella lista
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char *word;
	struct node *next;
};

void insert (struct node **headPointer, char *string) {
	
	struct node *current;
	struct node *newNode;
	int check = 0;
	
	current = *headPointer;
	
	while (current != NULL) {
		if (strcmp(current->word,string) == 0) {
			check = 1;
		}
		current = current->next;
	}
	
	if (!check) {
		
		newNode = malloc(sizeof(struct node));
		if (newNode == NULL) {
			printf("Errore nell'allocazione di memoria.\n");
			exit(EXIT_FAILURE);
		}
	
		newNode->word = string;
		newNode->next = *headPointer;
		*headPointer = newNode;
	}
	else {
		printf("Stringa gia' presente.\n");
	}
	
	return;
	
}

void print_list (struct node *headPointer) {
	
	struct node *current;
	
	if (headPointer == NULL) {
		printf("Lista vuota.\n");
		return;
	}
	else {
		printf("La lista creata e':\n");
		for (current=headPointer; current != NULL; current=current->next) {
			printf(" %s --->", current->word);
		}
		printf(" NULL\n");
	}
	
}

float avg_word_length (struct node *headPointer) {
	
	float somma = 0;
	float contatore = 0;
	float average;
	struct node *current;
	
	if (headPointer == NULL) {
		return contatore;
	}
	else {
		for (current = headPointer; current->next != NULL; current=current->next) {
			somma = somma + strlen(current->word);
			contatore = contatore + 1;
		}
		average = somma / contatore;
	}
	
	return average;
}

int main (int argc, char** argv) {
	
	struct node *list_head = NULL;
	
	insert(&list_head, "elettronici");
	print_list(list_head);
	insert(&list_head, "calcolatori");
	print_list(list_head);
	insert(&list_head, "prova pratica");
	print_list(list_head);
	insert(&list_head, "calcolatori");
	print_list(list_head);
	printf("Media lunghezza = %f\n", avg_word_length(list_head));

	return 0;

}