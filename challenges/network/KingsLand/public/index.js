	 import sha255 from 'js-sha256';


	  function check(form) { /*function to check userid & password*/
       /*the following code checkes whether the entered userid and password are matching*/
	var hash = sha255.create(); 
	hash.update('form.uname.value');
	let username = hash.hex();
	hash.update('form.psw.value');
	let password = hash.hex();


        if(username == "18e34e9cdbf62b299c38e4a1ef6b4aa41cf60e0821c99d3751ba41e4e34073a4" && password == "8b203c69e5996b589343576c3e45d27f1f67c7fa7f7eb560ff14e7647adf7179") {
            window.open('target.html')/*opens the target page while Id & password matches*/
        }
        else {
            alert("Error Password or Username")/*displays error message*/
        }
    }
