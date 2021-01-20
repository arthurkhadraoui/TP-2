#include "viewCommande.h"

ViewCommande::ViewCommande(Controller& _controller,vente::Magasin& magasin)
: View(), controller(_controller),_magasin(magasin)
{
	controller.addObserver(this);
}

void ViewCommande::notify()
{
	if (controller.getCurrentScreen() == 3)
		display();
}

void ViewCommande::addOrder(){
	std::cout<<"Veuillez saisir le prenom du client:"<<std::endl;
	std::string prenom;
	std::cin>>prenom;
	std::cout<<"Veuillez saisir le nom du client:"<<std::endl;
	std::string nom;
	std::cin>>nom;
	_magasin.vente::Magasin::addOrder(prenom,nom);
	notify();
}

void ViewCommande::changeStatus(){
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
	for (int i=0; i<73-std::string("0: Valider").length();i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;
	std::cout<<"|";
	std::cout<<"1: En Attente";
	for (int i=0; i<73-std::string("1: En Attente").length();i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;
	std::cout<<"|";
	std::cout<<"2: Refuser";
	for (int i=0; i<73-std::string("2: Refuser").length();i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;
	for (int i=0; i<75;i++){
		std::cout<<"-";
	}
	std::cout<<std::endl;
	std::cin>>statut;
	_magasin.vente::Magasin::switchStatuts(num,statut);
	notify();
}

void ViewCommande::validateOrder(){
	std::cout<<"Veuillez saisir le numero de commande:"<<std::endl;
	int num;
	std::cin>>num;
	_magasin.vente::Magasin::validateCommande(num);
	notify();
}



void ViewCommande::displayFromCustomer(){
	std::cout<<"Veuillez saisir le prenom du client:"<<std::endl;
	std::string prenom;
	std::cin>>prenom;
	std::cout<<"Veuillez saisir le nom du client:"<<std::endl;
	std::string nom;
	std::cin>>nom;
	_magasin.vente::Magasin::displayOrdersFromCustomer(prenom,nom);
	notify();
}




void ViewCommande::display(){
	_magasin.vente::Magasin::displayOrders();
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
	for (int i=0; i<73-std::string("1.Ajouter une commande").length();i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;
	std::cout<<"|";
	std::cout<<"2.Valider une commande";
	for (int i=0; i<73-std::string("2.Valider une commande").length();i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;

	std::cout<<"|";
	std::cout<<"3.Changer le statut d'une commande";
	for (int i=0; i<73-std::string("3.Changer le statut d'une commande").length();i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;

	std::cout<<"|";
	std::cout<<"4.Afficher les commandes d'un client";
	for (int i=0; i<73-std::string("4.Afficher les commandes d'un client").length();i++){
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
		case 1: addOrder();
		case 2: validateOrder();
		case 3: changeStatus();
		case 4: displayFromCustomer();
	}
}