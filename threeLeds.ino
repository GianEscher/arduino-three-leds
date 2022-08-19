// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2; // the number of the pushbutton pin

// variables will change:
int n = 0; // variable for reading the pushbutton status
int pin8 = 8;
int pin12 = 12;
int pin2 = 2;
int pin4 = 4;
int pin7 = 7;

void setup()
{
  Serial.begin(9600);
  Serial.flush();
  Serial.print("\n\ndigite um dado");
  Serial.println();

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin7, OUTPUT);


  
}

void resetLED(){
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(pin8, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin12, LOW);
  digitalWrite(pin7, LOW);
}

void loop()
{
    
  if (Serial.available() > 0)
  {
    
    n = Serial.read();

    switch (n)
    {
    case 97:
      resetLED();
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("\n\n--PRIMEIRO--\n");
      break;

    case 98:
      resetLED();
      digitalWrite(pin12, HIGH);
      Serial.println("\n\n--SEGUNDO--\n");
      break;

    case 99:
      resetLED();
      digitalWrite(pin8, HIGH);
      Serial.println("\n\n--TERCEIRO--\n");
      break;

    case 100:
      resetLED();
      digitalWrite(pin7, HIGH);
      Serial.println("\n\n--QUARTO--\n");
      break;

    case 101:
      resetLED();
      digitalWrite(pin4, HIGH);
      Serial.println("\n\n--QUINTO--\n");
      break;

    case 102:
      resetLED();
      digitalWrite(pin2, HIGH);
      Serial.println("\n\n--SEXTO--\n");
      break;

     case 10:
      break;
     
     default:
      resetLED();
     }

    Serial.print("\n\nValor digitado: ");
    Serial.println(n, BIN);
    Serial.print("Valor lido: ");
    Serial.println(n);
    
  }
  Serial.flush();
}
