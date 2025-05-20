//
//  Jeu.cpp
//  lo21_cascadia
//
//  Created by 赵振宇 on 16/05/2025.
//

#include "Jeu.hpp"
#include <array>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm> // for std::fill

void Jeu::attribuerJetonsEtTuiles(std::array<Tuile*, 4>& tuilesTable,
                                  std::array<JetonEspece*, 4>& jetonsTable) {
    // 1. 如果tuilesTable中有空位（nullptr），从habitat资源池中抽取并填充
    for (auto& tuile : tuilesTable) {
        if (tuile == nullptr) {
            auto nouvelles = poolHabitat.piocher(1);
            if (!nouvelles.empty()) tuile = nouvelles[0];
        }
    }

    // 2. 如果jetonsTable中有空位，从faune资源池中抽取并填充
    for (auto& jeton : jetonsTable) {
        if (jeton == nullptr) {
            auto nouveaux = poolFaune.piocher(1);
            if (!nouveaux.empty()) jeton = nouveaux[0];
        }
    }

    // 3. 检查是否有4个或3个相同类型的动物，用于是否进行重新抽取的判断
    std::map<Espece, int> compteur;
    for (auto& jeton : jetonsTable) {
        if (jeton != nullptr)
            compteur[jeton->getEspece()]++;
    }

    std::vector<JetonEspece*> retours;

    // 4. 如果4个动物相同，且玩家选择使用nature令牌，则全部重抽
    if (compteur.size() == 1 && joueurActuel->getNombreJetonsNature() > 0 && joueurActuel->choisirUtiliserJetonNature()) {
        for (auto& jeton : jetonsTable) {
            if (jeton != nullptr) {
                retours.push_back(jeton);
                jeton = nullptr;
            }
        }
        poolFaune.retournerRessources(retours);  // 放回池中
        auto nouveaux = poolFaune.piocher(4);    // 抽取4个新的
        for (int i = 0; i < 4 && i < nouveaux.size(); ++i)
            jetonsTable[i] = nouveaux[i];
    }

    // 5. 如果有3个相同动物，且玩家选择使用nature令牌，则只替换这3个
    for (const auto& [espece, count] : compteur) {
        if (count == 3 && joueurActuel->getNombreJetonsNature() > 0 && joueurActuel->choisirUtiliserJetonNature()) {
            int retirés = 0;
            for (auto& jeton : jetonsTable) {
                if (jeton && jeton->getEspece() == espece && retirés < 3) {
                    retours.push_back(jeton);
                    jeton = nullptr;
                    retirés++;
                }
            }
            poolFaune.retournerRessources(retours);  // 放回池中
            auto nouveaux = poolFaune.piocher(3);    // 抽取3个新的
            int pos = 0;
            for (auto& jeton : jetonsTable) {
                if (jeton == nullptr && pos < nouveaux.size()) {
                    jeton = nouveaux[pos++];
                }
            }
            break;
        }
    }

    // 6. 玩家选择一组：动物+栖息地
    int indexChoisi = 0;

    if (joueurActuel->getNombreJetonsNature() > 0 && joueurActuel->choisirUtiliserJetonNature()) {
        // 玩家选择任意组合
        indexChoisi = joueurActuel->choisirIndexLibre(tuilesTable, jetonsTable);
    } else {
        // 玩家只能选择相同索引位置的组合
        indexChoisi = joueurActuel->choisirIndexPair();
    }

    // 7. 玩家获取选择的资源，清除该位置
    joueurActuel->ajouterTuile(tuilesTable[indexChoisi]);
    joueurActuel->ajouterJeton(jetonsTable[indexChoisi]);

    tuilesTable[indexChoisi] = nullptr;
    jetonsTable[indexChoisi] = nullptr;

    // 8. 将被取走的空位重新补充
    for (auto& tuile : tuilesTable) {
        if (tuile == nullptr) {
            auto nouvelles = poolHabitat.piocher(1);
            if (!nouvelles.empty()) tuile = nouvelles[0];
        }
    }
    for (auto& jeton : jetonsTable) {
        if (jeton == nullptr) {
            auto nouveaux = poolFaune.piocher(1);
            if (!nouveaux.empty()) jeton = nouveaux[0];
        }
    }

    // 9. 输出当前地图状态
    //plateau.print();
}
