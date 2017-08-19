void check(byte address, byte data){
  digitalWrite(load, LOW); //open the door
  for(int i = 7; i >= 0; i--){
    
    digitalWrite(din, bitRead(address, i));
    digitalWrite(clk, LOW);
    digitalWrite(clk, HIGH);
  }

  for(int i = 7; i >= 0; i--){
    digitalWrite(din, bitRead(data, i));
    digitalWrite(clk, LOW);
    digitalWrite(clk, HIGH);
  }
  digitalWrite(load, HIGH); // close the door
}


void low(){
  for(byte i = 2; i < 8; i++){
    digitalWrite(i, LOW);
  }
}

void lame(byte pause, char color) {
  for(byte i = 0; i <= pause; i++){
    byte num = pause - i;
     if(color == 'R') { 
      digitalWrite(ledR1, HIGH);
      digitalWrite(ledG2, HIGH);
     }else if(color == 'G') { 
      digitalWrite(ledG1, HIGH);
      digitalWrite(ledR2, HIGH);
    }else if(color == 'Y' && digitalRead(ledG1 == HIGH)) { 
      digitalWrite(ledY1, HIGH);
    }else if(color == 'Y' && digitalRead(ledG2 == HIGH)){
      digitalWrite(ledY2, HIGH);
    }
    
    //Set Up
    
    int digit1 = num/10;
    int digit2 =   % 10; 

    //First Pannel Display       
    check(2, digit1);
    check(1, digit2);
    
    //Second Pannel Display 
    check(4, digit1);
    check(3, digit2);
    delay(500);
  }
  low();
}

