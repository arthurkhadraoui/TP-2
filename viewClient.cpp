#include "viewClient.h"
#include <string>

ViewClient::ViewClient(Controller & _controller, vente::Magasin& magasin)
	: View(), controller(_controller), _magasin(magasin)
{
	controller.addObserver(this);
}

void ViewClient::notify()
{
	if (controller.getCurrentScreen() == 1)
		display();
}

void ViewClient::addCustomer(){
	std::cout<<"Veuillez taper le prenom du client:"<<std::endl;
	std::string prenom;
	std::cin>>prenom;
	std::cout<<"Veuillez taper le nom du client:"<<std::endl;
	std::string nom;
	std::cin>>nom;
	_magasin.vente::Magasin::addCustomer(prenom,nom);
	clear();
	notify();
}

void ViewClient::showCustomer(){
	std::cout<<"Veuillez taper l'id du client:"<<std::endl;
	int id;
	std::cin>>id;
	_magasin.vente::Magasin::displayCustomer(id);
	notify();

}

void ViewClient::display(){
	_magasin.vente::Magasin::displayCustomers();
	std::cout<<std::endl;
	for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;

	std::cout<<"|Options";
		for (int i=0; i<66 ;i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		for (int i=0; i<73;i++){
			std::cout<<"-";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		std::cout<<"1.Ajouter un client";
		for (int i=0; i<73-std::string("1.Ajouter un client").length();i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		std::cout<<"2.Afficher un client";
		for (int i=0; i<73-std::string("2.Afficher un client").length();i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		std::cout<<"0.Retour";
		for (int i=0; i<73-std::string("0.Retour").length();i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;

		int res;
		std::cin.clear();
		std::cin >> res;

		switch(res){
			case 0: controller.setScreen(0);
			case 1: addCustomer();
			case 2: showCustomer();
		}
}