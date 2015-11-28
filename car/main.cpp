#include <iostream>
#include <unistd.h>
#include <time.h>

using namespace std;

const int cols = 4;
const int rows = 10;
char matrix[rows][cols];
int enemieX = 1, enemieY = 0;
int posX = 2, posY = rows - 2;
int score = 0;
unsigned int sleepTime  = 50000;

void init(){
    for(int i= 0; i < rows; i++){
        for(int j = 0; j < cols;  j++){
          matrix[i][j] = '|';
        }
    }
}


void draw(){
    system("clear");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if((i > 0 && i < rows - 1) && (j > 0 && j < cols - 1)){
                if(i == posY && j == posX)
                    cout << "M";
                else if (i == enemieY && j == enemieX)
                    cout << "W";
                else if (enemieY == posY && enemieX == posX){
                    cout << " ";
                }
                else
                    cout << " ";
               }
            else{
                cout << matrix[i][j];
            }
       }
        cout << endl;
    }
}

void randomEnemie()
{
    srand(time(NULL));
    enemieX = 1 + (rand() % 2);
}

void updateScore(){
    cout << "Score is: " << score << endl;
}

void sleep(){
    int level = sleepTime - (score * 500);
    if(level < 50000)
        sleepTime = 200000;
    usleep(level);

}

int main(){
    init();
    while(playGame){

        draw();
        enemieY += 1;

        if ((enemieX == 1) && (enemieY + 1 == posY))
            posX = 2;
        if ((enemieX == 2) && (enemieY + 1 == posY))
            posX = 1;

        if(enemieY > rows - 1){
            enemieY = 1;
            randomEnemie();
            score += 1;
        }
        updateScore();
        sleep();

    }
    return 0;
}
