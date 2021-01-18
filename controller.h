#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Subject.h"

class Controller: public Subject
{
private:
	int currentScreen;


public:
	Controller();
	void setScreen(const int& value);
	int getCurrentScreen();
};
#endif