#ifndef APPLICATION_H
#define APPLICATION_H

#include "controller.h"
#include "viewClient.h"
#include "viewProduit.h"
#include "viewMenu.h"
#include "viewCommande.h"
#include "magasin.h"

class Application{

	public:
		//Constructeur de la classe Application
		Application();
		//Lance une application en chargeant les clients et en lançant le MVC
		void run();

	private:
		//Controller pour le modèle MVC
		Controller controller;
		//Vue correspondant au menu principal
		ViewMenu viewMenu;
		//Vue correspondant au menu client
		ViewClient viewClient;
		//Vue correspondant au menu produit
		ViewProduit viewProduit;
		//Vue correspondant au menu commande
		ViewCommande viewCommande;
		//Itération de notre magasin
		vente::Magasin _magasin;
};
#endif
