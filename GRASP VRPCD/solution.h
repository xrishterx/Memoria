#ifndef __SOLUTION_H__
#define __SOLUTION_H__

#include "imports.h"
#include "vehicle.h"

class Solution{
	public:
		//vechiculos utilizados en la solucion
		vector<Vehicle> vehicles;
		/*vector que informa los procesos de consolidacion de cada vehiculo en el CD de la forma [[(10,1),(11,2)]  donde cada tupla es (cantidad_elementos, supplier)
																								  [(5,3),(6,4)]]
		*/
		vector<vector<vector<tuple<int,int>>>> consolidation;

		// funciones de la clase
		Solution();
};
#endif