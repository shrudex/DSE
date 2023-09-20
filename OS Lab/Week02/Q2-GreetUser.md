## Q2 - Write a shell script to accept a user name and display “Good morning” if username is Alice and “Good night” if the username is Peter.

### Shell Script
```
echo '
#!/bin/bash
echo "Enter your name : "
read name
if [ "$name" = "Alice" ]; then
echo "Good morning Alice!"
elif [ "$name" = "Peter"]; then
echo "Good night Peter!"
else
echo "Hello, $name"
fi' > greetUser.sh
```

### Command to make it an executable script
```
chmod +x greetUser.sh
```


### Command to run the file
```
./greetUser.sh
```

### Output
![image](https://github.com/shrudex/DSE/assets/91502997/9d1744be-9fe7-427c-bfcb-17fdd290b3d4)
