//
//  main.c
//  doubleInt
//
//  Created by peter on 06.11.17.
//  Copyright © 2017 peter. All rights reserved.
//

#include <stdio.h>
#include "mathParser.h"

double calcDoubleInt(char* strFunc, double a, double b, double c, double d, int xn, int yn) {
    
    double x, y, xh, yh;
    double i = 0;
    
    xh = (b - a) / (float)xn;
    yh = (d - c) / (float)yn;
    
    for(x = a + xh * 0.5; x < b; x += xh)
    {
        for(y = c + yh * 0.5; y < d; y += yh)
        {
            i += function_xy(strFunc, x, y);
            if(is_syntax_error())
                return 0.0/0.0;// NAN
        }
    }
    
    return i * xh * yh;
}

int main(int argc, const char * argv[]) {
    
    char strFunc[128] = "sin(x+y)";
    double a = 0, b = 1.57, c = 0, d = 0.785, i;
    int xn = 1000, yn = 1000;
    
    printf("Введите подинтегрированную функцию:\n");
    scanf("%127s", strFunc);
    
    printf("введите a:\n");
    scanf("%lf", &a);

    printf("введите b:\n");
    scanf("%lf", &b);
    
    printf("введите количество разбиений xn:\n");
    scanf("%i", &xn);
    if(xn < 2)
    {
        printf("количество разбиений должно быть больше 2!\n");
        return 0;
    }
    
    printf("введите c:\n");
    scanf("%lf", &c);
    
    printf("введите d:\n");
    scanf("%lf", &d);
    
    printf("введите количество разбиений yn:\n");
    scanf("%i", &yn);
    if(yn < 2)
    {
        printf("количество разбиений должно быть больше 2!\n");
        return 0;
    }
    
    
    i = calcDoubleInt(strFunc, a, b, c, d, xn, yn);
    
    if(i == i)
        printf("Двойной интеграл = %lf\n", i);
    else
        printf("Ошибка в выражении!\n");
    
    return 0;
}
