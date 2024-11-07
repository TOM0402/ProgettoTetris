# ProgettoTetris
progetto programmazione 2023/2024

-------------PACCHETTI-------------
-incurses per linux
sudo apt-get install libncurses5-dev

-json file linux 
sudo apt-get install libjsoncpp-dev



-------------COMANDI-------------
-per eseguire con ncurses

g++ -o ProgettoTetris main.cpp -lncurses



------------WINDOWS--------------
installare da Microsoft Store Ubuntu
// se non va il terminale eseguire questo in powershell
wsl --set-default-version 2

copiare tutta la cartella del progetto nella cartella di Ubuntu (io nella home di ubuntu)

//solo la prima volta 
cd /home
mkdir cmake-build
cd cmake-build
cmake ..
make
./ProgettoTetris

se si fanno delle modifiche basta rifare gli ultimi due
make
./ProgettoTetris


