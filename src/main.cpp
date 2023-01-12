//By Mohamed Amr & Mohamed Hesham
//Dr Hesham Salah & T.A Eng. Ahmed Zakaria
//Enjoy----------------
#include <iostream>
#include<graphics.h>
#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<mmsystem.h>
#include<string.h>
#include<stdlib.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"
struct player{ //EDITED FROM ETCH
	int count;
    char Nick_Name[20]; //strings
	long score;
    float per;
}; //struct
//REMAINING SCORE--INCREASING SPEED--CRASH GAMEOVER
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
	stars(xmax,ymax);
}
void text1a(int xmax,int ymax){//for starwars text animation
	for(int i=2;i<=9;i++){
		settextstyle(6,0,i);
	    outtextxy((xmax/2)-260,(ymax/2)-100,"StarWars");
		delay(1200);
	}
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
void Mainmenu(int *p,int *i,int xmax,int ymax){ //for main menu items
   *p=0;
   *i=0;
   while(*p==0){
	settextstyle(3,0,4);
	outtextxy(277,150,"Start");
	outtextxy(288,200,"Exit");
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
		outtextxy(288,200,"Exit");
	}
	else if(*i==1){
		settextstyle(3,0,4);
		setcolor(15);
	    outtextxy(277,150,"Start");
		setcolor(14);
		outtextxy(288,200,"Exit");
	}
	stars(xmax,ymax);
	getch();
	cleardevice();
   }
}

