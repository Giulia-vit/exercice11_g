#pragma once
#include "dessinable.h"
#include "support_a_dessin.h"
#include "Particule.h"
#include <iostream>

class Enceinte : public Dessinable {
private:
    double hauteur;
    double largeur;
    double profondità;

public:

    //[Constructeur par default]
    Enceinte(double hauteur = 20, double largeur = 20, double profondeur = 20);

    //[Constructeur de copie]
    Enceinte(const Enceinte& enceinteCopie);

    //[Méthodes getters utilisé pour representer l'enceinte dans la méthode dessine(Enceinte) dans vue_opengl.cc]
    double get_h() const { return hauteur; }
    double get_l() const { return largeur; }
    double get_p() const { return profondità; }

    virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); }

    //[Méthode pour l'afficheage du texte]
    std::ostream& afficheEnceinte(std::ostream& out) const;
};

//[Surcharge de l'opérateur externe]
std::ostream& operator<<(std::ostream& out, const Enceinte& e);






