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