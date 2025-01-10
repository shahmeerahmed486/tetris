#include <iostream>
//---Piece Starts to Fall When Game Starts---//

// ShahmeerAhmed

int rotations = 0;
int bombfall = 0; // for probability of bomb falling
int n = -10;
bool reachbottom = false; // for the bomb
int bombposition = 0;	  // x-coordinate of the bomb

bool paused = false;
bool gamepause = false;
bool gamebegin = false;

bool exitgame = false;

void fallingPiece(float &timer, float &delay, int &colorNum)
{
	if (gamepause == false && gamebegin == true)
	{

		reachbottom = 0;
		if (timer > delay)
		{
			for (int i = 0; i < 4; i++)
			{
				point_2[i][0] = point_1[i][0];
				point_2[i][1] = point_1[i][1];
				point_1[i][1] += 1; // How much units downward
			}
			if (!anamoly())
			{
				for (int i = 0; i < 4; i++)
				{
					gameGrid[point_2[i][1]][point_2[i][0]] = colorNum;
					if (n == -7) // checking for the specific value for n that denotes a bomb
					{
						reachbottom = true;
					}
				}

				colorNum = (rand() % 7) + 1;

				n = rand() % 7;

				bombfall = rand() % 25;

				if (bombfall == 7) // random value for bomb generation
				{

					n = -7;

					bombposition = rand() % 10;

					for (int i = 0; i < 4; i++)
					{
						point_1[i][0] = 0 % 2;
						point_1[i][1] = 1 / 2;

						point_1[i][0] += bombposition; // setting a random x coordinate for the bomb
					}
				}
				else
				{
					int startX = 4; // example: middle of the grid
					int startY = 0; // starting from the top
					for (int i = 0; i < 4; i++)
					{
						point_1[i][0] = startX + (BLOCKS[n][i] % 2); // adjust horizontal position
						point_1[i][1] = startY + (BLOCKS[n][i] / 2); // adjust vertical position
					}
				}
				rotations = 0;
			}
			timer = 0;
		}
	}
}

// right left movement
void movement(int &delta_x)
{
	for (int i = 0; i < 4; i++)
	{
		point_1[i][0] += delta_x;
	}

	if (!anamoly()) // reverse the changes if shape is at the edge
	{
		for (int i = 0; i < 4; i++)
		{
			point_1[i][0] -= delta_x;
		}
	}
	delta_x = 0;
}

