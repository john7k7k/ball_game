#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;

class WinArea:public RectangleShape{
    public:
        WinArea(){
            this->setFillColor(Color :: Green);
            this->setPosition(Vector2f(0,0));
            this->setSize(Vector2f(0,0));
            this->up_cornor();
        }
        WinArea(Vector2f in_size,Vector2f in_pos,Color in_color){
            this->setFillColor(in_color);
            this->setPosition(in_pos);
            this->setSize(in_size);
            this->up_cornor();
        }
        void set(Vector2f in_size,Vector2f in_pos,Color in_color){
            this->setFillColor(in_color);
            this->setPosition(in_pos);
            this->setSize(in_size);
            this->up_cornor();
        }
        Vector2f& getCornorLU(){return cornorLU;}
        Vector2f& getCornorRU(){return cornorRU;}
        Vector2f& getCornorLD(){return cornorLD;}
        Vector2f& getCornorRD(){return cornorRD;}
    private:
        void up_cornor(){
            cornorLU = this->getPosition();
            cornorRU = this->getPosition() + Vector2f(this->getSize().x,0);
            cornorLD = this->getPosition() + Vector2f(0,this->getSize().y);
            cornorRD = this->getPosition() + Vector2f(this->getSize().x,this->getSize().y);
        };
        Vector2f cornorLU;
        Vector2f cornorRU;
        Vector2f cornorLD;
        Vector2f cornorRD;
};

class Wall:public RectangleShape{
    public:
        Wall(){}
        Wall(Vector2f in_size,Vector2f in_pos,Color in_color = Color :: Black){
            this->setFillColor(in_color);
            this->setPosition(in_pos);
            this->setSize(in_size);
            this->up_cornor();
        }
        void set(Vector2f in_size,Vector2f in_pos,Color in_color = Color :: Black){
            this->setFillColor(in_color);
            this->setPosition(in_pos);
            this->setSize(in_size);
            this->up_cornor();
        }
        Vector2f& getCornorLU(){return cornorLU;}
        Vector2f& getCornorRU(){return cornorRU;}
        Vector2f& getCornorLD(){return cornorLD;}
        Vector2f& getCornorRD(){return cornorRD;}
    private:
        void up_cornor(){
            cornorLU = this->getPosition();
            cornorRU = this->getPosition() + Vector2f(this->getSize().x,0);
            cornorLD = this->getPosition() + Vector2f(0,this->getSize().y);
            cornorRD = this->getPosition() + Vector2f(this->getSize().x,this->getSize().y);
        }
        Vector2f cornorLU;
        Vector2f cornorRU;
        Vector2f cornorLD;
        Vector2f cornorRD;
};

