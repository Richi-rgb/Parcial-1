// Puertos Arduino
const int SER = 10; // Puerto serial
const int RCLK = 12; // Segundo reloj -etapa 1
const int SRCLK = 13; // Primer reloj-etapa 1

const int RCLK_row = 2; // Segundo reloj-etapa 2
const int SRCLK_row = 3; // Primera reloj-etapa 2

void setup()
{
  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);

  pinMode(RCLK_row, OUTPUT);
  pinMode(SRCLK_row, OUTPUT);

  //
  digitalWrite(SER, LOW);
  digitalWrite(RCLK, LOW);
  digitalWrite(SRCLK, LOW);

  digitalWrite(RCLK_row, LOW);
  digitalWrite(SRCLK_row, LOW);

  digitalWrite(SER, HIGH); // Dato del puerto serial

  // Primer reloj-primera etapa
  digitalWrite(SRCLK, LOW);
  digitalWrite(SRCLK, HIGH);
  digitalWrite(SRCLK, LOW);

  digitalWrite(SER, HIGH); // Dato del puerto serial

  // Primer reloj-primera etapa
  digitalWrite(SRCLK, LOW);
  digitalWrite(SRCLK, HIGH);
  digitalWrite(SRCLK, LOW);

  // Segundo reloj-primera etapa
  digitalWrite(RCLK, LOW);
  digitalWrite(RCLK, HIGH);
  digitalWrite(RCLK, LOW);

  // Primer reloj-segunda etapa
  digitalWrite(SRCLK_row, LOW);
  digitalWrite(SRCLK_row, HIGH);
  digitalWrite(SRCLK_row, LOW);

  // Segundo reloj-segunda etapa
  digitalWrite(RCLK_row, LOW);
  digitalWrite(RCLK_row, HIGH);
  digitalWrite(RCLK_row, LOW);
}

void loop()
{
}