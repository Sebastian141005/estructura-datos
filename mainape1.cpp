#include <iostream>   // Librería para entrada y salida de datos (cout, cin)
#include <vector>     // Librería que permite usar vectores dinámicos
#include <string>     // Librería para manejar datos tipo texto (string)

using namespace std;  // Permite usar cout, cin, string, vector sin escribir std::


// ----------------------------------------------------
// ESTRUCTURA VEHICULO
// ----------------------------------------------------
// Una estructura es un tipo de dato que permite agrupar
// varias variables relacionadas en un solo registro.
// En este caso representa un vehículo dentro del parqueadero.

struct Vehiculo {

    string placa;       // Guarda la placa del vehículo
    string marca;       // Guarda la marca del vehículo
    string modelo;      // Guarda el modelo del vehículo
    string color;       // Guarda el color del vehículo
    int horaEntrada;    // Guarda la hora en que entró al parqueadero

};


// ----------------------------------------------------
// FUNCIÓN mostrarVehiculo
// ----------------------------------------------------
// Esta función recibe un vehículo y muestra todos sus
// datos en pantalla.
// Se usa cuando queremos imprimir la información de
// un vehículo registrado.

void mostrarVehiculo(Vehiculo v) {

    cout << "Placa: " << v.placa << endl;
    cout << "Marca: " << v.marca << endl;
    cout << "Modelo: " << v.modelo << endl;
    cout << "Color: " << v.color << endl;
    cout << "Hora de entrada: " << v.horaEntrada << endl;

    cout << "-----------------------------" << endl;
}


// ----------------------------------------------------
// FUNCIÓN registrarVehiculo
// ----------------------------------------------------
// Esta función permite ingresar un nuevo vehículo al sistema.
// Se pide al usuario que introduzca los datos del vehículo
// y luego se guarda dentro del vector usando push_back.

void registrarVehiculo(vector<Vehiculo>& parqueadero) {

    Vehiculo v;   // Se crea una variable temporal tipo Vehiculo

    // Se solicitan los datos al usuario

    cout << "Ingrese placa: ";
    cin >> v.placa;

    cout << "Ingrese marca: ";
    cin >> v.marca;

    cout << "Ingrese modelo: ";
    cin >> v.modelo;

    cout << "Ingrese color: ";
    cin >> v.color;

    cout << "Ingrese hora de entrada: ";
    cin >> v.horaEntrada;

    // push_back agrega el nuevo registro al final del vector
    parqueadero.push_back(v);

    cout << "Vehiculo registrado correctamente.\n";
}


// ----------------------------------------------------
// FUNCIÓN mostrarTodos
// ----------------------------------------------------
// Esta función recorre todo el vector y muestra
// todos los vehículos almacenados.
// Se utiliza un ciclo for para recorrer cada posición.

void mostrarTodos(vector<Vehiculo>& parqueadero) {

    // Si el vector está vacío se informa al usuario
    if (parqueadero.size() == 0) {

        cout << "No hay vehiculos registrados.\n";
        return;

    }

    cout << "\nLISTA DE VEHICULOS EN EL PARQUEADERO\n";

    // Ciclo que recorre todos los elementos del vector
    for (int i = 0; i < parqueadero.size(); i++) {

        // Se muestra cada vehículo usando la función creada antes
        mostrarVehiculo(parqueadero[i]);

    }
}


// ----------------------------------------------------
// FUNCIÓN buscarVehiculo
// ----------------------------------------------------
// Esta función permite buscar un vehículo usando la placa.
// Se recorre el vector y se compara cada placa con la ingresada.

void buscarVehiculo(vector<Vehiculo>& parqueadero) {

    string placaBuscar;

    cout << "Ingrese la placa a buscar: ";
    cin >> placaBuscar;

    // Se recorre todo el vector
    for (int i = 0; i < parqueadero.size(); i++) {

        // Se compara la placa ingresada con la del registro
        if (parqueadero[i].placa == placaBuscar) {

            cout << "Vehiculo encontrado:\n";

            // Se muestran los datos del vehículo encontrado
            mostrarVehiculo(parqueadero[i]);

            return; // Termina la función si se encuentra

        }
    }

    // Si termina el ciclo sin encontrar coincidencia
    cout << "Vehiculo no encontrado.\n";
}


// ----------------------------------------------------
// FUNCIÓN modificarVehiculo
// ----------------------------------------------------
// Permite cambiar los datos de un vehículo existente.
// Se busca por placa y si se encuentra se reemplazan
// los datos antiguos por nuevos datos.

