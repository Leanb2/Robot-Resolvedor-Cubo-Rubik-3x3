#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x43);

SoftwareSerial sw(2,3);    //2 ES RX, 3 ES TX EN EL ARDUINO

#define vel 300

String kociemba_sol;
int o=0;
int a=0;
int w=0;
String color;
char dato;
int cont=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sw.begin(9600);
  servos.begin();  
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
}

void loop() {
if(w==0){                                                                            /////////////////////////////////////////////////////////////////////////////////////////
if(Serial.available()>0){
  color = Serial.read();
  //sw.print(color);
}

if(sw.available()>0){
color = sw.readString();                                                                       //ETAPA RECIBIR STRING DE COLORES DEL CUBO DESDE APP INVENTOR//
//Serial.print(color);
}                                    
if(color.length() > 50){
  //Serial.print(color);
  w=1;}
}                                                                                   //////////////////////////////////////////////////////////////////////////////////////////

if(color.length() > 50){
if(o==0){
sw.print("o");  
o++;
}
Serial.println(color);
delay(5000);
}

if((Serial.available()>0) and (w==1)){                                             ///////////////////////////////////////////////////////////////////////////////////////////
                                      color ="";
                                      kociemba_sol = Serial.readString();
                                      if(kociemba_sol.length() > 0){                          
                                      sacar();
                                      w=2;                                                          //ETAPA RECIBIR ALGORITMO DE RESOLUCION DESDE PYTHON//                      
                                      }                                                         

                                         
                                      }                                            ///////////////////////////////////////////////////////////////////////////////////////////


if(w==2){                                                                          ///////////////////////////////////////////////////////////////////////////////////////////
  if(a==0){
  sw.print("a");  
  a++;
  }
if(Serial.available()>0){
  dato = Serial.read();
}
if(sw.available()>0){
dato = sw.read();                                                                       
} 
    if((dato=='A') and (cont==0)){                                                                                
    cont=1;
    Serial.println("Cerrar");                                                                                         
        poner();                                                                                                     //ETAPA COLOCAR CUBO// 
    }                                                                                             
    if((dato=='C') and (cont==1)){
      cont=2;
      Serial.println("Cubo colocado");
      w=3;
    }
    if((dato=='B') and (cont==1)){                                                                                        
      cont=0;
      Serial.println("Abrir");
     sacar();
    }
    }
                                                                                  ///////////////////////////////////////////////////////////////////////////////////////////

  
if(w==3){                                                                          ///////////////////////////////////////////////////////////////////////////////////////////
          Serial.print("Algoritmo de resolucion: ");
          Serial.println(kociemba_sol);
          run_kociemba();                                                                           //ETAPA ANALIZAR ALGORTIMO DE RESOLUCION Y MOVER LOS SERVOS//
          w=4;
        }
}                                                                                  ///////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////


          //FUNCION PARA MOVER SERVOS//


//////////////////////////////////////////////////////        
void run_kociemba(){

int str_len = kociemba_sol.length()  + 1; 


Serial.print("Caracteres:");
Serial.println((str_len-1));

for(int
  i = 0; i <= str_len; i++){     

if(str_len==i){
  sacar();
  }
if
  ((kociemba_sol.charAt(i)) =='R'){


if ((kociemba_sol.charAt(i+1)) == '2')
  {
     doble(6);
     Serial.println("R2");
     }


if ((kociemba_sol.charAt(i+1))
  == '\'') {
     antihorario(6);
      Serial.println("R'");
      }

if (((kociemba_sol.charAt(i+1))!=
  '2') and((kociemba_sol.charAt(i+1)) != '\'')) {
      horario(6);
      Serial.println("R");
      }

}

else
  { //NO HACER NADA
      
}

if ((kociemba_sol.charAt(i)) =='L'){


if
  ((kociemba_sol.charAt(i+1)) == '2') {
      doble(4);
      Serial.println("L2");
      }


if
  ((kociemba_sol.charAt(i+1)) == '\'') {
      antihorario(4);
      Serial.println("L'");
      }

if (((kociemba_sol.charAt(i+1))!=
  '2') and((kociemba_sol.charAt(i+1)) != '\'')) {
     horario(4);
      Serial.println("L");
      }

}

else
  { //NO HACER NADA
      
}

if ((kociemba_sol.charAt(i)) =='U'){


if
  ((kociemba_sol.charAt(i+1)) == '2') {
    updoble();
    Serial.println("U2");
    }


if
  ((kociemba_sol.charAt(i+1)) == '\'') {
      upanti();
      Serial.println("U'");
      }

if (((kociemba_sol.charAt(i+1))!=
  '2') and((kociemba_sol.charAt(i+1)) != '\'')) {
      up();
      Serial.println("U");
      }

}

else
  { //NO HACER NADA
      
}



if ((kociemba_sol.charAt(i)) =='D'){


if
  ((kociemba_sol.charAt(i+1)) == '2') {
     downdoble();
      Serial.println("D2");
      }


if
  ((kociemba_sol.charAt(i+1)) == '\'') {
      downanti();
      Serial.println("D'");
      }

if (((kociemba_sol.charAt(i+1))!=
  '2') and((kociemba_sol.charAt(i+1)) != '\'')) {
     down();
      Serial.println("D");
      }

}

else
  { //NO HACER NADA
      
}





if ((kociemba_sol.charAt(i))
  =='F'){


if ((kociemba_sol.charAt(i+1)) == '2') {
      doble(7);
      Serial.println("F2");
      }


if ((kociemba_sol.charAt(i+1)) == '\'') {
      antihorario(7);
      Serial.println("F'");
      }

if
  (((kociemba_sol.charAt(i+1))!= '2') and((kociemba_sol.charAt(i+1)) != '\'')) {
     horario(7);
     Serial.println("F");
     }

}

else { //NO HACER NADA
      
}




if
  ((kociemba_sol.charAt(i)) =='B'){


if ((kociemba_sol.charAt(i+1)) == '2')
  {
     doble(5);
     Serial.println("B2");
     }


if ((kociemba_sol.charAt(i+1)) ==
  '\'') {
      antihorario(5);
      Serial.println("B'");
      }

if (((kociemba_sol.charAt(i+1))!= '2')
  and((kociemba_sol.charAt(i+1)) != '\'')) {
      horario(5);
      Serial.println("B");
      }

}

else
  { //NO HACER NADA
      
}

}
}

