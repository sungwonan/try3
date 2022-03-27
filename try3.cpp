#include<bangtal.h>

#include<time.h>
#include<stdlib.h>

SceneID room;
ObjectID startButton;
ObjectID restart;
ObjectID board[16], right[16];
TimerID timer, timer1;


const int X[16] = {340, 490, 640, 790, 340, 490, 640, 790, 340, 490, 640, 790, 340, 490, 640, 790};
const int Y[16] = {510, 510, 510, 510, 360, 360, 360, 360, 210, 210, 210, 210, 60, 60, 60, 60};

int blank;

int mixCount;

int board_index(ObjectID object) {
	for (int i = 0; i < 16; i++) {
		if (board[i] == object)return i;
	}
	return-1;
}

void move(int index) {
	ObjectID t = board[blank];
	board[blank] = board[index];
	board[index] = t;

	locateObject(board[blank], room, X[blank], Y[blank]);
	locateObject(board[index], room, X[index], Y[index]);

	blank = index;
}

bool complete() {
	for (int i = 0; i < 16; i++) {
		if (board[i] != right[i])return false;
	}
	return true;
}

bool movable(int index) {
	if (blank < 0 or blank>15) return false;
	if (blank % 4 !=0 and blank - 1 == index)return true;
	if (blank % 4 !=3 and blank + 1 == index)return true;
	if (blank / 4 !=0  and blank - 4 == index)return true;
	if (blank / 4 != 3 and blank + 4 == index)return true;

	return false;
}

void mix() {
	int index;

	do {
		switch (rand() % 4) {
		case 0: index = blank - 1; break;
		case 1: index = blank + 1; break;
		case 2: index = blank - 4; break;
		case 3: index = blank + 4; break;
		}
	} while (!movable(index));
	move(index);
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == startButton) {
		hideObject(board[15]);
		mixCount = 60;
		setTimer(timer, 0.1f);
		startTimer(timer);
		hideObject(startButton);
		startTimer(timer1);
		showTimer(timer1);

	}
	else {
		int index = board_index(object);
		if (movable(index)) {
			move(index);

			if (complete()) {
				showMessage("완료");
				showObject(restart);
				showObject(board[15]);
				stopTimer(timer1);
			}
		}
	}
	if (object == restart) {
		mixCount = 60;
		setTimer(timer, 0.1f);
		startTimer(timer);
		hideObject(restart);
		hideObject(board[15]);
		setTimer(timer1, 907.0f);
		startTimer(timer1);
		showTimer(timer1);
	}
}

void timerCallback(TimerID timer) {
	mixCount-- ;

	if (mixCount > 0) {
		mix();

		setTimer(timer, 0.1f);
		startTimer(timer);
	}
}

const char* image[16] = {
	"images/1.png",
	"images/2.png",
	"images/3.png",
	"images/4.png",
	"images/5.png",
	"images/6.png",
	"images/7.png",
	"images/8.png",
	"images/9.png",
	"images/10.png",
	"images/11.png",
	"images/12.png",
	"images/13.png",
	"images/14.png",
	"images/15.png",
	"images/16.png"

};


int main() {

	setMouseCallback(mouseCallback);
	setTimerCallback(timerCallback);

	room = createScene("퍼즐맞추기", "images/배경.png");


	for (int i = 0; i < 16; i++) {
		board[i] = createObject(image[i]);
		right[i] = board[i];
		locateObject(board[i], room, X[i], Y[i]);
		showObject(board[i]);
	};

	blank = 15;

	startButton = createObject("images/start.png");
	locateObject(startButton, room, 590, 70);
	showObject(startButton);

	restart = createObject("images/restart.png");
	locateObject(restart, room, 590, 70);

	timer = createTimer(0.1f);
	timer1 = createTimer(907.f);
	
	showMessage("퍼즐을 맞추세요.");
	startGame(room);

	return 0;
}

