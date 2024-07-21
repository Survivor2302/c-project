// blackjack.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "blackjack.h"

// Fonction pour tirer une carte aléatoire entre 1 et 11
int tirer_carte()
{
    return rand() % 11 + 1;
}

// Fonction pour calculer la somme des cartes d'un joueur
int calculer_somme(int *cartes, int nombre_cartes)
{
    int somme = 0;
    for (int i = 0; i < nombre_cartes; i++)
    {
        somme += cartes[i];
    }
    return somme;
}

// Fonction principale pour jouer une partie de blackjack
void jouer_blackjack(Joueur *joueur)
{
    // Vérifie si le joueur a assez de jetons pour jouer
    if (joueur->jetons <= 0)
    {
        printf("Vous n'avez pas assez de jetons pour jouer.\n");
        return;
    }

    int mise;
    printf("Combien de jetons voulez-vous miser? ");
    scanf("%d", &mise);

    // Vérifie si la mise est supérieure aux jetons du joueur
    if (mise > joueur->jetons)
    {
        printf("Vous n'avez pas assez de jetons pour miser.\n");
        return;
    }

    // Déduit la mise des jetons du joueur
    joueur->jetons -= mise;
    srand(time(NULL)); // Initialise le générateur de nombres aléatoires

    int joueur_cartes[10];          // Cartes du joueur
    int croupier_cartes[10];        // Cartes du croupier
    int joueur_nombre_cartes = 2;   // Nombre initial de cartes du joueur
    int croupier_nombre_cartes = 2; // Nombre initial de cartes du croupier

    // Tire deux cartes pour le joueur et le croupier
    joueur_cartes[0] = tirer_carte();
    joueur_cartes[1] = tirer_carte();
    croupier_cartes[0] = tirer_carte();
    croupier_cartes[1] = tirer_carte();

    // Calcule la somme des cartes du joueur et du croupier
    int joueur_somme = calculer_somme(joueur_cartes, joueur_nombre_cartes);
    int croupier_somme = calculer_somme(croupier_cartes, croupier_nombre_cartes);

    // Affiche les cartes du joueur et la première carte du croupier
    printf("Votre main: %d %d (somme = %d)\n", joueur_cartes[0], joueur_cartes[1], joueur_somme);
    printf("Main du croupier: %d ?\n", croupier_cartes[0]);

    // Vérifie si le joueur a un Blackjack ou a dépassé 21
    if (joueur_somme == 21)
    {
        joueur->jetons += 200 * mise;
        printf("Blackjack! Vous avez gagné x200 votre mise! Vous avez maintenant %d jetons.\n", joueur->jetons);
        return;
    }
    else if (joueur_somme > 21)
    {
        printf("Vous avez dépassé 21. Vous avez perdu.\n");
        return;
    }

    char choix;
    while (1)
    {
        // Demande au joueur s'il veut tirer une nouvelle carte ou rester
        printf("Voulez-vous tirer une nouvelle carte (t) ou rester (r)? ");
        scanf(" %c", &choix);
        if (choix == 't')
        {
            // Tire une nouvelle carte pour le joueur
            joueur_cartes[joueur_nombre_cartes++] = tirer_carte();
            joueur_somme = calculer_somme(joueur_cartes, joueur_nombre_cartes);
            printf("Votre main: ");
            for (int i = 0; i < joueur_nombre_cartes; i++)
            {
                printf("%d ", joueur_cartes[i]);
            }
            printf("(somme = %d)\n", joueur_somme);

            // Vérifie si le joueur a dépassé 21 ou a un Blackjack
            if (joueur_somme > 21)
            {
                printf("Vous avez dépassé 21. Vous avez perdu.\n");
                return;
            }
            else if (joueur_somme == 21)
            {
                joueur->jetons += 200 * mise;
                printf("Blackjack! Vous avez gagné x200 votre mise! Vous avez maintenant %d jetons.\n", joueur->jetons);
                return;
            }
        }
        else if (choix == 'r')
        {
            // Le joueur décide de rester
            break;
        }
        else
        {
            // Choix invalide
            printf("Choix invalide. Veuillez choisir 't' pour tirer ou 'r' pour rester.\n");
        }
    }

    // Affiche la main complète du croupier
    printf("Main du croupier: %d %d (somme = %d)\n", croupier_cartes[0], croupier_cartes[1], croupier_somme);

    // Le croupier tire des cartes jusqu'à atteindre au moins 17
    while (croupier_somme < 17)
    {
        croupier_cartes[croupier_nombre_cartes++] = tirer_carte();
        croupier_somme = calculer_somme(croupier_cartes, croupier_nombre_cartes);
        printf("Main du croupier: ");
        for (int i = 0; i < croupier_nombre_cartes; i++)
        {
            printf("%d ", croupier_cartes[i]);
        }
        printf("(somme = %d)\n", croupier_somme);
    }

    // Vérifie les différentes conditions de victoire ou de défaite
    if (croupier_somme > 21)
    {
        joueur->jetons += 200 * mise;
        printf("Le croupier a dépassé 21. Vous avez gagné x200 votre mise! Vous avez maintenant %d jetons.\n", joueur->jetons);
    }
    else if (croupier_somme == 21)
    {
        printf("Le croupier a fait Blackjack. Vous avez perdu.\n");
    }
    else if (croupier_somme >= joueur_somme)
    {
        printf("Le croupier a une main plus forte ou égale. Vous avez perdu.\n");
    }
    else
    {
        joueur->jetons += 200 * mise;
        printf("Vous avez une main plus forte. Vous avez gagné x200 votre mise! Vous avez maintenant %d jetons.\n", joueur->jetons);
    }
}
