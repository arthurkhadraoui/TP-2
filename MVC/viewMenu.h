#ifndef VIEWMENU_H
#define VIEWMENU_H
#include "observer.h"
#include "view.h"
#include "controller.h"
#include "../magasin.h"
class ViewMenu: public View
{
private:
Controller& controller;
public:
	
	ViewMenu(Controller& _controller);

	virtual void notify();

	virtual void display();
};
#endif