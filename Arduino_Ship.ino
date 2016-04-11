#define MOTOR_PIN 10
#define RUDDER_PIN 11

#define SONAR_LFT 9
#define SONAR_LFE 8
#define SONAR_LRT 7
#define SONAR_LRE 6
#define SONAR_FT 1
#define SONAR_FE 0
#define SONAR_RFT 3
#define SONAR_RFE 2
#define SONAR_RRT 5
#define SONAR_RRE 4



#include <Servo.h>
class Sonar {
  private:
    int TrigPin;
    int EchoPin;
    float  distanceCm;
    float distanceInc;
    void setPins(int trig, int echo){
      TrigPin = trig;
      EchoPin = echo;
      pinMode(EchoPin,INPUT);
      pinMode(TrigPin,OUTPUT);
    }
    
    void measure()
    {
      digitalWrite(TrigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(TrigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(TrigPin, LOW);
      float duration = pulseIn(EchoPin, HIGH);
      distanceCm = duration /29 / 2 ;
      distanceInc = duration / 74 / 2;
    };
  public:
    Sonar(){
      TrigPin = 0;
      EchoPin = 0;
      distanceCm = 0;
    };
    void setup(int t, int e){
       setPins(t,e);
    }
    float getDistanceCm(){
      return distanceCm;
    }
    
};


class Mechanism{
  private:
      int param;
      int Curparam;
      
      Servo mecServo;
  public:
      void setPins(int x){
          this->mecServo.attach(x);
      };
      Mechanism(){
        param = 90;
        Curparam = 90;
      };
      void act();
      void setParam(int x);

};


  void Mechanism::setParam(int x){
     param = x;
}

  
void Mechanism::act() {
  if (Curparam != param) {
    int Delta = Curparam - param;
    if (Delta > 0) {
      Curparam--;
    } else {
      Curparam++;
    }
    // TODO: move servo to currparam;
    mecServo.write(Curparam);
  }
}

class MyServo: public Mechanism {
  private:
    Servo myservo;
    int Angle;
    int CurrAngle;
  public:
    // sets the angle to servo
    void SetAngle(int x) {
      Angle = x;
    };
    MyServo() {
      Angle = 90;
    }; //Enter angle
    // moves the servo to given angle
    void Move();
    virtual void setup(int);    // here we set the proper pin for PWM output
   

};

void MyServo::Move() {
  if (CurrAngle != Angle) {
    int Delta = CurrAngle - Angle;
    if (Delta > 0) {
      CurrAngle--;
    } else {
      CurrAngle++;
    }
    // TODO: move servo to currAngle;
    myservo.write(CurrAngle);
  }

}
void MyServo::setup(int pin){
  setPins(pin);
  for( int i = 179; i>=90; i--){
           myservo.write(i);
                 delay(2);
  }
}                 


class Engine: public Mechanism {
  private:
    int MaxSpeed;
    int MinSpeed;
    int AvgSpeed;
     

  public:
    void setup(int);
};

void Engine :: setup(int throttlePin){
  setPins(throttlePin);
  for( int i = 179; i>=90; i--){
    setParam(i);
    delay(2);
  }
      
}









int leftRange;
int RightRange;
int ForwardRange;

MyServo rudder;
Engine motor;

Sonar RightSonar; 
Sonar LeftSonar;
Sonar ForwardSonar;

void setup() {
  // put your setup code here, to run once:
  motor.setup(MOTOR_PIN);
  rudder.setup(RUDDER_PIN);
  motor.setParam(120);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.act();
}

