#!/bin/sh

for g in "./submissions"/*
do
    name=$(echo $g | sed 's/\.\/submissions\/\(.*\)\.*Z*/\1/')
    echo $name
    cd $g/*
    if [ $? -eq 0 ]; then
        make 2>&1

        parser="./parser"
        passes=0
        num_tests=0

        echo ""
        echo "Negative Testcases"
        echo "------------------"
        temp="../../../tests/temp.out"
        for f in "../../../tests/neg"/*
        do
            name=$(echo $f | sed 's/\.\.\/\.\.\/\.\.\/tests\/neg\/\(.*\)\.java/\1/')
            outfile="../../../tests/output/$name.out"
            parse="$parser $f 2>&1 | head -n 1"
            parseroutput=$(eval timeout --signal=9 3 $parse)
            echo $parseroutput > "$temp"
            if cmp -s $outfile $temp
            then
                echo $name:\ PASS
                passes=$((passes+1))
            else
                echo $name:\ FAIL
            fi
            num_tests=$((num_tests+1))
        done
        rm -f $temp

        echo ""
        echo "Positive Testcases"
        echo "------------------"
        for f in "../../../tests/pos"/*
        do
            name=$(echo $f | sed 's/\.\.\/\.\.\/\.\.\/tests\/pos\/\(.*\)\.java/\1/')
            parse="$parser $f 2>&1"
            parseroutput=$(eval timeout --signal=9 3 $parse)
            if [ "$parseroutput" = "" ]; then
                echo $name:\ PASS
                passes=$((passes+1))
            else
                echo $name:\ FAIL
            fi
            num_tests=$((num_tests+1))
        done

        echo
        echo PASS/TOTAL:\ $passes/$num_tests
        make clean
        cd ../../../
    else
        echo "Wrong directory structure."
    fi
    echo ""
done
