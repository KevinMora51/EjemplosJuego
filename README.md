# EjemplosJuego

El proyecto esta desarrollado sobre MinGW64 utilizando Msys2
y como editor se esta utilizando Visual Studio Code.

## Prerequisitos

[Instalar las herramientas necesarias](./docs/herramientas.md)

[Instalar las Extensiones VSCode](./docs/extensiones.md)

[Instalar las librerias](./docs/librerias.md)

[Clonar el repositorio](./docs/fork.md)

## Como ejecutar los ejemplos

Instalar todas las dependencias descritas arriba y dentro de una terminal de vscode ejecutar:

> make run'NombreEjecutable'

Por ejemplo para ejecutar '00_Ventana.cpp' correr el comando en la terminal de vscode:

> make run00_Ventana




# Juego Pong en SFML

Este proyecto implementa un juego tipo Pong usando la biblioteca [SFML](https://www.sfml-dev.org/).

## Archivos principales

- **Juego.hpp / Juego.cpp**: Contienen la lógica principal del juego, el bucle de eventos, el renderizado y la gestión de colisiones.
- **PJ1.hpp, PJ2.hpp**: Que son los jugadores/Rectangulos.
- **Pe.hpp**:Es la pelota.
- **Jugador.hpp, Pelota.hpp**: Clases para el movimiento da los jugadores y la pelota.

## Cómo jugar

- **Jugador 1**: Usa las teclas `W` (arriba) y `S` (abajo).
- **Jugador 2**: Usa las flechas `Arriba` y `Abajo`.
- Cuando la pelota sale de la pantalla, presiona `R` para reiniciar.

## Requisitos

- [SFML 2.x](https://www.sfml-dev.org/download.php)


## Compilación

Este juego se puede ejcutar escribiendo en la terminal make runJuego


