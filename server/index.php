<?php

// App info

define('APP_NAME', 'Modell');
define('APP_VERSION', '1.0.0-dev');

// Needed helpers

require('./helpers/additionalContent.php');

// Baisc routing

if(isset($_GET['app'])) {
    require('./controllers/app.php');
} else {
    require('./controllers/home.php');
}
