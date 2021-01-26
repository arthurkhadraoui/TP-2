#include "client.h"

namespace vente{

  Client::Client(int id) : _id(id), _name(""), _firstName(""){

  }

  Client::Client(int id, std::string name, std::string firstName) : _id(id), _name(name), _firstName(firstName){

  }

  void Client::setName(std::string name){
    _name = name;
  }

  void Client::setFirstName(std::string firstName){
    _firstName = firstName;
  }

  std::string Client::getName() const{
    return _name;
  }

  std::string Client::getFirstName() const{
    return _firstName;
  }

  int Client::getID() const{
    return _id;
  }

  std::vector<Produit> Client::getProducts() const{
    return m_products;
  }

  std::vector<int> Client::getProductsQuantity() const{
    return _productQuantity;
  }

  void Client::add(Produit product){
    m_products.push_back(product); //Ajout du produit au panier
    _productQuantity.push_back(1); //Quantité du produit mise à 1 par défaut
  }

  void Client::clearProducts(){
    //Gestion des stocks depuis la classe Magasin
    m_products.clear(); //Vide le vector contenant le panier du client
    _productQuantity.clear(); //Réinitialise les quantités
  }

  void Client::modifyQuantity(Produit product, int quantity){
    //Gestion des stocks depuis la classe Magasin
    int i = 0; //Iterateur pour la position dans le panier
    for(Produit p : getProducts()){ //Pour chaque produit du panier
      if(p.getName().compare(product.getName()) == 0){ //Si le produit est celui dont on souhaite modifier la quantité
        _productQuantity.at(i)=quantity; //On modifie la quantité
      }
      i++;
    }
  }

  void Client::deleteProduct(Produit product){
    //Gestion des stocks depuis la classe Magasin
    int i = 0; //Iterateur pour la position dans le panier
    for(Produit p : getProducts()){ //Pour chaque produit du panier
      if(p.getName().compare(product.getName()) == 0){ //Si le produit est celui à supprimer
        m_products.erase(m_products.begin() + i); //On supprime le produit du panier
        _productQuantity.erase(_productQuantity.begin() + i); //On réinitialise la quantité
      }
      i++;
    }
  }

  std::ostream& operator << (std::ostream &flux, const Client& c){
    flux << c.display(); //Surcharge de l'opérateur
    return flux;
  }

  std::string Client::display() const{
    std::string outstring; //Variable de résultat
    outstring += std::to_string(getID()); //Ajout du champs ID
    for (int i= 0;i<14 - int(std::to_string(getID()).length());i++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
      outstring += " ";
    }
    outstring += getName()+ " " +getFirstName(); //Ajout des champs nom et prénom
    for (int i= 0;i<58 - int(getName().length()+getFirstName().length());i++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
      outstring += " ";
    }
    return(outstring);
  }
}
