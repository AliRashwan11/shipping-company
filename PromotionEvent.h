#include"Event.h"


class PromotionEvent : public Event
{
	int IdOfPromotedCargo;
	int ExtraMoney;

public:

	PromotionEvent(int,int,Company*,int,int);

	bool Execute(Cargo*);

};
