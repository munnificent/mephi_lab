#include <stdio.h>
#include <string.h>
struct Car
{
	char brand[17];
	char ownerName[100];
	double mileage;
};
Car inputCar()
{
	Car car;
	printf("Enter car brand (up to 16 characters, only letters, dashes and spaces): ");
	fgets(car.brand, 17, stdin);
	car.brand[strcspn(car.brand, "\n")] = 0;
	printf("Enter car owner's name: ");
	fgets(car.ownerName, 100, stdin);
	car.ownerName[strcspn(car.ownerName, "\n")] = 0;
	printf("Enter car mileage (in thousands of kilometers): ");
	scanf("%lf", &car.mileage);
	return car;
}
int main()
{
	Car myCar = inputCar();
	printf("Brand: %s\n", myCar.brand);
	printf("Owner: %s\n", myCar.ownerName);
	printf("Mileage: %.2f km\n", myCar.mileage);
	return 0;
}