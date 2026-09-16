#include<stdio.h>
#include<conio.h>

#define Size 5

int Bills[Size];
int Top = 0;

void Push(int No);
void Pop();
int Is_Bills_Full();
int Is_Bills_Empty();
void Display_Bills();
int Bills_Cnt();

int main()
{
    Push(23);
    Push(45);
    Push(89);

    getche();
    Display_Bills();

    getche();
    printf("\n\n Number of bills in stack is = %d \n", Bills_Cnt());

    Pop();
    Pop();
    Pop();
    Pop();

    getche();

    printf("\n Number of bills in stack is = %d", Bills_Cnt());

    Display_Bills();

    getch();
    return 0;
}

void Push(int No)
{
    if(Is_Bills_Full())
    {
        printf("\n Bills stack is already full..Can't insert new bill!!");
    }
    else
    {
        Bills[Top] = No;
        Top++;

        printf("\n Bill %d is successfully inserted!!!", No);
    }

    return;
}

void Pop()
{
    if(Is_Bills_Empty())
    {
        printf("\n Bills stack is already empty..Can't delete any bill!!");
    }
    else
    {
        printf("\n Deleted Bill from stack is = %d", Bills[Top - 1]);
        Bills[Top - 1] = 0;
        Top--;
    }

    return;
}

int Is_Bills_Full()
{
    if(Top == Size)
    {
        return 1;
    }

    return 0;
}

int Is_Bills_Empty()
{
    if(Top == 0)
    {
        return 1;
    }
    return 0;
}

void Display_Bills()
{
    if(Is_Bills_Empty())
    {
        printf("\n Bills stack is already empty..Can't display any bill!!");
    }
    else
    {
        int i = 0;

        printf("\n Present Bills in Stack Are ==> \n");

        for(i = 0; i < Top; i++)
        {
            printf("\n\n\t |%d|", Bills[i]);
        }
    }
}

int Bills_Cnt()
{
    return Top;
}













