#include "produit.h"

namespace vente{

  Produit::Produit(string name) : _name(name), _description(""), _quantity(0), _price(0){

  }

  Produit::Produit(string name, int quantity, double price) : _name(name), _description(""), _quantity(quantity), _price(price){

  }

  Produit::Produit(string name, string description, int quantity, double price) : _name(name), _description(description), _quantity(quantity), _price(price){

  }

  void Produit::setDescription(string description){
    _description = description;
  }

  void Produit::setQuantity(int quantity){
    _quantity = quantity;
  }

  void Produit::setPrice(double price){
    _price = price;
  }

  string Produit::getName() const{
    return _name;
  }

  string Produit::getDescription() const{
    return _description;
  }

  int Produit::getQuantity() const{
    return _quantity;
  }

  double Produit::getPrice() const{
    return _price;
  }

  string Produit::display() const{
    return (getName() + "\n" + getDescription() + "\n" + to_string(getPrice()) + "€ | " + to_string(getQuantity()) + " exemplaire\n");
  }

  ostream& operator << (ostream &flux, const Produit& p){
    flux << p.display();
    return flux;
  }

}
