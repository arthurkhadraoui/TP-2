#ifndef MAGASIN_H
#define MAGASIN_H
#include <vector>

#include "produit.h"

namespace vente{
	class Magasin {
	private:
		std::vector<Produit> m_products;
		//std::vector<Client> m_clients;
		
		//std::vector<Order*> m_orders;
	public:
		Magasin();
		void addProduct(Produit produit);
		void displayAllProducts() const;
	};
}



#endif