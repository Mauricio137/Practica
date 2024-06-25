#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Empleado {
    string nombre;
    char tipo; // C-contratado o N-nombrado
    double sueldoBasico;
    double deduccionesAFP;
    double deduccionesSeguro;
    double bonificacion;
    double sueldoNeto;
};

vector<Empleado> empleados;

void agregarEmpleado() {
    Empleado empleado;
    cout << "Ingrese el nombre del empleado: ";
    cin.ignore();
    getline(cin, empleado.nombre);
    cout << "Ingrese el tipo de empleado (C-contratado o N-nombrado): ";
    cin >> empleado.tipo;
    cout << "Ingrese el sueldo basico del empleado: ";
    cin >> empleado.sueldoBasico;

    empleado.deduccionesAFP = empleado.sueldoBasico * 0.08;
    empleado.deduccionesSeguro = empleado.sueldoBasico * 0.05;

    if (empleado.tipo == 'C') {
        empleado.bonificacion = empleado.sueldoBasico * 0.08;
    } else if (empleado.tipo == 'N') {
        empleado.bonificacion = empleado.sueldoBasico * 0.12;
    }

    empleado.sueldoNeto = empleado.sueldoBasico - empleado.deduccionesAFP - empleado.deduccionesSeguro + empleado.bonificacion;

    empleados.push_back(empleado);
}

void mostrarDetallesEmpleado() {
    for (vector<Empleado>::iterator it = empleados.begin(); it != empleados.end(); ++it) {
        Empleado empleado = *it;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Tipo: " << empleado.tipo << endl;
        cout << "Sueldo basico: " << empleado.sueldoBasico << endl;
        cout << "Deducciones AFP: " << empleado.deduccionesAFP << endl;
        cout << "Deducciones seguro: " << empleado.deduccionesSeguro << endl;
        cout << "Bonificacion: " << empleado.bonificacion << endl;
        cout << "Sueldo neto: " << empleado.sueldoNeto << endl;
        cout << endl;
    }
}

void mostrarResumen() {
    int contratados = 0;
    int nombrados = 0;
    double totalSueldosNetosContratados = 0;
    double totalSueldosNetosNombrados = 0;

    for (vector<Empleado>::iterator it = empleados.begin(); it != empleados.end(); ++it) {
        Empleado empleado = *it;
        if (empleado.tipo == 'C') {
            contratados++;
            totalSueldosNetosContratados += empleado.sueldoNeto;
        } else if (empleado.tipo == 'N') {
            nombrados++;
            totalSueldosNetosNombrados += empleado.sueldoNeto;
        }
    }

    cout << "Resumen:" << endl;
    cout << "Cantidad de empleados contratados: " << contratados << endl;
    cout << "Total sueldos netos contratados: " << totalSueldosNetosContratados << endl;
    cout << "Cantidad de empleados nombrados: " << nombrados << endl;
    cout << "Total sueldos netos nombrados: " << totalSueldosNetosNombrados << endl;
}

int main() {
    int opcion;
    do {
        cout << "1. Agregar empleado" << endl;
        cout << "2. Mostrar detalles de empleados" << endl;
        cout << "3. Mostrar resumen" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarEmpleado();
                break;
            case 2:
                mostrarDetallesEmpleado();
                break;
            case 3:
                mostrarResumen();
                break;
            case 4:
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}

