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
        // Verificar si el símbolo ya existe en el entorno
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            cerr << "Error: Symbol '" << name << "' already exists in the environment." << endl;
        } else {
            // Insertar el nuevo símbolo en el entorno
            symbolTable[name] = value;
        }
    }

