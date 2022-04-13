#include <deque>
#include <iostream>
#pragma once

class Lane
{
private:
   
    std::deque <bool> cars;
    bool right;
public:

    Lane(int width);
    void move();
    bool checkPosition(int pos);

};

