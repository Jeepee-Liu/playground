function showEmailAddr() {
	words = document.getElementById("show-email-address");
	words.innerHTML = "zhipingl[AT]umich.edu";
}

function showEmailAddrAlert() {
	alert("zhipingl[AT]umich.edu");
}

function submitForm() {
	try {
		var fso = new ActiveXObject("Scripting.FileSystemObject");
		var f1=fso.createtextfile("log.txt",true);
		f1.WriteLine("Testing...");
		f1.Close();
		alert("Text log written!");
	} catch(err) {
		alert("Error!\n" + err.message);
	}
}
