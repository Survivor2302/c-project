#include <stdio.h>
#include <stdlib.h>
#include "casino.h"
#include "poker.h"
#include "blackjack.h"
#include "roulette.h"

void afficher_menu(Joueur *joueur) {
    int choix;
    do {
        printf("Bienvenue au Casino!\n");
        printf("Vous avez %d jetons.\n", joueur->jetons);
        printf("1. Poker\n");
        printf("2. Blackjack\n");
        printf("3. Roulette\n");
        printf("4. Quitter\n");
        printf("Choisissez un jeu: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                jouer_poker(joueur);
                break;
            case 2:
                jouer_blackjack(joueur);
                break;
            case 3:
                jouer_roulette(joueur);
                break;
            case 4:
                printf("Merci d'avoir joué au Casino!\n");
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
        }
    } while(choix != 4);
}

int main() {
    Joueur *joueur = malloc(sizeof(Joueur));
    joueur->jetons = 100; // Initialisation des jetons du joueur

    afficher_menu(joueur);

    free(joueur);
    return 0;
}
