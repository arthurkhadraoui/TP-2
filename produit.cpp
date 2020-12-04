#include "produit.h"
#include <iomanip>

namespace vente{

  Produit::Produit(std::string name) : _name(name), _description(""), _quantity(0), _price(0){

  }

  Produit::Produit(std::string name, int quantity, double price) : _name(name), _description(""), _quantity(quantity), _price(price){

  }

  Produit::Produit(std::string name, std::string description, int quantity, double price) : _name(name), _description(description), _quantity(quantity), _price(price){

  }

  void Produit::setDescription(std::string description){
    _description = description;
  }

  void Produit::setQuantity(int quantity){
    _quantity = quantity;
  }

  void Produit::setPrice(double price){
    _price = price;
  }

  std::string Produit::getName() const{
    return _name;
  }

  std::string Produit::getDescription() const{
    return _description;
  }

  int Produit::getQuantity() const{
    return _quantity;
  }

  double Produit::getPrice() const{
    return _price;
  }

  std::string Produit::display() const{
    return (getName() + "\n" + getDescription() + "\n" + std::to_string(getPrice()) + "€ | " + std::to_string(getQuantity()) + " exemplaire\n");
  }

  std::ostream& operator << (std::ostream &flux, const Produit& p){
    flux << p.display();
    return flux;
  }

}
