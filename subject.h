#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "observer.h"

class Subject{

public:
	//Constructeur de la classe Subject
	Subject();

	//Ajout d'un observer
	void addObserver(Observer* observer);
	//Notification mettant à jour le MVC
	void notify();

private:
	//Liste des observers du Subject
	std::vector<Observer*> observers;

};
#endif
