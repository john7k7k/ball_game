#include "Object.hpp"

void Game::run(){
    while(!this->is_end){
        for(int i = 0; i < level_num;i++){
            this->runLevel(levelArray[i]);
        }
    }
}

Game::Game(){
    window.create(VideoMode(1200,600),L"ball");
    window.setFramerateLimit(60);
    is_end = 0;
    level_num = 3;
    
    //data0
        //rect
        data[0].rect1.set(Vector2f(30,30),Vector2f(20,280),Color :: Red,4);
        //ball
        data[0].ballNum = 16;
        for(int i = 0;i < 8;i++)
            data[0].ballArray[2*i].set(Vector2f(200+100*i,5),Color :: Blue,10,6,Vector2f(200+100*i,5),Vector2f(200+100*i,575));
        for(int i = 0;i < 8;i++)
            data[0].ballArray[2*i+1].set(Vector2f(250+100*i,575),Color :: Blue,10,6,Vector2f(250+100*i,575),Vector2f(250+100*i,5));
        //wall
        data[0].wallNum = 7;
        data[0].wallArray[0].set(Vector2f(5,600),Vector2f(0,0));
        data[0].wallArray[1].set(Vector2f(1200,5),Vector2f(0,0));
        data[0].wallArray[2].set(Vector2f(5,600),Vector2f(1195,0));
        data[0].wallArray[3].set(Vector2f(1200,5),Vector2f(0,595));
        //win0Area
        data[0].win.set(Vector2f(205,600),Vector2f(990,0),Color::Green);
    //data1
        //rect
        data[1].rect1.set(Vector2f(30,30),Vector2f(20,280),Color :: Red,4);
        //ball
        data[1].ballNum = 16;
        for(int i = 0;i < 8;i++)
            data[1].ballArray[2*i].set(Vector2f(200+100*i,5),Color :: Blue,10,9,Vector2f(200+100*i,5),Vector2f(200+100*i,575));
        for(int i = 0;i < 8;i++)
            data[1].ballArray[2*i+1].set(Vector2f(250+100*i,575),Color :: Blue,10,9,Vector2f(250+100*i,575),Vector2f(250+100*i,5));
        //wall
        data[1].wallNum = 7;
        data[1].wallArray[0].set(Vector2f(5,600),Vector2f(0,0));
        data[1].wallArray[1].set(Vector2f(1200,5),Vector2f(0,0));
        data[1].wallArray[2].set(Vector2f(5,600),Vector2f(1195,0));
        data[1].wallArray[3].set(Vector2f(1200,5),Vector2f(0,595));
        data[1].wallArray[4].set(Vector2f(20,500),Vector2f(180,100));
        data[1].wallArray[5].set(Vector2f(20,500),Vector2f(575,0));
        data[1].wallArray[6].set(Vector2f(20,500),Vector2f(970,100));
        //winArea
        data[1].win.set(Vector2f(205,100),Vector2f(990,500),Color::Green);
    //data2
        //rect
        data[2].rect1.set(Vector2f(30,30),Vector2f(20,280),Color :: Red,4);
  
        //ball
        data[2].ballNum = 12;
        data[2].ballArray[0].set(Vector2f(200,5),Color :: Blue,10,9,Vector2f(360,5),Vector2f(360,575));
        data[2].ballArray[1].set(Vector2f(250,575),Color :: Blue,10,9,Vector2f(410,575),Vector2f(410,5));
        data[2].ballArray[2].set(Vector2f(200,5),Color :: Blue,10,9,Vector2f(460,5),Vector2f(460,575));
        data[2].ballArray[3].set(Vector2f(250,575),Color :: Blue,10,9,Vector2f(510,575),Vector2f(510,5));
        data[2].ballArray[4].set(Vector2f(200,5),Color :: Blue,10,9,Vector2f(560,5),Vector2f(560,575));
        data[2].ballArray[5].set(Vector2f(250,575),Color :: Blue,10,9,Vector2f(610,575),Vector2f(610,5));
        data[2].ballArray[6].set(Vector2f(200,5),Color :: Blue,10,9,Vector2f(660,5),Vector2f(660,575));
        data[2].ballArray[7].set(Vector2f(250,575),Color :: Blue,10,9,Vector2f(710,575),Vector2f(710,5));
        data[2].ballArray[8].set(Vector2f(200,5),Color :: Blue,10,9,Vector2f(760,5),Vector2f(760,575));
        data[2].ballArray[9].set(Vector2f(250,575),Color :: Blue,10,9,Vector2f(810,575),Vector2f(810,5));
        data[2].ballArray[10].set(Vector2f(200,5),Color :: Blue,10,9,Vector2f(860,5),Vector2f(860,575));
        data[2].ballArray[11].set(Vector2f(250,575),Color :: Blue,10,9,Vector2f(910,575),Vector2f(910,5));
        //wall
        data[2].wallNum = 10;
        data[2].wallArray[0].set(Vector2f(5,600),Vector2f(0,0));
        data[2].wallArray[1].set(Vector2f(1200,5),Vector2f(0,0));
        data[2].wallArray[2].set(Vector2f(5,600),Vector2f(1195,0));
        data[2].wallArray[3].set(Vector2f(1200,5),Vector2f(0,595));
        data[2].wallArray[4].set(Vector2f(20,175),Vector2f(300,0));
        data[2].wallArray[5].set(Vector2f(20,100),Vector2f(300,250));
        data[2].wallArray[6].set(Vector2f(20,175),Vector2f(300,425));
        data[2].wallArray[7].set(Vector2f(20,350),Vector2f(630,125));
        data[2].wallArray[8].set(Vector2f(300,200),Vector2f(930,0));
        data[2].wallArray[9].set(Vector2f(300,200),Vector2f(930,400));
        //winArea
        data[2].win.set(Vector2f(300,200),Vector2f(930,200),Color::Green);
    for(int i = 0;i < level_num;i++) levelArray[i].set(&data[i]);
}
