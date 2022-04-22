#include "PromotionEvent.h"

PromotionEvent::PromotionEvent(int hour, int day, Company* cmp, int id, int money) :Event(hour, day, cmp)
{
	IdOfPromotedCargo = id;
	ExtraMoney = money;
	WasFound = 0;
}


bool PromotionEvent::Execute()
{

	WasFound = mainCompany->CargoSearch(IdOfPromotedCargo);

	if (WasFound)
	{

		Cargo* temp = nullptr;

		temp = mainCompany->CargoCancelled(IdOfPromotedCargo);

		if (temp)
		{
			mainCompany->AddToVIPWaitingCargos(temp);
			return true;
		}

		return false;

	}

	return false;
}
