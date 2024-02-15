#include <CapacitiveSensor.h>


CapacitiveSensor   cs_4_8 = CapacitiveSensor(4, 8); 
  String morseLetter[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
  String morseMorse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
  String morse = "";
  String morseString = "";
void setup()
{
  cs_4_8.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
}

void loop()
{
  long sensor =  cs_4_8.capacitiveSensor(50);
  morse = "";
  int time = 3000;

  for(int i = 0; i < time; i++)
  {
    if(sensor > 1000)
    {
      int timePress = 0;
      while(sensor>1000)
      {
        timePress+=15;
        digitalWrite(7,HIGH);
        sensor = cs_4_8.capacitiveSensor(50);
        Serial.println(timePress);
       
      }
      digitalWrite(7,LOW);
      if(timePress<200 && timePress > 30)
      {
     
       morse+= ".";
      
      
      }
      else if(timePress >= 200 && timePress < 500)
      {
        morse+= "-";
      
      }
      else if(timePress>= 500 && timePress < 700)
      {
        morse+= " ";
      }
      else if (timePress > 1000)
      {
        morse+= "\n";
      }
       morseString+= morse;
      }
         if (digitalRead(3) == 0)
      {
        morseString = "";
      }
      if(digitalRead(2) == 0)
      {
        Serial.print(morseString);
        Serial.println();
        delay(1000);
      }
   }
}

String morseStringtoWord(String str)
{
  String word = "";
  int indexOfSpace = 0;
 
  for(int i = 0; i < str.length(); i++)
  {
    String letter = str.substring(indexOfSpace,str.indexOf(" "));
    if(morseMorse[i].equals(letter))
    {
      word+=morseLetter[i];
    }
    indexOfSpace = str.indexOf(" ");
  }
  return word;
}
