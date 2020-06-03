<?php

require_once 'config.php';

// If no parameters are set, this page will display a list of all app data files

// Getting parameters from the URL
$request_uri = $_SERVER['REQUEST_URI'];
$url_components = parse_url($request_uri);
parse_str($url_components['query'], $params);

/*
DIY Parameters:
method: update
name: diy
type: favorites, hot-item, have
recipe: [recipe name]
*/

if (isset($_SESSION['access_token']) && $_SESSION['access_token']) {

    // Initializing $app_data variable
    $app_data = [];

    $client->setAccessToken($_SESSION['access_token']);

    // Google Drive
    $service_drive = new Google_Service_Drive($client);

    // 1 - Check appDataFolder for any existing files

    // List Files
    $results = $service_drive->files->listFiles(array(
        'spaces' => 'appDataFolder',
        'fields' => 'nextPageToken, files(id, name)',
        'pageSize' => 10
    ));

    // If no files are found, print message, then die the page
    if (count($results->getFiles()) == 0) {
        print "No files found.\n";
    } else {

        // If a method is set
        if(isset($params['method'])) {

            // If method is Get
            if($params['method'] == 'get') {

                if (isset($params['name'])) {

                    $filename = $params['name'].'.json';
                    
                    // Find the file that equals $filename
                    foreach ($results->getFiles() as $file) {
                        if($file->getName() == $filename) {
                            $id = $file->getId();
                        }
                    }

                    if(isset($id)) { // If the file exists, do this
                        $content = $service_drive->files->get($id, array("alt" => "media"));
                        $app_data = $content->getBody()->read(1024);
                        $app_data = json_decode($app_data);
                    }
                }
            
            // If the method is update
            } elseif($params['method'] == 'update') {

                if(isset($params['name']) && isset($params['type']) && isset($params['recipe'])) {

                    $filename = $params['name'].'.json';
                    
                    // Find the file that equals $filename
                    foreach ($results->getFiles() as $file) {
                        if($file->getName() == $filename) {
                            $id = $file->getId();
                        }
                    }

                    if(isset($id)) { // If the file exists, do this

                        $content = $service_drive->files->get($id, array("alt" => "media"));
                        $app_data = $content->getBody()->read(1024);

                        $app_data = json_decode($app_data);

                        // Converting to array
                        $app_data->{$params['type']} = (array) $app_data->{$params['type']};

                        // Sorting the array to re-index
                        sort($app_data->{$params['type']});

                        $app_data->{$params['type']} = array_values($app_data->{$params['type']});
                        // If the recipe is not in the array yet, add it
                        if(!in_array($params['recipe'],$app_data->{$params['type']})) {

                            // Push the recipe into the array
                            $app_data->{$params['type']}[] = $params['recipe'];

                        } else { // If it is in the array, delete it

                            if (($key = array_search($params['recipe'], $app_data->{$params['type']})) !== false) {
                                unset($app_data->{$params['type']}[$key]);
                            }
                        }
                        
                        // Update the app data in the google drive
                        try {
                            $emptyFile = new Google_Service_Drive_DriveFile();
                            $service_drive->files->update($id, $emptyFile, array(
                                'data' => json_encode($app_data),
                                'mimeType' => 'text/csv',
                                'uploadType' => 'multipart'
                            ));
                        } catch (Exception $e) {
                            print "An error occurred: " . $e->getMessage();
                        }
                        
                    } else { // If it doesn't exist, create it

                        $app_data->{$params['type']}[] = $params['recipe'];

                        $fileMetadata = new Google_Service_Drive_DriveFile(array(
                            'name' => $filename,
                            'parents' => array('appDataFolder')
                        ));
                    
                        $file = $service_drive->files->create($fileMetadata, array(
                            'data' => json_encode($app_data),
                            'mimeType' => 'application/json',
                            'uploadType' => 'multipart',
                        'fields' => 'id'));
                    }
                }
            }

        } elseif(isset($params['delete'])) { //////// THIS DOESN'T WORK /////// Need to figure out how to delete data
            if($params['delete']='all') {
                // Deleting all files
                if (count($results->getFiles()) != 0) {
                    foreach ($results->getFiles() as $file) {
                        $service_drive->files->delete($file['id']);
                        echo "Deleting: " . $file->getName() . ' ID: ' . $file->getId() .'\n';
                    }
                }
            }
        } else {
            // If no method is set, just list the IDs of each file
            foreach ($results->getFiles() as $file) {
                $app_data[] = $file->getId();
            }
        }
    }

    echo json_encode($app_data);
}

?>