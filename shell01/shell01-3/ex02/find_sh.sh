find -type f -name '*.sh' -execdir basename -s '.sh' {} + | sed 's/{.sh}$//'
