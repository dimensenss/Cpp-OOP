#include <stdio.h>
#include <math.h>
#include <iostream>


int main(void) {
    setlocale(LC_ALL, "RUS");

    int n;        
    double x, y;    
    short h;        
       
    for (n = 0; n < 5; n++) {
        
        printf("|   x   |      y     |\n");
        printf("|-------|------------|\n");
       
        for (x = 0; x < 4; x += 0.25) {
           
            if (x < 2)
            y = sqrt(4 - (x - 2) * (x - 2));
            
            else  
            y = -x + 4;
          
            printf("| %5.2lf | %10.7lf |", x + n * 4, y);
            
            h = y * 10 + 0.8;
            
            if (y * 10  - h  > 0.5) h++;
            
            for (; h > 0; h--) printf(" ");

            printf("*\n");
        }  
      
        printf("Нажмите клавишу Enter...");
        getchar();
    }  
    return 0;
} 