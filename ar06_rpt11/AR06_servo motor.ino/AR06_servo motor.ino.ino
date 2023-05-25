/*
 예제 7.2
 서보모터 구동  
*/
 
// 서보모터 라이브러리 불러오기
#include <Servo.h> 

// 서보모터 이름 설정
Servo motor1; 
const int inputPin1=2;
const int inputPin2=3;

// 서보 모터 신호핀 설정
int servoMotorPin = 9;

// 포텐쇼미터 핀 설정
int m_Angle=0;
// 모터 각도 변수 설정
int motorAngle;
int motorAngleOld;

void setup() {
  pinMode(inputPin1, INPUT_PULLUP);
  pinMode(inputPin2, INPUT_PULLUP);

  // 서보모터 설정. 0.6ms 부터 2.4ms 범위로 설정
  motor1.attach(servoMotorPin, 600, 2400);

  // 시리얼 통신 설정  
  Serial.begin(9600);
}

void loop(){
  // 포텐쇼미터 값을 읽어옴
  // 포텐쇼미터 값을 모터 각도로 변환한다
  // 모터에 각도값을 전달한다
  motor1.write(m_Angle);

  // 이전각도와 현재 각도가 같지 않으면 시리얼 모니터에 각도를 출력한다. 

  // 현재의 모터 각도를 저장한다.
  motorAngleOld = m_Angle;
   delay(20);
if(digitalRead(inputPin1) == LOW){  
    if(m_Angle<180){
      m_Angle=m_Angle+25; 
    }          
  }
  else if(digitalRead(inputPin2) == LOW){ 
    if(m_Angle>0){
      m_Angle=m_Angle-25; 
    }
  // 모터에 각도값을 전달한다
  motor1.write(m_Angle);

  // 이전각도와 현재 각도가 같지 않으면 시리얼 모니터에 각도를 출력한다. 

  // 현재의 모터 각도를 저장한다.
  motorAngleOld = m_Angle;
   delay(20);

  }
}