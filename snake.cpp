#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
using namespace std;

int score;
int const  width = 20, height = 40;
bool gameOver;

struct point {
	int x, y;
};
point player, fruit;



void setup() {
	player.x = width / 2;
	player.y = height / 2;

	fruit.x = rand() % width;
	fruit.y = rand() % height;

	gameOver = false;
	score = 0;

}

void draw() {



}

void input() {


}

void logic() {



}



int main() {

	srand(time(NULL));
	setup();

	while (!gameOver) {
		draw();
		input();
		logic();
		sleep(50);
	}


}