// ShahmeerAhmed
int temp[4][2];
int shadow[4][2];

int next2[4][2];
int next3[4][2];
int next4[4][2];
int n4 = 0;
int n3 = 0;
int n2 = 0;

int t_score = 0;
int level = 1;
int rowsremoved = 0;
float t_time = 0;
float delayval = 0.3;
int newN = 10;
int time_min;

int BLOCKS[7][4];
void shape()
{ // I
    BLOCKS[0][0] = 1;
    BLOCKS[0][1] = 3;
    BLOCKS[0][2] = 5;
    BLOCKS[0][3] = 7;

    // J
    BLOCKS[1][0] = 0;
    BLOCKS[1][1] = 1;
    BLOCKS[1][2] = 3;
    BLOCKS[1][3] = 5;

    // Z
    BLOCKS[2][0] = 1;
    BLOCKS[2][1] = 2;
    BLOCKS[2][2] = 3;
    BLOCKS[2][3] = 4;

    // T
    BLOCKS[3][0] = 1;
    BLOCKS[3][1] = 2;
    BLOCKS[3][2] = 3;
    BLOCKS[3][3] = 5;

    // L
    BLOCKS[4][0] = 0;
    BLOCKS[4][1] = 2;
    BLOCKS[4][2] = 4;
    BLOCKS[4][3] = 5;

    // O
    BLOCKS[5][0] = 0;
    BLOCKS[5][1] = 1;
    BLOCKS[5][2] = 2;
    BLOCKS[5][3] = 3;

    // S
    BLOCKS[6][0] = 0;
    BLOCKS[6][1] = 2;
    BLOCKS[6][2] = 3;
    BLOCKS[6][3] = 5;
}
