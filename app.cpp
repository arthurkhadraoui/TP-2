#include "magasin.h"
#include "produit.h"
#include <iomanip>

using vente::Magasin;
using vente::Produit;

int main()
{
	Magasin easyStore;
	Produit PS4("Playstation 4", "Console de jeu Playstation", 12, 399.99);
	Produit PS5("Playstation 5", "Console de jeu Playstation", 0, 499.99);
	easyStore.addProduct(PS4);
	easyStore.addProduct(PS5);
	easyStore.displayAllProducts();
	return 0;
}