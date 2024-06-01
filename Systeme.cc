#include "Systeme.h"
#include "testrandom.h"

#include <iostream>
using namespace std;



Systeme::Systeme() : collectionParticules() , encSys(){} //Est-ce qu'on doit le tenir?
//[Constructeur par default du Systeme]
Systeme::Systeme(vector<Particule*> particules, double hauteur = 20, double largeur = 20, double profondeur = 20) :  collectionParticules(particules) ,encSys(hauteur,largeur,profondeur){}

//[Constructeur pour initialiser de maniére indépedente la température]
Systeme::Systeme(double t): temperature(t){}

//[Méthode pour afficher de maniére textuelle l'entiéreté de notre Systeme]
ostream& Systeme::afficheSysteme(ostream& out) const{

    if(collectionParticules.size() == 0){
		out << "[Il n'y a pas de particules]";	
	}else if(collectionParticules.size() == 1){
        out << "Le systeme est constitué de la particule suivante : " << endl;
    }else{
        out << "Le systeme est contitué de " << collectionParticules.size() << " particules suivantes : " << endl;
    }

//[Grace à la surcharge de l'opérateur d'afficheage on peut afficher directement les valeures des particules]
    for(auto const& part : collectionParticules){
		out << *part << endl;	
	} 

    return out;
}



void Systeme::ajouteParticule(const Particule& particuleAjoute) {

			Particule* nouvelleParticule = particuleAjoute.clone(); 

			collectionParticules.push_back(nouvelleParticule);

}


void Systeme::ajouteParticulerandom(const Particule& particuleAjoute, unsigned int nbp) {

    for (unsigned int i = 0; i < nbp; ++i) {

        Particule* nouvelleParticule = particuleAjoute.clone(); 

        nouvelleParticule->setrandompart(encSys, tirage, temperature); 

        collectionParticules.push_back(nouvelleParticule); 
    }
}



void Systeme::effacerParticule(){

    for(auto const& particule: collectionParticules){
        delete particule;
    	collectionParticules.clear();
    }

}




void Systeme::evolue(double const& dt){

	  unsigned int nbchocs(0);

	  for(int k(0); k < 10; ++k){

		 	for (size_t j(0); j < collectionParticules.size() ;++j){

                collectionParticules[j]->evolue(dt);

				collectionParticules[j]->gerer_parois(encSys.get_h(),encSys.get_l(),encSys.get_p(),j+1);


				for (size_t i(0); i<collectionParticules.size() ;++i){


					if ((i != j) and ((collectionParticules[j])->rencontre_particules(*collectionParticules[i])==true)) {
						    ++nbchocs;

							cout<<"La particule" << j<<" entre en collision avec une autre particule."<<endl;

							cout<<"avant le choc"<<endl;

							(collectionParticules[j])->affiche_collision((*collectionParticules[i]),j+1,i+1);

							cout<<"après le choc"<<endl;

							(collectionParticules[j])->gerer_rencontre(*collectionParticules[i],tirage,nbchocs);

							(collectionParticules[j])->affiche_collision((*collectionParticules[i]),j+1,i+1);
							}
			
				 }
		    }
			cout<< *this<<endl;

	  }

	 }	



      
ostream& operator<<(ostream& out, const Systeme& systeme){
    return systeme.afficheSysteme(out);
}







