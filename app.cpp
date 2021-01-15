#include "magasin.h"
#include "produit.h"
#include <iomanip>

using vente::Magasin;
using vente::Produit;
using vente::Client;

int main()
{
	Magasin easyStore;
	Produit PS4("Playstation 4", "Console de jeu Playstation", 12, 399.99);
	Produit PS5("Playstation 5", "Console de jeu Playstation", 0, 499.99);
	Produit PS6("Playstation 6", "Console de jeu Playstation", 0, 699.99);
	easyStore.addCustomer("Jean-Michel","Blanquer");
	easyStore.addCustomer("Frederique","Vidal");
	easyStore.addCustomer("Jean","Castex");
	easyStore.addCustomer("Emmanuel","Macron");

	easyStore.addProduct(PS4);
	easyStore.addProduct(PS5);
	easyStore.addProduct(PS6);
	easyStore.displayAllProducts();
	easyStore.displayProduct("Playstation 4");
	easyStore.updateQuantity("Playstation 4",PS4.getQuantity()-1);
	easyStore.displayProduct("Playstation 4");
	easyStore.displayCustomers();
	easyStore.displayCustomer("Jean-Michel","Blanquer");


	return 0;
}