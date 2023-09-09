# Rotary-Encoder-Controlled-Robot-Arm
More see: https://www.instructables.com/Rotary-Encoder-Controlled-Robot-Arm/

# Rotary Encoder Controlled Robot Arm

## Overview

This project is inspired by a Bluetooth controlled robot arm seen on `howtomechatronics.com`. We've modified the design to use rotary encoders for more precise and user-friendly control. You can now control each joint of the robot arm using a rotary encoder and also record its movements.

## Supplies

- Servos: SG90 x 3, MG996 x 3
- Rotary encoders x 6
- Arduino Mega x 1
- 2-pin push buttons x 2
- 560-ohm resistors x 2
- M3 screws and nuts
- 3D printer

## Instructions

### Step 1: Connect the Servos

- Connect them as follows: 
  - Base servo (MG996)
  - Lower waist servo (MG996)
  - Elbow servo (MG996)
  - Lowest hand servo (SG90)
  - Middle hand servo (SG90)
  - Grab servo (SG90)
  
- **Caution**: Do not connect the Arduino’s 5V to an external 5V. Instead, ensure that the external power's ground is wired to both the servo ground pin and Arduino’s ground pin.

### Step 2: Connect the Push Buttons

- Left one: Reset button
- Right one: Play button (to play recorded movements)
- Use two 560-ohm resistors

### Step 3: Connect the Rotary Encoders

- Rotary Encoder connections are defined in the provided code section.

### Step 4: Download the STL Files

- The STL files are credited to `howtomechatronics.com`.

Attachments:
- [Download STL.rar](#)
- [Download Assembly1.iam](#)

### Step 5: Implement the Code

- **Steps to use**:
  1. Press reset (reset the play)
  2. For servos (except the grab servo): 
      - Rotate the rotary encoder for each servo
      - Press down the encoder (to record the start position). Repeat for each servo.
  3. After recording the start positions, repeat the process to record the end positions.
  4. For the grab servo:
      - Press down the encoder to record the "grab open" position.
      - After setting the start position for other servos, rotate the encoder and press again to record the "grab close" position.
      - After setting the end position for other servos, rotate and press down the encoder to record the "grab open" position for releasing an object.
  5. Press the start button to make the servos rotate from the start to end positions. Press multiple times if you want to repeat the action.
  6. The play button is on the right.

Happy building and have fun controlling your robot arm with rotary encoders!
