#include <stdio.h>

int main(void) {
	int h, m;
	
	printf("Enter a 24-hour time: ");
	scanf("%d:%d",&h,&m);
	
	if (h >= 1 && h<=12) {
		printf("Equivalent 12-hour time: %d:%.2d AM\n", h, m);
	} else {
		switch(h) {
			case 13: printf("Equivalent 12-hour time: 1:%.2d PM\n", m); break;
			case 14: printf("Equivalent 12-hour time: 2:%.2d PM\n", m); break;
			case 15: printf("Equivalent 12-hour time: 3:%.2d PM\n", m); break;
			case 16: printf("Equivalent 12-hour time: 4:%.2d PM\n", m); break;
			case 17: printf("Equivalent 12-hour time: 5:%.2d PM\n", m); break;
			case 18: printf("Equivalent 12-hour time: 6:%.2d PM\n", m); break;
			case 19: printf("Equivalent 12-hour time: 7:%.2d PM\n", m); break;
			case 20: printf("Equivalent 12-hour time: 8:%.2d PM\n", m); break;
			case 21: printf("Equivalent 12-hour time: 9:%.2d PM\n", m); break;
			case 22: printf("Equivalent 12-hour time: 10:%.2d PM\n", m); break;
			case 23: printf("Equivalent 12-hour time: 11:%.2d PM\n", m); break;
			case 0: printf("Equivalent 12-hour time: 12:%.2d PM\n", m); break;	
		}
	}
	
	return 0;
}