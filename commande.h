#ifndef COMMANDE_H
#define  COMMANDE_H
#include <iostream>
#include <string>
#include <vector>
#include "client.h"
#include "produit.h"

namespace vente{

  class Commande{

    public:
      //Enumération des différents statuts possible pour une commande
      enum Statut{
        Valide, EnAttente, Refuse
      };
      //Constructeur
      Commande(int numero,Client client);

      //Accesseurs
      void setStatut(Statut s);

      Statut getStatut() const;
      Client getClient() const;
      int getNumero() const;
      std::vector<Produit> getProducts() const;

      friend std::ostream& operator << (std::ostream &flux, const Commande& c);

    private:
      //Numéro de commande
      int _numero;
      //Client qui à passé la Commande
      Client _client;
      //Produit(s) acheté par le client
      std::vector<Produit> m_products;
      //Statut de la commande
      Statut _statut;

      //fonction d'affichage pour la surcharge d'opérateur
      std::string display() const;
  };

}

#endif
