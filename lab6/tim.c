#include <stdio.h>
#include <stdlib.h>

// структура под хранение
// записей в списке с переходом к next item
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

// преобразованный вывод
// передаем список и N
void transform(List* list, int N){
  // берем первый элемент списка
  Item* it = list->head;
  // под итерации сверки с N
  int i = 0;

  // выставить скобку
  putchar('"');
  // пока не дошли в конец списка выполн€ть
  while(it != NULL){
    // проверка если стоит разделитель слов
    if(it->ch == ' ' || it->ch == '\t')
      // итераци€ в -1
      i = -1;
    // если равенство N ставим пробел раздел€ подстроки
    if(i == N){
      putchar(' ');
      // сбрасываем в 0
      i = 0;
    }
    ++i; // увеличить итерацию
    // вывод символа
    putchar(it->ch);
    // вз€ть следующий из списка элемент
    it = it->next;
  }
  // закрыть кавычки
  putchar('"');
}
// вывод строки обычной из списка
void print(List* list){
  // берем первый элемент
  Item* it = list->head;
  // кавычки
  putchar('"');
  // пока не дошли до последнего эелемента
  while(it != NULL){
    // вывод символа
    putchar(it->ch);
    // вз€ть сл. элемент списка
    it = it->next;
  }
  putchar('"');
}
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

// удаление списка
void deleted(List* list){
  Item* it;
  // пока голова не NULL - последний элемент списка
  while(list->head != NULL){
    // берем начало спсика
    it = list->head;
    // переназначаем голову на сл элемент списка
    list->head = list->head->next;
    // декремент размера
    list->size--;
    // освободить пам€ть элемента
    free(it);
  }
  // освободить сам список
  free(list);
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
  char ch = NULL;
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


int main(int argc, char **argv)
{
  int N;  // длина подстрок
  printf("input N: ");
  scanf("%d", &N);  // ввод длины
  // из буфера выбирать пока не Enter
  while(getchar() != '\n') continue;

  // ввод строки
  printf("input string:\n");
  // ввод строки
  List* list = input();

  printf("source string:\n");
  // вывод оригинальной строки
  //print(list);

  printf("\nresult string:\n");
  // вывод преобразованной строки
  transform(list, N);
  // удалить список из пам€ти
  deleted(list);
  // ожидать нажатие клавиши
  putchar('\n');
  return 0;
}
