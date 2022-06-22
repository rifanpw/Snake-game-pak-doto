#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27

char map[20][20];
char player = '0', food = '*';
char tail[10] = {'*','*','*','*','*','*','*','*','*'};
int y = 12;
int x = 3;
int a[10], b[10];
int score = 0;
int n = 0, p = 10, q = 10, rand = 2, R = 1, i, j;
int gameover=0, flag;
char jalan;

void generateMap(int p, int q, int R);
void outputMap(int score);
void moveUp();
void moveDown();
void moveLeft();
void moveRight();

int main(){
	int i,j;
	do{
		system("cls");
		generateMap(p,q,R);
		outputMap(score);
		for(i=9; i>0; i--){
			a[i] = a[i-1];b[i] = b[i-1];
		}
		a[0] = y;b[0] = x;
		input();
		logic();
		}while(score < 10);
	system("cls");
	printf("\t\t+==============================+\n");
	printf("\t\t|      CONGRATULATION !!!      |\n");
	printf("\t\t+==============================+\n");
	printf("Your Score : 10");
	getch();
	return 0;
}

void generateMap(int p, int q, int R){
	int i,j;
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			map[i][j] = ' ';
		}
	}
	map[0][0] = '+';
	map[19][0] = '+';
	map[19][19] = '+';
	map[0][19] = '+';
	for(i=1; i<19; i++){
		map[i][0] = '|';
		map[i][19]= '|';
	}
	for(j=1; j<19; j++){
		map[0][j] = '=';
		map[19][j] = '=';
	}
	map[y][x] = player;
	for(i=0; i<R; i++){
		map[a[i]][b[i]] = tail[i];
	}
	map[p][q] = food;
}

void outputMap(int score){
	int i,j;
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
	printf("Score: 00%d",score);
}
void moveUp(){
	if(map[y - 1][x] == ' '){
				y--;
				map[y][x] = player;
				}
				else if(map[y - 1][x] == food){
					p *= (rand + y * 3);q *= (rand + x * 9);
					if(p >= 19) p %= 13;p++; 
					if(q >= 19) q %= 16;q++;
					score++;
					R++;
				}
				player = '0';
				for(i=0; i<R; i++){
					for(j=0; j<R; j++){
						map[a[i]][b[j]] = tail[n];
						n++;
					}
				}
}
void moveDown(){
	if(map[y+1][x] == ' '){
				y++;
				map[y][x] = player;															
	}
				else if(map[y + 1][x] == food){
					p *= (rand + y * 6);q *= (rand + x * 8);
					if(p >= 19) p %= 18;p++; 
					if(q >= 19) q %= 15;q++;
					score++;
					R++;
				}
				player = '0';
				for(i=0; i<R; i++){
					for(j=0; j<R; j++){
						map[a[i]][b[j]] = tail[n];
						n++;
					}
				}
}
void moveLeft(){
	if (map[y][x-1] == ' '){
				x--;
				map[y][x] = player;		
				}
				else if(map[y][x-1] == food){
					p *= (rand + y * 5);q *= (rand + x * 7);
					if(p >= 19) p %= 18;p++; 
					if(q >= 19) q %= 17;q++;
					score++;
					R++;
				}
				player = '0';
				for(i=0; i<R; i++){
					for(j=0; j<R; j++){
						map[a[i]][b[j]] = tail[n];
						n++;
					}
				}
}
void moveRight(){
	if(map[y][x+1] == ' '){
				x++;
				map[y][x] = player;	
				}
				else if(map[y][x+1] == food){
					p *= (rand + y * 2);q *= (rand + x * 3);
					if(p >= 19) p %= 18;p++;
					if(q >= 19) q %= 18;q++;
					score++;
					R++;
				}
				player = '0';
				for(i=0; i<R; i++){
						for(j=0; j<R; j++){
							map[a[i]][b[j]] = tail[n];
							n++;
					}
				}
}
void input()
{
    unsigned char button;
	if (kbhit()) {
		button = getch();
        if(button == 'a' || button == LEFT){
            flag = 1;
        }else if(button == 's' || button == DOWN){
            flag = 2;
        }else if(button == 'd' || button == RIGHT){
            flag = 3; 
        }else if(button == 'w' || button == UP){
            flag = 4;
        }else if(button == 'x' || button == ESC){
            gameover = 1;
        } 
	}
}
void logic(){
	sleep(0.01);
	switch (flag) {
	case 1: //turn left
		moveLeft();
		break;
	case 2: //turn down
		moveDown();
		break;
	case 3: //turn right
		moveRight();
		break;
	case 4: //turn up
		moveUp();
		break;
	default:
		break;
	}
}
