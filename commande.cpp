#include "commande.h"

namespace vente{

  Commande::Commande(int numero,Client client) : _numero(numero), _client(client), _statut(Statut::EnAttente){
    for (int i=0;i<int(client.getProducts().size());i++){
      m_products.push_back(client.getProducts().at(i));
      _productQuantity.push_back(client.getProductsQuantity().at(i));
    }
    client.clearProducts();
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
    std::string outstring;
    outstring += std::to_string(getNumero());
    for (int i= 0;i<12 - int(std::to_string(getNumero ()).length());i++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
      outstring += " ";
    }
    outstring += getClient().getName()+ " " + getClient().getFirstName();
    for (int i= 0;i<24 - int(getClient().getName().length()+ getClient().getFirstName().length());i++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
      outstring += " ";
    }
    outstring += _enumVal.at(getStatut());
    for (int i= 0;i<16 - int(_enumVal.at(getStatut()).length());i++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
      outstring += " ";
    }
    outstring+=getProducts().at(0).getName();
    for (int i= 0;i<15 - int(getProducts().at(0).getName().length());i++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
      outstring += " ";
    }
    outstring+="(";
        outstring+= std::to_string(_productQuantity.at(0));
        outstring+=")";
        for (int j= 0;j<3 - int(std::to_string(_productQuantity.at(0)).length());j++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
         outstring += " ";
        }
    outstring+="|";

    if(getProducts().size()>1){
      for (int i=1; i<int(getProducts().size());i++){
        outstring+="\n";
        outstring+="|";
        for (int j= 0;j<66 - int(getProducts().at(i).getName().length());j++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
          outstring += " ";
        }
        outstring+=getProducts().at(i).getName();
        for (int j= 0;j<15 - int(getProducts().at(i).getName().length());j++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
         outstring += " ";
        }
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
