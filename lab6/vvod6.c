#include <stdio.h>
#include <string.h>

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
  char *ch = NULL;
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

void transform(List* list, char* suffix) {
    printf("suffix:%s \t", suffix);
    // ����� ������ ������� ������
    Item* it = list->head;
    // ��� �������� ������
    int fin=0, i = 0, end =0;
    putchar('"');
    while(it != NULL && end !=1){
            if(it == NULL){
                printf("3");
            }
        if(it->ch == NULL){
                end=1;
            }
        if(i==1 && (it->ch == ' ' || it->ch == '\t' || end==1)){
            printf("1");
            printf("%s", suffix);
            putchar(' ');
            i=0;
        }
        if (it->ch == 'a' || it->ch == 'e' || it->ch == 'i' || it->ch == 'o' || it->ch == 'u' ||
            it->ch == 'A' || it->ch == 'E' || it->ch == 'I' || it->ch == 'O' || it->ch == 'U') {
                printf("2");
                i=1;
                }
            putchar(it->ch);
            // ����� ��������� �� ������ �������
            it = it->next;
            }

}

int main(int argc, char **argv)
{
    char suffix[10];
    printf("Enter a suffix: ");
    scanf("%s", suffix);
  // �� ������ �������� ���� �� Enter
    while(getchar() != '\n') continue;

  // ���� ������
    printf("Enter a string::\n");
  // ���� ������
    List* list = input();

    printf("source string:\n");
  // ����� ������������ ������
  //print(list);

    printf("\nresult string:\n");
  // ����� ��������������� ������
    transform(list, suffix);
  // ������� ������ �� ������

  // ������� ������� �������
    putchar('\n');

    return 0;
}
