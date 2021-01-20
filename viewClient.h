#ifndef VIEWCLIENT_H
#define VIEWCLIENT_H
#include "observer.h"
#include "view.h"
#include "controller.h"
#include "magasin.h"
class ViewClient: public View
{
private:
Controller& controller;
vente::Magasin& _magasin;

public:
	
	ViewClient(Controller& _controller,vente::Magasin& magasin);

	virtual void notify();

	virtual void display();

	virtual void addCustomer();

	virtual void showCustomer();
};
#endif