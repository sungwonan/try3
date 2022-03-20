#include<bangtal.h>

SceneID room1, room2;
ObjectID startButton, background;
ObjectID board[4][4];


int X[4] = {340, 490, 640, 790};
int Y[4] = {60, 210, 360, 510};
int radius = 150;

bool checked[4][4];

bool checkin(int x, int y, int cx, int cy, int r) {
	return(x > cx && x<cx + r && y>cy && y < cy + r);
}

void startGame() {
	enterScene(room2);
	board[3][0] = 0;
}


void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == startButton) {
		startGame();
	}

	if (object == board[2][0]) {
		for (int i = 0; i < 4; i++) {
			for (int r = 0; r < 4; r++) {
				if (board[i + 1][r] == 0 && (checkin(x, y, X[i], Y[r], radius)))
					board[i][r] = board[i + 1][r];

			}

		}
	}

}



int main() {

	setMouseCallback(mouseCallback);

	room1 = createScene("퍼즐맞추기", "images/원본.png");
	room2 = createScene("퍼즐맞추기");

	startButton = createObject("images/start.png");
	locateObject(startButton, room1, 590, 70);
	showObject(startButton);

	background = createObject("images/배경.png");
	locateObject(background, room2, 0, 0);
	showObject(background);


	for (int i = 0; i < 4; i++) {
		for (int r = 0; r < 4; r++) {
			board[0][0] = createObject("images/13.png");
			locateObject(board[0][0], room2, X[0], Y[0]);
			showObject(board[0][0]);
			board[1][0] = createObject("images/14.png");
			locateObject(board[1][0], room2, X[1], Y[0]);
			showObject(board[1][0]);
			board[2][0] = createObject("images/15.png");
			locateObject(board[2][0], room2, X[2], Y[0]);
			showObject(board[2][0]);
			board[3][0] = createObject("images/16.png");
			locateObject(board[3][0], room2, X[3], Y[0]);

			board[0][1] = createObject("images/9.png");
			locateObject(board[0][1], room2, X[0], Y[1]);
			showObject(board[0][1]);
			board[1][1] = createObject("images/10.png");
			locateObject(board[1][1], room2, X[1], Y[1]);
			showObject(board[1][1]);
			board[2][1] = createObject("images/11.png");
			locateObject(board[2][1], room2, X[2], Y[1]);
			showObject(board[2][1]);
			board[3][1] = createObject("images/12.png");
			locateObject(board[3][1], room2, X[3], Y[1]);
			showObject(board[3][1]);

			board[0][2] = createObject("images/5.png");
			locateObject(board[0][2], room2, X[0], Y[2]);
			showObject(board[0][2]);
			board[1][2] = createObject("images/6.png");
			locateObject(board[1][2], room2, X[1], Y[2]);
			showObject(board[1][2]);
			board[2][2] = createObject("images/7.png");
			locateObject(board[2][2], room2, X[2], Y[2]);
			showObject(board[2][2]);
			board[3][2] = createObject("images/8.png");
			locateObject(board[3][2], room2, X[3], Y[2]);
			showObject(board[3][2]);

			board[0][3] = createObject("images/1.png");
			locateObject(board[0][3], room2, X[0], Y[3]);
			showObject(board[0][3]);
			board[1][3] = createObject("images/2.png");
			locateObject(board[1][3], room2, X[1], Y[3]);
			showObject(board[1][3]);
			board[2][3] = createObject("images/3.png");
			locateObject(board[2][3], room2, X[2], Y[3]);
			showObject(board[2][3]);
			board[3][3] = createObject("images/4.png");
			locateObject(board[3][3], room2, X[3], Y[3]);
			showObject(board[3][3]);

			board[i][r] = 1;
		}
	}


	showMessage("퍼즐을 맞추세요.");
	startGame(room1);
}

