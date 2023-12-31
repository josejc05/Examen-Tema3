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
int main() {
    // Crear una instancia del entorno de juego
    Environment gameSettings;

    // Configuración inicial del juego
    gameSettings.setConfiguration("playerSpeed", 5); // Velocidad del jugador
    gameSettings.setConfiguration("enemyStrength", 8.5); // Fuerza de los enemigos
    gameSettings.setConfiguration("welcomeMessage", "¡Bienvenido al Rust!"); // Mensaje de bienvenida al Rust

    // Obtener y mostrar configuraciones
    Variant::Value playerSpeed = gameSettings.getConfiguration("playerSpeed");
    Variant::Value enemyStrength = gameSettings.getConfiguration("enemyStrength");
    Variant::Value welcomeMessage = gameSettings.getConfiguration("welcomeMessage");

    // Crear instancias de Variant con los valores obtenidos
    Variant speedVariant(playerSpeed);
    Variant strengthVariant(enemyStrength);
    Variant messageVariant(welcomeMessage);
    // Mostrar las configuraciones utilizando Variant
    std::cout << "Configuracion de velocidad del jugador: ";
    speedVariant.printValue();

    std::cout << "Configuracion de fuerza de los enemigos: ";
    strengthVariant.printValue();

    std::cout << "Mensaje de bienvenida: ";
    messageVariant.printValue();

    return 0;
}