class Ball : public CircleShape{
    public:
        Ball(){
            this->setPosition(Vector2f(0,0));
            this->setFillColor(Color :: White);
            this->setRadius(0);
            this->speed = 0;
            this->canMoving = 1;
            this->up_cornor();
            this->ck_pos = 1;
            this->di = 1;
        }
        Ball(Vector2f in_pos,Color in_color,float in_radius,float in_speed,Vector2f stPos = Vector2f(0,0),Vector2f endPos = Vector2f(0,0)){
            this->setPosition(in_pos);
            this->setFillColor(in_color);
            this->setRadius(in_radius);
            this->speed = in_speed;
            this->canMoving = 1;
            this->up_cornor();
            this->st_pos = stPos;
            this->end_pos = endPos;
        }
        void set(Vector2f in_pos,Color in_color,float in_radius,float in_speed,Vector2f stPos = Vector2f(0,0),Vector2f endPos = Vector2f(0,0)){
            this->setPosition(in_pos);
            this->setFillColor(in_color);
            this->setRadius(in_radius);
            this->speed = in_speed;
            this->canMoving = 1;
            this->up_cornor();
            this->st_pos = stPos;
            this->end_pos = endPos;
        }
        Vector2f move(Vector2f dis){
            this->setPosition(this->getPosition() + dis);
            this->up_cornor();
            return this->getPosition();
        }
        Vector2f move(String dir){
            if(dir == "up"){
                for(int i = 1;i <= speed;i++)
                    this->move(Vector2f(0,-speed));
            }
            else if(dir == "right"){
                for(int i = 1;i <= speed;i++)
                    this->move(Vector2f(speed,0));
            }
            else if(dir == "down"){
                for(int i = 1;i <= speed;i++)
                    this->move(Vector2f(0,speed));
            }
            else if(dir == "left"){
                for(int i = 1;i <= speed;i++)
                  this->move(Vector2f(-speed,0));
            }
            return this->getPosition();
        }
        void moving(Vector2f st_pos,Vector2f end_pos,float in_speed){
            if(canMoving){
                if(this->ck_pos){
                    this->setPosition(st_pos);
                    this->ck_pos = 0;
                }
                Vector2f velocity = (end_pos - st_pos);
                velocity.x = velocity.x*(in_speed/sqrt(pow(velocity.x,2) + pow(velocity.y,2)));
                velocity.y = velocity.y*(in_speed/sqrt(pow(velocity.x,2) + pow(velocity.y,2)));
                if(end_pos.x - st_pos.x >= 0 && end_pos.y - st_pos.y >= 0){
                    if(this->getPosition().y - end_pos.y > 0 || this->getPosition().y - st_pos.y < 0 || this->getPosition().x - end_pos.x > 0 || this->getPosition().x - st_pos.x < 0){
                        this->di = -this->di;
                    }
                }else if(end_pos.x - st_pos.x < 0 && end_pos.y - st_pos.y >= 0){
                    if(this->getPosition().y - end_pos.y > 0 || this->getPosition().y - st_pos.y < 0 || this->getPosition().x - end_pos.x < 0 || this->getPosition().x - st_pos.x > 0){
                        this->di = -this->di;
                    }
                }else if(end_pos.x - st_pos.x >= 0 && end_pos.y - st_pos.y < 0){
                    if(this->getPosition().y - end_pos.y < 0 || this->getPosition().y - st_pos.y > 0 || this->getPosition().x - end_pos.x > 0 || this->getPosition().x - st_pos.x < 0){
                        this->di = -this->di;
                    }
                }else if(end_pos.x - st_pos.x < 0 && end_pos.y - st_pos.y < 0){
                    if(this->getPosition().y - end_pos.y < 0 || this->getPosition().y - st_pos.y > 0 || this->getPosition().x - end_pos.x < 0 || this->getPosition().x - st_pos.x > 0){
                        this->di = -this->di;
                    }
                }
                for(int i = 1;i <= sqrt(pow(velocity.x,2) + pow(velocity.y,2));i++)
                    this->move(Vector2f(this->di*velocity.x*(1/sqrt(pow(velocity.x,2) + pow(velocity.y,2))),this->di*velocity.y*(1/sqrt(pow(velocity.x,2) + pow(velocity.y,2)))));
            }
        }
        void moving(Vector2f stPos,Vector2f endPos){
            this->moving(stPos,endPos,this->speed);
        }
        void moving(){
            this->moving(st_pos,end_pos,this->speed);
        }
        void circleMoving(Vector2f stPos,Vector2f in_center,float in_radSpeed){
            if(canMoving){
                if(this->ck_pos){
                    this->setPosition(stPos);
                    this->ck_pos = 0;
                }
            }
        }
        void stopMoving(){
            this->canMoving = 0;
        }
        void startMoving(){
            this->canMoving = 1;
        }
        float& getSpeed(){return speed;}
        void setSpeed(float in_speed){speed = in_speed;}
        Vector2f& getCornorLU(){return cornorLU;}
        Vector2f& getCornorRU(){return cornorRU;}
        Vector2f& getCornorLD(){return cornorLD;}
        Vector2f& getCornorRD(){return cornorRD;}
        Vector2f& getStPos(){return st_pos;}
        Vector2f& getEndPos(){return end_pos;}
    private:
        bool ck_pos;
        int di;
        Vector2f end_pos;
        Vector2f st_pos;
        float speed;
        float center;
        float radius_speed;
        bool canMoving;
        void up_cornor(){
            cornorLU = this->getPosition();
            cornorRU = this->getPosition() + Vector2f(2 * this->getRadius(),0);
            cornorLD = this->getPosition() + Vector2f(0,2 * this->getRadius());
            cornorRD = this->getPosition() + Vector2f(2 * this->getRadius(),2 * this->getRadius());
        }
        Vector2f cornorLU;
        Vector2f cornorRU;
        Vector2f cornorLD;
        Vector2f cornorRD;
};

