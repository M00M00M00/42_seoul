cat /etc/passwd | grep -v "#" | cut -f 1 -d ':' | awk 'NR % 2 == 0' | awk "NR>=$FT_LINE1 && NR<=$FT_LINE2" | rev | sort -r  | xargs echo | sed 's/ /, /g' | sed 's/$/./' | tr -d "\n"
