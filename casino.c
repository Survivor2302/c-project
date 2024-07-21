#include <stdio.h>
#include <stdlib.h>
#include "casino.h"
#include "roulette.h"

// Fonction pour afficher le menu et gérer les choix de l'utilisateur
void afficher_menu(Joueur *joueur)
{
    int choix; // Variable pour stocker le choix de l'utilisateur
    do
    {
        // Affichage du nombre de jetons du joueur
        printf("Vous avez %d jetons.\n", joueur->jetons);
        // Affichage des options de jeu
        printf("1. Craps\n");
        printf("2. Blackjack\n");
        printf("3. Roulette\n");
        printf("4. Machine a sous\n");
        printf("5. Quitter\n");
        printf("Choisissez un jeu: ");
        // Lecture du choix de l'utilisateur
        scanf("%d", &choix);

        // Gestion des choix de l'utilisateur
        switch (choix)
        {
        case 1:
            jouer_craps(joueur); // Appel de la fonction pour jouer au Craps
            break;
        case 2:
            jouer_blackjack(joueur); // Appel de la fonction pour jouer au Blackjack
            break;
        case 3:
            jouer_roulette(joueur); // Appel de la fonction pour jouer à la Roulette
            break;
        case 4:
            jouer_machine_a_sous(joueur); // Appel de la fonction pour jouer à la Machine à sous
            break;
        case 5:
            break; // Quitter le menu
        default:
            // Message d'erreur pour un choix invalide
            printf("Veuillez choisir un numéro valide.\n");
        }
    } while (choix != 5); // Répéter le menu tant que l'utilisateur ne choisit pas de quitter
}

// Fonction principale du programme
int main()
{
    // Allocation de mémoire pour un joueur
    Joueur *joueur = malloc(sizeof(Joueur));
    joueur->jetons = 200; // Initialisation des jetons du joueur

    afficher_menu(joueur); // Appel de la fonction pour afficher le menu

    free(joueur); // Libération de la mémoire allouée pour le joueur
    return 0;     // Fin du programme
}