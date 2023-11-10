#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x43);

SoftwareSerial sw(2,3);    //2 ES RX, 3 ES TX EN EL ARDUINO

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
  i = 0; i <= (str_len-1); i++){     //recorre

//if(i==str_len-1)
//Serial.print(i);


if
  ((kociemba_sol.charAt(i)) =='R'){


if ((kociemba_sol.charAt(i+1)) == '2')
  {
      //right();
     // right();
     doble(6);
     Serial.println("R2");
     }


if ((kociemba_sol.charAt(i+1))
  == '\\') {
     // right_inverted();
     antihorario(6);
      Serial.println("R'");
      }

if (((kociemba_sol.charAt(i+1))!=
  '2') and((kociemba_sol.charAt(i+1)) != '\\')) {
      //right();
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
      //left();
      //left();
      doble(4);
      Serial.println("L2");
      }


if
  ((kociemba_sol.charAt(i+1)) == '\\') {
      //left_inverted();
      antihorario(4);
      Serial.println("L'");
      }

if (((kociemba_sol.charAt(i+1))!=
  '2') and((kociemba_sol.charAt(i+1)) != '\\')) {
     // left();
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
     // up();
    //  up();
    updoble();
    Serial.println("U2");
    }


if
  ((kociemba_sol.charAt(i+1)) == '\\') {
      //up_inverted();
      upanti();
      Serial.println("U'");
      }

if (((kociemba_sol.charAt(i+1))!=
  '2') and((kociemba_sol.charAt(i+1)) != '\\')) {
      //up();
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
      //down();
      //down();
     downdoble();
      Serial.println("D2");
      }


if
  ((kociemba_sol.charAt(i+1)) == '\\') {
      //down_inverted();
      downanti();
      Serial.println("D'");
      }

if (((kociemba_sol.charAt(i+1))!=
  '2') and((kociemba_sol.charAt(i+1)) != '\\')) {
      //down();
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
      //front();
      doble(7);
      //front();
      Serial.println("F2");
      }


if ((kociemba_sol.charAt(i+1)) == '\\') {
      //front_inverted();
      antihorario(7);
      Serial.println("F'");
      }

if
  (((kociemba_sol.charAt(i+1))!= '2') and((kociemba_sol.charAt(i+1)) != '\\')) {

     // front();
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
      //back();
     // back();
     doble(5);
     Serial.println("B2");
     }


if ((kociemba_sol.charAt(i+1)) ==
  '\\') {
      //back_inverted();
      antihorario(5);
      Serial.println("B'");
      }

if (((kociemba_sol.charAt(i+1))!= '2')
  and((kociemba_sol.charAt(i+1)) != '\\')) {
      //back();
      horario(5);
      Serial.println("B");
      }

}

else
  { //NO HACER NADA
      
}

}
   
                
        //warm_up();

        //scramble();
}

void midstart(int pin){
  if(pin==7){
  servos.setPWM(7,0,390);
  delay(500);
  servos.setPWM(7,0,390);}    
  if(pin==4){
  servos.setPWM(4,0,390);
  delay(500);
  servos.setPWM(4,0,376);}
  if(pin==5){
  servos.setPWM(5,0,330);
  delay(500);
  servos.setPWM(5,0,351);}  
  if(pin==6){
  servos.setPWM(6,0,350);
  delay(500);
  servos.setPWM(6,0,380);}  
  
  delay(500); 
}

void midfin(int pin){
  if(pin==7){
  servos.setPWM(7,0,390);
  delay(500);
  servos.setPWM(7,0,390);}    
  if(pin==4){
  servos.setPWM(4,0,345);
  delay(500);
  servos.setPWM(4,0,376);}
  if(pin==5){
  servos.setPWM(5,0,330);
  delay(500);
  servos.setPWM(5,0,351);}  
  if(pin==6){
  servos.setPWM(6,0,350);
  delay(500);
  servos.setPWM(6,0,380);}  
  
  delay(500); 
}


  
void agarre(int pin){
if(pin==0){
  servos.setPWM(0,0,350);}
if(pin==1){
  servos.setPWM(1,0,470);}  
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
  delay(100);
  servos.setPWM(8,0,440);}  
if(pin==3){
  servos.setPWM(3,0,330);}    
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
  delay(500);
  servos.setPWM(4,0,110);}
if(pin==5){
  servos.setPWM(5,0,89);
  delay(500);
  servos.setPWM(5,0,98);}  
