#ifndef OBSERVER_H
#define OBSERVER_H

class Observer{

public:
	//Permet de mettre à jour le MVC, appelé par le Controller
	virtual void notify() = 0;

};
#endif
