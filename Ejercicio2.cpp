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
    // Método para obtener el valor de un símbolo desde el entorno
    int getSymbolValue(const string& name) {
        // Si el símbolo no está presente, devuelve un valor predeterminado (puedes ajustarlo según tu necesidad)
        if (symbolTable.find(name) != symbolTable.end()) {
            return symbolTable[name];
        } else {
            cerr << "Error: Symbol '" << name << "' not found in the environment." << endl;
            return 0; // Puedes cambiar esto según tus necesidades
        }
    }

private:
    map<string, int> symbolTable;
};
int main() {
    // Ejemplo de uso del método insert
    Environment env;

    // Insertar símbolos en el entorno
    env.insert("x", 10);
    env.insert("y", 20);

    // Intentar insertar un símbolo que ya existe
    env.insert("x", 30);

    // Obtener valores de símbolos desde el entorno
    int valueX = env.getSymbolValue("x");
    int valueY = env.getSymbolValue("y");

    cout << "Value of x: " << valueX << endl;
    cout << "Value of y: " << valueY << endl;

    return 0;
}
