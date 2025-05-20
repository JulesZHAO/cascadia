//
//  PoolFaune.cpp
//  lo21_cascadia
//
//  Created by 赵振宇 on 16/05/2025.
//

// PoolFaune.cpp
#include "PoolFaune.hpp"
#include "../Plateau/JetonEspece.h"
#include <iostream>  // 若需要调试输出

void PoolFaune::initialiser() {
    for (int i = 0; i < 20; ++i) {
           ajouterRessource(new JetonEspece(Espece::OURS));
           ajouterRessource(new JetonEspece(Espece::RAPACE));
           ajouterRessource(new JetonEspece(Espece::SAUMON));
           ajouterRessource(new JetonEspece(Espece::RENARD));
           ajouterRessource(new JetonEspece(Espece::CERF));
       }
       //melanger(); // 打乱顺序
   }
