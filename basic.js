// Get a reference to the database service
var ref = firebase.database().ref();
ref.on("value", function(snapshot){
    console.log(snapshot.val().sense1);
});