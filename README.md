# AI_Hill_Climbing_Local_Search
# Goal
This assignment aims to take a complex new problem and formulate and solve it as a search. Formulation as search is an integral skill of AI that will come in handy whenever facing a new trial. Heuristic search will allow you to find optimal solutions. Local search may not see the optimal solution, but it can usually find suitable solutions for huge problems.
# Problem Statement
A new large sports complex is being built in Delhi. It will have all the highest end equipment and courts with lots of zones. A zone will house one type of court/equipment. Example, there will be different zones for basketball courts, table tennis rooms, cardio gym, weight training, yoga center, swimming pool and so on. Different sportspersons will have different typical schedules of when they do swimming and when they practice in a court and so on.
Based on typical interest of sports persons and children in Delhi (example, more people want to be cricketers than volleyball players), some zones will be used more and some will be used less. Moreover, because it is a large complex, the zones are far from each other, so there will be walking times involved from one zone to the other based on a user’s personalized schedule. Our goal is to identify which zone should be at which part of the complex so that (on average) time spent walking can be reduced.
For that, we assume that we have Z: a set of z zones numbered {1,2,...,z} and L: a set of l locations numbered {1,2,..,l} such that (z<=l). We define two matrices T (lxl) and N (zxz). An entry tij will represent the time taken to walk from location i to location j. On the other hand, the entry nxy will represent the number of daily walks from zone x to zone y. Note that tij =tji , though this is not true for matrix N. Also, tij =0 if i=j.
Your goal is to output a mapping from Z to L such that the total time walking in a day is minimized.
# How to run code
1. METHOD 1
   a. open the folder in terminal
   b. type make
   c. an executable file main will be made
   d. then type ./main <input_file.txt> <output_file.txt>
2. METHOD 2
   a. run the bash script compile.sh
   b. an executable file main will be made
   c. run the bash script run.sh like ./run.sh <input_file.txt> <output_filet.txt>
