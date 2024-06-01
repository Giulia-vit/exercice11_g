#include "test.h"
#include <iostream>
#include <array>
#include <string>
using namespace std;


//Test pour les sommes addition + substraction + produit vectoriel 
void Test_Add_Sub_ProdVect(Vecteur3D const& vect1, Vecteur3D const& vect2,  std::string const& command){
    Vecteur3D vect3;
    char operateur('g');


    if (command == "addition") {
        vect3=vect1+vect2;
        operateur = '+';
    } else if (command == "substraction") {
        vect3= vect1-vect2;
        operateur = '-';
    } else if (command == "prod_vect") {
        vect3 = vect1^vect2; 
        operateur = 'x'; 
    }else{
        cout << "[Attention, entrer la commande " << command << " n'est pas juste]" << endl;
    }

    cout << "("<< vect1 << ") " << operateur << " ("<<vect2<< ") = ("<<vect3<< ")"<<endl;

    
}


//Test pour multiplication par un scalaire

void Test_Normes(Vecteur3D const& vect, std::string const& command){

    if(command == "norme"){
        double norme = vect.norme();
            cout << "||"<<vect<<"|| = " << norme << endl;
    }else if(command == "norme2"){
        double norme2 = vect.norme2();
            cout << "||"<<vect<<"|| = " << norme2 << endl;
    }else{
        cout << "[Attention, entrer la commande " << command << " n'est pas juste]" << endl;
    }
}

void Test_Produit(Vecteur3D const& vect1, Vecteur3D const& vect2, std::string command, double val) {
    Vecteur3D vect3;

    if (command == "mult") {
        vect3=val*vect1;
        cout << val << "*("<<vect1<< ") = ("<<vect3<< ")" << endl;

    } else if (command == "prod_scalaire") {
        
        double prod_scal = vect1.prod_scal(vect2); 
        cout << "("<<vect1<< ")^("<<vect2<< ") = " << prod_scal << endl;
    }else{
        cout << "[Attention, entrer la commande " << command << " n'est pas juste]" << endl;
    }
}






