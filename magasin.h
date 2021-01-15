#ifndef MAGASIN_H
#define MAGASIN_H
#include <vector>

#include "produit.h"
#include "client.h"
#include "commande.h"


namespace vente{
	class Magasin {
	private:
		std::vector<Produit> m_products;
		std::vector<Client> m_clients;
		std::vector<int> m_uids;
		//std::vector<Order*> m_orders;
	public:
		Magasin();
		void addProduct(Produit produit);
		void displayAllProducts() const;
		void displayProduct(std::string prod);
		void updateQuantity(std::string prodname, int quantity);

		bool checkUids(int testnb);
		void addCustomer(std::string prenom, std::string nom);
		void displayCustomers();
		void displayCustomer(std::string nprenom, std::string nom);
		void displayCustomer(int uid);

		void validateCommande(Commande c);//Permet de valider une commande
		void switchStatuts(Commande c, Commande::Statut s);//Permet de changer le statut d'une commande


		void addProductCart(std::string produit, std::string prenom, std::string nom);
		//void removeProductCart(std::string produit, std::string prenom, std::string nom);
		//void updateProductQuantityCart(std::string produit,int quantity ,std::string prenom, std::string nom);


	};
}



#endif
