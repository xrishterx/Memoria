#include "customer.h"


// CONSTRUCTOR
Customer::Customer (int id, int x_coord, int y_coord, int ready_time, int due_date ){
	this->type = 2;
	this->id = id;
	this->x_coord = x_coord;
	this->y_coord = y_coord;
	this->ready_time = ready_time;
	this->due_date = due_date;
}

Customer::Customer (){
}

//Customer::~Customer(){
//}