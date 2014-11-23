#include "Airport.h"
#include "RANDOM.H"
#include <iostream>
using std::cin; using std::endl; using std::cout; using std::flush; using std::cerr;

void run_idle(int time);
void initialize(int &end_time, int &queue_limit, double &arrival_rate, double &departure_rate);

// Selects the next runway that is flagged either incoming or both
void selectNextIncoming(Airport &airport);
// Selects the next runway that is flagged either outoing or both
void selectNextOutgoing(Airport &airport);

void test_1();
void test_2();
void test_3();

int main()
{
	char command[2];

	cout << "Type the number of the test program(1, 2, 3)" << endl;
	cin.getline(command, 2);

	switch (command[0]){
	case '1':
		test_1();
		break;
	case '2':
		test_2();
		break;
	case '3':
		test_3();
		break;
	};


	


	system("pause");
	return 0;
}

void run_idle(int time)
/*
Post: The specified time is printed with a message that the runway is idle.
*/
{
	cout << time << ": Runway is idle." << endl;
}

void initialize(int &end_time, int &queue_limit,
	double &arrival_rate, double &departure_rate)
	/*
	Pre:  The user specifies the number of time units in the simulation,
	the maximal queue sizes permitted,
	and the expected arrival and departure rates for the airport.
	Post: The program prints instructions and initializes the parameters
	end_time, queue_limit, arrival_rate, and departure_rate to
	the specified values.
	Uses: utility function user_says_yes
	*/

{
	cout << "This program simulates an airport." << endl
		<< "One plane can land or depart on each runway in each unit of time." << endl;
	cout << "Up to what number of planes can be waiting to land "
		<< "or take off at any time? " << flush;
	cin >> queue_limit;

	cout << "How many units of time will the simulation run?" << flush;
	cin >> end_time;

	bool acceptable = false;
	do {
		cout << "Expected number of arrivals per unit time?" << flush;
		cin >> arrival_rate;
		cout << "Expected number of departures per unit time?" << flush;
		cin >> departure_rate;
		if (arrival_rate < 0.0 || departure_rate < 0.0)
			cerr << "These rates must be nonnegative." << endl;
		else
			acceptable = true;

		//if (acceptable && arrival_rate + departure_rate > 1.0)
			//cerr << "Safety Warning: This airport will become saturated. " << endl;

	} while (!acceptable);
}
void selectNextIncoming(Airport &airport)
{
	while (airport.roleOfSelection() != incoming && airport.roleOfSelection() != both)
		airport.selectNext();
}

