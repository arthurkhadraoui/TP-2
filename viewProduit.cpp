#include "viewProduit.h"
#include <string>

ViewProduit::ViewProduit(Controller & _controller, vente::Magasin& magasin)	: View(), controller(_controller), _magasin(magasin){
	controller.addObserver(this); //Ajoute l'observer
}

void ViewProduit::notify(){
	if (controller.getCurrentScreen() == 2) //Si l'on se trouve sur le menu produit
		display(); //Affiche la page
}

 void ViewProduit::addProduct(){
	 //Saisie des informations du produit
	std::cout<<"Veuillez saisir le nom du produit:"<<std::endl;
	std::string name;
	std::cin.ignore();
	std::getline(std::cin,name);
	std::cout<<"Veuillez saisir la description du produit:"<<std::endl;
	std::string desc;
	std::getline(std::cin,desc);
	std::cout<<"Veuillez saisir la quantite du produit:"<<std::endl;
	int quantity;
	std::cin>>quantity;
	std::cout<<"Veuillez saisir le prix du produit:"<<std::endl;
	double prix;
	std::cin>>prix;
	_magasin.vente::Magasin::addProduct(name,desc,quantity,prix); //Ajout du produit au stock du magasin
	notify(); //Mets à jour le MVC
}

 void ViewProduit::showProduct(){
	 //Choix du produit dont on veut les détails
	std::cout<<"Veuillez saisir le nom du produit:"<<std::endl;
	std::string name;
	std::cin.ignore();
	std::getline(std::cin,name);
	_magasin.vente::Magasin::displayProduct(name); //Affichage du produit
}

 void ViewProduit::updateProductQuantity(){
	 //Choix du produit dont on veut modifier la quantité
	std::cout<<"Veuillez saisir le nom du produit:"<<std::endl;
	std::string name;
	std::cin.ignore();
	std::getline(std::cin,name);
	//Saisie de la quantite
	std::cout<<"Veuillez saisir la quantite du produit:"<<std::endl;
	int quantity;
	std::cin>>quantity;
	_magasin.vente::Magasin::updateQuantity(name,quantity); //Mets à jour la quantite du produit
}

void ViewProduit::addProductToCart(){
	//Choix du client dont on modifie le panier
	std::cout<<"Veuillez saisir le prenom du client:"<<std::endl;
	std::string prenom;
	std::cin>>prenom;
	std::cout<<"Veuillez saisir le nom du client:"<<std::endl;
	std::string nom;
	std::cin>>nom;
	//Choix du produit que l'on souhaite ajouter
	std::cout<<"Veuillez saisir le nom du produit:"<<std::endl;
	std::string name;
	std::cin.ignore();
	std::getline(std::cin,name);
	_magasin.vente::Magasin::addProductCart(name,prenom,nom); //Ajout du produit dans le panier du client
	notify(); //Mets à jour le MVC
}

void ViewProduit::removeProductFromCart(){
	//Choix du client dont on modifie le panier
	std::cout<<"Veuillez saisir le prenom du client:"<<std::endl;
	std::string prenom;
	std::cin>>prenom;
	std::cout<<"Veuillez saisir le nom du client:"<<std::endl;
	std::string nom;
	std::cin>>nom;
	//Choix du produit que l'on souhaite retirer
	std::cout<<"Veuillez saisir le nom du produit:"<<std::endl;
	std::string name;
	std::cin.ignore();
	std::getline(std::cin,name);
	_magasin.vente::Magasin::removeProductCart(name,prenom,nom); //Suppression du produit du panier du client
	notify(); //Mets à jour le MVC
}

void ViewProduit::updateProductQuantityCart(){
	//Choix du client dont on modifie le panier
	std::cout<<"Veuillez saisir le prenom du client:"<<std::endl;
	std::string prenom;
	std::cin>>prenom;
	std::cout<<"Veuillez saisir le nom du client:"<<std::endl;
	std::string nom;
	std::cin>>nom;
	//Choix du produit dont on souhaite modifier la quantité
	std::cout<<"Veuillez saisir le nom du produit:"<<std::endl;
	std::string name;
	std::cin.ignore();
	std::getline(std::cin,name);
	//Saisie de la quantité
	std::cout<<"Veuillez saisir la quantite du produit:"<<std::endl;
	int quantity;
	std::cin>>quantity;
	_magasin.vente::Magasin::updateProductQuantityCart(name,quantity,prenom,nom); //Mise à jour de la quantité dans le panier du client
	notify(); //Mets à jour le MVC
}

void ViewProduit::clearCart(){
	//Choix du clinet dont on souhaite vider le panier
	std::cout<<"Veuillez saisir le prenom du client:"<<std::endl;
	std::string prenom;
	std::cin>>prenom;
	std::cout<<"Veuillez saisir le nom du client:"<<std::endl;
	std::string nom;
	std::cin>>nom;
	_magasin.vente::Magasin::clearCart(prenom,nom); //Suppression de tous les produits du panier du client
	notify(); //Mets à jour le MVC
}

 void ViewProduit::display(){
	_magasin.vente::Magasin::displayAllProducts(); //Affiche tous les produits disponible dans le stock du magasin
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
		std::cout<<"1.Ajouter un produit";
		for (int i=0; i<73-int(std::string("1.Ajouter un produit").length());i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
		std::cout<<"2.Afficher un produit";
		for (int i=0; i<73-int(std::string("2.Afficher un produit").length());i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
			std::cout<<"|";
		std::cout<<"3.Modifier la quantite d'un produit";
		for (int i=0; i<73-int(std::string("3.Modifier la quantite d'un produit").length());i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;

			std::cout<<"|";
		std::cout<<"4.Ajouter un produit au panier d'un client";
		for (int i=0; i<73-int(std::string("4.Ajouter un produit au panier d'un client").length());i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
			std::cout<<"|";
		std::cout<<"5.Supprimer un produit du panier d'un client";
		for (int i=0; i<73-int(std::string("5.Supprimer un produit au panier d'un client").length());i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;

					std::cout<<"|";
		std::cout<<"6.Modifier la quantite d'un produit du panier d'un client";
		for (int i=0; i<73-int(std::string("6.Modifier la quantity d'un produit du panier d'un client").length());i++){
			std::cout<<" ";
		}
		std::cout<<"|"<<std::endl;
		std::cout<<"|";
				std::cout<<"7.Vider le panier d'un client";
		for (int i=0; i<73-int(std::string("7.Vider le panier d'un client").length());i++){
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

		while (res!=0 && res!=1 && res!=2 && res!=3 && res!=4 && res!=5 && res!=6 && res!=7  ){ //Si l'action saisie n'existe pas
		std::cout<<"Veuillez selectionner une option valide:"<<std::endl; //On demande au client de saisir une option valide
		std::cin >> res;
	}

		switch(res){ //Effectue l'action choisie
			case 0: controller.setScreen(0);break;
			case 1: addProduct();break;
			case 2: showProduct();break;
			case 3: updateProductQuantity();break;
			case 4: addProductToCart();break;
			case 5:removeProductFromCart();break;
			case 6: updateProductQuantityCart();break;
			case 7:clearCart();break;
		}
}