void mover(){
  servos.setPWM(4,0,345);
  servos.setPWM(6,0,655);
  delay(vel);
  servos.setPWM(4,0,376);
  servos.setPWM(6,0,642);  
  delay(vel);   
 }

void moveranti(){
  //servos.setPWM(4,0,390);
  //servos.setPWM(6,0,120);
  //delay(500);
  servos.setPWM(4,0,376);
  servos.setPWM(6,0,135);  
  delay(vel);   
 }
  void arreglo(){
poner();
delay(vel);
atras(2);
delay(vel);
mid(6);
delay(vel);
adelante(2);
delay(vel);

  }
  void prueba(){
agarre(1);
agarre(3);
delay(vel);
atras(0);
delay(vel);
start(4);
delay(vel);
agarre(0);
agarre(2);
delay(vel);
atras(1);
atras(3);
delay(vel);
moveranti();
delay(vel);
  }
void midstart(int pin){
  if(pin==7){
  servos.setPWM(7,0,390);
  delay(vel);
  servos.setPWM(7,0,390);}    
  if(pin==4){
  servos.setPWM(4,0,390);
  delay(vel);
  servos.setPWM(4,0,376);}
  if(pin==5){
  servos.setPWM(5,0,330);
  delay(vel);
  servos.setPWM(5,0,351);}  
  if(pin==6){
  servos.setPWM(6,0,350);
  delay(vel);
  servos.setPWM(6,0,380);}  
  
  delay(vel); 
}

void midfin(int pin){
  if(pin==7){
  servos.setPWM(7,0,390);
  delay(vel);
  servos.setPWM(7,0,390);}    
  if(pin==4){
  servos.setPWM(4,0,345);
  delay(vel);
  servos.setPWM(4,0,376);}
  if(pin==5){
  servos.setPWM(5,0,330);
  delay(vel);
  servos.setPWM(5,0,351);}  
  if(pin==6){
  servos.setPWM(6,0,350);
  delay(vel);
  servos.setPWM(6,0,380);}  
  
  delay(vel); 
}


  
void agarre(int pin){
if(pin==0){
  servos.setPWM(0,0,350);}
if(pin==1){
  servos.setPWM(1,0,500);}  
if(pin==2){
  servos.setPWM(8,0,450);}  
if(pin==3){
  servos.setPWM(3,0,340);}       
  }
  
void adelante(int pin){
 if(pin==0){
  servos.setPWM(0,0,340);}
if(pin==1){
  servos.setPWM(1,0,460);} //330 
if(pin==2){
  servos.setPWM(8,0,420);
  delay(vel);
  servos.setPWM(8,0,440);}  
if(pin==3){
  servos.setPWM(3,0,335);}    
    }  
    
void atras(int pin){
  if(pin==0){
  servos.setPWM(0,0,185);}
if(pin==1){
  servos.setPWM(1,0,250);}  //190
if(pin==2){
  servos.setPWM(8,0,260);}  
if(pin==3){
  servos.setPWM(3,0,170);}    
    }
  