class Rec : public RectangleShape{
    public:
        Rec(){
            this->const_speed = 0;
            this->speed = 0;
            this->setFillColor(Color :: White);
            this->setPosition (Vector2f(0,0)) ;
            this->setSize(Vector2f(0,0));
            this->direction = "";
            this->isMovingUp = 0;
            this->isMovingRight = 0;
            this->isMovingLeft = 0;
            this->isMovingDown = 0;
            this->touchUp = 0;
            this->touchDown = 0 ;
            this->touchRight = 0;
            this->touchLeft = 0;
        }
        Rec(Vector2f in_size,Vector2f in_pos,Color in_color,float in_speed){
            this->const_speed = in_speed;
            this->speed = 0;
            this->setPosition(in_pos);
            this->setFillColor(in_color);
            this->setSize(in_size);
            this->direction = "";
            this->isMovingUp = 0;
            this->isMovingRight = 0;
            this->isMovingLeft = 0;
            this->isMovingDown = 0;
            this->touchUp = 0;
            this->touchDown = 0 ;
            this->touchRight = 0;
            this->touchLeft = 0;
        }
        void set(Vector2f in_size,Vector2f in_pos,Color in_color,float in_speed){
            this->const_speed = in_speed;
            this->speed = 0;
            this->setPos(in_pos);
            this->setFillColor(in_color);
            this->setSize(in_size);
            this->direction = "";
            this->isMovingUp = 0;
            this->isMovingRight = 0;
            this->isMovingLeft = 0;
            this->isMovingDown = 0;
            this->touchUp = 0;
            this->touchDown = 0 ;
            this->touchRight = 0;
            this->touchLeft = 0;
        }
        void setPos(Vector2f in_pos){
            this->setPosition(in_pos);
            up_cornor();
        }
        Vector2f move(Vector2f dis){
            this->setPosition(this->getPosition() + dis);
            this->up_cornor();
            return this->getPosition();
        }
        Vector2f move(String dir){
            if(dir == "up"){
                for(int i = 1;i <= const_speed;i++)
                this->move(Vector2f(0,-1));
            }
            else if(dir == "right"){
                for(int i = 1;i <= const_speed;i++)
                this->move(Vector2f(1,0));
            }
            else if(dir == "down"){
                for(int i = 1;i <= const_speed;i++)
                this->move(Vector2f(0,1));
            }
            else if(dir == "left"){
                for(int i = 1;i <= const_speed;i++)
                this->move(Vector2f(-1,0));
            }
            return this->getPosition();
        }
        Vector2f moving(){
            if(direction == "up"){
                this->move(Vector2f(0,-speed));
                this->isMovingUp = 1;
            }
            else if(direction == "right"){
                this->move(Vector2f(speed,0));
                this->isMovingRight = 1;
            }
            else if(direction == "down"){
                this->move(Vector2f(0,speed));
                this->isMovingDown = 1;
            }
            else if(direction == "left"){
                this->move(Vector2f(-speed,0));
                this->isMovingLeft = 1;
            }
        }
        Vector2f movingTo(Wall* in_wall,int num){
            if(direction == "up"){
                for(int i = 1;i <= speed;i++){
                    if(!this->isTouchUp(in_wall,num))
                        this->move(Vector2f(0,-1));
                }
                this->isMovingUp = 1;
            }
            else if(direction == "right"){
                for(int i = 1;i <= speed;i++){
                    if(!this->isTouchRight(in_wall,num))
                        this->move(Vector2f(1,0));
                }
                this->isMovingRight = 1;
            }
            else if(direction == "down"){
                for(int i = 1;i <= speed;i++){
                    if(!this->isTouchDown(in_wall,num))
                        this->move(Vector2f(0,1));
                }
                this->isMovingDown = 1;
            }
            else if(direction == "left"){
                for(int i = 1;i <= speed;i++){
                    if(!this->isTouchLeft(in_wall,num))
                        this->move(Vector2f(-1,0));
                }
                this->isMovingLeft = 1;
            }
        }
        void startMoving(String dir){
            this->speed = const_speed;
            this->direction = dir;
        }
        void startMoving(String dir,float in_speed){
            this->speed = in_speed;
            this->direction = dir;
        }
        void stopMoving(){
            this->speed = 0;
            this->direction = "";
            this->isMovingUp = 0;
            this->isMovingRight = 0;
            this->isMovingLeft = 0;
            this->isMovingDown = 0;
        }

