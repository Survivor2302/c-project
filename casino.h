#ifndef CASINO_H
#define CASINO_H

typedef struct {
    int jetons;
} Joueur;

void afficher_menu(Joueur *joueur);
void jouer_poker(Joueur *joueur);
void jouer_blackjack(Joueur *joueur);
void jouer_roulette(Joueur *joueur);

#endif // CASINO_H
