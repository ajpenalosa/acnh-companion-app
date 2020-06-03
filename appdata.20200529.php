<?php

require_once 'config.php';

$diy_cards = [
    'favorites' => [
        'Flimsy Net',
        'Net',
        'Gold Net'
    ],
    'hot-item' => [
        'Vaulting Pole',
        'Golden Slingshot'
    ],
    'have' => [
        'Cosmos Wand'
    ]
];

$json_diy_cards = json_encode($diy_cards);

if (isset($_SESSION['access_token']) && $_SESSION['access_token']) {

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

    if (count($results->getFiles()) == 0) {
        print "No files found.\n";
    } else {
        foreach ($results->getFiles() as $file) {
            $app_data[] = $file->getId();
        }
    }

    // 2 - If any files exist, see what data they have

    // 3 - Delete

    // Create File
    // $fileMetadata = new Google_Service_Drive_DriveFile(array(
    //     'name' => 'diy_cards.json',
    //     'parents' => array('appDataFolder')
    // ));

    // $file = $drive->files->create($fileMetadata, array(
    //     'data' => $json_diy_cards,
    //     'mimeType' => 'application/json',
    //     'uploadType' => 'multipart',
    // 'fields' => 'id'));

    // printf("File ID: %s\n", $file->id);

    // foreach ($response->files as $file) {
    //     // printf("Found file: %s (%s)", $file->name, $file->id);

    //     if($file->name == 'diy_cards.json') {
    //         var_dump($file);
    //     }
    // }

    // $content = $service_drive->files->get('1cOAg-0vbwgyGVjD4fYPJslSCdIwazN6InQKI7RCCyB2avEOy', array("alt" => "media"));
    // $app_data = $content->getBody()->read(1024);
    // var_dump($app_data);

    echo json_encode($app_data);
}

// echo $json_diy_cards;

?>