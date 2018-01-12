#include <stdio.h>

int main(void) {
	float speed;
	
	printf("Enter a wind speed (knots): ");
	scanf("%f", &speed);
	
	if (speed < 1.0f) {
		printf("Description: Calm\n");
	} else if (speed >= 1.0f && speed <= 3.0f) {
		printf("Description: Light air\n");
	} else if (speed >= 4.0f && speed <= 27.0f) {
		printf("Description: Breeze\n");
	} else if (speed >= 28.0f && speed <= 47.0f) {
		printf("Description: Gale\n");
	} else if (speed >= 48.0f && speed <= 63.0f) {
		printf("Description: Storm\n");
	} else {
		printf("Description: Hurricane\n");
	}
	
	return 0;
}