// rotation
void rotation(bool &rotate, int n, int &rotations)
{
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 2; b++)
		{
			temp[a][b] = point_1[a][b];
		}
	}

	if (rotate == true)
	{

		switch (n)
		{
		case 3: // for shape T
			switch (rotations)
			{
			case 0:
				point_1[0][0] -= 1;
				point_1[0][1] += 1;

				point_1[1][0] += 1;
				point_1[1][1] += 1;

				point_1[3][0] += 1;
				point_1[3][1] -= 1;
				break;
			case 1:
				point_1[0][0] += 1;
				point_1[0][1] += 1;

				point_1[1][0] += 1;
				point_1[1][1] -= 1;

				point_1[3][0] -= 1;
				point_1[3][1] -= 1;
				break;
			case 2:
				point_1[0][0] += 1;
				point_1[0][1] -= 1;

				point_1[1][0] -= 1;
				point_1[1][1] -= 1;

				point_1[3][0] -= 1;
				point_1[3][1] += 1;
				break;
			case 3:
				point_1[0][0] -= 1;
				point_1[0][1] -= 1;

				point_1[1][0] -= 1;
				point_1[1][1] += 1;

				point_1[3][0] += 1;
				point_1[3][1] += 1;
				rotations = -1;
				break;
			}
			break;

		case 1: // for shape J
			switch (rotations)
			{
			case 0:
				point_1[0][0] += 1;
				point_1[0][1] += 1;

				point_1[2][0] += 1;
				point_1[2][1] -= 1;

				point_1[3][0] += 2;
				point_1[3][1] -= 2;
				break;
			case 1:
				point_1[0][0] += 1;
				point_1[0][1] -= 1;

				point_1[2][0] -= 1;
				point_1[2][1] -= 1;

				point_1[3][0] -= 2;
				point_1[3][1] -= 2;
				break;
			case 2:
				point_1[0][0] -= 1;
				point_1[0][1] -= 1;

				point_1[2][0] -= 1;
				point_1[2][1] += 1;

				point_1[3][0] -= 2;
				point_1[3][1] += 2;
				break;
			case 3:
				point_1[0][0] -= 1;
				point_1[0][1] += 1;

				point_1[2][0] += 1;
				point_1[2][1] += 1;

				point_1[3][0] += 2;
				point_1[3][1] += 2;
				rotations = -1;
				break;
			}
			break;

		case 4: // for shape L
			switch (rotations)
			{
			case 0:
				point_1[0][0] -= 2;
				point_1[0][1] += 2;

				point_1[1][0] -= 1;
				point_1[1][1] += 1;

				point_1[3][0] -= 1;
				point_1[3][1] -= 1;
				break;
			case 1:
				point_1[0][0] += 2;
				point_1[0][1] += 2;

				point_1[1][0] += 1;
				point_1[1][1] += 1;

				point_1[3][0] -= 1;
				point_1[3][1] += 1;
				break;
			case 2:
				point_1[0][0] += 2;
				point_1[0][1] -= 2;

				point_1[1][0] += 1;
				point_1[1][1] -= 1;

				point_1[3][0] += 1;
				point_1[3][1] += 1;
				break;
			case 3:
				point_1[0][0] -= 2;
				point_1[0][1] -= 2;

				point_1[1][0] -= 1;
				point_1[1][1] -= 1;

				point_1[3][0] += 1;
				point_1[3][1] -= 1;
				rotations = -1;
				break;
			}
			break;

		case 6: // for shape S
			switch (rotations)
			{
			case 0:
				point_1[0][0] -= 1;
				point_1[0][1] += 1;

				point_1[2][0] -= 1;
				point_1[2][1] -= 1;

				point_1[3][1] -= 2;
				break;
			case 1:
				point_1[0][0] += 1;
				point_1[0][1] += 1;

				point_1[2][0] -= 1;
				point_1[2][1] += 1;

				point_1[3][0] -= 2;

				break;
			case 2:
				point_1[0][0] += 1;
				point_1[0][1] -= 1;

				point_1[2][0] += 1;
				point_1[2][1] += 1;

				point_1[3][1] += 2;
				break;
			case 3:
				point_1[0][0] -= 1;
				point_1[0][1] -= 1;

				point_1[2][0] += 1;
				point_1[2][1] -= 1;

				point_1[3][0] += 2;
				rotations = -1;
				break;
			}
			break;

		case 5:	   // for shape O
			break; // because O stays same no matter how many time it is rotated

		case 2: // for shape Z
			switch (rotations)
			{
			case 0:
				point_1[0][0] -= 1;
				point_1[0][1] += 1;

				point_1[1][0] += 1;
				point_1[1][1] += 1;

				point_1[3][0] += 2;
				break;
			case 1:
				point_1[0][0] += 1;
				point_1[0][1] += 1;

				point_1[1][0] += 1;
				point_1[1][1] -= 1;

				point_1[3][1] -= 2;
				break;
			case 2:
				point_1[0][0] += 1;
				point_1[0][1] -= 1;

				point_1[1][0] -= 1;
				point_1[1][1] -= 1;

				point_1[3][0] -= 2;
				break;
			case 3:
				point_1[0][0] -= 1;
				point_1[0][1] -= 1;

				point_1[1][0] -= 1;
				point_1[1][1] += 1;

				point_1[3][1] += 2;
				rotations = -1;
				break;
			}
			break;

		case 0: // for shape I
			switch (rotations)
			{
			case 0:
				point_1[0][0] -= 1;
				point_1[0][1] += 1;

				point_1[2][0] += 1;
				point_1[2][1] -= 1;

				point_1[3][0] += 2;
				point_1[3][1] -= 2;
				break;
			case 1:
				point_1[0][0] += 1;
				point_1[0][1] += 1;

				point_1[2][0] -= 1;
				point_1[2][1] -= 1;

				point_1[3][0] -= 2;
				point_1[3][1] -= 2;
				break;
			case 2:
				point_1[0][0] += 1;
				point_1[0][1] -= 1;

				point_1[2][0] -= 1;
				point_1[2][1] += 1;

				point_1[3][0] -= 2;
				point_1[3][1] += 2;
				break;
			case 3:
				point_1[0][0] -= 1;
				point_1[0][1] -= 1;

				point_1[2][0] += 1;
				point_1[2][1] += 1;

				point_1[3][0] += 2;
				point_1[3][1] += 2;
				rotations = -1;
				break;
			}
			break;
		}
		if (!anamoly()) // return to previous value if not anamoly
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					point_1[i][j] = temp[i][j];
				}
			}
			rotations--;
		}

		rotations++;
		rotate = false;
	}
}

// ROW removing
void rowremove()
{
	bool rowfilled = true;

	for (int a = 0; a < M; a++)
	{
		rowfilled = true;
		for (int b = 0; b < N; b++)
		{
			if (gameGrid[a][b] < 1 || gameGrid[a][b] > 7) // row has an empty element
			{
				rowfilled = false;
				break;
			}
		}
		if (rowfilled == true) // checking wheter any row has been removed
		{
			rowsremoved++; // number of rows removed
			for (int k = a; k > 0; k--)
			{
				for (int c = 0; c < N; c++)
				{
					if (gameGrid[k][c] >= 1 || gameGrid[k][c] <= 7)
					{
						gameGrid[k][c] = gameGrid[k - 1][c]; // shifting the elements down
						gameGrid[k - 1][c] = 0;
					} // then deleting their previous location
				}
			}
		}
	}

} // end of removeline function

