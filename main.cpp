const short int SER_column = 2;
const short int RCLK_column = 3;
const short int SRCLK_column = 4;
const short int SER_row = 7;
const short int RCLK_row = 6;
const short int SRCLK_row = 5;

short binary_row[8];
int decimal_row;
short binary_column[8];
int decimal_column;

int One[2][8] = {{0,4,134,255,255,128,0,0},{0,2,4,8,16,32,0,0}};
int Two[2][8] = {{0,199,231,177,153,143,143,0},{0,2,4,8,16,32,64,0}};
int Three[2][8] = {{0,195,129,137,137,255,118,0},{0,2,4,8,16,32,64,0}};
int Four[2][8] = {{0,31,31,16,16,255,255,0},{0,2,4,8,16,32,64,0}};
int Five[2][8] = {{0,207,143,137,137,249,249,0},{0,2,4,8,16,32,64,0}};
int Six[2][8] = {{0,255,255,145,145,241,241,0},{0,2,4,8,16,32,64,0}};
int Seven[2][8] = {{0,1,225,241,61,31,7,0},{0,2,4,8,16,32,64,0}};
int Eight[2][8] = {{0,118,255,137,137,255,118,0},{0,2,4,8,16,32,64,0}};
int Nine[2][8] = {{0,31,31,17,17,255,255,0},{0,2,4,8,16,32,64,0}};
int Zero[2][8] = {{0,0,255,129,129,255,0,0},{0,0,4,8,16,32,0,0}};


void setup()
{
  Serial.begin(9600); // velocidad de transmisión de datos

  // Configuración de puertos digitales de salida
  pinMode(SER_column, OUTPUT);
  pinMode(RCLK_column, OUTPUT);
  pinMode(SRCLK_column, OUTPUT);
  pinMode(SRCLK_row, OUTPUT);
  pinMode(RCLK_row, OUTPUT);
  pinMode(SER_row, OUTPUT);
}

void loop()
{
  digitalWrite(SER_column, LOW);
  digitalWrite(RCLK_column, LOW);
  digitalWrite(SRCLK_column, LOW);
  digitalWrite(SRCLK_row, LOW);
  digitalWrite(RCLK_row, LOW);
  digitalWrite(SER_row, LOW);

  while(true){
    for(int i = 0; i < 8; i++){
        for(int j = 7; j >= 0; j--){
          // Llevar dato al puerto serial
          digitalWrite(SER_row, bitRead(Six[0][i],j));
          digitalWrite(SER_column, bitRead(Six[1][i],j));

          // Activar el reloj de la primera etapa de los registros
          digitalWrite(SRCLK_row, 0);
          digitalWrite(SRCLK_row, 1);
          digitalWrite(SRCLK_row, 0);

          digitalWrite(SRCLK_column, 0);
          digitalWrite(SRCLK_column, 1);
          digitalWrite(SRCLK_column, 0);
        }
    }

    // Activar el reloj de la segunda etapa de los registros
    digitalWrite(RCLK_row, 0);
    digitalWrite(RCLK_row, 1);
    digitalWrite(RCLK_row, 0);

    digitalWrite(RCLK_column, 0);
    digitalWrite(RCLK_column, 1);
    digitalWrite(RCLK_column, 0);

    delay(1000);
  }
}
