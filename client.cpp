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

  void Client::add(Produit product){
    m_products.push_back(product); //Ajoute le produit au panier
   
  }

  void Client::clearProducts(){
    //Gestion des stocks depuis la classe Magasin
    m_products.clear();//Vide le vector contenant le panier du client
  }

  void Client::modifyQuantity(Produit product, int quantity){
    int i = 0; //Iterateur pour la position dans le panier
    //Gestion des stocks depuis la classe Magasin
    for(Produit p : getProducts()){ //Pour chaque produit du panier
      if(p.getName().compare(product.getName()) == 0){ //Si le produit est celui à supprimer
        p.setQuantity(quantity); //Modifie la quantité
      }
      i++;
    }
  }

  void Client::deleteProduct(Produit product){
    int i = 0; //Iterateur pour la position dans le panier
    //Gestion des stocks depuis la classe Magasin
    for(Produit p : getProducts()){ //Pour chaque produit du panier
      if(p.getName().compare(product.getName()) == 0){ //Si le produit est celui à supprimer
        getProducts().erase(getProducts().begin() + i); //Supprime le produit du panier
      }
      i++;
    }
  }

  std::ostream& operator << (std::ostream &flux, const Client& c){
    flux << c.display(); //Surcharge de l'opérateur
    return flux;
  }

  std::string Client::display() const{
    std::string outstring;
    outstring += std::to_string(getID());
    for (int i= 0;i<14 - int(std::to_string(getID()).length());i++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
      outstring += " ";
    }
    outstring += getName()+ " " +getFirstName();
    for (int i= 0;i<58 - int(getName().length()+getFirstName().length());i++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
      outstring += " ";
    }
    return(outstring);
  }

}
