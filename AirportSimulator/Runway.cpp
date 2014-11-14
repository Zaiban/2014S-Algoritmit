
#include "Runway.h"

Runway::Runway(int limit)
{
	//TO-DO
}
Runway::~Runway()
{
	//TO-DO
}
Error_code Runway::can_land(const Plane &current)
{
	//TO-DO
	return stub_ec;
}
Error_code Runway::can_depart(const Plane &current)
{
	//TO-DO
	return stub_ec;
}
Runway_activity Runway::activity(int time, Plane &moving)
{
	//TO-DO
	return stub_ra;
}
void Runway::shut_down(int time) const
{
	//TO-DO
}