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
