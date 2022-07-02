#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//int player_move(int verti,int horizon,int cord_player_verti,int cord_player_horizon,char zone[verti][horizon]){


int move_up(int cord_player_verti,int cord_player_horizon,int verti,int horizon,char zone[verti][horizon]){
       // move up
    if (cord_player_verti==0){
        if(zone[verti-1][cord_player_horizon]!='#'){
            return verti-1;
        }
        return cord_player_verti;
    }
    if(zone[cord_player_verti-1][cord_player_horizon]!='#'){
        //return zone[cord_player_verti-1][cord_player_horizon]='P';
        return cord_player_verti-1;
    }
    //return zone[cord_player_verti][cord_player_horizon]='P';
    return cord_player_verti;
}

int move_right(int cord_player_verti,int cord_player_horizon,int verti,int horizon,char zone[verti][horizon]){
       // move right
    if (cord_player_horizon==horizon-1){
        if(zone[cord_player_verti][0]!='#'){
            return 0;
        }
        return cord_player_horizon;
    }
    if(zone[cord_player_verti][cord_player_horizon+1]!='#'){
        //return zone[cord_player_verti][cord_player_horizon+1]='P';
        return cord_player_horizon+1;
    }
    //return zone[cord_player_verti][cord_player_horizon]='P';
    return cord_player_horizon;
}

int move_down(int cord_player_verti,int cord_player_horizon,int verti,int horizon,char zone[verti][horizon]){
       // move down
    if (cord_player_verti==verti-1){
        if(zone[0][cord_player_horizon]!='#'){
            return 0;
        }
        return cord_player_verti;
    }
    if(zone[cord_player_verti+1][cord_player_horizon]!='#'){
        //return zone[cord_player_verti+1][cord_player_horizon]='P';
        return cord_player_verti+1;
    }
    //return zone[cord_player_verti][cord_player_horizon]='P';
    return cord_player_verti;
}

int move_left(int cord_player_verti,int cord_player_horizon,int verti,int horizon,char zone[verti][horizon]){
       // move left
    if (cord_player_horizon==0){
        if(zone[cord_player_verti][horizon-1]!='#'){
            return horizon-1;
        }
        return cord_player_verti;
    }
    if(zone[cord_player_verti][cord_player_horizon-1]!='#'){
        //return zone[cord_player_verti][cord_player_horizon-1]='P';
        return cord_player_horizon-1;
    }
    //return zone[cord_player_verti][cord_player_horizon]='P';
    return cord_player_horizon;
}
//    }
//return 0;
//}

int print_map(int a,int b,int verti,int horizon,char zone[verti][horizon]){

     for (a=0;a<verti;a++){
        printf("\n");
        for (b=0;b<horizon;b++){
            printf("%c",zone[a][b]);
            }
        }
    printf("\n");
    return 0;
}

void laby_generator(int verti,int horizon,int a,int b,char zone[verti][horizon]){
        //random labyrinthe generator

    for (a=0;a<verti;a++){
        for (b=0;b<horizon;b++){
            zone[a][b]='#';
        }
    }
    int cord_gene_verti = verti/2;
    int cord_gene_horizon = horizon/2;
    zone[cord_gene_verti][cord_gene_horizon]=' ';
    printf("%d %d\n",cord_gene_verti,cord_gene_horizon);
    //int wall=0;
    char zone_B[verti][horizon];
    for (int i=0;i<300000;i++){
        //int road = 2;
        int road = rand() % 4;
        //road = 3;
        //printf("%d",road);
        //if (cord_gene_verti!=0&&cord_gene_horizon!=0&&cord_gene_verti!=verti&&cord_gene_horizon!=horizon){
            if (road==0){
                if (zone[cord_gene_verti+1][cord_gene_horizon]=='#'&&zone[cord_gene_verti+1][cord_gene_horizon+1]=='#'&&zone[cord_gene_verti+1][cord_gene_horizon-1]=='#'&&zone[cord_gene_verti+2][cord_gene_horizon]=='#'){
                    zone[cord_gene_verti+1][cord_gene_horizon]=' ';
                    for (a=0;a<verti-1;a++){
                        for (b=0;b<horizon;b++){
                            //if (a!=verti){
                                zone_B[a][b]=zone[a+1][b];
                            //} else {
                                zone_B[verti-1][b]=zone[0][b];
                            //}
                        }
                    }
                }
                if (zone[cord_gene_verti+1][cord_gene_horizon]==' '){
                    //cord_gene_verti=cord_gene_verti+1;
                }
            }

            //}
            if (road==1){
                if (zone[cord_gene_verti-1][cord_gene_horizon]=='#'&&zone[cord_gene_verti-1][cord_gene_horizon+1]=='#'&&zone[cord_gene_verti-1][cord_gene_horizon-1]=='#'&&zone[cord_gene_verti-2][cord_gene_horizon]=='#'){
                    zone[cord_gene_verti-1][cord_gene_horizon]=' ';
                    for (a=1;a<verti;a++){
                        for (b=0;b<horizon;b++){
                            //if (a!=0){
                                zone_B[a][b]=zone[a-1][b];
                            //} else {
                                zone_B[0][b]=zone[verti-1][b];
                            //}
                        }
                    }
                }
                if (zone[cord_gene_verti-1][cord_gene_horizon]==' '){
                    //cord_gene_verti=cord_gene_verti-1;
                }
            }

            //}
            if (road==2){
                if (zone[cord_gene_verti][cord_gene_horizon+1]=='#'&&zone[cord_gene_verti+1][cord_gene_horizon+1]=='#'&&zone[cord_gene_verti-1][cord_gene_horizon+1]=='#'&&zone[cord_gene_verti][cord_gene_horizon+2]=='#'){
                    zone[cord_gene_verti][cord_gene_horizon+1]=' ';
                    for (a=0;a<verti;a++){
                        for (b=0;b<horizon-1;b++){
                            //if (b!=horizon){
                                zone_B[a][b]=zone[a][b+1];
                            //} else {
                                zone_B[a][horizon-1]=zone[a][0];
                            //}
                        }
                    }
                }
                if (zone[cord_gene_verti][cord_gene_horizon+1]==' '){
                    //cord_gene_horizon=cord_gene_horizon+1;
                }
            }

            //}
            if (road==3){
                if (zone[cord_gene_verti][cord_gene_horizon-1]=='#'&&zone[cord_gene_verti+1][cord_gene_horizon-1]=='#'&&zone[cord_gene_verti-1][cord_gene_horizon-1]=='#'&&zone[cord_gene_verti][cord_gene_horizon-2]=='#'){
                    zone[cord_gene_verti][cord_gene_horizon-1]=' ';
                    for (a=0;a<verti;a++){
                        for (b=1;b<horizon;b++){
                            //if (b!=0){
                                zone_B[a][b]=zone[a][b-1];
                            //} else {
                                zone_B[a][0]=zone[a][horizon-1];
                            //}
                        }
                    }
                }
                if (zone[cord_gene_verti][cord_gene_horizon-1]==' '){
                    //cord_gene_horizon=cord_gene_horizon-1;
                }
            }

            //}

            for (a=0;a<verti;a++){
                for (b=0;b<horizon;b++){
                    zone[a][b]=zone_B[a][b];
                }
            }

        //}
    }

            /*for (a=0;a<verti;a++){
                printf("\n");
                for (b=0;b<horizon;b++){

                    printf("%c",zone_B[a][b]);
                    //zone[a][b]=zone_B[a][b];
                }
            }
            printf("\n\n");*/
    //wall = rand() % road;
    for (a=0;a<verti;a++){
        for (b=0;b<horizon;b++){

        }
    }
    for (a=0;a<verti;a++){
        for (b=0;b<horizon;b++){
        }
    }
}

