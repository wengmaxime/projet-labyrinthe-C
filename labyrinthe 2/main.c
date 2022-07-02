#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int move_up(int cord_player_verti,int cord_player_horizon,int verti,int horizon,char zone[verti][horizon]){
       // move up
    if (cord_player_verti==0){
        if(zone[verti-1][cord_player_horizon]!='#'){
            return verti-1;
        }
        return cord_player_verti;
    }
    if(zone[cord_player_verti-1][cord_player_horizon]!='#'){
        return cord_player_verti-1;
    }
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
        return cord_player_horizon+1;
    }
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
        return cord_player_verti+1;
    }
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
        return cord_player_horizon-1;
    }
    return cord_player_horizon;
}

int print_map(int a,int b,int verti,int horizon,char zone[verti][horizon],int cord_player_verti,int cord_player_horizon,int cord_arriver_verti,int cord_arriver_horizon){

    //printing labyrinthe system

    char zone_B[verti+2][horizon+2];
    for (a=0;a<verti;a++){
        for (b=0;b<horizon;b++){
            zone_B[a+1][b+1]=zone[a][b];
            zone_B[0][b+1]=zone[verti-1][b];
            zone_B[verti+1][b+1]=zone[0][b];
            zone_B[a+1][0]=zone[a][horizon-1];
            zone_B[a+1][horizon+1]=zone[a][0];
            zone_B[0][0]=zone[verti-1][horizon-1];
            zone_B[verti+1][0]=zone[0][horizon-1];
            zone_B[0][horizon+1]=zone[verti-1][0];
            zone_B[verti+1][horizon+1]=zone[0][0];
        }
    }
    if(0){ //j'ai voulu tester toutes les routes et compter le nombre de cases traversées en bloquand les chemins qui menent nul part par des "*" mais j'ai pas réussi pour le point sur le chemin
        int count =0,best=0;
        char road,short_road;
        int cord_road_verti=cord_player_verti;
        int cord_road_horizon=cord_player_horizon;
        while ((cord_road_verti!=cord_arriver_verti&&cord_road_horizon!=cord_arriver_horizon)||(cord_road_verti!=cord_player_verti&&cord_road_horizon!=cord_player_horizon)){
            if (zone_B[cord_road_verti+1][cord_road_horizon]!='#'&&zone_B[cord_road_verti+1][cord_road_horizon]!='*'){
                zone_B[cord_road_verti][cord_road_horizon]='o';
                cord_arriver_verti=cord_road_verti+1;
                if (count==0){
                    road = 'd';
                }
                count++;
                if(zone_B[cord_road_verti+1][cord_road_horizon]=='o'){
                    for (a=0;a<verti+2;a++){
                        for (b=0;b<horizon+2;b++){
                            if(zone_B[a][b]=='o'){
                               zone_B[a][b]==' ';
                            }
                        }
                    }
                    count=0;
                    zone_B[cord_road_verti][cord_road_horizon]='*';
                    cord_road_verti=cord_player_verti;
                    cord_road_horizon=cord_player_horizon;
                }
            }
            if (zone_B[cord_road_verti-1][cord_road_horizon]!='#'&&zone_B[cord_road_verti-1][cord_road_horizon]!='*'){
                zone_B[cord_road_verti][cord_road_horizon]='o';
                cord_arriver_verti=cord_road_verti-1;
                if (count==0){
                    road='u';
                }
                count++;
                if(zone_B[cord_road_verti-1][cord_road_horizon]=='o'){
                    for (a=0;a<verti+2;a++){
                        for (b=0;b<horizon+2;b++){
                            if(zone_B[a][b]=='o'){
                               zone_B[a][b]==' ';
                            }
                        }
                    }
                    count=0;
                    zone_B[cord_road_verti][cord_road_horizon]='*';
                    cord_road_verti=cord_player_verti;
                    cord_road_horizon=cord_player_horizon;
                }
            }
            if (zone_B[cord_road_verti][cord_road_horizon+1]!='#'&&zone_B[cord_road_verti][cord_road_horizon+1]!='*'){
                zone_B[cord_road_verti][cord_road_horizon]='o';
                cord_arriver_horizon=cord_road_horizon+1;
                if (count==0){
                    road='r';
                }
                count++;
                if(zone_B[cord_road_verti][cord_road_horizon+1]=='o'){
                    for (a=0;a<verti+2;a++){
                        for (b=0;b<horizon+2;b++){
                            if(zone_B[a][b]=='o'){
                               zone_B[a][b]==' ';
                            }
                        }
                    }
                    count=0;
                    zone_B[cord_road_verti][cord_road_horizon]='*';
                    cord_road_verti=cord_player_verti;
                    cord_road_horizon=cord_player_horizon;
                }
            }
            if (zone_B[cord_road_verti][cord_road_horizon-1]!='#'&&zone_B[cord_road_verti][cord_road_horizon-1]!='*'){
                zone_B[cord_road_verti][cord_road_horizon]='o';
                cord_arriver_horizon=cord_road_horizon-1;
                if (count==0){
                    road = 'l';
                }
                count++;
                if(zone_B[cord_road_verti][cord_road_horizon-1]=='o'){
                    for (a=0;a<verti+2;a++){
                        for (b=0;b<horizon+2;b++){
                            if(zone_B[a][b]=='o'){
                               zone_B[a][b]==' ';
                            }
                        }
                    }
                    count=0;
                    zone_B[cord_road_verti][cord_road_horizon]='*';
                    cord_road_verti=cord_player_verti;
                    cord_road_horizon=cord_player_horizon;
                }
                if (count<best||best==0){
                    short_road=road;
                }
                if(zone_B[cord_road_verti][cord_road_horizon-1]!='#'){
                    for (a=0;a<verti+2;a++){
                        for (b=0;b<horizon+2;b++){
                            zone_B[a][b]==' ';
                        }
                    }
                }
            printf("%c",short_road);
            }
        }
    }
     for (a=0;a<verti;a++){
        printf("\n");
        for (b=0;b<horizon;b++){
            printf("%c",zone[a][b]);
        }
    }
    printf("\n\n");
    for (a=(cord_player_verti-1);a<(cord_player_verti+2);a++){
        printf("\n");
        for (b=(cord_player_horizon-1);b<(cord_player_horizon+2);b++){
                printf("%c",zone_B[a+1][b+1]);
        }
    }
    printf("\n\ncomment jouer ?(ou editer)\nz:deplacer vers le haut\nq:deplacer vers la gauche\nsdeplacer vers le bas\nd:deplacer vers la droite\ne:editeur de niveau\n+:ajouter un mur(editeur)\n-:enlever un mur(editeur)\np:deplacer le joueur(editeur)\na:deplacer l'arriver(editeur)\n");
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
    char zone_B[verti][horizon];
    int i =0;
    int c=0;
    for (;i<100;i++){
        int road = rand() % 4;
        if (road==0){
            if (zone[cord_gene_verti+1][cord_gene_horizon]=='#'&&zone[cord_gene_verti+1][cord_gene_horizon+1]=='#'&&zone[cord_gene_verti+1][cord_gene_horizon-1]=='#'&&zone[cord_gene_verti+2][cord_gene_horizon]=='#'){
                zone[cord_gene_verti+1][cord_gene_horizon]=' ';
                c=0;
            }
            if (zone[cord_gene_verti+1][cord_gene_horizon]==' '){
                for (a=0;a<verti-1;a++){
                    for (b=0;b<horizon;b++){
                        zone_B[a][b]=zone[a+1][b];
                        zone_B[verti-1][b]=zone[0][b];
                    }
                }
            }
        }
        if (road==1){
            if (zone[cord_gene_verti-1][cord_gene_horizon]=='#'&&zone[cord_gene_verti-1][cord_gene_horizon+1]=='#'&&zone[cord_gene_verti-1][cord_gene_horizon-1]=='#'&&zone[cord_gene_verti-2][cord_gene_horizon]=='#'){
                zone[cord_gene_verti-1][cord_gene_horizon]=' ';
                c=0;
            }
            if (zone[cord_gene_verti-1][cord_gene_horizon]==' '){
                for (a=1;a<verti;a++){
                    for (b=0;b<horizon;b++){
                        zone_B[a][b]=zone[a-1][b];
                        zone_B[0][b]=zone[verti-1][b];
                    }
                }
            }
        }
        if (road==2){
            if (zone[cord_gene_verti][cord_gene_horizon+1]=='#'&&zone[cord_gene_verti+1][cord_gene_horizon+1]=='#'&&zone[cord_gene_verti-1][cord_gene_horizon+1]=='#'&&zone[cord_gene_verti][cord_gene_horizon+2]=='#'){
                zone[cord_gene_verti][cord_gene_horizon+1]=' ';
                c=0;
            }
            if(zone[cord_gene_verti][cord_gene_horizon+1]==' '){
                for (a=0;a<verti;a++){
                    for (b=0;b<horizon-1;b++){
                        zone_B[a][b]=zone[a][b+1];
                        zone_B[a][horizon-1]=zone[a][0];
                    }
                }
            }
        }
        if (road==3){
            if (zone[cord_gene_verti][cord_gene_horizon-1]=='#'&&zone[cord_gene_verti+1][cord_gene_horizon-1]=='#'&&zone[cord_gene_verti-1][cord_gene_horizon-1]=='#'&&zone[cord_gene_verti][cord_gene_horizon-2]=='#'){
                zone[cord_gene_verti][cord_gene_horizon-1]=' ';
                c=0;
            }
            if (zone[cord_gene_verti][cord_gene_horizon-1]==' '){
                for (a=0;a<verti;a++){
                    for (b=1;b<horizon;b++){
                        zone_B[a][b]=zone[a][b-1];
                        zone_B[a][0]=zone[a][horizon-1];
                    }
                }
            }
        }
        for (a=0;a<verti;a++){
            for (b=0;b<horizon;b++){
                zone[a][b]=zone_B[a][b];
            }
        }
        for (a=1;a<verti-1;a++){
            for (b=1;b<horizon-1;b++){
                if (zone[a][b]=='#'&&zone[a+1][b]=='#'&&zone[a-1][b]=='#'&&zone[a][b+1]=='#'&&zone[a][b-1]=='#'&&i!=0){
                    i=0;
                    c++;
                    if (c==50){
                        laby_generator(verti,horizon,a,b,zone);
                        i=300;
                    }
                }
            }
        }
    }
}

