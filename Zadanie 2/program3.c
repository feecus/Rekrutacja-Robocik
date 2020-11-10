//Autor: Gabriel Kocenko, listopad 2020 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

#define SZEROKOSC 8

int temp[SZEROKOSC][SZEROKOSC];
int bicia[SZEROKOSC][SZEROKOSC];

int numer(int liczba)
{
	switch(liczba)
	{
	case 1: return 8;
	break;
	case 2: return 7;
	break;
	case 3: return 6;
	break;
	case 4: return 5;
	break;
	case 5: return 4;
	break;
	case 6: return 3;
	break;
	case 7: return 2;
	break;
	default: return 1;
	break;
	}
}

char litera(int liczba)
{
	switch(liczba)
	{
	case 1: return 'a';
	break;
	case 2: return 'b';
	break;
	case 3: return 'c';
	break;
	case 4: return 'd';
	break;
	case 5: return 'e';
	break;
	case 6: return 'f';
	break;
	case 7: return 'g';
	break;
	default: return 'h';
	break;
	}
}

void wyswietl(int tab[SZEROKOSC][SZEROKOSC])
{
  for(int i=0;i<SZEROKOSC;i++)
    {
      for(int j=0;j<SZEROKOSC;j++)
		{
			printf("%d\t",tab[i][j]); //Wyświetlanie szachownicy z liczbami
		}
      printf("\n");
    }
    printf("\n");
}

void tab_temp(int tab[SZEROKOSC][SZEROKOSC])
{
	  for(int i=0;i<SZEROKOSC;i++)
	  {
	      for(int j=0;j<SZEROKOSC;j++)
	      {
	      	temp[i][j]=tab[i][j];
	      }
	  }
}

void wyczysc_tablice(int tab[SZEROKOSC][SZEROKOSC])
{
	for(int i=0;i<SZEROKOSC;i++)
	  {
	      for(int j=0;j<SZEROKOSC;j++)
	      {
	      	tab[i][j]=0;
	      }
	  }
}

int symliczk(char a)
{
  if(a=='-') return 0;
  else if(a=='w') return 10;
  else if(a=='b') return 20;
  return 0;
}

int symliczf(char a)
{
	if(a=='-') return 0;
  else if(a=='p') return 1;
  else if(a=='r') return 2;
  else if(a=='k') return 3;
  else if(a=='b') return 4;
  else if(a=='q') return 5;
  else if(a=='W') return 6;
	return 0;
}

