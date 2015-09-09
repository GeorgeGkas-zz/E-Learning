<?php
  session_start();
  if(!isset($_SESSION['login']) && !isset($_COOKIE['userlogin'])) {
      header('Location: index.php');
    }

  if(isset($_POST['change-info'])) {
    echo "
    <script>
    $('.bio-info').css('background-color','rgba(32, 154, 188, 0.09)');
    $('#specialist').css('background-color','rgba(32, 154, 188, 0.09)');
    $('.profile-avatar').css('background-color','rgba(32, 154, 188, 0.09)');
    });
    ";
  }
?>
