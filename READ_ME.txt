
// This file describes each program and how to run each of the different main files in the folder //

======================================================================================================

// Exercise 39.1

To run the simulation demonstrating a single person, Joe, getting sick
the files needed are: Person.cc, Person.h and diseasesim_person.cc
compile each into object files with:
g++ -c diseasesim_person.cc Person.cc
then link the object files and define the executable name with
g++ diseasesim_person.o Person.o -o <executablefilename>
and then run with ./<executablefilename>


the program specifies two variables: days_infected and susceptibility
days_infected specifies how long the sample person, Joe, will be sick for
and susceptibility specifies the probability which Joe will remain healthy
until becoming infected. The infection is spread to Joe when a randomly generated
float value is greater than the susceptibility.


======================================================================================================

Programs with the class Population
Population does most of the work of all of the programming, with the key variables sick_length and 
per_day_enc specified in the Population.h header file. These variables specify the number of days
an individual will be sick for and the number of encounters a sick person will have per day, 
respectively. 

This class also contains a run_sim method, which takes an input integer from 0 to 4 that specifies the
type of population simulation being run

n = 0 ==> simulate for one person
n = 1 ==> simulate for transmission among neighbors
n = 2 ==> simulate with vaccination among neighbors
n = 3 ==> simulate spreading within a population
n = 4 ==> simulate spreading with a large population

As a result, most of the following main functions discussed will be very similar in content and can be
changed very easily to be the exact same file to one another. They are kept seperate as a form of 
organizing the different exercises performed in the assignment.

Exercises 39.2 to 39.4 should have population sizes kept small since their outputs will be output to
the screen and each individual will have their status displayed. 

Exercise 39.5 may have no screen output. When running it with diseasesim_spread, there will be an output 
much like the previous 3 exercises, but when diseasesim_largepop, no screen output will occur 
until the simulation is over, only displaying the percent of the non-innoculated population that 
has become infected and the number of simulated days that elapsed.


======================================================================================================

// Exercise 39.2

To run thes simulation that shows a random individual in a population becoming
infected, the files needed are: diseasesim_notrans.cc, Population.cc, Population.h, Person.cc, Person.h
compile each into object files with:
g++ -c diseasesim_notrans.cc Population.cc Person.cc
then link the object files and define the executable name with
g++ diseasesim_notrans.o Population.o Person.o -o <executablefilename>
and then run with ./<executablefilename>

======================================================================================================

// Exercise 39.3

To run thes simulation that shows a random individual in a population becoming
infected and then infecting their neighbors only, the files needed are: 
diseasesim_neighbortrans.cc, Population.cc, Population.h, Person.cc, Person.h
compile each into object files with:
g++ -c diseasesim_neighbortrans.cc Population.cc Person.cc
then link the object files and define the executable name with
g++ diseasesim_neighbortrans.o Population.o Person.o -o <executablefilename>
and then run with ./<executablefilename>

this program takes an input integer that is the chance an infected person will infect their
neighbor

======================================================================================================

// Exercise 39.4

To run thes simulation that shows a random individual in a population becoming
infected and then infecting their neighbors, but includes a set of innoculated individuals, 
the files needed are: diseasesim_spread.cc, Population.cc, Population.h, Person.cc, Person.h
compile each into object files with:
g++ -c diseasesim_spread.cc Population.cc Person.cc
then link the object files and define the executable name with
g++ diseasesim_spread.o Population.o Person.o -o <executablefilename>
and then run with ./<executablefilename>

this program takes two input integers, the chance that an infected person will infect their neighbor
and the number used to randomly innoculate a certain fraction of individuals

======================================================================================================

// Exercise 39.5

To run thes simulation that shows a random individual in a population becoming
infected, the files needed are: diseasesim_spread.cc, Population.cc, Population.h, Person.cc, Person.h
compile each into object files with:
g++ -c diseasesim_spread.cc Population.cc Person.cc
then link the object files and define the executable name with
g++ diseasesim_spread.o Population.o Person.o -o <executablefilename>
and then run with ./<executablefilename>

This program takes the same input as in Exercise 39.4

WHEN SIMULATING A LARGE POPULATION, "diseasesim_spread.cc" MAY AND SHOULD BE SUBSTITUTED FOR
diseasesim_largepop.cc, which supresses the screen output of the status of every individual

======================================================================================================
