# AyEDA P01 - La Hormiga de Langton

Es un programa en C++ que implementa una versión clásica del autómata celular conocido como la Hormiga de Langton.

## Uso

### **Compilación del ejecutable**

```bash
$ make
```

### **Ejecución del programa**

**Para un entorno básico (con la hormiga por defecto en el centro)**

```bash
$ ./hormiga_langton <columnas> <filas> <pasos>
```

**Para un entorno con la hormiga posicionada a elección del usuario**

```bash
$ ./hormiga_langton <columnas> <filas> <pasos> <posición i> <posición j>
```

> > Nota1: las posiciones i y j se encuentran en el rango [0 , (número de filas -1)] y [0 , (número de columnas -1)], respectivamente.

**Para un entorno con la hormiga posicionada a elección del usuario y con la dirección especificada**

```bash
$ ./hormiga_langton <columnas> <filas> <pasos> <posición i> <posición j> <dirección>
```

> > Nota2: las direcciones siguen el formato UP (arriba) RI (derecha) DO (abajo) LE (izquierda)

### **Lanzamiento de los tests**

```bash
$ make test
```

Se compila y ejecuta el conjunto de tests para luego ejecutarlos, de suceder satisfactoriamente debe aparecer lo siguiente por terminal:

```bash
Making tests: hormiga_langton_test
g++ -o hormiga_langton_test ./src/entorno.cpp ./src/hormiga.cpp ./test/includer.test.cpp
./hormiga_langton_test
===============================================================================
All tests passed (38 assertions in 2 test cases)
```

También se puede ejecutar un despliegue detallado de los tests si ya se ha lanzado el comando anterior:

```bash
$ ./hormiga_langton_test -s
```

## Licencia

[MIT](https://choosealicense.com/licenses/mit/)

## Autoría

- Eric Dürr Sierra - [alu0101027005](alu0101027005@ull.edu.es)