        bool& getIsMoving(String di){
            if(di == "up"){return this->isMovingUp;}
            else if(di == "down"){return this->isMovingDown;}
            else if(di == "right"){return this->isMovingRight;}
            else if(di == "left"){return this->isMovingLeft;}
        }
        bool isTouchUp(Wall in_wall){
            if((this->cornorLU.y <= in_wall.getCornorLD().y && this->cornorLU.y >= in_wall.getCornorLU().y) && (((this->cornorLD.x > in_wall.getCornorLD().x)&&(this->cornorLD.x < in_wall.getCornorRD().x))||((this->cornorRD.x < in_wall.getCornorRD().x)&&(this->cornorRD.x > in_wall.getCornorLD().x))||((this->cornorRD.x > in_wall.getCornorRD().x)&&(this->cornorLD.x < in_wall.getCornorRD().x))))
                return 1;
            else return 0;
        }
        bool isTouchLeft(Wall in_wall){
            if((this->cornorLU.x <= in_wall.getCornorRD().x && this->cornorLU.x >= in_wall.getCornorLD().x) && (((this->cornorLD.y > in_wall.getCornorLU().y)&&(this->cornorLD.y < in_wall.getCornorRD().y))||((this->cornorRU.y < in_wall.getCornorRD().y)&&(this->cornorRU.y > in_wall.getCornorLU().y))||((this->cornorRD.y > in_wall.getCornorRD().y)&&(this->cornorLU.y < in_wall.getCornorRD().y))))
                return 1;
            else return 0;
        }
        bool isTouchDown(Wall in_wall){
            if((this->cornorLD.y >= in_wall.getCornorLU().y && this->cornorLD.y <= in_wall.getCornorLD().y) && (((this->cornorLD.x > in_wall.getCornorLD().x)&&(this->cornorLD.x < in_wall.getCornorRD().x))||((this->cornorRD.x < in_wall.getCornorRD().x)&&(this->cornorRD.x > in_wall.getCornorLD().x))||((this->cornorRD.x > in_wall.getCornorRD().x)&&(this->cornorLD.x < in_wall.getCornorRD().x))))
                return 1;
            else return 0;
        }
        bool isTouchRight(Wall in_wall){
            if((this->cornorRD.x >= in_wall.getCornorLD().x && this->cornorRD.x <= in_wall.getCornorRD().x) && (((this->cornorLD.y > in_wall.getCornorLU().y)&&(this->cornorLD.y < in_wall.getCornorRD().y))||((this->cornorRU.y < in_wall.getCornorRD().y)&&(this->cornorRU.y > in_wall.getCornorLU().y))||((this->cornorRD.y > in_wall.getCornorRD().y)&&(this->cornorLU.y < in_wall.getCornorRD().y))))
                return 1;
            else return 0;
        }
        bool isTouchUp(Wall* in_wall,int num){
            this->touchUp= 0;
            for(int i = 0;i < num;i++){
                if(this->isTouchUp(in_wall[i])) this->touchUp = 1;
            }
            return this->touchUp;
        }
        bool isTouchDown(Wall* in_wall,int num){
            this->touchDown= 0;
            for(int i = 0;i < num;i++){
                if(this->isTouchDown(in_wall[i])) this->touchDown = 1;
            }
            return this->touchDown;
        }
        bool isTouchRight(Wall* in_wall,int num){
            this->touchRight= 0;
            for(int i = 0;i < num;i++){
                if(this->isTouchRight(in_wall[i])) this->touchRight = 1;
            }
            return this->touchRight;
        }
        bool isTouchLeft(Wall* in_wall,int num){
            this->touchLeft = 0;
            for(int i = 0;i < num;i++){
                if(this->isTouchLeft(in_wall[i])) this->touchLeft = 1;
            }
            return this->touchLeft;
        }
        bool isTouch(Ball in_ball){
            if(((this->cornorLU.y <= in_ball.getCornorLD().y && this->cornorLU.y >= in_ball.getCornorLU().y) && (((this->cornorLD.x > in_ball.getCornorLD().x)&&(this->cornorLD.x < in_ball.getCornorRD().x))||((this->cornorRD.x < in_ball.getCornorRD().x)&&(this->cornorRD.x > in_ball.getCornorLD().x))||((this->cornorRD.x > in_ball.getCornorRD().x)&&(this->cornorLD.x < in_ball.getCornorRD().x)))) || (this->cornorLU.x <= in_ball.getCornorRD().x && this->cornorLU.x >= in_ball.getCornorLD().x) && (((this->cornorLD.y > in_ball.getCornorLU().y)&&(this->cornorLD.y < in_ball.getCornorRD().y))||((this->cornorRU.y < in_ball.getCornorRD().y)&&(this->cornorRU.y > in_ball.getCornorLU().y))||((this->cornorRD.y > in_ball.getCornorRD().y)&&(this->cornorLU.y < in_ball.getCornorRD().y))) || (this->cornorLD.y >= in_ball.getCornorLU().y && this->cornorLD.y <= in_ball.getCornorLD().y) && (((this->cornorLD.x > in_ball.getCornorLD().x)&&(this->cornorLD.x < in_ball.getCornorRD().x))||((this->cornorRD.x < in_ball.getCornorRD().x)&&(this->cornorRD.x > in_ball.getCornorLD().x))||((this->cornorRD.x > in_ball.getCornorRD().x)&&(this->cornorLD.x < in_ball.getCornorRD().x))) || (this->cornorRD.x >= in_ball.getCornorLD().x && this->cornorRD.x <= in_ball.getCornorRD().x) && (((this->cornorLD.y > in_ball.getCornorLU().y)&&(this->cornorLD.y < in_ball.getCornorRD().y))||((this->cornorRU.y < in_ball.getCornorRD().y)&&(this->cornorRU.y > in_ball.getCornorLU().y))||((this->cornorRD.y > in_ball.getCornorRD().y)&&(this->cornorLU.y < in_ball.getCornorRD().y))))
                return 1;
            else return 0;
        }
        void setSpeed(float in_speed){this->speed = in_speed;}
        void setConstSpeed(float in_speed){this->const_speed = in_speed;}
        float& getSpeed(){return speed;}
        float& getConstSpeed(){return const_speed;}
        
