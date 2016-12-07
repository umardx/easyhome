#define stepperPin1 8
#define stepperPin2 9
#define stepperPin3 10
#define stepperPin4 11

int stepperState[8][4] = {
  {1,0,0,0},
  {1,1,0,0},
  {0,1,0,0},
  {0,1,1,0},
  {0,0,1,0},
  {0,0,1,1},
  {0,0,0,1},
  {1,0,0,1}};

void setStepper(int i) {
  digitalWrite(stepperPin1, stepperState[i][0]);
  digitalWrite(stepperPin2, stepperState[i][1]);
  digitalWrite(stepperPin3, stepperState[i][2]);
  digitalWrite(stepperPin4, stepperState[i][3]);
}

void setup() {
  pinMode(stepperPin1, OUTPUT);
  pinMode(stepperPin2, OUTPUT);
  pinMode(stepperPin3, OUTPUT);
  pinMode(stepperPin4, OUTPUT);
}

void rotate(int deg){

  int singleStep = deg/abs(deg);
  int stepCount = 4096/360*abs(deg);
  
  int currentStep = 0;
  int stepperPosition = 0;
  int currentTime = 0;
  int lastTime = 0;

  while (currentStep<=stepCount) {
    currentTime = micros();
    
    if(currentTime-lastTime>=1000){
      setStepper(stepperPosition);
      currentStep+=singleStep;
      stepperPosition=(currentStep+8)%8;
      lastTime=micros();
    }
  }
}

int x=0;
void loop() {
  if (x==0) {
    rotate(90);
    x=1;
  }
  
}
