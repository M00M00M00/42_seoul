a=$(echo $FT_NBR1 | tr "'" '0' | tr '\' '1' | tr '"' '2' | tr '?' '3' | tr '!' '4')
b=$(echo $FT_NBR2 | tr 'mrdoc' '01234')
aa=$(echo "ibase=5; $a" | bc)
bb=$(echo "ibase=5; $b" | bc)
c=$(expr $aa + $bb)
cc=$(echo "obase=13; $c" | bc)
echo $cc | tr "0123456789ABC" "gtaio luSnemf"
