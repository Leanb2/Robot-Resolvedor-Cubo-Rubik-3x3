#EJECUTAR SOLO CUANDO LA APLICACION ANDROID LO INDIQUE

import serial ,time

puerto = serial.Serial('COM4', 9600) #Cambiar el puerto "COM" en funcion al puerto que utilices.
datos = puerto.readline()

time.sleep(1)
cube = datos.decode('utf-8')
print("datos: " + cube)
from rubik_solver import utils
a=utils.solve(cube, 'Kociemba')
b = ' '.join(str(element) for element in a)
print(b)
puerto.write(b.encode())
time.sleep(1)
puerto.close()

#EN CASO DE DAR ERROR AL EJECUTAR, EJECUTAR NUEVAMENTE 