int czyszach(int tab[SZEROKOSC][SZEROKOSC],int bicia[SZEROKOSC][SZEROKOSC],int kolor)
{
	for(int i=0;i<SZEROKOSC;i++)
	{
		for(int j=0;j<SZEROKOSC;j++)
		{
			if(tab[i][j]==(kolor*10)+6)
			{
				if(bicia[i][j]==1)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

void goniecbicia(int x,int y,int tab[SZEROKOSC][SZEROKOSC],int kolor) 
{
	int g;
	if(kolor==2) g=1;
	else g=2;
	
	int i1=x-1; //prawo do gory
	int j1=y+1;
	
	int i2=x+1; //prawo do dolu
	int j2=y+1;
	
	int i3=x+1; //lewo do dolu
	int j3=y-1;
	
	int i4=x-1; //lewo do gory
	int j4=y-1;
	
	while((i1>=0&&j1<SZEROKOSC)&&(tab[i1][j1]==0||(tab[i1][j1])/10==g||tab[i1][j1]==(g*10)+6
	||tab[i1][j1]/10==kolor)) // prawo do gory
 	{
 		if(((tab[i1][j1])/10==g&&tab[i1][j1]!=(g*10)+6)||tab[i1][j1]/10==kolor)
 		{
 			bicia[i1][j1]=1;
 			break;
 		}
 		else
 		{
 			bicia[i1][j1]=1;
 			i1--;
 			j1++;
 		}
 	}
 	
 	while((i2<SZEROKOSC&&j2<SZEROKOSC)&&(tab[i2][j2]==0||(tab[i2][j2])/10==g||tab[i2][j2]==(g*10)+6||tab[i2][j2]/10==kolor)) // prawo do dolu
 	{
 		if(((tab[i2][j2])/10==g&&tab[i2][j2]!=(g*10)+6)||tab[i2][j2]/10==kolor)
 		{
 			bicia[i2][j2]=1;
 			break;
 		}
 		else
 		{
 			bicia[i2][j2]=1;
 			i2++;
 			j2++;
 		}
 	}
 	
 	while((i3<SZEROKOSC&&j3>=0)&&(tab[i3][j3]==0||(tab[i3][j3])/10==g||tab[i3][j3]==(g*10)+6||tab[i3][j3]/10==kolor)) // lewo do dolu
 	{
 		if(((tab[i3][j3])/10==g&&tab[i3][j3]!=(g*10)+6)||tab[i3][j3]/10==kolor)
 		{
 			bicia[i3][j3]=1;
 			break;
 		}
 		else
 		{
 			bicia[i3][j3]=1;
 			i3++;
 			j3--;
 		}
 	}
 	
 	 	
 	while((i4>=0&&j4>=0)&&(tab[i4][j4]==0||(tab[i4][j4])/10==g||tab[i4][j4]==(g*10)+6||tab[i4][j4]/10==kolor)) // lewo do gory
 	{
 		if(((tab[i4][j4])/10==g&&tab[i4][j4]==(g*10)+6)||tab[i1][j1]/10==kolor)
 		{
 			bicia[i4][j4]=1;
 			break;
 		}
 		else
 		{
 			bicia[i4][j4]=1;
 			i4--;
 			j4--;
 		}
 	}
}

void wiezabicia(int x,int y,int tab[SZEROKOSC][SZEROKOSC],int kolor)
{
	int g;
	if(kolor==2) g=1;
	else g=2;
	
	int i1=x-1;
	int j1=y-1;
	
	int i2=x+1;
	int j2=y+1;
	
 	while((i1>=0)&&(tab[i1][y]==0||(tab[i1][y])/10==g||tab[i1][y]==(g*10)+6||tab[i1][y]/10==kolor)) // bicia w gore
 	{
 		if(((tab[i1][y])/10==g&&tab[i1][y]!=(g*10)+6)||tab[i1][y]/10==kolor)
 		{
 			bicia[i1][y]=1;
 			break;
 		}
 		else
 		{
 			bicia[i1][y]=1;
 			i1--;
 		}
 	}
 	
 	while((j1>=0)&&(tab[x][j1]==0||(tab[x][j1])/10==g||tab[x][j1]==(g*10)+6||tab[x][j1]/10==kolor)) // bicia w lewo
 	{
 		if(((tab[x][j1])/10==g&&tab[x][j1]!=(g*10)+6)||tab[x][j1]/10==kolor)
 		{
 			bicia[x][j1]=1;
 			break;
 		}
 		else
 		{
 			bicia[x][j1]=1;
 			j1--;
 		}
 	}
 	
 	 	while((i2<SZEROKOSC)&&(tab[i2][y]==0||(tab[i2][y])/10==g||tab[i2][y]==(g*10)+6||tab[i2][y]/10==kolor)) // bicia w dol
 	{
 		if(((tab[i2][y])/10==g&&tab[i2][y]!=(g*10)+6)||tab[i2][y]/10==kolor)
 		{
 			bicia[i2][y]=1;
 			break;
 		}
 		else
 		{
 			bicia[i2][y]=1;
 			i2++;
 		}
 	}
 	
 	 	while((j2<SZEROKOSC)&&(tab[x][j2]==0||(tab[x][j2])/10==g||tab[x][j2]==(g*10)+6||tab[x][j2]/10==kolor)) // bicia w prawo
 	{
 		if(((tab[x][j2])/10==g&&tab[x][j2]!=(g*10)+6)||tab[x][j2]/10==kolor)
 		{
 			bicia[x][j2]=1;
 			break;
 		}
 		else
 		{
 			bicia[x][j2]=1;
 			j2++;
 		}
 	}
}



void hetmanbicia(int x,int y,int tab[SZEROKOSC][SZEROKOSC],int kolor)
{
	int g;
	if(kolor==2) g=1;
	else g=2;
	
	int i1=x-1; //gora
	int j1=y-1; //lewo
	
	int i2=x+1; //dol
	int j2=y+1; //prawo
	
	int i3=x-1; //prawo do gory
	int j3=y+1;
	
	int i4=x+1; //prawo do dolu
	int j4=y+1;
	
	int i5=x+1; //lewo do dolu
	int j5=y-1;
	
	int i6=x-1; //lewo do gory
	int j6=y-1;
	
 	while((i1>=0)&&(tab[i1][y]==0||(tab[i1][y])/10==g||tab[i1][y]==(g*10)+6||tab[i1][j1]/10==kolor)) // bicia w gore
 	{
 		if(((tab[i1][y])/10==g&&tab[i1][y]!=(g*10)+6)||tab[i1][j1]/10==kolor)
 		{
 			bicia[i1][y]=1;
 			break;
 		}
 		else
 		{
 			bicia[i1][y]=1;
 			i1--;
 		}
 	}
 	
 	while((j1>=0)&&(tab[x][j1]==0||(tab[x][j1])/10==g||tab[x][j1]==(g*10)+6||tab[x][j1]/10==kolor)) // bicia w lewo
 	{
 		if(((tab[x][j1])/10==g&&tab[x][j1]!=(g*10)+6)||tab[x][j1]/10==kolor)
 		{
 			bicia[x][j1]=1;
 			break;
 		}
 		else
 		{
 			bicia[x][j1]=1;
 			j1--;
 		}
 	}
 	
 	 	while((i2<SZEROKOSC)&&(tab[i2][y]==0||(tab[i2][y])/10==g||tab[i2][y]==(g*10)+6||tab[i2][y]/10==kolor)) // bicia w dol
 	{
 		if(((tab[i2][y])/10==g&&tab[i2][y]!=(g*10)+6)||tab[i2][y]/10==kolor)
 		{
 			bicia[i2][y]=1;
 			break;
 		}
 		else
 		{
 			bicia[i2][y]=1;
 			i2++;
 		}
 	}
 	
 	 	while((j2<SZEROKOSC)&&(tab[x][j2]==0||(tab[x][j2])/10==g||tab[x][j2]==(g*10)+6||tab[x][j2]/10==kolor)) // bicia w lewo
 	{
 		if(((tab[x][j2])/10==g&&tab[x][j2]!=(g*10)+6)||tab[x][j2]/10==kolor)
 		{
 			bicia[x][j2]=1;
 			break;
 		}
 		else
 		{
 			bicia[x][j2]=1;
 			j2++;
 		}
 	}
 	
 	while((i3>=0&&j3<SZEROKOSC)&&(tab[i3][j3]==0||(tab[i3][j3])/10==g||tab[i3][j3]==(g*10)+6||tab[i3][j3]/10==kolor)) // prawo do gory
 	{
 		if(((tab[i3][j3])/10==g&&tab[i3][j3]!=(g*10)+6)||tab[i3][j3]/10==kolor)
 		{
 			bicia[i3][j3]=1;
 			break;
 		}
 		else
 		{
 			bicia[i3][j3]=1;
 			i3--;
 			j3++;
 		}
 	}
 	
 	while((i4<SZEROKOSC&&j4<SZEROKOSC)&&(tab[i4][j4]==0||(tab[i4][j4])/10==g||tab[i4][j4]==(g*10)+6||tab[i4][j4]/10==kolor)) // prawo do dolu
 	{
 		if(((tab[i4][j4])/10==g&&tab[i4][j4]!=(g*10)+6)||tab[i4][j4]/10==kolor)
 		{
 			bicia[i4][j4]=1;
 			break;
 		}
 		else
 		{
 			bicia[i4][j4]=1;
 			i4++;
 			j4++;
 		}
 	}
 	
 	while((i5<SZEROKOSC&&j5>=0)&&(tab[i5][j5]==0||(tab[i5][j5])/10==g||tab[i5][j5]==(g*10)+6||tab[i5][j5]/10==kolor)) // lewo do dolu
 	{
 		if(((tab[i5][j5])/10==g&&tab[i5][j5]!=(g*10)+6)||tab[i5][j5]/10==kolor)
 		{
 			bicia[i5][j5]=1;
 			break;
 		}
 		else
 		{
 			bicia[i5][j5]=1;
 			i5++;
 			j5--;
 		}
 	}
 	
 	while((i6>=0&&j6>=0)&&(tab[i6][j6]==0||(tab[i6][j6])/10==g||tab[i6][j6]==(g*10)+6||tab[i6][j6]/10==kolor)) // lewo do gory
 	{
 		if(((tab[i6][j6])/10==g&&tab[i6][j6]!=(g*10)+6)||tab[i6][j6]/10==kolor)
 		{
 			bicia[i6][j6]=1;
 			break;
 		}
 		else
 		{
 			bicia[i6][j6]=1;
 			i6--;
 			j6--;
 		}
 	}
}

void skoczekbicia(int x, int y,int tab[SZEROKOSC][SZEROKOSC],int kolor)
{
	int g;
	if(kolor==2) g=1;
	else g=2;
	
	int i1=x-2; //gora prawo
	int j1=y+1;
	
	int i2=x-1; //prawo gora
	int j2=y+2;
	
	int i3=x+1; //prawo dol
	int j3=y+2;
	
	int i4=x+2; //dol prawo
	int j4=y+1;
	
	int i5=x-2; //gora lewo
	int j5=y-1;
	
	int i6=x-1; //lewo gora
	int j6=y-2;
	
	int i7=x+1; //lewo dol
	int j7=y-2;
	
	int i8=x+2; //dol lewo
	int j8=y-1;
	
	if(i1>=0&&j1<SZEROKOSC&&(tab[i1][j1]==0||(tab[i1][j1])/10==g)) //gora prawo
	{
		bicia[i1][j1]=1;
	}
	
	if(i2>=0&&j2<SZEROKOSC&&(tab[i2][j2]==0||(tab[i2][j2])/10==g)) //prawo gora
	{
		bicia[i2][j2]=1;
	}
	
	if(i3<SZEROKOSC&&j3<SZEROKOSC&&(tab[i3][j3]==0||(tab[i3][j3])/10==g)) //prawo dol
	{
		bicia[i3][j3]=1;
	}
	
	if(i4<SZEROKOSC&&j4<SZEROKOSC&&(tab[i4][j4]==0||(tab[i4][j4])/10==g)) //dol prawo
	{
		bicia[i4][j4]=1;
	}
	
	if(i5>=0&&j5>=0&&(tab[i5][j5]==0||(tab[i5][j5])/10==g)) //gora lewo
	{
		bicia[i5][j5]=1;
	}
	
	if(i6>=0&&j6>=0&&(tab[i6][j6]==0||(tab[i6][j6])/10==g)) //lewo gora
	{
		bicia[i6][j6]=1;
	}
	
	if(i7<SZEROKOSC&&j7>=0&&(tab[i7][j7]==0||(tab[i7][j7])/10==g)) //lewo dol
	{
		bicia[i7][j7]=1;
	}
	
	if(i8<SZEROKOSC&&j8>=0&&(tab[i8][j8]==0||(tab[i8][j8])/10==g)) //dol lewo
	{
		bicia[i8][j8]=1;
	}
}

void krolbicia(int x, int y,int tab[SZEROKOSC][SZEROKOSC],int kolor)
{
	int g;
	if(kolor==2) g=1;
	else g=2;
	
	if(x-1>=0&&(tab[x-1][y]==0||(tab[x-1][y])/10==g)) //do gory
	{
		bicia[x-1][y]=1;
	}
	
	if(x-1>=0&&y+1<SZEROKOSC&&(tab[x-1][y+1]==0||(tab[x-1][y+1])/10==g)) //gora prawo
	{
		bicia[x-1][y+1]=1;
	}
	
	if(x-1>=0&&y-1>=0&&(tab[x-1][y-1]==0||(tab[x-1][y-1])/10==g)) //gora lewo
	{
		bicia[x-1][y-1]=1;
	}
	
	if(y-1>=0&&(tab[x][y-1]==0||(tab[x][y-1])/10==g)) //lewo
	{
		bicia[x][y-1]=1;
	}
	
	if(x+1<SZEROKOSC&&y-1>=0&&(tab[x+1][y-1]==0||(tab[x+1][y-1])/10==g)) //dol lewo
	{
		bicia[x+1][y-1]=1;
	}
	
	if(x+1<SZEROKOSC&&(tab[x+1][y]==0||(tab[x+1][y])/10==g)) //dol
	{
		bicia[x+1][y]=1;
	}
	
	if(x+1<SZEROKOSC&&y+1<SZEROKOSC&&(tab[x+1][y+1]==0||(tab[x+1][y+1])/10==g)) //dol prawo
	{
		bicia[x+1][y+1]=1;
	}
	
	if(y+1<SZEROKOSC&&(tab[x][y+1]==0||(tab[x][y+1])/10==g)) //prawo
	{
		bicia[x][y+1]=1;
	}
	
}

void pionbicia(int x, int y,int tab[SZEROKOSC][SZEROKOSC],int kolor)
{
	int z;
	if(kolor==2)
	{
		z=1;
	}
	else
	{
		z=-1;
	}
	
	int i1=x+z;
	
	if(y+1<SZEROKOSC&&(tab[i1][y+1]==0)) //bicie w prawo po ukosie
	{
		bicia[i1][y+1]=1;
	}
	
	if(y-1>=0&&(tab[i1][y-1]==0)) //bicie w lewo po ukosie
	{
		bicia[i1][y-1]=1;
	}
}
	
void generuj_tablice_bic(int tab[SZEROKOSC][SZEROKOSC],int kolor)
{
	int col;
	int figura;
	for(int i=0;i<SZEROKOSC;i++)
   {
      for(int j=0;j<SZEROKOSC;j++)
		{
		  figura=(tab[i][j])%10;
		  col=(tab[i][j])/10;
		  if(col==kolor)
		  {
			  switch(figura)
			  {
			  	case 1:
			  		  pionbicia(i,j,tab,kolor);
			  	break;
			  	case 2:
			  			wiezabicia(i,j,tab,kolor);
			  	break;
			  	case 3:
			  			skoczekbicia(i,j,tab,kolor);
			  	break;
			  	case 4:
			  		  goniecbicia(i,j,tab,kolor);
			  	break;
			  	case 5:
			  			hetmanbicia(i,j,tab,kolor);
			  	break;
			  	case 6:
			  		  krolbicia(i,j,tab,kolor);
			  	break;
			  	default: printf("\n");
			  	break;
			  }
			}
		}
   }
}

int czy_legalny(int newx, int newy, int tab[SZEROKOSC][SZEROKOSC], int bicia[SZEROKOSC][SZEROKOSC], int kolor)
{

	if (tab[newx][newy]%10==6)
	{
		return 0;
	}
	
	if (bicia[newx][newy]==1)
	{
		return 0;
	}
	if (newx>=SZEROKOSC||newx<0||newy<0||newy>=SZEROKOSC)
	{
		return 0;
	}
	if ((tab[newx][newy])/10==kolor)
	{
		return 0;
	}
	return 1;
}

int czymat(int tab[SZEROKOSC][SZEROKOSC],int bicia[SZEROKOSC][SZEROKOSC],int kolor)
{
	int atak;
	int prawda;
	
	atak=kolor;
	
	for(int i=0;i<SZEROKOSC;i++)
	{
		for(int j=0;j<SZEROKOSC;j++)
		{
			if(tab[i][j]==(atak*10)+6)
			{
				if(bicia[i][j]==1)
				{
					if(czy_legalny(i, j, tab, bicia, atak)==1||
					czy_legalny(i-1, j, tab, bicia, atak)==1||
					czy_legalny(i-1, j+1, tab, bicia, atak)==1||
					czy_legalny(i, j+1, tab, bicia, atak)==1||
					czy_legalny(i+1, j+1, tab, bicia, atak)==1||
					czy_legalny(i+1, j, tab, bicia, atak)==1||
					czy_legalny(i+1, j-1, tab, bicia, atak)==1||
					czy_legalny(i, j-1, tab, bicia, atak)==1||
					czy_legalny(i-1, j-1, tab, bicia, atak)==1)
					{
						prawda=0;
					}
					else
					{
						prawda=1;
					}
				}
			}
		}
	}
	return prawda;
}

void pion(int x,int y,int tab[SZEROKOSC][SZEROKOSC],int temp[SZEROKOSC][SZEROKOSC],int kolor)
{
	int z;
	if(kolor==2) z=1;
	else z=-1; 
	
	int g;
	if(kolor==2) g=1;
	else g=2;
  
  int a=x+z;
  if((a<=SZEROKOSC)&&tab[a][y]==0)
  {
    temp[a][y]=11;
    temp[x][y]=0;
  }
  
  generuj_tablice_bic(temp,kolor);
  
  if(czy_legalny(a,y,temp,bicia,kolor)==1)
  {
  		if(czymat(temp,bicia,g)==1)
  		{
  			if(kolor==1)
  			{
  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(a+1));
  			}
  			else
  			{
  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(a+1),litera(y+1),numer(a+1));
  			}
  		}
  }
  wyczysc_tablice(bicia);
}

void goniec(int x,int y,int tab[SZEROKOSC][SZEROKOSC],int temp[SZEROKOSC][SZEROKOSC],int kolor)
{	
	int g;
	if(kolor==2) g=1;
	else g=2;
	
	int i1=x-1; //prawo do gory
	int j1=y+1;
	
	int i2=x+1; //prawo do dolu
	int j2=y+1;
	
	int i3=x+1; //lewo do dolu
	int j3=y-1;
	
	int i4=x-1; //lewo do gory
	int j4=y-1;
	
	tab_temp(tab);
	wyczysc_tablice(bicia);
	
	while((i1>=0&&j1<SZEROKOSC)&&(tab[i1][j1]==0||(tab[i1][j1])/10==g||tab[i1][j1]==(g*10)+6||tab[i1][j1]/10==kolor)) // prawo do gory
 	{
 		    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 

 		if(czy_legalny(i1,j1,temp,bicia,kolor)==1&&(tab[i1][j1]/10)==g)
 		{
 			    
 		
 			temp[i1][j1]=kolor*10+4;
 			temp[i1+1][j1-1]=0;

 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 		
			     
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(i1+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(i1+1));
	  			}
			}
 			
 			break;
 		}
 		
 		else
 		{
 			
 			temp[i1][j1]=kolor*10+4;
 			temp[i1+1][j1-1]=0;
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 		     
			
			if(czymat(temp,bicia,g)==1)
			{
				printf("Z pola %dx%d na pole %dx%d\n",x+1,y+1,i1+1,j1+1);
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(i1+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(i1+1));
	  			}
			}
 		}
 		i1--;
 		j1++;
 	}
 	
 	tab_temp(tab);
 	wyczysc_tablice(bicia);
 	
 	while((i2<SZEROKOSC&&j2<SZEROKOSC)&&(tab[i2][j2]==0||(tab[i2][j2])/10==g||tab[i2][j2]==(g*10)+6||tab[i2][j2]/10==kolor)) // prawo do dolu
 	{
 		    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 

 		if(czy_legalny(i2,j2,temp,bicia,kolor)==1&&(tab[i2][j2]/10)==g)
 		{
 			    
 		
 			temp[i2][j2]=kolor*10+4;
 			temp[i2-1][j2-1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
	
			     
			if(czymat(temp,bicia,g)==1)
			{

				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(i2+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(i2+1));
	  			}
			}
 			
 			break;
 		}
 		
 		else
 		{
 			

 			temp[i2][j2]=kolor*10+4;
 			temp[i2-1][j2-1]=0;
   
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);

			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(i2+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(i2+1));
	  			}
			}
 		}
 			i2++;
 			j2++;
 	}
 	
 	tab_temp(tab);
 	wyczysc_tablice(bicia);
 	
 	while((i3<SZEROKOSC&&j3>=0)&&(tab[i3][j3]==0||(tab[i3][j3])/10==g||tab[i3][j3]==(g*10)+6||tab[i3][j3]/10==kolor)) // lewo do dolu
 	{
 		    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 

 		if(czy_legalny(i3,j3,temp,bicia,kolor)==1&&(tab[i3][j3]/10)==g)
 		{
 			    
 		
 			temp[i3][j3]=kolor*10+4;
 			temp[i3-1][j3+1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
 			 
			  		
			     
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j3+1),numer(i3+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j3+1),numer(i3+1));
	  			}
			}
 			
 			break;
 		}
 		
 		else
 		{
 			

 			temp[i3][j3]=kolor*10+4;
 			temp[i3-1][j3+1]=0;
		     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
	     
			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j3+1),numer(i3+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j3+1),numer(i3+1));
	  			}
			}
 		}
 			i3++;
 			j3--;
 	}
 	
 	tab_temp(tab);
 	wyczysc_tablice(bicia);
 	 	
 	while((i4>=0&&j4>=0)&&(tab[i4][j4]==0||(tab[i4][j4])/10==g||tab[i4][j4]==(g*10)+6||tab[i4][j4]/10==kolor)) // lewo do gory
 	{
 			    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 
 		if(czy_legalny(i4,j4,temp,bicia,kolor)==1&&(tab[i4][j4]/10)==g)
 		{
 			    
 		
 			temp[i4][j4]=kolor*10+4;
 			temp[i4+1][j4+1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
 			 
			  		
			     
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j4+1),numer(i4+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j4+1),numer(i4+1));
	  			}
			}
 			
 			break;
 		}
 		
 		else
 		{
 			
 
 			temp[i4][j4]=kolor*10+4;
 			temp[i4+1][j4+1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 				     
			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j4+1),numer(i4+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j4+1),numer(i4+1));
	  			}
			}
 		}
 		i4--;
 		j4--;
 	}
}

