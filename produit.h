#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

namespace vente{

  class Produit{

    public :
    //Constructeurs de la classe Produit
    Produit(std::string name);
    Produit(std::string name, int quantity, double price);
    Produit(std::string name, std::string description, int quantity, double price);

    //Accesseurs des attributs de la classe Produit
    void setDescription(std::string description);
    void setPrice(double price);
    void setQuantity(int quantity);

    std::string getName() const;
    std::string getDescription() const;
    int getQuantity() const;
    double getPrice() const;

    //Surcharge de l'opérateur << pour afficher le produit
    friend std::ostream& operator << (std::ostream &flux, const Produit& p);

    private :
    //Nom du produit
    std::string _name;
    //Description du produit
    std::string _description;
    //Quantité disponible en stock
    int _quantity;
    //Prix unitaire du produit TTC
    double _price;

    //fonction d'affichage pour la surcharge d'opérateur
    std::string display() const;
  };
std::string lastSpaces(Produit p);
}
#endif
