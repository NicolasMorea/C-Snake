#pragma once
#include <vector>
#include "playboard.h"
#include <algorithm>

class Snake{
    friend void play_game();
    std::vector<int> body;

    public :
    //Snake(std::vector<SnakePart> &snakeBody) : body(snakeBody){}
    
    Snake(int head, int tail1, int tail2) {
        body.push_back((head));
        body.push_back((tail1));
        body.push_back((tail2));
    }
    int GetPos(int i){
        if(i <= body.size()){
            return body[i];
        }
        return -1;
    }
    int GetPosI(int i){
        if(i <= body.size()){
            return (body[i] - body[i]%columns) / columns;
        }
        return -1;
    }
    int GetPosJ(int i){
        if(i <= body.size()){
            return body[i]%columns;
        }
        return -1;
    }
    void RemoveTail(){
        body.pop_back();
    }
    int Size(){
        return body.size();
    }
    void AddHead(int pos){
        body.insert(body.begin(), pos);
    }
    bool CheckSnakeAt(int pos){
        return std::find(body.begin(), body.end(), pos) != body.end();
    }
};