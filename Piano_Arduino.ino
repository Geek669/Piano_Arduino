const int NOTA_DO  = 262;
const int NOTA_RE  = 294;
const int NOTA_MI  = 330;
const int NOTA_FA  = 349;
const int NOTA_SOL = 392;
const int NOTA_LA  = 440;
const int  NOTA_SI  = 494;
const int pulsador_DO  = 8;
const int pulsador_RE  = 7;
const int pulsador_MI  = 6;
const int pulsador_FA  = 5;
const int pulsador_SOL = 4;
const int pulsador_LA  = 3;
const int pulsador_SI  = 2;
int speaker=9;
int numero=1;
int DO=261;
int RE=294;
int MI=329;
int FA=349;
int SOL=392;
int LA=440;
int SI=493;
int DOs=277;
int REs=311;
int FAs=370;
int SOLs=415;
int LAs=466;
int count;
int value;
int notas_basicas[ ] = {NOTA_DO, NOTA_RE, NOTA_MI, NOTA_FA, NOTA_SOL, NOTA_LA, NOTA_SI};
int pulsadores   [ ] = {pulsador_DO, pulsador_RE, pulsador_MI, pulsador_FA, pulsador_SOL, pulsador_LA, pulsador_SI};
int pulsador_activado = 0;
#define DO 8
#define RE 7
#define MI 6
#define FA 5
#define SOL 4
#define LA 3
#define SI 2
byte s0, s1, s2, s3, s4, s5, s6;
void setup() 
{
  Serial.begin(9600);
 /*for(int pin=6; pin>0; pin--) 
  {
   pinMode(pulsadores[pin] , INPUT);
  }*/
  pinMode(speaker, OUTPUT);
  //digitalWrite(speaker, LOW);
  pinMode(DO, OUTPUT);
  pinMode(RE, OUTPUT);
  pinMode(MI, OUTPUT);
  pinMode(FA, OUTPUT);
  pinMode(SOL, OUTPUT);
  pinMode(LA, OUTPUT);
  pinMode(SI, OUTPUT);
}
void loop()
{
  /*for(count=0; count<8; count++)
  {
    s0=count&0x1;
    s1=(count>>1)&0x1;
    s2=(count>>2)&0x1;
    s3=(count>>3)&0x1;
    s4=(count>>4)&0x1;
    s5=(count>>5)&0x1;
    s6=(count>>6)&0x1;
    digitalWrite(8, s0);
    digitalWrite(7, s1);
    digitalWrite(6, s2);
    digitalWrite(5, s3);
    digitalWrite(4, s4);
    digitalWrite(3, s5);
    digitalWrite(2, s6);
    value=analogRead(0);
    if(value>5)
    {
      Serial.print(count);
      while(analogRead(0)>5);
    }
  }*/
int pulsador_actual;
  for (int pulsador=0; pulsador<7; pulsador++) 
  {
    pulsador_actual = digitalRead(pulsadores[pulsador]);     
    if (pulsador_actual == HIGH)
    {
      Serial.println("tocando");
      tone(9, notas_basicas[pulsador]);
      pulsador_activado = pulsadores[pulsador];
      break;
     }
  }
  if (digitalRead(pulsador_activado) == LOW) 
  {
    noTone(9);
  }
  if(Serial.available()>0)
  {
    byte recibido=Serial.read();
    if(recibido==97)
    {
      tone(speaker, DO);
      delay(100);
      noTone(speaker);
    }
    if(recibido==115)
    {
      tone(speaker, RE);
      delay(10);
      noTone(speaker);
    }
    if(recibido==100)
    {
      tone(speaker, MI);
      delay(10);
      noTone(speaker);
    }
    if(recibido==102)
    {
      tone(speaker, FA);
      delay(10);
      noTone(speaker);
    }
    if(recibido==103)
    {
      tone(speaker, SOL);
      delay(10);
      noTone(speaker);
    }
    if(recibido==104)
    {
      tone(speaker, LA);
      delay(10);
      noTone(speaker);
    }
    if(recibido==106)
    {
      tone(speaker, SI);
      delay(10);
      noTone(speaker);
    }
    if(recibido==1)
    {
      tone(speaker, DOs);
      delay(10);
      noTone(speaker);
    }
    if(recibido==2)
    {
      tone(speaker, REs);
      delay(10);
      noTone(speaker);
    }
    if(recibido==3)
    {
      tone(speaker, FAs);
      delay(10);
      noTone(speaker);
    }
    if(recibido==4)
    {
      tone(speaker, SOLs);
      delay(10);
      noTone(speaker);
    }
    if(recibido==5)
    {
      tone(speaker, LAs);
      delay(10);
      noTone(speaker);
    }
  }
}
