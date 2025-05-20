//
//  PoolHabitat.cpp
//  lo21_cascadia
//
//  Created by 赵振宇 on 16/05/2025.
//

#include "PoolHabitat.hpp"
#include "../Plateau/Tuile.h"
#include <array>
#include <random>
#include <algorithm>

void PoolHabitat::initialiser() {
    std::array<Habitat, 5> types = {
        Habitat::MONTAGNE,
        Habitat::PRAIRIE,
        Habitat::MARAIS,
        Habitat::FORET,
        Habitat::RIVIERE
    };

    // 每种类型添加 17 个 TuileHabitat，总共 85 个
    for (const auto& type : types) {
        for (int i = 0; i < 17; ++i) {
            ajouterRessource(new Tuile(type));
        }
    }

    // 打乱资源池
    //melanger();
}
