#pragma once
#include "Particule.h"
#include <iostream>


class Argon : public Particule{
   private:
   const double constanteSpecifique;

	
   public:	


   Argon(Vecteur3D  p, Vecteur3D  v, double m, std::string name,  double const& constante = 208) : Particule(p,v,m,name), constanteSpecifique(constante){}
   virtual Argon* clone() const override;
   
   virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); }
};
	
