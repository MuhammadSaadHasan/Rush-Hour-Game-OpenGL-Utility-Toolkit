/*
	Muhammad Saad Hasan
	21I-0566 S
	Semester Project
*/




//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include <cstdlib>
//#include <ctime>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
 
//*****************************************************DrawSquare( GetRandInRange(0,180 ) , GetRandInRange(0,180 ),30,colors[BLUE]);
long long int t = 9999999999; //To have enough time for the person to select a car


int array[20][20], rowcheck ,colcheck, block = 0, person = 0, package = 0, tree = 0, car = 0, row, col, carx1 = 0, cary1 = 0, carx2 = 0, cary2 = 0, carx3 = 0, cary3 = 0, p, score = 0, passengers = 0, startingcars = 2, x, y;
bool spacebar = false, leftkey = false, rightkey = false, upkey = false, downkey = false, green = false, check2 = false, check3 = false, bump = false, check4 = false, check5 = false, menucheck = false, yellow = false, red = false, check6 = false, menucheck2 = false, check = true;

//check 1 to 6 are for basic needs to make sure game is workign properly and make sure no mishaps happen -- mainly for continution of outputs
//the other bool variables with names have a specific purpose each can be identified by just reading the name

void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}



int xI = 180, yI = 670;




void yellownegpoints()	//to minus points for yellow taxi and to seperate the red and yellow negative points
{
	if(array[(xI-180-30)/30][(670-yI)/30] == 2 || array[(xI-180+30)/30][(670-yI)/30] == 2 || array[(xI-180)/30][(670-30-yI)/30] == 2 || array[(xI-180)/30][(670+30-yI)/30] == 2)
	{
		score -= 5;
	}
	else if(array[(xI-180-30)/30][(670-yI)/30] == 3 || array[(xI-180+30)/30][(670-yI)/30] == 3 || array[(xI-180)/30][(670-30-yI)/30] == 3 || array[(xI-180)/30][(670+30-yI)/30] == 3)
	{
		score -= 4;
	}
	else if(array[(xI-180-30)/30][(670-yI)/30] == 4 || array[(xI-180+30)/30][(670-yI)/30] == 4 || array[(xI-180)/30][(670-30-yI)/30] == 4 || array[(xI-180)/30][(670+30-yI)/30] == 4)
	{
		score -= 4;
	}
	else if(array[(xI-180-30)/30][(670-yI)/30] == 5 || array[(xI-180+30)/30][(670-yI)/30] == 5 || array[(xI-180)/30][(670-30-yI)/30] == 5 || array[(xI-180)/30][(670+30-yI)/30] == 5)
	{
		score -= 2;
	}

}

void rednegpoints()		//to minus points for yellow taxi and to seperate the red and yellow negative points
{
	if(array[(xI-180-30)/30][(670-yI)/30] == 2 || array[(xI-180+30)/30][(670-yI)/30] == 2 || array[(xI-180)/30][(670-30-yI)/30] == 2 || array[(xI-180)/30][(670+30-yI)/30] == 2)
	{
		score -= 5;
	}
	else if(array[(xI-180-30)/30][(670-yI)/30] == 3 || array[(xI-180+30)/30][(670-yI)/30] == 3 || array[(xI-180)/30][(670-30-yI)/30] == 3 || array[(xI-180)/30][(670+30-yI)/30] == 3)
	{
		score -= 2;
	}
	else if(array[(xI-180-30)/30][(670-yI)/30] == 4 || array[(xI-180+30)/30][(670-yI)/30] == 4 || array[(xI-180)/30][(670-30-yI)/30] == 4 || array[(xI-180)/30][(670+30-yI)/30] == 4)
	{
		score -= 2;
	}
	else if(array[(xI-180-30)/30][(670-yI)/30] == 5 || array[(xI-180+30)/30][(670-yI)/30] == 5 || array[(xI-180)/30][(670-30-yI)/30] == 5 || array[(xI-180)/30][(670+30-yI)/30] == 5)
	{
		score -= 3;
	}
}

