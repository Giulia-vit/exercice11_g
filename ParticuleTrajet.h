#pragma once
#include "Particule.h"
#include "Vecteur3D.h"
#include <vector>
#include <string>

class ParticuleTrajet : public  Particule {
private:
    //[Contient un ensemble de positions qui ont été ajouté à partir de la méthode evolue]
    std::vector<Vecteur3D*> ensemblePositions;

public:
    //[Meme constructeur de Particule]
    using Particule::Particule;

    virtual void dessine_sur(SupportADessin& support) override {support.dessine(*this);}

    //[Méthode évolue différente des autres particules car à chaque évolution on ajoute la position au vector]
    void evolue(double const& dt) override;

    std::ostream& afficheParticule(std::ostream& out) const override;

    //[Getter de la collection de positions pour pouvoir itérer sur toutes les positions dans la méthode dessine(ParticuleTrajet) donc d'afficher les segments ]
    std::vector<Vecteur3D*> getSysteme() const { return ensemblePositions; }
    
    virtual ParticuleTrajet* clone() const override;

};