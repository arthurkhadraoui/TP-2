#include "magasin.h"
#include "produit.h"
#include "client.h"
#include <iostream>

namespace vente {
	Magasin::Magasin(){}

	void Magasin::addProduct(Produit* produit){
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
		for (int i=0; i<63;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		for(int i=0; i<int(m_products.size());i++){
			std::cout<<"|";
			std::cout<<m_products.at(i)->getName();
			for (int i= 0;i<17-int (m_products.at(i)->getName().length());i++){
				std::cout<<" ";
			}
			std::cout<<m_products.at(i)->getDescription();
			for (int i= 0;i<34-int(m_products.at(i)->getName().length());i++){
				std::cout<<" ";
			}
			std::cout<<"("<<m_products.at(i)->getQuantity()<<")";
			for (int i= 0;i<14-int(std::to_string(m_products.at(i)->getQuantity()).length());i++){
				std::cout<<" ";
			}
			std::cout<<m_products.at(i)->getPrice()<<"€";
			for (int i= 0;i<7-int(std::to_string(m_products.at(i)->getQuantity()).length());i++){
				std::cout<<" ";
			}
			std::cout<<std::endl;
		}
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
	}
}