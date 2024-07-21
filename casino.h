#ifndef CASINO_H
#define CASINO_H

// Définition de la structure Joueur
typedef struct
{
    int jetons; // Nombre de jetons que le joueur possède
} Joueur;

// Déclaration de la fonction pour afficher le menu principal
void afficher_menu(Joueur *joueur);

// Déclaration de la fonction pour jouer à la roulette
void jouer_roulette(Joueur *joueur);

// Déclaration de la fonction pour jouer au craps
void jouer_craps(Joueur *joueur);

// Déclaration de la fonction pour jouer aux machines à sous
void jouer_machine_a_sous(Joueur *joueur);

// Déclaration de la fonction pour jouer au blackjack
void jouer_blackjack(Joueur *joueur);

#endif // CASINO_H