#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "machine_a_sous.h"

// Fonction pour tirer un rouleau de la machine à sous
int tirer_rouleau()
{
    // Retourne un nombre aléatoire entre 0 et 9
    return rand() % 10;
}

// Fonction pour jouer à la machine à sous
void jouer_machine_a_sous(Joueur *joueur)
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

    // Vérifie si le joueur a assez de jetons pour miser le montant demandé
    if (mise > joueur->jetons)
    {
        printf("Vous n'avez pas assez de jetons pour miser.\n");
        return;
    }

    // Déduit la mise des jetons du joueur
    joueur->jetons -= mise;
    // Initialise le générateur de nombres aléatoires
    srand(time(NULL));

    // Tire les trois rouleaux
    int rouleau1 = tirer_rouleau();
    int rouleau2 = tirer_rouleau();
    int rouleau3 = tirer_rouleau();

    // Affiche les résultats des rouleaux
    printf("Les rouleaux montrent: %d %d %d\n", rouleau1, rouleau2, rouleau3);

    // Vérifie les différentes conditions de victoire
    if (rouleau1 == 0 && rouleau2 == 0 && rouleau3 == 0)
    {
        // Jackpot: tous les rouleaux montrent 0
        joueur->jetons += 1000 * mise;
        printf("Jackpot! Vous avez gagné x1000 votre mise! Vous avez maintenant %d jetons.\n", joueur->jetons);
    }
    else if (rouleau1 == rouleau2 && rouleau2 == rouleau3)
    {
        // Victoire: tous les rouleaux sont identiques
        joueur->jetons += 500 * mise;
        printf("Vous avez gagné! Les trois rouleaux sont identiques. Vous avez maintenant %d jetons.\n", joueur->jetons);
    }
    else if (rouleau1 == rouleau2 || rouleau1 == rouleau3 || rouleau2 == rouleau3)
    {
        // Victoire: deux rouleaux sont identiques
        joueur->jetons += 250 * mise;
        printf("Vous avez gagné! Deux rouleaux sont identiques. Vous avez maintenant %d jetons.\n", joueur->jetons);
    }
    else
    {
        // Défaite: aucun rouleau n'est identique
        printf("Vous avez perdu. Vous avez maintenant %d jetons.\n", joueur->jetons);
    }
}