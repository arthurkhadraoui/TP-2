#ifndef VIEW_H
#define VIEW_H

#include <string.h>
#include "observer.h"

class View: public Observer{

public:
	//Constructeur de la classe View
	View();

	//Nettayage de l'invite de commande
	void clear() const;
	//Affichage de la view
	virtual void display() const;

};
#endif
