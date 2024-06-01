
#include "textviewer.h"
#include "argon.h"
#include "neon.h"
#include "Systeme.h"
#include <iostream>

using namespace std;


 
int main()
{
  /* Nous voulons un support à dessin :                          *
   * ici un TextViewer qui écrit sur cout                        */
  TextViewer ecran(cout);
  Systeme c;

 
 

 
  // Nous voulons un contenu à dessiner
  Argon a({1,18,5.1},{0,0.2,0},20.1797,"argon");
  Neon b({1,1,3.1},{0,0,-0.5},39.948,"neon");
  c.ajouteParticule(&a);
  c.ajouteParticule(&b);

  
 
  // Nous dessinons notre contenu  sur notre support à dessin précédent
  c.dessine_sur(ecran);
 
 
  return 0;
}