void yellowtaxicolor()			//color of yellow taxi according to what position it is in -- to give the effect of a collision so a person can clearly see it happening
{
	if(leftkey == true && bump ==  true)
	{
				cout << "LEFTT" << endl;
		DrawSquare(xI-30 , yI ,30,colors[RED]);
		DrawSquare(xI+5-30, yI+11, 15, colors[YELLOW]);
		DrawSquare(xI+15-30, yI+11, 15, colors[YELLOW]);
		DrawCircle(xI+8-30,yI+8,4,colors[BLACK]);
		DrawCircle(xI+25-30,yI+8,4,colors[BLACK]);
		//leftkey = false;
	}
	else if(rightkey == true && bump ==  true)
	{
		cout << "RIGHT" << endl;
		DrawSquare(xI+30 , yI ,30,colors[RED]);
		DrawSquare(xI+5+30, yI+11, 15, colors[YELLOW]);
		DrawSquare(xI+15+30, yI+11, 15, colors[YELLOW]);
		DrawCircle(xI+8+30,yI+8,4,colors[BLACK]);
		DrawCircle(xI+25+30,yI+8,4,colors[BLACK]);
		//rightkey = false;
	}
	else if(upkey == true && bump ==  true) 
	{
				cout << "UPPP" << endl;
		DrawSquare(xI , yI+30 ,30,colors[RED]);
		DrawSquare(xI+5, yI+11+30, 15, colors[YELLOW]);
		DrawSquare(xI+15, yI+11+30, 15, colors[YELLOW]);
		DrawCircle(xI+8,yI+8+30,4,colors[BLACK]);
		DrawCircle(xI+25,yI+8+30,4,colors[BLACK]);
		//upkey = false;
	}
	else if(downkey == true && bump ==  true)
	{
			cout << "DOWNNN" << endl;
		DrawSquare(xI , yI-30 ,30,colors[RED]);
		DrawSquare(xI+5, yI+11-30, 15, colors[YELLOW]);
		DrawSquare(xI+15, yI+11-30, 15, colors[YELLOW]);
		DrawCircle(xI+8,yI+8-30,4,colors[BLACK]);
		DrawCircle(xI+25,yI+8-30,4,colors[BLACK]);
		//downkey = false;
	}
	

	else 
	{
		DrawSquare(xI+5, yI+11, 15, colors[YELLOW]);
		DrawSquare(xI+15, yI+11, 15, colors[YELLOW]);
		DrawCircle(xI+8,yI+8,4,colors[BLACK]);
		DrawCircle(xI+25,yI+8,4,colors[BLACK]);
	}
}



void redtaxicolor()			//color of red taxi according to what position it is in -- to give the effect of a collision so a person can clearly see it
{
	if(leftkey == true && bump ==  true)
	{
				cout << "LEFTT" << endl;
		DrawSquare(xI-30 , yI ,30,colors[RED]);
		DrawSquare(xI+5-30, yI+11, 15, colors[RED]);
		DrawSquare(xI+15-30, yI+11, 15, colors[RED]);
		DrawCircle(xI+8-30,yI+8,4,colors[BLACK]);
		DrawCircle(xI+25-30,yI+8,4,colors[BLACK]);
		//leftkey = false;
	}
	else if(rightkey == true && bump ==  true)
	{
		cout << "RIGHT" << endl;
		DrawSquare(xI+30 , yI ,30,colors[RED]);
		DrawSquare(xI+5+30, yI+11, 15, colors[RED]);
		DrawSquare(xI+15+30, yI+11, 15, colors[RED]);
		DrawCircle(xI+8+30,yI+8,4,colors[BLACK]);
		DrawCircle(xI+25+30,yI+8,4,colors[BLACK]);
		//rightkey = false;
	}
	else if(upkey == true && bump ==  true) 
	{
				cout << "UPPP" << endl;
		DrawSquare(xI , yI+30 ,30,colors[RED]);
		DrawSquare(xI+5, yI+11+30, 15, colors[RED]);
		DrawSquare(xI+15, yI+11+30, 15, colors[RED]);
		DrawCircle(xI+8,yI+8+30,4,colors[BLACK]);
		DrawCircle(xI+25,yI+8+30,4,colors[BLACK]);
		//upkey = false;
	}
	else if(downkey == true && bump ==  true)
	{
			cout << "DOWNNN" << endl;
		DrawSquare(xI , yI-30 ,30,colors[RED]);
		DrawSquare(xI+5, yI+11-30, 15, colors[RED]);
		DrawSquare(xI+15, yI+11-30, 15, colors[YELLOW]);
		DrawCircle(xI+8,yI+8-30,4,colors[BLACK]);
		DrawCircle(xI+25,yI+8-30,4,colors[BLACK]);
		//downkey = false;
	}
	

	else 
	{
		DrawSquare(xI+5, yI+11, 15, colors[RED]);
		DrawSquare(xI+15, yI+11, 15, colors[RED]);
		DrawCircle(xI+8,yI+8,4,colors[BLACK]);
		DrawCircle(xI+25,yI+8,4,colors[BLACK]);
	}
}
	




