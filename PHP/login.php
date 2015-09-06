<?php
    define("DB_HOST", '');
    define("DB_USER", '');
    define("DB_PASSWORD", '');
    define("DB_DATABSE", '');

    $conn = mysql_connect(DB_HOST, DB_USER, DB_PASSWORD);
    mysql_select_db(DB_DATABSE, $conn);
    if(isset($_POST['login-button'])) {
        $emailid = $_POST['lemail'];
        $password = $_POST['lpassword'];
        $res = mysql_query("SELECT * FROM users WHERE emailid = '".$emailid."' AND password = '".md5($password)."'");
        $user_data = mysql_fetch_array($res);
        $no_rows = mysql_num_rows($res);
        if ($no_rows == 1) {
            $_SESSION['login'] = true;
            $_SESSION['uid'] = $user_data['id'];
            $_SESSION['username'] = $user_data['username'];
            $_SESSION['email'] = $user_data['emailid'];
            echo "<script type='text/javascript'>alert('Connect');</script>";
            header("location:home.php");
        }
        else {
            echo "<script type='text/javascript'>alert('Could not connect');</script>";
        }
    }


    $rusername = $_POST['rusername'];
    $remail = $_POST['remail'];
    $rpassword1 = $_POST['rpassword1'];
    $rpassword2 = $_POST['rpassword2'];
    $rCheckgender = $_POST['rgender'];
    $rCheckeducation = $_POST['reducation'];
    if(isset($_POST['register-button'])) {
        $qr = mysql_query("SELECT * FROM users WHERE emailid = '".$remail."'");
        $row = mysql_num_rows($qr);
        if($row > 0){
            echo "<script type='text/javascript'>alert('Email already registered');</script>";
        }
        else {
            $qra = mysql_query("SELECT * FROM users WHERE username = '".$rusername."'");
            $rowa = mysql_num_rows($qra);
            if($rowa > 0){
                echo "<script type='text/javascript'>alert('Username Exist');</script>";
            }
            else {
                if ($rpassword1 != $rpassword2) {
                    echo "<script type='text/javascript'>alert('Passwords do not match');</script>";
                }
                else {
                    $password = md5($password1);

                    if(empty($rCheckgender))  $rgender = "Female";
                    else $rgender = "Male"; //male

                    if(empty($rCheckeducation)) $reducation = "Teacher";
                    else $reducation = "Student"; //student

                    mysql_query("INSERT INTO users(username, emailid, password, gender, education) values('".$rusername."','".$remail."','".$password."','".$rgender."','".$reducation."')") or die(mysql_error());
                }
            }
        }
    }
?>
