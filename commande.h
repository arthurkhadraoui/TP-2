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

      //Constructeur de la classe Commande
      Commande(int numero,Client client);

      //Accesseurs des attributs de la classe Commande
      void setStatut(Statut s);

      Statut getStatut() const;
      Client getClient() const;
      int getNumero() const;
      std::vector<Produit> getProducts() const;
      std::vector<int> getProductQuantity() const;

      //Surcharge de l'opérateur << pour afficher le produit
      friend std::ostream& operator << (std::ostream &flux, const Commande& c);

    private:
      //Numéro de commande
      int _numero;
      //Client qui à passé la Commande
      Client _client;
      //Produit(s) acheté par le client
      std::vector<Produit> m_products;
      //Quantité d'un même produit acheté par le client
      std::vector<int> _productQuantity;
      //Statut de la commande
      Statut _statut;

      //Version string des statuts pour gérer l'affichage
      std::vector<std::string> _enumVal={"Valide","En Attente","Refuse"};

      //fonction d'affichage pour la surcharge d'opérateur
      std::string display() const;
  };
}
#endif
