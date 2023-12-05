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