void drawCar() {
	
	if(yellow == true)
	{
		yellowtaxicolor();
	}
	if(red == true)
	{
		redtaxicolor();
	}
	
	
	
	bump = false;				//collision -- bump
	rightkey = false;
	upkey = false;
	downkey = false;
	leftkey = false;
	/*
	if(green == true)
	{
		DrawCircle(xI+14,yI+30,4,colors[BLACK]);
		DrawString( xI+9, yI+10, "| " , colors[BLACK]);
		DrawString( xI+9, yI+10, "^ " , colors[BLACK]);
		//DrawString( xI+9, yI-10, "^ " , colors[BLACK]);
	}
	*/
	
	glutPostRedisplay();
}


bool flag = true;

void moveCar() {
	

	
	carx1 += 5;			//speed and movement of random cars
	
	carx2 += 5;
	cary2 += 5;
	
	carx3 += 5;
	cary3 += 5;
	
		
		
		
	
	/*
	*******RANDOM MOVEMENT LOGIC*******
	if (carx > 10 && flag) {
		carx -= 30;
		cout << "going left";
		if(carx < 100)
			
			flag = false;

	}
	else if (carx < 1010 && !flag) {
		cout << "go right";
		carx += 30;
		if (carx > 900)
			flag = true;
	}
	
	for(int row=0;row<20;row++)
   				{
					for(int col = 0;col<20;col++)
					{
						if(array[row][col] == 5)
						{
							if(array[row][col+1] == 0)
							{
								array[row][col] = {0};
								array[row][col+1] = {5};
								DrawSquare(carx, cary,    30,   colors[BLUE]);
							}
								 	
						}
					}
				}
	*/	
	/*	
	if(check4 == true)
	{	
		carx -= 30;					
		
		//check = false;
		
	}
	else
	{
		carx += 30;
	}		
			
			
				
				if(array[row][col+1] == 0 && array[row+1][col] == 0)
				{
					int value = GetRandInRange(0,1);
					if(value == 0)
					{
						carx += 15;
						if(carx == 30 || carx%30 == 0)
						{
							array[row+1][col] = {5};
							array[row][col] = {0};
						}
					}
					else
					{
						cary += 15;
						if(cary == 30 || cary%30 == 0)
						{
							array[row][col+1] = {5};
							array[row][col] = {0};
						}
					}
				}
				else
				{
				
					
					if(array[row][col+1] == 0)
					{
						carx += 15;
						if(carx == 30 || carx%30 == 0)
						{
							array[row+1][col] = {5};
							array[row][col] = {0};
						}
					}
					if(array[row+1][col] == 0)
					{
						cary += 15;
						if(cary == 30 || cary%30 == 0)
						{
							array[row][col+1] = {5};
							array[row][col] = {0};
						}
					}
				}
				*/
	

	/*
	for(int row=0;row<20;row++)
	{
		for(int col = 0;col<20;col++)
		{
			if(array[row][col] = 5)
			{
				
				p = GetRandInRange(1,4);
				if(p == 1)
				{
					if(array[row+1][col] == 0)
					{
						 array[row+1][col] = {5};
						 
					}
					
					
					array[row][col] = {0} ;
				}
				if(p == 2)
				{
					if(array[row][col-1] == 0)
					{
						 array[row][col-1] = {5};
						 
					}
					
					
					array[row][col] = {0} ;
				}
				if(p == 3)
				{
					if(array[row][col+1] == 0)
					{
						 array[row][col+1] = {5};
						 
					}
					
					
					array[row][col] = {0} ;
				}
				if(p == 4)
				{
					if(array[row-1][col] == 0)
					{
						 array[row-1][col] = {5};
						 
					}
					
					
					array[row][col] = {0} ;
				}
			
			}
		}
	}
				
				
	*/			
				
				
				
					
	
	/*if (xI > 10 && flag) {
		//xI -= 10;
		cout << "going left";
		if(xI <= 100)
			
			flag = false;

	}
	else if (xI < 1010 && !flag) {
		cout << "go right";
		//xI += 10;
		if (xI >= 900)
			flag = true;
	}*/
	
	
	/*
	if (xI > 10) {
		//xI -= 10;
		cout << "going left";
		

	}
	else if (xI < 1010) {
		cout << "go right";
		//xI += 10;
	}
	
	
	int d = GetRandInRange(0,2);
	if(d == 1)
	{
		if(yI < 670 && yI > 100)
		
		{
			npcy -= 30;
		}
	}
	else
	{
		if(xI < 750 && xI > 180)
		
		{
			npcx -= 30;
		}
	}
	*/
	
	
		
	
	
	
	
}