void test(int verti,int horizon,int a,int b,char zone[verti][horizon]){
    int generation=1;
    for (a=0;a<verti;a++){
        for (b=0;b<horizon;b++){
            if (zone[a][b]!='v'){
                generation=0;
            }
        }
    }
    int road_verti = rand() % verti;
    int road_horizon = rand() % horizon;
    while(zone[road_verti-1][road_horizon]!='v'||zone[road_verti+1][road_horizon]!='v'||zone[road_verti][road_horizon-1]!='v'||zone[road_verti][road_horizon+1]!='v'){
        zone[road_verti][road_horizon]=='v';
        int next = rand() % 4;

    }
}


int main(){
    //choose labyrinthe size

    srand(time(NULL));
    int a=0,b=0,verti=10,horizon=10;

    char zone[verti][horizon];
    printf("choisissez la longueur horizontale du labyrinthe\n");
    //scanf("%d",&horizon);
    printf("choisissez la longueur verticale du labyrinthe\n");
    //scanf("%d",&verti);

    laby_generator(verti,horizon,a,b,zone);

    //generate random win cord

    int cord_arriver_verti = rand() % verti;
    int cord_arriver_horizon = rand() % horizon;
    zone[cord_arriver_verti][cord_arriver_horizon]='A';

    //generate random player cord

    int cord_player_verti = rand() % verti;
    int cord_player_horizon = rand() % horizon;
    zone[cord_player_verti][cord_player_horizon]='@';

    //print map

    print_map(a,b,verti,horizon,zone);
    printf("coordone joueur : %d %d\n",cord_player_horizon,cord_player_verti);

    //move menu


    while(!(cord_arriver_horizon==cord_player_horizon&&cord_arriver_verti==cord_player_verti)){
        char move;
        fflush(stdin);
        move=getch();
        switch(move){
        case 'z':
            printf("z");
            fflush(stdin);
            zone[cord_player_verti][cord_player_horizon]=' ';
            cord_player_verti=move_up(cord_player_verti,cord_player_horizon,verti,horizon,zone);
            break;
        case 'd':
            printf("d");
            fflush(stdin);
            zone[cord_player_verti][cord_player_horizon]=' ';
            cord_player_horizon=move_right(cord_player_verti,cord_player_horizon,verti,horizon,zone);
            break;
        case 's':
            printf("s");
            fflush(stdin);
            zone[cord_player_verti][cord_player_horizon]=' ';
            cord_player_verti=move_down(cord_player_verti,cord_player_horizon,verti,horizon,zone);
            break;
        case 'q':
            printf("q");
            fflush(stdin);
            zone[cord_player_verti][cord_player_horizon]=' ';
            cord_player_horizon=move_left(cord_player_verti,cord_player_horizon,verti,horizon,zone);
            break;
        }
        zone[cord_player_verti][cord_player_horizon]='@';
        printf("\n coordone joueur : %d %d\n coordone arrivee : %d %d",cord_player_horizon,cord_player_verti,cord_arriver_horizon,cord_arriver_verti);

        print_map(a,b,verti,horizon,zone);
        if (cord_arriver_horizon==cord_player_horizon&&cord_arriver_verti==cord_player_verti) {
            char game;
            printf("rejouer ? (o/n)\n");
            fflush(stdin);
            scanf("%c",&game);
            fflush(stdin);
            if(game=='o'){
                printf("test");
                laby_generator(verti,horizon,a,b,zone);
            }
        }
    }

    return 0;
}
