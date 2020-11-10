 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <unistd.h>

 #include <sys/types.h> /*Biblioteki do obslugi FIFO*/
 #include <sys/stat.h>
 #include <errno.h>
 #include <fcntl.h>

int znak(int a)
{
  if(a%2==0)
    {
      return -1;
    }
  return 1;
}

unsigned long long pot(int a,int b)
{
  unsigned long long wynik=1;
  for(int i=0;i<b;i++)
    {
      wynik=wynik*a;
    }
  return wynik;
}

int main()
{
 
  int x=0,y=0,z=0,znakx,znaky,znakz;
  int n,t,c=0; /*n-ilość wywołań, t-czas, co jaki wywołanie następuje*/
  unsigned long long l_cyfr;
  printf("Program wyznacza kolejne wspolrzedne polozenia lodzi i przekazuje je do drugiego programu\n");

  printf("Podaj n (liczba wywolan): ");
  scanf("%d",&n);
  printf("Podaj t (czas): ");
  scanf("%d",&t);
  while(c<1||c>10)
    {
      printf("Podaj liczbe cyfr wspolrzednej  (od 1-10): ");
      scanf("%d", &c);
      if(c<1||c>10)
	{
	  printf("Niepoprawne dane. Wprowadz jeszcze raz. \n");
	}
    }
  
  l_cyfr=pot(10,c);
  printf("Zakres wspolrzednych: 1 - %lld\n", l_cyfr);

  
  if( mkfifo("fifo1",0777) == -1) /*Utworzenie pliku FIFO "fifo1"*/
    {
      if(errno != EEXIST) /*Jesli wystapil blad przy tworzeniu pliku FIFO inny niz to, ze plik juz istnieje */
	{
	  printf("Nie mozna nawiazac polaczenia\n"); /*"Nie mozna utworzyc pliku FIFO"*/
	  return 1;
	}
    }

  printf("Oczekiwanie na polaczenie... (otworz drugi program)\n");

  int tryb =  open("fifo1", O_WRONLY); /*Otworzenie pliku FIFO*/
  if(tryb == -1)
    {
      printf("Nastapil blad podczas nawiazywania polaczenia\n");
      return 2;
    }
  
  printf("Polaczono\n");

  printf("Wysylanie n ...\n");
  if (write(tryb, &n, sizeof(int))==-1)
	{
	  printf("Nastapil blad podczas przesylania danych\n");
	  return 3;
	}

  printf("Wysylanie t ...\n");
  if (write(tryb, &t, sizeof(int))==-1)
	{
	  printf("Nastapil blad podczas przesylania danych\n");
	  return 3;
	}

  printf("Wysylanie l_cyfr ...\n");
  if (write(tryb, &l_cyfr, sizeof(unsigned long long))==-1)
	{
	  printf("Nastapil blad podczas przesylania danych\n");
	  return 3;
	}
  
  srand((unsigned)time(0));
  for (int i=0;i<n;i++)
    {
      znakx=znak(rand()%10);
      znaky=znak(rand()%10);
      znakz=znak(rand()%10);
      
      x=(rand()%l_cyfr)*znakx;
      y=(rand()%l_cyfr)*znaky;
      z=(rand()%l_cyfr)*znakz;

      printf("\nGenerowanie %d. zestawu\n",i+1);
      printf("%d\t%d\t%d\n",x,y,z);

      
      printf("Wyslano: %d\t%d\t%d\n",x,y,z);
      
      if (write(tryb, &x, sizeof(int))==-1)
	{
	  printf("Nastapil blad podczas przesylania danych\n");
	  return 3;
	}

      if (write(tryb, &y, sizeof(int))==-1)
	{
	  printf("Nastapil blad podczas przesylania danych\n");
	  return 3;
	}

      if (write(tryb, &z, sizeof(int))==-1)
	{
	  printf("Nastapil blad podczas przesylania danych\n");
	  return 3;
	}
      
      
      sleep(t);
    }

  /*printf("%lld\n",l_cyfr);*/

  
  if (write(tryb, &l_cyfr, sizeof(unsigned long long))==-1)
	{
	  printf("Nastapil blad podczas przesylania danych\n");
	  return 3;
	}
  printf("\nWyslano sygnal 'STOP'\n");
  
  
  close(tryb);

  return 0;
}
