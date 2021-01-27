#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "subject.h"

class Controller: public Subject{

	public :
		//Constructeur de la classe Controller
		Controller();

		//Accesseurs de la classe Controller
		int getCurrentScreen();
		
		void setScreen(const int& value);

	private :
		//Ecran actuellement utilisé par l'application
		int currentScreen;
};
#endif
