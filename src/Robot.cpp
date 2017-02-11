/*
 * 2017
 * */
#include <iostream>
#include <memory>
#include <string>

#include <HumanInterfaceDevices/IRJoystick.h>
#include <RobotDrive/IRRobotDrive.h>

#include <Joystick.h>
#include <SampleRobot.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <RobotDrive.h>
#include <Timer.h>

#include <IRLift.cpp>
#include <IRAcuator.cpp>
#include <IRArm.cpp>

#include <../drivers/imu/ADIS16448_IMU.h>

class Robot: public frc::SampleRobot {
	IR::IRRobotDrive 	myDrive	 {0, 1, 2, 3, IR::Mecanum};
	IR::IRJoystick 		joystick {0}; // only joystick

	frc::SendableChooser<std::string> chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";

	ADIS16448_IMU *imu;

public:
	Robot() {
		imu = new ADIS16448_IMU;
	}

	void RobotInit() {
		chooser.AddDefault(autoNameDefault, autoNameDefault);
		chooser.AddObject(autoNameCustom, autoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &chooser);
	}

	/*
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as well.
	 */
	void Autonomous() {
		auto autoSelected = chooser.GetSelected();
		// std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;


	}

	/*
	 * Runs the motors with arcade steering.
	 */
	void OperatorControl() override {

		bool button4Pressed = false;

		while (IsOperatorControl() && IsEnabled()) {
			SmartDashboard::PutData("IMU", imu);

			myDrive.ArcadeDrive(joystick, true); // drive with arcade style (use right stick), boolean true if using deadZone
			if(gamePad.GetRawButton(3)) irlift.Lift();
			if(gamePad.GetRawButton(0)) iracuator.AcuatorIn();


			// wait for a motor update time
			frc::Wait(0.005);
		}
	}

	/*
	 * Runs during test mode
	 */
	void Test() override {

	}
};

START_ROBOT_CLASS(Robot)
