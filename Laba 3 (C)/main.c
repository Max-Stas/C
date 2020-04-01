//
//  main.c
//  Laba 3 (C)
//
//  Created by Максим Стасевич on 3/31/20.
//  Copyright © 2020 Максим Стасевич. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int CreateArray(short unsigned ****cube, short unsigned N);
void InitilizeCube(short unsigned ****cube, short unsigned N);
void DisplayCube(short unsigned ****cube, short unsigned N);
int CheckOne(short unsigned ****cube, short unsigned N);
void OpaqueCube(short unsigned ****cube, short unsigned N);
void FreeArray(short unsigned ****cube, short unsigned N);
 
int main(void)
{
    short unsigned ***cube, N;
 
    printf("Enter the cube size: ");
    while(!scanf("%hu", &N)) {
        printf("Invalid input. Try again.\nN = ");
        getchar();
    }
 
    if(CreateArray(&cube, N))
        return 0;
 
    InitilizeCube(&cube, N);
 
    printf("Cube of transparent and opaque elementary cubes:\n");
    DisplayCube(&cube, N);
 
    printf("Cube of opaque elementary cubes:\n");
    OpaqueCube(&cube, N - 1);
 
    FreeArray(&cube, N);
    return 0;
}
 
int CreateArray(short unsigned ****cube, short unsigned N)
{
    if(!(*cube = (short unsigned ***)malloc(N * (sizeof(short unsigned **))))) {
        printf("Problem with memory allocation.");
        return 1;
        }
 
    for(int i = 0; i < N; i++) {
        (*cube)[i] = (short unsigned **) malloc(N * sizeof(short unsigned *));
 
        for(int j = 0; j < N; j++)
            (*cube)[i][j] = (short unsigned *) malloc(N * sizeof(short unsigned));
    }
    return 0;
}
 
void InitilizeCube(short unsigned ****cube, short unsigned N)
{
    for(int i  = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                (*cube)[i][j][k] = 0;
 
    int count = 0, n = N - 1;
    n *= n * n;
    srand((unsigned int)(time(NULL)));
 
    while(count != n) {
 
        int i = rand() % N;
        int j = rand() % N;
        int k = rand() % N;
        (*cube)[i][j][k] = 1;
        count = CheckOne(cube, N);
    }
}
 
void DisplayCube(short unsigned ****cube, short unsigned N)
{
    for(int i  = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++)
                printf("%4d", (*cube)[i][j][k]);
 
            printf("\n");
        }
        printf("\n");
    }
}
 
void OpaqueCube(short unsigned ****cube, short unsigned N)
{
    for(int i  = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                (*cube)[i][j][k] = 1;
                printf("%4d", (*cube)[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
 
int CheckOne(short unsigned ****cube, short unsigned N)
{
    int count = 0;
 
    for(int i  = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                if ((*cube)[i][j][k] == 1)
                    count++;
    return count;
}
 
void FreeArray(short unsigned ****cube, short unsigned N)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j ++)
            free((*cube)[i][j]);
 
    for(int k = 0; k < N; k++)
        free((*cube)[k]);
 
    free((*cube));
}
