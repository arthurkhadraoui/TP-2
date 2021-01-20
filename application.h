#ifndef APPLICATION_H
#define APPLICATION_H
#include "Controller.h"
#include "viewClient.h"
#include "viewProduit.h"
#include "viewMenu.h"
#include "viewCommande.h"
#include "magasin.h"


class Application
{
private:
	Controller controller;
	ViewClient viewClient;
	ViewMenu viewMenu;
	ViewProduit viewProduit;
	ViewCommande viewCommande;
	vente::Magasin _magasin;

public:
	Application();
	void run();
};


#endif