/*
 * Main Canvas drawing function.
 * */
 
void drawmenu() //to draw the mnu in the beginning of the game and the end so you can select a color and see your score at the end
{
		
	if(menucheck == false && menucheck2 == false)		//MAIN MENU at the beginning of the game
	{
		DrawSquare( 180, 400 ,200,colors[YELLOW]);
		DrawSquare(700 ,400,200, colors[RED]);
		
		DrawString( 225, 495, "YELLOW" , colors[BLACK]);
		DrawString( 775, 495, "RED" , colors[BLACK]);
		
		DrawString( 460, 700, "RUSH HOUR!" , colors[WHITE]);
		DrawString( 310, 800, "CHOOSE THE COLOR OF YOUR TAXI(R or Y)" , colors[WHITE]);
		glutSwapBuffers();
	}
	if(menucheck2 == true)					//after it ends shows final score
	{
		DrawSquare( 180, 400 ,200,colors[YELLOW]);
		DrawSquare(700 ,400,200, colors[RED]);
		
		DrawString( 225, 495, "YELLOW" , colors[BLACK]);
		DrawString( 775, 495, "RED" , colors[BLACK]);
		
		DrawString( 460, 700, "RUSH HOUR!" , colors[WHITE]);
		DrawString( 310, 800, "YOUR FINAL SCORE IS " , colors[WHITE]);
		DrawString( 800, 800, to_string(score) , colors[WHITE]);
		
		glutSwapBuffers();
	}
} 

void FillingRandomly() //helps assigning a random object in a random empty space at a specific amount. so no 2 objects overlap and each space is used by one object
{
	if(check == true)
		{				
			while(block <= 60)
			{
				rowcheck = GetRandInRange(1,19);
				colcheck = GetRandInRange(1,19);			//keeps looking for an empty spot
				if(array[rowcheck][colcheck] == 0 )		//to see no block covers another block making sure it places a block in a free space
										//making sure all blocks are used
				{	
									
					
					array[rowcheck][colcheck] = {1};
					block++;
			
				}
				
			}
			while(person < 3)
			{
				rowcheck = GetRandInRange(1,19);
				colcheck = GetRandInRange(1,19);
				if(array[rowcheck][colcheck] == 0)
				{	
					if(array[rowcheck+1][colcheck] != 1 && array[rowcheck-1][colcheck] != 1 && array[rowcheck-1][colcheck] != 1 && array[rowcheck][colcheck-1] != 1)						//when people are added it checks if the person is not inbetween 4 blocks so the person is not trapped not accessible by the car
					{
						array[rowcheck][colcheck] = {2};
						person++;
					}
				}
				
			}
			while(package <= 5)
			{
				rowcheck = GetRandInRange(1,19);
				colcheck = GetRandInRange(1,19);
				if(array[rowcheck][colcheck] == 0)		//the logic with the person and blocks is also applied for the res tof the objects
				{	
					if(array[rowcheck+1][colcheck] != 1 && array[rowcheck-1][colcheck] != 1 && array[rowcheck-1][colcheck] != 1 && array[rowcheck][colcheck-1] != 1)
					{
						array[rowcheck][colcheck] = {3};
						package++;
					}
				}
				
			}
			while(tree <= 7)
			{
				rowcheck = GetRandInRange(1,19);
				colcheck = GetRandInRange(1,19);
				if(array[rowcheck][colcheck] == 0)
				{	
					
					array[rowcheck][colcheck] = {4};
					tree++;
				}
				
			}
			
			while(car <= startingcars)
			{
				rowcheck = GetRandInRange(1,19);
				colcheck = GetRandInRange(1,19);
				if(array[rowcheck][colcheck] == 0)
				{	
					if(array[rowcheck+1][colcheck] != 1 && array[rowcheck-1][colcheck] != 1 && array[rowcheck-1][colcheck] != 1 && array[rowcheck][colcheck-1] !=1)
					{
						array[rowcheck][colcheck] = {5};
						car++;
					}
				}
				
			}
			
			check = false;
		}
}

