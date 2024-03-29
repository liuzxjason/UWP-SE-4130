/*
 * ChalkBoi.cpp
 *
 * Used https://www.modernescpp.com/index.php/thread-safe-initialization-of-a-singleton
 * as an example for thread safe singleton.
 *
 *  Created on: Apr 1, 2021
 *      Author: Tkgn1
 */
#include "DCMotorController.h"
#include "RoteryEncoderMonitor.h"
#include "WheelDriver.h"
#include "DriveTrainController.h"
#include "ChalkBoi.h"
#include "string.h"

	ChalkBoi& ChalkBoi::getInstance() {

	static ChalkBoi instance;

		return instance;
	}

	void ChalkBoi::pwmPulse(int motor){
		if (motor == 1){
			return motor1->pwmPulse();
		}
		else if (motor == 2){
			return motor2->pwmPulse();
		}
		else if (motor == 3){
			return motor3->pwmPulse();
		}
	}
	void ChalkBoi::encoderTick(){
		
		encoder1->handleChange();
		encoder2->handleChange();
		encoder3->handleChange();
	}


	//TODO delete these pointers in the destructor to avoid memory leak

	ChalkBoi::ChalkBoi(){
		motor1 = new DCMotorController(M1_PWM_GPIO_Port, M1_PWM_Pin, M1_DIR_1_GPIO_Port, M1_DIR_1_Pin,M1_DIR_2_GPIO_Port, M1_DIR_2_Pin);
		motor2 = new DCMotorController(M2_PWM_GPIO_Port, M2_PWM_Pin, M2_DIR_1_GPIO_Port, M2_DIR_1_Pin,M2_DIR_2_GPIO_Port, M2_DIR_2_Pin);
		motor3 = new DCMotorController(M3_PWM_GPIO_Port, M3_PWM_Pin, M3_DIR_1_GPIO_Port, M3_DIR_1_Pin,M3_DIR_2_GPIO_Port, M3_DIR_2_Pin);

		motor1->setPower(.125);
		motor2->setPower(.125);
		motor3->setPower(.125);
		motor1->setDirection(DCMotorController::Clockwise);
		motor2->setDirection(DCMotorController::Clockwise);
		motor3->setDirection(DCMotorController::Clockwise);
		encoder1 = new RoteryEncoderMonitor(M1_ENC_1_GPIO_Port, M1_ENC_1_Pin,M1_ENC_2_GPIO_Port,M1_ENC_2_Pin);
		encoder2 = new RoteryEncoderMonitor(M2_ENC_1_GPIO_Port, M2_ENC_1_Pin,M2_ENC_2_GPIO_Port,M2_ENC_2_Pin);
		encoder3 = new RoteryEncoderMonitor(M3_ENC_1_GPIO_Port, M3_ENC_1_Pin,M3_ENC_2_GPIO_Port,M3_ENC_2_Pin);

		//wheel1 = new WheelDriver(motor1, encoder1);
		//wheel2 = new WheelDriver(motor2, encoder2);
		//wheel3 = new WheelDriver(motor3, encoder3);
		//driveBase = new DriveTrainController(wheel1, wheel2, wheel3);

}
