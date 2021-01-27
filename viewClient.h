#ifndef VIEWCLIENT_H
#define VIEWCLIENT_H

#include "observer.h"
#include "view.h"
#include "controller.h"
#include "magasin.h"

class ViewClient: public View{

	public:
		//Constructeur de la classe viewClient
		ViewClient(Controller& _controller,vente::Magasin& magasin);

		//Mets à jour le MVC
		virtual void notify();
		//Affiche le menu client
		virtual void display();
		//Ajout d'un utilisateur
		virtual void addCustomer();
		//Affichage des utilisateur 
		virtual void showCustomer();

	private:
		//Controller du menu client
		Controller& controller;
		//Instance du magasin
		vente::Magasin& _magasin;
};
#endif
