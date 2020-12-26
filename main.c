#include <stdio.h>
#include <stdlib.h>
#define KOSE 7
void tahta_yazdir(char tahta[KOSE][KOSE]);
void tahta_olustur(char tahta[KOSE][KOSE]);
int harita_kontrol(char tahta[KOSE][KOSE],int x, int y, int yon);
void hareket(char tahta[KOSE][KOSE]);
int icerde_mi(int x, int y);
void giris();



int main()
{
    system("color 7c");
    char tahta[KOSE][KOSE];
    giris();
    tahta_olustur(tahta);
    tahta_yazdir(tahta);
    hareket(tahta);
 return 0;
}
void giris()
{

    int a;
    printf("%20sSOLOTEST\n"," ");
    printf("\nKurallar:\n1-Ayni anda 2 tas atlayamazsiniz.\n");
    printf("\n2-Sadece rakam kullanmalisiniz\n");
    printf("\n\nIYI EGLENCELER");
    printf("\n\n****************OYUNA BASLAMAK ICIN 1'E BASINIZ****************\n%20s"," ");
    scanf("%d",&a);
    system("cls");
}
void tahta_olustur(char tahta[KOSE][KOSE])
{

    int i,j;
    for(i=0;i<KOSE;i++)
  {
      for (j=0;j<KOSE;j++)
      {
          tahta[i][j]='l';
      }
  }
  tahta[3][3]='O';
  for(i=0;i<2;i++)
  {
      for(j=0;j<2;j++)
      {
          tahta[i][j]=' ';
      }
  }
    for(i=5;i<7;i++)
  {
      for(j=5;j<7;j++)
      {
          tahta[i][j]=' ';
      }
  }
    for(i=0;i<2;i++)
  {
      for(j=5;j<7;j++)
      {
          tahta[i][j]=' ';
      }
  }
    for(i=5;i<7;i++)
  {
      for(j=0;j<2;j++)
      {
          tahta[i][j]=' ';
      }
  }
}
void tahta_yazdir(char tahta[KOSE][KOSE])
{

    int i,j;
    printf("  ");
    for(i=0;i<KOSE;i++)
     {
      printf("%2d",i);
    }
   printf("\n");
    for(i=0;i<KOSE;i++)
    {
        printf("%d|",i);

        for(j=0;j<KOSE;j++)
        {
            printf("%2c",tahta[i][j]);
        }
        printf("\n");
    }
}
void hareket(char tahta[KOSE][KOSE])
{
  int x,y,icerde,harita;
  int yon;
  int temp;
  while(1)
  {
      a:
      printf("x ve y koordinatlarini giriniz(cikmak icin -1 -1 giriniz):\n");
      scanf("%d%d",&x,&y);
      if (x==-1&&y==-1)
        break;
      printf("Yonu giriniz(4-sol,6-sag,8-yukari,2-asagi):\n");
      scanf("%d",&yon);
      temp=y;
      y=x;
      x=temp;

      icerde=icerde_mi(x,y);
      harita=harita_kontrol(tahta,x,y,yon);
      if(icerde==0)
      {
          printf("Sinirlar icinde degil.\n");
          goto a;
      }
      if(harita==0)
      {
          printf("Atlamaya calistiginiz deger bos degil veya sinirlardan tasiyorsunuz.\n");
          goto a;
      }
      if (yon==2)
      {
          tahta[x][y]='O';
          tahta[x+1][y]='O';
          tahta[x+2][y]='l';
      }
      if (yon==8)
      {
          tahta[x][y]='O';
          tahta[x-1][y]='O';
          tahta[x-2][y]='l';
      }
      if (yon==6)
      {
          tahta[x][y]='O';
          tahta[x][y+1]='O';
          tahta[x][y+2]='l';
      }
      if (yon==4)
      {
          tahta[x][y]='O';
          tahta[x][y-1]='O';
          tahta[x][y-2]='l';
      }
      tahta_yazdir(tahta);
  }
}
int icerde_mi(int x, int y)
{

    if(x<7 && y<7 && 0<x  && 0<y)
     {
         if((x<2 && y<2)||(x>5 && y<2)||(x<2 && y>5)||(x>5 && y>5))
         {

             return 0;
         }

           return 1;
     }
     return 0;
}
int harita_kontrol(char tahta[KOSE][KOSE],int x, int y, int yon)
{

    if(yon==6)
    {
      if (tahta[x][y+2]!='O')
      {
           return 0;
      }
    }

   if(yon==4)
   {
       if (tahta[x][y-2]!='O')
     {
         return 0;
     }
   }


    if(yon==8)
    {
        if (tahta[x-2][y]!='O')
            {
           return 0;
      }
    }

    if(yon==2)
    {
        if (tahta[x+2][y]!='O')
            {
           return 0;
      }
    }
return 1;
}








