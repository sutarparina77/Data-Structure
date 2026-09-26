#include"02 Singly_Linear_Link_List_Library.h"

int main()
{
    char Ch = '\0';
    int Choice = 0, Num = 0, Loc = 0;

    struct Node *Head = NULL;

    goto Start;

    while(1)
    {
        printf("\n ========================*****============================");
        printf("\n\n !!!**************Welcome to Link List App ***********!!! \n");
        printf("\n ========================*****============================");

        printf("\n Select Choice :");

        printf("\n\t\t 1. Insert Element at First Position in LL ");
        printf("\n\t\t 2. Insert Element at Last Position in LL ");
        printf("\n\t\t 3. Insert Element in between Position in LL ");
        printf("\n\t\t 4. Display all Inserted Element in LL ");
        printf("\n\t\t 5. Count of Inserted Element ");
        printf("\n\t\t 6. Delete First Element From LL ");
        printf("\n\t\t 7. Delete Last Element From LL ");
        printf("\n\t\t 8. Delete In between Element From LL ");
        printf("\n\t\t 9. Clear All Elements Node From Link List App ");
        printf("\n\t\t 10. Exit... ");

        printf("\n\n Enter Your Choice : ");
        scanf("%d",&Choice);

        switch(Choice)
        {
            case '1':
                    Start:

                    printf("\n Enter Value To Insert at First Position in Link List = ");
                    scanf("%d",&Num);

                    Insert_First(&Head, Num);
                    getch();

                    fflush(stdin);
                    system("cls");

                    break;

            case '2':
                    printf("\n Enter Value to Insert at Last Position in Link List = ");
                    scanf("%d",&Num);

                    Insert_Last(&Head, Num);
                    getch();

                    fflush(stdin);
                    system("cls");

                    break;

            case '3':
                    printf("\n Enter Value to Insert at Last Position in Link List = ");
                    scanf("%d",&Num);

                    Insert_Last(&Head, Num);
                    getch();

                    goto Out;

                    fflush(stdin);
                    system("cls");

                    break;

            default :
                    printf("\n\n Invalid Choice, Select Correct Option !!!");

                    getch();

                    fflush(stdin);
                    system("cls");
        }

    }
    Out :

    printf("\n\n ****Thanks For Using Our Application****");

    getch();
    return 0;
}




























