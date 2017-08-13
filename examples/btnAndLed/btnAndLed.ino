int led1= 2;
int led2= 3;
int led3= 4;
int led4= 5;
int led5= 6;
int led6= 7;
int led7= 8;
int led8= 9;
int led9= 10;
int led10= 11;
int button = 12;
char stat = "f";
int arrLed[10] = {'led1','led2','led3','led4','led5','led6','led7','led8','led9','led10'};

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  /*int buttonVal = digitalRead(button);
  int dubCounter = 0;
  int counter = 0;
 
  if(stat = 'f'){counter += 1;}
  else{dubCounter += 1;}
  
  if((counter % 2) == 0){
    stat = 't';
    switch(dubCounter % 10){
      case 1: digitalWrite(led1, HIGH); 
      case 2: digitalWrite(led2, HIGH);
      case 3: digitalWrite(led3, HIGH);
      case 4: digitalWrite(led4, HIGH);
      case 5: digitalWrite(led5, HIGH);
      case 6: digitalWrite(led6, HIGH);
      case 7: digitalWrite(led7, HIGH);
      case 8: digitalWrite(led8, HIGH);
      case 9: digitalWrite(led9, HIGH);
      case 0: digitalWrite(led10, HIGH);
    }
  }*/
  int buttonVal = digitalRead(button);
  if(buttonVal){
    digitalWrite(led10, HIGH); 
  }else{
    digitalWrite(led10, LOW); 
  }
}
