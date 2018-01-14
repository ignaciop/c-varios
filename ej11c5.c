#include <stdio.h>

int main(void) {
	int number;
	printf("Enter a two-digit number: ");
	scanf("%d",&number);
	
	int d = number / 10;
	int u = number % 10;
		
	switch(d) {
		case 9: printf("Ninety"); break;
		case 8: printf("Eighty"); break;
		case 7: printf("Seventy"); break;
		case 6: printf("Sixty"); break;
		case 5: printf("Fifty"); break;
		case 4: printf("Forty"); break;
		case 3: printf("Thirty"); break;
		case 2: printf("Twenty"); break;
		case 1:
			if (u==9) {
				printf("Nineteen\n"); return 0;
			} else if (u==8) {
				printf("Eighteen\n"); return 0;
			} else if (u==7) {
				printf("Seventeen\n"); return 0;
			} else if (u==6) {
				printf("Sixteen\n"); return 0;
			} else if (u==5) {
				printf("Fifteen\n"); return 0;
			} else if (u==4) {
				printf("Fourteen\n"); return 0;
			} else if (u==3) {
				printf("Thirteen\n"); return 0;
			} else if (u==2) {
				printf("Twelve\n"); return 0;
			} else if (u==1) {
				printf("Eleven\n"); return 0;
			} else {
				printf("Ten\n"); return 0;
			}
		}		
		
	switch(u) {
		case 9: printf("-nine\n"); break;
		case 8: printf("-eight\n"); break;
		case 7: printf("-seven\n"); break;
		case 6: printf("-six\n"); break;
		case 5: printf("-five\n"); break;
		case 4: printf("-four\n"); break;
		case 3: printf("-three\n"); break;
		case 2: printf("-two\n"); break;
		case 1: printf("-one\n"); break;
		case 0: printf("\n"); break;
	}

    return 0;
}