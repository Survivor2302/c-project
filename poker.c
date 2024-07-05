#include <stdio.h>
#include <stdlib.h>
#include "poker.h"

void jouer_poker(Joueur *joueur) {
    printf("Vous avez choisi de jouer au Poker.\n");
    int mise;
    printf("Combien de jetons voulez-vous miser? ");
    scanf("%d", &mise);
    
    if (mise > joueur->jetons) {
        printf("Vous n'avez pas assez de jetons pour miser.\n");
        return;
    }
    
    joueur->jetons -= mise;

    // Simplification : 50% de chances de gagner
    if (rand() % 2) {
        joueur->jetons += 2 * mise;
        printf("Vous avez gagné au Poker! Vous avez maintenant %d jetons.\n", joueur->jetons);
    } else {
        printf("Vous avez perdu au Poker. Vous avez maintenant %d jetons.\n", joueur->jetons);
    }
}
