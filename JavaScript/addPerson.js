var add_xmlHttp = new XMLHttpRequest();

function Add_handleServerResponse() {
    if (add_xmlHttp.readyState == 4 ) {
        if (add_xmlHttp.status == 200) {
            xmlResponse = add_xmlHttp.responseXML;
            xmlDocumentElement = xmlResponse.documentElement;
            var result = JSON.parse(xmlDocumentElement.firstChild.data);
            alert(result['msg']);
        }
        else {
           alert('Could not pass data to js. Status:' + add_xmlHttp.status + ' Ready state:' + add_xmlHttp.readyState);

        }
    }
}

function AddPerson(person) {
    if ((add_xmlHttp.readyState == 0 || add_xmlHttp.readyState == 4)) {
        add_xmlHttp.open("GET", "../lib/addPerson.php?email=" + person, true);
        add_xmlHttp.onreadystatechange = Add_handleServerResponse;
        add_xmlHttp.send();

    }
} 


AddPerson('georgegkas@gmail.com');
