echo "Testing with $@"
RESULT=$(./push_swap $@)
LENGTH=$(wc -l << EOF
$RESULT
EOF
)
<< EOF ./checker $@
$RESULT
EOF
echo "Cost: $(echo $LENGTH | awk '{print $1}')"