#include <iostream>
#include <map>
#include <string>
#include <variant>

class Variant {
public:
    using Value = std::variant<int, double, std::string>;

    Variant(const Value& val) : value(val) {}

    Value getValue() const {
        return value;
    }

    void printValue() const {
        std::visit([](const auto& v) { std::cout << v; }, value);
        std::cout << std::endl;
    }

private:
    Value value;
};

class Environment {
public:
    void addSymbol(const std::string& symbol, const Variant::Value& value) {
        symbolTable[symbol] = value;
    }
    Variant::Value getSymbolValue(const std::string& symbol) const {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            return it->second;
        } else {
            std::cerr << "Error: El símbolo '" << symbol << "' no está definido." << std::endl;
            return Variant::Value{};
        }
    }

    void removeSymbol(const std::string& symbol) {
        auto it = symbolTable.find(symbol);
        if (it != symbolTable.end()) {
            symbolTable.erase(it); // Eliminar el símbolo si existe
            std::cout << "Símbolo '" << symbol << "' eliminado del entorno." << std::endl;
        } else {
            std::cerr << "Error: El símbolo '" << symbol << "' no existe en el entorno." << std::endl;
        }
    }

    bool symbolExists(const std::string& symbol) const {
        return symbolTable.find(symbol) != symbolTable.end();
    }
private:
    std::map<std::string, Variant::Value> symbolTable;
};

int main() {
    Environment myEnvironment;

    myEnvironment.addSymbol("integerSymbol", 42);
    myEnvironment.addSymbol("doubleSymbol", 2.718);
    myEnvironment.addSymbol("stringSymbol", "Hola, Mundo!");

    Variant::Value valueInteger = myEnvironment.getSymbolValue("integerSymbol");
    Variant::Value valueDouble = myEnvironment.getSymbolValue("doubleSymbol");
    Variant::Value valueString = myEnvironment.getSymbolValue("stringSymbol");

    Variant varInteger(valueInteger);
    Variant varDouble(valueDouble);
    Variant varString(valueString);

    std::cout << "Valor del símbolo entero: ";
    varInteger.printValue();