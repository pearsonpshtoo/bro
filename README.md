# bro
front end for apt that accepts bro-centric commands and translates them to apt commands


#install
1) sudo apt-get install git g++
2) git clone https://github.com/pearsonpshtoo/bro
3) cd bro
4) g++ bro.cpp -o bro
5) sudo cp bro /usr/local/bin (or any directory listed from "echo $PATH")

#uninstall
1) sudo rm /usr/local/bin/bro


#commands
- "bro gimme vim"       =>   "sudo apt-get install vim" (currently only one package per command is supported)
- "bro wassupdate"      =>   "sudo apt-get update"
- "bro wassupgrade"     =>   "sudo apt-get upgrade"
- "bro wassupgrade yuh" =>   "sudo apt-get upgrade -y"
