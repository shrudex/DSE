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
    <title>Q1 - Udit</title>
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.2/css/all.min.css"/>
</head>
<body>
<div class="main_div">
    <div class="title">User Details</div>
    
    <form action="index1.php" method="get">
      <div class="input_box">
        <input type="text" name="name" placeholder="Full Name" required>
        <div class="icon"><i class="fas fa-user"></i></div>
      </div>
      <div class="input_box">
        <input type="number" name="number" placeholder="Phone Number" required>
        <div class="icon"><i class="fas fa-phone"></i></div>
      </div>
      <div class="input_box">
        <input type="text" name="address" placeholder="Address" required>
        <div class="icon"><i class="fas fa-address-book"></i></div>
      </div>
      
      <div class="input_box button">
        <input type="submit" name="submit" value="Submit">
      </div>
      <div class="sign_up">
        Not signed-up? <a href="signup1.php">Signup now</a>
      </div>
    </form>
  </div>
</body>
</html>

<?php
        if (isset($_GET['submit'])) {
            $name = $_GET['name'];
            $number = $_GET['number'];
            $address = $_GET['address'];
            $checkQuery = "SELECT * FROM table1 WHERE number = $number";
            $result = $conn->query($checkQuery);
    
            if ($result->num_rows == 0) {
                //asking to signup
                header("Location: signup1.php");
            } else {
                //storing in an associative array
                $customerDetails = array(
                    'name' => $name,
                    'number' => $number,
                    'address' => $address
                );
                //key-value pair
                echo '<div style="color: white; text-align: center;">';
                echo "<p>Details stored in an associative array</p>";
                echo '<p>Name: ' . $customerDetails['name'] . '</p>';
                echo '<p>Number: ' . $customerDetails['number'] . '</p>';
                echo '<p>Address: ' . $customerDetails['address'] . '</p>';
                echo '</div>';
            }
        }
    
?>