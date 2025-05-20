//
//  PoolRestant.h
//  lo21_cascadia
//
//  Created by 赵振宇 on 16/05/2025.
//

#ifndef PoolRestant_h
#define PoolRestant_h

#pragma once
#include <vector>
#include <algorithm>
#include <random>

template <typename T>
class PoolRestant {
protected:
    std::vector<T*> ressources;

public:
    virtual void initialiser() = 0;

    // 从资源池中抽取一定数量的资源
    std::vector<T*> piocher(int nombre) {
        std::vector<T*> pioche;
        for (int i = 0; i < nombre && !ressources.empty(); ++i) {
            pioche.push_back(ressources.back());
            ressources.pop_back();
        }
        return pioche;
    }

    // 将资源放回池中
    void retournerRessources(const std::vector<T*>& retours) {
        ressources.insert(ressources.end(), retours.begin(), retours.end());
    }

    // 获取当前资源池剩余资源
    std::vector<T*> obtenirReste() const {
        return ressources;
    }

    // 添加单个资源（用于初始化）
    void ajouterRessource(T* res) {
        ressources.push_back(res);
    }

    // 打乱资源池
    void melanger() {
        std::shuffle(ressources.begin(), ressources.end(), std::mt19937{std::random_device{}()});
    }
};


#endif /* PoolRestant_h */
