#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>

namespace vente{

  class Produit{

    public :
    //Constructeurs de la classe Produit
    Produit(string name);
    Produit(string name, int quantity, double price);
    Produit(string name, string description, int quantity, double price);

    //Accesseurs des attributs de la classe Produit
    void setDescription(string description);
    void setPrice(double price);
    void setQuantity(int quantity);

    string getName();
    string getDescription();
    int getQuantity();
    double getPrice();

    

    private :
    //Nom du produit
    string _name;
    //Description du produit
    string _description;
    //Quantité disponible en stock
    int _quantity;
    //Prix unitaire du produit TTC
    double _price;

  };
}

#endif
