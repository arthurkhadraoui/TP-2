#ifndef VIEWPRODUIT_H
#define VIEWCPRODUIT_H

#include "observer.h"
#include "view.h"
#include "controller.h"
#include "magasin.h"

class ViewProduit: public View{

	public:
		//Constructeur de la classe viewProduit
		ViewProduit(Controller& _controller,vente::Magasin& magasin);

		//Mets à jour le MVC
		virtual void notify();
		//Affiche le menu produit
		virtual void display();
		//Ajoute un produit au stock
		virtual void addProduct();
		//Affiche le stock
		virtual void showProduct();
		//Ajoute un produit au panier du client
		virtual void addProductToCart();
		//Enlève un produit du panier du client
		virtual void removeProductFromCart();
		//Mets à jour la quantité d'un produit dans le panier du client
		virtual void updateProductQuantityCart();
		//Vide le panier du client
		virtual void clearCart();
		//Mets à jour la quantité d'un produit dans le stock
		virtual void updateProductQuantity();

	private:
		//Controller du menu produit
		Controller& controller;
		//Instance du magasin
		vente::Magasin& _magasin;
};
#endif
