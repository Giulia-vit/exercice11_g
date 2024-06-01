#pragma once
#include "Particule.h"
#include <string>
using namespace std;


class Neon :public Particule{	
    private:
    const double constanteSpecifique;


    public:	

        Neon(Vecteur3D  p, Vecteur3D  v, double m, std::string name, double const& constante = 412) : Particule(p,v,m,name), constanteSpecifique(constante){}


        virtual Neon* clone() const override;
 
        virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); }
};

	
