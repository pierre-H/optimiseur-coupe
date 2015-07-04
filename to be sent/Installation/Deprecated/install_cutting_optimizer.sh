#!/bin/bash


if [ -f ./cutting_optimizer-1.0.0.tar.gz ] ; 
    then
        tar xzvf ./cutting_optimizer-1.0.0.tar.gz -C /tmp
    else
        echo "Archive ./cutting_optimizer-1.0.0.tar.gz manquante, abandon de l'installation"
        exit 1
fi


cd /tmp/cutting_optimizer-1.0.0
qmake
make
sudo mv /tmp/cutting_optimizer-1.0.0/cutting-optimizer /usr/local/bin/cutting-optimizer
sudo mv /tmp/cutting_optimizer-1.0.0/uninstall_cutting_optimizer.sh /usr/local/bin/uninstall_cutting_optimizer
sudo mv /tmp/cutting_optimizer-1.0.0/help /usr/local/bin/help
sudo rm -rf /tmp/cutting_optimizer-1.0.0
exit 0
