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

  string Produit::getName(){
    return _name;
  }

  string Produit::getDescription(){
    return _description;
  }

  int Produit::getQuantity(){
    return _quantity;
  }

  double Produit::getPrice(){
    return _price;
  }

  string Produit::display(){
    return (getName() << "\n" << getDescription() << "\n" << getPrice() << "€ | " << getQuantity() << " exemplaire\n");
  }

  ostream& Produit::operator<<(ostrame &flux, Produit const& p){
    p.display();
    return flux;
  }

}
