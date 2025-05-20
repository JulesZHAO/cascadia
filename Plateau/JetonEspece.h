//
//  JetonEspece.h
//  lo21_cascadia
//
//  Created by 赵振宇 on 18/05/2025.
//

#ifndef JetonEspece_h
#define JetonEspece_h
enum class Espece {
    OURS, 
    RAPACE,
    SAUMON,
    RENARD,
    CERF
};

class JetonEspece {
private:
    Espece espece;

public:
    JetonEspece(Espece e) : espece(e) {}
    Espece getEspece() const { return espece; }
};
#endif /* JetonEspece_h */
