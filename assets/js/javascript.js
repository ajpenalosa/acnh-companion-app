// Loading App Data

var appData = {};

// Toggle Profile Menu

const   btnProfileSettings = document.querySelector(".btn-profile-settings"),
        profileOptions = document.querySelector(".profile-options");

btnProfileSettings.addEventListener("click", function(e) {
    e.stopPropagation();
    if (profileOptions.classList.contains("active")) {
        profileClose();
        document.removeEventListener("click",profileClose);
    } else {
        profileOptions.classList.add("active");
        document.addEventListener("click",profileClose);
    }
});

function profileClose() {
    console.log("Closing Profile Menu");
    profileOptions.classList.remove("active");
}

// AJAX

var getJSON = function(url, callback) {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', url, true);
    xhr.responseType = 'json';
    xhr.onload = function() {
        var status = xhr.status;
        if (status == 200) callback(null, xhr.response);
        else callback(status);
    };
    xhr.send();
};

// DIY buttons

const   btnUpdateDIY = document.querySelectorAll(".btn-update-diy");

btnUpdateDIY.forEach(function(button) {
    button.addEventListener("click",function(e){
        let name = this.getAttribute('data-name'),
            type = this.getAttribute('data-type'),
            recipe = this.getAttribute('data-recipe').replace(" ", "+"),
            url = `https://www.acnh.pixelmotives.com/appdata.php?method=update&name=${name}&type=${type}&recipe=${recipe}`;

        console.log("Name: " + name);
        console.log("Type: " + type);
        console.log("Recipe: " + recipe);
        console.log("URL: " + url);

        // Getting json info
        getJSON(url, function(err, data) {

            if (err != null) {
                console.error(err);
            } else {
                var dataRecipe = recipe.replace("+"," "),
                    button = document.querySelector(`[data-type=${type}][data-recipe="${dataRecipe}"]`);


                    // LEFT OFF HERE. CAN'T FIGURE OUT WHY THIS CAN'T DETECT THE BUTTON IS PRESENT IN THE ARRAY

                console.log(data[type]);
                console.log(dataRecipe);

                console.log(data[type].hasOwnProperty(dataRecipe));

                if(data[type].hasOwnProperty(dataRecipe) && !button.classList.contains("active")) {
                    button.classList.add("active");
                } else {
                    button.classList.remove("active");
                }
            }
        });
    });
});

// Getting json info
getJSON(url, function(err, data) {
    if (err != null) {
        console.error(err);
    } else {

        appData = data;

        // Looping through object
        for (const property in data) {
            
            let recipes = data[property],
                type = property;
            
            // Looping through recipes
            for (const property in recipes) {
                let button = document.querySelector(`[data-type=${type}][data-recipe="${recipes[property]}"]`);
                button.classList.add("active");
                console.log(button);
            }
        }
    }
});
