#include<stdio.h>
#include<conio.h>
#include<dir.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<windows.h>
void setcolor(int);
int main(){

  char* a[100];
  int check;
    SetConsoleTitle("Directory Maker:- Himanshu Sharma");
  readAgain:
  printf("Enter The folder name with destination (example- D:/hello) if you won`t mention destination, by default it will be in D:/project in c/Directory Maker\n");
   printf(">>>>\t");
  gets(a);
  check =mkdir(a);
  setcolor(26);

  if(!check)
  {
    printf("Successfully Created Directory in %s (%d)\n",a,check);
  }else
  {
      setcolor(25);
    printf("Error in creating (same folder name may be already exist..) %d",check);

  }
setcolor(45);

printf("--------------------------------------\n");
  system("dir");
  printf("\n--------------------------------------\n");
  read:
      printf("\n");
      setcolor(63);
  printf("do you want to try again (Y\\N)?");
  char ch ;
  ch=getche();
  if(ch=='y' || ch=='Y'){
    system("cls");
    goto readAgain;
  }else if(ch=='n' || ch=='N'){

    getch();
  return 0;

  }else
  {

      goto read;
  }



}
void setcolor(int ForgC)
{
     WORD wColor;


     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;


     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
