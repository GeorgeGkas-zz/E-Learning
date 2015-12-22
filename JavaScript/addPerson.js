var find_xmlHttp = createfind_xmlHttpRequestObject();
var add_find_xmlHttp = createfind_xmlHttpRequestObject();

function createfind_xmlHttpRequestObject() {
    var find_xmlHttp;

    if (window.ActiveXObject) {
        try {
            find_xmlHttp = new ActiveXObject("Microsoft.find_xmlHttp");
        } catch(e) {
            find_xmlHttp = false;
        }
    }
    else {
        try {
            find_xmlHttp = new find_xmlHttpRequest();
        } catch(e) {
            find_xmlHttp = false;
        }
    }

    if (!find_xmlHttp) {
        alert("Can't create XML Object");
    }
    else {
        return find_xmlHttp;
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
            alert('Somenthing went wrong when tried to get data from server'+ find_xmlHttp.readyState);
        }
    }
}

function AjaxAddPerson() {
    if (find_xmlHttp.readyState == 0 || find_xmlHttp.readyState == 4) {
        person = encodeURIComponent(document.getElementById("PersonSearchInput").value);
        find_xmlHttp.open("GET", "../lib/addPerson.php?person=" + person, true);
        find_xmlHttp.onreadystatechange = Add_handleServerResponse;
        find_xmlHttp.send();

    }
}

function Add_handleServerResponse() {
    if (add_find_xmlHttp.readyState == 4 ) {
        if (add_find_xmlHttp.status == 200) {
            xmlResponse = add_find_xmlHttp.responseXML;
            xmlDocumentElement = xmlResponse.documentElement;
            var result = JSON.parse(xmlDocumentElement.firstChild.data);

            if (result['found']) {
                alert(result['msg']);
                document.getElementById("PersonSearchInput").value = "";
            }
            else {
                alert(result['msg']);
            }

            setTimeout(AjaxFindPerson, 1000);
        }
        else {
            alert('Somenthing went wrong when tried to get data from server'+ add_find_xmlHttp.readyState);
        }
    }
}
