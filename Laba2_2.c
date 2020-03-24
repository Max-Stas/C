//
//  main.c
//  2.2
//
//  Created by Максим Стасевич on 3/11/20.
//  Copyright © 2020 Максим Стасевич. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int dec(double x, double e);
long long fact(long long n);

int main(int argc, const char * argv[]) {
     double x, e;
    int n;
    
    printf("Введите допустимую погрешность e: ");
    scanf("%lf", &e);
    /*fflush(stdin);*/
    printf("Введите x: ");
    scanf("%lf", &x);
    n = dec(x, e);
    printf("%s%d%s", "При n = ", n, " будет достигнута желаемая точность\n");
    
    return 0;
}

int dec (double x, double e) {
    double sum = x, n = 1;
   
    while (fabs(sin(x) - sum) >= e) {
        sum += pow(-1, n - 1) * (pow(x, 2*n - 1)/fact(2*n - 1));
        n++;
    }
    return n;
}

long long fact (long long n) {
    if (n <= 1) {
        return 1;
    } else return n*fact(n - 1);
}
