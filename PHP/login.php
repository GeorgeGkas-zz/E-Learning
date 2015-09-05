	<?php
	    define("DB_HOST", 'mysql2.000webhost.com');
	    define("DB_USER", 'a4842672_georgeg');
	    define("DB_PASSWORD", 'O9e0IeJJe90p59');
	    define("DB_DATABSE", 'a4842672_lefromd');
	
	    $conn = mysql_connect(DB_HOST, DB_USER, DB_PASSWORD);
	    mysql_select_db(DB_DATABSE, $conn);
	    if(isset($_POST['login'])){
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
	        }
	        else
	        {
	            echo "<script type='text/javascript'>alert('Could not connect');</script>";
	        }
	
	        if($user_data["email"]==$emailid && $user_data["password"]==$password)
	            echo"You are a validated user.";
	        else
	            echo"Sorry, your credentials are not valid, Please try again.";
	    }
	
	
	?>
        <form class="form" id="login" name="login" method="post">
                <input type="email" name="lemail" placeholder="Email" required="required">
                <input type="password" name="lpassword" placeholder="Password" required="required">
                <p class="keeplogin"> 
                    <input type="checkbox" name="loginkeeping" id="loginkeeping" value="loginkeeping" /> 
                    <label for="loginkeeping">Keep me logged in</label>
                </p>
                <button type="submit" id="login-button" name="login-button">Login</button>
                <p></p>
                <p style="padding-top: 5px;">You want an account? <a href="#" id="to_signUp"> Sign Up</a></p>
        </form>
