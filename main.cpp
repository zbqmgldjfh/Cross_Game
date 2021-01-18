#include <iostream>
#include <deque>
#include <vector>
#include <conio.h>

using namespace std;

class cPlayer {
public:
    int x, y;
    cPlayer(int width) { x = width / 2; y = 0; } // 위치는 위쪽중앙에서 시작
};

class cLane {
private:
    deque<bool> cars;// lane을 연속의 dot로 표현할것, dot는 true, false로 결정
public:
    cLane(int width)
    {
        for (int i(0); i < width; i++)
            cars.push_front(true); // deque는 앞뒤에서 추출가능, flase는 차가 없는 상태
    }

    void Move() // 핵심 자동차 움직이기
    {
        if (rand() % 10 == 1) // 생성한 렌덤수가 1이면 mave car
            cars.push_front(true);
        else
            cars.push_front(false);
    }
    // 000100이면 cars[3]은 true
    bool CheckPos(int pos) { return cars[pos]; } // car의 위치 

};

class cGame {
private:
    bool quit;
    int numberOfLanes;
    int width;
    int score;
    cPlayer* player;
    vector<cLane*> map;

public:
    cGame(int w = 20, int h = 20) // 초기화 
    {
        numberOfLanes = h;
        width = w;
        quit = false;
        for(int i = 0; i < numberOfLanes; i++) // 화면그리기 
        {
            map.push_back(new cLane(width));
        }
        player = new cPlayer(width); 
    }

    void Draw()
    {
        system("cls");
        for(int i(0); i < numberOfLanes; i++)
        {
            for(int j(0); j < width; j++) // X축이라 생각하자
            {   // 첫줄과 마지막줄은 장애물 없음
                if(map[i]->CheckPos(j) && i != 0 && i != numberOfLanes - 1) // 위치에서 true라면
                    cout << "#";
                else if(player->x == j && player->y == i) // plaer 위치
                    cout << "V";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }

    void Input()
    {
        if(_kbhit()) // 방향조절 (왼쪽모서리가 원점)
        {
            char current = _getch();
            if(current == 'a') // 왼쪽으로
                player->x--;
            if(current == 'd') // 오른쪽으로 
                player->x++;
            if(current == 'w') // 위로
                player->y--;
            if(current == 's') // 아래로
                player->y++;
            if(current == 'q')
                quit = true; // 종료
        }
    }

    void Logic()
    { // 1번 line부터, 0번은 무시 시작지점임
        for(int i(1); i < numberOfLanes - 1; i++)
        {
            if(rand() % 10 == 1)
                map[i]->Move();
            if(map[i]->CheckPos(player->x) && player->y == i) // 장애물에 닿을시 게임종료
                quit = true;
        }
    }

    void Run()
    {
        while (!quit)
        {
            Input();
            Draw();
            Logic();
        }
    }
};

int main()
{
    cGame game(30, 5);
    game.Run();

    getchar;
    return 0;
}