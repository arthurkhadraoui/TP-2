#ifndef COMMANDE_H
#define COMMANDE_H

#include "produit.h"
#include "client.h"
namespace vente{

	class Commande
	{
	public:
		enum Status{
			Pending,
			Done,
			Cancelled
		};

		Commande(Client client, Produit produit, Status status);
	private:
		 Client _customer;
		 std::vector<Produit> bought_products;
		
		
	};
}



#endif