void start(int pin){
if(pin==4){
  servos.setPWM(4,0,95);
  delay(vel);
  servos.setPWM(4,0,110);}
if(pin==5){
  servos.setPWM(5,0,89);
  delay(vel);
  servos.setPWM(5,0,104);}  
if(pin==6){
  servos.setPWM(6,0,98);
  delay(vel);
  servos.setPWM(6,0,125);}  
if(pin==7){
  servos.setPWM(7,0,89);
  delay(vel);
  servos.setPWM(7,0,105);}    
}

void fin(int pin){
  if(pin==4){
  servos.setPWM(4,0,643);
  delay(vel);
  servos.setPWM(4,0,620);}
if(pin==5){
  servos.setPWM(5,0,641);
  delay(vel);
  servos.setPWM(5,0,620);}  
if(pin==6){
  servos.setPWM(6,0,655);
  delay(vel);
  servos.setPWM(6,0,630);}  
if(pin==7){
  servos.setPWM(7,0,640);
  delay(vel);
  servos.setPWM(7,0,625);}    
  delay(vel); 
}


  
void midt(){
  servos.setPWM(4,0,376);
  servos.setPWM(5,0,360);  
  servos.setPWM(6,0,380);  
  servos.setPWM(7,0,369);    
  delay(vel); 
  }
void mid(int pin){
  if(pin==7){
  servos.setPWM(7,0,360);
  delay(vel);
  servos.setPWM(7,0,369);}    
  if(pin==4){
  servos.setPWM(4,0,345);
  delay(vel);
  servos.setPWM(4,0,376);}
  if(pin==5){
  servos.setPWM(5,0,345);
  delay(vel);
  servos.setPWM(5,0,360);}  
  if(pin==6){
  servos.setPWM(6,0,350);
  delay(vel);
  servos.setPWM(6,0,380);}  
  
  delay(vel); 
}
void sacar(){
atras(0);
atras(2);
atras(1);
atras(3);
}

void poner(){
adelante(0);
adelante(1);
adelante(2);
adelante(3);
} 

void doble(int pin){
  if(pin==4){
  agarre(1);
  agarre(3);
  //agarre(2);
  atras(0);
  delay(vel);
  start(4);
  delay(vel);
  adelante(0);
  delay(vel);
  fin(4);
  delay(vel);
  atras(0);
  delay(vel);
  mid(4);
  delay(vel);
  poner();
  delay(vel);
  }
if(pin==5){
  agarre(0);
  //agarre(3);
  agarre(2);
  atras(1);
  delay(vel);
  start(5);
  delay(vel);
  adelante(1);
  delay(vel);
  fin(5);
  delay(vel);
  atras(1);
  delay(vel);
  mid(5);
  delay(vel);
  poner();
  delay(vel);
  }
if(pin==6){
  //agarre(0);
  agarre(3);
  agarre(1);
  atras(2);
  delay(vel);
  start(6);
  delay(vel);
  adelante(2);
  delay(vel);
  fin(6);
  delay(vel);
  atras(2);
  delay(vel);
  mid(6);
  delay(vel);
  poner();
  delay(vel);
  }
if(pin==7){
  agarre(0);
  //agarre(1);
  agarre(2);
  atras(3);
  delay(vel);
  start(7);
  delay(vel);
  adelante(3);
  delay(vel);
  fin(7);
  delay(vel);
  atras(3);
  delay(vel);
  mid(7);
  delay(vel);
  poner();
  delay(vel);
  }
}

