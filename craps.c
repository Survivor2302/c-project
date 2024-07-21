#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "craps.h"

// Fonction pour lancer un dé et retourner un nombre entre 1 et 6
int lancer_de()
{
    return rand() % 6 + 1;
}

// Fonction principale pour jouer au craps
void jouer_craps(Joueur *joueur)
{
    // Vérifie si le joueur a assez de jetons pour jouer
    if (joueur->jetons <= 0)
    {
        printf("Vous n'avez pas assez de jetons pour jouer.\n");
        return;
    }

    int mise;
    // Demande au joueur combien de jetons il veut miser
    printf("Combien de jetons voulez-vous miser? ");
    scanf("%d", &mise);

    // Vérifie si la mise est supérieure aux jetons disponibles du joueur
    if (mise > joueur->jetons)
    {
        printf("Vous n'avez pas assez de jetons pour miser.\n");
        return;
    }

    int choix;
    // Demande au joueur de choisir un chiffre entre 2 et 12
    printf("Choisissez un chiffre entre 2 et 12: ");
    scanf("%d", &choix);

    // Vérifie si le choix est valide
    if (choix < 2 || choix > 12)
    {
        printf("Choix invalide.\n");
        return;
    }

    // Déduit la mise des jetons du joueur
    joueur->jetons -= mise;
    // Initialise le générateur de nombres aléatoires
    srand(time(NULL));

    // Lance deux dés
    int de1 = lancer_de();
    int de2 = lancer_de();
    int resultat = de1 + de2;

    // Affiche le résultat des dés
    printf("Vous avez lancé %d et %d. Total: %d\n", de1, de2, resultat);

    // Vérifie si le résultat des dés correspond au choix du joueur
    if (resultat == choix)
    {
        // Le joueur gagne et reçoit le double de sa mise
        joueur->jetons += 2 * mise;
        printf("Vous avez gagné! Vous avez maintenant %d jetons.\n", joueur->jetons);
    }
    else
    {
        // Le joueur perd sa mise
        printf("Vous avez perdu. Vous avez maintenant %d jetons.\n", joueur->jetons);
    }
}