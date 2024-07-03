#include<iostream>
#include<conio.h>
#include<time.h>
#include<windows.h>
using namespace std;

const short int height = 30, width = 48;

short int ballPositionX, ballPositionY;
short int &x = ballPositionX;
short int &y = ballPositionY;

short int sliderPosition1, sliderPosition2, sliderSize;
short int sliderSpeed = 0;
short int &sP1= sliderPosition1;
short int &sP2= sliderPosition2;

bool gameOver;
bool bDirY, bDirX;

enum controls {STOP = 0, LEFT1, RIGHT1};
controls ctr;
enum controls2 {STOP2 = 0, LEFT2, RIGHT2};
controls2 ctr2;

short int score = 0;

void Initialization(){

	gameOver = 0;
	ctr = STOP;
	ctr2 = STOP2;
	x = width/2;
	y = height-2;
	sliderSize = 10;
	sliderPosition1 = (width/2)-(sliderSize/2);
	sliderPosition2 = (width/2)-(sliderSize/2);

}

void Draw(){

	system("cls"); 

	for(short int i = 0; i<width+1; i++){ //printing upper border
		cout<<"#";
	}
	cout<<endl; 

	for(short int h = 0; h<height; h++){

		for(short int w = 0; w<width; w++){

			if(w == 0){ //printing left side border
				cout<<"#";
			}
			
			else if(h == y && w == x){ //printing ball
				cout<<"O";
			}

			else if((h == height-2 && w> sP1 && w <= (sP1 + sliderSize)) || (h == 1 && w>sP2 && w <= (sP2 + sliderSize))){ //printing slider
					cout<<"=";
			}
			
			else{ //printing empty space
				cout<<" ";
			}
			
			if(w == width-1){ //printing right side border
				cout<<"#";
			}

		}
		cout<<h;
		cout<<endl;
	}
	 
	for(short int i = 0; i<width+1; i++){ //printing lower border
		cout<<"*";
	}

	cout<<endl;
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	// cout<<"Slider Speed = "<<sliderSpeed<<endl;
	cout<<"sP2 = "<<sP2<<" - "<<sP2+sliderSize<<endl;
	cout<<"sP1 = "<<sP1<<" - "<<sP1+sliderSize<<endl;
	cout<<"Score = "<<score<<endl;
}

void Input(){

	if(_kbhit()){

		switch(_getch()){
			case '4': 
				ctr = LEFT1;
				break;
			case '6':
				ctr = RIGHT1;
				break;
			case '`':
				gameOver = 1;
				break;
			case 'a':
				ctr2 = LEFT2;
				break;
			case 'd':
				ctr2 = RIGHT2;
			default:
				break;
		}
	}
}

void LogicB(){
	
	if(y == height-2 && x > sP1 && x <= (sP1+ sliderSize)){
		bDirY = 0;
		score++;
		if(score%5 ==0){
			sliderSize++;
		}
		srand(time(0));
		bDirX = rand() & 1 +0;
	}else if(y == 1 && y > sP2 && y <= (sP2 + sliderSize)){
		bDirY = 1;
		score++;
		srand(time(0));
		bDirX = rand() & 1 +0;
	}
	if(x == 1){
		bDirX = 1;
	}else if(x == width-1){
		bDirX = 0;
	}

	if(bDirY == 0){
		y--;
	}else if(bDirY == 1){
		y++;
	}
	if(bDirX == 0){
		x--;
	}else if(bDirX ==1){
		x++;
	}

}

void LogicS(){

	if(ctr == LEFT1){
		if(sP1 > 0){
			sP1 = sP1 - 1;
		}
	}else if(ctr == RIGHT1){
		if(sP1 < (width - sliderSize - 1)){
			sP1 = sP1 + 1;
		}
	}
	if(ctr2 == LEFT2){
		if(sP2 > 0){
			sP2 = sP2 - 1;
		}
	}else if(ctr2 == RIGHT2){
		if(sP2 < (width - sliderSize - 1)){
			sP2 = sP2 + 1;
		}
	}
	ctr = STOP;
	ctr2 = STOP2;
	if(y >= height || y < 0 ){
		gameOver = 1;
	}

}

void SliderSpeed(){
	cout<<"choose slider speed level"<<endl;
	cout<<"1. Super Slow \n2. Slow \n3. Normal \n4. Fast \n5. Super Fast"<<endl;

	while(1){

		if(_kbhit()){
		
			switch(_getch()){
				case '1':
				sliderSpeed = 1;
				break;
				case '2':
				sliderSpeed = 2;
				break;
				case '3':
				sliderSpeed = 3;
				break;
				case '4':
				sliderSpeed = 4;
				break;
				case '5':
				sliderSpeed = 5;
				break;
				case '`':
				gameOver = 1;
				default:
				sliderSpeed = 3;
			}
		
		}

		if(sliderSpeed>0){
			break;
		}

	}

}

int main(){

	

	Initialization();
	
	while(!gameOver){
		Draw();
		Input();
		LogicB();
		LogicS();
		Input();LogicS();
		Input();LogicS();
		// for(int i = 2; sliderSpeed>1 && i<=sliderSpeed; i++){
		// 	Input();
		// 	LogicS();
		// }
		Sleep(10);
	}

	return 0;
}
