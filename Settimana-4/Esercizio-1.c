#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	//dichiarazione della matrice ed assegnamento
    char mtr1[10][10]={{'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'},
                    {'.','.','.','.','.','.','.','.','.','.'}};
    char lung=65;
    int i, j, c, r, s=0, mossa=0, ct=0;

    srand(time(NULL));
    r=rand()%10;
    c=rand()%10;
    mtr1[r][c]=lung;
    lung++;
    ct++;

    //Controllo della matrice e degli indici
    do
    {
        if(ct==26)
        {
            break;
        }
        mossa=rand()%4;
        s=0;

        switch(mossa)//direzione della mossa presa dal random
        {
            case 0: if(c!=0)
                    {
                        if(mtr1[r][c-1]=='.')//controllo che il valore sia un .
                        {
                            c--;
                            mtr1[r][c]=lung;
                            lung++;
                            ct++;
                            break;
                        }
                        else
                            s++;

                    }
                    else
                        s++;
            case 1: if(r!=9)
                    {
                        if(mtr1[r+1][c]=='.')//controllo che il valore sia un .
                        {
                            r++;
                            mtr1[r][c]=lung;
                            lung++;
                            ct++;
                            break;
                        }
                        else
                            s++;
                    }
                    else
                        s++;
            case 2: if(c!=9)
                    {
                        if(mtr1[r][c+1]=='.')//controllo che il valore sia un .
                        {
                            c++;
                            mtr1[r][c]=lung;
                            lung++;
                            ct++;
                            break;
                        }
                        else
                            s++;
                    }
                    else
                        s++;
            case 3: if(r!=0)
                    {
                        if(mtr1[r-1][c]=='.')//controllo che il valore sia un .
                        {
                            r--;
                            mtr1[r][c]=lung;
                            lung++;
                            ct++;
                            break;
                        }
                        else
                            s++;

                    }
                    else
                        s++;
        }
    }
    while(s<4);

    //Stampa della matrice
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            printf(" %5c", mtr1[i][j]);

        }
        printf("\n\n");
    }
}
