#pragma once
#include "Vecteur3D.h"
#include <iostream>
#include <array>
#include <string>
#include <cmath>
#include "testrandom.h"
#include "support_a_dessin.h"
#include "dessinable.h"


class Systeme;


class Particule : public Dessinable{

  protected:

    Vecteur3D position;
    Vecteur3D vitesse;
    double masse;
    std::string name; 
    GenerateurAleatoire tirage;
    
  public:
  static constexpr double EPSILON = 1;  
  
  //[Constructer]
  Particule(Vecteur3D  p, Vecteur3D  v, double m, std::string name);

  //[Constructeur de copie]
  Particule(const Particule& particuleCopie);

  bool rencontre_particules(Particule& p,const double eps = EPSILON);

	void affiche_collision(Particule& p,unsigned int const& a,unsigned int const& b);

  void gerer_parois(double hauteur, double largeur,double profondeur, unsigned int n);

  void setrandompart(const Enceinte& e, GenerateurAleatoire& t, double temperature) ;
   
	void gerer_rencontre(Particule& p, GenerateurAleatoire t, unsigned int c=0);

  Vecteur3D tirage_v0(double norme, GenerateurAleatoire t) ;

	//[Méthode pour obtenir la position de la particule, elle est appellé dans le fichier vue_opengl.cc pour dessiner la particule]
	Vecteur3D getp() const {return position;}

  //[Méthode virtuelle qui permet de cloner une particule, 
  //méthode appellé par la classe Systeme dans la méthode ajouteParticuleRandom, 
  //ca permet de copier la particule passé en argument à ajouteParticuleRandom et la modifeir à chaque itération sans modifier celle de départ]
  virtual Particule* clone() const;
  
  //[Méthode evolue définit en virtual car l'evolution d'une sousParticule sera différente]
  virtual void evolue(double const& dt); 

	virtual void dessine_sur(SupportADessin& support) override{ support.dessine(*this); }
  virtual std::ostream& afficheParticule(std::ostream& out) const ;

  virtual ~Particule(){}

};

std::ostream& operator<<(std::ostream& out, const Particule& p);




