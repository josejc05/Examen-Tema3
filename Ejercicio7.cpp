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
    // Función para establecer una configuración en el entorno
    void setConfiguration(const std::string& key, const Variant::Value& value) {
        configTable[key] = value;
    }

    // Función para obtener el valor de una configuración desde el entorno
    Variant::Value getConfiguration(const std::string& key) const {
        auto it = configTable.find(key);
        if (it != configTable.end()) {
            return it->second;
        } else {
            std::cerr << "Error: Configuración '" << key << "' no encontrada." << std::endl;
            return Variant::Value{};
        }
    }

private:
    std::map<std::string, Variant::Value> configTable;
};
