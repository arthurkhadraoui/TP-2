#include "commande.h"

namespace vente{

  Commande::Commande(int numero,Client client) : _numero(numero), _client(client), _statut(Statut::EnAttente){
    for (int i=0;i<int(client.getProducts().size());i++){ //Pour chauqe produit dans le panier du client
      m_products.push_back(client.getProducts().at(i)); //On ajoute le produit à la commande
      _productQuantity.push_back(client.getProductsQuantity().at(i)); //On ajoute la quantité à la commande
    }
    client.clearProducts(); //On vide le panier du client
  }

  void Commande::setStatut(Statut s){
    _statut = s;
  }


  Commande::Statut Commande::getStatut() const{
    return _statut;
  }


  int Commande::getNumero() const{
    return _numero;
  }

  Client Commande::getClient() const{
    return _client;
  }

  std::vector<Produit> Commande::getProducts() const{
    return m_products;
  }

  std::vector<int> Commande::getProductQuantity() const{
    return _productQuantity;
  }

  std::string Commande::display() const{
    std::string outstring; //Variable de résultat
    outstring += std::to_string(getNumero()); //Ajout du champs Numéro
    for (int i= 0;i<12 - int(std::to_string(getNumero ()).length());i++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
      outstring += " ";
    }
    outstring += getClient().getName()+ " " + getClient().getFirstName(); //Ajout des champs nom et prénom
    for (int i= 0;i<24 - int(getClient().getName().length()+ getClient().getFirstName().length());i++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
      outstring += " ";
    }
    outstring += _enumVal.at(getStatut()); //Ajout du statut au format string
    for (int i= 0;i<16 - int(_enumVal.at(getStatut()).length());i++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
      outstring += " ";
    }
    outstring+=getProducts().at(0).getName(); //Ajout du produit
    for (int i= 0;i<15 - int(getProducts().at(0).getName().length());i++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
      outstring += " ";
    }
    //Ajout de la quantité du produit
    outstring+="(";
        outstring+= std::to_string(_productQuantity.at(0));
        outstring+=")";
        for (int j= 0;j<3 - int(std::to_string(_productQuantity.at(0)).length());j++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
         outstring += " ";
        }
    outstring+="|";

    if(getProducts().size()>1){ //Si il y a plus d'un produit dans la commande
      for (int i=1; i<int(getProducts().size());i++){
        outstring+="\n";
        outstring+="|";
        for (int j= 0;j<66 - int(getProducts().at(i).getName().length());j++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
          outstring += " ";
        }
        outstring+=getProducts().at(i).getName(); //Ajout du nom du produit
        for (int j= 0;j<15 - int(getProducts().at(i).getName().length());j++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
         outstring += " ";
        }
        //Ajout de la quantité du produit
        outstring+="(";
        outstring+= std::to_string(_productQuantity.at(i));
        outstring+=")";
        for (int j= 0;j<3 - int(std::to_string(_productQuantity.at(i)).length());j++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
         outstring += " ";
        }
        outstring+="|";
    }
  }
  return(outstring);
}

std::ostream& operator << (std::ostream &flux, const Commande& c){
    flux << c.display(); //Surcharge de l'opérateur
    return flux;
  }
}
