#include "magasin.h"
#include "produit.h"
#include <iomanip>

using vente::Magasin;
using vente::Produit;
using vente::Client;

int main()
{
	srand ( time(NULL) );
	Magasin easyStore;
	Produit PS4("Playstation 4", "Console de jeu Playstation", 12, 399.99);
	Produit PS5("Playstation 5", "Console de jeu Playstation", 10, 499.99);
	Produit PS6("Playstation 6", "Console de jeu Playstation", 10, 699.99);
	Produit PSVR("Playstation VR", "Casque de realité vituelle", 3, 299.99);
	easyStore.addCustomer("Jean-Michel","Blanquer");
	easyStore.addCustomer("Frederique","Vidal");
	easyStore.addCustomer("Jean","Castex");
	easyStore.addCustomer("Emmanuel","Macron");

	easyStore.addProduct(PS4);
	easyStore.addProduct(PS5);
	easyStore.addProduct(PS6);
	easyStore.addProduct(PSVR);
	easyStore.displayAllProducts();
	easyStore.addProductCart("Playstation 4","Jean-Michel","Blanquer");
	easyStore.addProductCart("Playstation 5","Jean-Michel","Blanquer");
	easyStore.addProductCart("Playstation 5","Frederique","Vidal");
	easyStore.addProductCart("Playstation 6","Frederique","Vidal");
	easyStore.addProductCart("Playstation 4","Emmanuel","Macron");
	easyStore.updateProductQuantityCart("Playstation 4",3,"Jean-Michel","Blanquer");
	easyStore.addOrder("Emmanuel","Macron");
	easyStore.addOrder("Jean-Michel","Blanquer");
	easyStore.addOrder("Frederique","Vidal");
	easyStore.displayOrders();
	easyStore.addProductCart("Playstation VR","Jean-Michel","Blanquer");
	easyStore.addOrder("Jean-Michel","Blanquer");
	easyStore.displayOrdersFromCustomer("Jean-Michel","Blanquer");
	easyStore.validateCommande(easyStore.getOrders().at(1).getNumero());
	easyStore.displayOrders();
	easyStore.displayAllProducts();

	easyStore.validateCommande(easyStore.getOrders().at(0).getNumero());
	easyStore.displayOrders();
	easyStore.displayAllProducts();

}