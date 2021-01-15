#include "commande.h"

namespace vente{

  Commande::Commande(int numero,Client client) : _numero(numero), _client(client), _statut(Statut::EnAttente){

  }

  void Commande::setStatut(Statut s){
    _statut = s;
  }

  Statut Commande::getStatut() const{
    return _statut;
  }

  int Commande::getNumero() const{
    return _numero;
  }

  Client Commande::getClient() const{
    return _client;
  }

  vector<Produit> Commande::getProducts() const{
    return m_products;
  }

  std::string Client::display() const{
    return(std::to_string(getNumero()) + " " + getClient() + "\n");
  }

}
