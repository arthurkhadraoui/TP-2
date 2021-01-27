#include "viewCommande.h"

ViewCommande::ViewCommande(Controller& _controller,vente::Magasin& magasin): View(), controller(_controller),_magasin(magasin){
	controller.addObserver(this); //Ajoute l'observer
}

void ViewCommande::notify(){
	if (controller.getCurrentScreen() == 3) //Si l'on se trouve sur le menu commande
		display(); //Affiche la page
}

void ViewCommande::addOrder(){
	//Saisie des données lors de l'ajout d'une commande
	std::cout<<"Veuillez saisir le prenom du client:"<<std::endl;
	std::string prenom;
	std::cin>>prenom;
	std::cout<<"Veuillez saisir le nom du client:"<<std::endl;
	std::string nom;
	std::cin>>nom;
	_magasin.vente::Magasin::addOrder(prenom,nom); //Ajout de la commande à la liste des commandes
	notify(); //Mets à jour le MVC
}

void ViewCommande::changeStatus(){
	//Affichage pour le changement de statut
	std::cout<<"Veuillez saisir le numero de commande:"<<std::endl;
	int num;
	std::cin>>num;
	int statut;
	for (int i=0; i<75;i++){
		std::cout<<"-";
	}
	std::cout<<std::endl;
	std::cout<<"|";
	std::cout<<"0: Valider";
	for (int i=0; i<73-int(std::string("0: Valider").length());i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;
	std::cout<<"|";
	std::cout<<"1: En Attente";
	for (int i=0; i<73-int(std::string("1: En Attente").length());i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;
	std::cout<<"|";
	std::cout<<"2: Refuser";
	for (int i=0; i<73-int(std::string("2: Refuser").length());i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;
	for (int i=0; i<75;i++){
		std::cout<<"-";
	}
	std::cout<<std::endl;
	//Choix du statut voulus
	std::cin>>statut;
	_magasin.vente::Magasin::switchStatuts(num,statut); //Mise à jour du statut
	notify(); //Mets à jour le MVC
}

void ViewCommande::validateOrder(){
	//Choix de la commande à valider
	std::cout<<"Veuillez saisir le numero de commande:"<<std::endl;
	int num;
	std::cin>>num;
	_magasin.vente::Magasin::validateCommande(num); //Validation de la commande
	notify(); //Mets à jour le MVC
}

void ViewCommande::displayFromCustomer(){
	//Choix du client dont on veut les commandes
	std::cout<<"Veuillez saisir le prenom du client:"<<std::endl;
	std::string prenom;
	std::cin>>prenom;
	std::cout<<"Veuillez saisir le nom du client:"<<std::endl;
	std::string nom;
	std::cin>>nom;
	_magasin.vente::Magasin::displayOrdersFromCustomer(prenom,nom); //Affichage des commandes du client
	notify(); //Mets à jour le MVC
}

void ViewCommande::display(){
	_magasin.vente::Magasin::displayOrders(); //Affichage des commandes
	//Affichage des actions possibles
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
	std::cout<<"1.Ajouter une commande";
	for (int i=0; i<73-int(std::string("1.Ajouter une commande").length());i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;
	std::cout<<"|";
	std::cout<<"2.Valider une commande";
	for (int i=0; i<73-int(std::string("2.Valider une commande").length());i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;

	std::cout<<"|";
	std::cout<<"3.Changer le statut d'une commande";
	for (int i=0; i<73-int(std::string("3.Changer le statut d'une commande").length());i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;

	std::cout<<"|";
	std::cout<<"4.Afficher les commandes d'un client";
	for (int i=0; i<73-int(std::string("4.Afficher les commandes d'un client").length());i++){
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
	//Choix de la prochaine action
	int res;
	std::cin.clear();
	std::cin >> res;

	while (res!=0 && res!=1 && res!=2 && res!=3 && res!=4  ){ //Vérifie que l'action saisie existe
		std::cout<<"Veuillez selectionner une option valide:"<<std::endl;
		std::cin >> res;
	}

	switch(res){ //Effectue l'action choisie
		case 0: controller.setScreen(0);break;
		case 1: addOrder();break;
		case 2: validateOrder();break;
		case 3: changeStatus();break;
		case 4: displayFromCustomer();break;
	}
}
