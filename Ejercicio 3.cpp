#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Estudiante {
    int codigo;
    string nombre;
    double nota1;
    double nota2;
    double nota3;
    double promedio;
};

vector<Estudiante> estudiantes;

void agregarEstudiante() {
    Estudiante estudiante;
    cout << "Ingrese el codigo del estudiante: ";
    cin >> estudiante.codigo;
    cout << "Ingrese el nombre del estudiante: ";
    cin.ignore();
    getline(cin, estudiante.nombre);
    cout << "Ingrese la nota 1 del estudiante: ";
    cin >> estudiante.nota1;
    cout << "Ingrese la nota 2 del estudiante: ";
    cin >> estudiante.nota2;
    cout << "Ingrese la nota 3 del estudiante: ";
    cin >> estudiante.nota3;

    estudiante.promedio = (estudiante.nota1 + estudiante.nota2 + estudiante.nota3) / 3.0;

    estudiantes.push_back(estudiante);
}

void mostrarPromedios() {
    int desaprobados = 0;
    for (vector<Estudiante>::iterator it = estudiantes.begin(); it != estudiantes.end(); ++it) {
        Estudiante estudiante = *it;
        cout << "Codigo: " << estudiante.codigo << ", Nombre: " << estudiante.nombre << ", Promedio: " << estudiante.promedio << endl;
        if (estudiante.promedio < 4.0) {
            desaprobados++;
        }
    }
    cout << "Cantidad de estudiantes desaprobados: " << desaprobados << endl;
}

bool compareEstudiantes(const Estudiante& a, const Estudiante& b) {
    return a.promedio > b.promedio;
}

void ordenarEstudiantes() {
    sort(estudiantes.begin(), estudiantes.end(), compareEstudiantes);
}

void mostrarEstudiantesOrdenados() {
    cout << "Estudiantes ordenados por promedio descendente:" << endl;
    for (vector<Estudiante>::iterator it = estudiantes.begin(); it != estudiantes.end(); ++it) {
        Estudiante estudiante = *it;
        cout << "Codigo: " << estudiante.codigo << ", Nombre: " << estudiante.nombre << ", Promedio: " << estudiante.promedio << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "1. Agregar estudiante" << endl;
        cout << "2. Mostrar promedios" << endl;
        cout << "3. Ordenar estudiantes" << endl;
        cout << "4. Mostrar estudiantes ordenados" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarEstudiante();
                break;
            case 2:
                mostrarPromedios();
                break;
            case 3:
                ordenarEstudiantes();
                break;
            case 4:
                mostrarEstudiantesOrdenados();
                break;
            case 5:
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}

