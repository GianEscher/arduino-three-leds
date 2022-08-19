// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2; // the number of the pushbutton pin

// variables will change:
int n = 0; // variable for reading the pushbutton status
int pin13 = 13;
int pin8 = 8;
int pin4 = 4;
int pin7 = 7;

void setup()
{
  Serial.begin(9600);
  Serial.flush();
  Serial.print("\n\ndigite um dado");
  Serial.println();

  pinMode(13, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin4, OUTPUT);
}

void resetLED(){
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(pin8, LOW);
  digitalWrite(pin4, LOW);
}

void loop()
{
  
  
  analogWrite(11,250);
  
  if (Serial.available() > 0)
  {
    
    //Serial.println("\n\n--pino ~11: ");
  	

  	//Serial.print("\n\n");
    
    n = Serial.read();

    switch (n)
    {
    case 97:
      resetLED();
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("\n\n--Amarelo--\n");
      break;

    case 98:
      resetLED();
      digitalWrite(pin8, HIGH);
      Serial.println("\n\n--Branco--\n");
      break;

    case 118:
      resetLED();
      digitalWrite(pin4, HIGH);
      Serial.println("\n\n--Vermelho--\n");
      break;
    }
    
    Serial.print("\n\nValor digitado: ");
    Serial.println(n, BIN);
    Serial.print("Valor lido: ");
    Serial.println(n);
    
  }
  Serial.flush();
}
