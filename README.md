# ProgettoTetris
progetto programmazione 2023/2024

-------------PACCHETTI-------------
-incurses per linux
sudo apt-get install libncurses5-dev

-json file linux 
sudo apt-get install libjsoncpp-dev



-------------COMANDI-------------
-per eseguire con ncurses

g++ -o g graphics.cpp -lncurses

-per scrivere su file

g++ -o main fileManagement/file.cpp main.cpp

-json file
g++ main.cpp -o main -ljsoncpp