void DrawMap() //draws the map so the the motion of the car can be seen
{
	//2D ARRAY is searched through and outputs a certain value accoriding to the value stored in it
	for(int row=0;row<20;row++)
	{
		for(int col = 0;col<20;col++)
		{
			if(array[row][col] == 1)
			{
				DrawSquare(180+(row*30) , 670-(col*30) ,30,colors[BLACK]);
			}
			if(array[row][col] == 2)
			{
				DrawCircle(180+(row*30)+14,670-(col*30)+23,4,colors[BLACK]);
				DrawLine( 180+(row*30)+14 , 670-(col*30)+3 , 180+(row*30)+15  , 670-(col*30)+18 , 2 , colors[BLACK] );
				DrawString( 180+(row*30)+9, 670-(col*30)+1, "^ " , colors[BLACK]);		 //each line is a different part of the total image
				DrawString( 180+(row*30)+9, 670-(col*30)-10, "^ " , colors[BLACK]);
				
			}
			if(array[row][col] == 3)
			{
				DrawSquare(180+(row*30)+5 , 670-(col*30)+5 ,20,colors[SANDY_BROWN]);
				DrawLine( 180+(row*30)+15 , 670-(col*30)+5 , 180+(row*30)+15  , 670-(col*30)+23 , 2 , colors[BLACK] );
				DrawLine( 180+(row*30)+5 , 670-(col*30)+14 , 180+(row*30)+23  , 670-(col*30)+14 , 2 , colors[BLACK] );	
			}
			if(array[row][col] == 4)
			{
				DrawSquare(180+(row*30)+12 , 670-(col*30)+21 ,10,colors[GREEN]);
				DrawSquare(180+(row*30)+7 , 670-(col*30)+15 ,10, colors[GREEN]);
				DrawSquare(180+(row*30)+16 , 670-(col*30)+15 ,10,colors[GREEN]);
				DrawSquare(180+(row*30)+13 , 670-(col*30)+8 ,8,colors[BROWN]);
				DrawSquare(180+(row*30)+13 , 670-(col*30)+4 ,8,colors[BROWN]);
					
			}
			
			
			
			
			if(array[row][col] == 5)
			{
				
				if(t%30 == 0)				//at a certain pace th ran dom cars will move mkaing the open space ahead of them 5 and replacing their old space with a 0
				{
					//array[row][col] = {0};
					
					//array[row][col] = {5};
					int check7 = false;
					if(array[row][col+1] == 0 && check7 == false)
					{							
						array[row][col] = {0};
						array[row][col+1] = {5};
						
						check7 = true;
						
					}
					if(array[row][col-1] == 0 && check7 == false)
					{
						array[row][col] = {0};
						array[row][col-1] = {5};
						
						check7 = true;
						
					}
					if(array[row+1][col] == 0 && check7 == false)
					{
						array[row][col] = {0};
						array[row+1][col] = {5};
						
						check7 = true;
						
					}
					if(array[row-1][col] == 0 && check7 == false)
					{
						array[row][col] = {0};
						array[row-1][col] = {5};
						
						check7 = true;
						
					}
				}
			
					
				
				
				DrawSquare(180+(row*30), 670-(col*30)+5,    15,   colors[BLUE]);				//add carx1 to change location
				DrawSquare(180+(row*30)+10,   670-(col*30)+5  , 15, colors[BLUE]);
				DrawCircle(180+(row*30),  670-(col*30)+3 ,   4,   colors[BLACK]);
				DrawCircle(180+(row*30)+20,   670-(col*30)+3 ,   4,colors[BLACK]);
			}
				
				
				
				
			
		}
	}
				
}

