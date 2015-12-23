<?php
    header('Content-Type: text/xml');
    echo '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>';
    session_start();
    define("DB_HOST", '.000webhost.com');
    define("DB_USER", '');
    define("DB_PASSWORD", '');
    define("DB_DATABSE", '');

    echo '<response>';
    $email = $_GET['email'];
    $UserEmail = $_SESSION['login'];

    $conn = mysql_connect(DB_HOST, DB_USER, DB_PASSWORD);
    mysql_select_db(DB_DATABSE, $conn);

    $sql_find = mysql_query("SELECT * FROM Users WHERE UserEmail='".$email."'");

    $UserInfo = array();

    while ($row = mysql_fetch_array($sql_find, MYSQL_ASSOC)) {
      $UserInfo[] =  $row['UserEmail'];  
    }
    
    if(in_array($email, $UserInfo)) {
        $result = mysql_query("UPDATE `Users` SET `Contacts` = '".$email."' WHERE `UserEmail` = '".$UserEmail."'");
        if ($result) {
           $returnRes = array( 'found' => true, 'msg' => "Person added to your record");
           echo json_encode($returnRes);
        } 
        else {
           $returnRes = array( 'found' => false, 'msg' => "Error adding person to your record \n Is the person emails' correct?");
           echo json_encode($returnRes);
        }
        
    }
    else {
        $returnRes = array( 'found' => false, 'msg' => "We couldn't find the user in our databases.");
        echo json_encode($returnRes);
    }

     echo '</response>';
?>
