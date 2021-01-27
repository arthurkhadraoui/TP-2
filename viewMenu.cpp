#include "viewMenu.h"
#include <iostream>
#include <stdlib.h>

ViewMenu::ViewMenu(Controller & _controller) : View(), controller(_controller){
	controller.addObserver(this);//Ajoute l'observer
}

void ViewMenu::notify(){
	if (controller.getCurrentScreen() == 0) //Si l'on se trouve sur le menu principal
		display(); //Affiche la page
}

void ViewMenu::display(){
	clear(); //Vide la page
	//Afficahge du menu principal
	std::cout<<R"(
    ______                 _____ __
   / ____/___ ________  __/ ___// /_____  ________
  / __/ / __ `/ ___/ / / /\__ \/ __/ __ \/ ___/ _ \
 / /___/ /_/ (__  ) /_/ /___/ / /_/ /_/ / /  /  __/
/_____/\__,_/____/\__, //____/\__/\____/_/   \___/
                 /____/
     )";
     std::cout<<std::endl;
	for (int i=0; i<75;i++){
		std::cout<<"-";
	}
	std::cout<<std::endl;
	std::cout<<"|Menu";
	for (int i=0; i<69 ;i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;
	std::cout<<"|";
	for (int i=0; i<73;i++){
		std::cout<<"-";
	}
	std::cout<<"|"<<std::endl;
	std::cout<<"|";
	std::cout<<"1.Afficher les clients";
	for (int i=0; i<73-int(std::string("1.Afficher les clients").length());i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;
	std::cout<<"|";
	std::cout<<"2.Afficher les produits";
	for (int i=0; i<73-int(std::string("1.Afficher les produits").length());i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;
	std::cout<<"|";
	std::cout<<"3.Afficher les commandes";
	for (int i=0; i<73-int(std::string("2.Afficher les commandes").length());i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;
	std::cout<<"|";
	std::cout<<"0.Quitter";
	for (int i=0; i<73-int(std::string("2.Quitter").length());i++){
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

	if (res==1 ||res==2||res==3){ //Si l'action saisie existe est n'est pas "Quitter"
		clear();
		controller.setScreen(res); //On affiche la page correspondante
	}
	else if (res==0){
		exit(0); //Sinon on quitte l'application
	}

	else {
		while (res !=0 && res !=1 && res !=2 && res !=3){ //Si l'action n'est pas valide on demande à l'utilisateur d'en saisir une valide
			std::cout<<"Veuillez saisir une option valide:"<<std::endl;
			std::cin.clear();
			std::cin >> res;
		}
	}
	clear();
	controller.setScreen(0);
}
