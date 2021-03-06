#include "Plane.h"
#include <iostream>
using std::cout; using std::endl;

Plane::Plane()
{
	flt_num = -1;
	clock_start = -1;
	state = null;
}
Plane::Plane(int flt, int time, Plane_status status)
{
	flt_num = flt;
	clock_start = time;
	state = status;
	cout << "Plane number " << flt << " ready to ";
	if (status == arriving)
		cout << "land." << endl;
	else
		cout << "take off." << endl;
}
Plane::~Plane()
{
}
void Plane::refuse() const
{
	cout << "Plane number " << flt_num;
	if (state == arriving)
		cout << " directed to another airport" << endl;
	else
		cout << " told to try to takeoff again later" << endl;
}
void Plane::land(int time) const
{
	int wait = time - clock_start;
	cout << time << ": Plane number " << flt_num << " landed after "
		<< wait << " time unit" << ((wait == 1) ? "" : "s")
		<< " in the takeoff queue." << endl;
}
void Plane::fly(int time) const
{
	int wait = time - clock_start;
	cout << time << ": Plane number " << flt_num << " took off after "
		<< wait << " time unit" << ((wait == 1) ? "" : "s")
		<< " in the takeoff queue." << endl;
}
int Plane::started() const
{
	return clock_start;
}