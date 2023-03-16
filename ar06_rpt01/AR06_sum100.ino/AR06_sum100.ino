/*
 DIY-3
*/

// start number
int number = 0;
int sum = 0;

void setup() {
  // 9600bps로 시리얼 통신 설정
  Serial.begin(9600);
  Serial.println();
}

void loop() {

  number++;
  sum += number;
  Serial.print("Number = ");
  Serial.print(number);
  Serial.print(", Sum = ");
  Serial.println(sum);  
  
  if(number == 100) {
  Serial.println();
  Serial.print("AR06 : 1 + 2 + 3 + ... + 100 = ");
  Serial.println(sum);
  number=0;
  sum=0;
  delay(100);  
  exit(0);    
  }
  
  delay(100);  // 0.1초동안 지연시킨다.
}