        bool isEnter(WinArea* in_area){
            if(this->cornorLD.x >= in_area->getCornorLD().x && this->cornorRD.x <= in_area->getCornorRD().x && this->cornorRD.y <= in_area->getCornorRD().y && this->cornorRU.y >= in_area->getCornorRU().y)
                return 1;
            else return 0;
        }
    private:
        float speed;
        String direction;
        bool isMovingUp;
        bool isMovingDown;
        bool isMovingRight;
        bool isMovingLeft;
        bool touchUp;
        bool touchDown;
        bool touchRight;
        bool touchLeft;
        float const_speed;
        void up_cornor(){
            cornorLU = this->getPosition();
            cornorRU = this->getPosition() + Vector2f(this->getSize().x,0);
            cornorLD = this->getPosition() + Vector2f(0,this->getSize().y);
            cornorRD = this->getPosition() + Vector2f(this->getSize().x,this->getSize().y);
        };
        Vector2f cornorLU;
        Vector2f cornorRU;
        Vector2f cornorLD;
        Vector2f cornorRD;
};

struct Level_data{
    Rec rect1;
    int ballNum;
    Ball* ballArray = new Ball[30];
    int wallNum;
    Wall* wallArray = new Wall[30];
    WinArea win;
};

class Level{
    public:
        Level(){
            rect1.set(Vector2f(30,30),Vector2f(20,280),Color :: Red,4);
            ballArray1 = new Ball[16];
            wall_num = 7;
            for(int i = 0;i < 16;i++)
                ballArray1[i].set(Vector2f(200+50*i,5),Color :: Blue,10,6);
            wallArray1 = new Wall[7];
            this->wallArray1[0] = Wall(Vector2f(5,600),Vector2f(0,0));
            this->wallArray1[1] = Wall(Vector2f(1200,5),Vector2f(0,0));
            this->wallArray1[2] = Wall(Vector2f(5,600),Vector2f(1195,0));
            this->wallArray1[3] = Wall(Vector2f(1200,5),Vector2f(0,595));
            this->wallArray1[4] = Wall(Vector2f(20,500),Vector2f(180,100));
            this->wallArray1[5] = Wall(Vector2f(20,500),Vector2f(575,0));
            this->wallArray1[6] = Wall(Vector2f(20,500),Vector2f(970,100));
            win1.set(Vector2f(205,100),Vector2f(990,500),Color::Green);
            pass = 0;
            pass_img.loadFromFile("image//victory.png");
            pass_msg.setTexture(pass_img);
            pass_msg.setPosition(Vector2f(420,220));
            font.loadFromFile("font//TWKai.ttf");
            continue_text.setString(String("press Q to continue"));
            continue_text.setColor(Color::Black);
            continue_text.setPosition(Vector2f(435,500));
            continue_text.setCharacterSize(24);
            continue_text.setStyle(Text::Bold);
            continue_text.setFont(font);
        }
        ~Level(){
            delete this->ballArray1;
            delete this->wallArray1;
            delete this;
        }

