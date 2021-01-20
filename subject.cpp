#include "Subject.h"


Subject::Subject()
{
}

void Subject::addObserver(Observer* observer)
{
	observers.push_back(observer);
}

void Subject::notify()
{
	for (int iObserver = 0; iObserver < observers.size(); ++iObserver)
	{
		observers[iObserver]->notify();
	}
}