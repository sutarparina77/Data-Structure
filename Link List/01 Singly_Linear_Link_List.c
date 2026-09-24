#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    struct Node *Next;
};

void Insert_First(struct Node **First, int No)
{
    struct Node *NewN = NULL;                                   /// Creating Pointer for New Node

    NewN = (struct Node*)malloc(sizeof(struct Node));           /// Allocation Dynamic Memory for New Node in Data Section (Heap) by malloc

    NewN ->Data = No;
    NewN ->Next = NULL;                                         /// Setting Values to New Node

    if(NULL == *First)                                          /// Only Ones means for inserting very 1st element in LL
    {
        *First  =  NewN;
        printf("\n\n Inside if block of insert first");
    }
    else                                                        /// Works for every next element i.e. from 2nd elements onwards
    {
        NewN -> Next = *First;
        *First = NewN;
        printf("\n\n Inside else block of insert first");
    }

    printf("\n %d Element Inserted Successfully !!!", No);

    return;
}

void  Display_LL(struct Node *First)
{
    if(NULL == First)
    {
        printf("\n Given Link List is Already Empty!!!");
    }
    else
    {
        printf("\n\n Elements in Given Link List are => \n\n\t");

        while(First != NULL)
        {
            printf("  | %d |  ->", First -> Data);
            First = First -> Next;
        }
        printf(" NULL ");
    }

    return;
}

void Insert_Last(struct Node **First, int No)
{
    struct Node *NewN = NULL;

    NewN = (struct Node*)malloc(sizeof(struct Node));

    NewN -> Data = No;
    NewN -> Next = NULL;

    if(NULL == *First)
    {
        *First = NewN;
        printf("\n Inside if block of insert Last");
    }
    else
    {
        struct Node *Temp = *First;

        while(Temp -> Next != NULL)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = NewN;
    }
    printf("\n %d Element Inserted at Last Position Successfully !!!", No);

    return;
}

int Count_LL_Nodes(struct Node *First)
{
    int Cnt = 0;

    while(First != NULL)
    {
        Cnt++;
        First = First -> Next;
    }

    return Cnt;
}

void Insert_At_Position(struct Node **First, int Pos, int No)
{
    int Ele_Cnt = Count_LL_Nodes(*First);

    struct Node *NewN = NULL, *Temp = NULL;

    if(Pos <= 0 || Pos > Ele_Cnt + 1)
    {
        printf("\n Invalid position enter valid position value");
    }
    else if(Pos == 1)
    {
        Insert_First(First, No);
    }
    else if(Pos == Ele_Cnt + 1)
    {
        Insert_Last(First, No);
    }
    else
    {
        struct Node *NewN = (struct Node*)malloc(sizeof(struct Node));

        NewN -> Data = No;
        NewN -> Next = NULL;

        struct Node *Temp = *First;
        while(Pos > 2)
        {
            Temp = Temp -> Next;
            Pos--;
        }
        NewN -> Next = Temp -> Next;
        Temp -> Next = NewN;
    }
     return;
}

void Delete_First(struct Node **First)
{
    if(NULL == *First)
    {
        printf("\n Link List is already Empty, Cant Delete Any Element !!!");
    }
    else
    {
        struct Node *Temp = *First;
        *First = Temp -> Next;

        printf("\n Deleted First Element in LL is = %d", Temp -> Data);

        free(Temp);
    }
    return;
}

void Delete_Last(struct Node **First)
{
    if(NULL == *First)
    {
        printf("\n Link List is already Empty, Cant Delete Any Element !!!");
    }
    else
    {
        struct Node *Temp = *First;
        if(Temp -> Next == NULL)
        {
            *First = NULL;
            printf("\n\n Deleted First Element in LL is = %d.", Temp->Data);

            free(Temp);
        }
        else
        {
            while(Temp -> Next -> Next != NULL)
            {
                Temp = Temp -> Next;
            }
            printf("\n\n Deleted Last Element in LL is = %d.", Temp->Next->Data);

            free(Temp -> Next);
            Temp -> Next = NULL;
        }
    }

    return;
}

void Delete_At_Position(struct Node **First, int Pos)
{
    int Ele_Cnt = Count_LL_Nodes(*First);

    if(Pos <= 0 || Pos > Ele_Cnt)
    {
        printf("\n\n Invalid position enter valid position value");
    }
    else if(Pos == 1)
    {
        Delete_First(First);
    }
    else if(Pos == Ele_Cnt)
    {
        Delete_Last(First);
    }
    else
    {
        struct Node *Temp1 = NULL, *Temp2 = NULL;

        Temp1 = *First;

        while(Pos > 2)
        {
            Temp1 = Temp1 -> Next;
            Pos--;
        }
        Temp2 = Temp1 -> Next;
        Temp1 -> Next = Temp2 -> Next;

        printf("\n Deleted given position element in link list is = %d", Temp2 -> Data);

        free(Temp2);
    }

    return;
}

void Free_All_Nodes(struct Node **First)
{
    struct Node *Temp = NULL;
    while(*First != NULL)
    {
        Temp = *First;
        *First = (*First) -> Next;
        free(Temp);
    }

    printf("\n\n All Nodes Deleted & Link list are Cleared.");
    return;
}

int main()
{
    int Num = 21;
    struct Node *Head = NULL;

    Display_LL(Head);
    getch();

    Delete_First(&Head);
    getch();

    Insert_First(&Head, 101);
    Insert_Last(&Head, 90);

    Insert_First(&Head, 95);
    Insert_Last(&Head, 65);

    Insert_First(&Head, Num);
    Insert_Last(&Head, 12);

    getch();

    ///system("cls");
    Display_LL(Head);

    getch();

    Count_LL_Nodes(Head);

    Insert_At_Position(&Head, 0, 46);
    Insert_At_Position(&Head, 1, 89);
    Insert_At_Position(&Head, 2, 34);
    Insert_At_Position(&Head, 5, 76);
    Insert_At_Position(&Head, 3, 49);

    Display_LL(Head);
    getch();

    Delete_First(&Head);

    Display_LL(Head);

    getch();
    Delete_Last(&Head);

    Display_LL(Head);

    getch();

    Delete_At_Position(&Head, 0);
    Delete_At_Position(&Head, 8);
    Delete_At_Position(&Head, 5);

    getch();

    Display_LL(Head);

    Free_All_Nodes(&Head);
    getch();

    Display_LL(Head);

    getch();
    return 0;
}
