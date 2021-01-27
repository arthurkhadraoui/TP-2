#ifndef VIEWCOMMANDE_H
#define VIEWCOMMANDE_H

#include "observer.h"
#include "view.h"
#include "controller.h"
#include "magasin.h"

class ViewCommande: public View{

public:
	//Constructeur de la classe viewCommande
	ViewCommande(Controller& _controller,vente::Magasin& magasin);

	//Mets à jour le MVC
	virtual void notify();
	//Affiche le menu commande
	virtual void display();
	//Ajoute une commande au magasin
	virtual void addOrder();
	//Change le statut d'une commande existante
	virtual void changeStatus();
	//Valide une commande existante
	virtual void validateOrder();
	//Affiche les commande d'un client en particulier
	virtual void displayFromCustomer();

private:
	//Controller du menu commande
	Controller& controller;
	//Instance du maagasin
	vente::Magasin& _magasin;

};
#endif
