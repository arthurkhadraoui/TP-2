#include "Application.h"


Application::Application()
	:controller(),viewMenu(controller),viewClient(controller,_magasin),viewProduit(controller,_magasin), viewCommande(controller,_magasin)
{
}

void Application::run()
{
	controller.notify();
}
