#include <stdio.h>
#define WIDTH 1024
#define HEIGHT 768
#define HEADER 54

unsigned char R[HEIGHT][WIDTH],G[HEIGHT][WIDTH],B[HEIGHT][WIDTH];
int main( )
{
  FILE *fp1 = fopen("sample.bmp","rb");
  FILE *fp2 = fopen("asciiart.txt","wt");
  char t[20]=" .,^;17opnmgWKQ&";
  int i, j;
  for(i=0; i<HEADER; i++) //����κ� ��������
    getc(fp1);
    
  for(i=0; i<HEIGHT; i++)
    for(j=0; j<WIDTH; j++)
    {
      B[i][j]=getc(fp1);
      G[i][j]=getc(fp1);
      R[i][j]=getc(fp1);
    }
    
  //�� ������ �迭 ������ �۾�!!
  int g;  //���ο� �� ���� ����� ���� ����
  for(i=448; i>256; i--)
  {
    for(j=64; j<256; j++)
    {
      //���� ����� ��� �ΰ����� ���� ȸ����ȯ
      //ITU-R BT.601 ǥ��?
      g = B[i][j]*0.299+G[i][j]*0.587+R[i][j]*0.114;
      fprintf(fp2,"%c",t[(15-g/16)]);
    }
    fprintf(fp2,"\n");
  }
  return 0;
}
