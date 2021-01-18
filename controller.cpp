#include "controller.h"


Controller::Controller()
	: Subject(), currentScreen(0)
{

}

void Controller::setScreen(const int & value)
{
	if (value >= 0 && value <= 9)
		currentScreen = value;

	notify();
}

int Controller::getCurrentScreen()
{
	return currentScreen;
}