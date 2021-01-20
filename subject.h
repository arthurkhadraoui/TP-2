#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "Observer.h"
class Subject
{
private:
	std::vector<Observer*> observers;
public:
	Subject();
	void addObserver(Observer* observer);
	void notify();
};
#endif