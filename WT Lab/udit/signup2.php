<?php
    $server = "localhost";
    $user = "root";
    $pass = "";
    $name = "endsem";
    $conn = "";

    $conn = new mysqli($server, $user, $pass, $name);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Q2 - Udit</title>
    <link rel="stylesheet" href="style2.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.2/css/all.min.css"/>
</head>
<body>
<div class="main_div">
    <div class="title">Customer Sign-up</div>
    
    <form action="signup2.php" method="post">
      <div class="input_box">
        <input type="text" name="name" placeholder="Full Name" required>
        <div class="icon"><i class="fas fa-user"></i></div>
      </div>
      <div class="input_box">
        <input type="email" name="email" placeholder="Email" required>
        <div class="icon"><i class="fas fa-envelope"></i></div>
      </div>
      <div class="input_box">
        <input type="text" name="number" placeholder="Phone Number" required>
        <div class="icon"><i class="fas fa-phone"></i></div>
      </div>
      <div class="input_box">
        <input type="text" name="class" placeholder="Customer Class" required>
        <div class="icon"><i class="fas fa-podcast"></i></div>
      </div>
      
      <div class="input_box button">
        <input type="submit" name="submit" value="Submit">
      </div>
      <div class="sign_up">
        Already signed-up? <a href="index2.php">Fetch details now</a>
      </div>
    </form>
  </div>
</body>
</html>

<?php
    $errors = [];

    // Check if the form is submitted
    if (isset($_POST['submit'])) {
        // Server-side validation
        $name = $_POST['name'];
        $email = $_POST['email'];
        $number = $_POST['number'];
        $class = $_POST['class'];
        
        // Perform additional validations
        if (!ctype_alpha(str_replace(' ', '', $name))) {
            $errors[] = "Name should contain only alphabetic characters and spaces.";
        }
    
        if (!preg_match("/^[0|6|9]\d{9}$/", $number)) {
            $errors[] = "Invalid phone number. It should start with 0, 6, or 9 and have 10 digits.";
        }
    
        if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $errors[] = "Invalid email format.";
        }
    
        // Check if there are no validation errors
        if (empty($errors)) {
            $sql = "INSERT INTO table2 (name, email, phone, class) VALUES ('$name', '$email', '$number', '$class')";

            if ($conn->query($sql) === TRUE) {
                echo "Record inserted successfully";
            } else {
                echo "Error: " . $sql . "<br>" . $conn->error;
            }
            exit();
        }
        else{
            if (!empty($errors)) {
                echo '<div class="error_box">';
                foreach ($errors as $error) {
                    echo '<p>' . $error . '</p>';
                }
                echo '</div>';
            }            
        }
    }
    ?>
    