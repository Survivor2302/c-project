#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "roulette.h"

void jouer_roulette(Joueur *joueur) {
    printf("Vous avez choisi de jouer à la Roulette.\n");
    int mise;
    printf("Combien de jetons voulez-vous miser? ");
    scanf("%d", &mise);

    if (mise > joueur->jetons) {
        printf("Vous n'avez pas assez de jetons pour miser.\n");
        return;
    }

    joueur->jetons -= mise;

    int choix;
    printf("Choisissez un numéro entre 0 et 36: ");
    scanf("%d", &choix);

    if (choix < 0 || choix > 36) {
        printf("Choix invalide.\n");
        joueur->jetons += mise;
        return;
    }

    srand(time(NULL));
    int resultat = rand() % 37;
    printf("Le résultat de la roulette est: %d\n", resultat);

    if (choix == resultat) {
        joueur->jetons += 35 * mise;
        printf("Vous avez gagné à la Roulette! Vous avez maintenant %d jetons.\n", joueur->jetons);
    } else {
        printf("Vous avez perdu à la Roulette. Vous avez maintenant %d jetons.\n", joueur->jetons);
    }
}