void wieza(int x,int y,int tab[SZEROKOSC][SZEROKOSC],int temp[SZEROKOSC][SZEROKOSC],int kolor)
{

	
	tab_temp(tab);
	
	     
	
	int g;
	if(kolor==2)
	{
		g=1;
	}
	else 
	{
		g=2;
	}
	
	int i1=x-1;
	int j1=y-1;
	
	int i2=x+1;
	int j2=y+1;
	
	
	tab_temp(tab);
	wyczysc_tablice(bicia);
	
 	while((i1>=0)&&(tab[i1][y]==0||(tab[i1][y])/10==g)) // bicia w gore
 	{
 		    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 
 		
 		if(czy_legalny(i1,y,temp,bicia,kolor)==1&&(tab[i1][y]/10)==g)
 		{
 			    
 		
 			temp[i1][y]=kolor*10+2;
 			temp[i1+1][y]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			 		
			     
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i1+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i1+1));
	  			}
			}
 			
 			break;
 		}
 		
 		else
 		{  
 			
 			temp[i1][y]=kolor*10+2;
 			temp[i1+1][y]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			     
			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i1+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i1+1));
	  			}
			}
 		}
 		i1--;
 	}
 	
 	
 	tab_temp(tab);
 	wyczysc_tablice(bicia);
 	
 	while((j1>=0)&&(tab[x][j1]==0||(tab[x][j1])/10==g)) // bicia w lewo
 	{
 		    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 

 		if(czy_legalny(x,j1,temp,bicia,kolor)==1&&(tab[x][j1])/10==g)
 		{
 			    
 			
 			temp[x][j1]=kolor*10+2;
 			temp[x][j1+1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);

 			     
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(x+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(x+1));
	  			}
			}
 			
 			break;
 		}
 		
 		else
 		{
 			    
 			temp[x][j1]=kolor*10+2;
 			temp[x][j1+1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			   
			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(x+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(x+1));
	  			}
			}
 		}
 		j1--;
 	}
 	
 	tab_temp(tab);
 	wyczysc_tablice(bicia);

 	while((i2<SZEROKOSC)&&(tab[i2][y]==0||(tab[i2][y])/10==g)) // bicia w dol
 	{
 	
 		    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 
 		if(czy_legalny(i2,y,temp,bicia,kolor)==1&&(tab[i2][y])/10==g)
 		{
 			    
 		
 			temp[i2][y]=kolor*10+2;
 			temp[i2-1][y]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			

			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i2+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i2+1));
	  			}
			}
 			
 			break;
 		}
 		else
 		{

	 		temp[i2][y]=kolor*10+2;
	 		temp[i2-1][y]=0;
	 			
		
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);

			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i2+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i2+1));
	  			}
			}
	 	}
	 	i2++;
 	}
 	
 	tab_temp(tab);
 	wyczysc_tablice(bicia);
 	 	
 	
 	while((j2<SZEROKOSC)&&(tab[x][j2]==0||(tab[x][j2])/10==g)) // bicia w prawo
 	{
 		    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 
 		
 		if(czy_legalny(x,j2,temp,bicia,kolor)==1&&(tab[x][j2])/10==g)
 		{
 			    
 		
 			temp[x][j2]=kolor*10+2;
 			temp[x][j2-1]=0;

 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);

			     
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(x+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(x+1));
	  			}
			}
 			
 			break;
 		}
 		else
 		{
 			    
 			
 			temp[x][j2]=kolor*10+2;
 			temp[x][j2-1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
		     
			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(x+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(x+1));
	  			}
			}
 		}
 		j2++;
 	}
}

