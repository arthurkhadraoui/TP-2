#ifndef VIEWCOMMANDE_H
#define VIEWCOMMANDE_H
#include "observer.h"
#include "view.h"
#include "controller.h"
#include "magasin.h"
class ViewCommande: public View
{
private:
Controller& controller;
vente::Magasin& _magasin;
public:
	
	ViewCommande(Controller& _controller,vente::Magasin& magasin);

	virtual void notify();

	virtual void display();

	virtual void addOrder();

	virtual void changeStatus();

	virtual void validateOrder();

	virtual void displayFromCustomer();
};
#endif