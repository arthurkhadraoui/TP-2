#ifndef VIEWMENU_H
#define VIEWMENU_H

#include "observer.h"
#include "view.h"
#include "controller.h"

class ViewMenu: public View{

	public:
		//Constructeur de ka ckasse viewMenu
		ViewMenu(Controller& _controller);

		//Mets à jour le MVC
		virtual void notify();
		//Affiche le menu principal
		virtual void display();

	private:
		//Controller du menu principal
		Controller& controller;
};
#endif
