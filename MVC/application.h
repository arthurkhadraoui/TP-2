#ifndef APPLICATION_H
#define APPLICATION_H
#include "Controller.h"
#include "viewClient.h"
#include "viewMenu.h"
#include "magasin.h"


class Application
{
private:
	Controller controller;
	ViewClient viewClient;
	ViewMenu viewMenu;
	vente::Magasin& _magasin;

public:
	Application(vente::Magasin& magasin);
	void run();
};


#endif