void hetman(int x,int y,int tab[SZEROKOSC][SZEROKOSC],int temp[SZEROKOSC][SZEROKOSC],int kolor)
{
	
	tab_temp(tab);
	
	     
	
	int g;
	if(kolor==2)
	{
		g=1;
	}
	else 
	{
		g=2;
	}
	
	int i1=x-1;
	int j1=y-1;
	
	int i2=x+1;
	int j2=y+1;
	
	int i3=x-1; //prawo do gory
	int j3=y+1;
	
	int i4=x+1; //prawo do dolu
	int j4=y+1;
	
	int i5=x+1; //lewo do dolu
	int j5=y-1;
	
	int i6=x-1; //lewo do gory
	int j6=y-1;

	
	tab_temp(tab);
	wyczysc_tablice(bicia);
	
 	while((i1>=0)&&(tab[i1][y]==0||(tab[i1][y])/10==g)) // bicia w gore
 	{
 		    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 
 		
 		if(czy_legalny(i1,y,temp,bicia,kolor)==1&&(tab[i1][y]/10)==g)
 		{
 			    
 		
 			temp[i1][y]=kolor*10+5;
 			temp[i1+1][y]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);

			     
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i2+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i2+1));
	  			}
			}
 			
 			break;
 		}
 		
 		else
 		{
			    
 			
 			temp[i1][y]=kolor*10+5;
 			temp[i1+1][y]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			

			if(czymat(temp,bicia,g)==1)
			{
					if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i2+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i2+1));
	  			}
			}
 		}
 		i1--;
 	}
 	
 	
 	
 	tab_temp(tab);
 	wyczysc_tablice(bicia);
 	
 	while((j1>=0)&&(tab[x][j1]==0||(tab[x][j1])/10==g)) // bicia w lewo
 	{
 		    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 
 		

 		if(czy_legalny(x,j1,temp,bicia,kolor)==1&&(tab[x][j1])/10==g)
 		{
 			    
 			
 			temp[x][j1]=kolor*10+5;
 			temp[x][j1+1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
 			 
 			
 			     
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(x+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(x+1));
	  			}
			}
 			
 			break;
 		}
 		
 		else
 		{
 			    
 			
 			temp[x][j1]=kolor*10+5;
 			temp[x][j1+1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			

			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(x+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(x+1));
	  			}
			}
 		}
 		j1--;
 	}
 	
 	
 	tab_temp(tab);
 	wyczysc_tablice(bicia);
 		
 	while((i2<SZEROKOSC)&&(tab[i2][y]==0||(tab[i2][y])/10==g)) // bicia w dol
 	{
 	
 		    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 

 		if(czy_legalny(i2,y,temp,bicia,kolor)==1&&(tab[i2][y])/10==g)
 		{
 			    
 		
 			temp[i2][y]=kolor*10+5;
 			temp[i2-1][y]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
 			 
 			
 			     
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i2+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i2+1));
	  			}
			}
 			
 			break;
 		}
 		else
 		{
 			    
 			
	 		temp[i2][y]=kolor*10+5;
	 		temp[i2-1][y]=0;
	 			
	 		     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i2+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(y+1),numer(i2+1));
	  			}
			}
	 	}
	 	i2++;
 	}

 	
 	tab_temp(tab);
 	wyczysc_tablice(bicia);
 	 	
 	 	while((j2<SZEROKOSC)&&(tab[x][j2]==0||(tab[x][j2])/10==g)) // bicia w prawo
 	{
 		    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 

 		if(czy_legalny(x,j2,temp,bicia,kolor)==1&&(tab[x][j2])/10==g)
 		{
 			    
 		
 			temp[x][j2]=kolor*10+5;
 			temp[x][j2-1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
 			 
			  		
			     
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(x+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(x+1));
	  			}
			}
 			
 			break;
 		}
 		else
 		{
 			    
 			
 			temp[x][j2]=kolor*10+5;
 			temp[x][j2-1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
 			 
			  		
			     
			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(x+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(x+1));
	  			}
			}
 		}
 		
 		j2++;
 	}
	
	tab_temp(tab);
	wyczysc_tablice(bicia);
	
	while((i3>=0&&j3<SZEROKOSC)&&(tab[i3][j3]==0||(tab[i3][j3])/10==g||tab[i3][j3]==(g*10)+6||tab[i3][j3]/10==kolor)) // prawo do gory
 	{
 		    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 
 		
 		if(czy_legalny(i3,j3,temp,bicia,kolor)==1&&(tab[i3][j3]/10)==g)
 		{
 			    
 		
 			temp[i3][j3]=kolor*10+5;
 			temp[i3+1][j3-1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
 			 
			  		
			     
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j3+1),numer(i3+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j3+1),numer(i3+1));
	  			}
			}
 			
 			break;
 		}
 		
 		else
 		{
 			
 			temp[i3][j3]=kolor*10+5;
 			temp[i3+1][j3-1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);

			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j3+1),numer(i3+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j3+1),numer(i3+1));
	  			}
			}
 		}
 		i3--;
 		j3++;
 	}
 	
 	tab_temp(tab);
 	wyczysc_tablice(bicia);
 	
 	while((i4<SZEROKOSC&&j4<SZEROKOSC)&&(tab[i4][j4]==0||(tab[i4][j4])/10==g||tab[i4][j4]==(g*10)+6||tab[i4][j4]/10==kolor)) // prawo do dolu
 	{
 		    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 
 		
 		if(czy_legalny(i4,j4,temp,bicia,kolor)==1&&(tab[i4][j4]/10)==g)
 		{
 			    
 		
 			temp[i4][j4]=kolor*10+5;
 			temp[i4-1][j4-1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
 			 
			  		
			     
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j4+1),numer(i4+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j4+1),numer(i4+1));
	  			}
			}
 			
 			break;
 		}
 		
 		else
 		{
 			
 			    
 			
 			temp[i4][j4]=kolor*10+5;
 			temp[i4-1][j4-1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
 			 
			  		
			     
			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j4+1),numer(i4+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j4+1),numer(i4+1));
	  			}
			}
 		}
 			i4++;
 			j4++;
 	}
 	
 	tab_temp(tab);
 	wyczysc_tablice(bicia);
 	
 	while((i5<SZEROKOSC&&j5>=0)&&(tab[i5][j5]==0||(tab[i5][j5])/10==g||tab[i5][j5]==(g*10)+6||tab[i5][j5]/10==kolor)) // lewo do dolu
 	{
 		    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 

 		if(czy_legalny(i5,j5,temp,bicia,kolor)==1&&(tab[i5][j5]/10)==g)
 		{
 			  
 			temp[i5][j5]=kolor*10+5;
 			temp[i5-1][j5+1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
 			 
			  		
			     
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j5+1),numer(i5+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j5+1),numer(i5+1));
	  			}
			}
 			
 			break;
 		}
 		
 		else
 		{

 			
 			temp[i5][j5]=kolor*10+5;
 			temp[i5-1][j5+1]=0;
 			
 			     
 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
			     
			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j5+1),numer(i5+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j5+1),numer(i5+1));
	  			}
			}
 		}
 			i5++;
 			j5--;
 	}
 	
 	tab_temp(tab);
 	wyczysc_tablice(bicia);
 	 	
 	while((i6>=0&&j6>=0)&&(tab[i6][j6]==0||(tab[i6][j6])/10==g||tab[i6][j6]==(g*10)+6||tab[i6][j6]/10==kolor)) // lewo do gory
 	{
 			    
 		
 		wyczysc_tablice(bicia);
 		generuj_tablice_bic(temp,g);
 		 
 		
 		if(czy_legalny(i6,j6,temp,bicia,kolor)==1&&(tab[i6][j6]/10)==g)
 		{
 				
 			temp[i6][j6]=kolor*10+5;
 			temp[i6+1][j6+1]=0;
 			
 			 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
 			 
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j6+1),numer(i6+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j6+1),numer(i6+1));
	  			}
			}
 			
 			break;
 		}
 		
 		else
 		{
 			
 			 			
 			temp[i6][j6]=kolor*10+5;
 			temp[i6+1][j6+1]=0;
 			
 						
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
 								
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j6+1),numer(i6+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j6+1),numer(i6+1));
	  			}
			}
 		}
 		i6--;
 		j6--;
 	}
}

