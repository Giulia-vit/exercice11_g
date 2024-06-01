#include "Systeme.h"
#include "argon.h"
#include "neon.h"
//#include "helium.h"
#include <iostream>
#include <cmath>

using namespace std;


int main(){
   // Helium p1 ({1,1,1},{0,0,0},4.002602, "Helium");
    Neon p2 ({1,18.5,1},{0,0.2,0}, 20.1797, "Neon");
    Argon p3 ({1,1,3.1},{0,0,-0.5},39.948, "Argon"); 


    Systeme systeme1;
    //systeme1.ajouteParticule(p1);
    systeme1.ajouteParticule(&p2);
    systeme1.ajouteParticule(&p3);

    cout << systeme1;
    cout<<"Lancement de la simulation"<<endl;
	cout<<"==========----------"<<endl;
	systeme1.evolue(1);


    return 0;


  


};
