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
    //Constante pour les taille des colones
    const int NAME_SIZE = 17;
    const int DESCRIPTION_SIZE = 34;
    const int QUANTITY_SIZE = 14;
    const int PRICE_SIZE = 7;

    std::string res = ""; //Variable de résultat

    res += getName(); //Ajout du champs
    for (int i= 0;i<NAME_SIZE - int(getName().length());i++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
      res += " ";
    }
    res += getDescription();
    for (int i= 0;i<DESCRIPTION_SIZE - int(getDescription().length());i++){
      res += " ";
    }
    res += std::to_string(getQuantity());
    for (int i= 0;i<QUANTITY_SIZE - int(std::to_string(getQuantity()).length());i++){
      res += " ";
    }
    res += std::to_string(getPrice());
    for (int i= 0;i<PRICE_SIZE - int(std::to_string(getPrice()).length());i++){
      res += " ";
    }
    
    return res;
  }

  std::ostream& operator << (std::ostream &flux, const Produit& p){
    flux << p.display();
    return flux;
  }

}