void skoczek(int x, int y,int tab[SZEROKOSC][SZEROKOSC],int temp[SZEROKOSC][SZEROKOSC],int kolor)
{
	int g;
	if(kolor==2) g=1;
	else g=2;
	
	int i1=x-2; //gora prawo
	int j1=y+1;
	
	int i2=x-1; //prawo gora
	int j2=y+2;
	
	int i3=x+1; //prawo dol
	int j3=y+2;
	
	int i4=x+2; //dol prawo
	int j4=y+1;
	
	int i5=x-2; //gora lewo
	int j5=y-1;
	
	int i6=x-1; //lewo gora
	int j6=y-2;
	
	int i7=x+1; //lewo dol
	int j7=y-2;
	
	int i8=x+2; //dol lewo
	int j8=y-1;
	
	
	wyczysc_tablice(bicia);
	wyczysc_tablice(temp);
		
	tab_temp(tab);
 	generuj_tablice_bic(temp,g);
	 	
 	if(i1>=0&&j1<SZEROKOSC&&(tab[i1][j1]==0||(tab[i1][j1])/10==g)) //gora prawo
	{
		if(czy_legalny(i1,j1,temp,bicia,kolor)==1&&(tab[i1][j1]/10)==g)
 		{
 		
 			temp[i1][j1]=kolor*10+3;
 			temp[i1+1][j1+1]=0;
 	 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(i1+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(i1+1));
	  			}
			}
 			
 		}
 		
 		else
 		{
 			temp[i1][j1]=kolor*10+5;
 			temp[i1+1][j1+1]=0;

 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
			  	
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(i1+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j1+1),numer(i1+1));
	  			}
			}
 		}
	}

	
	
	wyczysc_tablice(bicia);
	wyczysc_tablice(temp);
		
	tab_temp(tab);
 	generuj_tablice_bic(temp,g);
	 	
 	if(i2>=0&&j2<SZEROKOSC&&(tab[i2][j2]==0||(tab[i2][j2])/10==g)) //gora prawo
	{
		if(czy_legalny(i2,j2,temp,bicia,kolor)==1&&(tab[i2][j2]/10)==g)
 		{
 		
 			temp[i2][j2]=kolor*10+3;
 			temp[i2+1][j2+1]=0;
 	 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(i2+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(i2+1));
	  			}
			}
 			
 		}
 		
 		else
 		{
 			temp[i2][j2]=kolor*10+5;
 			temp[i2+1][j2+1]=0;

 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
			  	
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(i2+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j2+1),numer(i2+1));
	  			}
			}
 		}
	}

	
	
	wyczysc_tablice(bicia);
	wyczysc_tablice(temp);
		
	tab_temp(tab);
 	generuj_tablice_bic(temp,g);
	 	
 	if(i3>=0&&j3<SZEROKOSC&&(tab[i3][j3]==0||(tab[i3][j3])/10==g)) //gora prawo
	{
		if(czy_legalny(i3,j3,temp,bicia,kolor)==1&&(tab[i3][j3]/10)==g)
 		{
 		
 			temp[i3][j3]=kolor*10+3;
 			temp[i3+1][j3+1]=0;
 	 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j3+1),numer(i3+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j3+1),numer(i3+1));
	  			}
			}
 			
 		}
 		
 		else
 		{
 			temp[i3][j3]=kolor*10+5;
 			temp[i3+1][j3+1]=0;

 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
			  	
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j3+1),numer(i3+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j3+1),numer(i3+1));
	  			}
			}
 		}
	}

	
	
	wyczysc_tablice(bicia);
	wyczysc_tablice(temp);
		
	tab_temp(tab);
 	generuj_tablice_bic(temp,g);
	 	
 	if(i4>=0&&j4<SZEROKOSC&&(tab[i4][j4]==0||(tab[i4][j4])/10==g)) //gora prawo
	{
		if(czy_legalny(i4,j4,temp,bicia,kolor)==1&&(tab[i4][j4]/10)==g)
 		{
 		
 			temp[i4][j4]=kolor*10+3;
 			temp[i4+1][j4+1]=0;
 	 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j4+1),numer(i4+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j4+1),numer(i4+1));
	  			}
			}
 			
 		}
 		
 		else
 		{
 			temp[i4][j4]=kolor*10+5;
 			temp[i4+1][j4+1]=0;

 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
			  	
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j4+1),numer(i4+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j4+1),numer(i4+1));
	  			}
			}
 		}
	}

	
	
	wyczysc_tablice(bicia);
	wyczysc_tablice(temp);
		
	tab_temp(tab);
 	generuj_tablice_bic(temp,g);
	 	
 	if(i5>=0&&j5<SZEROKOSC&&(tab[i5][j5]==0||(tab[i5][j5])/10==g)) //gora prawo
	{
		if(czy_legalny(i5,j5,temp,bicia,kolor)==1&&(tab[i5][j5]/10)==g)
 		{
 		
 			temp[i5][j5]=kolor*10+3;
 			temp[i5+1][j5+1]=0;
 	 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j5+1),numer(i5+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j5+1),numer(i5+1));
	  			}
			}
 			
 		}
 		
 		else
 		{
 			temp[i5][j5]=kolor*10+5;
 			temp[i5+1][j5+1]=0;

 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
			  	
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j5+1),numer(i5+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j5+1),numer(i5+1));
	  			}
			}
 		}
	}

	
	
	wyczysc_tablice(bicia);
	wyczysc_tablice(temp);
		
	tab_temp(tab);
 	generuj_tablice_bic(temp,g);
	 	
 	if(i6>=0&&j6<SZEROKOSC&&(tab[i6][j6]==0||(tab[i6][j6])/10==g)) //gora prawo
	{
		if(czy_legalny(i6,j6,temp,bicia,kolor)==1&&(tab[i6][j6]/10)==g)
 		{
 		
 			temp[i6][j6]=kolor*10+3;
 			temp[i6+1][j6+1]=0;
 	 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j6+1),numer(i6+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j6+1),numer(i6+1));
	  			}
			}
 			
 		}
 		
 		else
 		{
 			temp[i6][j6]=kolor*10+5;
 			temp[i6+1][j6+1]=0;

 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
			  	
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j6+1),numer(i6+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j6+1),numer(i6+1));
	  			}
			}
 		}
	}

	
	
	wyczysc_tablice(bicia);
	wyczysc_tablice(temp);
		
	tab_temp(tab);
 	generuj_tablice_bic(temp,g);
	 	
 	if(i7>=0&&j7<SZEROKOSC&&(tab[i7][j7]==0||(tab[i7][j7])/10==g)) //gora prawo
	{
		if(czy_legalny(i7,j7,temp,bicia,kolor)==1&&(tab[i7][j7]/10)==g)
 		{
 		
 			temp[i7][j7]=kolor*10+3;
 			temp[i7+1][j7+1]=0;
 	 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j7+1),numer(i7+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j7+1),numer(i7+1));
	  			}
			}
 			
 		}
 		
 		else
 		{
 			temp[i7][j7]=kolor*10+5;
 			temp[i7+1][j7+1]=0;

 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
			  	
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j7+1),numer(i7+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j7+1),numer(i7+1));
	  			}
			}
 		}
	}

	
	
	wyczysc_tablice(bicia);
	wyczysc_tablice(temp);
		
	tab_temp(tab);
 	generuj_tablice_bic(temp,g);
	 	
 	if(i8>=0&&j8<SZEROKOSC&&(tab[i8][j8]==0||(tab[i8][j8])/10==g)) //gora prawo
	{
		if(czy_legalny(i8,j8,temp,bicia,kolor)==1&&(tab[i8][j8]/10)==g)
 		{
 		
 			temp[i8][j8]=kolor*10+3;
 			temp[i8+1][j8+1]=0;
 	 			
 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
 			
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j8+1),numer(i8+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j8+1),numer(i8+1));
	  			}
			}
 			
 		}
 		
 		else
 		{
 			temp[i8][j8]=kolor*10+5;
 			temp[i8+1][j8+1]=0;

 			wyczysc_tablice(bicia);
 			generuj_tablice_bic(temp,kolor);
			  	
			if(czymat(temp,bicia,g)==1)
			{
				if(kolor==1)
	  			{
	  				printf("Bialy moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j8+1),numer(i8+1));
	  			}
	  			else
	  			{
	  				printf("Czarny moze wygrac (%c%d - %c%d)\n",litera(y+1),numer(x+1),litera(j8+1),numer(i8+1));
	  			}
			}
 		}
	}

}


