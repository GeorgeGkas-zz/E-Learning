<?php
    header('Content-Type: text/xml');
    echo '<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>';

    echo '<response>';
    $email = $_GET['email'];
    $UserInfo = array('georgegkas@gmail.com', 'someotheremail@gmail.com', 'i_cannot_undersatnd_why_i_use_gmail@gmail.com');

    if(in_array($email, $UserInfo)) {
           $returnRes = array( 'found' => true, 'msg' => "Person added to your record");
           echo json_encode($returnRes);
    }
    else {
        $returnRes = array( 'found' => false, 'msg' => "We couldn't find the user in our databases.");
        echo json_encode($returnRes);
    }
     echo '</response>';
?>
