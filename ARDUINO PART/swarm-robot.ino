#include <SoftwareSerial.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

SoftwareSerial BT(9, 10);  //(TX,RX)
char value = 0;



const int RIGHT_WHEELS_FORWARD = 3;  // L298N'in IN1 Girişi  (sağ tekerler ileri)
const int RIGHT_WHEELS_BACK = 11;    // L298N'in IN2 Girişi  (Sağ tekerler geri)
const int LEFT_WHEELS_BACK = 5;      // L298N'in IN3 Girişi  (sol tekerler geri)
const int LEFT_WHEELS_FORWARD = 6;   // L298N'in IN4 Girişi  (sol tekerler ileri)

int rotatingLed = 7;
int stopLed = 13;

typedef enum {
  ROTATING,
  MOVING
} VehicleStatus;

VehicleStatus vehicle_status = ROTATING;

typedef struct {
  int x;
  int y;
  int z;
} Rotation;

Rotation rotation;

void setup() {
  Serial.begin(2000000);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  
  pinMode(RIGHT_WHEELS_FORWARD, OUTPUT);
  pinMode(RIGHT_WHEELS_BACK, OUTPUT);
  pinMode(LEFT_WHEELS_BACK, OUTPUT);
  pinMode(LEFT_WHEELS_FORWARD, OUTPUT);
  
  pinMode(rotatingLed, OUTPUT);
  pinMode(stopLed, OUTPUT);

  BT.begin(9600);
}

void update_rotation(void) {
  mpu6050.update();
  rotation.x = mpu6050.getAngleX();
  rotation.y = mpu6050.getAngleY();
  rotation.z = -mpu6050.getAngleZ();   //sağa ve sola dönüş açısı ( mpu6050'nin konumundan dolayı negatifle çarparak istenilen değer elde ediliyor )

      Serial.print("angleX : ");
      Serial.print(rotation.x);
      Serial.print("\tangleY : ");
      Serial.print(rotation.y);
      Serial.print("\tangleZ : ");
      Serial.println(rotation.z);
}

void rotate_logic(double degree) {  //istenilen açıya ulaşıncaya kadar aracın dönmesini sağlanıyor
  update_rotation();
  while (degree != rotation.z) {
    analogWrite(degree < 0 ? RIGHT_WHEELS_FORWARD : LEFT_WHEELS_FORWARD, 200);
    analogWrite(degree < 0 ? LEFT_WHEELS_BACK : RIGHT_WHEELS_BACK, 180);
    analogWrite(degree < 0 ? RIGHT_WHEELS_BACK : RIGHT_WHEELS_FORWARD, 0);
    analogWrite(degree < 0 ? LEFT_WHEELS_FORWARD : LEFT_WHEELS_BACK, 0);

    digitalWrite(rotatingLed, HIGH);

    update_rotation();
  }
  vehicle_status = MOVING;
}


void rerotate_logic(double degree) {  //istenilen açıya ulaşıncaya kadar aracın dönmesini sağlanıyor
  int rotating_left = degree < rotation.z;
  update_rotation();
  while (rotating_left ? degree < rotation.z : degree > rotation.z) {
    analogWrite(degree < 0 ? RIGHT_WHEELS_FORWARD : LEFT_WHEELS_FORWARD, 200);
    analogWrite(degree < 0 ? LEFT_WHEELS_BACK : RIGHT_WHEELS_BACK, 180);
    analogWrite(degree < 0 ? RIGHT_WHEELS_BACK : RIGHT_WHEELS_FORWARD, 0);
    analogWrite(degree < 0 ? LEFT_WHEELS_FORWARD : LEFT_WHEELS_BACK, 0);

    digitalWrite(rotatingLed, HIGH);

    update_rotation();
  }
  stop();
}


