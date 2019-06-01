#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <iostream>
using namespace std;

int _color(int r,int g,int b);
void SetColor(int f,int b);
int diff=0;
 
int main(){
	while(true){
	//system("cls");
	FILE *image_input;
    FILE *image_output;
    fstream dirty;
    int i, j, k;
    int trash=0;;
    int row;
    int col;
    int width,height;
	
    if ((image_input = fopen("test.bmp","rb")) == NULL){
      printf( "\n Can't open file %s","test.bmp");
    }
    else
    {
        for(i=0;i<54;i++){
				trash=fgetc(image_input);
	    }
	}
	cin>>row;
	cin>>col;
	system("cls");
	cout<<row<<" "<<col<<endl;
	int g,b,r;
	int pic[row*3][col];
	width=(row*3/4+1)*4;
	height=col;
	cout<<row<<" "<<col<<endl;
	for(i=0;i<row*col*3;i++){
		//cout<<"¦ì¸m "<<i%(row*3)<<","<<i/(row*3)<<":"; 
		if((i+1)%(row*3)!=0){
			pic[i%(row*3)][i/(row*3)]=fgetc(image_input);
			//cout<<pic[i%(row*3)][i/(row*3)]<<" | ";
		}else{
			pic[i%(row*3)][i/(row*3)]=fgetc(image_input);
			//cout<<pic[i%(row*3)][i/(row*3)]<<endl;
			if(width-row*3!=4){
			for(j=0;j<width-row*3;j++){
				trash=fgetc(image_input);
			}
			}
		}
	}
	for(i=col-1;i>-1;i--){
		for(j=0;j<row*3;j+=3){
			SetColor(_color(pic[j+2][i],pic[j+1][i],pic[j][i]),_color(pic[j+2][i],pic[j+1][i],pic[j][i]));
			cout<<"¡½";
		}
		cout<<endl;
	}
	SetColor(7,0); 
	}
}

int _color(int r,int g,int b){
	int color=0;
	if(r==0 && g==0 && b==0) color=0;
	if(r==255 && g==255 && b==255) color=7;
	return color;
}

void SetColor(int f,int b){
    unsigned short ForeColor=f+16*b;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,ForeColor);
}

