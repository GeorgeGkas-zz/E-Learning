function Add_handleServerResponse() {
    if (add_xmlHttp.readyState == 4 ) {
        if (add_xmlHttp.status == 200) {
           alert('worked!');
        }
        else {
           alert('It didn\'t work ' + add_xmlHttp.status + ' ' + add_xmlHttp.readyState);

        }
    }
}

function AddPerson() {
        if ((add_xmlHttp.readyState == 0 || add_xmlHttp.readyState == 4) && document.getElementById("PersonSearchInput").value != "") {
        person = encodeURIComponent(document.getElementById("PersonSearchInput").value);
        add_xmlHttp.open("GET", "../lib/addPerson.php?email=" + person, true);
        add_xmlHttp.onreadystatechange = Add_handleServerResponse;
        add_xmlHttp.send();

    }
} 
