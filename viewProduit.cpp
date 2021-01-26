#include "viewProduit.h"
#include <string>
ViewProduit::ViewProduit(Controller & _controller, vente::Magasin& magasin)
	: View(), controller(_controller), _magasin(magasin)
{
	controller.addObserver(this);
}

void ViewProduit::notify()
{
	if (controller.getCurrentScreen() == 2)
		display();
}

 void ViewProduit::addProduct(){
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
	_magasin.vente::Magasin::addProduct(name,desc,quantity,prix);
	notify();
}


 void ViewProduit::showProduct(){
	std::cout<<"Veuillez saisir le nom du produit:"<<std::endl;
	std::string name;
	std::cin.ignore();
	std::getline(std::cin,name);
	_magasin.vente::Magasin::displayProduct(name);
}

 void ViewProduit::updateProductQuantity(){
	std::cout<<"Veuillez saisir le nom du produit:"<<std::endl;
	std::string name;
	std::cin.ignore();
	std::getline(std::cin,name);
	std::cout<<"Veuillez saisir la quantite du produit:"<<std::endl;
	int quantity;
	std::cin>>quantity;
	_magasin.vente::Magasin::updateQuantity(name,quantity);
}

void ViewProduit::addProductToCart(){
	std::cout<<"Veuillez saisir le prenom du client:"<<std::endl;
	std::string prenom;
	std::cin>>prenom;
	std::cout<<"Veuillez saisir le nom du client:"<<std::endl;
	std::string nom;
	std::cin>>nom;
	std::cout<<"Veuillez saisir le nom du produit:"<<std::endl;
	std::string name;
	std::cin.ignore();
	std::getline(std::cin,name);
	_magasin.vente::Magasin::addProductCart(name,prenom,nom);
	notify();
}

void ViewProduit::removeProductFromCart(){
	std::cout<<"Veuillez saisir le prenom du client:"<<std::endl;
	std::string prenom;
	std::cin>>prenom;
	std::cout<<"Veuillez saisir le nom du client:"<<std::endl;
	std::string nom;
	std::cin>>nom;
	std::cout<<"Veuillez saisir le nom du produit:"<<std::endl;
	std::string name;
	std::cin.ignore();
	std::getline(std::cin,name);
	_magasin.vente::Magasin::removeProductCart(name,prenom,nom);
	notify();
}

void ViewProduit::updateProductQuantityCart(){
	std::cout<<"Veuillez saisir le prenom du client:"<<std::endl;
	std::string prenom;
	std::cin>>prenom;
	std::cout<<"Veuillez saisir le nom du client:"<<std::endl;
	std::string nom;
	std::cin>>nom;
	std::cout<<"Veuillez saisir le nom du produit:"<<std::endl;
	std::string name;
	std::cin.ignore();
	std::getline(std::cin,name);
	std::cout<<"Veuillez saisir la quantite du produit:"<<std::endl;
	int quantity;
	std::cin>>quantity;
	_magasin.vente::Magasin::updateProductQuantityCart(name,quantity,prenom,nom);
	notify();
}

void ViewProduit::clearCart(){
	std::cout<<"Veuillez saisir le prenom du client:"<<std::endl;
	std::string prenom;
	std::cin>>prenom;
	std::cout<<"Veuillez saisir le nom du client:"<<std::endl;
	std::string nom;
	std::cin>>nom;
	_magasin.vente::Magasin::clearCart(prenom,nom);
	notify();
}



 void ViewProduit::display(){
	_magasin.vente::Magasin::displayAllProducts();
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

		int res;
		std::cin.clear();
		std::cin >> res;

		while (res!=0 && res!=1 && res!=2 && res!=3 && res!=4 && res!=5 && res!=6 && res!=7  ){
		std::cout<<"Veuillez selectionner une option valide:"<<std::endl;
		std::cin >> res;
	}

		switch(res){
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

