#ifndef VIEWPRODUIT_H
#define VIEWCPRODUIT_H
#include "observer.h"
#include "view.h"
#include "controller.h"
#include "magasin.h"

class ViewProduit: public View
{
private:
Controller& controller;
vente::Magasin& _magasin;

public:
	
	ViewProduit(Controller& _controller,vente::Magasin& magasin);

	virtual void notify();

	virtual void display();

	virtual void addProduct();

	virtual void showProduct();

	virtual void addProductToCart();

	virtual void removeProductFromCart();

	virtual void updateProductQuantityCart();

	virtual void clearCart();

	virtual void updateProductQuantity();
};
#endif