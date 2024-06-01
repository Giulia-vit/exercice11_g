#include <iostream>
#include "Enceinte.h"

using namespace std;

//[Constructeur]
Enceinte::Enceinte(double hauteur, double largeur, double profondeur)
: hauteur(hauteur), largeur(largeur), profondità(profondità) {}

//[Constructeur de copie]
Enceinte::Enceinte(const Enceinte& copie)
    : hauteur(copie.hauteur), largeur(copie.largeur), profondità(copie.profondità) {}


//[Declaration afficheage de l'enceinte]
std::ostream& Enceinte::afficheEnceinte(std::ostream& out) const {
    out << "Hauteur: " << hauteur << ", Largeur: " << largeur << ", Profondeur: " << profondità;
    return out;
}

//[Declaration surcharge externe]
ostream& operator<<(std::ostream& out, const Enceinte& e) {
    return e.afficheEnceinte(out);
}