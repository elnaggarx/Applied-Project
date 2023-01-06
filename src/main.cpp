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
void input(char nn[]){
	printf("please enter your nickname \n");
	gets(nn);
}
/*void MainmenuSelector(int *i,int *c){
	if(*c==0){
		*i=0;
	}
	c++;
	while(true){
	    if(*i==0){
		    settextstyle(3,0,4);
		    setcolor(14);
	        outtextxy(277,150,"Start");
		    setcolor(15);
		    outtextxy(210,200,"Scoreboard");
	    }
	    else{
		    settextstyle(3,0,4);
		    setcolor(15);
	        outtextxy(277,280,"Start"); //277,150
		    setcolor(14);
		    outtextxy(210,200,"Scoreboard");
	    }
		if(GetAsyncKeyState(VK_UP)){ //|| GetAsyncKeyState(VK_DOWN)
		    if((*i)==0){
			   (*i)++;
			   break;
		}
		    else{
			   (*i)--;
			   break;
		}	
	    }
	}
}*/
void Mainmenu(int *p,int *i){ //for main menu items
   *p=0;
   *i=0;
   while(*p==0){
	settextstyle(3,0,4);
	outtextxy(277,150,"Start");
	outtextxy(210,200,"Scoreboard");
	if(GetAsyncKeyState(VK_RETURN)){
		(*p)++;
		if(*p!=0){
			cleardevice();
			break;
		}
	}
	else if(GetAsyncKeyState(VK_DOWN) && *i==0){
		(*i)++;
	}
	else if(GetAsyncKeyState(VK_UP) && *i==1){
		(*i)--;
	}
	if(*i==0){
		settextstyle(3,0,4);
		setcolor(14);
	    outtextxy(277,150,"Start");
		setcolor(15);
		outtextxy(210,200,"Scoreboard");
	}
	else if(*i==1){
		settextstyle(3,0,4);
		setcolor(15);
	    outtextxy(277,150,"Start");
		setcolor(14);
		outtextxy(210,200,"Scoreboard");
	}
	getch();
	cleardevice();
   }
}

void game(int xmax,int ymax){
	int speed=10;
	int posx1=300;
	int posx2;
	int speedo=5;
	int posy2=0;
	int radius;
	srand(time(0));
	posx2 = (rand()% xmax )+1;
	while(true){
	//body of the spaceship
	setfillstyle(1,DARKGRAY);
	bar(posx1,330,posx1+25,420);
	//head of the spaceship
	int ap[]={posx1,330,posx1+13,310,posx1+25,330};
	setfillstyle(1,RED);
	fillpoly(3,ap);
	//Wings of the spaceship
	setcolor(BLACK);
	int ap1[]={posx1-55,420,posx1,420,posx1,375}; //points of left wing
	int ap2[]={posx1+80,420,posx1+25,420,posx1+25,375}; //points of right wing
	setfillstyle(1,BLUE);
	fillpoly(3,ap1);
	fillpoly(3,ap2);
	if(GetAsyncKeyState(VK_LEFT) && posx1>0){
		posx1=posx1 - speed;
	}
	else if(GetAsyncKeyState(VK_RIGHT) && posx1<xmax){
		posx1=posx1+speed;
	}
	radius = 50;
	int ap3[]={posx2,posy2,posx2,posy2+40,posx2+50,posy2+40,posx2+50,posy2};
	setfillstyle(1,RED);
	fillpoly(4,ap3);
	posy2+=speedo;
	if(posy2>=ymax){
		posy2=0;
		posx2 = (rand()% xmax )+1;
	}
	delay(50);
	cleardevice();
	}
	getch();
}
int main()
{
	int xmax,ymax;//For maximum x&y co-ordinates
	int x=0; //for detecting return key
	char nn[30]; //To hold nickname string
	int w; //For detecting menu selector
	int gd = DETECT , gm;
	input(nn);
	//starwars theme song  RELATIVE PATH NEEDED : CORRECTED
	PlaySound(TEXT("..\\src\\Theme.wav"), NULL, SND_LOOP | SND_ASYNC);
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
	if(GetAsyncKeyState(VK_RETURN)){
		x++;
	}
	getch(); // 46-47 not functioning code lines to be corrected MODIFIED : CORRECTED 
	cleardevice();
	Mainmenu(&x,&w);
	if(w==0){
		game(xmax,ymax);
	}
	printf("%d",w);
	getch();
	closegraph();
	std::cout << "Hello world!" << std::endl;
	return 0;
}