#include "imports.h"
#include "instance.h"
#include "request.h"
#include "grasp.h"
#include "solution.h"


// FUNCION QUE LEERA LA VENTANA DE COMANDOS 
tuple<string,int,int,int,int,int,int> read_input(int argc, char **argv){

	string input_file = (char *)(argv[1]);
	int list_size = stoi((char *)(argv[2]));
	int iterations = stoi((char *)(argv[3]));
	int seed = stoi((char *)(argv[7]));
	int porc_movimiento1 = stoi((char *)(argv[4]));
	int porc_movimiento2 = stoi((char *)(argv[5]));
	int porc_movimiento3 = stoi((char *)(argv[6]));

	return make_tuple(input_file,list_size,iterations,porc_movimiento1,porc_movimiento2,porc_movimiento3,seed);

}


int main(int argc, char *argv[]) {

	if(argc != 8){
		cout << "El formato para la ejecucion es: " << argv[0] << " archivo_entrada tamaño_lista iteraciones porc_movimiento1 porc_movimiento2 porc_movimiento3 semilla"<<endl;
		return 0;
	}

	string input_file;
	int list_size,seed,iterations,porc_movimiento1,porc_movimiento2,porc_movimiento3;

	tie(input_file,list_size,iterations,porc_movimiento1,porc_movimiento2,porc_movimiento3,seed) = read_input(argc,argv);

	if(list_size<=0){
		cout<<"El tamaño de la lista debe ser mayor o igual a 1"<<endl;
		return 0;
	}

	srand(seed);
	Instance instance(input_file);
	instance.read_instance();

	Grasp grasp(instance,list_size);

	clock_t start_time = clock();
	Solution final_solution = grasp.run(iterations,porc_movimiento1,porc_movimiento2,porc_movimiento3);	
	clock_t end_time = clock();

	if(feasible_solution(final_solution)){
		cout<<"LA SOLUCION FINAL SIIII ES FACTIBLE"<< endl;
	}
	else{
		cout<<"LA SOLUCION FINAL NOOOO ES FACTIBLE"<< endl;
	}

	cout<<"La solucion inicial es"<<endl;
	print_solution(final_solution);
	cout<<"----------------------------------------------------"<<endl;
	cout<<"................Los tiempos son ...................."<<endl;
	print_times(final_solution);

	cout<<"CANTIDAD DE AUTOS USADOS: "<<final_solution.vehicles.size()<<endl;
	cout<<"COSTO TOTAL DE: "<< grasp.evaluation_function(final_solution)<<endl;

	double total_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;
	cout<<" Se demoro: "<< total_time << " segundos" << endl;

	export_solution(final_solution);


    return 0;

}