
#include <UTFT.h>

// Declare which fonts we will be using
extern uint8_t SmallFont[];

// Set the pins to the correct ones for your development shield
// ------------------------------------------------------------
// Standard Arduino Mega/Due shield            : <display model>,38,39,40,41

// Remember to change the model parameter to suit your display module!
UTFT myGLCD(SSD1963_800480,38,39,40,41);  //(byte model, int RS, int WR, int CS, int RST, int SER)


void setup()
{
  randomSeed(analogRead(0));
  
// Setup the LCD
  myGLCD.InitLCD();
 // -------------------------------------------------------------
  pinMode(8, OUTPUT);  //backlight 
  digitalWrite(8, HIGH);//on
// -------------------------------------------------------------
  myGLCD.setFont(SmallFont);

}

void loop()
{
  int buf[478];
  int x, x2;
  int y, y2;
  int r;

// Clear the screen and draw the frame
  myGLCD.clrScr();
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRect(0, 0, 799, 13);

  myGLCD.setColor(64, 64, 64);
  myGLCD.fillRect(0,458 , 899, 459);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(255, 0, 0);
  myGLCD.print("* Universal Color TFT Display Library *", CENTER, 1);
  myGLCD.setBackColor(64, 64, 64);
  myGLCD.setColor(255,255,0);
  myGLCD.print("<http://www.buydisplay.com>", CENTER, 459);
//
  myGLCD.setColor(0, 0, 255);
  myGLCD.drawRect(0, 14, 799, 457);
//
//// Draw crosshairs
  myGLCD.setColor(0, 0, 255);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.drawLine(399, 15, 399, 456);
  myGLCD.drawLine(1, 235, 478, 235);
  for (int i=9; i<790; i+=10)
    myGLCD.drawLine(i, 233, i, 238);
  for (int i=15; i<456; i+=10)
    myGLCD.drawLine(437, i, 441, i);
// Draw sin-, cos- and tan-lines  
   myGLCD.setColor(0,255,255);
   myGLCD.print("Sin", 5, 15);
  for (int i=1; i<798; i++)
  {
    myGLCD.drawPixel(i,235+(sin(((i*1.13)*3.14)/180)*95));
  }
  myGLCD.setColor(255,0,0);
  myGLCD.print("Cos", 5, 27);
  for (int i=1; i<798; i++)
  {
    myGLCD.drawPixel(i,235+(cos(((i*1.13)*3.14)/180)*95));
  }

  myGLCD.setColor(255,255,0);
  myGLCD.print("Tan", 5, 39);
  for (int i=1; i<798; i++)
  {
    myGLCD.drawPixel(i,235+(tan(((i*1.13)*3.14)/180)));
  }
//
  delay(2000);
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,479);
  myGLCD.setColor(0, 0, 255);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.drawLine(439, 15, 439, 478);
  myGLCD.drawLine(1, 235, 798, 235);
//
//// Draw a moving sinewave
  x=1;
  for (int i=1; i<(798*20); i++) 
  {
    x++;
    if (x==799)
      x=1;
    if (i>799)
    {
      if ((x==449)||(buf[x-1]==235))
        myGLCD.setColor(0,0,255);
      else
        myGLCD.setColor(0,0,0);
        myGLCD.drawPixel(x,buf[x-1]);
    }
    myGLCD.setColor(0,255,255);
    y=235+(sin(((i*1.65)*3.14)/180)*(90-(i / 100)));
    myGLCD.drawPixel(x,y);
    buf[x-1]=y;
  }
//
  delay(2000);
//  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,478);
//
// Draw some filled rectangles
   for (int i=1; i<6; i++)
   {
     switch (i)
     {
      case 1:
        myGLCD.setColor(255,0,255);
        break;
      case 2:
        myGLCD.setColor(255,0,0);
        break;
      case 3:
        myGLCD.setColor(0,255,0);
        break;
      case 4:
        myGLCD.setColor(0,0,255);
        break;
      case 5:
        myGLCD.setColor(255,255,0);
        break;
    }
    myGLCD.fillRect(250+(i*20), 146+(i*20), 410+(i*20), 206+(i*20));
  }