if(pin==6){
  servos.setPWM(6,0,98);
  delay(500);
  servos.setPWM(6,0,125);}  
if(pin==7){
  servos.setPWM(7,0,89);
  delay(500);
  servos.setPWM(7,0,105);}    
}

void fin(int pin){
  if(pin==4){
  servos.setPWM(4,0,643);
  delay(500);
  servos.setPWM(4,0,620);}
if(pin==5){
  servos.setPWM(5,0,645);
  delay(500);
  servos.setPWM(5,0,607);}  
if(pin==6){
  servos.setPWM(6,0,655);
  delay(500);
  servos.setPWM(6,0,630);}  
if(pin==7){
  servos.setPWM(7,0,635);
  delay(500);
  servos.setPWM(7,0,620);}    
  delay(500); 
}

void mover(){
  servos.setPWM(4,0,345);
  servos.setPWM(6,0,655);
  delay(500);
  servos.setPWM(4,0,376);
  servos.setPWM(6,0,655);  
  delay(500);   
 }

void moveranti(){
  servos.setPWM(4,0,390);
  servos.setPWM(6,0,120);
  delay(500);
  servos.setPWM(4,0,376);
  servos.setPWM(6,0,160);  
  delay(500);   
 }
  
void midt(){
  servos.setPWM(4,0,376);
  servos.setPWM(5,0,358);  
  servos.setPWM(6,0,380);  
  servos.setPWM(7,0,369);    
  delay(500); 
  }
void mid(int pin){
  if(pin==7){
  servos.setPWM(7,0,360);
  delay(500);
  servos.setPWM(7,0,369);}    
  if(pin==4){
  servos.setPWM(4,0,345);
  delay(500);
  servos.setPWM(4,0,376);}
  if(pin==5){
  servos.setPWM(5,0,330);
  delay(500);
  servos.setPWM(5,0,358);}  
  if(pin==6){
  servos.setPWM(6,0,350);
  delay(500);
  servos.setPWM(6,0,380);}  
  
  delay(500); 
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
  agarre(2);
  atras(0);
  delay(500);
  start(4);
  delay(500);
  adelante(0);
  delay(500);
  fin(4);
  delay(500);
  atras(0);
  delay(500);
  mid(4);
  delay(500);
  poner();
  delay(500);
  }
if(pin==5){
  agarre(0);
  agarre(3);
  agarre(2);
  atras(1);
  delay(500);
  start(5);
  delay(500);
  adelante(1);
  delay(500);
  fin(5);
  delay(500);
  atras(1);
  delay(500);
  mid(5);
  delay(500);
  poner();
  delay(500);
  }
if(pin==6){
  agarre(0);
  agarre(3);
  agarre(1);
  atras(2);
  delay(500);
  start(6);
  delay(500);
  adelante(2);
  delay(500);
  fin(6);
  delay(500);
  atras(2);
  delay(500);
  mid(6);
  delay(500);
  poner();
  delay(500);
  }
if(pin==7){
  agarre(0);
  agarre(1);
  agarre(2);
  atras(3);
  delay(500);
  start(7);
  delay(500);
  adelante(3);
  delay(500);
  fin(7);
  delay(500);
  atras(3);
  delay(500);
  mid(7);
  delay(500);
  poner();
  delay(500);
  }
}