void PickUp() //allows to pickup a person and vanish it from the map giving the illusion the person is in the car
{
	if(array[(xI-180-30)/30][(670-yI)/30] == 2 && spacebar == true && check3 == false )    //checks if the the car is next to the person or not to pick up 
												//spacebar checks if spcaebar has been pressed or not
	{
		
		array[(xI-180-30)/30][(670-yI)/30] = 0;				
		green = true;
		check3 = true;					//check3 allows for the spacebar not be locked causing the green block to vanish anywhere on screen
		spacebar = false;
		
	}
	if(array[(xI-180+30)/30][(670-yI)/30] == 2 && spacebar == true && check3 == false)
	{
		array[(xI-180+30)/30][(670-yI)/30] = 0;
		green = true;
		check3 = true;
		spacebar = false;
		
	}
	if(array[(xI-180)/30][(670+30-yI)/30] == 2 && spacebar == true && check3 == false)
	{
		array[(xI-180)/30][(670+30-yI)/30] = 0;
		green = true;
		check3 = true;
		spacebar = true;
		
	}
	if(array[(xI-180)/30][(670-30-yI)/30] == 2 && spacebar == true && check3 == false)
	{
		array[(xI-180)/30][(670-30-yI)/30] = 0;
		green = true;
		check3 = true;
		spacebar = false;
		
	}
	else if(spacebar == true && check3 == true)
	{
		spacebar = false;
	}
}

void DisplayGreen() //displays a green box in a random location so the user knows where to got o drop of the person who was picked up
{
	
		if(green == true) //to give a green output till the person presses the space bar whilst next to the green location
		{	
			if(check2 == false)
			{
				rowcheck = GetRandInRange(0,19);
				colcheck = GetRandInRange(0,19);
				
				while(array[rowcheck][colcheck] != 0 && array[rowcheck+1][colcheck] != 2 && array[rowcheck-1][colcheck] != 2 && array[rowcheck][colcheck+1] != 2 && array[rowcheck][colcheck-1] != 2 && array[rowcheck+1][colcheck+1] != 2 && array[rowcheck-1][colcheck-1] != 2 && array[rowcheck+1][colcheck-1] != 2 && array[rowcheck-1][colcheck+1] != 2 && array[rowcheck+1][colcheck] != 1 && array[rowcheck-1][colcheck] != 1 && array[rowcheck][colcheck+1] != 1 && array[rowcheck][colcheck-1] != 1 && array[rowcheck+1][colcheck] != 3 && array[rowcheck-1][colcheck] != 3 && array[rowcheck][colcheck+1] != 3 && array[rowcheck][colcheck-1] != 3 && array[rowcheck+1][colcheck+1] != 3 && array[rowcheck-1][colcheck-1] != 3 && array[rowcheck+1][colcheck-1] != 3 && array[rowcheck-1][colcheck+1] != 3)	
				//makes sure box is not trapped in a location not accessible by car
				//allows the green box not be near a another person making the game more fun and casuing errors
				//allowing the green box to in a place the car will always be able to reach
				{
					rowcheck = GetRandInRange(0,19);
					colcheck = GetRandInRange(0,19);
				}
				array[rowcheck][colcheck] = {10}; ////10 is rhe location of green part
				check2 = true;
				check5 = false;
				check6 = false;
			}
			//DrawString( 180+(rowcheck*30), 670-(colcheck*30), "P" , colors[BLACK]);
			DrawSquare(180+(rowcheck*30) , 670-(colcheck*30) ,30,colors[LIGHT_GREEN]);
		}
		
}

