# DOMAN position feedback servo

The servos DOMAN [S2003MD](http://micropede.de/shop/doman-s2003md) and [S2000MD](http://micropede.de/shop/doman-s2000md) are now available with digital position feedback without the need of additional wires.

# How to
To get the current angle, send a 50us (microsecond) pulse to the servo motor. The servo will pull the control wire high after the microseconds that represent the current position.
This can be done using Arduino:
```C++
pinMode(pin, OUTPUT);
digitalWrite(pin, HIGH);
delayMicroseconds(50); // send a 50 us pulse to get the current position
digitalWrite(pin, LOW);
pinMode(pin, INPUT);
int position = pulseIn(pin, HIGH); //e.g. 500-2500
```

# Examples
## Teach and Replay
Wire the servo as shown below:

![servo-feedbacksketch_steckplatine](https://user-images.githubusercontent.com/3062564/38412016-ace14fe4-3988-11e8-8465-46ee4870c5ab.png)

Press enter on the serial  monitor (enable Carriage return) to teach the current angle. 3 angles can be teached. Press enter to replay the angles.

## Mirror movement

Wire two servos according to:

![2-servo-feedbacksketch_steckplatine](https://user-images.githubusercontent.com/3062564/38412015-acbb7d78-3988-11e8-9c4d-44a8e7eec516.png)
 
 Move the servo connected to pin 9. The servo on pin 10 should follow. Open the serial plotter to view the read angle.
 
 <img width="932" alt="bildschirmfoto 2018-04-06 um 11 01 50" src="https://user-images.githubusercontent.com/3062564/38412581-f2f374fc-3989-11e8-88e0-f0e90560667a.png">
