# -Closed-loop-motion-control-in-DC-Motor-encoder-Controller-with-PID-Controller
 Closed-loop motion control in DC Motor (encoder Controller) with PID Controller


Project Aim: 
 Closed-loop motion control in DC Motor (encoder Controller) with PID Controller
Equipment List:
• PC 
• Arduino (Nano/Uno/Mega)
• Breadboard x 1 
• L293D
• DC Motor with encoder
• LN298N motor driver

System Description and Mathematical Calculation:
  It is common problem to stop dc motor in specific location or angle , because of that, we should make a closed loop control system and minimize our error. In our project it is expected to make one system, which stops in specific angle. For example when user entered 30 degree our system will stop between 29.98 and 30.02. In our project, PID is applied. You can see our systems’ mathematical schematic in figure-1-
![alt text](https://github.com/btknzn/-Closed-loop-motion-control-in-DC-Motor-encoder-Controller-with-PID-Controller/blob/master/PID%20Mats.png)
Results:
You can see our system results in figure-2-
For 360 degree target value, it stopped 359.99 degre 
![alt text](https://github.com/btknzn/-Closed-loop-motion-control-in-DC-Motor-encoder-Controller-with-PID-Controller/blob/master/PID%20RESULTS.PNG)
Please be note that, you should change in code the variables’ (targetDeg) value to see our system behavior in other angles.


