# Proyecto-TCU-Walle
## Tabla de contenidos:

- [Descripción](#descripción)
- [Contenido del repositorio](#contenido-del-repositorio)
- [Instrucciones para encender el dispositivo](#instrucciones-para-encender-el-prototipo)
- [Instrucciones para utilizar el prototipo](#instrucciones-para-utilizar-el-prototipo)
- [Acciones recomendadas luego de utilizar el prototipo](#acciones-recomendadas-luego-de-utilizar-el-prototipo)
- [Instrucciones para realizar modificaciones al código](#instrucciones-para-realizar-modificaciones-al-código)
- [Notas sobre el mantenimiento](#notas-sobre-el-mantenimiento)
- [Fotografias del dispositivo](#fotografías-del-dispositivo)

## Descripción
Este repositorio contiene el código y el diagrama eléctronico implementado en el prototipo "Wall-e" realizado para el TC-691: Tropicalización de la tecnología de la Universidad de Costa Rica.

## Contenido del repositorio
La carpeta "codigo_de_walle" contiene el código que se utiliza en el Arduino UNO que utiliza el prototipo. Este código se realizó en Arduino IDE, por lo que se recomienda realizar cualquier modificación utilizando este mismo IDE.
La imagen "Diagrama del Walle" es una captura de pantalla del diagrama eléctrico que utiliza el prototipo. Este diagrama fue realizado en Tinkercad, se puede acceder por medio de este [link](https://www.tinkercad.com/things/7Rk4uLrkQ7N-dazzling-krunk-elzing/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=8nwAPvhacpUmtkSRFdSvu5vPRoAT0Ql_esmfhcNviRY). Este diseño no contiene código, por lo que es únicamente el diagrama.

## Instrucciones para encender el prototipo
El prototipo wall-e utiliza dos baterias para alimentar los motores dc y los servomotores, y utiliza una tercera batería dedicada exclusivamente a alimentar al arduino que lo controla. Cuando se va a utilizar el protipo, se recomienda primero conectar la bateria del arduino, luego colocar el acelerometro sobre una superficie plana, y manteniendolo en la superficie, activar el switch de las otras baterias, esto activará los motores y permitirá que el protipo se mueva.  
Antes de cualquier gira, es muy recomendable cargar las tres baterías completamente, para esto se pueden conectar a un cable con puerto mini USB, y esperar hasta que el color cambie a color verde.

## Instrucciones para utilizar el prototipo
El prototipo wall-e utiliza un acélerometro como control para su movimiento. Este sensor está montado sobre un cartón con forma de control de consola de videojuego para indicar la posición en la que se debe utilizar, y sobre este cartón está escrito con flechas el movimiento que se debe realizar para mover el prototipo.  
Para hacer que el prototipo se mueva hacia adelante, se debe girar el acelerometro hacia el frente. Para hacer que se mueva hacia antrá, se debe inclinar el control hacia atrás. En combinación con estos giros hacia el frente y hacia atrás, el control se puede inclinar hacia los lados, estó hará que el prototipo gire hacia los lados, dependiendo de si el control se gira hacia la derecha o hacia la izquierda, y si se está inclinando hacia adelante o hacia atrás.  
Estas instrucciones se explican también en un video haciendo uso del protitipo, se puede acceder por medio de este [link](https://youtu.be/OO7-eh5WjbY).

## Acciones recomendadas luego de utilizar el prototipo
Se recomienda que cuando el dispositivo no se utilice, se desconecte la bateria del arduino, y también DESCONECTAR LAS BATERIAS DE LOS MOTORES, de lo contrario las baterias se descargarán completamente aunque el prototipo no se esté utilizando.

## Instrucciones para realizar modificaciones al código
El código que utiliza el prototipo es muy sencillo, y puede entenderse facilmente. En caso que se desee realizar cambios lo más importante a tener en cuenta es tener cuidado con los angulos en los que se pueden mover los servomotores, ya que si estos se mueven mas allá de sus limites (en el código se explica cuáles son estos limites) se puede llegar a dañar la estructura de cartón. En caso de que alguna cosa con respecto al código no esté clara, o se tengan dudas, se puede contactar al autor del proyecto al correo josemario.navarro@ucr.ac.cr

## Notas sobre el mantenimiento
Al estar fabricado en cartón, el prototipo resulta muy frágil, es importante evitar que entre en contacto con cualquier tipo de liquido.  
También puede ser necesario realizar mantenimientos en el futuro cada vez que se utiliza, como revisar el estado de las orugas, las cuales si no se utilizan un tiempo, comienzan a estirarse y dejan se ser funcionales. Como sugerencia, se podría realizar una version mejorada de estas, que sean impresas en 3d. 

## Fotografías del dispositivo
<div style="text-align: center;">
    <img src="imagenes/controlwalle.jpg" alt="Control del prototipo" width="450" height="300" >
</div>

<div style="text-align: center;">
    <img src="imagenes/walle.jpg" alt="Control del prototipo" >
</div>

<div style="text-align: center;">
    <img src="imagenes/walle1.jpg" alt="Control del prototipo"  >
</div>

<div style="text-align: center;">
    <img src="imagenes/walle2.jpg" alt="Control del prototipo">
</div>

