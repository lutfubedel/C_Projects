#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "create_stack.h"
#include "push_stack.h"
#include "pop_stack.h"



bool balanced(Stack* myStack,char text[]);

int main()
{

    char text[1000];
    Stack *myStack = createStack();

    // Kullanicidan parantezler alinir.
    printf("Parantezleri giriniz : ");
    scanf("%s",text);

    if(balanced(myStack,text) == 1)
    {
        printf("Eslesme basarili \n");
    }
    else
    {
        printf("Eslesme basarisiz \n");
    }

    return 0;
}


// Parantezlerin dengeli olup olmadigini kontrol eden fonksiyon
bool balanced(Stack* myStack, char text[])
{
    // Her bir parantezi kontrol eden dongu
    for (int i = 0; i < strlen(text); i++)
    {
        // Kapali parantez kontrolu
        if (text[i] == ')')
        {
            // Stack bos ise dengeli degildir.
            if (myStack->counter == 0)
            {
                return false;
            }
            else
            {
                // Stack'de acik parantez bulursa acik parantezi stack'den cikarir.
                if (myStack->top->data == '(')
                    popStack(myStack);
                else
                    return false;
            }
        }
        // Kapali suslu parantez kontrolu
        else if (text[i] == '}')
        {
            // Stack bos ise dengeli degil
            if (myStack->counter == 0)
            {
                return false;
            }
            else
            {
                //Stack'de acik suslu parantez bulursa acik suslu parantezi stack'den cikarir.
                if (myStack->top->data == '{')
                    popStack(myStack);
                else
                    return false;
            }
        }
        // Acik parantez veya suslu parantez ise stack'e ekleme
        else if ((text[i] == '(') || (text[i] == '{'))
        {
            pushStack(myStack, text[i]);
        }

        else
        {
            // Diger karakterler icin herhangi bir islem yapma
        }
    }

    // Stack bos ise parantezler dengeli
    if (myStack->counter == 0)
    {
        return true;
    }
    // Stack bos degilse parantezler dengeli degildir.
    else
    {
        return false;
    }
}



