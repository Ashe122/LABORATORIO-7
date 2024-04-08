#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Definición de la clase Persona
class Persona {
private:
    string nombre;
    int edad;
    string ocupacion;

public:
    // Constructor
    Persona(string n, int e, string o) : nombre(n), edad(e), ocupacion(o) {}

    // Métodos para establecer y obtener valores de los atributos
    void setNombre(string n) { nombre = n; }
    void setEdad(int e) { edad = e; }
    void setOcupacion(string o) { ocupacion = o; }

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    string getOcupacion() const { return ocupacion; }
};

// Función para guardar datos en un archivo de texto
void guardarDatos(const vector<Persona>& personas) {
    ofstream archivo("datos.txt");
    if (archivo.is_open()) {
        for (const auto& persona : personas) {
            archivo << persona.getNombre() << " " << persona.getEdad() << " " << persona.getOcupacion() << endl;
        }
        archivo.close();
        cout << "Datos guardados correctamente en el archivo 'datos.txt'" << endl;
    } else {
        cout << "Error al abrir el archivo 'datos.txt'" << endl;
    }
}

// Función para leer datos desde un archivo de texto
void leerDatos() {
    ifstream archivo("datos.txt");
    if (archivo.is_open()) {
        string nombre, ocupacion;
        int edad;
        while (archivo >> nombre >> edad >> ocupacion) {
            cout << "Nombre: " << nombre << ", Edad: " << edad << ", Ocupación: " << ocupacion << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo 'datos.txt'" << endl;
    }
}

// Clase Estudiante que hereda de Persona
class Estudiante : public Persona {
private:
    string numEstudiante;
    float promedioCalificaciones;

public:
    // Constructor
    Estudiante(string n, int e, string o, string ne, float pc)
        : Persona(n, e, o), numEstudiante(ne), promedioCalificaciones(pc) {}

    // Métodos para establecer y obtener valores de atributos específicos
    void setNumEstudiante(string ne) { numEstudiante = ne; }
    void setPromedioCalificaciones(float pc) { promedioCalificaciones = pc; }

    string getNumEstudiante() const { return numEstudiante; }
    float getPromedioCalificaciones() const { return promedioCalificaciones; }
};

// Función para ordenar una lista de nombres de estudiantes
void ordenarNombres(vector<string>& nombres) {
    sort(nombres.begin(), nombres.end());
}

int main() {
    vector<Persona> personas;
    vector<string> nombres;

    // Ingreso de datos de personas
    cout << " -----hola personita----Ingresa los datos de las personas y escribe 'fin' para terminar:" << endl;
    while (true) {
        string nombre, ocupacion;
        int edad;
        cout << "Nombre: ";
        cin >> nombre;
        if (nombre == "fin") break;
        cout << "Edad: ";
        cin >> edad;
        cout << "Ocupación: ";
        cin >> ocupacion;

        // Crear objeto Persona y agregarlo al vector de personas
        personas.push_back(Persona(nombre, edad, ocupacion));
        nombres.push_back(nombre);  // Para el algoritmo de ordenamiento
    }

    // Guardar datos en archivo de texto
    guardarDatos(personas);

    // Leer datos del archivo y mostrarlos en pantalla
    cout << "\nDatos almacenados en el archivo 'datos.txt':" << endl;
    leerDatos();

    // Instanciar objetos de la clase Estudiante
    Estudiante estudiante("Juan", 20, "Estudiante", "12345", 8.5);
    cout << "\nDatos del estudiante:" << endl;
    cout << "Nombre: " << estudiante.getNombre() << endl;
    cout << "Edad: " << estudiante.getEdad() << endl;
    cout << "Ocupación: " << estudiante.getOcupacion() << endl;
    cout << "Número de estudiante: " << estudiante.getNumEstudiante() << endl;
    cout << "Promedio de calificaciones: " << estudiante.getPromedioCalificaciones() << endl;

    // Ordenar lista de nombres de estudiantes
    ordenarNombres(nombres);
    cout << "\nNombres de estudiantes ordenados:" << endl;
    for (const auto& nombre : nombres) {
        cout << nombre << endl;
    }

    return 0;
}
