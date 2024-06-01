#include "Particule.h"
#include "Vecteur3D.h"
#include "Systeme.h"
#include <cmath>
#include <iostream>
#include <array>
using namespace std;



Particule::Particule(const Particule& particuleCopie): position(particuleCopie.position), vitesse(particuleCopie.vitesse), masse(particuleCopie.masse), name(particuleCopie.name){}


Particule::Particule(Vecteur3D  p, Vecteur3D  v, double m, std::string name): position(p), vitesse(v), masse(m), name(name) ,tirage(123456){}


void Particule::evolue(double const& dt){
	Vecteur3D deplacement(dt*vitesse);
	position = position + deplacement;
	
}



ostream& Particule::afficheParticule(ostream& out) const{
    out << name << ": pos : " <<  position << "; v : " << vitesse << "; m : " << masse << endl;
    return out;
}




bool Particule::rencontre_particules(Particule&  p,const double eps){
		int compt(0);
		for (int i(0); i<3; ++i){
		    if (floor(position[i]/eps) == floor(p.position[i]/eps))
		        ++compt;
		}   
		return (compt==3);
	}




ostream& operator <<(ostream& out, const Particule& part) { 
    return part.afficheParticule(out);
}

Particule* Particule::clone() const{
    return new Particule(*this);
}


void Particule::setrandompart(const Enceinte& e, GenerateurAleatoire& t, double temperature){

	position = {t.uniforme(0,e.get_l()), t.uniforme(0,e.get_p()),t.uniforme(0,e.get_h())};
	
	vitesse[0] = t.gaussienne(0.0, sqrt(10 * temperature));
	vitesse[1] = t.gaussienne(0.0, sqrt(10 * temperature));
	vitesse[2] = t.gaussienne(0.0, sqrt(10 * temperature));
}



Vecteur3D Particule::tirage_v0(double norme,GenerateurAleatoire t) {

	    const double L(norme);

	    double z(tirage.uniforme(-L,L));

	    double phi(tirage.uniforme(0,2*M_PI));

        const double r(sqrt(L*L - z*z));

        Vecteur3D v0(r*cos(phi),r*sin(phi),z);

        return v0;
    }

void Particule::gerer_parois(double hauteur, double largeur,double profondeur, unsigned int n){

		 if (position[0] <= 0 || position[0] >= largeur)    vitesse[0] = -vitesse[0];  
		 if (position[1] <= 0 || position[1] >= profondeur) vitesse[1] = -vitesse[1]; 
		 if (position[2] <= 0 || position[2] >= hauteur)    vitesse[2] = -vitesse[2];
	}
	



void Particule::affiche_collision(Particule& p,unsigned int const& a,unsigned int const& b){

		cout<<"part."<<a<<": : pos "<<(*this).position<< " ; v : "<<(*this).vitesse<<endl;
		cout<<"autre"<<b<<": : pos "<<p.position<< " ; v : "<<p.vitesse<<endl;
}




	void Particule::gerer_rencontre(Particule& p, GenerateurAleatoire t, unsigned int c){ ////revoir ttes ces conceptions et ecriture
	
		Vecteur3D vg((masse / (masse + p.masse))*vitesse + (p.masse / (masse + p.masse))*p.vitesse);//comemnt prendre la vitesse de l'instance courante
		    Vecteur3D v1_vg (vitesse-vg);
		    Vecteur3D v0;
		    if (c==1){
		        const double L1(v1_vg.norme());
		        v0={0.5*L1, 0.86603*L1,0};
		        vitesse=vg +v0;
				p.vitesse = vg- masse/p.masse*v0;}
		        
		    else {
		        v0 = tirage_v0(v1_vg.norme(),t);
				vitesse= vg +v0;
				p.vitesse = vg- masse/p.masse*v0;}
	}	





