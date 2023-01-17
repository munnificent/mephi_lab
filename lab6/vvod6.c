#include <stdio.h>
#include <string.h>

typedef struct Item{
  char ch;
  struct Item* next;
}Item;

// структура списка
typedef struct List{
  // размер списка
  int size;
  // голова списка
  Item* head;
  // хвост списка
  Item* tail;
}List;

// добавление в списoк символа
void insert(List* list, char ch){
  // выдел€ем под символ элемент списка
  Item* it = (Item*)malloc(sizeof(Item));
  // выставл€ем символ
  it->ch = ch;
  // если список пуст
  if(list->size == 0){
    // голова и хвост одни и теже
    list->head = it;
    list->tail = it;
    // свз€ываем голову с хвостом
    list->head->next = list->tail;
  }
  else
  {  // иначе добавл€ем в хвост
    list->tail->next = it;
    // хвосту переназначем элемент
    list->tail = list->tail->next;
  }
  // увеличть длину списка
  list->size++;
}



// создание пустого списка
List* create(){
  // выделить пам€ть под список
  List* list = (List*)malloc(sizeof(List));
  // сбросить в 0 и NULL адреса
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  return list;
}


// ввод строки
List* input(){
  // создать список под строку
  List* list = create();
  char *ch = NULL;
  //
  while(1){
    // вз€ть символ
    ch = getchar();
    // если Enter закончить цикл ввода
    if( ch == '\n' ) break;
    // иначе добавить в список элемент
    insert(list, ch);
  }
  return list;
}

void transform(List* list, char* suffix) {
    printf("suffix:%s \t", suffix);
    // берем первый элемент списка
    Item* it = list->head;
    // под итерации сверки
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
            // вз€ть следующий из списка элемент
            it = it->next;
            }

}

int main(int argc, char **argv)
{
    char suffix[10];
    printf("Enter a suffix: ");
    scanf("%s", suffix);
  // из буфера выбирать пока не Enter
    while(getchar() != '\n') continue;

  // ввод строки
    printf("Enter a string::\n");
  // ввод строки
    List* list = input();

    printf("source string:\n");
  // вывод оригинальной строки
  //print(list);

    printf("\nresult string:\n");
  // вывод преобразованной строки
    transform(list, suffix);
  // удалить список из пам€ти

  // ожидать нажатие клавиши
    putchar('\n');

    return 0;
}
