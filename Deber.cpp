#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registrarEstudiante() {
    ofstream archivo;
    archivo.open("estudiantes.txt", ios::app);

    if (archivo.fail()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string nombre, carrera;
    int edad;
    float promedio;

    cin.ignore(); // limpiar buffer

    cout << "Ingrese el nombre: ";
    getline(cin, nombre);

    // Validación de edad
    do {
        cout << "Ingrese la edad: ";
        cin >> edad;
        if (edad <= 0) {
            cout << "Edad inválida. Intente nuevamente.\n";
        }
    } while (edad <= 0);

    cin.ignore();

    cout << "Ingrese la carrera: ";
    getline(cin, carrera);

    // Validación de promedio
    do {
        cout << "Ingrese el promedio (0 - 10): ";
        cin >> promedio;
        if (promedio < 0 || promedio > 10) {
            cout << "Promedio inválido. Intente nuevamente.\n";
        }
    } while (promedio < 0 || promedio > 10);

    // Guardar en archivo
    archivo << "Nombre: " << nombre << endl;
    archivo << "Edad: " << edad << endl;
    archivo << "Carrera: " << carrera << endl;
    archivo << "Promedio: " << promedio << endl;
    archivo << "------------------------" << endl;

    archivo.close();

    cout << "Estudiante guardado correctamente.\n";
}

void mostrarMenu() {
    int opcion;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;
            case 2:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }

    } while (opcion != 2);
}

int main() {
    mostrarMenu();
    return 0;
}