        Level(struct Level_data* levelData){
            this->rect1_speed = levelData->rect1.getConstSpeed();
            this->rect1_st_pos = levelData->rect1.getPosition();
            rect1.set(levelData->rect1.getSize(),this->rect1_st_pos,levelData->rect1.getFillColor(),this->rect1_speed);
            this->ball_num = levelData->ballNum;
            ballArray1 = new Ball[ball_num];
            for(int i = 0;i < ball_num;i++)
                this->ballArray1[i].set(levelData->ballArray[i].getStPos(),levelData->ballArray[i].getFillColor(),levelData->ballArray[i].getRadius(),levelData->ballArray[i].getSpeed(),levelData->ballArray[i].getStPos(),levelData->ballArray[i].getEndPos());
            this->wall_num = levelData->wallNum;
            wallArray1 = new Wall[this->wall_num];
            for(int i = 0;i < this->wall_num;i++)
                this->wallArray1[i].set(levelData->wallArray[i].getSize(),levelData->wallArray[i].getPosition(),levelData->wallArray[i].getFillColor());
            win1.set(levelData->win.getSize(),levelData->win.getPosition(),Color::Green);
            pass = 0;
            pass_img.loadFromFile("image//victory.png");
            pass_msg.setTexture(pass_img);
            pass_msg.setPosition(Vector2f(420,220));
            font.loadFromFile("font//TWKai.ttf");
            continue_text.setString(String("press Q to continue"));
            continue_text.setColor(Color::Black);
            continue_text.setPosition(Vector2f(435,500));
            continue_text.setCharacterSize(24);
            continue_text.setStyle(Text::Bold);
            continue_text.setFont(font);
        }
        void set(struct Level_data* levelData){
            this->rect1_speed = levelData->rect1.getConstSpeed();
            this->rect1_st_pos = levelData->rect1.getPosition();
            rect1.set(levelData->rect1.getSize(),this->rect1_st_pos,levelData->rect1.getFillColor(),this->rect1_speed);
            this->ball_num = levelData->ballNum;
            ballArray1 = new Ball[ball_num];
            for(int i = 0;i < ball_num;i++)
                this->ballArray1[i].set(levelData->ballArray[i].getStPos(),levelData->ballArray[i].getFillColor(),levelData->ballArray[i].getRadius(),levelData->ballArray[i].getSpeed(),levelData->ballArray[i].getStPos(),levelData->ballArray[i].getEndPos());
            this->wall_num = levelData->wallNum;
            wallArray1 = new Wall[this->wall_num];
            for(int i = 0;i < this->wall_num;i++)
                this->wallArray1[i].set(levelData->wallArray[i].getSize(),levelData->wallArray[i].getPosition(),levelData->wallArray[i].getFillColor());
            win1.set(levelData->win.getSize(),levelData->win.getPosition(),Color::Green);
            pass = 0;
            pass_img.loadFromFile("image//victory.png");
            pass_msg.setTexture(pass_img);
            pass_msg.setPosition(Vector2f(420,220));
            font.loadFromFile("font//TWKai.ttf");
            continue_text.setString(String("press Q to continue"));
            continue_text.setColor(Color::Black);
            continue_text.setPosition(Vector2f(435,500));
            continue_text.setCharacterSize(24);
            continue_text.setStyle(Text::Bold);
            continue_text.setFont(font);
        }

        Text& getContinueText(){return continue_text;}
        Wall*& getWallArray1(){return wallArray1;}
        int& getBallNum(){return ball_num;}
        int& getWallNum(){return wall_num;}
        Ball*& getBallArray1(){return ballArray1;}
        Rec& getRect1(){return rect1;}
        WinArea& getWin1(){return win1;}
        Sprite& getPassMsg(){return pass_msg;}
        bool& getPass(){return pass;}
        void process();
        void process(Event);
        void update();
        void render();
        void end();
    private:
        Wall* wallArray1;
        int wall_num;
        Ball* ballArray1;
        int ball_num;
        Rec rect1;
        float rect1_speed;
        Vector2f rect1_st_pos;
        WinArea win1;
        Texture pass_img;
        Sprite pass_msg;
        Text continue_text;
        Font font;
        bool pass;
};

