#include "PromotionEvent.h"

PromotionEvent::PromotionEvent(int hour,int day,Company* cmp,int id,int money):Event(hour,day,cmp)
{
	IdOfPromotedCargo = id;
	ExtraMoney = money;
}


bool PromotionEvent::Execute(Cargo* promotedCargo)
{
	promotedCargo = nullptr;

	// complete implementation

	return true;
}
