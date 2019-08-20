if [[ $(git ls-files --others --exclude-standard | wc -l) -gt 0 ||  $(git ls-files --modified --exclude-standard | wc -l) -gt 0 ]]; then 
    echo "You have uncommitted files. Verify with 'git status', and then commit them."; 
else
    echo "Hola";
fi
