#include "controller.h"

Controller::Controller() : Subject(), currentScreen(0){

}

int Controller::getCurrentScreen(){
	return currentScreen;
}

void Controller::setScreen(const int & value){
	if (value >= 0 && value <= 9) //Vérifie que la valeur est possible
		currentScreen = value; //Met à jour la valeur

	notify(); //Informe le MVC
}
