#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "blackjack.h"

void jouer_blackjack(Joueur *joueur) {
    printf("Vous avez choisi de jouer au Blackjack.\n");
    int mise;
    printf("Combien de jetons voulez-vous miser? ");
    scanf("%d", &mise);

    if (mise > joueur->jetons) {
        printf("Vous n'avez pas assez de jetons pour miser.\n");
        return;
    }

    joueur->jetons -= mise;

    // Simplification : le joueur gagne si le tirage est supérieur ou égal à 18
    srand(time(NULL));
    int joueur_tirage = rand() % 21 + 1;
    int croupier_tirage = rand() % 21 + 1;

    printf("Votre tirage: %d\n", joueur_tirage);
    printf("Tirage du croupier: %d\n", croupier_tirage);

    if (joueur_tirage > croupier_tirage) {
        joueur->jetons += 2 * mise;
        printf("Vous avez gagné au Blackjack! Vous avez maintenant %d jetons.\n", joueur->jetons);
    } else {
        printf("Vous avez perdu au Blackjack. Vous avez maintenant %d jetons.\n", joueur->jetons);
    }
}
