#pragma once
#include <vector>
#include "Particule.h"
#include "Enceinte.h"
#include "dessinable.h"
#include <iostream>
#include <memory>

class Systeme : public Dessinable {

  private:
    //[Ensemble de pointeur sur des particules]
    std::vector <Particule*> collectionParticules;
    
    Enceinte encSys;

    GenerateurAleatoire tirage;

    double temperature;

  public:


    Systeme();

    Systeme(std::vector<Particule*> , double, double, double);


    //[Constructeur pour initialiser que la température]
    Systeme(double);
    
    //[Méthode pour l'afficheage compléte du systeme]
    std::ostream& afficheSysteme(std::ostream&) const;
    
    //[Méthode pour ajouter dynamiquement les particules à notre ensemble de Particules]
    void ajouteParticule(const Particule& particuleAjoute);

    //[Méthode pour ajouter dynamiquement les particules à notre ensemble de Particules de maniére rendom]
    void ajouteParticulerandom(const Particule& particule, unsigned int npb=1);

    //[Méthode pour eliminer dynamiquement les particules de notre ensemble de Particules]
    void effacerParticule();

    //[Méthode pour faire évoluer notre systéme de partiules]
    void evolue(double const& dt);
    
    //[Getter nécessaire pour obtenir l'enceinte du systéme, méthode appelé dans dessine(Systeme) pour la dessine, i.e vue_opengl.cc]
    Enceinte getEnceinte() const {return encSys;}

    //[Getter nécessaire pour obtenir l'ensemble de particules pour iterer et les affichier toutes, méthode appelé dans dessine(Systeme), i.e vue_opengl.cc]
    const std::vector<Particule*>& getVectorParticule() const { return collectionParticules; }   
    
    virtual void dessine_sur(SupportADessin& support) { support.dessine(*this); }

    //[Méthode pour ne pas faire de copies de Systemes]
    Systeme(const Systeme& systemeCopie) = delete;  

    //[Surcharge de l'opérateur d'affection]
    Systeme& operator =(const Systeme& systemeAffectation) = delete;

    //[Destructeur pour effacer directement toutes les particuler]
    ~Systeme(){effacerParticule();}

};

//[Surcharge externe de l'opérateur d'afficheage]
std::ostream& operator<<(std::ostream& , Systeme const& );


