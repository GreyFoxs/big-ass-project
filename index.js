var firebase = require('firebase')

var ttn = require("ttn")
var appID = "s4dgrootproject"
var accessKey = "ttn-account-v2.j9xCvWDmsUTn-Xenb_esjMVaapBqBctqpXSN4gsei5U"

ttn.data(appID, accessKey)
  .then(function (client) {
    client.on("uplink", function (devID, payload) {
      console.log("Received uplink from ", devID)
      console.log(payload)
      // variabelen uit de payload worden opgeslagen in javascript-variabelen.
      var locationLive = [payload.metadata.latitude, payload.metadata.longitude]
      //batteryLive = payload.payload_fields.battery
      var parkStateLive = payload.payload_fields.bezet
      //update firebase met de meest recente data.
      setLiveTegel(locationLive, parkStateLive)
    })
  })
  .catch(function (error) {
    console.error("Error", error)
    process.exit(1)
  })

//initializatie van de firebase.
firebase.initializeApp({
    databaseURL: 'https://stoeptegelproject.firebaseio.com/',
    serviceAccount: 'stoeptegelproject-firebase-adminsdk-iyxld-1f3f6959c2',
})

//variabele om onze firebase makkelijk mee aan te kunnen spreken.
var database = firebase.database()

function setLiveTegel(location, parkState){
  database.ref('/').child("0").update({
    lat: location[0],
    lng: location[1],
    //battery: batteryLive,
    parkState: parkState
  })
}

//genereerd een random coördinaat op basis van een minimale en maximale long/lat-itude.
function getRandomCoordinate(min, max) {
  return Math.random() * (max - min) + min
}
function getRandomState(){
  var isFree = Math.random()
  if(isFree <= 0.49){
    return true
  }else{
    return false
  }
}
function firebaseSet(amount){
  for(j = 0; j < amount; j++){
    database.ref('/').child(j).set({
      lat: getRandomCoordinate(51.985265, 51.990220),
      lng: getRandomCoordinate(5.954364, 5.939818),
      parkState: getRandomState(),
      battery: Math.floor(Math.random()*100) + "%"
    })
  }
}

firebaseSet(50)
