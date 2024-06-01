#include "ParticuleTrajet.h"
#include "Particule.h"
#include <iostream>
using namespace std;



void ParticuleTrajet::evolue(double const&  dt) {
    Particule::evolue(dt);
    ensemblePositions.push_back(new Vecteur3D(position));
}
    
ostream& ParticuleTrajet::afficheParticule(std::ostream& out) const {
    out <<"Particule avec Trajet"<< "pos : " << position << " v : " << vitesse << " m : " << masse << endl;
    return out;
}

ParticuleTrajet* ParticuleTrajet::clone() const  {
    return new ParticuleTrajet(*this);
}
