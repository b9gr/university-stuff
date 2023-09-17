#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ***************************
        BUGRA ILHAN
          2315307
   *************************** */

/* This function return a number between 0-7 (including 0) */
int randomDiamond()
{
    return rand()%7;
}

/* This function fills the both boards. It fills diamond board
with the certain number of diamonds which comes from main function.  */
void initializeBoards(char Diamondboard[7][7],char UserBoard[7][7], int G)
{
    int i,j;
    for(i=0;i<7;i++)
    {
        for(j=0;j<7;j++)
        {
            UserBoard[i][j]='?';
            Diamondboard[i][j]='?';
        }
    }
    int k;
    int a,b;
    for(k=0;k<G;k++)
    {
        a = randomDiamond();
        b = randomDiamond();
        if (Diamondboard[a][b]=='?')
            Diamondboard[a][b]='*';
        else
            G +=1;
    }
}

/* This function displays user board at the beginning of the game
and at the end of every round. In this function, there is a clearscreen
because program shouldn't print the "Your total points is 0" at the very
beginning of the game.  */
void displayUserBoard(char UserBoard[7][7], int total,int clearscreen)
{
    if (clearscreen>50)
        printf("\nYour total points is %d!\n", total);
    printf("\n\t     UserBoard\n\n");
    int i,n;
    for(n=1;n<=7;n++)
    {
        if (n==1)
            printf("     %d ", n);
        else
            printf("  %d ",n);
    }

    printf("\n   -----------------------------\n");
    for(n=1;n<=7;n++)
    {
        printf("%d  |", n);
        for(i=0;i<7;i++)
                printf(" %c |", UserBoard[n-1][i]);
        printf("\n   -----------------------------\n");
    }
    printf("\n");
}

/* This function gets the guessed coordinates from the user and returns
them to the main by pass by reference. It also checks that guessed
coordinates are guessed correctly - User input must be "(number,number)"
form and numbers must be between 0-7 -  or not. Then, it returns a value
due to the certain situation. */
int getGuessedCoordinates(int *a,int *b)
{
    fflush(stdin);
    printf("Please enter row and column:");
    scanf("(%d,%d)", a, b);
    system("cls");
    if ((*a>=1)&&(*a<=7)&&(*b>=1)&&(*b<=7))
        return 5;
    else
        return 10;
}

/* This function checks the coordinates which the user guessed.
If there is a diamond it returns 1, it there isn't one it returns 0. */
int checkDiamonds(int c, int d, char Diamondboard[7][7])
{
    if (Diamondboard[c-1][d-1]=='*')
        return 1;
    else
        return 0;
}

/* This function shows the user how many diamond/diamonds around the guessed
coordinates - around 8 coordinates - if there is not a diamond at the given coordinates. */
int provideHints(int R, int C, char UserBoard[7][7],char Diamondboard[7][7])
{
    int h1,h2;
    int countdiamond=0;
    for(h1=(R-2);h1<=R;h1++)
    {
        for(h2=(C-2);h2<=C;h2++)
        {
            if ((h1<0)||(h2<0)||(h1>6)||(h2>6))
                continue;
            else if (Diamondboard[h1][h2]==Diamondboard[R-1][C-1])
                continue;
            else if (Diamondboard[h1][h2]=='*')
                countdiamond++;
        }
    }
    UserBoard[R-1][C-1]=(char)(countdiamond+48);
    return 15;
}

/* This function changes "?" to "*" at the user board in the
guessed coordinates if there is a diamond. */
void showDiamond(int RR,int CC, char UserBoard[7][7])
{
    UserBoard[RR-1][CC-1]='*';
}

/* This function checks that whether the found diamond
is found for the first time. If it returns 0, that means
there is already '*' at the Userboard - This diamond found before - . */
int checkUserBoard(int rr, int cc, char Userboard[7][7])
{
    if (Userboard[rr-1][cc-1]=='*')
        return 0;
    else
        return 1;
}


int main()
{
    srand(time(NULL));
    char playagain; /* Yes/No condition for if the user wants to play again. */
    int diamonds; /* number of diamonds */
    char Diamondboard[7][7],UserBoard[7][7];
    int row,column;
    int check; /* It's for guessed coordinates check. */
    int round=1;
    int highestpoints=0; /* It keeps the highest points unless the program is closed. */
    do
    {
        /* This integer clearscreen is about printing totalpoints. */
        int clearscreen=10; /* It's 10 because program shouldn't print the "Your total points is 0" before the rounds. */
        system("cls"); /* clearing screen for windows*/
        printf("** Diamond Hunter **\nLet's get started!\n");
        printf("Enter the number of diamonds to hunt:");
        char ch;
        scanf("%d%c", &diamonds, &ch);
        initializeBoards(Diamondboard,UserBoard,diamonds);
        int totalpoints=0;
        displayUserBoard(UserBoard,totalpoints,clearscreen);
        for(round=1;round<=10;round++)
        {
            clearscreen=100; /* It's 100 now, because rounds started and program will print totalpoints at the end of every round.*/
            printf("\nRound %d:\n", round);
            check = getGuessedCoordinates(&row,&column);
            /* If coordinates guessed in the wrong form
            it prints error message and runs getGuessedCoordinates
            function again. */
            while(check!=5)
            {
                printf("\nInvalid Input!\n");
                check = getGuessedCoordinates(&row,&column);
            }
            if (checkDiamonds(row,column,Diamondboard)==1)
            {
                /* If the found diamond found for the first time, checkUserBoard function
                returns 1 and showDiamond function shows diamond to the user. Therefore,
                if the user guess the same coordinates again program will give error for this. */
                if(checkUserBoard(row,column,UserBoard)==1)
                {
                    printf("You got 100 points!");
                    totalpoints+=100;
                    showDiamond(row,column,UserBoard);
                }
                else
                    printf("\nYou already found this diamond!");

            }
            else
            {
                /* If there isn't a diamond in the guessed coordinates,
                provideHints function runs and user gets 0 points. */
                printf("You got 0 points!");
                int check2; /* It's for provideHints function runs correctly or not */
                check2=provideHints(row,column,UserBoard,Diamondboard);
                if (check2!=15)
                    printf("\nSomething wrong!");
            }
            displayUserBoard(UserBoard,totalpoints,clearscreen);
            fflush(stdin);
            if (diamonds*100==totalpoints)
            {
                /* Program checks if the user find the all diamonds or
                not at the end of every raund. If s/he found all the diamonds,
                it breaks the round loop and finishes the game. */
                printf("\nAll diamonds has been found!\n");
                break;
            }
        }
        /* Total points stores here unless the program is closed. */
        if (totalpoints>highestpoints)
            highestpoints=totalpoints;
        printf("HighestPoints: %d", highestpoints);
        printf("\n !! GAME OVER !!\n\n");
        /* If you want to play again just press Y :) */
        printf("\n\nDo you want to play again?:");
        fflush(stdin);
        scanf("%c", &playagain);
    }while ((playagain=='Y')||(playagain=='y'));
    return 0;
}
