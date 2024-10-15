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
point tail[600];
int n_tail;  

enum direction{
	STOP = 0,LEFT,RIGHT,UP,DOWN
};
direction dir;

void setup() {
	player.x = width / 2;
	player.y = height / 2;

	fruit.x = rand() % (width - 2) + 1;
	fruit.y = rand() % (height - 2) + 1;

	gameOver = false;
	score = 0;
	n_tail = 0;

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
			else if (j == player.x && i == player.y)
				cout << "O";
			else if (j == fruit.x && i == fruit.y)
				cout << "X";
			else {
				bool flag = false;
				for (int k = 0; k < n_tail; k++)
					if (j == tail[k].x && i == tail[k].y) {
						cout << "o";
						flag = true;
					}
				if(!flag)
					cout << " ";
						
			}
				
		}
		cout << endl;
	}
	

	for (i = 0; i < width; i++)
		cout << "*";

	cout << "\n Score : " << score;
}

void input() {
	if (_kbhit()) {
		switch (_getche())
		{
		case 'w':
		case 'W':
			dir = UP;
			break;

		case 's':
		case 'S':
			dir = DOWN;
			break;

		case 'a':
		case 'A':
			dir = LEFT;
			break;

		case 'd':
		case 'D':
			dir = RIGHT;
			break;

		default:
			break;
		}

	}

}

void logic() {

	for (int i=n_tail - 1; i >=1 ; i--) {
		tail[i].x = tail[i - 1].x;
		tail[i].y = tail[i - 1].y;
	}
	tail[0].x = player.x;
	tail[0].y = player.y;
	
	switch (dir)
	{
	
	case LEFT:
		player.x = (player.x - 1 + width) % width;
		break;

	case RIGHT:
		player.x = (player.x + 1) % width;
		break;

	case UP:
		player.y = (player.y - 1 + height) % height;
		break;

	case DOWN:
		player.y = (player.y + 1) % height;
		break;

	default:
		break;
	}

	if (player.x == fruit.x && player.y == fruit.y) {
		score += 10;

		fruit.x = rand() %( width-2) +1;
		fruit.y = rand() % (height-2)+1;

		n_tail++;
	}
}



int main() {

	srand(time(NULL));
	setup();

	while (!gameOver) {
		draw();
		input();
		logic();
		Sleep(500);
	}

	return 0;
}