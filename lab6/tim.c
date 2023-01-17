#include <stdio.h>
#include <stdlib.h>

// ��������� ��� ��������
// ������� � ������ � ��������� � next item
typedef struct Item{
  char ch;
  struct Item* next;
}Item;

// ��������� ������
typedef struct List{
  // ������ ������
  int size;
  // ������ ������
  Item* head;
  // ����� ������
  Item* tail;
}List;

// ��������������� �����
// �������� ������ � N
void transform(List* list, int N){
  // ����� ������ ������� ������
  Item* it = list->head;
  // ��� �������� ������ � N
  int i = 0;

  // ��������� ������
  putchar('"');
  // ���� �� ����� � ����� ������ ���������
  while(it != NULL){
    // �������� ���� ����� ����������� ����
    if(it->ch == ' ' || it->ch == '\t')
      // �������� � -1
      i = -1;
    // ���� ��������� N ������ ������ ������� ���������
    if(i == N){
      putchar(' ');
      // ���������� � 0
      i = 0;
    }
    ++i; // ��������� ��������
    // ����� �������
    putchar(it->ch);
    // ����� ��������� �� ������ �������
    it = it->next;
  }
  // ������� �������
  putchar('"');
}
// ����� ������ ������� �� ������
void print(List* list){
  // ����� ������ �������
  Item* it = list->head;
  // �������
  putchar('"');
  // ���� �� ����� �� ���������� ���������
  while(it != NULL){
    // ����� �������
    putchar(it->ch);
    // ����� ��. ������� ������
    it = it->next;
  }
  putchar('"');
}
// ���������� � ����o� �������
void insert(List* list, char ch){
  // �������� ��� ������ ������� ������
  Item* it = (Item*)malloc(sizeof(Item));
  // ���������� ������
  it->ch = ch;
  // ���� ������ ����
  if(list->size == 0){
    // ������ � ����� ���� � ����
    list->head = it;
    list->tail = it;
    // ��������� ������ � �������
    list->head->next = list->tail;
  }
  else
  {  // ����� ��������� � �����
    list->tail->next = it;
    // ������ ������������ �������
    list->tail = list->tail->next;
  }
  // �������� ����� ������
  list->size++;
}

// �������� ������
void deleted(List* list){
  Item* it;
  // ���� ������ �� NULL - ��������� ������� ������
  while(list->head != NULL){
    // ����� ������ ������
    it = list->head;
    // ������������� ������ �� �� ������� ������
    list->head = list->head->next;
    // ��������� �������
    list->size--;
    // ���������� ������ ��������
    free(it);
  }
  // ���������� ��� ������
  free(list);
}

// �������� ������� ������
List* create(){
  // �������� ������ ��� ������
  List* list = (List*)malloc(sizeof(List));
  // �������� � 0 � NULL ������
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  return list;
}


// ���� ������
List* input(){
  // ������� ������ ��� ������
  List* list = create();
  char ch = NULL;
  //
  while(1){
    // ����� ������
    ch = getchar();
    // ���� Enter ��������� ���� �����
    if( ch == '\n' ) break;
    // ����� �������� � ������ �������
    insert(list, ch);
  }
  return list;
}


int main(int argc, char **argv)
{
  int N;  // ����� ��������
  printf("input N: ");
  scanf("%d", &N);  // ���� �����
  // �� ������ �������� ���� �� Enter
  while(getchar() != '\n') continue;

  // ���� ������
  printf("input string:\n");
  // ���� ������
  List* list = input();

  printf("source string:\n");
  // ����� ������������ ������
  //print(list);

  printf("\nresult string:\n");
  // ����� ��������������� ������
  transform(list, N);
  // ������� ������ �� ������
  deleted(list);
  // ������� ������� �������
  putchar('\n');
  return 0;
}
