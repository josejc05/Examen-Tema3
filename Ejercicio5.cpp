#include <iostream>
#include <map>
#include <string>
#include <variant>

class Variant {
public:
    // Definir un tipo para representar valores flexibles
    using Value = std::variant<int, double, std::string>;

    // Constructor que acepta un valor inicial
    Variant(const Value& val) : value(val) {}

    // Obtener el valor almacenado en Variant
    Value getValue() const {
        return value;
    }

    // Imprimir el valor almacenado
    void printValue() const {
        std::visit([](const auto& v) { std::cout << v; }, value);
        std::cout << std::endl;
    }

private:
    Value value;
};

class Environment {
public:
    // Método para agregar un símbolo y su valor a la tabla de símbolos
    void addSymbol(const std::string& symbol, const Variant::Value& value) {
        symbolTable[symbol] = value;
    }

    // Método para obtener el valor asociado a un símbolo en la tabla de símbolos
    Variant::Value getSymbolValue(const std::string& symbol) const {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            return it->second; // Devuelve el valor asociado al símbolo
        } else {
            std::cerr << "Error: El símbolo '" << symbol << "' no está definido." << std::endl;
            return Variant::Value{}; // Devuelve un valor predeterminado
        }
    }

private:
    std::map<std::string, Variant::Value> symbolTable;
};
int main() {
    // Crear un entorno
    Environment myEnvironment;

    // Agregar símbolos con valores de diferentes tipos al entorno
    myEnvironment.addSymbol("integerSymbol", 42);
    myEnvironment.addSymbol("doubleSymbol", 2.718);
    myEnvironment.addSymbol("stringSymbol", "Hola, Mundo!");

    // Obtener y mostrar los valores de los símbolos
    Variant::Value valueInteger = myEnvironment.getSymbolValue("integerSymbol");
    Variant::Value valueDouble = myEnvironment.getSymbolValue("doubleSymbol");
    Variant::Value valueString = myEnvironment.getSymbolValue("stringSymbol");

    // Crear instancias de Variant con los valores obtenidos
    Variant varInteger(valueInteger);
    Variant varDouble(valueDouble);
    Variant varString(valueString);