//
  delay(2000);
//  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,478);
//
// Draw some filled, rounded rectangles
  for (int i=1; i<6; i++)
  {
    switch (i)
    {
      case 1:
        myGLCD.setColor(255,0,255);
        break;
      case 2:
        myGLCD.setColor(255,0,0);
        break;
      case 3:
        myGLCD.setColor(0,255,0);
        break;
      case 4:
        myGLCD.setColor(0,0,255);
        break;
      case 5:
        myGLCD.setColor(255,255,0);
        break;
    }
    myGLCD.fillRoundRect(630-(i*20), 76+(i*20), 570-(i*20), 186+(i*20));
  }
//  
  delay(2000);
//  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,478);
//
// Draw some filled circles
  for (int i=1; i<6; i++)
  {
    switch (i)
    {
      case 1:
        myGLCD.setColor(255,0,255);
        break;
      case 2:
        myGLCD.setColor(255,0,0);
        break;
      case 3:
        myGLCD.setColor(0,255,0);
        break;
      case 4:
        myGLCD.setColor(0,0,255);
        break;
      case 5:
        myGLCD.setColor(255,255,0);
        break;
    }
    myGLCD.fillCircle(330+(i*20),140+(i*20), 50);
  }
//  
  delay(2000);
//  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,478);
//
//// Draw some lines in a pattern
  myGLCD.setColor (255,0,0);
  for (int i=15; i<478; i+=5)
  {
    myGLCD.drawLine(1, i, (i*1.88)-10, 478);
  }
  myGLCD.setColor (255,0,0);
  for (int i=478; i>15; i-=5)
  {
    myGLCD.drawLine(798, i, (i*1.88)-11, 15);
  }
  myGLCD.setColor (0,255,255);
  for (int i=478; i>15; i-=5)
  {
    myGLCD.drawLine(1, i, 801-(i*1.88), 15);
  }
  myGLCD.setColor (0,255,255);
  for (int i=15; i<478; i+=5)
  {
    myGLCD.drawLine(798, i, 800-(i*1.88), 478);
  }
//  
  delay(2000);
//  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,478);
//
//// Draw some random circles
  for (int i=0; i<150; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    x=32+random(716);
    y=45+random(378);
    r=random(30);
    myGLCD.drawCircle(x, y, r);
  }
//
  delay(2000);
//  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,478);
//
// Draw some random rectangles
  for (int i=0; i<150; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    x=2+random(796);
    y=16+random(459);
    x2=2+random(796);
    y2=16+random(459);
    myGLCD.drawRect(x, y, x2, y2);
  }
//
  delay(2000);
//  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,478);
//
//// Draw some random rounded rectangles
  for (int i=0; i<150; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    x=2+random(796);
    y=16+random(459);
    x2=2+random(796);
    y2=16+random(459);
    myGLCD.drawRoundRect(x, y, x2, y2);
  }
//
  delay(2000);
//  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,478);
//
  for (int i=0; i<150; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    x=2+random(796);
    y=16+random(459);
    x2=2+random(796);
    y2=16+random(459);
    myGLCD.drawLine(x, y, x2, y2);
  }
//
  delay(2000);
//  
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(1,15,798,478);
//
  for (int i=0; i<10000; i++)
  {
    myGLCD.setColor(random(255), random(255), random(255));
    myGLCD.drawPixel(2+random(476), 16+random(239));
  }
//
  delay(2000);
//
  myGLCD.fillScr(0, 0, 255);
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRoundRect(160, 70, 319, 169);
//  
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(255, 0, 0);
  myGLCD.print("That's it!", CENTER, 93);
  myGLCD.print("Restarting in a", CENTER, 119);
  myGLCD.print("few seconds...", CENTER, 132);
//  
  myGLCD.setColor(0, 255, 0);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.print("Runtime: (msecs)", CENTER, 243);
  myGLCD.printNumI(millis(), CENTER, 258);
//  
  delay (10000);
}
