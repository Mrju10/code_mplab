
int n[ 12 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ;
int M0=2;
int M1=3;
int M2=4;
int M3=5;
int M4=6;
int M5=7;
int M6=8;
int M7=9;
int M8=10;
int M9=11;
int M10=12;
int M11=13;
int start = A2;

void convert(int leds[]);

void setup() {
  
  Serial.begin(115200);
  pinMode(M0, INPUT);
  pinMode(M1, INPUT);
  pinMode(M2, INPUT);
  pinMode(M3, INPUT);
  pinMode(M4, INPUT);
  pinMode(M5, INPUT);
  pinMode(M6, INPUT);
  pinMode(M7, INPUT);
  pinMode(M8, INPUT);
  pinMode(M9, INPUT);
  pinMode(M10, INPUT);
  pinMode(M11, INPUT);
  
  pinMode(start, INPUT);

}

void loop() {
   
      int D0 = digitalRead(M0);
      int D1 = digitalRead(M1);
      int D2 = digitalRead(M2);
      int D3 = digitalRead(M3);
      int D4 = digitalRead(M4);
      int D5 = digitalRead(M5);
      int D6 = digitalRead(M6);
      int D7 = digitalRead(M7);
      int D8 = digitalRead(M8);
      int D9 = digitalRead(M9);
      int D10 = digitalRead(M10);
      int D11 = digitalRead(M11);
      int start_pin = digitalRead(start);
      //int leds[]={D11,D10,D9,D8,D7,D6,D5,D4,D3,D2,D1,D0};
      int leds[]={D0,D1,D2,D3,D4,D5,D6,D7,D8,D9,D10,D11};
      
     if(start_pin == HIGH){
      convert(leds);
      //Serial.println('.');
     }
     else{
        
      }
}
void convert(int leds[]){
      int a=0;
      float aux=0;
      float dat=0;
        //  Serial.println('.');
      for(int i=0;i<=11;i++){
        //Serial.println(leds[i]);
        //Serial.println(i);
        double expo = pow(2,i); 
        aux = leds[i]*expo + aux;
        dat =(aux*3.3)/(4096);
      }
      Serial.println(dat);

}
