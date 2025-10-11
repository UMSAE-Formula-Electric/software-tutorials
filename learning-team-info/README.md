<div id="Software Systems">

## Team Info - Software Systems

</div>

The UMSAE Formula Electric Software System is broken down into multiple
sections. Each section has a team lead, and they are all overseen by the
Software Systems Officer (SSO).

-   Vehicle Control Systems (VCS)

-   Data Acquisition Lead (DAQ)

-   Software Testing Lead (SWT)  

<u>As of 2025, these are our software team leads!</u>

-   Systems Officer (SSO) → Caleb Pollreis

-   Vehicle Control Systems (VCS) → Mason Pronger

-   Data Acquisition Lead (DAQ) → Ethan Alexander

-   Software Testing Lead (SWT) → Evan Mack  

<div id="Vehicle Control Software (VCS))">

### Vehicle Control Software (VCS)

</div>

This section is responsible for writing all the embedded software to
control the car, which includes the following:

-   Accumulator Control Unit (ACU)

-   Vehicle Control Unit (VCU)

-   Motor Controller (MC)

-   Battery Management System (BMS)

-   Driver Display (Dash)

<div id="Data Acquisition Lead (DAQ)">

### Data Acquisition Lead (DAQ)

</div>

This section is responsible for gathering and transferring data from the
car. Our goal is to log data from the our Sensor Control Unit (SCU),
with the data logger, to validate other systems. A future goal for this
section is to write an app to monitor data collection in real time, as
well as visualize our data collection against other sensors on our car.
Accurate data collection is an important step for this year’s car and
our goal is to start collecting data in when the car is ready to drive!

<div id="Software Testing Lead (SWT)">

### Software Testing Lead (SWT)

</div>

This section focuses on ensuring the quality and reliability of software
and system components through comprehensive testing, automation and
analyzing data. Responsibilities include writing documentation and
enforcing test cases, unit testing, performing system, functional and
integration testing on car software such as ACU, VCU, SCU, and CAN
communication.

---

<div id="Vehicle Control Systems">

## Vehicle Control Systems

</div>

<div id="Accumulator Control Unit (ACU)">

### Accumulator Control Unit (ACU)

</div>

The ACU includes all the circuitry behind the firewall (a fireproof
barrier that separates the driver from the accumulator). The ACU
controls all the auxiliary functions for the accumulator (safety,
control, and charging) and also manages/distributes low voltage (LV)
power. The code base includes opening the AIRs (Accumulator Isolation
Relays), accumulator charging, turning on the radiator fans etc.

<div id="Vehicle Control Unit (VCU)">

### Vehicle Control Unit (VCU)

</div>

The VCU is responsible for interfacing with the pedal sensors,
determining and sending torque commands to the motor controller, keeping
track of the car state using a state machine, and interfacing with the
dash screen.

<div id="Sensor Control Unit (SCU)">

### Sensor Control Unit (SCU)

</div>

The SCU is responsible for gathering data from many sensors and sending
that data to a CAN bus for the logging board to collect the data. Some
examples of data we collect are:

-   Wheel speed data

-   Cooling loop temperature

-   Flow meter readings (for cooling loop)

-   Shock potentiometer data

-   IMU (Inertial Measurement Unit) data

<div id="Motor Controller (MC)">

### Motor Controller (MC)

</div>

We use a PM100Dx motor controller to control our Emrax 228 motor. It’s
important that the motor controller is calibrated properly to ensure the
motor can output a higher maximum torque value! We calibrate the motor
by using the RMS GUI software.

<div id="Battery Management System (BMS)">

### Battery Management System (BMS)

</div>

We use a EMUS G1 BMS to monitor the cells in our accumulator. A BMS will
increase the safety factor that comes with high voltage (HV) components
such as our accumulator. The BMS can collect data about the cells
(balancing levels, tempurature, voltage etc.) and we can read that data
via the EMUS G1 software. We are also able to communicate to the BMS via
CAN (Controller Area Network) communication.

<div id="Driver Display (Dash)">

### Driver Display (Dash)

</div>

Our dash screen is used to display important information to the driver
in real time. This includes:

-   Vehicle speed

-   Safety loop status

-   TSA (Tractive System Active) indicator light

-   RTD (Ready to Drive) indicator light