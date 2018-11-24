#include "robots.h" //we included the robots.cpp file(the robot world.)
#include<string>
using namespace std;
void newmove(Robot& myrobot, int step, bool& check) //this function is for checking the condition of hitting wall.
{
	int i = 0;
	while(i<step && check ==false) //this is a loop function which is written for checking facing wall.
	{
		if(!myrobot.Blocked()){            //if my original robot is not blocked by wall,it will continue its move.
			myrobot.Move();
			i++;
		}	
		else  //if original robot faces a wall,i.e. check is true, this message will be shown and it will end move. The loop is over.
		{
			ShowMessage("Robots encountered a wall. End of spiral."); //showing message of facing wall.
			check = true;
		}
	}
}
void SetColor(Robot& myrobot,Robot& mirrorrobot) //after getting the coordinates from user,if coordinates are 0 <= x,y <12 then the colors will be by this function.
{
	myrobot.SetColor(blue);     //original robot color is set to blue.
	mirrorrobot.SetColor(red);
}
void SetColor2(Robot& myrobot,Robot& mirrorrobot)   //if the first cycle of move is succesfull, then both robot's color will change.
{
	myrobot.SetColor(green);
	mirrorrobot.SetColor(purple);
}
void TurnLeft(Robot& mirrorrobot)  //for not writing 3 times turnright, we defined a new function for turning left.
{
	mirrorrobot.TurnRight();
	mirrorrobot.TurnRight();
	mirrorrobot.TurnRight();
}
void moveRobot(Robot& myrobot, Robot& mirrorrobot, bool &check) //first cycle of both robots.
{
	myrobot.TurnRight();
	TurnLeft(mirrorrobot);	
	newmove(myrobot, 1, check);  //calling the void newmove function which had loop in for checking facing walls.
	newmove(mirrorrobot, 1, check);
	if(!check){   //after first move,my program will check by loop again.if condition is ok,i.e. not faced wall,then it will move again.
	myrobot.TurnRight();
	TurnLeft(mirrorrobot);}
    newmove(myrobot, 1, check);
	newmove(mirrorrobot, 1, check);
	if(!check){
	myrobot.TurnRight();
	TurnLeft(mirrorrobot);}
	newmove(myrobot, 2, check);
	newmove(mirrorrobot, 2, check);
	if(!check){
	myrobot.TurnRight();
	TurnLeft(mirrorrobot);}
	newmove(myrobot, 2, check);
	newmove(mirrorrobot, 2, check);	
}
void moveRobot2(Robot& myrobot, Robot& mirrorrobot, bool &check) //second cycle of both robots.
{
	if(!check){
	myrobot.TurnRight();
	TurnLeft(mirrorrobot);}
	newmove(myrobot, 3, check);  //calling the void newmove function which had loop in for checking facing walls.
	newmove(mirrorrobot, 3, check);
	if(!check){
	myrobot.TurnRight();
	TurnLeft(mirrorrobot);}
	newmove(myrobot, 3, check);
	newmove(mirrorrobot, 3, check);
	if(!check){
	myrobot.TurnRight();
	TurnLeft(mirrorrobot);}
	newmove(myrobot, 4, check);
	newmove(mirrorrobot, 4, check);
	if(!check){        //after first move,my program will check by loop again.if condition is ok,i.e. not faced wall,then it will move again.
	myrobot.TurnRight();
	TurnLeft(mirrorrobot);}
	newmove(myrobot, 4, check);
	newmove(mirrorrobot, 4, check);
	if(check==false){
	ShowMessage("Robots completed the spiral.");   //if the loop was ok, i.e. check is true, then it will show this message.
	}
}
int main() 
{
	int x, y;
	string robotColor;
	GetInput("Please Enter X position of the robot", x);  //taking x coordinates from the user.
	GetInput("Please Enter Y position of the robot", y);  //taking y coordinates from the user.
	if (x,y >=0 && x,y<12)  //the coordinates input should be in that interval or the program will be terminated.
	{
		Robot myrobot(x, y, east, 0);     //my original robot at x and y coordinates of user'S input. settled towards to east.
		Robot mirrorrobot(23-x, y, west, 0);  //mirrorrobot should be symmetrical to original robot's coordinates.
		SetColor(myrobot,mirrorrobot);
		bool check = false;
		moveRobot(myrobot,mirrorrobot, check);    //calling the void move function for first cycle.
		SetColor2(myrobot,mirrorrobot);
		moveRobot2(myrobot,mirrorrobot, check);		
	}
	}