void game(int xmax,int ymax , int *p,int *w,long *score ){
	long loop=0,limit=50;
	char str[20];
	int speed=10;
	int posx1=300;
	int posx2;
	int speedo=14;
	int posy2=0;
	int posx3;
	int posy3 =0;
	int posx4;
	int posy4=0;
	srand(time(0));
	posx2 = (rand()% xmax )+1;
	posx3 = (rand()% xmax )+1;
	posx4 = (rand()% xmax )+1;
	
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
	if((*score)>=limit){
		speedo=speedo*1.5;
		limit+=50;
	}
	if(GetAsyncKeyState(VK_LEFT) && posx1>0){
		posx1=posx1 - speed;
	}
	else if(GetAsyncKeyState(VK_RIGHT) && posx1<xmax){
		posx1=posx1+speed;
	}
	//obstacles
	int ap3[]={posx2,posy2,posx2,posy2+40,posx2+50,posy2+40,posx2+50,posy2};
	setfillstyle(1,YELLOW);
	fillpoly(4,ap3);
	int ap4[]={posx3,posy3,posx3,posy3+40,posx3+50,posy3+40,posx3+50,posy3};
	setfillstyle(1,YELLOW);
	fillpoly(4,ap4);
	int ap5[]={posx4,posy4,posx4,posy4+40,posx4+50,posy4+40,posx4+50,posy4};
	setfillstyle(1,YELLOW);
	fillpoly(4,ap5);
	posy2+=speedo;
	posy3+=speedo;
	posy4+=speedo;
	if(posy2>=ymax && posy4>=ymax && posy3>=ymax ){
		posy2=0;
		posy3=0;
		posy4=0;
	    posx2 = (rand()% xmax )+1;
		posx3 = (rand()% xmax )+1;
	    posx4 = (rand()% xmax )+1;
	}

	if((posy2+40)>=310 && posy2<=310 && posx2<=posx1 && (posx2+50)>=posx1){
		cleardevice();
		break;
	}
	else if(posy2>=330 && posy2<=420 && posx2>=posx1 && posx2<=(posx1+25)){
		cleardevice();
		break;
	}
	else if(posy2>=330 && posy2<=420 && (posx2+50)>=posx1 && (posx2+50)<=(posx1+25)){
		cleardevice();
		break;
	}
	if((posy3+40)>=310 && posy3<=310 && posx3<=posx1 && (posx3+50)>=posx1){
		cleardevice();
		break;
	}
	else if(posy3>=330 && posy3<=420 && posx3>=posx1 && posx3<=(posx1+25)){
		cleardevice();
		break;
	}
	else if(posy3>=330 && posy3<=420 && (posx3+50)>=posx1 && (posx3+50)<=(posx1+25)){
		cleardevice();
		break;
	}
	if((posy4+40)>=310 && posy4<=310 && posx4<=posx1 && (posx4+50)>=posx1){
		cleardevice();
		break;
	}
	else if(posy4>=330 && posy4<=420 && posx4>=posx1 && posx4<=(posx1+25)){
		cleardevice();
		break;
	}
	else if(posy4>=330 && posy4<=420 && (posx4+50)>=posx1 && (posx4+50)<=(posx1+25)){
		cleardevice();
		break;
	}
	stars(xmax,ymax);
	*score=loop*0.5;
	sprintf(str,"%ld",*score);
	setcolor(WHITE);
    outtextxy(100,100,str);
	loop++;
	delay(50);
	cleardevice();
	} 
	PlaySound(NULL,NULL,0);
	*p=0;
	PlaySound(TEXT("..\\src\\GameOver.wav"),NULL,SND_ASYNC);
    for(int i=3;i<=8;i++){
		setcolor(WHITE);
	    settextstyle(3,0,i);
	    outtextxy(100,180,"GAME OVER");
	    delay(500);
	}
	while(true){
	setcolor(WHITE);
	settextstyle(3,0,8);
	outtextxy(100,180,"GAME OVER");
	if(GetAsyncKeyState(VK_RETURN)){
		*p++;
	}
	if(*p==1){
		break;
	}
	}
	
	getch();
	cleardevice();
}
int main()
{
	struct player info;
	info.score=0;
	int xmax,ymax;//For maximum x&y co-ordinates
	int x=0; //for detecting return key
	char nn[30]; //To hold nickname string
	int w; //For detecting menu selector
	long score1;
	int gd = DETECT , gm;
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
	Mainmenu(&x,&w,xmax,ymax);
	if(w==0){
		game(xmax,ymax,&x,&w,&score1);
		info.score=score1;
		printf("Your Score : %ld",score1);
		char another;
        FILE *fp;
        do{
			system("cls");
			printf("\t\t\t\t*Add Players Info*\n\n\n"); 
			fp=fopen("information.txt","a"); 
			printf("\n\t\t\tEnter Your Nick Name     : ");
			gets(info.Nick_Name);
			info.score=score1;
			printf("\n\t\t\t__\n");       
			if(fp==NULL){
				fprintf(stderr,"can't open file");
		    }
			else{
				printf("\t\t\t Data stored successfuly\n");
            }
            fwrite(&info, sizeof(struct player), 1, fp); 
            fclose(fp);
            printf("\t\t\tYou want to add another record?(y/n) : ");
            scanf("%c",&another);
        }while(another=='y'||another=='Y');
		fp=fopen("information.txt","r");
		printf("\t\t\t\t*PlAYERS DASHBORAD*\n\n\n");
		if(fp==NULL){
        fprintf(stderr,"can't open file\n");
        exit(0);
		}
		else{
        printf("\t\t\t\t Data :\n");
        printf("\t\t\t\t___\n\n");
		}
        while(fread(&info,sizeof(struct player),1,fp)){
			printf("\n\t\t\t\t Player Name  : %s",info.Nick_Name);
			printf("\n\t\t\t\t\t Score  : %ld",info.score);
			printf("\n\t\t\t\t __\n");
		}
        fclose(fp);
		int r;
		printf("please enter the number of players you want to view their score\t");
		scanf("%d",&r);
		long *k= (long *)malloc(sizeof(long)*r); //malloc (1d long array for scores)
		fp = fopen("information.txt","r");
		int b=0;
		while(fread(&info,sizeof(struct player),1,fp)){
			if(b==r){
				break;
			}
			//if(info.score!=NULL){
				k[b]=info.score;
			    b++;
			//}
		}
		fclose(fp);
		for(b=0;b<r;b++){
			printf("\n\nscore %d = %d",b,(int)k[b]);
		}
		printf("\n\n\t\t**enter the first letter of any player**  \t\t\n:");
		char l;
		int u=0;
		char names[5][30]; //2d array
		scanf("%s",&l); //doesnt want to read a char %c
		fp = fopen("information.txt","r");
		while(fread(&info,sizeof(struct player),1,fp)){ //linear search
			if(u>=5){
				break;
			}
			if(info.Nick_Name[0]==l){
				strcpy(names[u],info.Nick_Name);
				u++;
			}
		}
		fclose(fp);
		for(int g=0;g<5;g++){
			if(names[g][0]!='\0'){ //names[g][0]==l
				puts(names[g]);
			}
		}
	}
	else if(w==1){
		closegraph();
		return 0;
	}
    x=0;
	while(x==0){
		if(GetAsyncKeyState(VK_RETURN)){
			x = x+1;
		}
	}
	closegraph();
	return 0;
}