void DropOff() //allows the green box to vanihs and shows the user has been dropped off giving the illusion person is no longer in the car
{
	//after spacebar is pressed to make the green block vanish this condition is used
	if(array[(xI-180-30)/30][(670-yI)/30] == 10 || array[(xI-180+30)/30][(670-yI)/30] == 10 || array[(xI-180)/30][(670+30-yI)/30] == 10 || array[(xI-180)/30][(670-30-yI)/30] == 10)
	{
		if(spacebar == true)
		{
			green = false;
			check3 = false;
			check2 = false;
			spacebar = false;
			score += 10;
			passengers++;
			if(passengers%2 == 0)
			{
				while(check6 == false)
				{
					rowcheck = GetRandInRange(1,19);
					colcheck = GetRandInRange(1,19);
					if(array[rowcheck][colcheck] == 0 ) 
					{	
						array[rowcheck][colcheck] = {5};	
							//increasing the number of cars after 2 passengers dropped
						check6 = true;
					}
				}
			}
			
			while(check5 == false)
			{
				rowcheck = GetRandInRange(1,19);
				colcheck = GetRandInRange(1,19);
				if(array[rowcheck][colcheck] == 0 ) 
				{	
					array[rowcheck][colcheck] = {2};			//adding another passenger everytime one is dropped to allow the score to reach 100
					check5 = true;
				}
			}
			
			
		}
	}
}

void LeftMovement() //any movement to the left including normla motio or a bump indicating a collision against an object so one can see you have collided
{	
	
	if(xI>180 && array[(xI-180-30)/30][(670-yI)/30] == 0 || array[(xI-180-30)/30][(670-yI)/30] == 10) //allows the car to move only inside the map and only over roads and also previosuly acllaimed spot by the green spot
	{
		
		leftkey = true;
		if(yellow == true)
		{
			xI -= 30;
		}
		if(red == true)
		{
			xI -= 15;
		}
		
		
	}
	else if(array[(xI-180-30)/30][(670-yI)/30] == 2 || array[(xI-180-30)/30][(670-yI)/30] == 3 || array[(xI-180-30)/30][(670-yI)/30] == 4 || array[(xI-180-30)/30][(670-yI)/30] == 5)
	{
		if(xI > 180)
		{
			bump = true;
			leftkey = true;
			if(yellow == true)
			{
				yellownegpoints();
			}
			if(red == true)
			{
				rednegpoints();
			}
		}
		
		
		
	}
}

void RightMovement()//any movement to the right including normla motio or a bump indicating a collision against an object so one can see you have collided
{
		
	if(xI < 750 && array[(xI-180+30)/30][(670-yI)/30] == 0 || array[(xI-180+30)/30][(670-yI)/30] == 10 )   //|| xI < 750 
	{	
		
		rightkey = true;
		if(yellow == true)
		{
			xI += 30;
		}
		if(red == true)
		{
			xI += 15;
		}
	}
	else if(array[(xI-180+30)/30][(670-yI)/30] == 2 || array[(xI-180+30)/30][(670-yI)/30] == 3 || array[(xI-180+30)/30][(670-yI)/30] == 4 || array[(xI-180+30)/30][(670-yI)/30] == 5)
	{
		if(xI < 750)
		{
			bump = true;
			rightkey = true;
			if(yellow == true)
			{
				yellownegpoints();
			}
			if(red == true)
			{
				rednegpoints();
			}
		}
	}
}
		
void UpMovement()//any movement up including normla motio or a bump indicating a collision against an object so one can see you have collided
{
		
	if(yI<670 && array[(xI-180)/30][(670-30-yI)/30] == 0 || array[(xI-180)/30][(670-30-yI)/30] == 10)
	{
		
		upkey = true; 
		if(yellow == true)
		{
			yI += 30;
		}
		if(red == true)
		{
			yI += 15;
		}
		
	}
	else if(array[(xI-180)/30][(670-30-yI)/30] == 2 || array[(xI-180)/30][(670-30-yI)/30] == 3 || array[(xI-180)/30][(670-30-yI)/30] == 4 || array[(xI-180)/30][(670-30-yI)/30] == 5)
	{
		if(yI <670)
		{
			bump = true;
			upkey = true;
			if(yellow == true)
			{
				yellownegpoints();
			}
			if(red == true)
			{
				rednegpoints();
			}
		}
	}
}

