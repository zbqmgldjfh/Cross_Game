#include <iostream>
#include <deque>

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
            cars.push_front(false); // deque는 앞뒤에서 추출가능, flase는 차가 없는 상태
    }

    void Move() // 자동차 움직이기
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
public:
    void Draw()
    {

    }

    void Input()
    {

    }

    void Logic()
    {

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
    cLane lane1(20);
    for (int i = 0; i < 20; i++)
    {
        if (lane1.CheckPos(i))
            cout << "#";
        else
            cout << "0";
    }
    lane1.Move();
    cout << endl;
    for (int i = 0; i < 20; i++)
    {
        if (lane1.CheckPos(i))
            cout << "#";
        else
            cout << "0";
    }
    lane1.Move();
    lane1.Move();
    lane1.Move();
    lane1.Move();
    cout << endl;
    for (int i = 0; i < 20; i++)
    {
        if (lane1.CheckPos(i))
            cout << "#";
        else
            cout << "0";
    }

    getchar;
    return 0;
}