//
//  main.c
//  2.1
//
//  Created by Максим Стасевич on 3/11/20.
//  Copyright © 2020 Максим Стасевич. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int graviy = 0, tsement = 0, beton = 0, number, country = 0, dostavkaTsement = 0, dostavkaGraviy = 0, dostavkaBeton = 0;
   
    while (1) {
        printf ("\tВыберите функцию: \n 1) Заказа цемента \n 2) Заказ гравия \n 3) Заказ бетона \n 4) Выбор страны доставки \n 5) Параметры заказа \n 6) Решение о принятии заказа \n 7) Информация \n 8) Выход \n");
        scanf ("%d", &number);
        if (number==1) {
            printf ("Сколько тонн цемента\n");
            scanf ("%d", &tsement);
           
        }
        else if (number==2) {
            printf ("Сколько тонн гравия\n");
            scanf ("%d", &graviy);
        }
        else if (number==3) {
            printf ("Сколько тонн бетон\n");
            scanf ("%d", &beton);
        }
        else if (number==4) {
            printf ("Страна доставки: 1 = bel, 2 = (rus or ukr), 3 = mol\n");
            scanf ("%d", &country);
        }
        else if (number==5) {
            printf ("\nСведения: \n1 тонна цемента = 230 $ (себ = 160  $)\n1 тонна гравия = 142 $ (себ = 96 $) \n1 тонна бетона = 260 $ (205 $) \nдоставка в bel = 200 $ \nдоставка в rus or ukr = 320 $ \nдоставка в mol 360 $ \n\nCтоимость заказанных материалов: \n");
            printf ("%s%d%s", "цемент = ", tsement * 230, " $\n");
            printf ("%s%d%s", "гравий = ", graviy * 142, " $\n");
            printf ("%s%d%s", "бетон = ", beton * 260, " $\n");
            printf ("\nКоличество вагонов: \n");
            float vag = tsement/50.0;
            int vagonTsement = tsement/50;
            if (vag - vagonTsement > 0) {
                vagonTsement = tsement/50 + 1;
            }
            printf ("%s%d%s", "с цементом = ", vagonTsement,"\n");
            
            vag = graviy/50.0;
            int vagonGraviy = graviy/50;
            if (vag - vagonGraviy > 0) {
                vagonGraviy = graviy/50 + 1;
            }
            printf ("%s%d%s", "с гравием = ", vagonGraviy,"\n");
            
            vag = beton/50.0;
            int vagonBeton = beton/50;
            if (vag - vagonBeton > 0) {
                vagonBeton = beton/50 + 1;
            }
            printf ("%s%d%s", "с бетоном = ", vagonBeton,"\n");
            
            if (country == 1) {
                dostavkaTsement = vagonTsement * 200;
                dostavkaGraviy = vagonGraviy * 200;
                dostavkaBeton = vagonBeton * 200;
                printf("%s%d%s", "\nСтоимость доставки по Беларуси: \nцемента ", dostavkaTsement, "$\n");
                printf("%s%d%s", "гравия ", dostavkaGraviy, "$\n");
                printf("%s%d%s", "бетона ", dostavkaBeton, "$\n");
            } else if (country == 2) {
                dostavkaTsement = vagonTsement * 320;
                dostavkaGraviy = vagonGraviy * 320;
                dostavkaBeton = vagonBeton * 320;
                printf("%s%d%s", "\nСтоимость доставки по Украине/России : \nцемента ", dostavkaTsement, "$\n");
                printf("%s%d%s", "гравия ", dostavkaGraviy, "$\n");
                printf("%s%d%s", "бетона ", dostavkaBeton, "$\n");
            } else if (country == 3) {
                dostavkaTsement = vagonTsement * 360;
                dostavkaGraviy = vagonGraviy * 360;
                dostavkaBeton = vagonBeton * 360;
                printf("%s%d%s", "\nСтоимость доставки по Молдове: \nцемента ", dostavkaTsement, "$\n");
                printf("%s%d%s", "гравия ", dostavkaGraviy, "$\n");
                printf("%s%d%s", "бетона ", dostavkaBeton, "$\n");
            } else {
                printf("\nДоствака в данную страну не осуществляется\n");
            }
        }
        else if (number == 6) {
            int pribyl = tsement*70 + graviy*46+ beton*55 - dostavkaBeton - dostavkaGraviy - dostavkaTsement;
            if (pribyl >= 25000) {
                printf("\tЗаказ принят!\n");
                int zena = tsement*230 + graviy*142+ beton*260 + dostavkaBeton + dostavkaGraviy + dostavkaTsement;
                printf("%s%d%s","Общая стоимость с учетом  доставки: ", zena,"$\n");
                printf("%s%d%s","Прибыль предприятия: ", pribyl,"$\n");
            }
        }
        else if (number == 7) {
            printf("\nВерсия 1.0\nАвтор: Стасевич Максим Александрович\n\n");
        }
        else {
            printf("Программа завершена\n");
            return 0;
        }
    }
    return 0;
}
