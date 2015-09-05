<?php
    define("DB_HOST", 'mysql2.000webhost.com');
    define("DB_USER", 'a4842672_georgeg');
    define("DB_PASSWORD", 'O9e0IeJJe90p59');
    define("DB_DATABSE", 'a4842672_lefromd');

    $conn = mysql_connect(DB_HOST, DB_USER, DB_PASSWORD);
    mysql_select_db(DB_DATABSE, $conn);
    if(isset($_POST['login-button'])){
        echo "<script type='text/javascript'>alert('Really annoying pop-up!');</script>";
        $emailid = $_POST['lemail'];
        $password = $_POST['lpassword'];
        $res = mysql_query("SELECT * FROM users WHERE emailid = '".$emailid."' AND password = '".md5($password)."'");
        $user_data = mysql_fetch_array($res);
        $no_rows = mysql_num_rows($res);
        if ($no_rows == 1) 
        {
         
            $_SESSION['login'] = true;
            $_SESSION['uid'] = $user_data['id'];
            $_SESSION['username'] = $user_data['username'];
            $_SESSION['email'] = $user_data['emailid'];
            echo "<script type='text/javascript'>alert('Connect');</script>";
            header("location:home.php");
        }
        else
        {
            echo "<script type='text/javascript'>alert('Could not connect');</script>";
        }

    }
    if(isset($_POST['register-button'])) {
        echo "<script type='text/javascript'>alert('Register');</script>";
    }


?>
