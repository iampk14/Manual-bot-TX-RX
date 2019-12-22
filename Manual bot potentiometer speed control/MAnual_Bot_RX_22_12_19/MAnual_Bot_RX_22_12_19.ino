 
int FirstDigit,SecondDigit,ThirdDigit,SpeedControl,enfrt,enflt;

#define X 88
#define S 83
#define F 70
#define R 82
#define L 76
#define l 108
#define r 114
#define B 66
#define enfr 11 // Enable  pin for ffr & fbr 
#define enfl 3 // Enable  pin for ffl & fbl 

int ffr = 13;  // forward front right  
int fbr = 12;   // forward back right
int bfr = 10;  // backward front right
int bbr = 8;   // backward back right
int ffl = 7;  // forward front left  
int fbl = 6;   // forward back left
int bfl = 5;  // backward front left
int bbl = 4;   // backward back left
 



int cmd1 = 0; // for incoming serial data1
int cmd2 = 0; // for incoming serial data2



void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ffr, OUTPUT);
  pinMode(fbr, OUTPUT);
  pinMode(bfr, OUTPUT);
  pinMode(bbr, OUTPUT);
  pinMode(ffl, OUTPUT);
  pinMode(fbl, OUTPUT);
  pinMode(bfl, OUTPUT);
  pinMode(bbl, OUTPUT);
  Serial.begin(9600);


  pinMode(enfr, OUTPUT);
  pinMode(enfl, OUTPUT);

  
}

void Forward()   //function for forward action of the right motor
{
  digitalWrite(ffr, HIGH);
  digitalWrite(bfr, HIGH);
  digitalWrite(ffl, HIGH);
  digitalWrite(bfl, HIGH);
  digitalWrite(fbr, LOW);
  digitalWrite(bbr, LOW);
  digitalWrite(bbl, LOW);
  digitalWrite(fbl, LOW);
}

void Back()    //function for back action of the right motor
{
  digitalWrite(ffr, LOW);
  digitalWrite(bfr, LOW);
  digitalWrite(ffl, LOW);
  digitalWrite(bfl, LOW);
  digitalWrite(fbr, HIGH);
  digitalWrite(bbr, HIGH);
  digitalWrite(bbl, HIGH);
  digitalWrite(fbl, HIGH);         
}

void Right()
{
  digitalWrite(ffr, HIGH);
  digitalWrite(fbr, LOW);
  digitalWrite(bfr, HIGH);
  digitalWrite(bbr, LOW);
  digitalWrite(ffl, LOW);
  digitalWrite(fbl, HIGH);
  digitalWrite(bfl, LOW);
  digitalWrite(bbl, HIGH);
}

void Left()
{
  digitalWrite(ffr, LOW);
  digitalWrite(fbr, HIGH);
  digitalWrite(bfr, LOW);
  digitalWrite(bbr, HIGH);
  digitalWrite(ffl, HIGH);
  digitalWrite(fbl, LOW);
  digitalWrite(bfl, HIGH);
  digitalWrite(bbl, LOW);
}

void MecanumRight()
{
  digitalWrite(ffr, LOW);
  digitalWrite(fbr, HIGH);
  digitalWrite(bfr, HIGH);
  digitalWrite(bbr, LOW);
  digitalWrite(ffl, HIGH);
  digitalWrite(fbl, LOW);
  digitalWrite(bfl, LOW);
  digitalWrite(bbl, HIGH);
}


void MecanumLeft()    //function for left action of the robot
{
  digitalWrite(ffr, HIGH);
  digitalWrite(fbr, LOW);
  digitalWrite(bfr, LOW);
  digitalWrite(bbr, HIGH);
  digitalWrite(ffl, LOW);
  digitalWrite(fbl, HIGH);
  digitalWrite(bfl, HIGH);
  digitalWrite(bbl, LOW);
}

void allstop()    //function for stopping the robot
{
  digitalWrite(ffr, LOW);
  digitalWrite(bbr, LOW);
  digitalWrite(fbr, LOW);
  digitalWrite(bfr, LOW);
  digitalWrite(ffl, LOW);
  digitalWrite(bbl, LOW);
  digitalWrite(fbl, LOW);
  digitalWrite(bfl, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()> 0) {
      // read the incoming cmd1:
      cmd1 = Serial.read();
     //
  //   Serial.println("S received");
      if(cmd1==X)
      {
        //Serial.println("X received");
        while (!Serial.available());
      {
      // read the incoming cmd2:
      cmd2 = Serial.read();
      
      Serial.println(cmd2);
      //analogWrite(enfr,255);
      //analogWrite(enfl,255);
            if(cmd2==S)
              {
                //stop received
                Serial.println("S received");
                allstop();
              }
            else if(cmd2==F)
            {
              // Forward received
              Serial.println("F received");
              Forward();
              
            }
            else if(cmd2==R)
            {
              // Right received
              Serial.println("R received");
              Right();
            }
            else if(cmd2==L)
            {
              // Left received
              Serial.println("L received");
              Left();
            }
            else if(cmd2==B)
            {
              // Back received
              Serial.println("B received");
              Back();
            }
            else if(cmd2==l)
            {
              // sliding left
              Serial.println("l received");
              MecanumLeft();
            }
            else if(cmd2==r)
            {
              // sliding right
              Serial.println("r received");
              MecanumRight();
            }
      
      }
     }
     else
      {
        if(cmd1=='Y')
          {
              while (!Serial.available());
              FirstDigit = Serial.read();
              while (!Serial.available());
              SecondDigit = Serial.read();
              while (!Serial.available());
              ThirdDigit = Serial.read();
  
              //Calculation of received number
              if(FirstDigit=='0')
              {
                if(SecondDigit=='0')
                  SpeedControl=int(ThirdDigit)-48;
                else
                  SpeedControl=10*(int(SecondDigit)-48)+(int(ThirdDigit)-48);
              }
              else
                 SpeedControl=100*(int(FirstDigit)-48)+10*(int(SecondDigit)-48)+(int(ThirdDigit)-48);
             
          }
          enfrt= map(analogRead(enfr), 0, 1023, 0, 255);
          enflt= map(analogRead(enfl), 0, 1023, 0, 255);
          
      }
     
  }
}
