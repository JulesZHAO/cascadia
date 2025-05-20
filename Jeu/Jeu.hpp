//
//  Jeu.hpp
//  lo21_cascadia
//
//  Created by 赵振宇 on 16/05/2025.
//

#ifndef Jeu_hpp
#define Jeu_hpp

#include <stdio.h>
#include <vector>
#include <array>
#include <string>
#include <iostream>
#include "../Plateau/Plateau.hpp"
#include "../Plateau/Tuile.h"
#include "../Plateau/JetonEspece.h"
#include "../Pool/PoolFaune.hpp"
#include "../Pool/PoolHabitat.hpp"
#include "../Joueur/Joueur.hpp"

class Jeu {
private:
    std::vector<Joueur*> joueurs;
    //Plateau plateau;
    PoolFaune poolFaune;
    PoolHabitat poolHabitat;
    Joueur* joueurActuel;
    int tour = 0;
    //ModeDeJeu mode;

    int indexJoueurActuel = 0; // 用于切换当前玩家

public:
    void commencerJeu();
    void tourSuivant();
    void terminerJeu();

    //void définirMode(ModeDeJeu nouveauMode);
    
    bool vérifierJetonsFaune();
    void réattribuerJetonsFaune();
    std::vector<JetonEspece*> piocherJetonsEspece(int nombre);
    Tuile* piocherTuile();
    void attribuerJetonsEtTuiles(std::array<Tuile*, 4>& tuilesTable,
                                 std::array<JetonEspece*, 4>& jetonsTable);
};
#endif /* Jeu_hpp */
