#include "subject.h"

Subject::Subject(){

}

void Subject::addObserver(Observer* observer)
{
	observers.push_back(observer); //Ajout de l'observer à la liste des observers
}

void Subject::notify()
{
	for (int iObserver = 0; iObserver < int(observers.size()); ++iObserver) //Pour chaque observer du subject
	{
		observers[iObserver]->notify(); //Utilise notify de observer
	}
}
