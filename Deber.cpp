#include <iostream> #include <fstream> #include <string> #include <limits>

using namespace std;

// Estructura para organizar los datos del estudiante struct Estudiante {
string nombre; int edad; string carrera;
float promedio;
};

// Función para validar que la entrada sea un número
 
void validarNumero() { while (cin.fail()) {
cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cout << "Error: Ingrese un valor numerico valido: ";
}
}

// Función para registrar y guardar los datos void registrarEstudiante() {
Estudiante est; ofstream archivo;

// Uso de ios::app para añadir datos sin borrar los anteriores archivo.open("estudiantes.txt", ios::app);

if (archivo.fail()) {
cout << "No se pudo abrir el archivo para guardar datos." << endl; return;
}

cin.ignore(); // Limpiar buffer antes de leer strings con espacios cout << "\n--- Registro de Estudiante ---" << endl;

cout << "Nombre: "; getline(cin, est.nombre);

cout << "Edad: "; cin >> est.edad; validarNumero();

cin.ignore();
cout << "Carrera: "; getline(cin, est.carrera);

cout << "Promedio: "; cin >> est.promedio; validarNumero();

// Guardar en el archivo con formato
archivo << "Nombre: " << est.nombre << " | "
<< "Edad: " << est.edad << " | "
<< "Carrera: " << est.carrera << " | "
<< "Promedio: " << est.promedio << endl;

// Uso de close() según requerimiento archivo.close();
 
cout << "\nDatos guardados exitosamente en 'estudiantes.txt'." << endl;
}

int main() { int opcion;

do {
cout << "\n====================================" << endl; cout << " SISTEMA DE GESTION ACADEMICA" << endl;
cout << "====================================" << endl;
cout << "1. Registrar Estudiante" << endl; cout << "2. Salir" << endl;
cout << "Seleccione una opcion: "; cin >> opcion;
validarNumero();

switch (opcion) { case 1:
registrarEstudiante(); break;
case 2:
cout << "Saliendo del programa..." << endl; break;
default:
cout << "Opcion no valida. Intente de nuevo." << endl;
}
} while (opcion != 2);

return 0;
}
