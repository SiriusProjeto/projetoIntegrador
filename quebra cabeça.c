#include <windows.h>
#include <stdio.h>
#include <iostream.h>

extern"C" int getch(void); 

void gotoxy(int lin, int col)
{

HANDLE hOut;
COORD Position;
hOut = GetStdHandle(STD_OUTPUT_HANDLE);
Position.X = col;
Position.Y = lin;
SetConsoleCursorPosition(hOut,Position);
}

void desenha_caixa()
{
cout.flush();
gotoxy(0,0);
cout<<"Quebra-cabeca";cout.flush();
gotoxy(4,2);
cout<<"\332\304\304\304\302\304\304\304\302\304\304\304\277";cout.flush();
gotoxy(5,2);
cout<<"\263 \263 \263 \263";cout.flush();
gotoxy(6,2);
cout<<"\303\304\304\304\305\304\304\304\305\304\304\304\264";cout.flush();
gotoxy(7,2);
cout<<"\263 \263 \263 \263";cout.flush();
gotoxy(8,2);
cout<<"\303\304\304\304\305\304\304\304\305\304\304\304\264";cout.flush();
gotoxy(9,2);
cout<<"\263 \263 \263 \263";cout.flush();
gotoxy(10,2);
cout<<"\300\304\304\304\301\304\304\304\301\304\304\304\331";cout.flush();
}

void coloca_val(char mat[][3])
{
for (int l = 0; l < 3; l++)
for (int c = 0; c < 3; c++) {
gotoxy (5+l*2,4+4*c);
printf ("%c",mat[l][c]);
}
}

int verifica (char tentativa[][3],char objetivo[][3])
{

int i,j;
for (i=0;i<3;i++)
for (j=0;j<3;j++)
if (tentativa[j]!=objetivo[j])
return 0;

return 1;
}

/* Função que procura a posição do numero requisitado na matriz,
retorna false se não encontrou, se encontrou copia os valores
para col e lin*/
bool procura_numero(char puzzle[][3], char val, int &col, int &lin)
{
for (col = 0; col < 3; col++)
for (lin = 0; lin < 3; lin++)
if (puzzle[col][lin] == val)
return true;

return false;
}

bool move (char tenta[][3])
{
char valor;
int i,j,c,l,;

gotoxy(11,1);
cout<<"\nValor a ser movido:";cout.flush();
valor = getch();
if (valor == 's' || valor == 'S') // 's' ou 'S' sai do programa.
exit(0);
if ((valor < '0') && (valor > '9')) // Se a entrada for inválida não faz nada
return 0;

if (!(procura_numero(tenta, valor, c, l))) // Passa c e l por referência
return false;

if ((c < 2) && (tenta[c + 1][l] == ' ')) { // Checa se pode ir para frente.
tenta[c + 1][l] = tenta[c][l];
tenta[c][l] = ' ';
return true;
}

if ((c > 0) && (tenta[c - 1][l] == ' ')) { // Checa se pode ir para trás.
tenta[c - 1][l] = tenta[c][l];
tenta[c][l] = ' ';
return true;
}

if ((l > 0) && (tenta[c][l - 1] == ' ')) { // Checa se pode ir para cima.
tenta[c][l - 1] = tenta[c][l];
tenta[c][l] = ' ';
return true;
}

if ((l < 2) && (tenta[c][l + 1] == ' ')) { // Checa se pode ir para baixo.
tenta[c][l + 1] = tenta[c][l];
tenta[c][l] = ' ';
return true;
}

return false; // Se o movimento for inválido não faz nada.
}


int main()
{
char certa[3][3]= { { '1', '2', '3' },
{ '4', '5', '6' },
{ '7', '8', ' ' } }; // Espaço para facilitar a saída

char err[3][3]= { { '4', '1', '3' },
{ '7', '2', '5' },
{ '8', '6', ' ' } }; // ... O mesmo aqui

printf ("Para sair digite S");

while (!verifica (err,certa)) {
desenha_caixa();
coloca_val(err);
move(err);
}
gotoxy(12,5);
cout<<"Parabens!\n";cout.flush();

return 0;
}

