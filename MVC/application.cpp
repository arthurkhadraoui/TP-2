#include "Application.h"


Application::Application(vente::Magasin& magasin)
	:controller(),_magasin(magasin),viewMenu(controller),viewClient(controller,_magasin)
{
}

void Application::run()
{
	controller.notify();
}
