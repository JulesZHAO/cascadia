//
//  PoolFaune.hpp
//  lo21_cascadia
//
//  Created by 赵振宇 on 16/05/2025.
//

#ifndef PoolFaune_hpp
#define PoolFaune_hpp

#include <stdio.h>
#pragma once
#include "PoolRestant.h"
#include "../Plateau/JetonEspece.h"

enum class Type {
    OURS,
    RAPACE,
    LOUP,
    CERF
};


class PoolFaune : public PoolRestant<JetonEspece> {
public:
    void initialiser() override;
};

#endif /* PoolFaune_hpp */
