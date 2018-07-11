#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "imports.h"
#include "suplier.h"
#include "customer.h"
#include "crossdock.h"
#include "node.h"



class Vehicle{
	public:
		int total_capacity,fixed_time,unit_time,remaining_capacity, id;
		vector<Suplier> pickup_route;
		vector<Customer> delivery_route;
		// rutas de crossdocks luego del pickup route (para IAA siempre habra solo 1 CD)
		vector<Crossdock> crossdock_route;
		// Lista de la cantidad items que contien de cada supplier, en cada ruta de la forma [{10,1},{11,2}...] 10 elem, del suplier 1, 11 del 2, etc.
		vector<tuple<int,int>> pickup_items, delivery_items;
		// Lista de tiempos de llegada y salida en cada nodo de la forma [{t_llegada1,t_salida1},{t_llegada2,t_salida2}...]
		vector<tuple<float,float>> pickup_times,crossdock_times,delivery_times;
		//Lugar de partida y termino de los vehiculos, por el momento se asume el primer CD leido
		Node vehicle_depot;
		// TIempo en el que el vehiculo deja un crossdock luego de la consolidacion
		int departure_cd_time;

		// VELLOCIDAD DE LOS VEHICULOS EN EL PAPPER ESTA EN KM/H, PERO se almacena en m/s
		float speed;
		// TIEMPO QUE SE DEMORA EN DESCARGAR LOS PRODUCTOS (NO ES EL TIEMPO EN EL QUE DESCARGA TODOS LOS PRODUCTOS).
		float download_time;
		// TIEMPO QUE SE DEMORA EN CARGAR LOS PRODUCTOS CORRESPONDIENTES.
		float reload_time;


		// PRE PROCESAMIENTO ------------------------------------------
		// Estructuras que guardan la id de los vehiculos involucrados en cada item
		vector<int> involved_pickup;
		vector<int> involved_delivery;


		// funciones de la clase
		Vehicle(int,int,int, Node, int,float);
		Vehicle();
		//funcion que setea los tiempos de llegada y salida de cada nodo de todas las rutas
		void set_times();
		//funcion que determina si la rita cumple con los TW
		bool feasible_route();
		float get_pickup_cost();
		float get_crossdock_cost();
		float get_delivery_cost();
		//funcion que retorna el costo del vehiculo
		float get_total_cost();
		//funcion que obtiene la capacidad restante con la que llega al CD luego de la ruta de pickup
		int get_pickup_capacity();
		// funcion que setea el atributo remaining capacity
		void set_remaining_capacity();
		// funcion que obtiene los items a descargar en un CD si la opcion es 0, y los items a cargar en un CD si la opcion es 1
		vector<int> get_items(int);
		//funciones que setean el atributo download_stime y upload_time
		void set_download_time();
		void set_reload_time();
		

};
#endif