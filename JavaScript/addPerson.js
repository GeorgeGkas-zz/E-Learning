var find_xmlHttp = create_xmlHttpRequestObject();
var add_xmlHttp = create_xmlHttpRequestObject();

function create_xmlHttpRequestObject() {
    var xmlHttp;

    if (window.ActiveXObject) {
        try {
            xmlHttp = new ActiveXObject("Microsoft.XMLHTTP");
        } catch(e) {
            xmlHttp = false;
        }
    }
    else {
        try {
            xmlHttp = new XMLHttpRequest();
        } catch(e) {
            xmlHttp = false;
        }
    }

    if (!xmlHttp) {
        alert("Can't create XML Object");
    }
    else {
        return xmlHttp;
    }
}


function AjaxFindPerson() {
    if ((find_xmlHttp.readyState == 0 || find_xmlHttp.readyState == 4) && document.getElementById("PersonSearchInput").value != "") {
        person = encodeURIComponent(document.getElementById("PersonSearchInput").value);
        find_xmlHttp.open("GET", "../lib/search.php?email=" + person, true);
        find_xmlHttp.onreadystatechange = Find_handleServerResponse;
        find_xmlHttp.send();

    }
    else {
        document.getElementById('Label-Result').innerHTML = "";
        document.getElementById('UserNameSearchResult').innerHTML = "";
        $('#add-person-btn').attr("disabled", "disabled");
        setTimeout(AjaxFindPerson, 1000);
    }
}


function Find_handleServerResponse() {
    if (find_xmlHttp.readyState == 4 ) {
        if (find_xmlHttp.status == 200) {
            xmlResponse = find_xmlHttp.responseXML;
            xmlDocumentElement = xmlResponse.documentElement;
            var result = JSON.parse(xmlDocumentElement.firstChild.data);

            if (result['found'] != null) {
                document.getElementById('Label-Result').innerHTML = result['msg'];
                document.getElementById('UserNameSearchResult').innerHTML = result['found'];
                $('#add-person-btn').removeAttr("disabled");
                isFoundPerson = true;
            }
            else {
                document.getElementById('Label-Result').innerHTML = result['msg'];
                document.getElementById('UserNameSearchResult').innerHTML = "";
                $('#add-person-btn').attr("disabled", "disabled");
                isFoundPerson = false;
            }

            setTimeout(AjaxFindPerson, 1000);
        }
        else {
            alert('Somenthing went wrong when tried to get data from server'+ find_xmlHttp.status);
        }
    }
}



function Add_handleServerResponse() {
    if (add_xmlHttp.readyState == 4 ) {
        if (add_xmlHttp.status == 200) {
            xmlResponse = add_xmlHttp.responseXML;
            xmlDocumentElement = xmlResponse.documentElement;
            var result = JSON.parse(xmlDocumentElement.firstChild.data);

            if (result['found']) {
                alert('OK')
            }
            else {
                alert('NO' + ' why?');
            }

            //setTimeout(AjaxFindPerson, 1000);
        }
        else {
           alert('NO ' + add_xmlHttp.status + ' ' + add_xmlHttp.readyState);

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
    else {
       alert('COULD NOT UPDATE!');
    }
} 
