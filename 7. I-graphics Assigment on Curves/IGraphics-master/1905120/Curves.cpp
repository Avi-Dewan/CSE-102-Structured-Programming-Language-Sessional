#include "iGraphics.h"
#include <math.h>
#include <stdio.h>

int x = 1500, y = 800; // the length and width of the screen
double pi = acos(-1);
double dx = 20, x1, xc = 0, xc1 , y1, y2, y3, y4, yc1, yc2, yc3, yc4;
float fr = 2, amp = 15;

int r = 0, g = 0, b = 100; // these are for changing the color of Wave

int  prevFrY = 0, pointFrX = x-35, pointFrY = y-30; // the buttons of changing frequency with mouse
int  prevAmpY = 0, pointAmpX = x-35, pointAmpY = y - 87; // the buttons of changing amplitude with mouse



bool sCurve = true;
bool help = false; // the Help menu
bool wave1 = true, wave2 = true ,wave3 = true, wave4 = true; // The animation



void iDraw() {
    iClear();
    iLine(0, y/2, x, y/2);

    iSetColor(r, g, b);

    if(sCurve)
        for(float i = 0; i < x; i += 0.5) {
            x1 = i*pi/180;
            y1 = 10*sin(0.3*x1*fr)*amp + y/2;
            y2 = 15*sin(x1*fr + 100)*amp +y/2;
            y3 =  10*cos(x1*fr)*amp + y/2 ;
            y4 = y1 + y2 + y3 - 2*y/2;
            iSetColor(r, g, b);
            iFilledCircle(i, y1 , 1.5);
            iFilledCircle(i, y2 , 1.5);
            iFilledCircle(i, y3, 1.5);
            iFilledCircle(i, y4, 1.5);
        }
        xc1 = xc*pi/180;
        yc1 = 10*sin(0.3*xc1*fr)*amp + y/2;
        yc2 = 15*sin(xc1*fr + 100)*amp +y/2;
        yc3 =  10*cos(xc1*fr)*amp + y/2 ;
        yc4 = yc1 + yc2 + yc3 - 2*y/2;
        if(wave1) {
            iSetColor(255, 0, 0);
            iFilledCircle(xc, yc1 , 7);
            iSetColor(r, g, b);

        }
        if(wave2) {
            iSetColor(0, 255, 0);
            iFilledCircle(xc, yc2 , 7);
            iSetColor(r, g, b);

        }
        if(wave3) {
            iSetColor(0, 0, 255);
            iFilledCircle(xc, yc3 , 7);
            iSetColor(r, g, b);

        }
        if(wave4) {
            iSetColor(100, 150, 200);
            iFilledCircle(xc, yc4 , 7);
            iSetColor(r, g, b);

        }


    if(help) {
        iSetColor(0, 0, 0);
        iShowBMP(350, 100, "help.bmp");
        iText(400, 750, "Toggle Help/ Main Page   :  F1");
        iText(400, 720, "Toggle curve show/hide   :  s/S");
        iText(400, 690, "Toggle tracer show/hide  :  <curve_No>");
        iText(400, 660, "Pause animation   : p/P");
        iText(400, 630, "Resume animation  : r/R");
        iText(400, 600, "Increase amplitude: a");
        iText(400, 570, "Decrease amplitude: A");
        iText(400, 540, "Increase frequency: f");
        iText(400, 510, "Decrease frequency: F");
        iText(400, 480, "Increase Speed    : +");
        iText(400, 450, "Decrease Speed    : -");
        iText(400, 420, "Exit              : END");
        iText(400, 390, "Change the color of the Waves :  M");
        iSetColor(r, g, b);
    }

    iSetColor( 0, 150, 0);
    iText(10, 20, "Press p for pause, r for resume, END for exit");

    iText(x-125, y-15, "Frequency: "); // drawing that up and down button for frequency
    iRectangle(x-30, y-50, 10, 45);
    iLine(x-25, y - 48, x-25, y - 8);

    iFilledRectangle(pointFrX, pointFrY, 20, 5);

    iText(x-125, y-70, "Amplitude: "); // drawing that up and down button for Amplitude
    iRectangle(x-30, y-110, 10, 45);
    iLine(x-25, y - 105, x-25, y - 67);

    iFilledRectangle(pointAmpX, pointAmpY, 20, 5);

    iRectangle(x - 310, 30, 300, 25);
    iText(x - 300, 40, "click to change Color of the Waves");


}

void iKeyboard(unsigned char key) {
    if(key == 's' || key == 'S') {
        sCurve = !sCurve;
    } else if(key == 'a') {
        amp += 0.3;
    } else if(key == 'A') {
        amp -= 0.3;
    } else if(key == 'f') {
        fr += 0.1;
    } else if(key == 'F') {
        fr -= 0.1;
    } else if(key == 'p' || key == 'P') {
        iPauseTimer(0);
    } else if(key == 'r' || key == 'R') {
        iResumeTimer(0);
    } else if(key == '1') {
        wave1 = !wave1;
    } else if(key == '2') {
        wave2 = !wave2;
    } else if(key == '3') {
        wave3 = !wave3;
    } else if(key == '4') {
        wave4 = !wave4;
    } else if(key == '+') {
        dx += 3;
    } else if(key == '-') {
        dx -= 3;
    } else if(key == 'm') {
        r = (r+100)%255;
        g = (g+40)%255;
        b = (b+25)%255;
    }




}

void iSpecialKeyboard(unsigned char key) {
    if(key == GLUT_KEY_F1) {
        help = !help;
    } else if(key == GLUT_KEY_END) {
        exit(0);
    }
}

void iMouse(int button, int state, int mx, int my) {

   if((mx > x-310 && mx < x-10) && (my > 30 && my < 55)) { // Changing the color of Waves
        r = (r + 20)%255;
        g = (g + 10)%255;
        b = (b + 30)%255;
   }

}

void iMouseMove(int mX, int mY) {

    if((mX > x-35 && mX < x-15) && (mY > y-50 && mY < y-5)) {
        pointFrY = mY;
        if(mY > prevFrY)
            fr += 0.1;
        else if (mY < prevFrY)
            fr -= 0.1;

        prevFrY = mY; // tracking the previous one so that we can understand whether we're increasing the FREQUENCY or decreasing
    }

    if((mX > x-35 && mX < x-15) && (mY > y-110 && mY < y-65)) {
        pointAmpY = mY;
        if(mY > prevAmpY)
            amp += 0.5;
        else if (mY < prevAmpY)
            amp -= 0.5;

        prevAmpY = mY; // tracking the previous one so that we can understand whether we're increasing the AMPLITUDE or decreasing
    }


}

void ballChange() { // the ball will change direction if they hit the screen
    xc += dx;
    if(xc > x || xc < 0) dx = -dx;
}

int main()
{
    iSetTimer(20, ballChange);
    iInitialize(x, y, "Curves");

    return 0;
}
