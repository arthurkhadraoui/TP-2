#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <vector>
#include "produit.h"
#include "magasin.h"

namespace vente{

    class Client{

      public :
      //Constructeurs de client
      Client(int id, Magasin shop);
      Client(int id, std::string name, std::string firstName, Magasin shop);

      //Accesseurs des attrbuts du client
      void setName(std::string name);
      void setFirstName(std::string firstName);
      void setShop(Magasin shop);

      int getID() const;
      std::string getName() const;
      std::string getFirstName() const;
      std::vector<Produit> getProducts() const;
      Magasin getShop();

      //Méthode d'ajout d'un produit "product" dans le panier en "quantity" quantité
      void add(Produit product, int quantity);
      //Méthode qui vide le panier
      void clearProducts();
      //Méthode qui modifie la quantité d'un produit du panier
      void modifyQuantity(Produit product, int quantity);
      //Méthode qui supprime un élément du panier
      void deleteProduct(Produit product);

      //Surcharge de l'opérateur << pour l'affichage
      friend std::ostream& operator << (std::ostream &flux, const Client& c);

      private :
      //Identifiant du client
      int _id;
      //Nom du client
      std::string _name;
      //Prénom du client
      std::string _firstName;
      //Panier de client (liste de produit)
      std::vector<Produit> m_products;
      //Magasin dans lequel se trouve le Client
      Magasin _shop;

      //fonction d'affichage pour la surcharge d'opérateur
      std::string display() const;

    };
}

#endif
