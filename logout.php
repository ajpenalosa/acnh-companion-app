<?php

require_once 'config.php';

// Remove token and user data from the session
unset($_SESSION['access_token']);
unset($_SESSION['user_data']);

// Reset OAuth access token
$client->revokeToken();

// Destroy entire session data
session_destroy();

// Redirect to homepage
header("Location:index.php");

?>