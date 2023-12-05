# Examen-Tema3
https://github.com/josejc05/Examen-Tema3.git

Parte 1:

Parte 2:

Ejercicio1: El código presenta una implementación básica de la clase Environment en C++, que utiliza un std::map para representar una tabla de símbolos. La clase incluye métodos para agregar símbolos al entorno (addSymbol) y recuperar sus valores (getSymbolValue). En la función main, se crea una instancia de esta clase, se agregan dos símbolos con valores, se recuperan e imprimen dichos valores, y se muestra un mensaje de error al intentar obtener el valor de un símbolo ausente en el entorno. El uso de using namespace std; simplifica la notación al evitar el prefijo std::.

Ejercicio2: El código en C++ presenta una clase Environment que utiliza un std::map para gestionar un entorno de símbolos con valores enteros. Se ha añadido el método insert para agregar nuevos símbolos, evitando conflictos al verificar la existencia previa del símbolo. En la función main, se ilustra la inserción de "x" y "y", y se intenta agregar nuevamente "x", generando un mensaje de error si el símbolo ya existe. Se obtienen e imprimen los valores de "x" e "y" desde el entorno. Este código demuestra la funcionalidad del método insert y la capacidad del entorno para manejar símbolos de manera segura.

Ejercicio3: El código implementa una clase Environment en C++ que gestiona un entorno de símbolos con valores enteros mediante un std::map. En el método insert, se añaden símbolos al entorno asociados con valores. El método lookup busca un símbolo en el entorno y devuelve su valor, o un valor predeterminado si el símbolo no existe. En la función main, se ejemplifica la inserción de símbolos "x" y "y", seguido de la búsqueda de sus valores con el método lookup. Además, se busca el símbolo "z" con un valor predeterminado de 30. Los resultados se imprimen en la consola, demostrando la funcionalidad básica del entorno

Ejercicio4: Este código en C++ implementa la clase Environment, que gestiona un entorno de símbolos con valores enteros utilizando un std::map. Se han introducido mecanismos de manejo de excepciones en el método insert para capturar intentos de insertar un símbolo ya existente con un valor diferente y en el método lookup para manejar la búsqueda de un símbolo inexistente. En el bloque main, se ilustra el uso de estos métodos, y en caso de excepciones, se imprime un mensaje de error en la consola. Además, se ejemplifica la búsqueda de valores de símbolos existentes y no existentes, demostrando así el manejo de excepciones y la funcionalidad básica del entorno

Ejercicio5: Este código en C++ define dos clases, Variant y Environment. La clase Variant permite almacenar valores flexibles, como enteros, decimales o cadenas, y proporciona métodos para obtener y imprimir estos valores. La clase Environment representa un entorno de símbolos mediante un mapa que asocia nombres de símbolos con valores de tipo Variant. En el programa principal, se crea una instancia de Environment, se añaden símbolos con valores de diferentes tipos, y se obtienen y muestran estos valores utilizando la clase Variant. La salida consiste en la impresión de los valores asociados a los símbolos "integerSymbol", "doubleSymbol", y "stringSymbol".

Ejercicio6: El código en C++ define dos clases, Variant y Environment. La clase Variant permite almacenar valores flexibles, como enteros, decimales o cadenas, y ofrece métodos para obtener y imprimir estos valores. La clase Environment representa un entorno de símbolos mediante un mapa que asocia nombres de símbolos con valores de tipo Variant. En el programa principal, se crea una instancia de Environment, se añaden símbolos con valores de diferentes tipos, y se obtienen y muestran estos valores utilizando la clase Variant. Además, se introducen funciones adicionales en Environment para eliminar símbolos, verificar su existencia y se ilustra su uso eliminando el símbolo "doubleSymbol" y verificando su existencia posteriormente.

Ejercicio7: 
