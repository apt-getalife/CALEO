#include<Servo.h>

//Definição para os dois motores
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

//Definindo pinos para o controle de velocidade dos motores
#define ENA 3
#define ENB 11

Servo myservo;

// Variáveis globais para receberem os valores dos eixo X e Y do JoyStick A
//int JoyAX = 150, JoyAY = 150;
int JoyBX = 90, JoyBY = 90;              

void setup() {

  // Iniciando a porta serial
  Serial.begin(9600); 

  // Declarando os motores 
  pinMode(IN1,OUTPUT);         
  pinMode(IN2,OUTPUT);              
  pinMode(IN3,OUTPUT);              
  pinMode(IN4,OUTPUT);              
  pinMode(ENA,OUTPUT);              
  pinMode(ENB,OUTPUT);     
  myservo.attach(10);

  // Definindo a velocidade dos motores, caso esteja muito lento ou muito rápido altere os números entre 0 a 255           
  analogWrite(ENA,200);            
  analogWrite(ENB,200);            
}
 
char cha;
 
void loop() { 

  if (Serial.available() > 0) {
     cha = Serial.read();
    delay(10);
  }

  //Movimenta para frente
  if(cha == 'B'){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  }

  //Movimenta para trás
  if(cha == 'F'){
   digitalWrite(IN1,LOW);
   digitalWrite(IN2,HIGH);
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,HIGH);
  }

  //Controla o esterçamento
  if (cha == 'C') {          
    JoyBX = Serial.parseInt();         
    while (cha != 'D') {     
      if (Serial.available()) {         
        cha = Serial.read(); 
        if (cha == 'Y') {   
            JoyBY = Serial.parseInt();    
        }
      }
    }
  }
  myservo.write(JoyBX);

  if(cha=='8'){
  myservo.write(135);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW); 
}
  //Sem movimento
  if(cha == '0') {
    delay(2);
    myservo.write(90);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
  }
}
