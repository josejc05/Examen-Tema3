#include <map>
#include <string>
#include <iostream>

class Environment {
public:
    // Constructor
    Environment() {}

    // Destructor
    ~Environment() {}

    // Función para agregar un símbolo y su valor al entorno
    void addSymbol(const std::string& name, int value) {
        symbolTable[name] = value;
    }
    // Función para obtener el valor de un símbolo desde el entorno
    int getSymbolValue(const std::string& name) {
        // Si el símbolo no está presente, devuelve un valor predeterminado (puedes ajustarlo según tu necesidad)
        if (symbolTable.find(name) != symbolTable.end()) {
            return symbolTable[name];
        } else {
            std::cerr << "Error: Symbol '" << name << "' not found in the environment." << std::endl;
            return 0; // Puedes cambiar esto según tus necesidades
        }
    }

private:
    std::map<std::string, int> symbolTable;
};