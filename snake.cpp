#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
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
	system("cls");
	int i, j;
	for (i = 0; i < width; i++)
		cout << "*";
	cout << endl;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (j == 0 || j == width - 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	

	for (i = 0; i < width; i++)
		cout << "*";
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
		Sleep(200);
	}

	return 0;
}