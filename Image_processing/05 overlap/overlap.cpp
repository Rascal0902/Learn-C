#include <stdio.h>
#define WIDTH 1024
#define HEIGHT 768
#define HEADER 54

unsigned char R1[HEIGHT][WIDTH],G1[HEIGHT][WIDTH],B1[HEIGHT][WIDTH];
unsigned char R2[HEIGHT][WIDTH],G2[HEIGHT][WIDTH],B2[HEIGHT][WIDTH];
unsigned char R3[HEIGHT][WIDTH],G3[HEIGHT][WIDTH],B3[HEIGHT][WIDTH];

int main( )
{
  FILE *fp1 = fopen("red.bmp","rb");
  FILE *fp2 = fopen("green.bmp","rb");
  FILE *fp3 = fopen("overlap.bmp","wb");
    
  int i, j;
  for(i=0; i<HEADER; i++)   //1024*768 24bit ��������� �����سֱ�
  {
    putc(getc(fp1), fp3);
    getc(fp2); //fp2 ���� �б�, �о�� ���� ������ ��ġ�� �Ű���
  }
    
  for(i=0; i<HEIGHT; i++)   //�� ������ �޸𸮷� �б�
    for(j=0; j<WIDTH; j++)
    {
      B1[i][j]=getc(fp1);
      G1[i][j]=getc(fp1);
      R1[i][j]=getc(fp1);
            
      B2[i][j]=getc(fp2);
      G2[i][j]=getc(fp2);
      R2[i][j]=getc(fp2);
    }
    
  //���� �뿡�� �о�� �� ������ �迭 ������ �۾�?!!
  for(i=0; i<HEIGHT; i++)
    for(j=0; j<WIDTH; j++)
    {
      B3[i][j]=(B1[i][j]+B2[i][j])/2;
      G3[i][j]=(G1[i][j]+G2[i][j])/2;
      R3[i][j]=(R1[i][j]+R2[i][j])/2;
    }
    
  for(i=0; i<HEIGHT; i++)   //�� ������ ���Ϸ� ����
    for(j=0; j<WIDTH; j++)
    {
      putc(B3[i][j],fp3);
      putc(G3[i][j],fp3);
      putc(R3[i][j],fp3);
    }
  return 0;
}
