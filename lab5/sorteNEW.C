#include <stdio.h>
#include <string.h>

#define MAX_MAKE_LEN 16

typedef struct
{
	char make[MAX_MAKE_LEN + 1];
	char *owner;
	double mileage;
} Car;

void shaker_sort(Car cars[], int n)
{
	int i, j;
	int swapped;
	Car temp;

	for (i = 0; i < n - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (cars[j].mileage > cars[j + 1].mileage)
			{
				temp = cars[j];
				cars[j] = cars[j + 1];
				cars[j + 1] = temp;
				swapped = 1;
			}
		}
		if (!swapped)
		{
			break;
		}
		swapped = 0;
		for (j = n - 2 - i; j > i; j--)
		{
			if (cars[j].mileage < cars[j - 1].mileage)
			{
				temp = cars[j];
				cars[j] = cars[j - 1];
				cars[j - 1] = temp;
				swapped = 1;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}

void insertion_sort_binary(Car cars[], int n)
{
	int i, j, left, right, mid;
	Car key_car;
	double key_mileage;

	for (i = 1; i < n; i++)
	{
		key_car = cars[i];
		key_mileage = cars[i].mileage;

		// binary search to find the correct position for key_car
		left = 0;
		right = i - 1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (cars[mid].mileage < key_mileage)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}

		// move all cars one position to the right to make space for key_car
		for (j = i - 1; j > right; j--)
		{
			cars[j + 1] = cars[j];
		}
		cars[right + 1] = key_car;
	}
}