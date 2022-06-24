#include <stdio.h>
#include <stdlib.h>
#include <time.h>


    //generating labyrinthe

//    srand(time(NULL));
//    int cord_arriver_x = rand() % x;
//    int cord_arriver_y = rand() % y;
//    int cord_player_x = rand() % x;
//    int cord_player_y = rand() % y;

//    zone[cord_arriver_x][cord_arriver_y]='A';


int main()
{
    //choose labyrinthe size

    int a,b,x,y;
    printf("choisissez la longueur horizontale du labyrinthe\n");
    scanf("%d",&x);
    printf("choisissez la longueur verticale du labyrinthe\n");
    scanf("%d",&y);
    char zone[x][y];
    for (a=0;a<x;a++){
        for (b=0;b<y;b++){
            int road =6;
            if (zone[a-1][b]!='#'){
                road--;
            }
            if (zone[a+1][b]!='#'){
                road--;
            }
            if (zone[a][b-1]!='#'){
                road--;
            }
            if (zone[a][b+1]!='#'){
                road--;
            }
            srand(time(NULL));
            int wall = rand() % road;
            if (wall==0){
                zone[a][b]='#';
            } else {
                zone[a][b]=' ';
            }
        }
    }
    //print map

    for (a=0;a<x;a++){
        printf("\n");
        for (b=0;b<y;b++){
            printf("%c",zone[a][b]);
        }
    }
    return 0;
}


