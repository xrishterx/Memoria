#include "solution.h"

Solution::Solution(){
}


bool Solution::feasible_capacity(){

	vector <Vehicle>::iterator vehicle_iterator;
	int demand,remaining_pickup_capacity,remaining_delivery_capacity;

	//cout<<"FEASIBLE CAPACITY: ANTES PRIMER FOR"<<endl;
	for (vehicle_iterator = this->vehicles.begin(); vehicle_iterator != this->vehicles.end(); ++vehicle_iterator) {

		remaining_pickup_capacity = vehicle_iterator->total_capacity;
		remaining_delivery_capacity = vehicle_iterator->total_capacity;
	//cout<<"FEASIBLE CAPACITY: ANTES SEGUNDO FOR"<<endl;

		for(int i=0; (unsigned)i<vehicle_iterator->pickup_items.size();i++){

			demand = get<0>(vehicle_iterator->pickup_items[i]);
			remaining_pickup_capacity -= demand;
		}
	//cout<<"FEASIBLE CAPACITY: ANTES TERCER FOR"<<endl;

		for(int i=0; (unsigned)i<vehicle_iterator->delivery_items.size();i++){

			demand = get<0>(vehicle_iterator->delivery_items[i]);
			remaining_delivery_capacity -= demand;
		}

		if(remaining_delivery_capacity < 0 || remaining_pickup_capacity <0 ){
			return false;
		}

	}

	return true;
}

bool Solution::feasible_tw(){

	for (int i=0; (unsigned)i < this->vehicles.size(); i++) {
		if(!this->vehicles[i].feasible_route()) return false;
	}
	return true;
}

void Solution::set_vehicles_times(){
	// se aplica set_times() a todos los vehiculos
	for (int i=0; (unsigned)i < this->vehicles.size(); i++) {
		this->vehicles[i].set_times();
	}
}

tuple<int,int> Solution::count_nodes(){
	vector <Vehicle>::iterator vehicle_iterator;
	int pickup_nodes = 0;
	int delivery_nodes = 0;

	for (vehicle_iterator = this->vehicles.begin(); vehicle_iterator != this->vehicles.end(); ++vehicle_iterator) {

		pickup_nodes += vehicle_iterator->pickup_route.size();
		delivery_nodes += vehicle_iterator->delivery_route.size();

	}

	return make_tuple(pickup_nodes,delivery_nodes);
}
