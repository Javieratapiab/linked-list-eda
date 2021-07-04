#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "input.txt"

/**
 * Crea la estructura de un nodo.
 */
struct Node {
  int data;
  struct Node * next;
};
typedef struct Node Node;

/**
 * Create la estructura de una lista enlazada
 */
struct List {
  struct Node * head;
  struct Node * tail;
};
typedef struct List List;

/**
 * Crea una lista enlazada vacía
 */
List * create_list() {
  List * list = (List * ) malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

/**
 * Función que inserta un nuevo nodo en una lista enlazada
 * @param[in] list Lista enlazada
 * @param[in] data Data que será agregada al nuevo nodo
 */
void insert(List * list, int data) {
  if (list->head == NULL) {
    list->head = (Node * ) malloc(sizeof(Node));
    list->head->next = NULL;
    list->head->data = data;
  } else if (list->tail == NULL) {
    Node * node = (Node * ) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    list->tail = node;
    list->head->next = node;
  } else {
    Node * node = (Node * ) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    list->tail->next = node;
    list->tail = node;
  }
}

/**
 * Función que elimina el primer nodo de una lista enlazada
 * @param[in] list Lista enlazada
 */
void remove_first(List * list) {
  list->head = list->head->next;
}

/**
 * Función que imprime una lista enlazada
 * @param[in] list Lista enlazada
 */
void print_list(List * list) {
  Node * aux = list->head;

  while (aux != NULL) {
    printf("%d\n", aux->data);
    aux = aux->next;
  }
}

/**
 * Función que lee archivo input.txt ubicado en la raíz de este proyecto 
 * @param[in] queue_one Lista enlazada que representa la primera fila en el cine
 * @param[in] queue_two Lista enlazada que representa la segunda fila en el cine
 */
void read_file(List * queue_one, List * queue_two) {
  FILE * fp;
  size_t line_buf_size = 0;
  ssize_t line_size;
  char * line_buf = NULL;
  char delim[] = " ";
  int char_count = 0;
  int line_count = 0;

  fp = fopen(FILENAME, "r");

  if (fp == NULL)
    exit(EXIT_FAILURE);

  line_size = getline( & line_buf, & line_buf_size, fp);

  while (line_size >= 0) {
    line_count++;
    char * ptr = strtok(line_buf, delim);
    char_count = 0;

    while (ptr != NULL) {
      char_count++;
      if (char_count == 1) {
        insert(queue_one, atoi(ptr));
      } else {
        insert(queue_two, atoi(ptr));
      }
      ptr = strtok(NULL, delim);
    }
    line_size = getline( & line_buf, & line_buf_size, fp);
  }

  fclose(fp);

  if (line_buf) {
    free(line_buf);
  }
}

/**
 * Función que crea archivo output.txt ubicado en la raíz de este proyecto 
 * @param[in] queue_one Lista enlazada que representa la primera fila en el cine
 * @param[in] queue_two Lista enlazada que representa la segunda fila en el cine
 * @param[out] queue_three Lista enlazada que representa a las personas
 * que lograron entrar al cine.
 */
void generate_file(List* queue_one, List* queue_two, List* queue_three) {
  FILE * fp;
  Node * aux;

  fp = fopen("output.txt", "w");

  if (fp == NULL)
    exit(EXIT_FAILURE);
  
  fputs("Fila 1\n", fp);
  aux = queue_one->head;
  
  while (aux != NULL) {
    fprintf(fp, "%d\n", aux->data);
    aux = aux->next;
  }

  fputs("\nFila 2\n", fp);
  aux = queue_two->head;
  
  while (aux != NULL) {
    fprintf(fp, "%d\n", aux->data);
    aux = aux->next;
  }

  fputs("\nPersonas con entradas\n", fp);
  aux = queue_three->head;
  
  while (aux != NULL) {
    fprintf(fp, "%d\n", aux->data);
    aux = aux->next;
  }

  fclose(fp);
}

/**
 * Función que aplica lógica de selección de personas dentro de las filas 
 * a partir del número de entradas disponibles. Retorna una nueva 
 * lista enlazada con aquellas personas que lograron entrar al cine y 
 * actualizará aquellas listas que representan a las filas con aquellas 
 * personas que no lograron entrar.
 * @param[in] tickets Cantidad de entradas de cine disponibles.
 * @param[in] queue_one Lista enlazada que representa la primera fila en el cine.
 * @param[in] queue_two Lista enlazada que representa la segunda fila en el cine.
 * @param[out] queue_three Nueva lista enlazada que representa a las personas 
 * que lograron entrar al cine.
 */
List * check_tickets(int tickets, List * queue_one, List * queue_two) {
  List * queue_three = create_list();

  while (tickets > 0) {
    // No quedan personas en las filas de espera
    if (queue_one->head == NULL && queue_two->head == NULL) break;

    // Quedan personas en ambas filas de espera
    if (queue_one->head != NULL && queue_two->head != NULL) {
      if (queue_one->head->data < queue_two->head->data) {
        insert(queue_three, queue_one->head->data);
        remove_first(queue_one);
      } else if (queue_one->head->data > queue_two->head->data) {
        insert(queue_three, queue_two->head->data);
        remove_first(queue_two);
      } else {
        insert(queue_three, queue_one->head->data);
        insert(queue_three, queue_two->head->data);
        remove_first(queue_one);
        remove_first(queue_two);
      }
    // Quedan personas sólo en la primera fila
    } else if (queue_two->head == NULL) {
      insert(queue_three, queue_one->head->data);
      remove_first(queue_one);
    // Quedan personas sólo en la segunda fila
    } else {
      insert(queue_three, queue_two->head->data);
      remove_first(queue_two);
    }

    tickets--;
  }

  return queue_three;
}

int main() {
  List * queue_one = create_list();
  List * queue_two = create_list();
  int tickets;

  // Pide número de entradas disponibles
  printf("Ingrese el número de entradas deseadas: ");
  scanf("%d", &tickets);

  // Lee archivo input.txt para generar ambas filas
  read_file(queue_one, queue_two);

  // Aplica lógica de entradas, genera tercera fila (personas con entrada)
  List * queue_three = check_tickets(tickets, queue_one, queue_two);
  
  // Genera archivo de salida output.txt
  generate_file(queue_one, queue_two, queue_three);
  printf("Los resultados se encuentran disponibles en el archivo output.txt\n");

  return 0;
}
