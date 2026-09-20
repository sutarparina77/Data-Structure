#include"03Stack_Library.h"

int main()
{
    char Ch = '\0';
    int Choice = 0, Amnt = 0, Stack_Size = 0;
    int *FStack = NULL;

    goto Start;

    while(1)
    {
        printf("\n ========================*****============================");
        printf("\n\n Welcome to Billing App Using Array \n");

        printf("\n Select Choice :");

        printf("\n\t\t 1. Create Billing App Stack ");
        printf("\n\t\t 2. Insert Amount in Stack(PUSH) ");
        printf("\n\t\t 3. Delete Amount From Stack(POP) ");
        printf("\n\t\t 4. Display all entered Stack Amount ");
        printf("\n\t\t 5. Count of Entered Amount ");
        printf("\n\t\t 6. Search Stack Amount ");
        printf("\n\t\t 7. Total Amount in Billing App");
        printf("\n\t\t 8. Even Amount From Stack ");
        printf("\n\t\t 9. Odd Amount From Stack ");
        printf("\n\t\t 10. Highest Amount in Stack ");
        printf("\n\t\t 11. Lowest Amount in Stack ");
        printf("\n\t\t 12. Even Amount Count of Entered Amount ");
        printf("\n\t\t 13. Odd Amount Count of Entered Amount ");
        printf("\n\t\t 14. Delete Billing App Stack ");
        printf("\n\t\t 15. Exit... ");

        printf("\n\n Enter Your Choice : ");
        scanf("%d",&Choice);

        switch(Choice)
        {
            case 1:
                Start:
                printf("\n Enter How Many Amounts Stack Do you Want : ");
                scanf("%d",&Stack_Size);

                if(FStack != NULL)
                {
                    fflush(stdin);
                    printf("\n Want To Delete Current Stack And, \n Do You Want To Create New Stack (Yes / No) : ");
                    scanf("%s",&Ch);

                    if(Ch == 'y' || Ch == 'Y')
                    {
                        Delete_Stack(&FStack);
                        printf("\n Stack Deleted Successfully");
                    }
                    else
                    {
                        getch();
                        fflush(stdin);
                        system("cls");
                        break;
                    }
                }

                if(Create_Stack(&FStack, Stack_Size))
                {
                    printf("\n Stack Created Use Further Services.");
                }
                else
                {
                    printf("\n Stack is not Created due to insufficient memory.");
                }

                getch();
                fflush(stdin);
                system("cls");

                break;

            case 2:
                printf("\n Enter An Amount to Insert in Stack = ");
                scanf("%d",&Amnt);

                Push_Amnt(FStack, Amnt);

                getch();
                fflush(stdin);
                system("cls");

                break;

            case 3:
                Pop_Amnt(FStack);

                getch();
                fflush(stdin);
                system("cls");

                break;

            case 4:
                Display_Stack(FStack);

                getch();
                fflush(stdin);
                system("cls");

                break;

            case 5:
                printf("\n Count of Amounts in Stack are = %d.", Count_Stack_Amnt());

                getch();
                fflush(stdin);
                system("cls");

                break;

            case 6:
                printf("\n Enter Amount to Search = ");
                scanf("%d",&Amnt);

                Search_Amnt(FStack, Amnt);

                getch();
                fflush(stdin);
                system("cls");

                break;

            case 7:
                Total_Amnt(FStack);

                getch();
                fflush(stdin);
                system("cls");

                break;


            case 8:
                Even_Amnt(FStack);

                getch();
                fflush(stdin);
                system("cls");

                break;

            case 9:
                Odd_Amnt(FStack);

                getch();
                fflush(stdin);
                system("cls");

                break;

            case 10:
                Max_Amnt(FStack);

                getch();
                fflush(stdin);
                system("cls");

                break;

            case 11:
                Min_Amnt(FStack);

                getch();
                fflush(stdin);
                system("cls");

                break;

            case 12:
                Even_Amnt_Cnt(FStack);

                getch();
                fflush(stdin);
                system("cls");

                break;

            case 13:
                Odd_Amnt_Cnt(FStack);

                getch();
                fflush(stdin);
                system("cls");

                break;

            case 14:

                if(FStack != NULL)
                {
                    fflush(stdin);
                    printf("\n Are You Sure Want To Delete Current Stack (Yes/ No) : ");
                    scanf("%s",&Ch);

                    if(Ch == 'y' || Ch == 'Y')
                    {
                        Delete_Stack(&FStack);
                        printf("\n Stack Deleted Successfully");
                    }
                }

                getch();
                fflush(stdin);
                system("cls");

                break;

            case 15:
                    fflush(stdin);
                    printf("\n Are You Sure Do You Want To Exit Application??? (YES/ No) : ");
                    Ch = getchar();

                    if(Ch == 'y' || Ch == 'Y')

                    goto Out;

                    fflush(stdin);
                    system("cls");

                    break;

            default :
                    printf("\n Invalid Choice!!!");

                    getch();
                    fflush(stdin);
                    system("cls");

                    break;
        }
    }

    Out:
        printf("\n ==================*****==================");
        printf("\n Thanks For Using Our Application \n");


    getch();
    return 0;
}
