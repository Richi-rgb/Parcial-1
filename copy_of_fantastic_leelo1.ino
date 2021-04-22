// Caracteres permitidos
// Numeros
const int one[8] = {0,4,134,255,255,128,0,0};
const int two[8] = {0,199,231,177,153,143,143,0};
const int three[8] = {0,195,129,137,137,255,118,0};
const int four[8] = {0,31,31,16,16,255,255,0};
const int five[8] = {0,207,143,137,137,249,249,0};
const int six[8] = {0,255,255,145,145,241,241,0};
const int seven[8] = {0,1,225,241,61,31,7,0};
const int eight[8] = {0,118,255,137,137,255,118,0};
const int nine[8] = {0,31,31,17,17,255,255,0};
const int zero[8] = {0,0,255,129,129,255,0,0};

// Alfabeto mayuscula
const int A[8] = {0,255,255,17,17,255,255,0};
const int B[8] = {0,255,255,137,137,255,118,0};
const int C[8] = {0,255,255,129,129,129,195,0};
const int D[8] = {0,255,255,129,129,195,126,0};
const int E[8] = {0,255,255,137,137,129,195,0};
const int F[8] = {0,255,255,9,9,1,3,0};
const int G[8] = {0,255,255,129,145,241,243,0};
const int H[8] = {0,255,255,24,24,255,255,0};
const int I[8] = {0,129,129,255,255,129,129,0};
const int J[8] = {0,224,129,129,255,255,1,1};
const int K[8] = {0,255,255,8,52,194,131,0};
const int L[8] = {0,255,255,128,128,128,0,0};
const int M[8] = {0,255,255,6,8,6,255,255};
const int N[8] = {0,255,255,6,24,96,255,255};
const int O[8] = {0,126,255,129,129,255,126,0};
const int P[8] = {0,255,255,17,17,31,31,0};
const int Q[8] = {0,126,255,129,193,255,254,128};
const int R[8] = {0,255,255,17,113,223,159,0};
const int S[8] = {0,207,143,137,137,249,251,0};
const int T[8] = {0,1,1,255,255,1,1,0};
const int U[8] = {0,127,255,128,128,255,127,0};
const int V[8] = {0,63,127,128,128,127,63,0};
const int W[8] = {127,255,64,32,64,255,127,0};
const int X[8] = {0,131,68,40,16,40,68,131};
const int Y[8] = {0,7,12,248,248,12,7,0};
const int Z[8] = {131,195,225,177,153,141,199,195};

// Alfabeto minuscula
const int a[8] = {0,236,228,164,164,252,252,0};
const int b[8] = {0,254,254,144,144,240,240,0};
const int c[8] = {0,252,252,132,132,132,204,0};
const int d[8] = {0,240,240,144,144,254,254,0};
const int e[8] = {0,252,252,148,148,156,156,0};
const int f[8] = {0,252,254,18,2,4,0,0};
const int g[8] = {0,238,142,138,138,254,254,0};
const int h[8] = {0,254,254,32,32,224,224,0};
const int i[8] = {0,0,0,244,244,0,0,0};
const int j[8] = {0,192,128,250,250,0,0,0};
const int k[8] = {0,252,252,16,40,196,132,0};
const int l[8] = {0,0,0,254,254,0,0,0};
const int m[8] = {252,252,8,248,8,248,248,0};
const int n[8] = {0,252,252,8,8,248,248,0};
const int o[8] = {0,120,252,132,132,252,120,0};
const int p[8] = {0,254,254,10,10,14,14,0};
const int q[8] = {0,14,14,10,42,254,254,32};
const int r[8] = {0,252,252,8,8,24,24,0};
const int s[8] = {0,156,156,148,148,244,244,0};
const int t[8] = {0,0,4,254,254,132,0,0};
const int u[8] = {0,124,252,128,128,252,124,0};
const int v[8] = {0,60,124,128,128,124,60,0};
const int w[8] = {0,124,252,128,64,128,252,124};
const int x[8] = {0,140,80,32,80,140,0,0};
const int y[8] = {0,206,206,136,136,254,254,0};
const int z[8] = {0,140,196,164,148,140,196,0};

// Esta función convierte los numeros del sistema decimal a binario
int binary(int array[], int position, int number) {
	for (int i = 0; i < 8; i++) {
		array[i] = number % 2;
		number /= 2;
	}
	return array[position];
}

// Puertos Arduino
const int SER = 10; // Puerto serial
const int RCLK = 12; // Segundo reloj -etapa 1
const int SRCLK = 13; // Primer reloj-etapa 1

const int RCLK_row = 2; // Segundo reloj-etapa 2
const int SRCLK_row = 3; // Primera reloj-etapa 2

void setup()
{
  Serial.begin(9600);

  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);

  pinMode(RCLK_row, OUTPUT);
  pinMode(SRCLK_row, OUTPUT);

  Serial.print("MANUAL DE USO\n");
  Serial.print("Al iniciar el programa tiene tres opciones:\n");
  Serial.print("1) Verificar: enciende los leds uno por uno de abajo hacia arriba y de izquierda a derecha\n");
  Serial.print("\t\tpara ver si la matriz 8x8 funciona, para esto debe de ingresar 1.\n");
  Serial.print("2) Imagen: Mostrara en la matriz de leds un caracter disponible (estos caracteres se mostraran mas abajo).\n");
  Serial.print("3) Patron de Imagenes: Mostrara letra por letra la frase que el usuario ingrese (tener en cuenta que si el caracter\n");
  Serial.print("\t\tno se encuentra disponible no lo imprimira y continuara con los otros).\n");
  Serial.print("Caracteres Disponibles:\n");
  Serial.print("Cuenta con todas las letras del alfabeto ingles en mayuscula y minuscula y los numeros arabigos\n\n\n");
}

void loop()
{
  
}