void Level :: process(){
   Event event;
    while(!this->pass){
        if (Keyboard::isKeyPressed(Keyboard::Up)){
            if(!rect1.getIsMoving("up"))rect1.startMoving("up");
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down)){
            if(!rect1.getIsMoving("down"))rect1.startMoving("down");
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right)){
            if(!rect1.getIsMoving("right"))rect1.startMoving("right");
        }
        else if (Keyboard::isKeyPressed(Keyboard::Left)){
            if(!rect1.getIsMoving("left"))rect1.startMoving("left");
        }
        else{
            rect1.stopMoving();
        }
        if(event.key.code == Keyboard::F){
            rect1.setConstSpeed(rect1.getConstSpeed() + 3);
        }
        if(event.key.code == Keyboard::S){
            rect1.setConstSpeed(rect1.getConstSpeed());
        }
    }
}

void Level :: process(Event e){
    if (Keyboard::isKeyPressed(Keyboard::Up)){
        if(!rect1.getIsMoving("up"))rect1.startMoving("up");
    }
    else if (Keyboard::isKeyPressed(Keyboard::Down)){
        if(!rect1.getIsMoving("down"))rect1.startMoving("down");
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right)){
        if(!rect1.getIsMoving("right"))rect1.startMoving("right");
    }
    else if (Keyboard::isKeyPressed(Keyboard::Left)){
        if(!rect1.getIsMoving("left"))rect1.startMoving("left");
    }
    else{
        rect1.stopMoving();
    }
    if(e.key.code == Keyboard::F){
        rect1.setConstSpeed(this->rect1_speed+3);
    }
    if(e.key.code == Keyboard::S){
        rect1.setConstSpeed(this->rect1_speed);
    }
}

void Level :: update(){
    rect1.movingTo(this->wallArray1,wall_num);
    for(int i = 0;i < ball_num;i++){
        ballArray1[i].moving();
        if(rect1.isTouch(ballArray1[i])){
            rect1.setPos(rect1_st_pos);
        }
    }  
}

void Level :: end(){
    this->pass = 0;
    rect1.set(Vector2f(30,30),this->rect1_st_pos,Color :: Red,this->rect1_speed);
    //delete this;
}

class Game{
    public:
        Game();
        ~Game(){
            delete this->data;
            delete this->levelArray;
            delete this;
        };
        void run();
        void runLevel(Level&);
        Level& getLevel(int num){return levelArray[num];}
    private:
        RenderWindow window;
        Level* levelArray = new Level[3];
        int level_num;
        void process(Level&);
        void update(Level&);
        void render(Level&);
        void levelEnd(Level&);
        void end();
        bool is_end;
        struct Level_data* data = new struct Level_data[3];
};

void Game::end(){
    window.close();
    this->is_end = 1;
}

void Game :: render(Level& in_level){
    window.clear(Color :: White);
    window.draw(in_level.getWin1());
    window.draw(in_level.getRect1());
    for(int i = 0;i < in_level.getBallNum();i++)
        window.draw(in_level.getBallArray1()[i]);
    for(int i = 0;i < in_level.getWallNum();i++)
        window.draw(in_level.getWallArray1()[i]);
    if(in_level.getRect1().isEnter(&in_level.getWin1())){
        window.draw(in_level.getPassMsg());
        window.draw(in_level.getContinueText());
    }
    if(in_level.getPass()){
        window.clear(Color :: White);
    }
    window.display();
}

void Game::runLevel(Level& in_level){
    while(!(in_level.getPass() || this->is_end)){
        this->process(in_level);
        this->update(in_level);
        this->render(in_level);
    }
    in_level.end();
}

void Game :: update(Level& in_level){
   in_level.update();
}
void Game::process(Level& in_level){
    Event event;
    while(window.pollEvent(event)){
        if(event.type == Event :: Closed){
            this->end();
        }
        if(in_level.getRect1().isEnter(&in_level.getWin1())){
            if(event.key.code == Keyboard::Q){
                in_level.getPass() = 1;
            }
        }
        in_level.process(event);
    }
}