#include <iostream>

using namespace std;

int main() {
    int matriz1[2][3];
    int matriz2[3][2];

    cout << "Ingrese los numeros para la primera matriz (2x3):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            while (true) {
                int num;
                cout << "Ingresa un numero entre 1 y 10 para la posicion (" << i << ", " << j << "): ";
                cin >> num;
                if (1 <= num && num <= 10) {
                    matriz1[i][j] = num;
                    break;
                } else {
                    cout << "Numero invalido. Intente de nuevo." << endl;
                }
            }
        }
    }

    cout << "Ingrese los numeros para la segunda matriz (3x2):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            while (true) {
                int num;
                cout << "Ingresa un numero entre 1 y 10 para la posicion (" << i << ", " << j << "): ";
                cin >> num;
                if (1 <= num && num <= 10) {
                    matriz2[i][j] = num;
                    break;
                } else {
                    cout << "Numero invalido. Intente de nuevo." << endl;
                }
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz1[i][j] > 5) {
                matriz1[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (matriz2[i][j] < 6) {
                matriz2[i][j] = 0;
            }
        }
    }

    cout << "Matriz 1 modificada:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriz1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Matriz 2 modificada:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matriz2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