void horario(int pin){
if(pin==4){
  agarre(1);
  agarre(3);
  //agarre(2);
  delay(vel);
  fin(4);
  delay(vel);
  atras(0);
  delay(vel);
  mid(4);
  delay(vel);
  adelante(0);
  delay(vel);
  poner();
  delay(vel);
  }
if(pin==5){
  agarre(0);
  //agarre(3);
  agarre(2);
  delay(vel);
  fin(5);
  delay(vel);
  atras(1);
  delay(vel);
  mid(5);
  delay(vel);
  adelante(1);
  delay(vel);
  poner();
  delay(vel);
  }
if(pin==6){
  //agarre(0);
  agarre(3);
  agarre(1);
  delay(vel);
  fin(6);
  delay(vel);
  atras(2);
  delay(vel);
  mid(6);
  delay(vel);
  adelante(2);
  delay(vel);
  poner();
  delay(vel);
  }
if(pin==7){
  agarre(0);
  //agarre(1);
  agarre(2);
  delay(vel);
  fin(7);
  delay(vel);
  atras(3);
  delay(vel);
  mid(7);
  delay(vel);
  adelante(3);
  delay(vel);
  poner();
  delay(vel);
  }
}
void antihorario(int pin){
  if(pin==4){
  agarre(1);
  agarre(3);
  //agarre(2);
  delay(vel);
  start(4);
  delay(vel);
  atras(0);
  delay(vel);
  mid(4);
  delay(vel);
  adelante(0);
  delay(vel);
  poner();
  delay(vel);
  }
if(pin==5){
  agarre(0);
  //agarre(3);
  agarre(2);
  delay(vel);
  start(5);
  delay(vel);
  atras(1);
  delay(vel);
  mid(5);
  delay(vel);
  adelante(1);
  delay(vel);
  poner();
  delay(vel);
  }
if(pin==6){
  //agarre(0);
  agarre(3);
  agarre(1);
  delay(vel);
  start(6);
  delay(vel);
  atras(2);
  delay(vel);
  mid(6);
  delay(vel);
  adelante(2);
  delay(vel);
  poner();
  delay(vel);
  }
if(pin==7){
  agarre(0);
  //agarre(1);
  agarre(2);
  delay(vel);
  start(7);
  delay(vel);
  atras(3);
  delay(vel);
  mid(7);
  delay(vel);
  adelante(3);
  delay(vel);
  poner();
  delay(vel);
  }
  }

  void up(){
agarre(1);
agarre(3);
delay(vel);
atras(0);
delay(vel);
fin(4);
delay(vel);
agarre(0);
agarre(2);
delay(vel);
atras(1);
atras(3);
delay(vel);
mover();
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(2);
delay(vel);
mid(6);
delay(vel);
poner();
delay(vel);
horario(5);
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(0);
delay(vel);
start(4);
delay(vel);
agarre(0);
agarre(2);
delay(vel);
atras(1);
atras(3);
delay(vel);
moveranti();
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(2);
delay(vel);
mid(6);
delay(vel);
poner();
delay(vel);
}

void upanti(){
agarre(1);
agarre(3);
delay(vel);
atras(0);
delay(vel);
fin(4);
delay(vel);
agarre(0);
agarre(2);
delay(vel);
atras(1);
atras(3);
delay(vel);
mover();
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(2);
delay(vel);
mid(6);
delay(vel);
poner();
delay(vel);
antihorario(5);
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(0);
delay(vel);
start(4);
delay(vel);
agarre(0);
agarre(2);
delay(vel);
atras(1);
atras(3);
delay(vel);
moveranti();
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(2);
delay(vel);
mid(6);
delay(vel);
poner();
delay(vel);
}

void down(){
agarre(1);
agarre(3);
delay(vel);
atras(0);
delay(vel);
fin(4);
delay(vel);
agarre(0);
agarre(2);
delay(vel);
atras(1);
atras(3);
delay(vel);
mover();
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(2);
delay(vel);
mid(6);
delay(vel);
poner();
delay(vel);
horario(7);
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(0);
delay(vel);
start(4);
delay(vel);
agarre(0);
agarre(2);
delay(vel);
atras(1);
atras(3);
delay(vel);
moveranti();
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(2);
delay(vel);
mid(6);
delay(vel);
poner();
delay(vel);
}

void downanti(){
agarre(1);
agarre(3);
delay(vel);
atras(0);
delay(vel);
fin(4);
delay(vel);
agarre(0);
agarre(2);
delay(vel);
atras(1);
atras(3);
delay(vel);
mover();
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(2);
delay(vel);
mid(6);
delay(vel);
poner();
delay(vel);
antihorario(7);
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(0);
delay(vel);
start(4);
delay(vel);
agarre(0);
agarre(2);
delay(vel);
atras(1);
atras(3);
delay(vel);
moveranti();
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(2);
delay(vel);
mid(6);
delay(vel);
poner();
delay(vel);
}

void downdoble(){
agarre(1);
agarre(3);
delay(vel);
atras(0);
delay(vel);
fin(4);
delay(vel);
agarre(0);
agarre(2);
delay(vel);
atras(1);
atras(3);
delay(vel);
mover();
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(2);
delay(vel);
mid(6);
delay(vel);
poner();
delay(vel);
doble(7);
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(0);
delay(vel);
start(4);
delay(vel);
agarre(0);
agarre(2);
delay(vel);
atras(1);
atras(3);
delay(vel);
moveranti();
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(2);
delay(vel);
mid(6);
delay(vel);
poner();
delay(vel);
}

void updoble(){
agarre(1);
agarre(3);
delay(vel);
atras(0);
delay(vel);
fin(4);
delay(vel);
agarre(0);
agarre(2);
delay(vel);
atras(1);
atras(3);
delay(vel);
mover();
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(2);
delay(vel);
mid(6);
delay(vel);
poner();
delay(vel);
doble(5);
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(0);
delay(vel);
start(4);
delay(vel);
agarre(0);
agarre(2);
delay(vel);
atras(1);
atras(3);
delay(vel);
moveranti();
delay(vel);
agarre(1);
agarre(3);
delay(vel);
atras(2);
delay(vel);
mid(6);
delay(vel);
poner();
delay(vel);
}
