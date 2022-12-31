#include <stdio.h>
#include <stdlib.h>
#include "laber.h"

int main()
{
	int variant,menu;
	int fin = 1,capacity = 1;
	int *arr = (int *)malloc(capacity * sizeof(int));
	int *arr1 = (int *)malloc(capacity * sizeof(int));

	do
	{
		print_menu1();

		variant = get_variant(8);
		switch (variant)
		{
		case 1:
			add_arr(&capacity,&arr);
			break;

		case 2:
			add_num(capacity, &arr);
			break;

		case 3:
			del_num(&capacity, &arr);
			break;

		case 4:
		    print_menu2();
		    menu = get_variant(2);
		    switch(menu){
            case 1:
                print_arr(capacity, &arr);
                break;

            case 2:
                print_arr(fin, &arr1);
                break;
		    }
			break;

        case 5:
			make_test(&capacity, &fin, &arr, &arr1);
			break;

        case 8:
            restart(&capacity, &fin, &arr, &arr1);
            break;
		}

		if (variant != 6)
			system("pause");
	} while (variant != 6);
            free(arr);
            free(arr1);
	return 0;
}