int main(){

    //choose labyrinthe size

    int fin =0;

    printf("Bienvenue dans le jeu du Labyrinthe de Maxime Weng \n \n1)jouer \n2)quitter \n \ncopyright 2022 \n");
    int menu;
    fflush(stdin);
    scanf("%d",&menu);
    fflush(stdin);
    system ("cls");
    switch(menu){
    case 1:
        while (fin!=1){
            srand(time(NULL));
            int a=0,b=0,verti=10,horizon=10;
            time_t debut_t,fin_t;
            char zone[verti][horizon];
            printf("\nchoisissez la longueur horizontale du labyrinthe (exemple : 10)\n");
            //scanf("%d",&horizon);
            printf("\nchoisissez la longueur verticale du labyrinthe (exemple : 10)\n");
            //scanf("%d",&verti);

            system ("cls");

            laby_generator(verti,horizon,a,b,zone);

            //generate random win cord

            int cord_arriver_verti = rand() % verti;
            int cord_arriver_horizon = rand() % horizon;
            zone[cord_arriver_verti][cord_arriver_horizon]='A';

            //generate random player cord

            int cord_player_verti = rand() % verti;
            int cord_player_horizon = rand() % horizon;
            zone[cord_player_verti][cord_player_horizon]='@';

            //generate random ennemy cord non configurer par manque d'organisation

            //int cord_ennemy_verti = rand() % verti;
            //int cord_ennemy_horizon = rand() % horizon;
            //zone[cord_ennemy_verti][cord_ennemy_horizon]='E';

            char save;
            int cord_editeur_verti = 0;
            int cord_editeur_horizon = 0;
            zone[cord_player_verti][cord_player_horizon]='@';

            print_map(a,b,verti,horizon,zone,cord_player_verti,cord_player_horizon,cord_arriver_verti,cord_arriver_horizon);

            //move menu

            debut_t = time(NULL);
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

                    case 'e':
                        save=zone[cord_editeur_verti][cord_editeur_horizon];
                        zone[cord_editeur_verti][cord_editeur_horizon]='x';
                        print_map(a,b,verti,horizon,zone,cord_player_verti,cord_player_horizon,cord_arriver_verti,cord_arriver_horizon);
                        char edit=' ';
                        fflush(stdin);
                        while(edit!='e'){
                        edit=getch();
                            switch(edit){
                                case 'z':
                                    zone[cord_editeur_verti][cord_editeur_horizon]= save;
                                    cord_editeur_verti=cord_editeur_verti-1;
                                    save = zone[cord_editeur_verti][cord_editeur_horizon];
                                    zone[cord_editeur_verti][cord_editeur_horizon]='x';
                                    break;
                                case 'd':
                                    zone[cord_editeur_verti][cord_editeur_horizon]= save;
                                    cord_editeur_horizon=cord_editeur_horizon+1;
                                    save = zone[cord_editeur_verti][cord_editeur_horizon];
                                    zone[cord_editeur_verti][cord_editeur_horizon]='x';
                                    break;
                                case 's':
                                    zone[cord_editeur_verti][cord_editeur_horizon]= save;
                                    cord_editeur_verti=cord_editeur_verti+1;
                                    save = zone[cord_editeur_verti][cord_editeur_horizon];
                                    zone[cord_editeur_verti][cord_editeur_horizon]='x';
                                    break;
                                case 'q':
                                    zone[cord_editeur_verti][cord_editeur_horizon]= save;
                                    cord_editeur_horizon=cord_editeur_horizon-1;
                                    save = zone[cord_editeur_verti][cord_editeur_horizon];
                                    zone[cord_editeur_verti][cord_editeur_horizon]='x';
                                    break;
                                case '+':
                                    save = '#';
                                    break;
                                case '-':
                                    save = ' ';
                                    break;
                                case 'p':
                                    zone[cord_player_verti][cord_player_horizon]=' ';
                                    cord_player_verti=cord_editeur_verti;
                                    cord_player_horizon=cord_editeur_horizon;
                                    zone[cord_player_verti][cord_player_horizon]='@';
                                    save = 'p';
                                    break;
                                case 'a':
                                    zone[cord_arriver_verti][cord_arriver_horizon]=' ';
                                    cord_arriver_verti=cord_editeur_verti;
                                    cord_arriver_horizon=cord_editeur_horizon;
                                    zone[cord_arriver_verti][cord_arriver_horizon]='A';
                                    save = 'A';
                                    break;
                                case 'e':
                                    zone[cord_editeur_verti][cord_editeur_horizon]=save;
                                    break;
                            }
                            system ("cls");
                            print_map(a,b,verti,horizon,zone,cord_player_verti,cord_player_horizon,cord_arriver_verti,cord_arriver_horizon);
                        }
                    }
                system ("cls");
                zone[cord_player_verti][cord_player_horizon]='@';

                print_map(a,b,verti,horizon,zone,cord_player_verti,cord_player_horizon,cord_arriver_verti,cord_arriver_horizon);
                if (cord_arriver_horizon==cord_player_horizon&&cord_arriver_verti==cord_player_verti) {
                    char game;
                    fin_t = time(NULL);
                    printf("temps pour atteindre l'arriver : %.0f unite machine\n",(float)difftime(fin_t, debut_t));
                    printf("rejouer ? (n:non)\n");
                    fflush(stdin);
                    scanf("%c",&game);
                    fflush(stdin);
                    if(game=='n'){
                        fin =1;
                    }
                }
            }
        }
        break;
    //case 2:
    case 2: //je comptais faire un menu avec + de choix au début
        return 0;
        break;
    }
    return 0;
}
