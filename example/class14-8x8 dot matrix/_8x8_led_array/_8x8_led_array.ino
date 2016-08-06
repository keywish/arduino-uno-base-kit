/***********************************************************************
 *       __                                                          _
 *      / /        _____  __    __  _          _   (_)   ________   | |
 *     / /____   / _____) \ \  / / | |   __   | |  | |  (  ______)  | |_____
 *    / / ___/  | |_____   \ \/ /  | |  /  \  | |  | |  | |______   |  ___  |
 *   / /\ \     | |_____|   \  /   | | / /\ \ | |  | |  (_______ )  | |   | |
 *  / /  \ \__  | |_____    / /    | |/ /  \ \| |  | |   ______| |  | |   | |
 * /_/    \___\  \______)  /_/      \__/    \__/   |_|  (________)  |_|   |_|
 *
 *
 * KeyWay Tech firmware
 *
 * Copyright (C) 2015-2020
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, in version 3.
 * learn more you can see <http://www.gnu.org/licenses/>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * [Title]     8x8bit led array display Heart images
 * [Diagram]
 *         Arduino PIN 2   ===================  8x8bit led array pin 9
 *         Arduino PIN 3   ===================  8x8bit led array pin 14
 *         Arduino PIN 4   ===================  8x8bit led array pin 8
 *         Arduino PIN 5   ===================  8x8bit led array pin 12
 *         Arduino PIN 6   ===================  8x8bit led array pin 13
 *         Arduino PIN 7   ===================  8x8bit led array pin 3
 *         Arduino PIN 8   ===================  8x8bit led array pin 4
 *         Arduino PIN 9   ===================  8x8bit led array pin 10
 *         Arduino PIN 10  ===================  8x8bit led array pin 6
 *         Arduino PIN 11  ===================  8x8bit led array pin 11
 *         Arduino PIN 12  ===================  8x8bit led array pin 15
 *         Arduino PIN 13  ===================  8x8bit led array pin 16
 *         Arduino PIN 14  ===================  8x8bit led array pin 5
 *         Arduino PIN 15  ===================  8x8bit led array pin 2
 *         Arduino PIN 16  ===================  8x8bit led array pin 7
 *         Arduino PIN 16  ===================  8x8bit led array pin 1
 */

 //the pin to control ROW_
#define    ROW_0   2   // the number of the ROW_ pin 9
#define    ROW_1   3   // the number of the ROW_ pin 14
#define    ROW_2   4   // the number of the ROW_ pin 8
#define    ROW_3   5   // the number of the ROW_ pin 12
#define    ROW_4   17   // the number of the ROW_ pin 1
#define    ROW_5   16   // the number of the ROW_ pin 7
#define    ROW_6   15   // the number of the ROW_ pin 2
#define    ROW_7   14   // the number of the ROW_ pin 5
//the pin to control COL_
#define     LED_A   6  // the number of the COL_ pin 13
#define     LED_B   7  // the number of the COL_ pin 3
#define     LED_C   8  // the number of the COL_ pin 4
#define     LED_D   9  // the number of the COL_ pin 10
#define     LED_E   10  // the number of the COL_ pin 6
#define     LED_F   11  // the number of the COL_ pin 11
#define     LED_G   12  // the number of the COL_ pin 15
#define     LED_H   13  // the number of the COL_ pin 16

const char ROW_PIN[8] = {ROW_0 , ROW_1 , ROW_2 , ROW_3 ,ROW_4 ,ROW_5 , ROW_6 ,ROW_7 } ;
const char COL_PIN[8] = {  LED_A ,  LED_B ,  LED_C ,  LED_D ,  LED_E , LED_F ,  LED_G ,  LED_H } ;

char HeartMap[8][8] = {
    0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
    0 , 1 , 1 , 0 , 0 , 1 , 1 , 0 ,
    1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
    1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
    1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
    0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 ,
    0 , 0 , 1 , 1 , 1 , 1 , 0 , 0 ,
    0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 ,
};
void setup() {
    // put your setup code here, to run once:
    int i = 0 ;
    Serial.begin(115200);
    for( i = 0 ; i < 8 ; i++)
    {
        pinMode(ROW_PIN[i] , OUTPUT );
        pinMode(COL_PIN[i] , OUTPUT );
        delay(10);
        digitalWrite(ROW_PIN[i] ,LOW);
        digitalWrite(COL_PIN[i] ,HIGH);
    }
    digitalWrite(ROW_4,LOW);
    Serial.println("Start display 12\n");
}

void loop() {
  // put your main code here, to run repeatedly:
    int i , j;
     for ( j = 0 ; j < 8 ; j++ )
     {
         for( i = 0 ; i < 8 ; i++ )
        {
            if(  HeartMap[i][j] )
            digitalWrite(ROW_PIN[i],HIGH);
            else
            digitalWrite(ROW_PIN[i],LOW);
        }
        digitalWrite( COL_PIN[j],LOW);
        delay(2);
        digitalWrite( COL_PIN[j],HIGH);
    }
}
