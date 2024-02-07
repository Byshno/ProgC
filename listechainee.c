#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


typedef struct {
    Node* head;
} LinkedList;


void initList(LinkedList* list) {
    list->head = NULL;
}


void displayList(const LinkedList* list) {
    const Node* current = list->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}


void appendToList(LinkedList* list, int value) {

  if (test_elem_in_list(list, n))
    return NULL;
  
  listechainee_ptr new_node = (listechainee_ptr)malloc(sizeof(struct listechainee_st));
  new_node->N = n;
  new_node->next = (listechainee_ptr)NULL;
  if (list == NULL)
    {
      list = new_node;
    }
  else
    {
      listechainee_ptr tmp = list;
      while(tmp)
        {
          if (tmp->next == NULL)
            break;
          tmp = tmp->next;
        }
      tmp->next = new_node;
    }
  return list; 
}


void freeList(LinkedList* list) {
      while(list)
    {
      listechainee_ptr tmp = list;
      list = list->next;
      free(tmp);
    }

}


int main() {
    LinkedList list;
    initList(&list);

    int choice;

    do {
        printf("Bonjour, opération à effectuer ?\n");
        printf("1 – Afficher\n");
        printf("2 – Ajouter un élément à la fin de la liste\n");
        printf("3 – Quitter le programme\n");
        printf("Opération ? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList(&list);
                break;
            case 2: {
                int element;
                printf("Entrez l'élément à ajouter : ");
                scanf("%d", &element);
                appendToList(&list, element);
                break;
            }
            case 3:
                printf("Programme terminé.\n");
                break;
            default:
                printf("Opération non reconnue.\n");
        }

    } while (choice != 3);

    freeList(&list);

    return 0;
}