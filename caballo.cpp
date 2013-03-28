#include <iostream>
 using namespace::std;
 #include <cstdlib>
 #include <ctime>

 const int TamanoTabla = 8; //casilla 8x8 ajedrez
 
 int Valores( int );
 void Mueve(int A[TamanoTabla][ TamanoTabla ], int);
 int x = 0;
 int y = 0;
 int contador = 1;

 int main()

 { 

 srand(time(NULL)); //random
 int Tabla[TamanoTabla ][TamanoTabla ] = {{0}, {0}};
 int i;
 int caballo = 1;
 int espaciollenar;
 int Puedo_Mover_Aqui[TamanoTabla ] = {0};
 //int sinpasar[Tamano_Arreglo] [Tamano_Arreglo] = {{3}, {3} || {3}, {6} || {6}, {3} || {6}, {6}} ;
 int Valores_Accesibilidad[TamanoTabla ] = {0, 0};
 cout <<"Cuantas casillas quiere que recorra el caballo -> ";
 cin >> espaciollenar;
if (espaciollenar > 64)
{ cout <<endl << "Ingrese saltos del caballo menor a 64, gracias" << endl <<endl;
  cout << "Para salir "; system("pause"); return 0; }
  
  for ( int j = 0; j < TamanoTabla; j++ )
   {

      for( int k = 0; k < TamanoTabla; k++ )
        {
          Tabla[j][k] = 0;
        }

      Puedo_Mover_Aqui[ j ] = 0;
      Valores_Accesibilidad[j] = 10;
   }

 Tabla[ y ][ x ] = 1;
 while ( espaciollenar > contador && 1 == caballo )
 {
  //analiza cuantos espacios se lñlenaran
 caballo = 0;
 for( int k = 0; k < TamanoTabla; k++ )
 {
 Puedo_Mover_Aqui[ k ] = 0;
 Valores_Accesibilidad[k] = 10;
 }

 for ( i = 0; i < TamanoTabla; i++ )

 { 
 switch (i)
 { 

 case 0:
 {
     if ( x + 2 < TamanoTabla && y - 1 >= 0 )
     {
          
       if ( Tabla[y - 1][x + 2] == 0 )
        {
            
           Puedo_Mover_Aqui[i] = 1;
           
        }
        
         //if ( Tabla [3,3] || Tabla [3,6] || Tabla [6,3] || Tabla [6,6] )
         //{  }

     }
 break;
 }
 //--------------------------------------------------
 
 case 1:
 {

 if ( x + 1 < TamanoTabla && y - 2 >= 0 )
 {
 if ( Tabla[y - 2][x + 1] == 0 )
 {
 Puedo_Mover_Aqui[i] = 1;
 }
 }
 break;

 }

 case 2:
 {

 if ( x - 1 >= 0 && y - 2 >= 0 )
 {
 if ( Tabla[y - 2][x - 1] == 0 )
 {
 Puedo_Mover_Aqui[i] = 1;
 }
 }
 break;
 }
 case 3:
 {
 if ( x - 2 >= 0 && y - 1 >= 0 )
 {
 if ( Tabla[y - 1][x - 2] == 0 )
 {
 Puedo_Mover_Aqui[i] = 1;
 }
 }
 break;
 }

 case 4:
 {
 if ( x - 2 >= 0 && y + 1 < TamanoTabla )
 {
 if ( Tabla[y + 1][x - 2] == 0 )
 {
 Puedo_Mover_Aqui[i] = 1;
 }
 }
 break;
 }
 case 5:

 {

 if ( x - 1 >= 0 && y + 2 < TamanoTabla )
 {
 if ( Tabla[y + 2][x - 1] == 0 )
 {
 Puedo_Mover_Aqui[i] = 1;
 }
 }
 break;
 }
 case 6:

 {
 if ( x + 1 < TamanoTabla && y + 2 < TamanoTabla )
 {
 if ( Tabla[y + 2][x + 1] == 0 )
 {
 Puedo_Mover_Aqui[i] = 1;
 }
 }
 break;

 }

 case 7:
 {
 if ( x + 2 < TamanoTabla && y + 1 < TamanoTabla )
 { 
 if ( Tabla[y + 1][x + 2] == 0 )
 { 
 Puedo_Mover_Aqui[i] = 1;
 } 
 } 
 break;
 }
 default:
 {
 cout << "Contador i presenta fallas" << endl;
 
 break;

 }
 } 
 } 
 
 for ( i = 0; i < TamanoTabla; i++ )
 {
 if ( 1 == Puedo_Mover_Aqui[i] )
 {
 caballo = 1;
 }
 }
 if ( 1 == caballo )
 { 
 for ( i = 0; i < TamanoTabla; i++ )
 { 
 if ( 1 == Puedo_Mover_Aqui[ i ])
 { //ABRE IF ANIDADO
 Valores_Accesibilidad[i] = Valores(i);
 } //CIERRA IF
 } //CIERRA FOR

 int menor = Valores_Accesibilidad[0];
 int movimiento_a_hacer = 0;

 for ( i = 1; i < TamanoTabla; i++ )
 {
 if ( Valores_Accesibilidad[i] < menor )
 {
 menor = Valores_Accesibilidad[i];
 movimiento_a_hacer = i;
 }

 if ( Valores_Accesibilidad[i] == menor )
 {
 int aguila_o_sol = rand() % 2;
 if ( 0 == aguila_o_sol )
 movimiento_a_hacer = i;
 }
 }

 ++contador;
 Mueve( Tabla, movimiento_a_hacer);

 } 
 } 
 int num=8;
 cout <<"El contador es: " << contador << endl << endl; 
 cout<<"Puede que salga un contador menor al ingresado, esto sucede por los mivimientos random que se realizan, disculpe las molestias"<<endl<<endl;
 cout<<"El numero que sale en la tabla, indica el orden de los movimientos segun la cantidad ingresada, el 0 indica posiciones donde no paso el caballo"<<endl<<endl;
  cout <<"  A  B  C  D  E  F  G  H "<<endl; //IMPRIME indice del tablero horizontal
  cout <<num<<"-";
  num--;
 for ( int d = 0; d < TamanoTabla; d++ )
 {
 for( int k = 0; k < TamanoTabla; k++ )
 { 
 if ( 0 == Tabla[d][k] && 0 == Tabla[d][k] / 10 )
  
 cout << " ";
 cout << Tabla[d][k] << " "; 
 }
 cout << endl <<endl;
 
 cout <<num<<"-"; //IMPRIME indice del tablero vertical 
 num--;
 }
system("pause");
 return 0;

 } 




 int Valores(int movimiento)

 { 
 int Acceso[TamanoTabla + 1][TamanoTabla + 1] =

 {

 { 2, 3, 4, 4, 4, 4, 3, 2 },
 { 3, 4, 6, 6, 6, 6, 4, 3 },
 { 4, 6, 99, 8, 8, 99, 6, 4 },
 { 4, 6, 8, 8, 8, 8, 6, 4 },
 { 4, 6, 8, 8, 8, 8, 6, 4 },
 { 4, 6, 99, 8, 8, 99, 6, 4 },  //el numero 99 indica donde estan supuestamente los peones 
 { 3, 4, 6, 6, 6, 6, 4, 3 },    //para que no haga un movimiento en esa casilla se uso
 { 2, 3, 4, 4, 4, 4, 3, 2 }    //un numero mayor para que no ejecutara el movimiento

 };

 switch (movimiento)

 { 

 case 0:
 {
 return Acceso[y - 1][x + 2];
 break;
 }

 case 1:
 {
 return Acceso[y - 2][x + 1];
 break;
 }
 case 2:
 {
 return Acceso[y - 2][x - 1];
 break;
 }
 case 3:
 {
 return Acceso[y - 1][x - 2];
 break;
 }

 case 4:
 {
 return Acceso[y + 1][x - 2];
 break;
 }

 case 5:
 {
 return Acceso[y + 2][x - 1];
 break;
 }

 case 6:
 {
 return Acceso[y + 2][x + 1];
 break;
 }

 case 7:
 {
 return Acceso[y + 1][x + 2];
 break;
 }

 default:

 {
 cout << "El moviemiento no esta permitido" << endl;
 return -1;
 break;
 }
 } 

 } 


 void Mueve(int A[TamanoTabla][TamanoTabla ], int movimientos )

 {
 switch (movimientos)

 { 
 case 0:
 {
 y -= 1;
 x += 2;
 A[y ][x ] = contador;
 break;
 }

 case 1:
 {
 y -= 2;
 x += 1;
 A[y ][x ] = contador;
 break;
 }

 case 2:
 {
 y -= 2;
 x -= 1;
 A[y ][x ] = contador;
 break;

 }

 case 3:
 {
 y -= 1;
 x -= 2;
 A[y ][x ] = contador;
 break;
 }

 case 4:
 {
 y += 1;
 x -= 2;
 A[y ][x ] = contador;
 break;
 }

 case 5:
 {
 y += 2;
 x -= 1;
 A[y][x ] = contador;
 break;
 }

 case 6:
 {
 y += 2;
 x += 1;
 A[y ][x ] = contador;
 break;
 }

 case 7:
 {
 y += 1;
 x += 2;
 A[y ][x ] = contador;
 break;
 }

 default:

 {
 cout << "El movimiento no esta permitido" << endl;
 
 
 break;
 
 }

} 
 return;

 } 
 
