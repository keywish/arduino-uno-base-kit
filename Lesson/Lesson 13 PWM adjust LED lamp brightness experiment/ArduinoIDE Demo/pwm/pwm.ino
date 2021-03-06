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
 * [Title]     led Brightness controled by continuous potentiometer
 * [diagram]
 *           Arduino PIN A0   ===================   potentiometer pin 2
 *           Arduino PIN 11  ===================   LED
 */

int  ADPIN  = A0 ;
int  PWM_LEDPIN = 11 ;
int  value = 0 ;
float voltage = 0.0 ;
void setup()
{
    pinMode(ADPIN,INPUT);    // Define ADPIN input PWM_LEDPIN output
    pinMode(PWM_LEDPIN,OUTPUT);
    Serial.begin(9600);    // The serial baud rate is 9600
}
void loop()
{
    value =  analogRead(ADPIN);       // Read analog pin raw data
    voltage = ( float )value /1023 ;
    Serial.print("voltage==");
    Serial.println(voltage);
    value = (int)(voltage * 256 );   // Convert to voltage to achieve PWM duty cycle
    Serial.print("value==");
    Serial.println(value);
    analogWrite(PWM_LEDPIN,value);
    delay(1000);
}
