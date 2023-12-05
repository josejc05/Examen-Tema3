# Examen-Tema3
https://github.com/josejc05/Examen-Tema3.git

Parte 1:

Parte 2:

Ejercicio1: El código presenta una implementación básica de la clase Environment en C++, que utiliza un std::map para representar una tabla de símbolos. La clase incluye métodos para agregar símbolos al entorno (addSymbol) y recuperar sus valores (getSymbolValue). En la función main, se crea una instancia de esta clase, se agregan dos símbolos con valores, se recuperan e imprimen dichos valores, y se muestra un mensaje de error al intentar obtener el valor de un símbolo ausente en el entorno. El uso de using namespace std; simplifica la notación al evitar el prefijo std::.

Ejercicio2: El código en C++ presenta una clase Environment que utiliza un std::map para gestionar un entorno de símbolos con valores enteros. Se ha añadido el método insert para agregar nuevos símbolos, evitando conflictos al verificar la existencia previa del símbolo. En la función main, se ilustra la inserción de "x" y "y", y se intenta agregar nuevamente "x", generando un mensaje de error si el símbolo ya existe. Se obtienen e imprimen los valores de "x" e "y" desde el entorno. Este código demuestra la funcionalidad del método insert y la capacidad del entorno para manejar símbolos de manera segura.

Ejercicio3: El código implementa una clase Environment en C++ que gestiona un entorno de símbolos con valores enteros mediante un std::map. En el método insert, se añaden símbolos al entorno asociados con valores. El método lookup busca un símbolo en el entorno y devuelve su valor, o un valor predeterminado si el símbolo no existe. En la función main, se ejemplifica la inserción de símbolos "x" y "y", seguido de la búsqueda de sus valores con el método lookup. Además, se busca el símbolo "z" con un valor predeterminado de 30. Los resultados se imprimen en la consola, demostrando la funcionalidad básica del entorno
