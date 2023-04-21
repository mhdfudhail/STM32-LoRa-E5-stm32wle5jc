char data;
int i = 0;
String retData ;
String finaldata ="";
String buf ="";

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  delay(2000);
  
  for (int i=0;i<2;i++){
    delay(500);
    buf = send_command("AT\r\n",9);
    delay(100);
    check_response(buf);
    delay(1000);
    buf = send_command("AT+MODE=TEST\r\n",9);
    delay(100);
    check_response(buf);
    delay(1000);
    buf = send_command("AT+TEST=RXLRPKT\r\n",9);
    delay(100);
    check_response(buf);
    delay(1000);
 
  }
  
}

void loop() {
// Serial.println("hello");
 delay(50);


    while(Serial2.available()>0){
      i = i+1;
      if(i >35){
          data = Serial2.read();
          retData.concat(data);
      }
      i=0;
      delay(1000)
      Serial.println(retData);
      Serial.println(i);
    
}


}
String send_command(char* at_msg, int buff_size){
  Serial2.write(at_msg);
  while(Serial2.available()>0){
      data = Serial2.read();
//      Serial.print(data);
      retData.concat(data);
//      Serial.println(retData);
      i = i+1;
      if(i == buff_size){
        finaldata = retData;
        i=0;        
        retData = "";
        break;
      }      
} return finaldata;
}

void check_response(String msg){
  if ((msg.indexOf("OK"))>0) {
    Serial.println("---OK---");
  }else if((msg.indexOf("TES"))>0){
     Serial.println("---OK---");
  }else if((msg.indexOf("RXL"))>0){
    Serial.println("---OK---");
  }else if ((msg.indexOf("ERR"))>0){
    Serial.println("Error : "+msg);
  }
 
//  Serial.print(msg);
  finaldata="";
  buf ="";
    
}