void horario(int pin){
if(pin==4){
  agarre(1);
  agarre(3);
  agarre(2);
  delay(500);
  fin(4);
  delay(500);
  atras(0);
  delay(500);
  mid(4);
  delay(500);
  adelante(0);
  delay(500);
  poner();
  delay(500);
  }
if(pin==5){
  agarre(0);
  agarre(3);
  agarre(2);
  delay(500);
  fin(5);
  delay(500);
  atras(1);
  delay(500);
  mid(5);
  delay(500);
  adelante(1);
  delay(500);
  poner();
  delay(500);
  }
if(pin==6){
  agarre(0);
  agarre(3);
  agarre(1);
  delay(500);
  fin(6);
  delay(500);
  atras(2);
  delay(500);
  mid(6);
  delay(500);
  adelante(2);
  delay(500);
  poner();
  delay(500);
  }
if(pin==7){
  agarre(0);
  agarre(1);
  agarre(2);
  delay(500);
  fin(7);
  delay(500);
  atras(3);
  delay(500);
  mid(7);
  delay(500);
  adelante(3);
  delay(500);
  poner();
  delay(500);
  }
}
void antihorario(int pin){
  if(pin==4){
  agarre(1);
  agarre(3);
  agarre(2);
  delay(500);
  start(4);
  delay(500);
  atras(0);
  delay(500);
  mid(4);
  delay(500);
  adelante(0);
  delay(500);
  poner();
  delay(500);
  }
if(pin==5){
  agarre(0);
  agarre(3);
  agarre(2);
  delay(500);
  start(5);
  delay(500);
  atras(1);
  delay(500);
  mid(5);
  delay(500);
  adelante(1);
  delay(500);
  poner();
  delay(500);
  }
if(pin==6){
  agarre(0);
  agarre(3);
  agarre(1);
  delay(500);
  start(6);
  delay(500);
  atras(2);
  delay(500);
  mid(6);
  delay(500);
  adelante(2);
  delay(500);
  poner();
  delay(500);
  }
if(pin==7){
  agarre(0);
  agarre(1);
  agarre(2);
  delay(500);
  start(7);
  delay(500);
  atras(3);
  delay(500);
  mid(7);
  delay(500);
  adelante(3);
  delay(500);
  poner();
  delay(500);
  }
  }

  void up(){
agarre(1);
agarre(3);
delay(500);
atras(0);
delay(500);
fin(4);
delay(500);
adelante(0);
delay(500);
atras(1);
atras(3);
delay(1000);
mover();
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(2);
delay(500);
mid(6);
delay(500);
poner();
delay(500);
horario(5);
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(0);
delay(500);
start(4);
delay(500);
adelante(0);
delay(500);
atras(1);
atras(3);
delay(1000);
moveranti();
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(2);
delay(500);
mid(6);
delay(500);
poner();
delay(500);
}

void upanti(){
agarre(1);
agarre(3);
delay(500);
atras(0);
delay(500);
fin(4);
delay(500);
adelante(0);
delay(500);
atras(1);
atras(3);
delay(1000);
mover();
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(2);
delay(500);
mid(6);
delay(500);
poner();
delay(500);
antihorario(5);
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(0);
delay(500);
start(4);
delay(500);
adelante(0);
delay(500);
atras(1);
atras(3);
delay(1000);
moveranti();
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(2);
delay(500);
mid(6);
delay(500);
poner();
delay(500);
}

void down(){
agarre(1);
agarre(3);
delay(500);
atras(0);
delay(500);
fin(4);
delay(500);
adelante(0);
delay(500);
atras(1);
atras(3);
delay(1000);
mover();
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(2);
delay(500);
mid(6);
delay(500);
poner();
delay(500);
horario(7);
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(0);
delay(500);
start(4);
delay(500);
adelante(0);
delay(500);
atras(1);
atras(3);
delay(1000);
moveranti();
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(2);
delay(500);
mid(6);
delay(500);
poner();
delay(500);
}

void downanti(){
agarre(1);
agarre(3);
delay(500);
atras(0);
delay(500);
fin(4);
delay(500);
adelante(0);
delay(500);
atras(1);
atras(3);
delay(1000);
mover();
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(2);
delay(500);
mid(6);
delay(500);
poner();
delay(500);
antihorario(7);
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(0);
delay(500);
start(4);
delay(500);
adelante(0);
delay(500);
atras(1);
atras(3);
delay(1000);
moveranti();
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(2);
delay(500);
mid(6);
delay(500);
poner();
delay(500);
}

void downdoble(){
agarre(1);
agarre(3);
delay(500);
atras(0);
delay(500);
fin(4);
delay(500);
adelante(0);
delay(500);
atras(1);
atras(3);
delay(1000);
mover();
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(2);
delay(500);
mid(6);
delay(500);
poner();
delay(500);
doble(7);
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(0);
delay(500);
start(4);
delay(500);
adelante(0);
delay(500);
atras(1);
atras(3);
delay(1000);
moveranti();
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(2);
delay(500);
mid(6);
delay(500);
poner();
delay(500);
}

void updoble(){
agarre(1);
agarre(3);
delay(500);
atras(0);
delay(500);
fin(4);
delay(500);
adelante(0);
delay(500);
atras(1);
atras(3);
delay(1000);
mover();
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(2);
delay(500);
mid(6);
delay(500);
poner();
delay(500);
doble(5);
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(0);
delay(500);
start(4);
delay(500);
adelante(0);
delay(500);
atras(1);
atras(3);
delay(1000);
moveranti();
delay(500);
agarre(1);
agarre(3);
delay(500);
atras(2);
delay(500);
mid(6);
delay(500);
poner();
delay(500);
}