int main()
{
  int tab[SZEROKOSC][SZEROKOSC];
  int licznik;
  char szachownica[SZEROKOSC][50];
  int kolor;
  
  int figura;
  
  printf("Wprowadz dane szachownicy:\n\n");
  
  for(int i=0;i<SZEROKOSC;i++)
    {
      fgets(szachownica[i], sizeof szachownica[i] , stdin);
    }

  wyczysc_tablice(tab);
  
  for(int i=0;i<SZEROKOSC;i++)
    {
      licznik=0;
      for(int j=0;j<(sizeof szachownica[i]);j++)
		{
		  if(szachownica[i][j]=='\'')
			 {
			   tab[i][licznik]=symliczk(szachownica[i][j+1])+symliczf(szachownica[i][j+2]);
			   j=j+4;
			   licznik=licznik+1;
			 }
		}
    }
  
  printf("\n");
  
  kolor=1;
  
  for(int i=0;i<SZEROKOSC;i++)
   {
      for(int j=0;j<SZEROKOSC;j++)
		{
		  figura=(tab[i][j])%10;
		  {
			  switch(figura)
			  {
			  	case 1:
			  		  pion(i,j,tab,temp,kolor);
			  	break;
			  	
			  	case 2:
			  			wieza(i,j,tab,temp,kolor);
			  	break;
			  	case 3:
			  			skoczek(i,j,tab,temp,kolor);
			  	break;
			  	case 4:
			  		  goniec(i,j,tab,temp,kolor);
			  	break;
			  	case 5:
			  			hetman(i,j,tab,temp,kolor);
			  	break;
			  	default: printf("\a");
			  	break;
			  }
			}
		}
   }
   
   kolor=2;
   
   for(int i=0;i<SZEROKOSC;i++)
   {
      for(int j=0;j<SZEROKOSC;j++)
		{
		  figura=(tab[i][j])%10;
		  {
			  switch(figura)
			  {
			  	case 1:
			  		  pion(i,j,tab,temp,kolor);
			  	break;
			  	
			  	case 2:
			  			wieza(i,j,tab,temp,kolor);
			  	break;
			  	case 3:
			  			skoczek(i,j,tab,temp,kolor);
			  	break;
			  	case 4:
			  		  goniec(i,j,tab,temp,kolor);
			  	break;
			  	case 5:
			  			hetman(i,j,tab,temp,kolor);
			  	break;
			  	default: printf("\a");
			  	break;
			  }
			}
		}
   }
   	   
  return 0;
}
