#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>
#include <SoftwareSerial.h>

#define LEFT 2
#define RIGHT 3

//component serials
SoftwareSerial bluetooth(2, 3);
Adafruit_MPU6050 mpu;

//global variables
int	cmd = 0;

void setup() 
	Serial.begin(9600);
	bluetooth.begin(9600);
	mpu.begin(0x69);

	mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
	mpu.setGyroRange(MPU6050_RANGE_250_DEG);
	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);


void loop() {
	if (detectMPU())
		correct_MPU();
	if (bluetooth.available())
		cmd = get_bluetooth_command();
	if (cmd)
		execute(cmd);
	readMPU();
	delay(100);
}

////Read acceleromter data
void readMPU() {
	psensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);

//	Serial.print("Acceleration(");
//	Serial.print(a.acceleration.x);
//	Serial.print(", ");
//	Serial.print(a.acceleration.y);
//	Serial.print(", ");
//	Serial.print(a.acceleration.z);
//	Serial.print(") m/s^2|");
//	Serial.print("Rotation(");
//	Serial.print(g.gyro.x);
//	Serial.print(", ");
//	Serial.print(g.gyro.y);
//	Serial.print(", ");
//	Serial.print(g.gyro.z);
//	Serial.println(") rad/s");
}

int detectMPU()
{
	return (0);
}


void	correct_MPU()
{
	return ;
}

void execute()
{
	return ;
}

int get_bluetooth_command()
{
	string input = "";
	while (bluetooth.available)
		input += bluetooth.read();
	if (input == "off")
		return (0);
	if (input == "on")
		return (1);
	if (input == "l")
		return (LEFT);
	if (input == "r")
		return (RIGHT);
	return (cmd);
}