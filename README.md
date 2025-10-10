---
title: "**UMSAE Software Tutorials**"
---

<div class="center">

![image](media/UMSAE_ePBR_Icon-BLUE_GRADIENT_V5.2_White_Background.png)

</div>

<div id="Introduction Label">

# Introduction

</div>

Hi! Welcome to the UMSAE Formula Electric Software System! We have
created the following tutorials so new members can learn some of the
basics to start working on our vehicle. This document outlines the
structure of the software system, provides some common terminology we
use on our team, and walks you through each tutorial. The earlier you
finish the tutorials, the earlier we can give you a task! If you need
help with any of the tutorials the Software System Officer (SSO),
Vehicle Control Software Lead (VCS), Data Acquisition Lead (DAQ), or
Software Testing Lead (SWT) for help, and we’ll guide you in the right
direction!

<div id="Software Systems">

## Software Systems

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

<div id="Downloading CubeMx and CubeIDE">

## Downloading CubeMx and CubeIDE

</div>

<div id="CubeMx">

### CubeMx

</div>

STM32CubeMX is a way to start some of your projects. You need to
download **6.11.1**, which you can find on the STM32CubeMX page:
<https://www.st.com/en/development-tools/stm32cubemx.html> and create a
free account to download!

<div id="CubeIDE">

### CubeIDE

</div>

CubeIDE is the IDE we use to program our STM32 microcontrollers on our
various PCBs (ACU, VCU, and SCU) on our car. You need to download
version **1.15.1**, go to the STM32CubeIDE page:
<https://www.st.com/en/development-tools/stm32cubeide.html#get-software>

<div id="Hardware">

## Hardware

</div>

The STM32-F446RE is the development board we use to flash on all the
PCBs on the car (ACU, VCU, and SCU). Unlike normal programming that can
be compiled and ran on any hardware, embedded systems software is
usually written for a specific chip. Here we are using an ARM Cortex M4
bases chip, and we need to buy the corresponding dev board to develop
for it. It costs about $30, so the SSO will get a list of new members
and make a mass order of boards.

<div id="Tutorial Projects Label">

# Tutorial Projects

</div>

These projects will give you an introduction to embedded systems
development. Our code base uses the Hardware Abstraction Layer (HAL)
library for the STM32. Hardware Abstraction Layer (HAL) is one layer
above Standard Peripheral Library (SPL), and as the name suggests, HAL
abstracts SPL functions. Once you finish a tutorial, tell your SSO. They
will likely want to see your code to make sure everything is done
correctly, or if they have any tips on good practice/optimization.  
NOTE: After you finish each tutorial please reference the **[Uploading
Tutorials to GitHub](#GitHub Tutorial)** section. A section lead or the
SSO will review a few pull requests (PRs) from each new member. The goal
is to teach you how to submit PRs and give you guys feedback on your
work :)

<div id="GitHub Tutorial">

# Uploading Tutorials to GitHub!

</div>