using std::cout;

extern "C" { int getch(void); }

void gotoxy(int lin, int col)
{
HANDLE hOut;
COORD Position;
hOut = GetStdHandle(STD_OUTPUT_HANDLE);
Position.X = col;
Position.Y = lin;
SetConsoleCursorPosition(hOut,Position);
}

void desenha_caixa()
{
cout.flush();
gotoxy(0,0);
cout<<"Quebra-cabeca";cout.flush();
gotoxy(4,2);
cout<<"\332\304\304\304\302\304\304\304\302\304\30 4\304\277";cout.flush();
gotoxy(5,2);
cout<<"\263 \263 \263 \263";cout.flush();
gotoxy(6,2);
cout<<"\303\304\304\304\305\304\304\304\305\304\30 4\304\264";cout.flush();
gotoxy(7,2);
cout<<"\263 \263 \263 \263";cout.flush();
gotoxy(8,2);
cout<<"\303\304\304\304\305\304\304\304\305\304\30 4\304\264";cout.flush();
gotoxy(9,2);
cout<<"\263 \263 \263 \263";cout.flush();
gotoxy(10,2);
cout<<"\300\304\304\304\301\304\304\304\301\304\30 4\304\331";cout.flush();
}

void coloca_val(char mat[][3])
{
for (int l = 0; l < 3; l++)
for (int c = 0; c < 3; c++) {
gotoxy (5+l*2,4+4*c);
printf ("%c",mat[l][c]);
}
}

int verifica (char tentativa[][3],char objetivo[][3])
{

int i,j;
for (i=0;i<3;i++)
for (j=0;j<3;j++)
if (tentativa[j]!=objetivo[j])
return 0;

return 1;
}

/* Função que procura a posição do numero requisitado na matriz,
retorna false se não encontrou, se encontrou copia os valores
para col e lin*/
bool procura_numero(char puzzle[][3], char val, int &col, int &lin)
{
for (col = 0; col < 3; col++)
for (lin = 0; lin < 3; lin++)
if (puzzle[col][lin] == val)
return true;

return false;
}

bool move (char tenta[][3])
{
char valor;
int i,j,c,l,;

gotoxy(11,1);
cout<<"\nValor a ser movido:";cout.flush();
valor = getch();
if (valor == 's' || valor == 'S') // 's' ou 'S' sai do programa.
exit(0);
if ((valor < '0') && (valor > '9')) // Se a entrada for inválida não faz nada
return 0;

if (!(procura_numero(tenta, valor, c, l))) // Passa c e l por referência
return false;

if ((c < 2) && (tenta[c + 1][l] == ' ')) { // Checa se pode ir para frente.
tenta[c + 1][l] = tenta[c][l];
tenta[c][l] = ' ';
return true;
}

if ((c > 0) && (tenta[c - 1][l] == ' ')) { // Checa se pode ir para trás.
tenta[c - 1][l] = tenta[c][l];
tenta[c][l] = ' ';
return true;
}

if ((l > 0) && (tenta[c][l - 1] == ' ')) { // Checa se pode ir para cima.
tenta[c][l - 1] = tenta[c][l];
tenta[c][l] = ' ';
return true;
}

if ((l < 2) && (tenta[c][l + 1] == ' ')) { // Checa se pode ir para baixo.
tenta[c][l + 1] = tenta[c][l];
tenta[c][l] = ' ';
return true;
}

return false; // Se o movimento for inválido não faz nada.
}


int main()
{
char certa[3][3]= { { '1', '2', '3' },
{ '4', '5', '6' },
{ '7', '8', ' ' } }; // Espaço para facilitar a saída

char err[3][3]= { { '4', '1', '3' },
{ '7', '2', '5' },
{ '8', '6', ' ' } }; // ... O mesmo aqui

printf ("Para sair digite S");

while (!verifica (err,certa)) {
desenha_caixa();
coloca_val(err);
move(err);
}
gotoxy(12,5);
cout<<"Parabens!\n";cout.flush();

return 0;
}
