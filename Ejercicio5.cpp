#include <map>
#include <string>
#include <iostream>
#include <variant>

using namespace std;

// Definición de la clase Variant para almacenar valores de diferentes tipos
class Variant {
public:
    Variant(int intValue) : value(intValue) {}
    Variant(const string& stringValue) : value(stringValue) {}

    // Método para obtener el valor como entero
    int getIntValue() const {
        return visit([](auto&& arg) -> int {
            return arg;
        }, value);
    }

    // Método para obtener el valor como cadena
    string getStringValue() const {
        return visit([](auto&& arg) -> string {
            return to_string(arg);
        }, value);
    }

private:
    variant<int, string> value;
};
// Definición de la clase Environment que trabaja con Variant
class Environment {
public:
    // Constructor
    Environment() {}

    // Destructor
    ~Environment() {}

    // Método para insertar un símbolo y su valor al entorno
    void insert(const string& name, const Variant& value) {
        symbolTable[name] = value;
    }

    // Método para obtener el valor de un símbolo desde el entorno como Variant
    Variant lookup(const string& name) {
        auto it = symbolTable.find(name);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            cerr << "Error: Symbol '" << name << "' not found in the environment." << endl;
            return Variant(0); // Valor predeterminado en caso de que el símbolo no exista
        }
    }

private:
    map<string, Variant> symbolTable;
};
int main() {
    // Ejemplo de uso de Environment con Variant
    Environment env;

    // Insertar símbolos con valores de diferentes tipos en el entorno
    env.insert("x", Variant(10));
    env.insert("y", Variant("Hello"));

    // Buscar valores de símbolos en el entorno y mostrarlos
    Variant valueX = env.lookup("x");
    Variant valueY = env.lookup("y");

    cout << "Value of x: " << valueX.getIntValue() << endl;
    cout << "Value of y: " << valueY.getStringValue() << endl;

    // Intentar buscar un símbolo que no está en el entorno
    Variant valueZ = env.lookup("z");

    return 0;
}
