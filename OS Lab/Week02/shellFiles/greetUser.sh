
#!/bin/bash
echo "Enter your name : "
read name
if [ "$name" = "Alice" ]; then
echo "Good morning Alice!"
elif [ "$name" = "Peter"]; then
echo "Good night Peter!"
else
echo "Hello, $name"
fi
