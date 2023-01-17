#include <stdio.h>
#include <stdlib.h>
//#include <readline/readline.h>

#define DELIM " \t"
#define HELLO ">_"

char *work(const char *);

int main()
{
	int N;
	//char *input = readline(HELLO); нeработает на винде поэтому испльзую VAL массив снизу
	char mass[] = "This is a test string.";
	printf("Enter number N=");
	scanf("%d", &N); // число знвков котоиые нужно удалить 
	char *output = work(mass); // не хочу затирать мсходный массив создаю новый
	N--;					   // выше быд первый проход
	while (N != 0)
	{
		output = work(output);
		N--;
	}

	printf("Modifaed string:%s", output);
	free(mass);
	free(output);
	return 0;
}

char *work(const char *line)
{
	char *trash = strdup(line);
	int s_len = strlen(trash);
	char *res = calloc(s_len + 1, sizeof(char));
	int len = 0;
	char *world = strtok(trash, DELIM);
	while (world != NULL)
	{
		int w_len = strlen(world) - 1;
		if (w_len > 0)
		{
			memcpy(res + len, world + 1, w_len * sizeof(char));
			len += w_len;
			res[len] = ' ';
			++len;
		}
		world = strtok(NULL, DELIM);
	}
	free(trash);
	if (len > 0)
	{
		--len;
	}
	res[len] = '\0';
	res = realloc(res, (len + 1) * sizeof(char));
	return res;
}
