#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
/* ****************** **
       2315307
      BUGRA ILHAN
** ****************** */

/* It fills the secretcode string array
with 5 random color names. */
void Create_code(char **secretcode)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        j=rand()%5+2;
        if (j==2)
            strcpy(secretcode[i],"red");
        else if (j==3)
            strcpy(secretcode[i],"green");
        else if (j==4)
            strcpy(secretcode[i],"orange");
        else if (j==5)
            strcpy(secretcode[i],"blue");
        else if (j==6)
            strcpy(secretcode[i],"yellow");
    }
}
/* It gets the user's guesses, fills them to the
guesscode string array and if there are any
uppercase characters, it converts them to
lowercase.  */
void player_guess(char **guesscode)
{
    int i;
    printf("Enter your guess:");
    for(i=0;i<4;i++)
        scanf("%s", guesscode[i]);

    int a,b;
    for(a=0;a<4;a++)
    {
        for(b=0;guesscode[a][b]!='\0';b++)
            guesscode[a][b]= tolower(guesscode[a][b]);
    }
}

/* This function first checks that whether secretcode's
first element is the same with the guesscode's first element.
If it is, it converts guesscode's first element to "Black".
If it is not, it checks whether that guessed color is in the
whole secretcode array or not. If it is in the secretcode array
with different place, it converts  that particular guess place
to "White". If it is not in the whole secretcode array, it
converts that particular guess place to "_". Finally, it checks
whether whole guesscode array are full of Black or not. If it is
it returns 1 and if it is not it returns 0.   */
int find_score(char **secretcode, char **guesscode)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        int check=0;
        if (strcmp(secretcode[i],guesscode[i])==0)
            strcpy(guesscode[i],"Black");
        else
        {
            int a;
            for(a=0;a<4;a++)
            {
                if (a==i)
                    continue;
                else if ((strcmp(secretcode[a],guesscode[i])==0))
                {
                    strcpy(guesscode[i],"White");
                    check=1;
                }

            }
            if (check==0)
                strcpy(guesscode[i],"_");
        }
    }

    for(j=0;j<4;j++)
    {
        if(strcmp(guesscode[j],"Black")==0)
            continue;
        else
            return 0;
    }
    return 1;
}

/* It displays guesscode array after each guesses. */
void display_score(char **guesscode)
{
    printf("Your score is:");
    int a;
    for(a=0;a<4;a++)
        printf("%s ", guesscode[a]);
}

/* If find_score function returns 1, it displays about
that the user is the winner. If it returns 0, it displays
that the computer -codemaker- is the winner.  */
void display_winner(int point,int round,char **secretcode)
{
    if (point==1)
    {
        printf("\nYou win the game!\n");
        printf("Secretcode = ");
        int a;
        for(a=0;a<4;a++)
            printf("%s ", secretcode[a]);
        printf("\nYou found it after %d guesses!", round);
    }
    else
    {
        printf("\nYou LOST!\n");
        printf("Secretcode = ");
        int a;
        for(a=0;a<4;a++)
            printf("%s ", secretcode[a]);
        printf("\nCODEMAKER WINS!");
    }
}

int main()
{
    srand(time(NULL));
    char playagain; /* It is about you want to play 1 more time or not.*/
    int i,k; /* i is about memory allocation and k is return value for find_score. */
    char **secretcode, **guesscode; /* String arrays */
    /* Memory allocation for string arrays */
    secretcode = (char **) malloc (4 * sizeof(char *));
    for(i=0;i<4;i++)
        secretcode[i]=malloc(10 * sizeof(char));
    guesscode = (char **) malloc (4 * sizeof(char *));
    for(i=0;i<4;i++)
        guesscode[i]=malloc(10 * sizeof(char));
    /* Whether there is a enough memory or not. */
    if ((secretcode == NULL)||(guesscode == NULL))
    {
        printf("There is something wrong about memory!");
        exit(1);
    }

    printf("CODEBREAKER IS STARTING!\n");
    do
    {
        printf("Colors: Red - Orange - Blue - Green - Yellow\n");
        Create_code(secretcode); /* creating secretcode */
        printf("Secretcode is generated!");
        int round; /* Round :D */
        for(round=0;round<8;round++)
        {
            printf("\n%d.", round+1); /* printing round */
            player_guess(guesscode); /* taking guesses */
            k = find_score(secretcode,guesscode); /* let's see whether user find the secretcode. */
            display_score(guesscode); /* displays what's changed. */
            /* If user finds the code, it stops the round loop. */
            if (k==1)
                break;
        }
        /* displaying winner */
        display_winner(k,round+1,secretcode);
        printf("\n\nDo you want to play again?");
        fflush(stdin);
        /* you wanna play again? */
        scanf("%c", &playagain);
    }while((playagain=='y')||(playagain=='Y'));
    /* see ya bro */
    printf("BYEEE");

    return 0;
}
