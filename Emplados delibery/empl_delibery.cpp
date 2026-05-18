#include <iostream>
#include <string>

using namespace std;

// ===== Tipos de datos =====

// Registro interno
struct DatosRepartidor {
    string NomyApe;
    int DNI;
};

// Registro principal
struct Repartidor {
    string departamento;
    string zona;
    int anioIngreso;
    int reclamos;

    // Vector de entregas mensuales
    int entregas[12];

    // Registro anidado
    DatosRepartidor repartidor;
};

// =======================================


// ===== Subprograma 1 =====
// Mostrar repartidores sin reclamos
void mostrarSinReclamos(Repartidor empleados[], int cantidad) {

    int contador = 0;

    cout << "\n=== REPARTIDORES SIN RECLAMOS ===\n";

    for(int i = 0; i < cantidad; i++) {

        if(empleados[i].reclamos == 0) {

            cout << "-----------------------------\n";
            cout << "Nombre: "
                 << empleados[i].repartidor.NomyApe << endl;

            cout << "DNI: "
                 << empleados[i].repartidor.DNI << endl;

            cout << "Departamento: "
                 << empleados[i].departamento << endl;

            cout << "Zona: "
                 << empleados[i].zona << endl;

            contador++;
        }
    }

    cout << "-----------------------------\n";
    cout << "Cantidad total sin reclamos: "
         << contador << endl;
}

// =======================================


// ===== Subprograma 2 =====
// Mostrar repartidor/es con mayor cantidad
// de entregas en noviembre + diciembre
void mayorEntregas(Repartidor empleados[], int cantidad) {

    int mayor = 0;

    // Buscar el mayor
    for(int i = 0; i < cantidad; i++) {

        int total =
            empleados[i].entregas[10] + // noviembre
            empleados[i].entregas[11];  // diciembre

        if(total > mayor) {
            mayor = total;
        }
    }

    // Mostrar quienes alcanzaron el mayor
    cout << "\n=== MAYOR CANTIDAD DE ENTREGAS NOV/DIC ===\n";

    for(int i = 0; i < cantidad; i++) {

        int total =
            empleados[i].entregas[10] +
            empleados[i].entregas[11];

        if(total == mayor) {

            cout << "-----------------------------\n";

            cout << "Nombre: "
                 << empleados[i].repartidor.NomyApe << endl;

            cout << "DNI: "
                 << empleados[i].repartidor.DNI << endl;

            cout << "Departamento: "
                 << empleados[i].departamento << endl;

            cout << "Zona: "
                 << empleados[i].zona << endl;

            cout << "Total Nov+Dic: "
                 << total << endl;
        }
    }
}

// =======================================


// ===== Subprograma 3 =====
// Promedio de entregas en abril
float promedioEntregas(Repartidor empleados[],
                       int cantidad,
                       string zonaIngresada) {

    int suma = 0;
    int cantPersonas = 0;

    for(int i = 0; i < cantidad; i++) {

        if(empleados[i].zona == zonaIngresada) {

            suma += empleados[i].entregas[3]; // abril
            cantPersonas++;
        }
    }

    if(cantPersonas > 0) {
        return (float)suma / cantPersonas;
    }

    return 0;
}

// =======================================


// ===== Subprograma 4 =====
// Porcentaje de entregas por trimestre
void porcentajeEntregasPorTrimestre(
    Repartidor empleados[],
    int cantidad,
    string zonaIngresada) {

    int trim1 = 0;
    int trim2 = 0;
    int trim3 = 0;
    int trim4 = 0;

    // Sumar entregas
    for(int i = 0; i < cantidad; i++) {

        if(empleados[i].zona == zonaIngresada) {

            // Enero - Marzo
            trim1 += empleados[i].entregas[0]
                   + empleados[i].entregas[1]
                   + empleados[i].entregas[2];

            // Abril - Junio
            trim2 += empleados[i].entregas[3]
                   + empleados[i].entregas[4]
                   + empleados[i].entregas[5];

            // Julio - Septiembre
            trim3 += empleados[i].entregas[6]
                   + empleados[i].entregas[7]
                   + empleados[i].entregas[8];

            // Octubre - Diciembre
            trim4 += empleados[i].entregas[9]
                   + empleados[i].entregas[10]
                   + empleados[i].entregas[11];
        }
    }

    int totalZona =
        trim1 + trim2 + trim3 + trim4;

    if(totalZona > 0) {

        float p1 = (trim1 * 100.0) / totalZona;
        float p2 = (trim2 * 100.0) / totalZona;
        float p3 = (trim3 * 100.0) / totalZona;
        float p4 = (trim4 * 100.0) / totalZona;

        cout << "\n=== PORCENTAJE POR TRIMESTRE ===\n";

        cout << "Zona: "
             << zonaIngresada << endl;

        cout << "1er trimestre: "
             << p1 << "%\n";

        cout << "2do trimestre: "
             << p2 << "%\n";

        cout << "3er trimestre: "
             << p3 << "%\n";

        cout << "4to trimestre: "
             << p4 << "%\n";
    }
    else {

        cout << "\nNo hay entregas registradas en esa zona.\n";
    }
}

// =======================================


// ===== Programa principal =====
int main() {

    const int CANTIDAD = 50;

    Repartidor empleados[CANTIDAD];

    string zonaIngresada;

    // ===== Carga de ejemplo =====
    for(int i = 0; i < CANTIDAD; i++) {

        empleados[i].repartidor.NomyApe =
            "Repartidor " + to_string(i + 1);

        empleados[i].repartidor.DNI =
            30000000 + i;

        empleados[i].departamento =
            "Mendoza";

        empleados[i].zona =
            (i % 2 == 0) ? "Centro" : "Norte";

        empleados[i].anioIngreso =
            2020 + (i % 4);

        empleados[i].reclamos =
            i % 3;

        for(int j = 0; j < 12; j++) {

            empleados[i].entregas[j] =
                50 + i + j;
        }
    }

    // ===== Llamadas =====

    mostrarSinReclamos(empleados, CANTIDAD);

    mayorEntregas(empleados, CANTIDAD);

    cout << "\nIngrese una zona: ";
    cin >> zonaIngresada;

    cout << "\nPromedio de entregas en abril: "
         << promedioEntregas(
                empleados,
                CANTIDAD,
                zonaIngresada)
         << endl;

    porcentajeEntregasPorTrimestre(
        empleados,
        CANTIDAD,
        zonaIngresada);

    return 0;
}