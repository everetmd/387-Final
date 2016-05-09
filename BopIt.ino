int start_pin = 0;
int pull_it_pin = 1;
int bop_it_pin = 2;
int twist_it_pin = 3;

int start = 0;
int pull_it = 0;
int bop_it = 0;
int twist_it = 0;

int num_pull = 0;
int num_bop = 0;
int num_twist = 0;
int score = 0;

int highscore = 0;

boolean prep = false;
boolean playing = false;

void setup() {
   pinMode(start_pin, INPUT);
   pinMode(pull_it_pin, INPUT);
   pinMode(bop_it_pin, INPUT);
   pinMode(twist_it_pin, INPUT);
   Serial.begin(9600);
   Serial.println("Bop It");

}

void loop() {
  start = digitalRead(start_pin);
  pull_it = digitalRead(pull_it_pin);
  bop_it = digitalRead(bop_it_pin);
  twist_it = digitalRead(twist_it_pin);

  if(start == HIGH){//if start button pressed
    if(!prep && !playing){//if not preped do so
      prep = true;
      num_bop = 0;
      num_twist = 0;
      num_pull = 0;
      score = 0;
      Serial.println("Bop it to start.");
      digitalWrite(13, HIGH);
    }else if(playing){//if playing stop
      playing = false;
      prep = false;
      score = num_bop + num_twist + num_pull;
      score = score/3;
      Serial.print("Score: ");
      Serial.println(score);
      
      if(score > highscore){
        highscore = score;
        Serial.println("New highscore!");
      }
      digitalWrite(13, LOW);
      delay(1000);
    }
  }

  if(prep && bop_it == HIGH){//bop it to start
    playing = true;
    prep = false;
    Serial.print("Highscore: ");
    Serial.println(highscore);
    delay(2000);//wait 2 seconds for the game to start
  }

  if(playing){
    if(bop_it == LOW){
      num_bop++;
      delay(1000);
    }
    if(twist_it == LOW){
      num_twist++;
      delay(1000);
    }
    if(pull_it == LOW){
      num_pull++;
      delay(1000);
    }
  }

  

}
