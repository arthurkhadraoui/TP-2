#ifndef VIEW_H
#define VIEW_H
#include <string.h>
#include "observer.h"
class View: public Observer
{
	
private:


public:
	View();
	
	void clear() const;

	virtual void display() const;
};
#endif