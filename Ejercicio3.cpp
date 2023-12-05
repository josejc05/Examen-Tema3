#include <map>
#include <string>
#include <iostream>

using namespace std;

class Environment {
public:
    // Constructor
    Environment() {}

    // Destructor
    ~Environment() {}

    // Método para insertar un símbolo en el entorno
    void insert(const string& name, int value) {
        symbolTable[name] = value;
    }
    // Método para obtener el valor de un símbolo desde el entorno
    int lookup(const string& name, int defaultValue = 0) {
        // Buscar el símbolo en el entorno
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            // Si el símbolo existe, devolver su valor
            return it->second;
        } else {
            // Si el símbolo no existe, devolver el valor predeterminado
            return defaultValue;
        }
    }

private:
    map<string, int> symbolTable;
};