void selectNextOutgoing(Airport &airport)
{
	while (airport.roleOfSelection() != outgoing && airport.roleOfSelection() != both)
		airport.selectNext();
}
void test_1()
{
	int end_time;            //  time to run simulation
	int queue_limit;         //  size of Runway queues
	int flight_number = 0;
	double arrival_rate, departure_rate;
	initialize(end_time, queue_limit, arrival_rate, departure_rate);
	Random variable(true);
	Runway small_airport(queue_limit, both);
	for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
		int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
		for (int i = 0; i < number_arrivals; i++) {
			Plane current_plane(flight_number++, current_time, arriving);
			if (small_airport.can_land(current_plane) != success)
				current_plane.refuse();
		}

		int number_departures = variable.poisson(departure_rate); //  current departure requests
		for (int j = 0; j < number_departures; j++) {
			Plane current_plane(flight_number++, current_time, departing);
			if (small_airport.can_depart(current_plane) != success)
				current_plane.refuse();
		}

		Plane moving_plane;
		switch (small_airport.activity(current_time, moving_plane)) {
			//  Let at most one Plane onto the Runway at current_time.
		case land:
			moving_plane.land(current_time);
			break;
		case takeoff:
			moving_plane.fly(current_time);
			break;
		case idle:
			run_idle(current_time);
		}
	}
	small_airport.shut_down(end_time);
}
void test_2()
{
	const int RUNWAYS = 2;
	int end_time;            //  time to run simulation
	int queue_limit;         //  size of Runway queues
	int flight_number = 0;
	double arrival_rate, departure_rate;
	initialize(end_time, queue_limit, arrival_rate, departure_rate);
	Random variable(true);
	Airport small_airport(queue_limit, incoming);
	small_airport.addRunway(queue_limit, outgoing);

	for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals

		while (small_airport.roleOfSelection() != incoming) // select the runway for incoming flights
			small_airport.selectNext();
		int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
		for (int i = 0; i < number_arrivals; i++) {
			Plane current_plane(flight_number++, current_time, arriving);
			if (small_airport.can_land(current_plane) != success)
				current_plane.refuse();
		}

		while (small_airport.roleOfSelection() != outgoing) // select the runway for outgoing flights
			small_airport.selectNext();
		int number_departures = variable.poisson(departure_rate); //  current departure requests
		for (int j = 0; j < number_departures; j++) {
			Plane current_plane(flight_number++, current_time, departing);
			if (small_airport.can_depart(current_plane) != success)
				current_plane.refuse();
		}

		Plane moving_plane[RUNWAYS];
		for (int i = 0; i < RUNWAYS; i++)
		{
			switch (small_airport.activity(current_time, moving_plane[i])) {
				//  Let at most one Plane onto the Runway at current_time.
			case land:
				moving_plane[i].land(current_time);
				break;
			case takeoff:
				moving_plane[i].fly(current_time);
				break;
			case idle:
				run_idle(current_time);
			}
			small_airport.selectNext();
		}

	}
	small_airport.shut_down(end_time);
}
void test_3()
{
	const int RUNWAYS = 2;
	int end_time;            //  time to run simulation
	int queue_limit;         //  size of Runway queues
	int flight_number = 0;
	double arrival_rate, departure_rate;
	initialize(end_time, queue_limit, arrival_rate, departure_rate);
	Random variable(true);
	Airport small_airport(queue_limit, incoming);
	small_airport.addRunway(queue_limit, outgoing);
	// When redirect is true, all incoming flights are directed to outgoing runway instead
	bool redirect;
	bool incoming_empty;
	bool outgoing_empty;

	for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals

		redirect = false;
		incoming_empty = false;
		outgoing_empty = false;

		// Checks for incoming runway
		selectNextIncoming(small_airport);
		if (small_airport.sizeOfIncomingQueueForSelection() == 0)
			incoming_empty = true;
		if (small_airport.sizeOfIncomingQueueForSelection() == queue_limit - 1)
			redirect = true;

		// Checks for outgoing runway
		selectNextOutgoing(small_airport);
		if (small_airport.sizeOfOutgoingQueueForSelection() == 0)
			outgoing_empty = true;


		int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
		for (int i = 0; i < number_arrivals; i++) {

			if (redirect) // If redirect is true, redirect arriving plane to outoing runway
			{
				selectNextOutgoing(small_airport);
				Plane current_plane(flight_number++, current_time, arriving);
				if (small_airport.can_land(current_plane) != success)
					current_plane.refuse();
			}
			else
			{
				// If outgoing runway has no queue AND incoming runway has some queue, redirect plane to outgoing runway
				if (outgoing_empty && !incoming_empty) 
					selectNextOutgoing(small_airport);
				// Else direct plane to incoming runway
				else
					selectNextIncoming(small_airport);

				Plane current_plane(flight_number++, current_time, arriving);
				if (small_airport.can_land(current_plane) != success)
					current_plane.refuse();
			}

		}

		int number_departures = variable.poisson(departure_rate); //  current departure requests
		for (int j = 0; j < number_departures; j++) {

			if (redirect) // If redirect is true, departing planes are directed on outgoing runway
			{
				selectNextOutgoing(small_airport);
				Plane current_plane(flight_number++, current_time, departing);
				if (small_airport.can_depart(current_plane) != success)
					current_plane.refuse();
			}
			else
			{
				// If incoming runway has no queue AND outgoing runway has some queue, redirect plane to incoming runway
				if (incoming_empty && !outgoing_empty)
					selectNextIncoming(small_airport);
				// Else direct plane to outgoing runway
				else
					selectNextOutgoing(small_airport);

				Plane current_plane(flight_number++, current_time, departing);
				if (small_airport.can_depart(current_plane) != success)
					current_plane.refuse();
			}
		}

		Plane moving_plane[RUNWAYS];
		for (int i = 0; i < RUNWAYS; i++)
		{
			switch (small_airport.activity(current_time, moving_plane[i])) {
				//  Let at most one Plane onto the Runway at current_time.
			case land:
				moving_plane[i].land(current_time);
				break;
			case takeoff:
				moving_plane[i].fly(current_time);
				break;
			case idle:
				run_idle(current_time);
			}
			small_airport.selectNext();
		}

	}
	small_airport.shut_down(end_time);
}
