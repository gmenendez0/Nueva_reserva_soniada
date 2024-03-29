# Nueva reserva soñada

## Instrucciones de usuario
Para compilar aplicar el siguiente comando en la linea de comando de linux:  
        **g++ *.cpp -Wall -Werror -Wconversion -o reserva_soniada***  

Para correr el ejecutable, aplicar el siguiente comando en la linea de comando de linux:  
        ***./reserva_soniada***
        
        
## Funcionalidades

A la mayoría de la gente le gustan los animales y hay muchas personas dispuestas a cuidarlos y darles un
hogar. Después de mucho ahorrar, se logró abrir una reserva para todos los animales que lo necesiten.
Pero al tener tantos es difícil llevar un registro de todo...

1)Se listaran todos los animales con su nombre, edad, tamaño, especie en forma completa,
personalidad, hambre e higiene.

2)La reserva consiguió un auto y puede ir a buscar los animales que necesitan ser rescatados. El
auto comenzará con 100 de combustible y se le cargara 5 por cada acción del menú principal que sea
seleccionada.

3)Se solicitara el nombre del animal al usuario y validara que el mismo este entre los animales de la
reserva. Si el animal existe se le mostrará la información de este.

4)Se le pedira al usuario que seleccione que animal desea cuidar y que tipo de cuidado desea aplicar. Al alimentar a cualquier animal su hambre volverá a 0 y dira su nombre y lo que comió.
Al bañar a cualquier animal su higiene volverá a 100 y si no requiere un baño lo dira.
En caso de que un animal este totalmente hambriento o que este totalmente sucio, este se escapara de la reserva. Si 3 animales escapan, la reserva sera clausurada.

5)Se deberá preguntara el espacio disponible para el animal (en metros cuadrados) y mostrara todos los
animales de la lista que podrían ser adoptados.
Se le deberá pedira al usuario que elija entre alguno de los animales o si desea cancelar la adopción. 

5)Podra elegirse la cantidad de combustible a cargar al auto.

6)Al terminar de usar el programa, se guardaran los cambios hechos.

## Diagramas de clases

<img src="https://github.com/gmenendez0/Nueva_reserva_soniada/blob/main/doc/Diagrama_de_clases_Reserva.png" alt="Diagrama de clases de Reserva">
<img src="https://github.com/gmenendez0/Nueva_reserva_soniada/blob/main/doc/Diagrama_de_clases_Grafo.png" alt="Diagrama de clases de Grafo">
<img src="https://github.com/gmenendez0/Nueva_reserva_soniada/blob/main/doc/Diagrama_de_clases_Animal.png" alt="Diagrama de clases de Animal">
<img src="https://github.com/gmenendez0/Nueva_reserva_soniada/blob/main/doc/Diagrama_de_clases_UserUI.png" alt="Diagrama de clases de UserUI">
