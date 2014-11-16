#pragma once
enum Runway_activity{ idle, land, takeoff };
#include "Utility.h"
#include "QueueLinkedExtended.cpp"
#include "Plane.h"

class Runway
{
public:
	/*
	Post:  The Runway data members are initialized to record no
	prior Runway use and to record the limit on queue sizes.
	*/
	Runway(int limit);
	~Runway();
	/*
	Post:  If possible, the Plane current is added to the
	landing Queue; otherwise, an Error_code of overflow is
	returned. The Runway statistics are updated.
	Uses:  class Extended_queue.
	*/
	Error_code can_land(const Plane &current);
	/*
	Post:  If possible, the Plane current is added to the
	takeoff Queue; otherwise, an Error_code of overflow is
	returned. The Runway statistics are updated.
	Uses:  class Extended_queue.
	*/
	Error_code can_depart(const Plane &current);
	/*
	Post:  If the landing Queue has entries, its front
	Plane is copied to the parameter moving
	and a result  land is returned. Otherwise,
	if the takeoff Queue has entries, its front
	Plane is copied to the parameter moving
	and a result  takeoff is returned. Otherwise,
	idle is returned. Runway statistics are updated.
	Uses:  class Extended_queue.
	*/
	Runway_activity activity(int time, Plane &moving);
	/*
	Post: Runway usage statistics are summarized and printed.
	*/
	void shut_down(int time) const;

private:
	QueueLinkedExtended<Plane> landingPlanes;
	QueueLinkedExtended<Plane> takeoffPlanes;
	unsigned queue_limit;
	int num_land_requests;        //  number of planes asking to land
	int num_takeoff_requests;     //  number of planes asking to take off
	int num_landings;             //  number of planes that have landed
	int num_takeoffs;             //  number of planes that have taken off
	int num_land_accepted;        //  number of planes queued to land
	int num_takeoff_accepted;     //  number of planes queued to take off
	int num_land_refused;         //  number of landing planes refused
	int num_takeoff_refused;      //  number of departing planes refused
	int land_wait;                //  total time of planes waiting to land
	int takeoff_wait;             //  total time of planes waiting to take off
	int idle_time;                //  total time runway is idle
};