void bomb()
{
	int positiony = 0; // the row number(y-coordinate) where the bomb lands

	if (reachbottom == true) // only start checking when the bomb has stopped moving
	{
		for (int i = 0; i < M; i++)
		{
			if (gameGrid[i][bombposition] >= 1 && gameGrid[i][bombposition] <= 7)
			{
				positiony = i;
				break;
			}
		}

		// box below the box has same colour
		if ((gameGrid[positiony][bombposition] == gameGrid[positiony + 1][bombposition]) && positiony != (M - 1))
		{
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					gameGrid[i][j] = 0;
				}
			}
			reachbottom = false;
		}

		// box below the bomb has different colour
		else if ((gameGrid[positiony][bombposition] != gameGrid[positiony + 1][bombposition]) && positiony != (M - 1))
		{
			gameGrid[positiony][bombposition] = gameGrid[positiony + 1][bombposition] = gameGrid[positiony + 2][bombposition] = gameGrid[positiony + 1][bombposition + 1] = gameGrid[positiony + 2][bombposition + 1] = 0;
			reachbottom = false;
		}

		// box has fallen to the last line
		else if (positiony == (M - 1))
		{
			gameGrid[positiony][bombposition] = 0;
			reachbottom = false;
		}
	}

} // end of bomb function

void gameover()
{
	for (int i = 0; i < 10; i++)
	{
		if (gameGrid[0][i] >= 1 && gameGrid[0][i] <= 7)
		{
			exitgame = true;
			std::cout << "Your score is: " << t_score << std::endl;
		}
	}

} // end of gameover function

bool shadow_anamoly()
{ // checking for anamoly of shadow just like point_1's anamoly
	for (int i = 0; i < 4; i++)
		if (shadow[i][0] < 0 || shadow[i][0] >= N || shadow[i][1] >= M)
			return 0;
		else if (gameGrid[shadow[i][1]][shadow[i][0]])
			return 0;
	return 1;
};

void showing_shadow()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			shadow[i][j] = point_1[i][j];
		}
	}

	while (shadow_anamoly())
	{
		for (int i = 0; i < 4; i++)
		{
			shadow[i][1] += 1;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		shadow[i][1] -= 1;
	}
}

void hardfall()
{
	while (anamoly())
	{
		for (int i = 0; i < 4; i++)
		{
			point_2[i][0] = point_1[i][0];
			point_2[i][1] = point_1[i][1];
			point_1[i][1] += 1;
		}
	}
	for (int i = 0; i < 4; i++)
	{ // to stop losing the bottom block(s)
		point_2[i][0] = point_1[i][0];
		point_2[i][1] = point_1[i][1];
		point_1[i][1] -= 1;
	}
}

void score()
{
	switch (rowsremoved)
	{
	case 1:
		t_score += 10 * level;
		break;
	case 2:
		t_score += 30 * level;
		break;
	case 3:
		t_score += 60 * level;
		break;
	case 4:
		t_score += 100 * level;
		break;
	}
	rowsremoved = 0; // resetting the number of rows removed
}

// increasing difficulty
void difficulty()
{
	static int difficultyincrease = 0;
	if (time_min > 5)
	{
		switch (difficultyincrease)
		{
		case 0:
			delayval = 0.25;
			newN--;
			level = 2;
			difficultyincrease++;
			break;
		case 2:
		case 3:
		case 4:
		case 5:
			newN--;
			delayval -= 0.05;
			break;
		}

		t_time = 0; // time is reset so that after next 5min difficulty can be increased again
		time_min = 0;
	}
}

void newgame(float &timer, float &delay)
{
    timer = 0;          // Reset timer
    delay = 0.3;        // Reset delay value
    level = 1;          // Reset game level
    t_score = 0;        // Reset score

    // Reset game grid to empty
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            gameGrid[i][j] = 0;
        }
    }

    // Reset piece coordinates (point_1 holds the blocks' positions)
    int startX = 4;  // You can place the piece in the middle of the grid horizontally
    int startY = 0;  // Reset the falling piece to start at the top of the grid
    int n = rand() % 7;  // Randomly select a new piece type

    // Adjust the positions of the piece based on the new starting position (startX, startY)
    for (int i = 0; i < 4; i++) {
        point_1[i][0] = startX + (BLOCKS[n][i] % 2);  // Adjust horizontal position
        point_1[i][1] = startY + (BLOCKS[n][i] / 2);  // Adjust vertical position
    }

}

