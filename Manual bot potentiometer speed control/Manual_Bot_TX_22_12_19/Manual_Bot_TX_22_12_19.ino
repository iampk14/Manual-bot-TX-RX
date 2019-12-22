int JoystickRobotBaseDirX=A0;
int JoystickRobotBaseDirY=A1;

int SlidingJoystickControl=8;

int SpeedControl=A2;

char cmd1=0,cmd2=0;


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(JoystickRobotBaseDirX,INPUT);
  pinMode(JoystickRobotBaseDirY,INPUT);
  pinMode(SlidingJoystickControl,INPUT);
  pinMode(SpeedControl,INPUT);

}
int Analog_JoystickBase_X,Analog_JoystickBase_Y,SpeedControl_Value;
int x,y;
void loop() {
  // cmd1 represent that we are going to send the data of joystick which controls the robot movement
  if (cmd1='X')
  {
  Serial.print(cmd1);
  delay(10);
  // read analog data from robot joystick
  Analog_JoystickBase_X=analogRead(JoystickRobotBaseDirX)-512;
  Analog_JoystickBase_Y=analogRead(JoystickRobotBaseDirY)-512;

  x=Analog_JoystickBase_X;
  y=Analog_JoystickBase_Y;
  // Finding the Region
  if(abs(x)<50 && abs(y)<50)
    cmd2='S';
    
  else if(abs(y)>abs(x))      // either Forward or back
          {
            if(y>50)
              cmd2='F';
            else
              cmd2='B';
          }
       else                   // either right or left
           {
            if(digitalRead(SlidingJoystickControl))
            {
              // normal right and left turn
              if(x>50)
                cmd2='L';
              else
                cmd2='R';
            }
            else
            {
               // sliding right and left turn
              if(x>50)
                cmd2='l';
              else
                cmd2='r';
            }
            
           }
  }

 else if (cmd1='Y')          // sending data to control speed
    {
        cmd1='Y';                         
        Serial.print(cmd1);
        delay(10);
        SpeedControl_Value=map(analogRead(SpeedControl), 0, 1023, 0, 255);
        if (SpeedControl_Value<100) Serial.print('0');
        delay(10);
        if (SpeedControl_Value<10) Serial.print('0');
        delay(10);
        Serial.print(SpeedControl_Value);
        delay(10);  
    }
}
