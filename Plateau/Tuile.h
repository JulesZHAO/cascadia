//
//  Tuile.h
//  lo21_cascadia
//
//  Created by 赵振宇 on 18/05/2025.
//

#ifndef Tuile_h
#define Tuile_h
enum class Habitat{
    MONTAGNE,
    PRAIRIE,
    MARAIS,
    FORET,
    RIVIERE
};

class Tuile {
private:
    std::vector<Habitat> types;

public:
    Tuile(Habitat type) : types{type} {}
    Tuile(const std::vector<Habitat>& t) : types(t) {}

    std::vector<Habitat> getTypes() const { return types; }
    bool contient(Habitat type) const {
        for (const auto& t : types) {
            if (t == type) return true;
        }
        return false;
    }
};
#endif /* Tuile_h */
