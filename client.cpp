#include "client.h"

namespace vente{

  Client::Client(int id, Magasin shop) : _id(id), _name(""), _firstName(""), _shop(shop){

  }

  Client::Client(int id, std::string name, std::string firstName, Magasin shop) : _id(id), _name(name), _firstName(firstName), _shop(shop){

  }

  void Client::setName(std::string name){
    _name = name;
  }

  void Client::setFirstName(std::string firstName){
    _firstName = firstName;
  }

  void Client::setShop(Magasin shop){
    _shop = shop;
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

  Magasin Client::getShop(){
    return _shop;
  }

  void Client::add(Produit product, int quantity){
    getProducts().push_back(product); //Ajoute le produit au panier
    getProducts().at(getProducts().size()-1).setQuantity(quantity); //Change la quantité par celle choisis par le client
    //supprimer stock magasin

  }

  void Client::clearProducts(){
    m_products.clear();//Vide le vector contenant le panier du client
  }

  void Client::modifyQuantity(Produit product, int quantity){
    int i = 0; //Iterateur pour la position dans le panier

    //Ajouter stock magasin

    for(Produit p : getProducts()){ //Pour chaque produit du panier
      if(p.getName().compare(product.getName()) == 0){ //Si le produit est celui à supprimer
        p.setQuantity(quantity); //Modifie la quantité
      }
      i++;
    }
  }

  void Client::deleteProduct(Produit product){
    int i = 0; //Iterateur pour la position dans le panier

    //Ajouter stock magasin

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
    return(getFirstName() + " " + getName() + "\n" + "n° " + std::to_string(getID()) + "\nA dans son panier : \n" );
  }

}
