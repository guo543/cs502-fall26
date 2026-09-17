#!/bin/bash
if [ $# -eq 0 ]; then
        echo "Please enter the lab you'd like to make a directory for."
fi

if [ -d ~/submit/$1 ]; then
        #mkdir $1
        cd $1

        mkdir submissions
        cp ~/submit/$1/* submissions/

        for f in ./submissions/*
        do
                name=$(echo $f | sed 's/\.\/submissions\/\(.*\)\.*Z*/\1/')
                echo $name
                zcat -f $f > "zip-temp"
                rm $f
                mkdir submissions/$name
                tar --directory=./submissions/$name -xvf "zip-temp"

        done
        echo "Directory created successfully"
else
        echo "Bad submit directory"
fi

