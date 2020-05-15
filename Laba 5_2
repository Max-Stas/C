//
//  main.c
//  2
//
//  Created by Максим Стасевич on 5/5/20.
//  Copyright © 2020 Максим Стасевич. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    char  data[90];
    int amount;
    Node* left, * right;
};

int Vowels(const char* word);
void Printout(Node* Tree);
Node * AddToTree(Node* Tree, char* word);

int main()
{
    Node* Tree = NULL;
    char buffer[80];
    FILE* myfile;
    fopen (&myfile, "read.txt", "r");
    if (myfile == NULL)
    {
        printf("файл не найден");
        return -1;
    }
    int i = 0;
    while (!feof(myfile))
    {
        buffer[i] = fgetc(myfile);
        if (buffer[i] == ' ')
        {
            Tree=AddToTree(Tree, buffer);
            i = 0; continue;
        }
        i++;
    }
    Printout(Tree);
}

int Vowels (const char * word)
{
    int k = 0;
    for (int i = 0; word[i]!= ' '; i++)
        if (word[i] == 'A' || word[i] == 'a' || word[i] == 'O' || word[i] == 'o' || word[i] == 'U' || word[i] == 'u' || word[i] == 'E'
            || word[i] == 'e'|| word[i] == 'I' || word[i] == 'i' || word[i] == 'Y' || word[i] == 'y')
            k++;
    return k;
}

Node * AddToTree(Node *Tree, char *word)
{
    if (Tree == NULL)
    {
        Tree = (Node*)malloc(sizeof(Node));
        if (Tree == NULL)
        {
            printf("ошибка");
            exit(1);
        }
        strncpy(Tree->data, word, 50);
        Tree->amount = Vowels(word);
        Tree->left = NULL;
        Tree->right = NULL;
        return Tree;
    }
    else if (Vowels(word) > Tree->amount)
        Tree->right = AddToTree(Tree->right, word);
    else if (Vowels(word)<Tree->amount)
        Tree->left=AddToTree(Tree->left, word);
    return Tree;
}

void Printout(Node* Tree)
{
    Node* tmp = Tree;
    if (tmp->left) Printout(tmp->left);
    if (tmp->amount > 2)
    {
        for (int i = 0; tmp->data[i] != ' '; i++)
            printf("%c", tmp->data[i]);
        printf("\n");
    }
    if (tmp->right) Printout(tmp->right);
}
