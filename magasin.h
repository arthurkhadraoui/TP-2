#ifndef MAGASIN_H
#define MAGASIN_H

#include <vector>
#include "produit.h"
#include "client.h"
#include "commande.h"

namespace vente{

	class Magasin {
		
		public:
			//Constructeur de la classe Magasin
			Magasin();

			//Accesseur des attributs de la classe Magasin
			std::vector<Commande> getOrders() const;

		//Fonctionnalités liées aux produits
			//Ajoute un produit dans le stock du magasin
			void addProduct(std::string name, std::string description, int quantity, double price);
			//Modifie la quantité d'un produit dans le stock du magasin
			void updateQuantity(std::string prodname, int quantity);
			//Affiche tous les produits du stock du magasin
			void displayAllProducts() const;
			//Affiche un produit en particulier du stock du magasin
			void displayProduct(std::string prod);

		//Fonctionnalités liées aux clients
			//Vérifie l'existance de l'id passé en paramètre
			bool checkUids(int testnb);
			//Ajoute un client dans la liste des clients du magasin
			void addCustomer(std::string prenom, std::string nom);
			//Affiche tous les clients du magasin
			void displayCustomers() const;
			//Affiche les information du client spécifié par son nom et prénom
			void displayCustomer(std::string nprenom, std::string nom);
			//Affiche les information du client spécifié par son id
			void displayCustomer(int uid);

		//Fonctionnalités liées aux commandes
			//Vérifie l'existance du numéro de commande passé en paramètre
			bool checkOrderNum(int testnb);
			//Ajoute une commande au magasin
			void addOrder(std::string prenom, std::string nom);
			//Valide une commande du magasin
			void validateCommande(int orderNum);
			//Chage le statut d'une commande du magasin
			void switchStatuts(int orderNum, Commande::Statut s);
			//Affiche toutes les commandes du magasin
			void displayOrders();
			//Affiche la commande d'un client spécifié par son nom et prénom
			void displayOrdersFromCustomer(std::string prenom, std::string nom);

		//Fonctionnalités liées aux paniers des clients
			//Ajoute un produit à la commande du client spécifié par son nom et prénom
			void addProductCart(std::string nproduit, std::string prenom, std::string nom);
			//Ajoute un produit à la commande du client spécifié par son id
			void addProductCart(std::string nproduit,int uid);
			//Supprime un produit de la commande d'un client spécifié par son nom et prénom
			void removeProductCart(std::string nproduit, std::string prenom, std::string nom);
			//Modifie la quantité d'un produit dans la commande d'un client spécifié par son nom et prénom
			void updateProductQuantityCart(std::string nproduit,int quantity ,std::string prenom, std::string nom);
			//Vide la commande d'un client spécifié par son nom et prénom
			void clearCart(std::string prenom, std::string nom);
			//Charge la liste des clients contenu dans un fichier de sauvegarde
			void loadCustomers();

		private:
			//Liste des produits en stock dans le magasin
			std::vector<Produit> m_products;
			//Liste des clients connus du magasin
			std::vector<Client> m_clients;
			//Liste des id des clients du magasin
			std::vector<int> m_uids;
			//Liste des commandes passées dans le magasin
			std::vector<Commande> m_orders;
			//Liste des numéros des commandes passées dans le magasin
			std::vector<int> orders_num;
	};
}
#endif
