#include "magasin.h"
#include "produit.h"
#include "client.h"
#include <iostream>
#include <algorithm>

namespace vente {
	Magasin::Magasin(){}

	void Magasin::addProduct(Produit produit){
		m_products.push_back(produit);
	}

	void Magasin::displayAllProducts() const {
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
		std::cout<<"|Produits";
		for (int i=0; i<65 ;i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|Name             Description                       Quantity      Price   |"<<std::endl;

		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		for(int i=0; i<int(m_products.size());i++){
			std::cout<<"|";
			std::cout<<m_products.at(i);
			std::cout<<"|";
			std::cout<<std::endl;
		}
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
	}

	void Magasin::displayProduct(std::string name){
		auto it = m_products.begin();
 			it = std::find_if(it, m_products.end(),
 			[name](const Produit produit) {
 				return produit.getName()==name;
 			});
 		int index = std::distance(m_products.begin(), it);
 		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
		std::cout<<"|Details du produit";
		for (int i=0; i<55 ;i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|Name             Description                       Quantity      Price   |"<<std::endl;

		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
			std::cout<<"|";
			std::cout<<m_products.at(index);
			std::cout<<"|";
			std::cout<<std::endl;

		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
	}

	void Magasin::updateQuantity(std::string prodname, int quantity){
		auto it = m_products.begin();
 			it = std::find_if(it, m_products.end(),
 			[prodname](const Produit produit) {
 				return produit.getName()==prodname;
 			});
 		int index = std::distance(m_products.begin(), it);
 		m_products.at(index).setQuantity(quantity);
	}

	void Magasin::addCustomer(Client client){
		m_clients.push_back(client);
	}

	void Magasin::displayCustomers(){
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
		std::cout<<"|Clients";
		for (int i=0; i<66 ;i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|ID            Full name                                                  |"<<std::endl;
		for(int i=0; i<int(m_clients.size());i++){
			std::cout<<"|";
			std::cout<<m_clients.at(i);
			std::cout<<"|";
			std::cout<<std::endl;
		}
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
	}

	void Magasin::validatesCommande(Commande c){
			c.setStatut(Statut::Valide);
		}

	void Magasin::switchStatuts(Commande c, Statut s){
			c.setStatut(s);
		}
	}

	}

	}
