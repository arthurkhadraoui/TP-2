#include "viewMenu.h"
#include <iostream>
#include <stdlib.h>
#include <Windows.h>




ViewMenu::ViewMenu(Controller & _controller)
: View(), controller(_controller)
{
	controller.addObserver(this);
}

void ViewMenu::notify()
{
	if (controller.getCurrentScreen() == 0)
		display();
}

void ViewMenu::display()
{
	std::cout<<R"(
	|  ____|               / ____| |                
	| |__   __ _ ___ _   _| (___ | |_ ___  _ __ ___ 
	|  __| / _` / __| | | |\___ \| __/ _ \| '__/ _ \
	| |___| (_| \__ \ |_| |____) | || (_) | | |  __/
	|______\__,_|___/\__, |_____/ \__\___/|_|  \___|                         
	)";
	for (int i=0; i<75;i++){
		std::cout<<"-";
	}
	std::cout<<std::endl;
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
	for (int i=0; i<73-std::string("1.Afficher les clients").length();i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;
	std::cout<<"|";
	std::cout<<"2.Afficher les produits";
	for (int i=0; i<73-std::string("1.Afficher les produits").length();i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;
	std::cout<<"|";
	std::cout<<"3.Afficher les commandes";
	for (int i=0; i<73-std::string("2.Afficher les commandes").length();i++){
		std::cout<<" ";
	}
	std::cout<<"|"<<std::endl;
	std::cout<<"|";
	std::cout<<"0.Quitter";
	for (int i=0; i<73-std::string("2.Quitter").length();i++){
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
	
	if (res==1 ||res==2||res==3){
		controller.setScreen(res);
	}
	else if (res==0){
		exit(0);
	}
	
	else {
		while (res !=0 && res !=1 && res !=2 && res !=3){
			std::cout<<"Veuillez saisir une option valide:"<<std::endl;
			std::cin.clear();
			std::cin >> res;
		}
	}

	clear();
	
	controller.setScreen(0);
}
