//
//  Joueur.hpp
//  lo21_cascadia
//
//  Created by 赵振宇 on 18/05/2025.
//

#ifndef Joueur_hpp
#define Joueur_hpp

#include <stdio.h>
#include <vector>
#include <array>
#include "../Plateau/Tuile.h"
#include "../Plateau/JetonEspece.h"

class Joueur {
private:
    int nombreJetonsNature;                      // 玩家拥有的“自然”令牌数量
    std::vector<Tuile*> tuilesPossedees;        // 玩家持有的栖息地牌
    std::vector<JetonEspece*> jetonsPossedes;   // 玩家持有的动物标记

public:
    Joueur();

    // 获取玩家“自然”令牌的数量
    int getNombreJetonsNature() const;

    // 玩家选择是否使用“自然”令牌，返回true表示使用
    bool choisirUtiliserJetonNature() const;

    // 玩家选择一个任意组合的索引（任意组合：tuilesTable和jetonsTable中不同位置组合）
    // 参数为当前桌面上栖息地和动物标记数组
    int choisirIndexLibre(const std::array<Tuile*, 4>& tuilesTable,
                          const std::array<JetonEspece*, 4>& jetonsTable) const;

    // 玩家选择只能选择相同位置组合的索引（只能选相同索引的栖息地和动物）
    int choisirIndexPair() const;

    // 玩家获得一个栖息地资源，加入自己的持有牌中
    void ajouterTuile(Tuile* tuile);

    // 玩家获得一个动物标记，加入自己的持有标记中
    void ajouterJeton(JetonEspece* jeton);

    // 其他成员函数和数据成员
};

#endif /* Joueur_hpp */
