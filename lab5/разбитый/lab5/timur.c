#define NOLOGGING

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <malloc.h>

#define INPUT_FAILURE 1
#define SUCCESS 0
#define bool int
#define true 1
#define false 0
#define ERROR_FILE 2

#ifndef NOLOGGING
#define LOG(msg)
#else
#define LOG(msg) std::cout << "[LOG] (" FILE ":" << LINE ") from " << func  << "()\n     " << msg << "\n";
#endif // NOLOGGING

typedef struct
{
    char *name;             //фамилия, имя, отчество
    char *electoral;        //избирательный участок
    int age;                //возраст
    struct person* next;
} person;

person* create_person(char* _name, char* _electoral, int age)
{
    person* new_person = malloc(sizeof(person));
    if (NULL != new_person)
    {
        new_person->name = _name;
        new_person->electoral = _electoral;
        new_person->age = age;
    }
}

int compare_age(const void *a, const void *b)
{
    person *p1 = (person *)a;
    person *p2 = (person *)b;

    return p1->age - p2->age;
}

void delete_person(person* old_person)
{
    if (NULL != old_person->next)
        delete_person(old_person->next);
    return old_person;
}

person* add_person(person* person_list, char* _name, char* _electoral, int _age)
{
    person* new_person = create_person(_name, _electoral, _age);
    if (NULL != new_person)
        new_person->next = person_list;
    return new_person;
}

int main(int argc, char *argv[])
{
    printf("%s\n", "Hello, world!");


    int opt, a = 0, f = 0, r = 0;
    char *i = "";
    char *o = "";
    //a - алгоритм сортировки (1 - пузырьковая сортировка, 2 - сортировка Шелла, 3 - быстрая сортировка)
    //f - поле, по которому осуществляется сортировка (1 - ФИО, 2 - номер избирательного участка, 3 - возраст)
    //r - направление сортировки (1 - по возрастанию, 2 - по убыванию)
    //i - имя входного файла
    //o - имя выходного файла
    while ((opt = getopt(argc, argv, "a:f:r:i:o:")) != -1)
    {
        switch (opt) {
        case 'a':
            a = atoi(optarg);
            break;
        case 'f':
            f = atoi(optarg);
            break;
        case 'r':
            r = atoi(optarg);
            break;
        case 'i':
            i = optarg;
            break;
        case 'o':
            o = optarg;
            break;
        }
    }

    //убедимся,что заданы все аргументы и все они заданы верно
    bool b = true;
    b &= (a >= 1) && (a <= 3);
    b &= (f >= 1) && (f <= 3);
    b &= (r >= 1) && (r <= 2);
    b &= strlen(i) >= 0;
    b &= strlen(o) >= 0;

    //если при вводе были допущены ошибки выйдем с соответствующим сообщением
    /*if (!b)
        exit(INPUT_FAILURE);*/

    //откроем файл для чтения
    //printf("file=%s\n", i);
    i = "in1.txt";
    FILE * ptrFILE = fopen(i, "r");

    person* persons;
    int N = 0;
    if (ptrFILE != NULL)
    {
        fscanf(ptrFILE, "%d", &N);
        if (N < 1)
            exit(ERROR_FILE);

        persons = (person*)malloc(sizeof(person) * N);

        for (int n = 0; n < N; n++)
        {
            char _name[100], _number[15];
            int _age;
            fscanf(ptrFILE, "%s", _name);
            fscanf(ptrFILE, "%s", _number);
            fscanf(ptrFILE, "%d", &_age);

            if (n == 0)
                persons = create_person(_name, _number, _age);
            else
                persons = add_person(persons, _name, _number, _age);
            persons[n].name = _name;

            printf("%d\n", n);
            //printf("name=%s\n", _name);
        }
    }
    else
    {
        printf("filename=%s\n", i);
        perror("error");
        exit(ERROR_FILE);
    }
    fclose(ptrFILE);

    qsort(persons, N, sizeof(person), compare_age);

    ptrFILE = fopen(i, "w");
    if (ptrFILE != NULL)
    {
        for (int n = 0; n < N; n++)
        {
            fprintf(ptrFILE, "%s", persons[n].name);
            fprintf(ptrFILE, "%s", persons[n].electoral);
            fprintf(ptrFILE, "%d", persons[n].age);
        }
    }
    else
        exit(ERROR_FILE);



    free(persons);
    persons = NULL;
    exit(SUCCESS);
}
