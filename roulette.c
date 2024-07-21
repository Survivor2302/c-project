#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "roulette.h"

// Fonction pour jouer à la roulette
void jouer_roulette(Joueur *joueur)
{
    int mise;
    // Demande au joueur combien de jetons il veut miser
    printf("Combien de jetons voulez-vous miser? ");
    scanf("%d", &mise);

    // Vérifie si le joueur a assez de jetons pour miser
    if (mise > joueur->jetons)
    {
        printf("Vous n'avez pas assez de jetons pour miser.\n");
        return;
    }

    // Déduit la mise des jetons du joueur
    joueur->jetons -= mise;

    int choix;
    // Demande au joueur de choisir un numéro entre 0 et 36
    printf("Choisissez un numéro entre 0 et 36: ");
    scanf("%d", &choix);

    // Vérifie si le choix est valide
    if (choix < 0 || choix > 36)
    {
        printf("Choix invalide.\n");
        // Rembourse la mise si le choix est invalide
        joueur->jetons += mise;
        return;
    }

    // Initialise le générateur de nombres aléatoires
    srand(time(NULL));
    // Tire un numéro aléatoire entre 0 et 36
    int resultat = rand() % 37;
    printf("Le numéro tiré est: %d\n", resultat);

    // Vérifie si le choix du joueur correspond au numéro tiré
    if (choix == resultat)
    {
        // Le joueur gagne 35 fois sa mise
        joueur->jetons += 35 * mise;
        printf("Win, Vous avez maintenant %d jetons.\n", joueur->jetons);
    }
    else
    {
        // Le joueur perd sa mise
        printf("Loose Vous avez maintenant %d jetons.\n", joueur->jetons);
    }
}