#include <map>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class Environment {
public:
    // Constructor
    Environment() {}

    // Destructor
    ~Environment() {}

    // Método para insertar un símbolo en el entorno
    void insert(const string& name, int value) {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            // Si el símbolo ya existe, lanzar una excepción
            throw runtime_error("Error: Symbol '" + name + "' already exists in the environment.");
        } else {
            // Insertar el nuevo símbolo en el entorno
            symbolTable[name] = value;
        }
    }
    // Método para obtener el valor de un símbolo desde el entorno
    int lookup(const string& name, int defaultValue = 0) {
        try {
            // Buscar el símbolo en el entorno
            auto it = symbolTable.find(name);
            if (it != symbolTable.end()) {
                // Si el símbolo existe, devolver su valor
                return it->second;
            } else {
                // Si el símbolo no existe, lanzar una excepción
                throw out_of_range("Error: Symbol '" + name + "' not found in the environment.");
            }
        } catch (const exception& e) {
            cerr << e.what() << endl;
            // Devolver el valor predeterminado en caso de excepción
            return defaultValue;
        }
    }

private:
    map<string, int> symbolTable;
};
