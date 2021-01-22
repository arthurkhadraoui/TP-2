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
		std::vector<Commande> m_orders;
		std::vector<int> orders_num;
	public:
		Magasin();
		void addProduct(std::string name, std::string description, int quantity, double price);
		void displayAllProducts() const;
		void displayProduct(std::string prod);
		void updateQuantity(std::string prodname, int quantity);
		std::vector<Commande> getOrders() const;

		bool checkUids(int testnb);
		void addCustomer(std::string prenom, std::string nom);
		void displayCustomers() const;
		void displayCustomer(std::string nprenom, std::string nom);
		void displayCustomer(int uid);

		void addOrder(std::string prenom, std::string nom);
		bool checkOrderNum(int testnb);
		void validateCommande(int orderNum);//Permet de valider une commande
		void switchStatuts(int orderNum, int s);//Permet de changer le statut d'une commande
		void displayOrders();
		void displayOrdersFromCustomer(std::string prenom, std::string nom);


		void addProductCart(std::string nproduit, std::string prenom, std::string nom);
		void addProductCart(std::string nproduit,int uid);
		void removeProductCart(std::string nproduit, std::string prenom, std::string nom);
		void updateProductQuantityCart(std::string nproduit,int quantity ,std::string prenom, std::string nom);
		void clearCart(std::string prenom, std::string nom);

		void loadCustomers();


		


	};
}



#endif
