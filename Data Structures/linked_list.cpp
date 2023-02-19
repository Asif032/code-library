#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node *head, *tail;

void InsertFirst(int data) {
  struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void InsertE(int data) {
  struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
  struct Node* temp1 = head;
  temp->data = data;
  temp->next = NULL;
  if(head == NULL) {
    head = temp;
    return;
  }
  while(temp1->next != NULL) {
    temp1 = temp1->next;
  }
  temp1->next = temp;
}

void InsertMid(int data, int pos) {
  struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
  struct Node* temp1 = head;
  temp->data = data;
  if(pos == 1) {
    temp->next = head;
    head = temp;
    return;
  }
  for(int i = 0; i < pos - 2; i++) {
    temp1 = temp1->next;
  }
  temp->next = temp1->next;
  temp1->next = temp;
}

void InsertLast(int data) {
  struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL) {
      head = tail = temp;
      return;
    }
    tail->next = temp;
    tail = temp;
}

void del(int pos) {
  struct Node *temp = head, *temp1;
    for(int i = 0; i < pos - 2; i++) {
      temp = temp->next;
    }
    temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
}

void print() {
  struct Node* temp = head;
  printf("The list is : ");
  while(temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  head = tail = NULL;
  InsertLast(1);
  InsertLast(2);
  InsertLast(3);
  print();
  return 0;
}