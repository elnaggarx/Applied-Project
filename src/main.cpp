#include <iostream>
#include<graphics.h>
#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<mmsystem.h>
void stars(int xmax,int ymax){ //function for galaxy stars background
	int rxnumber , rynumber,i=0;
	srand(time(0));
	for(i=0;i<600;i++){
		rxnumber = (rand() % xmax)+1 ;
		rynumber= (rand()%ymax)+1; 
		putpixel(rxnumber,rynumber,WHITE);
	}
}
void text1(int xmax,int ymax){ //All the text in the start menu
	settextstyle(6,0,9);
	outtextxy((xmax/2)-260,(ymax/2)-100,"StarWars");
	settextstyle(3,0,2);
	outtextxy((xmax/2)-100,(ymax/2)+20,"press any key to continue...");
}
void text1a(int xmax,int ymax){//for starwars text animation
	for(int i=2;i<=9;i++){
		settextstyle(6,0,i);
	    outtextxy((xmax/2)-260,(ymax/2)-100,"StarWars");
		delay(1200);
	}
}

int main(int argc, char *argv[])
{
	int xmax,ymax; //For maximum x&y co-ordinates
	int gd = DETECT , gm;
	//starwars theme song
	PlaySound(TEXT("C:\\Users\\user\\Desktop\\Applied Project\\src\\Theme.wav"), NULL, SND_LOOP | SND_ASYNC);
	initgraph(&gd,&gm,(char*)"");
	xmax = getmaxx();
	ymax = getmaxy();
	text1a(xmax,ymax);
	while(!kbhit()){//To keep randomizing the stars
	    text1(xmax,ymax);
		stars(xmax,ymax);
		delay(2000);
		cleardevice();
	}
	getch(); // 46-47 not functioning code lines to be corrected MODIFIED : CORRECTED 
	cleardevice();






	getch();
	closegraph();
	std::cout << "Hello world!" << std::endl;
	return 0;
}