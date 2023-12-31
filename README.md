# Robot-Resolvedor-Cubo-Rubik-3x3
Este es un proyecto que realizamos para el colegio La Salle Florida, consiste en un robot que es capaz de resolver el cubo Rubik 3x3 de forma autónoma mediante el uso de un Arduino UNO y una aplicación Android creada por nosotros en App Inventor   
<br>
# Materiales utilizados
<br>
- X10 - Servomotores SG90
<br>
- X1 - Arduino UNO
<br>
- X1 - Shield Uno Controlador Servos(nosotros utilizamos este pero se puede utilizar cualquiera que se encuentre: https://articulo.mercadolibre.com.ar/MLA-1302551439-shield-uno-controlador-servos-16ch-i2c-pca9685-pwm-arduino-_JM#position=15&search_layout=stack&type=item&tracking_id=58346647-e868-4fc0-8177-801a2d0baeeb)
<br>
- X1 - Packs de cables macho-hembra
<br>
- X1 - Modulo HC-05
<br>
- X1 - Cubo RUBIK Stickerless (preferentemente un modelo similar a este debido a que no probamos si funciona el reconocimiento de colores de la aplicacion con otro cubo)
<br>


<img src="Cubo_RUBIK_Stickerless.jpg" alt="" width="500" height="">

<br>

# Impresiones 3D
<br>
-Las impresiones 3D fueron sacadas de la siguiente fuente: 
<br>
https://github.com/EmanGM/Arduino-RubikSolver/tree/master
<br>
https://www.youtube.com/watch?v=ZHaAKOHkDEo&list=LL&index=14&t=14s
<br>

# Programas necesarios
<br>
-Visual Studio Code: https://code.visualstudio.com/
<br>
-Python 3.9(con versiones mas nuevas no funciona debido a que la libreria que utilizamos no tiene soporte en versiones mas nuevas): https://www.python.org/downloads/release/python-390/  o  buscarlo en "Microsoft Store" en windows(recomiendo esta opcion debido a que es mas sencilla).
<br>
-Arduino: https://www.arduino.cc/en/software
<br>
-Aplicacion android(link adjunto en el repositorio)

# Instrucciones instalacion
**Aplicacion Android:**
<br>
  _Descargar el APK adjunto en el repositorio.
  <br>
  _Ingresar a la configuracion de la aplicacion dentro del dispositivo movil e ir al apartado de "PERMISOS".
  <br>
  _Dentro del apartado de "PERMISOS" permitir los "archivos y contenido multimedia" y "camara".
  <br>
  _Activar el bluetooth del dispositivo.
  <br>
  _La aplicacion esta configurada correctamente.
<br>

**Python:**
  <br>
  _Descargar python 3.9 con pip incluido.
  <br>
  _Una vez instalado abrir "Símbolo del sistema de Windows" o "CMD" buscando "cmd" en el buscador de windows.
  <br>
  _Si el pip esta correctamente instalado ingresar los siguientes textos:  
  -"pip install rubik-solver" (esperar instalacion)
     <br>
                                                                           -"pip install pyserial" (esperar instalacion)
         <br>
                                                                           -"pip install --upgrade pip" (esperar instalacion)
<br>

**Visual Studio Code:**
<br>
  _Descargar Visual Studio Code con el link adjunto anteriormente.
  <br>
  _Copiar y pegar el codigo de Visual Studio Code adjunto en el repositorio.
  <br>
  _Instalar la extension de "PYTHON" dentro del Visual Studio Code.
<br>

**Arduino:**
 <br>
  _Instalar el software de Arduino.
  <br>
  _Copiar y pegar el codigo arduino adjunto en el repositorio.
  <br>
  _Dentro del software del Arduino ir al apartado "programa" en la esquina superior izquierda, luego ir a "incluir bibliotecas" y entrar    a "administrar bibliotecas...".
 <br>
  _Buscar la biblioteca "Adafruit PWM Servo  Driver Library" y instalarla.

**Instalacion finalizada, las intrucciones de como utilizar la aplicacion para resolver el cubo esta dentro de la aplicacion misma.**
