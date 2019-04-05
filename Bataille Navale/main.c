#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <math.h>
#pragma execution_character_set("utf-8")

#define STLC 218 // ┌, Single Top Left Corner
#define STRC 191 // ┐, Single Top Right Corner
#define SBLC 192 // └, Single Bottom Left Corner
#define SBRC 217 // ┘, Single Bottom Right Corner
#define SVSB 179 // │, Single Vertical Simple Border
#define SVRB 180 // ┤, Single Vertical Right Border
#define SVLB 195 // ├, Single Vertical Left Border
#define SHSB 196 // ─, Single Horizontal Simple Border
#define SHBB 193 // ┴, Single Horizontal Bottom Border
#define SHTB 194 // ┬, Single Horizontal Top Border
#define SC   197 // ┼, Single Center
#define DTLC 201 // ╔, Double Top Left Corner
#define DTRC 187 // ╗, Double Top Right Corner
#define DBLC 200 // ╚, Double Bottom Left Corner
#define DBRC 188 // ╝, Double Bottom Right Corner
#define DVSB 186 // ║, Double Vertical Simple Border
#define DVRB 185 // ╣, Double Vertical Right Border
#define DVLB 204 // ╠, Double Vertical Left Border
#define DHSB 205 // ═, Double Horizontal Simple Border
#define DHBB 202 // ╩, Double Horizontal Bottom Border
#define DHTB 203 // ╦, Double Horizontal Top Border
#define DC   206 // ╬, Double Center

