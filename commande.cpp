#include "commande.h"

namespace vente{

  Commande::Commande(int numero,Client client) : _numero(numero), _client(client), _statut(Statut::EnAttente){

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

  std::string Client::display() const{
    std::string outstring;
    outstring += std::to_string(getNumero());
    for (int i= 0;i<14 - int(std::to_string(getNumero ()).length());i++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
      outstring += " ";
    }
    outstring += getClient().getName()+ " " + getClient().getFirstName();
    for (int i= 0;i<58 - int(getClient().getName().length()+ getClient().getFirstName().length());i++){ //Pour la taille de la colone moins celle du champs, on ajoute des espaces
      outstring += " ";
    }
    return(outstring);
  }

}