void move_logic(int time) { //aracın ilerleme süresi belirleniyor
  
  digitalWrite(rotatingLed, LOW);
    
    analogWrite(RIGHT_WHEELS_BACK, 0);
    analogWrite(LEFT_WHEELS_BACK, 0);
    analogWrite(RIGHT_WHEELS_FORWARD, 170);
    analogWrite(LEFT_WHEELS_FORWARD, 170);

    delay(time);

    analogWrite(RIGHT_WHEELS_FORWARD, 0);
    analogWrite(LEFT_WHEELS_FORWARD, 0);
    digitalWrite(stopLed, HIGH);
   
  
}

void stop(){
while(true){
    analogWrite(RIGHT_WHEELS_FORWARD, 0);
    analogWrite(LEFT_WHEELS_FORWARD, 0);
    analogWrite(RIGHT_WHEELS_BACK, 0);
    analogWrite(LEFT_WHEELS_BACK, 0);
    }
  
}



void loop() {

 
if (BT.available() > 0) {
value = BT.read();

if(value == 0){

 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3726);
    rerotate_logic(1); 
  } else {
    rotate_logic(-22);
  } 
}
}

if(value == 1){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3576);
    rerotate_logic(1); 
  } else {
    rotate_logic(-17);
  } 
}
}

if(value == 2){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3459);
    rerotate_logic(1); 
  } else {
    rotate_logic(-11);
  } 
}
}

if(value == 3){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3379);
    rerotate_logic(1); 
  } else {
    rotate_logic(-5);
  } 
}
}

if(value == 4){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3338);
    rerotate_logic(1); 
  } else {
    rotate_logic(-1);
  } 
}
}

if(value == 5){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3338);
    rerotate_logic(-1); 
  } else {
    rotate_logic(1);
  } 
}
}

if(value == 6){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3379);
    rerotate_logic(-1); 
  } else {
    rotate_logic(3);
  } 
}
}

if(value == 7){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3459);
    rerotate_logic(-1); 
  } else {
    rotate_logic(8);
  } 
}
}

if(value == 8){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3576);
    rerotate_logic(-1); 
  } else {
    rotate_logic(17);
  } 
}
}

if(value == 9){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3726);
    rerotate_logic(-1); 
  } else {
    rotate_logic(20);
  } 
}
}

if(value == 10){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3399);
    rerotate_logic(1); 
  } else {
    rotate_logic(-29);
  } 
}
}

if(value == 11){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3234);
    rerotate_logic(1); 
  } else {
    rotate_logic(-23);
  } 
}
}
if(value == 12){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3104);
    rerotate_logic(1); 
  } else {
    rotate_logic(-17);
  } 
}
}
if(value == 13){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3014);
    rerotate_logic(1); 
  } else {
    rotate_logic(-12);
  } 
}
}
if(value == 14){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2968);
    rerotate_logic(1); 
  } else {
    rotate_logic(-3);
  } 
}
}

if(value == 15){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2968);
    rerotate_logic(-1); 
  } else {
    rotate_logic(3);
  } 
}
}

if(value == 16){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3014);
    rerotate_logic(-1); 
  } else {
    rotate_logic(10);
  } 
}
}

if(value == 17){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3004);
    rerotate_logic(-1); 
  } else {
    rotate_logic(8);
  } 
}
}

if(value == 18){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3134);
    rerotate_logic(-1); 
  } else {
    rotate_logic(14);
  } 
}
}

if(value == 19){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3399);
    rerotate_logic(-1); 
  } else {
    rotate_logic(18);
  } 
}
}


if(value == 20){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3082);
    rerotate_logic(1); 
  } else {
    rotate_logic(-25);
  } 
}
}

if(value == 21){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2898);
    rerotate_logic(1); 
  } else {
    rotate_logic(-26);
  } 
}
}

if(value == 22){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2752);
    rerotate_logic(1); 
  } else {
    rotate_logic(-19);
  } 
}
}

if(value == 23){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2651);
    rerotate_logic(1); 
  } else {
    rotate_logic(-12);
  } 
}
}

if(value == 24){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2599);
    rerotate_logic(1); 
  } else {
    rotate_logic(-4);
  } 
}
}

