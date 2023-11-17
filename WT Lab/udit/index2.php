<?php
    session_start();

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
    <div class="title">Customer Details</div>
    
    <form action="index2.php" method="post">
      <div class="input_box">
        <input type="text" name="name" placeholder="Full Name" required>
        <div class="icon"><i class="fas fa-user"></i></div>
      </div>
      <div class="input_box">
        <input type="email" name="email" placeholder="Email" required>
        <div class="icon"><i class="fas fa-envelope"></i></div>
      </div>
      <div class="input_box">
        <input type="number" name="number" placeholder="Phone Number" required>
        <div class="icon"><i class="fas fa-phone"></i></div>
      </div>
      <div class="input_box">
        <input type="text" name="address" placeholder="Customer Class" required>
        <div class="icon"><i class="fas fa-podcast"></i></div>
      </div>
      
      <div class="input_box button">
        <input type="submit" name="submit" value="Submit">
      </div>
      <div class="sign_up">
        Not signed-up? <a href="signup2.php">Signup now</a>
      </div>
    </form>
  </div>
</body>
</html>

<?php
    if (isset($_POST['submit'])) {
        $phoneNumber = $_POST['number'];
    
        // Prepare and execute the SQL query
        $sql = "SELECT * FROM table2 WHERE phone = '$phoneNumber'";
        $result = $conn->query($sql);
        // Check if a row with the entered phone number exists
        if ($result->num_rows > 0) {
            // Row exists, fetch details
            $row = $result->fetch_assoc();

            // Store details in session
            $_SESSION['customer_details'] = $row;

            // Display details
            echo "Name: " . $row['name'] . "<br>";
            echo "Email: " . $row['email'] . "<br>";
            echo "Phone Number: " . $row['phone'] . "<br>";
            echo "Customer Class: " . $row['class'] . "<br>";
        } else {
            // Row doesn't exist, echo signup
            echo "Signup";
        }
    }
    
?>