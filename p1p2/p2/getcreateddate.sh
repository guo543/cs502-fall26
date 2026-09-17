for file in /homes/cs352/submit/p5/*; do
    echo "$(basename "$file") was created on $(stat -c %y "$file")"
done
