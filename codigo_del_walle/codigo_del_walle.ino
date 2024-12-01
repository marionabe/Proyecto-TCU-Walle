#include <Servo.h>

// _ _ _ _ _ _ _ _ _ _ _ _ Conexión de Pines _ _ _ _ _ _ _ _ _ _ _ _\\ 
//Pines de control de giro de motor derecho
int mot_der_hor = 12;
int mot_der_ant_hor =11;  

//Pines de control de gito de motor izquierdo
int mot_izq_hor = 4;
int mot_izq_ant_hor = 2;

//Pines para control de motores con PWM
int vel_der = 6;
int vel_izq = 3;

//Pines de lectura de datos de acelerometro
int x_out = 3;
int y_out = 1;
int z_out = 2;


// _ _ _ _ _ _ _ _ _ _ _ _ Variables _ _ _ _ _ _ _ _ _ _ _ _ \\
//Almacenar valores de lectura analogica de aceleraciones
int x_analog;
int y_analog;
int z_analog;

//Valores para calibrar el acelerometro
//Indicar el valor medido correspondiente a 0g y 1g en cada entrada
int x_m1g = 274;//-1g 
int x_0g = 340;
int x_1g = 410;

int y_m1g = 272;
int y_0g = 340 ;
int y_1g = 410;

int z_m1g = 277;
int z_0g  = 343;
int z_1g  = 410;

// Posicion mas baja = 70°  < Movimiento del brazo derecho   < 110°=Posición más alta
// Posicion mas baja = 120° < Movimiento del brazo izquierdo < 70° =Posición más alta
int angulo_derecho=90;
int angulo_izquierdo=90;


//Para escribir en motores
int vel_base_motrs; //Velocidad base de los motores, con base en el angulo
int vel_dir_motrs;  //Control de velocidad con base en si hay que girar a derecha o izquierda
int vel_mot_der;    //Utilizadas para escribir sobre los motores
int vel_mot_izq;

//Almacenar los valores de los angulos
int x_angulo;
int y_angulo;
int z_angulo; //Variable z no implementada en el codigo

int rang_inf_pwm=5; //Se utiliza para mapear la entrada analogica del acelerometro: 
                    //en lugar de 0, se reemplaza por esta variable
int rang_sup_pwm=90;

float velocidad = 0;

Servo servoDerecho;
Servo servoIzquierdo;
Servo servoCabeza;

int modificador_angulo=1;
int angulo_cabeza=90;

bool lim_sup=true;
int stop_mov;
int contador=0;


void setup()
{
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  servoDerecho.attach(9);
  servoIzquierdo.attach(5);
  servoCabeza.attach(10);

  //Posicion centrada de los brazos y la cabeza
  servoDerecho.write(90);
  servoIzquierdo.write(90);
  servoCabeza.write(90);  //Rango de movimiento de la cabeza: 135-50
}
 

void loop(){
  y_analog = analogRead(y_out);
  x_analog = analogRead(x_out);

  //Imprimir valores analogicos leidos:
  Serial.print("|   Valor de x_analog, y_analog, z_analog:   ");
  Serial.print(x_analog);
  Serial.print("   ");
  Serial.print(y_analog);
    Serial.print("   ");
  Serial.print(z_analog);
     Serial.print("   ");
  Serial.println(angulo_izquierdo);
   Serial.print("   ");
  Serial.println(angulo_derecho);
    Serial.println();

  // Aqui se controla si se debe mover hacia adelante o hacia atrás. También se decide la velocidad a la que se debe realizar.
  if (y_analog > 370){
    //Esto indica que se está inclinando el acelerometro hacia el frente, es decir, hay que moverse hacia el frente
    digitalWrite(mot_der_hor, HIGH);
    digitalWrite(mot_izq_hor, HIGH);
    digitalWrite(mot_der_ant_hor, LOW);
    digitalWrite(mot_izq_ant_hor, LOW);
    velocidad = ((y_analog-370)/((y_1g-370)*0.1))*rang_sup_pwm*0.1+80;
    Serial.print(int(velocidad));
    analogWrite(vel_der, int(velocidad)+20);
    analogWrite(vel_izq, int(velocidad)+25);

    // Cuando el robot se mueve hacia adelante, los brazos se mueven simulando caminar
    servoDerecho.write(angulo_derecho);
    servoIzquierdo.write(angulo_izquierdo);
    angulo_derecho = angulo_derecho + modificador_angulo;
    angulo_izquierdo = angulo_izquierdo + modificador_angulo;
    if (angulo_derecho >= 110){
      modificador_angulo = -5;
    }else if (angulo_derecho <= 70){
      modificador_angulo = 5;
    }

    //También cuando camina hacia adelante, el robot mueve la cabeza hacia abajo simulando caminar
    if (angulo_cabeza>=55){
      angulo_cabeza--;
      lim_sup=false;
      stop_mov=false;
      contador=0;
    }
    servoCabeza.write(angulo_cabeza);

  } else if(y_analog < 320){
    // Este es el caso donde se indica que se desea mover hacia atrás el walle
    digitalWrite(mot_der_hor, LOW);
    digitalWrite(mot_izq_hor, LOW);
    digitalWrite(mot_der_ant_hor, HIGH);
    digitalWrite(mot_izq_ant_hor, HIGH);
    analogWrite(vel_der, int(velocidad));
    analogWrite(vel_izq, int(velocidad));
    velocidad = ((370-y_analog)/((370-y_m1g)*0.1))*rang_sup_pwm*0.1+80;
    Serial.print(int(velocidad));
    analogWrite(vel_der, int(velocidad));
    analogWrite(vel_izq, int(velocidad));
  }else{
    // El walle se detiene
    analogWrite(vel_der, 0);
    analogWrite(vel_izq, 0);
    // Cuando se tiene el movimiento, los brazos y la cabeza también se retornan a la posicion central
    angulo_derecho = 90;
    angulo_izquierdo = 90;

    // Cuando el movimiento se detiene, el walle sube y baja la cabeza, como si estuviera viendo lo que tiene en frente 
    if (angulo_cabeza<=120 && lim_sup==false){
      angulo_cabeza=angulo_cabeza+4;
    }
    if (angulo_cabeza>=120){
        // Este es un pequeño retardo que se agrega para que el walle se quede "viendo" hacia arriba un momento cuando termina de caminar, 
        // como si estuviera viendo lo que tiene enfrente
        contador++;
        if (contador>=10){
          lim_sup=true;
        }
    }
    if(lim_sup==true){
      if (angulo_cabeza>=90){
        angulo_cabeza=angulo_cabeza-4;
      }

    }
    servoDerecho.write(angulo_derecho);
    servoIzquierdo.write(angulo_izquierdo);
    servoCabeza.write(angulo_cabeza);
  }
  // Aqui se decide cuándo se debe rotar
  if (x_analog < 320){
    analogWrite(vel_der, 0);
    analogWrite(vel_izq, 200);
  } else if (x_analog > 360){
    analogWrite(vel_der, 200);
    analogWrite(vel_izq, 0);
  }
}
