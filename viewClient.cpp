#include "viewClient.h"
#include <string>

ViewClient::ViewClient(Controller & _controller, vente::Magasin& magasin)	: View(), controller(_controller), _magasin(magasin){
	controller.addObserver(this); //Ajoute l'observer
}

void ViewClient::notify(){
	if (controller.getCurrentScreen() == 1) //Si l'on se trouve sur le menu client
		display();//Affiche la page
}

void ViewClient::addCustomer(){
	//Saisie des données lors de l'ajout d'un client
	std::cout<<"Veuillez taper le prenom du client:"<<std::endl;
	std::string prenom;
	std::cin>>prenom;
	std::cout<<"Veuillez taper le nom du client:"<<std::endl;
	std::string nom;
	std::cin>>nom;
	_magasin.vente::Magasin::addCustomer(prenom,nom); //Ajout du client à la liste des clients du magasin
	clear(); //Vide la fenêtre
	notify(); //Mets à jour le MVC
}

void ViewClient::showCustomer(){
	//Choix du client à afficher
	std::cout<<"Veuillez taper l'id du client:"<<std::endl;
	int id;
	std::cin>>id;
	_magasin.vente::Magasin::displayCustomer(id); //Affiche le client choisis
	notify(); //Mets à jour le MVC
}

void ViewClient::display(){
	_magasin.vente::Magasin::displayCustomers(); //Affiche les clients
	//Affichage du sous menu
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
		for (int i=0; i<73-int(std::string("1.Ajouter un client").length());i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		std::cout<<"2.Afficher un client";
		for (int i=0; i<73-int(std::string("2.Afficher un client").length());i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		std::cout<<"0.Retour";
		for (int i=0; i<73-int(std::string("0.Retour").length());i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		for (int i=0; i<75;i++){
			std::cout<<"-";
		}
		std::cout<<std::endl;
		//Choix de l'action suivante
		int res;
		std::cin.clear();
		std::cin >> res;

		while (res!=0 && res!=1 && res!=2 && res!=3  ){ //Gestion de l'erreur de l'utilisateur
		std::cout<<"Veuillez selectionner une option valide:"<<std::endl;
		std::cin >> res;
		}

		switch(res){ //Action à réaliser en fonction du choix de l'utilisateur
			case 0: controller.setScreen(0); break;
			case 1: addCustomer(); break;
			case 2: showCustomer();break;
		}
}
