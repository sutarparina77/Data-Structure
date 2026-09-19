/// Static Implementation of Stack - Using Array
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

static int Top = 0;
static int Size = 0;

BOOL Create_Stack(int**, int);

int Is_Stack_Empty(int*);
int Is_Stack_Full(int*);
void Push_Amnt(int*, int);
void Pop_Amnt(int*);
void Display_Stack(int*);
int Count_Stack_Amnt();
void Search_Amnt(int*, int);
void Total_Amnt(int*);
void Even_Amnt(int*);
void Odd_Amnt(int*);
void Max_Amnt(int*);
void Min_Amnt(int*);
void Even_Amnt_Cnt(int*);
void Odd_Amnt_Cnt(int*);
void Delete_Stack(int**);

BOOL Create_Stack(int **Stack_Ptr, int Amnt_Cnt)
{
    *Stack_Ptr = (int*) malloc (Amnt_Cnt *sizeof(int));

    Top = 0;
    Size = Amnt_Cnt;

    if(NULL == *Stack_Ptr)
    {
        return FALSE;
    }

    return TRUE;
}

int Is_Stack_Empty(int *Stack)
{
    if(Top == 0)
    {
        return 1;
    }
    return 0;
}

int Is_Stack_Full(int *Stack)
{
    if(Top == Size)
    {
        return 1;
    }
    return 0;
}

void Push_Amnt(int *Stack, int Price)
{
    if(Is_Stack_Full(Stack))
    {
        printf("\n Stack is already full, Cant insert new Amount.");
    }
    else
    {
        Stack[Top] = Price;
        Top++;

        printf("\n Amount %d is Inserted at %d Index Successfully...",Price, Top-1);
    }

    return;
}

void Pop_Amnt(int *Stack)
{
    if(Is_Stack_Empty(Stack))
    {
        printf("\n Stack is already Empty, Cant remove any Amount.");
    }
    else
    {
        Top--;
        printf("\n Removed Amount is : %d",Stack[Top]);
        Stack[Top] = 0;
    }

    return;
}

void Display_Stack(int *Stack)
{
    int i = 0;

    if(Is_Stack_Empty(Stack))
    {
        printf("\n Stack is already Empty, No Bills to Display.");
    }
    else
    {
        printf("\n\n Bills in Given Stack are => \n");

        for(i = Top-1; i >= 0; i--)
        {
            printf("\n\t | %3d | \n",Stack[i]);
        }
    }

    return;
}

int Count_Stack_Amnt()
{
    return Top;
}

void Search_Amnt(int *Stack, int Num)
{
    int i = 0;

    if(Is_Stack_Empty(Stack))
    {
        printf("\n Stack is already Empty, Searching is Illogical");
    }
    else
    {
        for(i = 0; i < Top; i++)
        {
            if(Stack[i] == Num)
            {
                printf("\n Amount %d Found 1st Time at index %d in Given Stack(Bottom To Top).", Num, i+1);
                break;
            }
        }
    }

    if(i == Top)
    {
        printf("\n %d Amount Not Present in Array.", Num);
    }

    return;
}

void Total_Amnt(int *Stack)
{
    int i = 0, Total = 0;

    for(i = 0; i < Top; i++)
    {
        Total = Total + Stack[i];
    }
    printf("\n Total Amount in stack are : %d", Total);

    return;
}

void Even_Amnt(int *Stack)
{
    int i = 0;

    printf("\n Even Amounts in stack are :");

    for(i = 0; i < Top; i++)
    {
        if(Stack[i] % 2 == 0)
        {
            printf("%d", Stack[i]);
        }
    }

    return;
}

void Odd_Amnt(int *Stack)
{
    int i = 0;

    printf("\n Odd Amounts in stack are :");

    for(i = 0; i < Top; i++)
    {
        if(Stack[i] % 2 == 1)
        {
            printf("%d", Stack[i]);
        }
    }

    return;
}

void Max_Amnt(int *Stack)
{
    int i = 0, Max = 0;

    Max = Stack[0];

    for(i = 1; i < Top; i++)
    {
        if(Stack[i] > Max)
        {
            Max = Stack[i];
        }
    }

    printf("\n Highest Amount From stack is : %d", Max);

    return;
}

void Min_Amnt(int *Stack)
{
    int i = 0, Min = 0;

    Min = Stack[0];

    for(i = 1; i < Top; i++)
    {
        if(Stack[i] < Min)
        {
            Min = Stack[i];
        }
    }

    printf("\n Lowest Amount From stack is : %d", Min);

    return;
}

void Even_Amnt_Cnt(int *Stack)
{
    int i = 0, ECnt = 0;

    for(i = 0; i < Top; i++)
    {
        if(Stack[i] % 2 == 0)
        {
            ECnt++;
        }
    }

    printf("\n Total Even Amounts in Stack are : %d", ECnt);

    return;
}

void Odd_Amnt_Cnt(int *Stack)
{
    int i = 0, OCnt = 0;

    for(i = 0; i < Top; i++)
    {
        if(Stack[i] % 2 == 1)
        {
            OCnt++;
        }
    }

    printf("\n Total Odd Amounts in Stack are : %d", OCnt);

    return;
}

void Delete_Stack(int **Stack)
{
    Top = 0;
    Size = 0;
    free(*Stack);

    return;
}