if(value == 25){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2599);
    rerotate_logic(-1); 
  } else {
    rotate_logic(4);
  } 
}
}

if(value == 26){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2651);
    rerotate_logic(-1); 
  } else {
    rotate_logic(12);
  } 
}
}

if(value == 27){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2752);
    rerotate_logic(-1); 
  } else {
    rotate_logic(9);
  } 
}
}

if(value == 28){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2698);
    rerotate_logic(-1); 
  } else {
    rotate_logic(14);
  } 
}
}

if(value == 29){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(3082);
    rerotate_logic(-1); 
  } else {
    rotate_logic(28);
  } 
}
}

if(value == 30){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2777);
    rerotate_logic(1); 
  } else {
    rotate_logic(-28);
  } 
}
}

if(value == 31){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2572);
    rerotate_logic(1); 
  } else {
    rotate_logic(-30);
  } 
}
}

if(value == 32){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2407);
    rerotate_logic(1); 
  } else {
    rotate_logic(-22);
  } 
}
}

if(value == 33){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2290);
    rerotate_logic(1); 
  } else {
    rotate_logic(-14);
  } 
}
}

if(value == 34){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2230);
    rerotate_logic(1); 
  } else {
    rotate_logic(-4);
  } 
}
}

if(value == 35){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2230);
    rerotate_logic(-1); 
  } else {
    rotate_logic(4);
  } 
}
}

if(value == 36){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2290);
    rerotate_logic(-1); 
  } else {
    rotate_logic(5);
  } 
}
}

if(value == 37){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2407);
    rerotate_logic(-1); 
  } else {
    rotate_logic(12);
  } 
}
}

if(value == 38){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2572);
    rerotate_logic(-1); 
  } else {
    rotate_logic(20);
  } 
}
}

if(value == 39){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2777);
    rerotate_logic(-1); 
  } else {
    rotate_logic(27);
  } 
}
}


if(value == 40){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2491);
    rerotate_logic(1); 
  } else {
    rotate_logic(-35);
  } 
}
}

if(value == 41){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2260);
    rerotate_logic(1); 
  } else {
    rotate_logic(-30);
  } 
}
}


if(value == 42){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2070);
    rerotate_logic(1); 
  } else {
    rotate_logic(-26);
  } 
}
}


if(value == 43){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1933);
    rerotate_logic(1); 
  } else {
    rotate_logic(-16);
  } 
}
}


if(value == 44){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1861);
    rerotate_logic(1); 
  } else {
    rotate_logic(-5);
  } 
}
}


if(value == 45){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1861);
    rerotate_logic(-1); 
  } else {
    rotate_logic(5);
  } 
}
}


if(value == 46){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1933);
    rerotate_logic(-1); 
  } else {
    rotate_logic(7);
  } 
}
}


if(value == 47){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2070);
    rerotate_logic(-1); 
  } else {
    rotate_logic(16);
  } 
}
}


if(value == 48){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2260);
    rerotate_logic(-1); 
  } else {
    rotate_logic(22);
  } 
}
}

/*
if(value == 49){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2491);
    rerotate_logic(-1); 
  } else {
    rotate_logic(36);
  } 
}
}*/

if(value == 49){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1091);
    rotate_logic(-19);
    move_logic(500);
    rotate_logic(19);
    move_logic(1900);
    rerotate_logic(-1); 
  } else {
    rotate_logic(36);
  } 
}
}

if(value == 50){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2230);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-48);
  } 
}
}

if(value == 51){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1968);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-41);
  } 
}
}

if(value == 52){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1747);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-32);
  } 
}
}

if(value == 53){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1582);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-20);
  } 
}
}

if(value == 54){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1492);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-7);
  } 
}
}

if(value == 55){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1492);
    rerotate_logic(-1); 
  } else {
    rotate_logic(7);
  } 
}
}

if(value == 56){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1582);
    rerotate_logic(-1); 
  } else {
    rotate_logic(20);
  } 
}
}

if(value == 57){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1747);
    rerotate_logic(-1); 
  } else {
    rotate_logic(32);
  } 
}
}

