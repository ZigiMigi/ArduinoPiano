# ArduinoPiano
## About
This project was made as an assigment for a collage subject.
![](https://github.com/ZigiMigi/ArduinoPiano/blob/main/IRL_Project.png)  
The project is made out of 2 parts:
- One part plays the piano and tries to recreate a melody,
- the other chooses the melody.  
By pressing the reset/start button the melody (that was chosen on the slave arduino) will start playing. After it stops the user must recreate the melody and if he does it sucessesfuly, a winning melody will be played and the greed LED will light up (if its wrong the red one will continue to glow). The other aruino (the slave) has an osciloscope that chooses a  melody (currently it has 3 choices). With the press of the reset/start button on the master arduino the melody is taken from the slave and given to the game.

## How its made
It uses 2 arduinos, 1 made as a master and the other made as a slave.

## Demonstration

