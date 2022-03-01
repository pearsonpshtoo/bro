# bro
front end for apt that accepts bro-centric commands and translates them to apt commands


#install
1) git clone https://github.com/pearsonpshtoo/bro
2) cd bro
3) g++ bro.cpp -o bro
4) sudo cp bro /usr/local/bin


#commands
- "bro gimme vim"       =>   "sudo apt-get install vim" (currently only one package per command is supported)
- "bro wassupdate"      =>   "sudo apt-get update"
- "bro wassupgrade"     =>   "sudo apt-get upgrade"
- "bro wassupgrade yuh" =>   "sudo apt-get upgrade -y"