if(value == 58){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1968);
    rerotate_logic(-1); 
  } else {
    rotate_logic(41);
  } 
}
}

if(value == 59){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2230);
    rerotate_logic(-1); 
  } else {
    rotate_logic(48);
  } 
}
}

if(value == 60){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2003);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-56);
  } 
}
}

if(value == 61){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1707);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-49);
  } 
}
}

if(value == 62){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1446);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-39);
  } 
}
}

if(value == 63){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1242);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-26);
  } 
}
}

if(value == 64){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1126);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-9);
  } 
}
}

if(value == 65){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1126);
    rerotate_logic(-1); 
  } else {
    rotate_logic(9);
  } 
}
}

if(value == 66){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1242);
    rerotate_logic(-1); 
  } else {
    rotate_logic(26);
  } 
}
}

if(value == 67){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1446);
    rerotate_logic(-1); 
  } else {
    rotate_logic(39);
  } 
}
}

if(value == 68){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1707);
    rerotate_logic(-1); 
  } else {
    rotate_logic(49);
  } 
}
}

if(value == 69){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(2003);
    rerotate_logic(-1); 
  } else {
    rotate_logic(56);
  } 
}
}


if(value == 70){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1823);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-66);
  } 
}
}

if(value == 71){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1493);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-60);
  } 
}
}

if(value == 72){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1185);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-51);
  } 
}
}

if(value == 73){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(925);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-36);
  } 
}
}

if(value == 74){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(763);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-14);
  } 
}
}

if(value == 75){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(763);
    rerotate_logic(-1); 
  } else {
    rotate_logic(14);
  } 
}
}

if(value == 76){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(925);
    rerotate_logic(-1); 
  } else {
    rotate_logic(36);
  } 
}
}

if(value == 77){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1185);
    rerotate_logic(-1); 
  } else {
    rotate_logic(51);
  } 
}
}

if(value == 78){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1493);
    rerotate_logic(-1); 
  } else {
    rotate_logic(60);
  } 
}
}

if(value == 79){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1823);
    rerotate_logic(-1); 
  } else {
    rotate_logic(66);
  } 
}
}

if(value == 80){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1707);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-77);
  } 
}
}

if(value == 81){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1348);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-74);
  } 
}
}

if(value == 82){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(997);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-68);
  } 
}
}

if(value == 83){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(667);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-56);
  } 
}
}

if(value == 84){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(414);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-26);
  } 
}
}

if(value == 85){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(414);
    rerotate_logic(-1); 
  } else {
    rotate_logic(26);
  } 
}
}

if(value == 86){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(667);
    rerotate_logic(-1); 
  } else {
    rotate_logic(56);
  } 
}
}

if(value == 87){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(997);
    rerotate_logic(-1); 
  } else {
    rotate_logic(68);
  } 
}
}

if(value == 88){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1348);
    rerotate_logic(-1); 
  } else {
    rotate_logic(74);
  } 
}
}

if(value == 89){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1707);
    rerotate_logic(-1); 
  } else {
    rotate_logic(77);
  } 
}
}

if(value == 90){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1666);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-90);
  } 
}
}

if(value == 91){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1296);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-90);
  } 
}
}

if(value == 92){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(925);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-90);
  } 
}
}

if(value == 93){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(555);
    rerotate_logic(-1); 
  } else {
    rotate_logic(-90);
  } 
}
}

if(value == 96){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(555);
    rerotate_logic(-1); 
  } else {
    rotate_logic(90);
  } 
}
}

if(value == 97){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(925);
    rerotate_logic(-1); 
  } else {
    rotate_logic(90);
  } 
}
}

if(value == 98){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1296);
    rerotate_logic(-1); 
  } else {
    rotate_logic(90);
  } 
}
}

if(value == 99){
 
 while(true){ 
  if (vehicle_status == MOVING) {
    move_logic(1666);
    rerotate_logic(-1); 
  } else {
    rotate_logic(90);
  } 
}
}













}


}


  