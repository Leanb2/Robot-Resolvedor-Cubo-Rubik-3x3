import serial ,time

puerto = serial.Serial('COM4', 9600)
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

