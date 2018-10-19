# CIRTS
Configurable IR Tomography Systems - Final Year Project

This repository contains the code, data and CAD files created over the course of my final year project at UCT. It will also house future improvements and code as I develop these ideas further (once marking is complete). The repository is organised as follows:

CAD Files: Contains .stl files for the 3D printed parts used to create the rotating platform and the fixed rings of sensors. To edit the models in an online CAD Environment, go to https://cad.onshape.com/documents/62c0b2d6366894838288f93a/w/3fe4b95f8f33dafba5659a18/e/5c17d16593a6d50fb0745449.

Misc Notebooks: In the interest of transparency, all notebooks created as part of this project are included here. There is a lot of duplication, and some have been modified and edited in such a way as to obscure their original purpose. Most should execute correctly but I cannot guarentee that all of them will work as expected. THESE SHOULD BE IGNORED - please see the selected notebooks in the 'Summary Notebooks' folder.

Summary Notebooks: These notebooks show the majority of the code developed for this project with some explanations and example data. They should give an overview of the techniques used, show the results of the different experiments and provide a starting point for anyone wanting to try this for themselves.

Microcontroller Code: This folder contains the code for the Teensy boards used in this project. The files can be opened with the Arduino IDE. Each one was used for a different aspect of the project:
	- adc_speed_test was used to benchmark the ADC on the Teensy 3.6
	- serial_c is the code used to control the rotating platform. It used various charachters as commands to move the two axes and read the ADC. Clunky, but it worked well enough that it was never improved.
	- r8_fast and r8_small are very similar. They take a set of readings and send it in response to a command from the host PC. Used for the ring of 8 and its smaller brother. See the related notebooks in 'Summary Notebooks' for examples of Python code to read the data over serial.
	- ring_of_8 was used before I switched to the approach in r8_fast. It gave control over each LED and ADC reading via serial. Again, clunky but functional
	- 36_read_adcs Takes a set of readings for the ring of 16 and sends over serial. Very similar to r8_fast. Can also be modified to only send the sparse readings (see section 6 of the report).


