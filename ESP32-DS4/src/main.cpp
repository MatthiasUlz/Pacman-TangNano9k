#include <PS4Controller.h>

int servoPin = 18;      // GPIO pin used to connect the servo control (digital out)

int val=90;    // variable to read the value from the analog pin

bool lastRight=false, lastLeft=false, lastUp=false, lastDown=false;
bool lastSquare=false, lastCross=false, lastCircle=false, lastTriangle=false;
bool lastL1=false, lastR1=false, lastL2=false, lastR2=false;
bool lastShare=false, lastOptions=false, lastL3=false, lastR3=false;
bool lastPS=false, lastTouch=false;

void setup() {
  Serial.begin(115200);
  PS4.begin();

  Serial.println("Ready.");

}


void loop() {
  if (!PS4.isConnected()) return;

  bool r=PS4.Right();
  bool l=PS4.Left();
  bool u=PS4.Up();
  bool d=PS4.Down();
  bool sq=PS4.Square();
  bool cr=PS4.Cross();
  bool ci=PS4.Circle();
  bool tr=PS4.Triangle();
  bool l1=PS4.L1();
  bool r1=PS4.R1();
  bool l2=PS4.L2();
  bool r2=PS4.R2();
  bool sh=PS4.Share();
  bool op=PS4.Options();
  bool l3=PS4.L3();
  bool r3=PS4.R3();
  bool ps=PS4.PSButton();
  bool tp=PS4.Touchpad();

  if (r && !lastRight) Serial.println("Right");
  if (l && !lastLeft) Serial.println("Left");
  if (u && !lastUp) Serial.println("Up");
  if (d && !lastDown) Serial.println("Down");

  if (sq && !lastSquare) Serial.println("Square");
  if (cr && !lastCross) Serial.println("Cross");
  if (ci && !lastCircle) Serial.println("Circle");
  if (tr && !lastTriangle) Serial.println("Triangle");

  if (l1 && !lastL1) Serial.println("L1");
  if (r1 && !lastR1) Serial.println("R1");
  if (l2 && !lastL2) Serial.println("L2");
  if (r2 && !lastR2) Serial.println("R2");

  if (sh && !lastShare) Serial.println("Share");
  if (op && !lastOptions) Serial.println("Options");
  if (l3 && !lastL3) Serial.println("L3");
  if (r3 && !lastR3) Serial.println("R3");
  if (ps && !lastPS) Serial.println("PS");
  if (tp && !lastTouch) Serial.println("Touchpad");

  lastRight=r;
  lastLeft=l;
  lastUp=u;
  lastDown=d;
  lastSquare=sq;
  lastCross=cr;
  lastCircle=ci;
  lastTriangle=tr;
  lastL1=l1;
  lastR1=r1;
  lastL2=l2;
  lastR2=r2;
  lastShare=sh;
  lastOptions=op;
  lastL3=l3;
  lastR3=r3;
  lastPS=ps;
  lastTouch=tp;

  delay(10);
}