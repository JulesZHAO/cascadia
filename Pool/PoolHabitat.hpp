//
//  PoolHabitat.hpp
//  lo21_cascadia
//
//  Created by 赵振宇 on 16/05/2025.
//

#ifndef PoolHabitat_hpp
#define PoolHabitat_hpp

#include <stdio.h>
#include "PoolRestant.h"
#include "../Plateau/Tuile.h"

class PoolHabitat : public PoolRestant<Tuile> {
public:
    // 重写初始方法，构建 85 个栖息地（17 x 5 种类型）
    void initialiser() override;

    // 析构函数负责释放所有动态分配的 TuileHabitat（可选，防内存泄漏）
    ~PoolHabitat() {
        for (auto res : ressources) {
            delete res;
        }
        ressources.clear();
    }
};
#endif /* PoolHabitat_hpp */
