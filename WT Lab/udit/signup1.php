<?php
    $server = "localhost";
    $user = "root";
    $pass = "";
    $name = "endsem";
    $conn = "";

    $conn = mysqli_connect($server, $user, $pass, $name);

    // Check connection
    if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Q1 Signup - Udit</title>
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.2/css/all.min.css"/>
</head>
<body>
<div class="main_div">
    <div class="title">User Sign-up</div>
    
    <form action="signup1.php" method="post">
      <div class="input_box">
        <input type="text" name="name" placeholder="Full Name" required>
        <div class="icon"><i class="fas fa-user"></i></div>
      </div>
      <div class="input_box">
        <input type="number" name="number" placeholder="Phone Number" required>
        <div class="icon"><i class="fas fa-phone"></i></div>
      </div>
      <div class="input_box">
        <input type="password" name="password" placeholder="Password" required>
        <div class="icon"><i class="fas fa-key"></i></div>
      </div>
      <div class="input_box">
        <input type="password" name="conpassword" placeholder="Confirm Password" required>
        <div class="icon"><i class="fas fa-key"></i></div>
      </div>
      
      <div class="input_box button">
        <input type="submit" name="submit" value="Sign Up">
      </div>
      <div class="sign_up">
        Already have an account? <a href="index1.php">Enter details</a>
      </div>
    </form>
  </div>
</body>
</html>

<?php
    if (isset($_POST['submit'])) {
        $name = $_POST['name'];
        $number = $_POST['number'];
        $password = $_POST['password'];
        $conpassword = $_POST['conpassword'];

        // Check if the password has at least 10 characters, minimum 2 uppercase, 1 digit, and 1 of @, _, $
        if (strlen($password) >= 10 && preg_match('/[A-Z].*[A-Z]/', $password) && preg_match('/\d/', $password) && preg_match('/[@_$]/', $password)) {
            // Check if confirm password and password are the same
            if ($password == $conpassword) {
                // Insert data into table1
                $insertQuery = "INSERT INTO table1 (name, number, password) VALUES ('$name', '$number', '$password')";

                if (mysqli_query($conn, $insertQuery)) {
                    echo "Data inserted successfully!";
                } else {
                    echo "Error: " . $insertQuery . "<br>" . mysqli_error($conn);
                }
            } else {
                echo "Password and Confirm Password do not match.";
            }
        } else {
            echo "Password does not meet the specified criteria.";
        }
        mysqli_close($conn);
    }
?>
