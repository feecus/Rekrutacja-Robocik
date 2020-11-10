//Autor: Gabriel Kocenko, listopad 2020
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

float s(int a1, int b1, int c1,int a2, int b2, int c2)
{
  return sqrt(pow((float)(a2-a1),2.0)+pow((float)(b2-b1),2.0)+pow((float)(c2-c1),2.0));
}

int main()
{
  int n,t,x0=0,y0=0,z0=0,x,y,z,koniec;
  float droga, predkosc;
  unsigned long long l_cyfr;

  printf("Oczekiwanie na dane ...\n");
  
  int tryb = open("fifo1", O_RDONLY);
  if(tryb == -1)
    {
      printf("Nastapil blad podczas nawiazywania polaczenia\n");
    }

  if(read(tryb, &n, sizeof(int))==-1)
    {
      printf("Nastapil blad podczas pobierania danych\n");
      return 3;
    }
  printf("Otrzymano n = %d\n",n);


  if(read(tryb, &t, sizeof(int))==-1)
    {
      printf("Nastapil blad podczas pobierania danych\n");
      return 3;
    }
  printf("Otrzymano t = %d\n",t);


  if(read(tryb, &l_cyfr, sizeof(unsigned long long))==-1)
    {
      printf("Nastapil blad podczas pobierania danych\n");
      return 3;
    }
  printf("Otrzymano l_cyfr = %lld\n",l_cyfr);

  for(int i=0;i<n;i++)
    {
      if(read(tryb, &x, sizeof(int))==-1)
	{
	  printf("Nastapil blad podczas pobierania danych\n");
	  return 3;
	}

      if(read(tryb, &y, sizeof(int))==-1)
	{
	  printf("Nastapil blad podczas pobierania danych\n");
	  return 3;
	}

      if(read(tryb, &z, sizeof(int))==-1)
	{
	  printf("Nastapil blad podczas pobierania danych\n");
	  return 3;
	}
      printf("\nOdebrano wspolrzedne: %d\t%d\t%d\n",x,y,z);

      droga=s(x0,y0,z0,x,y,z);
      predkosc=droga/((float)t);

      x0=x;
      y0=y;
      z0=z;
      
      printf("Aktualna predkosc: %f [j/s] \n",predkosc);

      sleep(t);
    }

  if(read(tryb, &koniec, sizeof(int))==-1)
	{
	  printf("Nastapil blad podczas pobierania danych\n");
	  return 3;
	}
  
  close(tryb);

  if(koniec == l_cyfr)
    {
      printf("\nOdebrano argument konczacy prace programu.\n");
      return 0;
    }
  
  return 0;
}