void modificarVehiculo(vector<Vehiculo>& parqueadero) {

    string placaBuscar;

    cout << "Ingrese la placa del vehiculo a modificar: ";
    cin >> placaBuscar;

    // Se recorre el vector buscando la placa
    for (int i = 0; i < parqueadero.size(); i++) {

        if (parqueadero[i].placa == placaBuscar) {

            cout << "Ingrese nueva marca: ";
            cin >> parqueadero[i].marca;

            cout << "Ingrese nuevo modelo: ";
            cin >> parqueadero[i].modelo;

            cout << "Ingrese nuevo color: ";
            cin >> parqueadero[i].color;

            cout << "Ingrese nueva hora de entrada: ";
            cin >> parqueadero[i].horaEntrada;

            cout << "Vehiculo modificado correctamente.\n";

            return;
        }
    }

    cout << "Vehiculo no encontrado.\n";
}


// ----------------------------------------------------
// FUNCIÓN eliminarVehiculo
// ----------------------------------------------------
// Permite eliminar un registro del vector.
// Primero se busca el vehículo por placa y luego se usa
// erase() para eliminar esa posición del vector.

void eliminarVehiculo(vector<Vehiculo>& parqueadero) {

    string placaEliminar;

    cout << "Ingrese la placa del vehiculo a eliminar: ";
    cin >> placaEliminar;

    for (int i = 0; i < parqueadero.size(); i++) {

        if (parqueadero[i].placa == placaEliminar) {

            // erase elimina el elemento en la posición indicada
            parqueadero.erase(parqueadero.begin() + i);

            cout << "Vehiculo eliminado correctamente.\n";
            return;
        }
    }

    cout << "Vehiculo no encontrado.\n";
}


// ----------------------------------------------------
// FUNCIÓN reporteFinal
// ----------------------------------------------------
// Muestra todos los vehículos registrados y el total.
// Sirve como resumen final del sistema.

void reporteFinal(vector<Vehiculo>& parqueadero) {

    cout << "\nREPORTE FINAL\n";

    // size() indica cuántos elementos tiene el vector
    cout << "Total de vehiculos registrados: " << parqueadero.size() << endl;

    for (int i = 0; i < parqueadero.size(); i++) {

        mostrarVehiculo(parqueadero[i]);

    }
}


// ----------------------------------------------------
// FUNCIÓN PRINCIPAL (main)
// ----------------------------------------------------
// Aquí inicia la ejecución del programa.
// Se crea el vector que almacenará los vehículos
// y se maneja el menú interactivo del sistema.

int main() {

    vector<Vehiculo> parqueadero;  // Vector que almacena todos los vehículos


    // =====================================================
    // 10 REGISTROS INICIALES (REQUISITO DEL TRABAJO)
    // =====================================================
    // Estos registros se agregan automáticamente cuando
    // el programa inicia para cumplir con el mínimo
    // de registros solicitados.

    parqueadero.push_back((Vehiculo){"ABC123","Toyota","Corolla","Rojo",8});
    parqueadero.push_back((Vehiculo){"DEF456","Chevrolet","Spark","Azul",9});
    parqueadero.push_back((Vehiculo){"GHI789","Kia","Rio","Negro",10});
    parqueadero.push_back((Vehiculo){"JKL111","Hyundai","Accent","Blanco",7});
    parqueadero.push_back((Vehiculo){"MNO222","Mazda","3","Gris",11});
    parqueadero.push_back((Vehiculo){"PQR333","Nissan","Versa","Rojo",12});
    parqueadero.push_back((Vehiculo){"STU444","Suzuki","Swift","Azul",6});
    parqueadero.push_back((Vehiculo){"VWX555","Ford","Fiesta","Negro",8});
    parqueadero.push_back((Vehiculo){"YZA666","Renault","Logan","Blanco",9});
    parqueadero.push_back((Vehiculo){"BCD777","Volkswagen","Gol","Gris",10});


    int opcion;  // Variable que guarda la opción del menú


    // Ciclo do while que mantiene activo el menú
    // hasta que el usuario elija salir

    do {

        cout << "\n------ SISTEMA DE PARQUEADERO ------\n";

        cout << "1. Registrar vehiculo\n";
        cout << "2. Mostrar todos los vehiculos\n";
        cout << "3. Buscar vehiculo por placa\n";
        cout << "4. Modificar vehiculo\n";
        cout << "5. Eliminar vehiculo\n";
        cout << "6. Generar reporte final\n";
        cout << "7. Salir\n";

        cout << "Seleccione una opcion: ";
        cin >> opcion;


        // switch ejecuta diferentes acciones según
        // la opción elegida por el usuario

        switch(opcion) {

            case 1:
                registrarVehiculo(parqueadero);
                break;

            case 2:
                mostrarTodos(parqueadero);
                break;

            case 3:
                buscarVehiculo(parqueadero);
                break;

            case 4:
                modificarVehiculo(parqueadero);
                break;

            case 5:
                eliminarVehiculo(parqueadero);
                break;

            case 6:
                reporteFinal(parqueadero);
                break;

            case 7:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opcion invalida.\n";

        }

    } while(opcion != 7); // El programa sigue ejecutándose hasta elegir salir


    return 0; // Fin del programa

}
