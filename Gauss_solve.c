//������� ������� ���. ��������� ������� ������
//� ������� �������� ��������
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
//#define N 50
void glavelem( int k, double mas[5] [6], int n, int otv[] );

int main( void )
{
  //setlocale (LC_CTYPE, �Rus�);
  
  double mas[5][6]={   //����� ������, � ������� ����� ����������� ����������� ������� �������
	{4,2,2,3,-3,10},
	{0,4,5,4,5,28},
	{2,4,-1,4,5,46},
	{3,3,-1,4,3,39},
	{-2,5,0,1,-1,-3}
				 };
  char letters[5]={'x','y','z','p','q'};
  double x[5]; //����� �������
  int otv[5]; //�������� �� ������� ������
  int i, j, k, n=5;
  //���� ������
  system("cls");
  /*do
  {
    printf( "Enter number of equations: " );
    scanf( "%d", & n );
    if ( N < n )
      printf( "This number is very big. Try again\n" );
  }
  while ( N < n );
  printf( "Enter system of equations:\n" );
  for ( i = 0; i < n; i++ )
    for ( j = 0; j < n + 1; j++ )
      scanf( "%lf", & mas[i] [j] );*/
  //����� ��������� �������
  system("cls");
  printf( "Solve system:\n" );
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n + 1; j++ )
      printf( "%7.2f ", mas[i] [j] );
    printf( "\n" );
  }
  //������� ��� ����� �� �������
  for ( i = 0; i < n ; i++ )
    otv[i] = i;
  //������ ��� ������ ������
  for ( k = 0; k < n; k++ )
  { //�� ����� ������� ������ ������ ������� �������
    glavelem( k, mas, n, otv ); //��������� �������� ��������
    if ( fabs( mas[k] [k] ) < 0.0001 )
    {
      printf( "NO SOLUTION!" );  //���� ��� ������� � �������
      return ( 0 );
    }
    for ( j = n; j >= k; j-- )
      mas[k] [j] /= mas[k] [k];
    for ( i = k + 1; i < n; i++ )
      for ( j = n; j >= k; j-- )
        mas[i] [j] -= mas[k] [j] * mas[i] [k];
  }
  //�������� ���
  for ( i = 0; i < n; i++ )
    x[i] = mas[i] [n];
  for ( i = n - 2; i >= 0; i-- )
    for ( j = i + 1; j < n; j++ )
      x[i] -= x[j] * mas[i] [j];
  //����� ����������
  printf( "SOLUTION:\n" );
  for ( i = 0; i < n; i++ )
    for ( j = 0; j < n; j++ )
      if ( i == otv[j] )
      { //����������� ����� �� �������
		printf("%c=",letters[i]);
        printf( "%f\n", x[j] );
        break;
      }
  return ( 0 );
}
//----------------------------------------------
//��������  �������
//----------------------------------------------
void glavelem( int k, double mas[5] [6], int n, int otv[] )
{
  int i, j, i_max = k, j_max = k;
  double temp;
  //���� ������������ �� ������ �������
  for ( i = k; i < n; i++ )
    for ( j = k; j < n; j++ )
      if ( fabs( mas[i_max] [j_max] ) < fabs( mas[i] [j] ) )
      {
        i_max = i;
        j_max = j;
      }
  //������������ ������
  for ( j = k; j < n + 1; j++ )
  {
    temp = mas[k] [j];
    mas[k] [j] = mas[i_max] [j];
    mas[i_max] [j] = temp;
  }
  //������������ �������
  for ( i = 0; i < n; i++ )
  {
    temp = mas[i] [k];
    mas[i] [k] = mas[i] [j_max];
    mas[i] [j_max] = temp;
  }
  //��������� ��������� ������� ������
  i = otv[k];
  otv[k] = otv[j_max];
  otv[j_max] = i;
}