int main() {

    SetConsoleOutputCP(65001);

    char base[9][9] = {
            /*{'0','1',2,3,4,5,6,7,8,9},*/
            {'~','~','~','~','~','~','~','~','~'},
            {'~','~','~','~','~','~','~','~','~'},
            {'~','~','~','~','~','~','~','~','~'},
            {'~','~','~','~','~','~','~','~','~'},
            {'~','~','~','~','~','~','~','~','~'},
            {'~','~','~','~','~','~','~','~','~'},
            {'~','~','~','~','~','~','~','~','~'},
            {'~','~','~','~','~','~','~','~','~'},
            {'~','~','~','~','~','~','~','~','~'},
    };
    int jeu1[9][9] = {
            /*12,3,4,5,6,7,8,9*/
            {1,1,0,0,0,0,0,0,22},
            {0,0,0,0,0,4,0,0,22},
            {2,0,0,0,0,4,0,0,22},
            {2,0,0,0,0,4,0,0,0},
            {2,0,0,0,0,4,0,0,0},
            {0,0,0,0,0,4,0,0,0},
            {0,0,3,3,3,3,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},

    };
    int jeu2[9][9] = {
            /*12,3,4,5,6,7,8,9*/
            {0,1,0,0,0,0,0,0,0},
            {0,1,0,0,0,22,0,0,0},
            {2,2,2,0,0,22,0,0,0},
            {0,0,0,0,0,22,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,3,0,0,0,0,0,0,0},
            {0,3,0,0,0,0,0,0,0},
            {0,3,0,0,0,0,0,0,0},
            {0,3,0,0,4,4,4,4,4},

    };
    int jeu3[9][9] = {
            /*12,3,4,5,6,7,8,9*/
            {0,4,0,2,2,2,0,0,0},
            {0,4,0,0,0,0,1,0,0},
            {0,4,0,0,0,0,1,0,3},
            {0,4,0,0,0,0,0,0,3},
            {0,4,0,0,0,0,0,0,3},
            {0,0,0,0,0,0,0,0,3},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,22,22,22,0,0},
            {0,0,0,0,0,0,0,0,0},

    };
    int jeu[9][9] = {
            /*12,3,4,5,6,7,8,9*/
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},

    };
    int ligne,colonne;
    int grand = 5,moyen = 4,sousmarinun = 3,sousmarindeux = 3,petit = 2,vietotale = 17,sortie = 1;
    int score = 0, tire = 0;
    char menu_option[5];


    FILE* fichier = fopen("scores.txt", "a+");










    //Imprimer image de la bataille navale sur la console
    printf("\t                                                 \n");
    printf("\t*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
    printf("\t*               ______________                   *\n");
    printf("\t*              |              |                  *\n");
    printf("\t*              |              |                  *\n");
    printf("\t*              |______________|                  *\n");
    printf("\t*                     ||                         *\n");
    printf("\t*                    |  |        WELCOME TO      *\n");
    printf("\t*                   |    |       BATTLESHIP      *\n");
    printf("\t*                  |      |                      *\n");
    printf("\t*                 |________|                     *\n");
    printf("\t*                |          |                    *\n");
    printf("\t*                |          |                    *\n");
    printf("\t*                |          |                    *\n");
    printf("\t*                |          |                    *\n");
    printf("\t*                |          |                    *\n");
    printf("\t*                |          |                    *\n");
    printf("\t*                 (        )                     *\n");
    printf("\t*                  (      )                      *\n");
    printf("\t*                   (____)                       *\n");
    printf("\t*                    (__)                        *\n");
    printf("\t*                                                *\n");
    printf("\t*      /|                           /|           *\n");
    printf("\t*     /_|             /|           /_|           *\n");
    printf("\t*   ____|____        /_|         ____|____       *\n");
    printf("\t*~~~|________/~~~~~____|____~~~~|________/~~~~~~~*\n");
    printf("\t*~~~~~~~~~~~~~~~~~|________/~~~~~~~~~~~~~~~~~~~~~*\n");
    printf("\t*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
    printf("\t*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\n");
    // fin de l'images de la bataille navale


    //Afficher date/time sur la console
    //Utilise les functions dans la librarie: <time.h>
    time_t rawtime;
    struct tm *info;
    char date_heure[250];
    time( &rawtime );
    info = localtime( &rawtime );
    strftime(date_heure,250,"%d/%m/%Y *** %H:%M:%S", info);
    printf("\n\n\tBonjour! Nous sommes : | %s |\n", date_heure );
    printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    Sleep(3500);

    system("cls");

    printf("\n");
    int menu_un;
    char pseudo[256];

    do{
        printf("\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n\t\t Menu Principal");
        printf("\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n\t\t 1 Jouer");
        printf("\n\t\t 2 Score");
        printf("\n\t\t 3 Aide");
        printf("\n\t\t 4 Quitter");
        printf("\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\t\t");
        printf("\n\tEntrez le numero de votre choix: ");
        scanf("%d",&menu_un);
        switch(menu_un)
        {
            case 1:
                    printf("\n\t ==========================================================\n\n");
                    printf("\t     Quel est votre nom capitaine? (Sans espaces SVP!!)\n");
                    printf("\n\t\t");
                    scanf("%s", pseudo);
                    //printf("%s",pseudo);   //afficher le pseudo
                    printf("\n\t     Bonjour capitaine %s !", pseudo);
                    printf("\n\n\t ==========================================================\n");
                    Sleep(400);
                do {
                    printf("\n\n\t      Merci de choisir une option dans le menu suivant!");
                    printf("\n\n\t ==========================================================\n\n");

                    //Afficher le sous-menu pour Jouer
                    printf("\t\t 1 Commencer\n");
                    printf("\t\t 2 Choix des cartes\n");
                    printf("\t\t 3 Retour\n");
                    printf("\n\t ==========================================================\n");

                    int sous_menu_un;
                    printf("\n\t\t Tapez votre choix de sous-menu : ");
                    scanf("%d", &sous_menu_un);

                    Sleep(1500);
                    system("cls");
                    switch (sous_menu_un) {
                        case 1:
                            do {
                                if (jeu[0][1] == 0){ for (int ligne = 0; ligne < 9; ++ligne) { for (int colonne = 0; colonne < 9; ++colonne) { jeu[ligne][colonne] = jeu1[ligne][colonne]; }}}    //test pour voir si l'utilisateur à choisi une carte ou pas

                                system("cls");
                                printf("\t1\t2\t3\t4\t5\t6\t7\t8\t9\n\n");
                                for (int ligne = 0; ligne < 9; ++ligne) {
                                    printf("%d\t", ligne + 1);
                                    for (int colonne = 0; colonne < 9; ++colonne) {
                                        printf("%c\t", base[ligne][colonne]);
                                    }
                                    printf("\n\n");
                                }


                                printf("(pour quitter entrez 0) entrez la ligne: \n");
                                scanf("%d", &ligne);
                                printf("(pour quitter entrez 0) entrez la colonne: \n");
                                scanf("%d", &colonne);

                                if (ligne != 0 || colonne != 0) {

                                    ligne = ligne - 1;
                                    colonne = colonne - 1;


                                    switch (jeu[ligne][colonne]) {
                                        case 1:
                                            base[ligne][colonne] = 'T';
                                            printf("Navir touché");
                                            petit = petit - 1;
                                            score = score + 1;tire = tire +1;
                                            vietotale = vietotale - 1;
                                            for (int ligne = 0; ligne < 9; ++ligne) {
                                                for (int colonne = 0; colonne < 9; ++colonne) {
                                                    if (petit == 0 && jeu[ligne][colonne] == 1) {
                                                        base[ligne][colonne] = 'C';
                                                        printf("Navir coulé");
                                                    }
                                                }
                                            }Sleep(500);
                                            break;
                                        case 2:
                                            base[ligne][colonne] = 'T';
                                            printf("Navir touché");
                                            sousmarinun = sousmarinun - 1;
                                            score = score + 1;tire = tire +1;
                                            vietotale = vietotale - 1;
                                            for (int ligne = 0; ligne < 9; ++ligne) {
                                                for (int colonne = 0; colonne < 9; ++colonne) {
                                                    if (sousmarinun == 0 && jeu[ligne][colonne] == 2) {
                                                        base[ligne][colonne] = 'C';
                                                        printf("Navir coulé");
                                                    }
                                                }
                                            }Sleep(500);
                                            break;
                                        case 3:
                                            base[ligne][colonne] = 'T';
                                            printf("Navir touché");
                                            moyen = moyen - 1;
                                            score = score + 1;tire = tire +1;
                                            vietotale = vietotale - 1;
                                            for (int ligne = 0; ligne < 9; ++ligne) {
                                                for (int colonne = 0; colonne < 9; ++colonne) {
                                                    if (moyen == 0 && jeu[ligne][colonne] == 3) {
                                                        base[ligne][colonne] = 'C';
                                                        printf("Navir coulé");
                                                    }
                                                }
                                            }Sleep(500);
                                            break;
                                        case 4:
                                            base[ligne][colonne] = 'T';
                                            printf("Navir touché");
                                            grand = grand - 1;
                                            score = score + 1;tire = tire +1;
                                            vietotale = vietotale - 1;
                                            for (int ligne = 0; ligne < 9; ++ligne) {
                                                for (int colonne = 0; colonne < 9; ++colonne) {
                                                    if (grand == 0 && jeu[ligne][colonne] == 4) {
                                                        base[ligne][colonne] = 'C';
                                                        printf("Navir coulé");
                                                    }
                                                }
                                            }Sleep(500);
                                            break;
                                        case 22:
                                            base[ligne][colonne] = 'T';
                                            printf("Navir touché");
                                            sousmarindeux = sousmarindeux - 1;
                                            score = score + 1;tire = tire +1;
                                            vietotale = vietotale - 1;
                                            for (int ligne = 0; ligne < 9; ++ligne) {
                                                for (int colonne = 0; colonne < 9; ++colonne) {
                                                    if (sousmarindeux == 0 && jeu[ligne][colonne] == 22) {
                                                        base[ligne][colonne] = 'C';
                                                        printf(" coulé");
                                                    }
                                                }
                                            }Sleep(500);
                                            break;
                                        default:
                                            base[ligne][colonne] = 'R';
                                            printf("Raté");
                                            tire = tire +1;
                                            Sleep(500);
                                            break;
                                    }
                                } else { sortie = 0; }
                            } while (vietotale != 0 && sortie != 0);
                            if (vietotale == 0) {
                                printf("'''~~~~~~~~~~~~~~~~''''\n"
                                       "'''YAY TU AS Gagné''''\n");
                                printf("'''~~~~~~~~~~~~~~~~''''\n"
                                       "'''~~~~~~~~~~~~~~~~''''\n");
                            }
                            fprintf(fichier,"%s",pseudo);
                            fprintf(fichier, "%s", "\n");
                            fprintf(fichier,"%d",score);
                            fprintf(fichier, "%s", "\n");
                            fprintf(fichier,"%d",tire);
                            fprintf(fichier, "%s", "\n");
                            break;
                        case 2:
                            printf("\n\t\t Vous etes dans le sous-menu: 2 Choix des cartes \n");
                            printf("\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                            //char ref[5];
                            int choix;
                            char choix_carte[5];
                            do {  //Repete la boucle jusqu'à ce que jouer fasse le choix correct de la carte
                                printf("\n\t\t Tapez votre choix de Carte 1 ou 2 ou 3 = ");
                                scanf("%d", &choix);
                                printf("\n\t\t Vous avez choisie Carte : %d \n", choix);
                                printf("\n\t ==========================================================\n");
                                switch(choix)
                                {
                                    case 1:
                                        for (int ligne = 0; ligne < 9; ++ligne) {
                                            for (int colonne = 0; colonne < 9; ++colonne) {
                                                jeu[ligne][colonne] = jeu1[ligne][colonne];
                                            }
                                        }
                                        break;
                                    case 2:
                                        for (int ligne = 0; ligne < 9; ++ligne) {
                                            for (int colonne = 0; colonne < 9; ++colonne) {
                                                jeu[ligne][colonne] = jeu2[ligne][colonne];
                                            }
                                        }
                                        break;
                                    case 3:
                                        for (int ligne = 0; ligne < 9; ++ligne) {
                                            for (int colonne = 0; colonne < 9; ++colonne) {
                                                jeu[ligne][colonne] = jeu3[ligne][colonne];
                                            }
                                        }
                                        break;
                                    default: printf ("Ce n'est pas une carte\n");
                                        break;
                                }

                            } while (choix != 1 && choix != 2 && choix != 3);

                            break;
                        case 3:
                            printf("\n\t\t Vous etes dans le sous-menu: 1 Retour \n");
                            printf("\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
                            system("cls");
                            sortie = 0;
                            break;
                        default:
                            break;
                    }
                }while(sortie != 0 && vietotale != 0);
                break;
            case 2:
                system("cls");
                fclose(fichier);
                fichier = fopen("scores.txt", "a+");
                printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n\t~~~~~~~~~  meilleures joueurs  ~~~~~~~~~~~~");
                printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
                while(!feof(fichier)){
                    fscanf(fichier,"%s",&pseudo);
                    fscanf(fichier,"%d",&score);
                    fscanf(fichier,"%d",&tire);
                    printf("\n\t Joueur    %s    %d points   %d tire(s)", pseudo, score, tire);
                    Sleep(100);
                }


                printf("\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n\n\t Appuyez sur n'import quel touche + Enter ");
                printf("\n\n\t pour retourner au Menu Principale");
                printf("\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t");
                scanf("%s",&menu_option);
                fclose(fichier);
                fichier = fopen("scores.txt", "a+");
                system("cls");

                break;
            case 3:
                system("cls");
                printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n\n\t Pour vous dirigez dans les Menus tapez le");
                printf("\n\t chiffre correspondant à l'options souhaitée ");
                printf("\n\t puis apuyez sur Entrer.");
                printf("\n\n\t Pour votre information vos choix et vos");
                printf("\n\t scores seront enregistres dans un fichier");
                printf("\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n\n\t Appuyez sur n'import quel touche + Enter ");
                printf("\n\n\t pour retourner au Menu Principale");
                printf("\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\t");

                scanf("%s",&menu_option);
                system("cls");
                break;
            case 4:
                system("cls");
                printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                printf("\n\n\t Vous avez choisi de quiter le jeux.");
                printf("\n\n\t A la prochaine :)");
                printf("\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n");
                Sleep(2000);
                menu_un=0;
                break;
            default: printf ("Vous n'avez choisi aucune options viable\n");
                break;
        }
    }while (menu_un!=0);

    fclose(fichier);









    return 0;
}