void DownMovement() //any movement down including normla motio or a bump indicating a collision against an object so one can see you have collided
{
		
	if(yI>100 && array[(xI-180)/30][(670+30-yI)/30] == 0 || array[(xI-180)/30][(670+30-yI)/30] == 10)
	{
		
		downkey = true;
		if(yellow == true)
		{
			yI -= 30;
		}
		if(red == true)
		{
			yI -= 15;
		}
		
	}
	else if(array[(xI-180)/30][(670+30-yI)/30] == 2 || array[(xI-180)/30][(670+30-yI)/30] == 3 || array[(xI-180)/30][(670+30-yI)/30] == 4 || array[(xI-180)/30][(670+30-yI)/30] == 5)
	{
		if(yI > 100)
		{
			bump = true;
			downkey = true;
			if(yellow == true)
			{
				yellownegpoints();
			}
			if(red == true)
			{
				rednegpoints();
			}
		}
	}
}

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.
	
	
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	drawmenu();
		
			
				
			
	if(menucheck == true && menucheck2 == false)		// the game itself showing its outputs
	{
			
		DrawSquare( 180 , 100 ,600,colors[WHITE]);			//main background
		DrawString( 50, 800, to_string(score), colors[WHITE]);
			//continously updated screen
			DrawString( 550, 800, to_string(t/10), colors[WHITE]);
		
		
			
			/*	
			Filling randomly is the main logic to the game -Only 1 2D array is used to store the location of the game instead of multiple 2D arrays
			assigning a specific number to each object and going through array to-- see number print output accoridng to that
			EMPTY -- ROAD -- 0
			BUILDING -- 1
			PERSON -- 2
			BOX -- 3
			TREE -- 4
			NPC CAR -- 5
			HIGHLIGHTED GREEN  -- DROP OFF -- 10
			
			so the array would look somehwat like this
			
			0 0 0 0 0 0 1 0 0 0 0 0 
			2 0 0 3 0 0 1 1 1 1 0 0
			3 4 0 0 2 3 1 0 10 0 1 0 
			
			to locate the location with pixels i derived a formula according to the location of the map(ie 180,670)
			
			180+(row*30) = xI and 670-(col*30) = yI
			*/
			FillingRandomly();
			DrawMap();		
			PickUp();
			DisplayGreen();
			DropOff();
			
			
				
			
			
			
			
			
			drawCar();
			glutSwapBuffers(); // do not modify this line..

		}
}


/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */





void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		LeftMovement();
			
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
			
		RightMovement();
			
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
			
		UpMovement();
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
			
		DownMovement();
	}
	

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
	

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	
	
	if(menucheck == false)
	{
		if(key == 'Y' || key == 'y')
		{
			yellow = true;
			menucheck = true;
			menucheck2 = false;
			t = 1800;			// for 3 min
							//time is set for 3 min her because as soon as the usr selects the type of car then the game begins
		}
		if(key == 'R' || key == 'r')
		{
			red = true;
			menucheck = true;
			menucheck2 = false;
			t = 1800;
		}

	}
			
	

	


	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 32 || key == 32) //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "space bar pressed" << endl;
		
		
		//these conditions only allow spacebar to be pressed when in a certain location		
		if(array[(xI-180-30)/30][(670-yI)/30] == 2 || array[(xI-180+30)/30][(670-yI)/30] == 2 || array[(xI-180)/30][(670+30-yI)/30] == 2 || array[(xI-180)/30][(670-30-yI)/30] == 2)
		{
			spacebar = true;
			//check3 = false;
		}
		if(array[(xI-180-30)/30][(670-yI)/30] == 10 || array[(xI-180+30)/30][(670-yI)/30] == 10 || array[(xI-180)/30][(670+30-yI)/30] == 10 || array[(xI-180)/30][(670-30-yI)/30] == 10)
		{
			spacebar = true;
			check3 = false;
		}
		
		

	}
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */

void Timer(int m) {

	// implement your functionality here
	moveCar();
	if(t <= 0)			//checks time for 3 min
	{
		menucheck2 = true;
		menucheck = true;			// bring back to home page with total score
	}
	t--;
	
	
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
	
	
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	
	
	
	
	
	
	
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;
		
		if(x > 180 && x < 380 && y < 400 && y > 600)
		{
			yellow == true;
			menucheck = true;
			menucheck2 = false;
			t = 1800;
		}
		if(x > 700 && x < 900 && y < 400 && y > 600)
		{
			red == true;
			menucheck = true;
			menucheck2 = false;
			t = 1800;
		}
		
		
	

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
 
 
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	//int width = 1920, height = 1080;
	
		
		
		
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Muhammad Saad Hasan 21I-0566 S "); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
	 
	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */0












