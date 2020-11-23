#include "magasin.h"
#include "produit.h"

using vente::Magasin;
using vente::Produit;

int main()
{
	Magasin easyStore;
	Produit PS4("Playstation 4", "Console de jeu Playstation", 12, 399.99);
	easyStore.addProduct(PS4);
	std::cout<<PS4<<endl;
	easyStore.displayAllProducts();
	return 0;
}