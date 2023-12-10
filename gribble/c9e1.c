#include <stdio.h>
#include <string.h>

int main(void) {
    char *provinces[] = { "British Columbia", "Alberta", "Saskatchewan", 
                        "Manitoba", "Ontario", "Quebec", "New Brunswick",
                        "Nova Scotia", "Prince Edward Island", "Newfoundland",
                        "Yukon", "Northwest Territories", "Nunavut" };
  
    for (int i = 0; i < 13; i++) {
        printf("provinces[%d] = %c", i, provinces[i][0]);
        int j = 1;
    
        while (provinces[i][j] != 0) {
            char tmpchar = provinces[i][j];
            
            if ((provinces[i][j] >= 'a') && (provinces[i][j] <= 'z')) {
	            tmpchar = provinces[i][j] - 32;
            }
      
            printf("%c", tmpchar);
            
            j++;
        }
        
        printf("\n");
    }
    
    return 0;
}